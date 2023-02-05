OpenSSL_withVisualStudio
==================

<p align="center">
    <a href="https://github.com/imahjoub/OpenSSL_withVisualStudio/actions/workflows/OpenSSL_Test_codeql.yml">
        <img src="https://github.com/imahjoub/OpenSSL_withVisualStudio/actions/workflows/OpenSSL_Test_codeql.yml/badge.svg" alt="CodeQL"></a>
    <a href="https://github.com/imahjoub/OpenSSL_withVisualStudio/issues?q=is%3Aissue+is%3Aopen+sort%3Aupdated-desc">
        <img src="https://custom-icon-badges.herokuapp.com/github/issues-raw/imahjoub/OpenSSL_withVisualStudio?logo=github" alt="Issues" /></a>
    <a href="https://github.com/imahjoub/OpenSSL_withVisualStudio" alt="GitHub code size in bytes">
        <img src="https://img.shields.io/github/languages/code-size/imahjoub/OpenSSL_withVisualStudio" /></a>
    <a href="https://github.com/imahjoub/OpenSSL_withVisualStudio/blob/main/LICENSE_1_0.txt">
        <img src="https://img.shields.io/badge/license-BSL%201.0-blue.svg" alt="Boost Software License 1.0"></a>
    <a href="https://github.com/imahjoub/OpenSSL_withVisualStudio" alt="Activity">
        <img src="https://img.shields.io/github/commit-activity/y/imahjoub/OpenSSL_withVisualStudio" /></a>
</p>

This repository helps you to build and use OpenSSL with Visual Studio.  <br>

The vcxproj file of OpenSSL_Lib is built with help of [vcxproj_generator](https://github.com/imahjoub/vcxproj_generator)

## Using OpenSSL_withVisualStudio

### Required tools
  - Visual Studio
  - Install and Make Perl available via the PATH settings
  - Update the path to VS Command Prompt in Build_OpenSSL_Lib.bat (line 13)

### Build the library OpenSSL_Lib
Build the following targets, in order to generate openssl libs and headers. <br>
  - OpenSSL_Lib_Debug
  - OpenSSL_Lib_Release

### Use openssl code in visual studio
After generating the libs/headers you can use OpenSSL_Test as a template to get access to the openssl API-functions and code.

OpenSSL_Test project provides a sha256-example
