:: -----------------------------------------------------
::  Copyright Iliass Mahjoub 2023.                     
::  Distributed under the Boost Software License,      
::  Version 1.0. (See accompanying file LICENSE_1_0.txt
::  or copy at http://www.boost.org/LICENSE_1_0.txt)   
:: -----------------------------------------------------

@echo off

call "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvarsall.bat" x86_amd64

echo "Run Build_OpenSSL_Lib.bat ..."

set Configuration=%1
set Platform=%2
echo %Configuration%
echo %Platform%

echo "Setting up Build environement ..."
::cpan -i Text::Template
::cpan -i Test::More

nmake /? 


echo "Build %Configuration% %Platform%"
::perl Configure VC-WIN64A --prefix=%cd%_Bin\Lib\%Configuration%\%Platform% --openssldir=%cd% no-shared

perl Configure VC-WIN64A --prefix=%cd%\OpenSSL_Lib\_Bin\Lib\%Configuration%_%Platform% --openssldir=%cd%\OpenSSL_Lib no-shared

nmake install_sw

