@ECHO off

IF /I "%1"=="debug" GOTO Start
IF /I "%1"=="release" GOTO Start

ECHO First argument should be 'debug' or 'release'
GOTO END

:Start
@rem setting environment vars for vc tools
@call "%VS110COMNTOOLS%..\\..\\VC\\vcvarsall.bat" x86

rem creating makefile

IF /I "%1"=="debug" "%QTDIR%\\5.2.1\\msvc2012\\bin\\qmake.exe" main.pro -r -spec win32-msvc2012 "CONFIG+=%1" "CONFIG+=declarative_%1" "CONFIG+=qml_%1"
IF /I "%1"=="release" "%QTDIR%\\5.2.1\\msvc2012\\bin\\qmake.exe" main.pro -r -spec win32-msvc2012 "CONFIG+=%1" "CONFIG+=declarative_%1" "CONFIG+=qml_%1" "DEFINES+=NDEBUG"

rem building the project from makefile
"%QTDIR%\\Tools\\QtCreator\\bin\\jom.exe" %1
