# OpenSSL_withVisualStudio
This repository helps you to build and use OpenSSL in Visual Studio
The vcxproj file of OpenSSL_Lib is built with help of [vcxproj_generator](https://github.com/imahjoub/vcxproj_generator)

## Using OpenSSL_withVisualStudio

### Required tools
  - Visual Studio
  - Install and Make Perl available via the PATH settings

### Build the Librarie OpenSSL_lib
First you need to build the following two targets, in order to generate the libs and headers
  - OpenSSL_Lib_Debug
  - OpenSSL_Lib_Release

### How to use OpenSSL_Test
After generating the libs/headers you can now use the sha256 example in OpenSSL_Test project.

