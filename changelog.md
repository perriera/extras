# Changelog

> All notable changes to this project will be documented in this file.</br>
> The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/), </br>
> and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).</br>
> To add a tag to the git repository do:
>
> > git tag -a v8.10.11 -m "added syncfile interface"</br>
> > git push origin v8.10.11
>
> > POPULAR LINKS:
> > https://zed0.co.uk/clang-format-configurator/

IMPORTANT:

- Manually keep the changelog version number in sync with CMakeLists.txt project version.<br>
- Keep the changelog.md up to date, neat and tidy, (as it is a convenient tool for code maintenance).<br>
- Use [Semantic Versioning](https://semver.org/spec/v2.0.0.html) such that<br>
- Given a version number MAJOR.MINOR.PATCH, increment the:<br>
- MAJOR version when you make incompatible API changes,<br>
- MINOR version when you add functionality in a backwards compatible manner, and<br>
- PATCH version when you make backwards compatible bug fixes. <br>
- But there is no need to change the version number for correcting spelling errors, (etc).<br>
- MAKE SURE to tag and update the tag compare list below, (for quick code comparison purposes).<br>

## [Unreleased]
- replacement for filesystem include file 

#### 8.10.0 (2023-03-23)
### Refactored 
- added renumber interface

#### 8.10.0 (2023-03-23)
### Upgraded 
- added syncfile interface

#### 8.9.3 (2023-03-23)
### Upgraded 
- added bash scripts on hosting

#### 8.9.2 (2023-03-22)
### Upgraded 
- added docs on hosting

#### 8.9.1 (2023-03-21)
### Upgraded 
- added docs on hosting

#### 8.9.0 (2023-03-21)
### Upgraded 
- added docs on hosting

#### 8.8.11 (2023-03-21)
### Upraded 
- added docs 

#### 8.8.10 (2023-03-21)
### Upraded 
- added docs 

#### 8.8.9 (2023-03-21)
### Upraded 
- added docs 

#### 8.8.8 (2023-03-21)
### Upraded 
- added docs 

#### 8.7.7 (2023-02-21)
### Upraded 
- refactored interfaces folder

#### 8.7.5 (2023-02-21)
### Upraded 
- refactored interfaces folder

#### 8.7.4 (2023-02-21)
### Upraded 
- refactored interfaces folder

#### 8.7.1 (2023-02-21)
### Upraded 
- refactored interfaces folder

#### 8.7.0 (2023-02-21)
### Upraded 
- refactored interfaces folder

#### 8.6.5 (2023-01-08)
### Upraded 
- disabled cmake.yml

#### 8.6.4 (2022-12-26)
### Upraded 
- Using CPM_DOWNLOAD_VERSION 0.36.0
### Added 
- added docs/CPM.md
* [CPM: An Awesome Dependency Manager for C++ with CMake](https://medium.com/swlh/cpm-an-awesome-dependency-manager-for-c-with-cmake-3c53f4376766)
* [CMake's missing package manager](https://github.com/cpm-cmake/CPM.cmake)
* wget -O cmake/CPM.cmake https://github.com/cpm-cmake/CPM.cmake/releases/latest/download/get_cpm.cmake

#### 8.6.3 (2022-12-20)
### Added 
- removed unused exceptions
- changelog.md

#### 8.6.2 (2022-12-10)
### Added 
- added new split method test cases
- changelog.md

#### 8.6.1 (2022-12-07)
### Added 
- added new split method to header file
- changelog.md

#### 8.6.0 (2022-12-07)
### Added 
- added new split method
- changelog.md

#### 8.5.2 (2022-10-16)
### Fixed version number
### Modified 
- include/extras/version.hpp
- changelog.md

#### 8.5.1 (2022-10-16)
### Added convenience method
### Modified 
- include/extras/file/interfaces.hpp
- src/file/interfaces.hpp
- test/file/mold_assertions.hpp
- changelog.md

#### 8.5.0 (2022-10-16)
### Added file::FolderExistsException exception 
### Modified 
- include/extras/language/interfaces.hpp
### Changed
- src/file/assertions.cpp (from src/file/exceptions.cpp)
- test/fileinterface to test/file
- changelog.md
* we now have a convenient way of determining that a 
* folder exists

#### 8.4.0 (2022-09-20)
### Added 
- Dock/Molds Interfaces Framework

#### 8.3.1 (2022-09-20)
### Fixed 
- MINSIGSTKSZ in catch2.hpp
* [MINSIGSTKSZ error](https://stackoverflow.com/questions/71454588/minsigstksz-error-after-update-in-my-manjaro-linux)

#### 8.3.0 (2022-09-20)
### Updated 
- link to Pulse Secure

#### 8.2.0 (2022-08-30)
### Updated 
- latest ubuntu vm urls
* [Download Ubuntu 20.04.4 LTS](https://releases.ubuntu.com/20.04/) <br/>
* [Download Ubuntu 21.04.1 LTS](https://releases.ubuntu.com/21.04/) <br/>
* [Download Ubuntu 22.04.1 LTS](https://releases.ubuntu.com/22.04/) <br/>

#### 8.1.0 (2022-08-30)
### Updated 
- latest virtual box urls
* [Index of /virtualbox/6.1.32](http://download.virtualbox.org/virtualbox/6.1.32/)<br/>
* [Index of /virtualbox/6.1.34](http://download.virtualbox.org/virtualbox/6.1.34/)<br/>
* [Index of /virtualbox/6.1.36](http://download.virtualbox.org/virtualbox/6.1.36/)<br/>

#### 8.0.0 (2022-08-28)
### Refactored 
- file::Interface exceptions
- file::NotFoundException
- file::NotCopiedException
- file::InvalidNameException
- file::ExistsException

#### 7.5.0 (2022-08-28)
### Added 
- FileNotFoundException
- FileNotCopiedException
- FilenameInvalidException
- FileExistsException

#### 7.4.0 (2022-08-04)
### Added 
- added test/vendor/README.md
- added cmake/README.md

#### 7.3.0 (2022-08-02)
### Added 
- added Find32or64bit.cmake
- added MAKE32BITONLY environment variable
- added MAKE64BITONLY environment variable

#### 7.2.0 (2022-08-01)
### Added 
- applied _i386

#### 7.1.0 (2022-08-01)
### Added 
- targets both 32/64 formats

#### 7.0.0 (2022-08-01)
### Added 
- using file::Interface

#### 6.2.0 (2022-07-29)
### Added 
- FileInterface added
- File class
- FileNotFoundException added (back)
- FeatureInterface added

#### 6.1.0 (2022-07-26)
### Added 
- -m32 support
[We can now build and debug in 32bit, (and on a 64bit platform)](https://stackoverflow.com/questions/5665228/in-linux-determine-if-a-a-library-archive-32-bit-or-64-bit)

#### 6.0.0 (2022-07-25)
### Added 
- gcc 7.5.0 support
- Ubuntu 18.04 support
### Removed
- __cpp_lib_filesystem support

#### 5.27.0 (2022-04-20)
### Added 
- __cpp_lib_filesystem support

#### 5.26.0 (2022-04-20)
### Changed
- -pthread added

#### 5.25.0 (2022-04-20)
### Changed
- INSTALL.md

#### 5.24.0 (2022-01-08)
### Added
- DockIt.hpp
- NotEnoughParametersException
- HelpParameterException

#### 5.23.0 (2021-12-23)
### Added
- justthefilename(), justtheextension()
### Changed
- filename()

#### 5.22.1 (2021-12-23)
### Fixed
- Directory, DirectoryListing

#### 5.22.0 (2021-12-20)
### Added
- replace_first

#### 5.21.0 (2021-12-17)
### Added
- Refactored string_support.hpp

#### 5.20.1 (2021-12-16)
### Added
- link

#### 5.20.0 (2021-12-16)
### Added
- namespace extras::str, (for better string support)

#### 5.19.1 (2021-12-16)
### Added
- Improved replace_last() algorithm

#### 5.19.0 (2021-12-16)
### Added
- Added replace_last & extras::filesystem

#### 5.18.1 (2021-12-15)
### Added
- Note on CPM/Shared Library debugging issue

#### 5.18.0 (2021-12-11)
### Added
- Pathname, Pathnames

#### 5.17.0 (2021-12-08)
### Improved
- improved code

#### 5.16.0 (2021-12-08)
### Improved
- improved code

#### 5.15.0 (2021-12-08)
### Improved
- added operator

#### 5.14.0 (2021-12-04)
### Improved
- exception handler

#### 5.13.0 (2021-12-03)
### Improved
- exception handler

#### 5.12.0 (2021-12-02)
### Improved
- Added extras::exception ...

#### 5.11.1 (2021-12-02)
### Improved
- Added msg ...

#### 5.11.0 (2021-12-02)
### Improved
- Added ExtrasExceptionInterface
- Added ExtrasExceptionInterface stream

#### 5.10.4 (2021-12-02)
### Improved
- Added new exceptions

#### 5.9.4 (2021-12-02)
### Improved
- Fixed FileNotFound 'exception'

#### 5.9.2 (2021-12-02)
### Improved
- Refactored extras/types.hpp

#### 5.9.1 (2021-12-01)
### Improved
- Fixed issue with header files

#### 5.9.0 (2021-12-01)
### Improved
- Updated docs

#### 5.8.0 (2021-12-01)
### Improved
- Updated docs

#### 5.7.0 2021-12-01)
### Improved
- Updated docs

#### 5.6.0 (2021-11-30)
### Improved
- Refactired exceptions.hpp

#### 5.5.1 (2021-11-30)
### Improved
- Corrected directive

#### 5.5.0 (2021-11-30)
### Improved
- MIT/X LICENSE

#### 5.4.0 (2021-11-29)
### Added
- MIT/X LICENSE
- Fixed formatting

#### 5.3.6 (2021-11-24)
### Fixed
- a technicality on ScriptException

#### 5.3.5 (2021-11-20)
### Fixed
- a technicality on ScriptException

#### 5.3.4 (2021-11-20)
### Added
- Removed a diagnostic

#### 5.3.3 (2021-11-20)
### Added
- FileNotFoundException added back

#### 5.3.2 (2021-11-20)
### Added
- FileNotFoundException depercated

#### 5.3.1 (2021-11-19)
### Added
- Updated version info

#### 5.3.0 (2021-11-19)
### Added
- Ported StatusLine

#### 5.2.1 (2021-11-19)
### Added
- Fixed ScriptException

#### 5.2.0 (2021-11-16)
### Added
- ScriptException

#### 5.1.2 (2021-11-16)
### Added
- ScriptException

#### 5.1.1 (2021-11-15)
### Changed
- Corrected missing parameter

#### 5.1.0 (2021-11-14)
### Changed
- Added SystemException

#### 5.0.9 (2021-11-11)
### Changed
- Added typeinfo to exception msg

#### 5.0.8 (2021-11-10)
### Changed
- Added docs on CPM CACHE optimization

#### 5.0.7 (2021-11-10)
### Changed
- Fixed issue

#### 5.0.6 (2021-11-10)
### Changed
- Fixed typo
### Removed
- doxygen.conf

#### 5.0.5 (2021-11-10)
### Added
- Better perriera/cc_starter instructions
- INSTALL.md
- HOWTO.md
### Changed
- Updated README.md
### Removed
- html/ directory

#### 5.0.4 (2021-11-10)
### Added
- Added perriera/cc_starter instructions
### Changed
- Updated README.md
- Updated CPM instructions

#### 5.0.3 (2021-11-10)
### Added
- MAKE_EXTRAS_LIBRARY_ONLY flag
### Changed
- Updated README.md
- Updated CPM instructions
- Removed unnecessary files

#### 5.0.2 (2021-11-10)
### Removed
- Updated README.md
- Removed unnecessary files

#### 5.0.1 (2021-11-09)
### Removed
- Updated README.md
- Updated version.h

#### 5.0.0 (2021-11-09)
### Removed
- Anytzing related to RSI is moved to extras_rsi
- PE-34

#### 4.19.0 (2021-11-08)
### Added
- Adjusting MAKE_EXTRAS_LIBRARY_ONLY flag constraints
- PE-33

#### 4.18.0 (2021-11-08)
### Added
- Adjusting MAKE_EXTRAS_LIBRARY_ONLY flag
- PE-33

#### 4.17.0 (2021-11-08)
### Added
- Added MAKE_EXTRAS_LIBRARY_ONLY
- PE-33

#### 4.16.0 (2021-11-08)
### Added
- back the <extras/interfaces.hpp> header file
- PE-33

#### 4.15.0 (2021-11-08)
### Added
- Working prototype
- PE-18C

#### 4.14.0 (2021-11-01)
### Added
- Added RequestTypeCompilationInterface
- Added RequestTypeCompilerInterface
- PE-25

#### 4.11.1 (2021-11-01)
### Added
- Forgot to commit
- PE-30

#### 4.11.0 (2021-11-01)
### Added
- UploaderInterface
- PE-30

#### 4.10.0 (2021-10-29)
### Added
- UploaderInterface
- PE-29

#### 4.9.0 (2021-10-29)
### Resolved
- RSI Subsystem Refactoring
- PE-27

#### 4.8.0 (2021-10-29)
### Added
- rsi_client/rsi_server added
- RSIInterface
- RSIRequestInterface

#### 4.7.0 (2021-10-25)
### Added
- Minor refinements

#### 4.6.0 (2021-10-25)
### Added
- Working -async, -server_async parameters

#### 4.5.0 (2021-10-25)
### Added
- added -nsync, -server_nsync options

#### 4.4.0 (2021-10-25)
### Added
- first successful RSI

#### 4.3.0 (2021-10-25)
### Added
- request_server, request_client

#### 4.2.0 (2021-10-25)
### Added
- port_server, port_client

#### 4.1.0 (2021-10-25)
### Added
- PortAuthorityInterface, PortAuthority

#### 4.0.0 (2021-10-25)
### Refactored
- include/extras direcory structure

#### 3.30.0 (2021-10-25)
### Refactored
- Test case direcory

#### 3.29.0 (2021-10-25)
### Added
- PortAuthorityInterface

#### 3.28.0 (2021-10-25)
### Added
- FileTransferInterface

#### 3.27.0 (2021-10-24)
### Added
- Added current_path to ~Paths function

#### 3.26.0 (2021-10-24)
### Added
- DomainInterface
* (PE-14)[https://github.com/perriera/extras/compare/v3.25.1...v3.26.0]

#### 3.25.1 (2021-10-24)
### Added
- Fixed issue with IP address

#### 3.25.0 (2021-10-24)
### Added
- FileTransferInterface

#### 3.24.0 (2021-10-16)
### Added
- AverageTempInterface

#### 3.23.0 (2021-10-16)
### Added
- HexFileTransfer

#### 3.22.0 (2021-10-16)
### Changed
- README.md

#### 3.21.0 (2021-10-16)
### Added
- Hex2BinInterface
- BinInterface
- Bin2HexInterface
- HexInterface

#### 3.20.0 (2021-10-16)
### Added
- Streams to SocketClient
- Streams to SocketServer

#### 3.19.0 (2021-10-16)
### Added
- SocketPacket

#### 3.18.0 (2021-10-16)
### Added
- Refactored header files

#### 3.17.0 (2021-10-16)
### Added
- Added DNS support

#### 3.16.0 (2021-10-16)
### Added
- Numerous refinements

#### 3.15.0 (2021-10-16)
### Added
- SocketInterface, Socket class
* SocketClientInterface, SocketClient class
* SocketServerInterface, SocketServer class

#### 3.14.2 (2021-10-12)
### Added
- The ~() overload on Paths class
* not necessary for best practices
* but it looks pretty cool

#### 3.14.1 (2021-10-11)
### Added
- Removed unnecessary semi-colon
* necessary for best practices

#### 3.14.0 (2021-10-11)
### Added
- Added dev branch
* necessary for best practices

#### 3.13.0 (2021-10-11)
### Added
- PathsInterface
* necessary for freeformjs support

#### 3.12.0 (2021-09-25)
### Added
- Updated docs
* necessary for chessmind support

#### 3.11.0 (2021-09-25)
### Added
- files.hpp back
* necessary for chessmind support

#### 3.10.0 (2021-09-25)
### Added
- ANSI colors back
- .vscode support

#### 3.8.2 (2021-08-11)
### Added
- Push to Github on (PE-7)

### Changed
- Version number

#### 3.8.1 (2021-08-11)
### Added
- Push to Github
### Changed
- Version number

#### 3.8.0 (2021-08-11)
### Added
- DotENVNoKeyException, (dotenv.hpp)
- DotENVBadFormatException, (dotenv.hpp)

### Changed
- DotENVLineKeyException, (dotenv.hpp, dotenv.cpp)
- DotENVLineKeyException::assertion(), (dotenv.cpp)

#### 3.7.0 (2021-08-11)
### Added
- DotENVLineInterface, (dotenv.hpp)
- DotENVLine, (dotenv.cpp)
- DotENVLineInterface mocks, (mock_dotenv.cpp)
- DotENVLine unit tests, (test_dotenv.cpp)
### Changed
- Updated README.md

#### 3.6.0 (2021-08-11)
### Added
- DotENVInterface, (dotenv.hpp)
- DotENV, (dotenv.cpp)
- DotENVInterface mocks, (mock_dotenv.cpp)
- DotENV unit tests, (test_dotenv.cpp)

### Changed
- Updated README.md

#### 3.5.1 (2021-08-11)
### Added
- extras:: in front of **INFO** macro

#### 3.5.0 (2021-08-11)
### Removed
- spdlog from CMakeLists.txt

#### 3.4.0 (2021-08-11)
### Added
- ExtrasExceptionInterface
  - [Exception handling syntax](https://en.wikipedia.org/wiki/Exception_handling_syntax)
- AbstractCustomException
  - [Abstract factory pattern](https://en.wikipedia.org/wiki/Abstract_factory_pattern)
- SpecificCustomException
  - An example of how to implemnts a specific custom exception
- GroupCustomException
  - An example of how to group custom exceptions, (into types of exceptions)
- OctalException
  - An example of how custom exceptions are used and how to use assertion() methods
  - [Octal format](https://en.wikipedia.org/wiki/Octal)

#### 3.3.1 (2021-08-10)
### Corrected
- Compare links for 3.3.0

#### 3.3.0 (2021-08-10)
### Added
- OctalInterface, (needed by chessmind)
  - [chessmind is now undergoing a refit on new CMakeLists.txt format](https://github.com/perriera/chessmind)
- mock_octal.cpp, (needed by developers)
  - [how to use mocks effectively](https://github.com/eranpeer/FakeIt)
### Changed

- .clang-format started acting up and The Cure was found here:
  - [clang-format configuratot](https://zed0.co.uk/clang-format-configurator/)

#### 3.2.1 (2021-08-09)
### Updated
- README.md

#### 3.2.0 (2021-08-09)
### Added
- Added Popular header only libraries are bundled in the library under the extras/vendor
  - [cxxpots v2.2.0 for command line parsing](https://github.com/jarro2783/cxxopts)
  - [nlohmann/json v3.9.1 for first class json support](https://github.com/nlohmann/json)
- Addded Popular logging and fmt libraries as that are installed on the system but not bundled
  - [spdlog v1.9.1 for logging, also comes bundled with fmtlib](https://github.com/gabime/spdlog)
  - [fmtlib 8.0.1 faster than iostream and printf](https://github.com/fmtlib/fmt)
- Added CPM, cmakes missing package manager
  - [CPM a thin wrapper around Fetch_Content](https://github.com/cpm-cmake/CPM.cmake)
- Added clang-format and cmake-format files, using Googles style guidelines
- Added Interprocedural optimization support to cmake file.
- Added new project options that can be called from command line, or in cmake file
  - -DBUILD_TESTS=<OFF, ON> defaults to ON,
  - -DDEBUG=<OFF, ON> defaults to ON
- Added new version.hpp file, and cmake/utils.cmake file to update the version,
  now the version will only need to be updated in the version.hpp file, and in this
  changelog
### Removed
- Removed ansi color support as fmt lib supplies that functionality
- Removed Directory, File support as c++17 has filesystem build in
- Removed redundant wrapper header files, and redundant cpp files
- Removed uneeded std namespace includes

#### 3.1.0 (2021-08-05)
### Added
- Added nlohmann json header only library.
- There is a conflicting variable name in extras and in json
  called "pure". Changed the name of the variable on line 1441 to purex

#### 3.0.0 (2021-08-05)
### Removed
- Removed docopts 3rd party library
### Changed
- Added another shot in the wind

#### 2.3.8 (2021-07-26)
### Changed
- Added another shot in the wind

#### 2.3.7 (2021-07-26)
### Changed
- Added export() statement

#### 2.3.6 (2021-07-26)
### Changed
- Troubleshooting Install parameters

#### 2.3.5 (2021-07-26)
### Changed
- Install parameters

#### 2.3.4 (2021-07-26)
### Changed
- Put all headers under include directory
- Changed library name from 'extra' to 'extras'

#### 2.3.3 (2021-07-26)
### Changed
- Put all headers into the same subdirectory
- Put all sub libraries back into one library

#### 2.2.3 (2021-07-26)
### Fixed
- Directory test case.
### Fixed
- Directory (Linux) needed an -a option to see hidden files.

#### 2.2.1 (2021-07-26)
### Changes
- Updated README.md

#### 2.2.0 (2021-07-26)
### Added
- extras_interfaces

#### 2.1.0 (2021-07-26)
### Added
- #include <extra/interfaces.hpp>

#### 2.0.0 (2021-07-26)
### Added
- namespace extras support
### Changed
- README.md content for namespaces
### Fixed
- Name collision in the docopt package

#### 1.2.4 (2021-07-25)
### Added
- README.md content
- sudo checkinstall process
### Changed
- ansi_colors.hpp

#### 1.2.3 (2021-07-25)
### Added
- README.md content
- PRODUCTION mode
### Changed
- Updated Doxygen documentation

#### 1.2.2 (2021-07-25)
### Added
- README.md content
### Changed
- Updated Doxygen documentation

#### 1.2.1 (2021-07-25)
### Changed
- Added documentation to keywords.hpp
- Fixed some header files

#### 1.1.1 (2021-07-25)
### Added
- extra_options added

### Changed
- docopt filename changed
- some functionality commented out, (for compilation reasons)

#### 1.0.1 (2021-07-25)
### Added
- extra header (more generic) files
### Changed
- extra older header files

#### 1.0.0 (2021-07-25)
### Added
- extra_crcs library
- extra_colors library
- extra_files library
- extra_keywords library
- extra_strings library
### Changed
- extra library

#### 0.1.3 (2021-07-25)
### Changed
- Changelog format
- Changelog documentation

#### 0.1.2 (2021-07-25)
### Added
- Added tag reference

#### 0.1.1 (2021-07-25)
### Added
- Adopted new changelog format.
- sudo make install parameters
### Changed
- version number
### Removed
- nothing

[unreleased]: https://github.com/perriera/extras/compare/v8.10.1..HEAD
[8.10.1]: https://github.com/perriera/extras/compare/v8.10.0...v8.10.1
[8.10.0]: https://github.com/perriera/extras/compare/v8.9.3...v8.10.0
[8.9.3]: https://github.com/perriera/extras/compare/v8.9.2...v8.9.3
[8.9.2]: https://github.com/perriera/extras/compare/v8.9.1...v8.9.2
[8.9.1]: https://github.com/perriera/extras/compare/v8.9.0...v8.9.1
[8.9.0]: https://github.com/perriera/extras/compare/v8.8.11...v8.9.0
[8.8.11]: https://github.com/perriera/extras/compare/v8.8.10...v8.8.11
[8.8.10]: https://github.com/perriera/extras/compare/v8.8.9...v8.8.10
[8.8.9]: https://github.com/perriera/extras/compare/v8.8.8...v8.8.9
[8.8.8]: https://github.com/perriera/extras/compare/v8.7.7...v8.8.8
[8.7.7]: https://github.com/perriera/extras/compare/v8.7.5...v8.7.7
[8.7.5]: https://github.com/perriera/extras/compare/v8.7.4...v8.7.5
[8.7.4]: https://github.com/perriera/extras/compare/v8.7.3...v8.7.4
[8.7.3]: https://github.com/perriera/extras/compare/v8.7.2...v8.7.3
[8.7.2]: https://github.com/perriera/extras/compare/v8.7.1...v8.7.2
[8.7.1]: https://github.com/perriera/extras/compare/v8.7.0...v8.7.1
[8.7.0]: https://github.com/perriera/extras/compare/v8.6.5...v8.7.0
[8.6.5]: https://github.com/perriera/extras/compare/v8.6.4...v8.6.5
[8.6.4]: https://github.com/perriera/extras/compare/v8.6.3...v8.6.4
[8.6.3]: https://github.com/perriera/extras/compare/v8.6.2...v8.6.3
[8.6.2]: https://github.com/perriera/extras/compare/v8.6.1...v8.6.2
[8.6.1]: https://github.com/perriera/extras/compare/v8.6.0...v8.6.1
[8.6.0]: https://github.com/perriera/extras/compare/v8.5.2...v8.6.0
[8.5.2]: https://github.com/perriera/extras/compare/v8.5.0...v8.5.2
[8.5.1]: https://github.com/perriera/extras/compare/v8.5.0...v8.5.1
[8.5.0]: https://github.com/perriera/extras/compare/v8.4.0...v8.5.0
[8.4.0]: https://github.com/perriera/extras/compare/v8.3.1...v8.4.0
[8.3.1]: https://github.com/perriera/extras/compare/v8.3.0...v8.3.1
[8.3.0]: https://github.com/perriera/extras/compare/v8.2.0...v8.3.0
[8.2.0]: https://github.com/perriera/extras/compare/v8.1.0...v8.2.0
[8.1.0]: https://github.com/perriera/extras/compare/v8.0.0...v8.1.0
[8.0.0]: https://github.com/perriera/extras/compare/v7.5.0...v8.0.0
[7.5.0]: https://github.com/perriera/extras/compare/v7.4.0...v7.5.0
[7.4.0]: https://github.com/perriera/extras/compare/v7.3.0...v7.4.0
[7.3.0]: https://github.com/perriera/extras/compare/v7.2.0...v7.3.0
[7.2.0]: https://github.com/perriera/extras/compare/v7.1.0...v7.2.0
[7.1.0]: https://github.com/perriera/extras/compare/v7.0.0...v7.1.0
[7.0.0]: https://github.com/perriera/extras/compare/v6.2.0...v7.0.0
[6.2.0]: https://github.com/perriera/extras/compare/v6.1.0...v6.2.0
[6.1.0]: https://github.com/perriera/extras/compare/v6.0.0...v6.1.0
[6.0.0]: https://github.com/perriera/extras/compare/v5.26.0...v6.0.0
[5.27.0]: https://github.com/perriera/extras/compare/v5.26.0...v5.27.0
[5.26.0]: https://github.com/perriera/extras/compare/v5.25.0...v5.26.0
[5.25.0]: https://github.com/perriera/extras/compare/v5.24.0...v5.25.0
[5.24.0]: https://github.com/perriera/extras/compare/v5.23.0...v5.24.0
[5.23.0]: https://github.com/perriera/extras/compare/v5.22.2...v5.23.0
[5.22.2]: https://github.com/perriera/extras/compare/v5.22.1...v5.22.2
[5.22.1]: https://github.com/perriera/extras/compare/v5.22.0...v5.22.1
[5.22.0]: https://github.com/perriera/extras/compare/v5.21.0...v5.22.0
[5.21.0]: https://github.com/perriera/extras/compare/v5.20.1...v5.21.0
[5.20.1]: https://github.com/perriera/extras/compare/v5.19.1...v5.20.1
[5.20.0]: https://github.com/perriera/extras/compare/v5.19.1...v5.20.0
[5.19.1]: https://github.com/perriera/extras/compare/v5.19.0...v5.19.1
[5.19.0]: https://github.com/perriera/extras/compare/v5.18.1...v5.19.0
[5.18.1]: https://github.com/perriera/extras/compare/v5.18.0...v5.18.1
[5.18.0]: https://github.com/perriera/extras/compare/v5.17.0...v5.18.0
[5.17.0]: https://github.com/perriera/extras/compare/v5.16.0...v5.17.0
[5.16.0]: https://github.com/perriera/extras/compare/v5.15.0...v5.16.0
[5.15.0]: https://github.com/perriera/extras/compare/v5.14.0...v5.15.0
[5.14.0]: https://github.com/perriera/extras/compare/v5.13.0...v5.13.0
[5.13.0]: https://github.com/perriera/extras/compare/v5.12.0...v5.13.0
[5.12.0]: https://github.com/perriera/extras/compare/v5.11.1...v5.12.0
[5.11.1]: https://github.com/perriera/extras/compare/v5.10.4...v5.11.1
[5.10.4]: https://github.com/perriera/extras/compare/v5.9.2...v5.10.4
[5.9.2]: https://github.com/perriera/extras/compare/v5.9.1...v5.9.2
[5.9.1]: https://github.com/perriera/extras/compare/v5.9.0...v5.9.1
[5.9.0]: https://github.com/perriera/extras/compare/v5.8.0...v5.9.0
[5.8.0]: https://github.com/perriera/extras/compare/v5.7.0...v5.8.0
[5.7.0]: https://github.com/perriera/extras/compare/v5.6.0...v5.7.0
[5.6.0]: https://github.com/perriera/extras/compare/v5.5.1...v5.6.0
[5.5.1]: https://github.com/perriera/extras/compare/v5.5.0...v5.5.1
[5.5.0]: https://github.com/perriera/extras/compare/v5.4.0...v5.5.0
[5.4.0]: https://github.com/perriera/extras/compare/v5.3.6...v5.4.0
[5.3.6]: https://github.com/perriera/extras/compare/v5.3.5...v5.3.6
[5.3.5]: https://github.com/perriera/extras/compare/v5.3.4...v5.3.5
[5.3.4]: https://github.com/perriera/extras/compare/v5.3.3...v5.3.4
[5.3.3]: https://github.com/perriera/extras/compare/v5.3.2...v5.3.3
[5.3.2]: https://github.com/perriera/extras/compare/v5.3.1...v5.3.2
[5.3.1]: https://github.com/perriera/extras/compare/v5.3.0...v5.3.1
[5.3.0]: https://github.com/perriera/extras/compare/v5.2.1...v5.3.0
[5.2.1]: https://github.com/perriera/extras/compare/v5.2.0...v5.2.1
[5.2.0]: https://github.com/perriera/extras/compare/v5.1.2...v5.2.0
[5.1.2]: https://github.com/perriera/extras/compare/v5.1.1...v5.1.2
[5.1.1]: https://github.com/perriera/extras/compare/v5.1.0...v5.1.1
[5.1.0]: https://github.com/perriera/extras/compare/v5.0.9...v5.1.0
[5.0.9]: https://github.com/perriera/extras/compare/v5.0.8...v5.0.9
[5.0.8]: https://github.com/perriera/extras/compare/v5.0.7...v5.0.8
[5.0.7]: https://github.com/perriera/extras/compare/v5.0.6...v5.0.7
[5.0.6]: https://github.com/perriera/extras/compare/v5.0.5...v5.0.6
[5.0.5]: https://github.com/perriera/extras/compare/v5.0.4...v5.0.5
[5.0.4]: https://github.com/perriera/extras/compare/v5.0.3...v5.0.4
[5.0.3]: https://github.com/perriera/extras/compare/v5.0.2...v5.0.3
[5.0.2]: https://github.com/perriera/extras/compare/v5.0.1...v5.0.2
[5.0.1]: https://github.com/perriera/extras/compare/v5.0.0...v5.0.1
[5.0.0]: https://github.com/perriera/extras/compare/v4.19.0...v5.0.0
[4.19.0]: https://github.com/perriera/extras/compare/v4.18.0...v4.19.0
[4.18.0]: https://github.com/perriera/extras/compare/v4.17.0...v4.18.0
[4.17.0]: https://github.com/perriera/extras/compare/v4.16.0...v4.17.0
[4.16.0]: https://github.com/perriera/extras/compare/v4.15.0...v4.16.0
[4.15.0]: https://github.com/perriera/extras/compare/v4.14.0...v4.15.0
[4.14.0]: https://github.com/perriera/extras/compare/v4.13.0...v4.14.0
[4.13.0]: https://github.com/perriera/extras/compare/v4.12.0...v4.13.0
[4.12.0]: https://github.com/perriera/extras/compare/v4.11.1...v4.12.0
[4.11.1]: https://github.com/perriera/extras/compare/v4.11.0...v4.11.1
[4.11.0]: https://github.com/perriera/extras/compare/v4.10.0...v4.11.0
[4.10.0]: https://github.com/perriera/extras/compare/v4.9.0...v4.10.0
[4.9.0]: https://github.com/perriera/extras/compare/v4.8.0...v4.9.0
[4.8.0]: https://github.com/perriera/extras/compare/v4.7.0...v4.8.0
[4.7.0]: https://github.com/perriera/extras/compare/v4.6.0...v4.7.0
[4.6.0]: https://github.com/perriera/extras/compare/v4.5.0...v4.6.0
[4.5.0]: https://github.com/perriera/extras/compare/v4.4.0...v4.5.0
[4.4.0]: https://github.com/perriera/extras/compare/v4.3.0...v4.4.0
[4.3.0]: https://github.com/perriera/extras/compare/v4.2.0...v4.3.0
[4.2.0]: https://github.com/perriera/extras/compare/v4.1.0...v4.2.0
[4.1.0]: https://github.com/perriera/extras/compare/v4.0.0...v4.1.0
[4.0.0]: https://github.com/perriera/extras/compare/v3.30.0...v4.0.0
[3.30.0]: https://github.com/perriera/extras/compare/v3.29.0...v3.30.0
[3.29.0]: https://github.com/perriera/extras/compare/v3.28.0...v3.29.0
[3.28.0]: https://github.com/perriera/extras/compare/v3.27.0...v3.28.0
[3.27.0]: https://github.com/perriera/extras/compare/v3.26.0...v3.27.0
[3.26.0]: https://github.com/perriera/extras/compare/v3.25.1...v3.26.0
[3.25.1]: https://github.com/perriera/extras/compare/v3.25.0...v3.25.1
[3.25.0]: https://github.com/perriera/extras/compare/v3.24.0...v3.25.0
[3.24.0]: https://github.com/perriera/extras/compare/v3.23.0...v3.24.0
[3.23.0]: https://github.com/perriera/extras/compare/v3.22.0...v3.23.0
[3.22.0]: https://github.com/perriera/extras/compare/v3.21.0...v3.22.0
[3.21.0]: https://github.com/perriera/extras/compare/v3.20.0...v3.21.0
[3.20.0]: https://github.com/perriera/extras/compare/v3.19.0...v3.20.0
[3.19.0]: https://github.com/perriera/extras/compare/v3.18.0...v3.19.0
[3.18.0]: https://github.com/perriera/extras/compare/v3.17.0...v3.18.0
[3.17.0]: https://github.com/perriera/extras/compare/v3.16.0...v3.17.0
[3.16.0]: https://github.com/perriera/extras/compare/v3.15.0...v3.16.0
[3.15.0]: https://github.com/perriera/extras/compare/v3.14.2...v3.15.0
[3.14.2]: https://github.com/perriera/extras/compare/v3.14.1...v3.14.2
[3.14.1]: https://github.com/perriera/extras/compare/v3.14.0...v3.14.1
[3.14.0]: https://github.com/perriera/extras/compare/v3.13.0...v3.14.0
[3.13.0]: https://github.com/perriera/extras/compare/v3.12.0...v3.13.0
[3.12.0]: https://github.com/perriera/extras/compare/v3.11.0...v3.12.0
[3.11.0]: https://github.com/perriera/extras/compare/v3.10.0...v3.11.0
[3.10.0]: https://github.com/perriera/extras/compare/v3.8.2...v3.10.0
[3.8.2]: https://github.com/perriera/extras/compare/v3.8.1...v3.8.2
[3.8.1]: https://github.com/perriera/extras/compare/v3.8.0...v3.8.1
[3.8.0]: https://github.com/perriera/extras/compare/v3.7.0...v3.8.0
[3.7.0]: https://github.com/perriera/extras/compare/v3.6.0...v3.7.0
[3.6.0]: https://github.com/perriera/extras/compare/v3.5.1...v3.6.0
[3.5.1]: https://github.com/perriera/extras/compare/v3.5.0...v3.5.1
[3.5.0]: https://github.com/perriera/extras/compare/v3.4.0...v3.5.0
[3.4.0]: https://github.com/perriera/extras/compare/v3.3.1...v3.4.0
[3.3.1]: https://github.com/perriera/extras/compare/v3.3.0...v3.3.1
[3.3.0]: https://github.com/perriera/extras/compare/v2.2.1...v3.3.0
[3.2.1]: https://github.com/perriera/extras/compare/v2.3.7...v3.2.1
[3.2.0]: https://github.com/mattcoding4days/extras/compare/v3.1.0...v3.2.0
[3.1.0]: https://github.com/mattcoding4days/extras/compare/v3.0.0...v3.1.0
[3.0.0]: https://github.com/mattcoding4days/extras/compare/v2.3.9...v3.0.0
[2.3.7]: https://github.com/perriera/extras/compare/v2.3.6...v2.3.7
[2.3.6]: https://github.com/perriera/extras/compare/v2.3.5...v2.3.6
[2.3.5]: https://github.com/perriera/extras/compare/v2.3.4...v2.3.5
[2.3.4]: https://github.com/perriera/extras/compare/v2.3.3...v2.3.4
[2.3.3]: https://github.com/perriera/extras/compare/v2.2.3...v2.3.3
[2.2.3]: https://github.com/perriera/extras/compare/v2.2.2...v2.2.3
[2.2.2]: https://github.com/perriera/extras/compare/v2.2.1...v2.2.2
[2.2.1]: https://github.com/perriera/extras/compare/v2.2.0...v2.2.1
[2.2.0]: https://github.com/perriera/extras/compare/v2.1.0...v2.2.0
[2.1.0]: https://github.com/perriera/extras/compare/v2.0.0...v2.1.0
[2.0.0]: https://github.com/perriera/extras/compare/v1.2.4...v2.0.0
[1.2.4]: https://github.com/perriera/extras/compare/v1.2.3...v1.2.4
[1.2.3]: https://github.com/perriera/extras/compare/v1.2.2...v1.2.3
[1.2.2]: https://github.com/perriera/extras/compare/v1.2.1...v1.2.2
[1.2.1]: https://github.com/perriera/extras/compare/v1.1.1...v1.2.1
[1.1.1]: https://github.com/perriera/extras/compare/v1.0.1...v1.1.1
[1.0.1]: https://github.com/perriera/extras/compare/v1.0.0...v1.0.1
[1.0.0]: https://github.com/perriera/extras/compare/v0.1.3...v1.0.0
[0.1.3]: https://github.com/perriera/extras/compare/v0.1.2...v0.1.3
[0.1.2]: https://github.com/perriera/extras/compare/v0.1.1...v0.1.2
[0.1.1]: https://github.com/perriera/extras/releases/tag/v0.1.1
