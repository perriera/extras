# Find32or64bit.cmake
*(perriera) extras* now supports g++ 7.5.0 and 32bit compilations on the 18.04 Ubuntu platform. However, this may not be required for modern applications in which case a global environment variable is available to determine what kind of compilation will take place. By default both 32bit and 64bit compilations are produced. To change this default behavior you may set in the .bashrc file either or both of the following environment variables:

> MAKE32BITONLY 
> MAKE64BITONLY 
 
### For 32bit only compilations:

	export MAKE32BITONLY=1
	#export MAKE64BITONLY=1

### For 64bit only compilations:

	#export MAKE32BITONLY=1
	export MAKE64BITONLY=1

**Note**: after you change your .bashrc be sure to source it 

	vi ~/.bashrc
	source ~/.bashrc


