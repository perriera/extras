# Changelog
> All notable changes to this project will be documented in this file.</br>
The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/), and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).</br>
> To add a tag to the git repository do:
> > git tag -a v0.1.2 -m "my version 0.1.2"</br>
> > git push origin v0.1.2
> >

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

[Unreleased]: https://github.com/perriera/extras/compare/v3.5.0...HEAD
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
