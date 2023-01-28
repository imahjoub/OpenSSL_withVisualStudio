:: -----------------------------------------------------
::  Copyright Iliass Mahjoub 2023.                     
::  Distributed under the Boost Software License,      
::  Version 1.0. (See accompanying file LICENSE_1_0.txt
::  or copy at http://www.boost.org/LICENSE_1_0.txt)   
:: -----------------------------------------------------

@echo off

::echo "Run Build_OpenSSL_Lib.bat %1 %2"

echo "print perl version"
perl -v

echo "print perl help"
perl --help

:: TBD make this relativ
::call "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvarsall.bat" x86_amd64

set OpenSSL_Dir=%0
set Configuration=%1
set Platform=%2

echo %OpenSSL_Dir%
echo %Configuration%
echo %Platform%


::if NOT x%Configuration:Debug=%==x%Configuration% (
::echo "Build %Configuration% %Platform%"
::perl Configure VC-WIN64A --prefix=%OpenSSL_Dir%\_Bin\%Configuration%_%Platform% --openssldir=%OpenSSL_Dir% no-shared
::nmake install_sw
::
::) else (
::echo "Build %Configuration% %Platform%"
::perl Configure VC-WIN64A --prefix=%OpenSSL_Dir%\_Bin\%Configuration%_%Platform% --openssldir=%OpenSSL_Dir% no-shared
::nmake install_sw
::)
