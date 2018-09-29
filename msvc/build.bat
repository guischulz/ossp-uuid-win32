@echo off
setlocal

rem Visual Studio 2017 build tools
call "C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Auxiliary\Build\vcvars64.bat"

pushd %~dp0
msbuild uuid.sln /p:Configuration="Release" /p:Platform=x64
popd