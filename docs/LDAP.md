> [Install and Configure OpenLDAP Server on Ubuntu 22.04|20.04|18.04](https://computingforgeeks.com/install-and-configure-openldap-server-ubuntu/)


- [ ] Set hostname for the Ubuntu server


    sudo hostnamectl set-hostname ldap.example.com

- [ ] Add the IP and FQDN to file /etc/hosts. 

        sudo vim /etc/hosts
        192.168.18.50 ldap.example.com

- [ ] Install OpenLDAP Server on Ubuntu 22.04|20.04|18.04

        sudo apt update
        sudo apt -y install slapd ldap-utils

- [ ] During the installation, you’ll be prompted to set LDAP admin password, provide your desired password, then press <OK>

Confirm the password and continue installation by selecting <ok> with TAB key.

You can confirm that your installation was successful using the commandslapcat  to output SLAPD database contents.

        $ sudo slapcat
        dn: dc=example,dc=com
        objectClass: top
        objectClass: dcObject
        objectClass: organization
        o: example.com
        dc: example
        structuralObjectClass: organization
        entryUUID: 3096cde2-64b5-103c-836e-1d0b0995a781
        creatorsName: cn=admin,dc=example,dc=com
        createTimestamp: 20220510135944Z
        entryCSN: 20220510135944.468673Z#000000#000#000000
        modifiersName: cn=admin,dc=example,dc=com
        modifyTimestamp: 20220510135944Z

- [ ] Add base dn for Users and Groups

The next step is adding a base DN for users and groups. Create a file named basedn.ldif with below contents: 

        vim basedn.ldif
        dn: ou=people,dc=example,dc=com
        objectClass: organizationalUnit
        ou: people

        dn: ou=groups,dc=example,dc=com
        objectClass: organizationalUnit
        ou: groups

Replace example and com with your correct domain components.

- [ ] Now add the file by running the command:

        ldapadd -x -D cn=admin,dc=example,dc=com -W -f basedn.ldif
        Enter LDAP Password:
        adding new entry "ou=people,dc=example,dc=com"
        adding new entry "ou=groups,dc=example,dc=com"

- [ ] Add User Accounts and Groups

Generate a password for the user account to add.

        sudo slappasswd
        New password: 
        Re-enter new password: 
        {SSHA}Zn4/E5f+Ork7WZF/alrpMuHHGufC3x0k

Create ldif file for adding users.

        vim ldapusers.ldif
        dn: uid=computingforgeeks,ou=people,dc=example,dc=com
        objectClass: inetOrgPerson
        objectClass: posixAccount
        objectClass: shadowAccount
        cn: computingforgeeks
        sn: Wiz
        userPassword: {SSHA}Zn4/E5f+Ork7WZF/alrpMuHHGufC3x0k
        loginShell: /bin/bash
        uidNumber: 2000
        gidNumber: 2000
        homeDirectory: /home/computingforgeeks

    - Replace computingforgeeks with the username to add
    - dc=example,dc=com with your correct domain values.
    - cn & sn with your Username Values
    - {SSHA}Zn4/E5f+Ork7WZF/alrpMuHHGufC3x0k with your hashed password

- [ ] When done with edit, add account by running.

        ldapadd -x -D cn=admin,dc=example,dc=com -W -f ldapusers.ldif 
        Enter LDAP Password: 
        adding new entry "uid=computingforgeeks,ou=people,dc=example,dc=com"

- [ ] Do the same of group. Create ldif file:

        vim ldapgroups.ldif
        dn: cn=computingforgeeks,ou=groups,dc=example,dc=com
        objectClass: posixGroup
        cn: computingforgeeks
        gidNumber: 2000
        memberUid: computingforgeeks

- [ ] Add group:

        ldapadd -x -D cn=admin,dc=example,dc=com -W -f ldapgroups.ldif
        Enter LDAP Password: 
        adding new entry "cn=computingforgeeks,ou=groups,dc=example,dc=com"

You can combine the two into single file.

- [ ] Install LDAP Account Manager – Recommended

I noticed phpLDAPadmin doesn’t work well with PHP 7.2+. I recommend you use LDAP Account Manager instead. Follow our guide below to install and configure LDAP Account Manager.

    Install and configure LDAP Account Manager on Ubuntu

The guide also shows you how to add user accounts and groups to your LDAP server.

- [ ] Configure your Ubuntu 22.04|20.04|18.04 as LDAP Client

The last step is to configure the systems in your network to authenticate against the LDAP server we’ve just configured:

    Configure LDAP Client on Ubuntu

- [ ] Securing LDAP Server/Client

Secure your LDAP Server and access from LDAP Client with TLS/SSL:

    Secure LDAP Server with SSL/TLS on Ubuntu

Summary 

Wrapping Up ... 

Thanks for using our guide to install and configure OpenLDAP server on your Ubuntu. I recommend installing and using LDAP Account Manager to administer your LDAP server through a web interface.

Next Steps

If you need an advanced centralized user management platform, see

    How to Install and Configure FreeIPA Server on Ubuntu
    How to Configure FreeIPA Client on Ubuntu / CentOS 7
    How to Configure FreeIPA replication on Ubuntu / CentOS



