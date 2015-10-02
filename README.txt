=============================================================================
SECTION 1. Directories structure
=============================================================================
 [+] ROOT
  |-[+] Docs
  |  |- Application Settings Design.docx
  |  |- My180Cam_classes_diagram.uml ==> created with StarUML v5.0.2.1570
  |  
  |-[+] Setup
  |  |- INI files installer.exe
  |	 
  |-[+] SourceCode
     |-[+] SoftwareSettings
	 |  |- SoftwareSettings.sln
	 |  |- SoftwareSettings.pro
	 |  |- (...) 
	 |
	 |-[+] TestSettings
	 |  |- TestSettings.pro
	 |	|- (...)
	 |
	 |- Main.pro
	 |- build_from_qtpro.bat
	 
=============================================================================
SECTION 2. Environment Setup
=============================================================================
STEP 1. Install required tools:
1. Qt5.2.1 msvc2012 x86
2. QtCreator (Optional)
3. Microsoft Visual Studio 2012 (Optional)
4. Qt VSAddin (Optional)

STEP 2. Install INI-files for testing
Perform installation using %Root%\Setup\INI files installer.exe.

INI files will be installed to locations:
C:\Users\%USER%\AppData\Roaming\Ukrainian Power\My180Cam.ini 
C:\ProgramData\Ukrainian Power\My180Cam.ini

NOTE: "INI files installer.exe" is InstallShield installer, so 
Uninstall can be done to remove INI files from your PC.


=============================================================================
SECTION 3. Build instruction
=============================================================================
There are three approaches to build deliverables: 
1) Using Visual Studio 2) Using QtCreator 3) Using build_from_qtpro.bat

APPROACH 1. QtCreator
1. Open %Root%\SourceCode\Main.pro using QtCreator
2. Build solution

APPROACH 2. Build script
1. Launch command prompt
2. cd %Root%\SourceCode
3. run build_from_qtpro.bat with one of the arguments: "debug" or "release"

APPROACH 3. Visual Studio
1. Open %Root%\SourceCode\SoftwareSettings\SoftwareSettings.sln in Visual Studio
2. Using Qt VSAddin, register Qt version with name "Qt5.2.1"
3. Build solution

==============================================================================
SECTION 4. Deliverables
==============================================================================
After build, deliverables will be copied to 
%Root%\SourceCode\Debug and %Root%\SourceCode\Release

There will be two files:
1. SoftwareSettings.lib
2. TestSettings.exe

TestSettings.exe is very simple test application, 
it runs only one unit-test case - change settings values
and checks that settings are actually modified.

==============================================================================
END
==============================================================================





