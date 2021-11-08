# Changelog
> All notable changes to this project will be documented in this file.</br>
The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/), and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).</br>
> To add a tag to the git repository do:
> > git tag -a v4.14.0 -m "RequestTypeCompilerInterface"</br>
> > git push origin v4.14.0
> >
>
> > POPULAR LINKS:
> https://zed0.co.uk/clang-format-configurator/
>

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
- Update Doxygen content
- dev branch added

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
- extras:: in front of __INFO__ macro

#### 3.5.0 (2021-08-11)
### Removed
- spdlog from CMakeLists.txt

#### 3.4.0 (2021-08-11)
### Added 
- CustomExceptionInterface
  * [Exception handling syntax](https://en.wikipedia.org/wiki/Exception_handling_syntax)
- AbstractCustomException
  * [Abstract factory pattern](https://en.wikipedia.org/wiki/Abstract_factory_pattern)
- SpecificCustomException
  * An example of how to implemnts a specific custom exception
- GroupCustomException
  * An example of how to group custom exceptions, (into types of exceptions)
- OctalException 
  * An example of how custom exceptions are used and how to use assertion() methods
  * [Octal format](https://en.wikipedia.org/wiki/Octal)

#### 3.3.1 (2021-08-10)
### Corrected
- Compare links for 3.3.0

#### 3.3.0 (2021-08-10)
### Added
- OctalInterface, (needed by chessmind)
  * [chessmind is now undergoing a refit on new CMakeLists.txt format](https://github.com/perriera/chessmind)
- mock_octal.cpp, (needed by developers)
  * [how to use mocks effectively](https://github.com/eranpeer/FakeIt)
### Changed
- .clang-format started acting up and The Cure was found here:
   * [clang-format configuratot](https://zed0.co.uk/clang-format-configurator/)

#### 3.2.1 (2021-08-09)
### Updated
- README.md

#### 3.2.0 (2021-08-09)
### Added
- Added Popular header only libraries are bundled in the library under the extras/vendor
  * [cxxpots v2.2.0 for command line parsing](https://github.com/jarro2783/cxxopts)
  * [nlohmann/json v3.9.1 for first class json support](https://github.com/nlohmann/json)
- Addded Popular logging and fmt libraries as that are installed on the system but not bundled
  * [spdlog v1.9.1 for logging, also comes bundled with fmtlib](https://github.com/gabime/spdlog)
  * [fmtlib 8.0.1 faster than iostream and printf](https://github.com/fmtlib/fmt)
- Added CPM, cmakes missing package manager
  * [CPM a thin wrapper around Fetch_Content](https://github.com/cpm-cmake/CPM.cmake)
- Added clang-format and cmake-format files, using Googles style guidelines
- Added Interprocedural optimization support to cmake file.
- Added new project options that can be called from command line, or in cmake file
  * -DBUILD_TESTS=<OFF, ON> defaults to ON,
  * -DDEBUG=<OFF, ON> defaults to ON
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

[Unreleased]: https://github.com/perriera/extras/compare/v4.14.0...HEAD
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
