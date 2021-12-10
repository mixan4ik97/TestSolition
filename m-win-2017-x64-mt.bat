@ECHO OFF
setlocal EnableDelayedExpansion && pushd .& set RET=0

rem ---------- VS2017 command propmpt --------------
echo Locating required Visual studio...
if /i "%PROCESSOR_ARCHITECTURE%"=="x86" (
  set "VSWHERE=%ProgramFiles%\Microsoft Visual Studio\Installer\vswhere.exe"
) else (
  set "VSWHERE=%ProgramFiles(x86)%\Microsoft Visual Studio\Installer\vswhere.exe"
)
IF EXIST "%VSWHERE%" (
  echo * vswhere.exe located, path = "%VSWHERE%"
) ELSE (
  set RET=102
  ECHO * vswhere.exe not found
  goto :EXITCMD
)
for /d %%I in ("%VSWHERE%") do set VSWHERE=%%~sI
for /F "tokens=*" %%I in ('%VSWHERE% -version "[15.0,16.0)" -property installationPath') do set "VS150COMNTOOLS=%%I"

if NOT EXIST "%VS150COMNTOOLS%" (
  echo * Required Visual Studio or its component was not found
  set RET=103
  goto :EXITCMD
)
set "VS150COMNTOOLS=%VS150COMNTOOLS%\Common7\Tools"
echo * Launching VS command prompt %VS150COMNTOOLS%.
IF EXIST "%VS150COMNTOOLS%\VsDevCmd.bat" (
  call "%VS150COMNTOOLS%\VsDevCmd.bat"
)
echo * OK
echo *

rem -------- CMake-x64
echo * Run cmake-x64 MT 
SETLOCAL
del /f /s /q build-vs-2017-x64-mt >NUL 2>&1
rd /f /s /q build-vs-2017-x64-mt >NUL 2>&1
mkdir build-vs-2017-x64-mt
cd build-vs-2017-x64-mt
set PreferredToolArchitecture=x64
cmake -DUSE_STATIC_MSVC_CRT=ON -DCMAKE_GENERATOR_PLATFORM=x64 -G "Visual Studio 15 2017" ..
if ERRORLEVEL 1 ( set RET=104& goto :EXITCMD )
cd ..
ENDLOCAL
echo * OK
echo.

rem -------- Build
echo * Building for vs2017-x64-mt
SETLOCAL
cd build-vs-2017-x64-mt
set PreferredToolArchitecture=x64
cmake --build . -j %NUMBER_OF_PROCESSORS% -- /property:Configuration=Release
if ERRORLEVEL 1 ( set RET=104& goto :EXITCMD )
cd ..
ENDLOCAL
echo * OK
echo.

rem -------- Exit
:EXITCMD
POPD
if !RET! NEQ 0 (
  echo Error: %SCRIPTNAME% failed with code %RET%
  if !RET! NEQ -1 if not DEFINED TEAMCITY_VERSION pause
)
exit /b %RET%