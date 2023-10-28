# Section 4 - Writing Programs and Types of Errors

this section is about compilation, linking, and runtime errors.

to create c++ code, there are three stages:

## Compiling
we use g++ to create .o files from each .cpp file.
this .o file has all the code in the cpp file, and ALSO has any file we \#include there, which is typically .h files, and libraries.

the command for g++ is 
```shell
g++.exe -c -fdiagnostics-color=always -g -Wall -std=c++20 *.cpp
```

the -c tag meaning it just compiles (creates .o files), doesnt link
the -g tag enables debugging info to be included in the compiled object files

A task for visual studio that does this is
```json
{	
    "label": "g++ compile all .cpp files into .o files",
            "type": "cppbuild",
            "command": "C:/msys64/ucrt64/bin/g++.exe",
            "args": [
                "-c",
                "-fdiagnostics-color=always",
                "-g",
                "-Wall",
                "-std=c++20",
                "*.cpp"
            ],
            "options": {
                "cwd": "${fileDirname}"
            },
            "group": "build",
            "problemMatcher": ["$gcc"],
            "detail": "compiling all cpp files to object files in the current folder"
}
```

you can also compile a single file with this one:
```json
{	"label": "g++ compile current single file into .o ",
    "type": "cppbuild",
    "command": "C:/msys64/ucrt64/bin/g++.exe",
    "args": [
        "-c",
        "-fdiagnostics-color=always",
        "-g",
        "-Wall",
        "-std=c++20",
        "${file}",
        "-o",
        "${fileDirname}/${fileBasenameNoExtension}.o"
    ],
    "group": "build",
    "problemMatcher": ["$gcc"],
    "detail": "compiling ${file} to .o file"
}
```

## Linking
once we have .o files, we can link them all into a .exe file
the command for this is 
```shell
g++.exe folder_path/*.o -o path/exe_name.exe
```
and a task for that in vscode is:
```json
{	"label": "g++ link all .o files into .exe",
    "type": "cppbuild",
    "command": "C:/msys64/ucrt64/bin/g++.exe",
    "args": [
        "${fileDirname}/*.o",
        "-o",
        "${fileDirname}/${fileDirnameBasename}.exe"
    ],
    "options": {
        "cwd": "${fileDirname}"
    },
    "group": "build",
    "problemMatcher": ["$gcc"],
    "detail": "linking all object files into ${fileDirname}.exe"
},
```

## cleaning
we want to delete the .o and .exe files sometimes.
in windows this is a good task for it:
```json
{	
    "label": "clean .exe and .o",
    "command": "cmd",
    "args": ["/C", "del", "${fileDirname}\\*.exe", "${fileDirname}\\*.o"],
    "type": "shell",
    "group": {
        "kind": "build",
        "isDefault": true
    },
    "detail": "delete built files with .o and .exe extensions in the current folder"
}   
```

## Tasks.json predefined vars
we can use some dynamic file and folder names from this link:
https://code.visualstudio.com/docs/editor/variables-reference

The following predefined variables are supported:
- ```${userHome}``` - the path of the user's home folder
- ```${workspaceFolder}``` - the path of the folder opened in VS Code
- ```${workspaceFolderBasename}``` - the name of the folder opened in VS Code without any slashes (/)
- ```${file}``` - the current opened file
- ${```fileWorkspaceFolder```} - the current opened file's workspace folder
- ${```relativeFile```} - the current opened file relative to workspaceFolder
- ${```relativeFileDirname```} - the current opened file's dirname relative to workspaceFolder
- ${```fileBasename```} - the current opened file's basename
- ${```fileBasenameNoExtension```} - the current opened file's basename with no file extension
- ${```fileExtname```} - the current opened file's extension
- ${```fileDirname```} - the current opened file's folder path
- ${```fileDirnameBasename```} - the current opened file's folder name
- ${```cwd```} - the task runner's current working directory upon the startup of VS Code
- ${```lineNumber```} - the current selected line number in the active file
- ${```selectedText```} - the current selected text in the active file
- ${```execPath```} - the path to the running VS Code executable
- ${```defaultBuildTask```} - the name of the default build task
- ${```pathSeparator```} - the character used by the operating system to separate components in file paths

## Launching and debuggging the program
we can use a run configuration in launch.json
i used this one:
```json
{   "name": "g++ Build *.cpp and then run .exe",
    "type": "cppdbg",
    "request": "launch",
    "program": "${fileDirname}/${fileDirnameBasename}.exe",
    "args": [],
    "stopAtEntry": false,
    "cwd": "${fileDirname}",
    "environment": [],
    "externalConsole": false,
    "MIMode": "gdb",
    "miDebuggerPath": "gdb",
    "setupCommands": [
        {
            "description": "Enable pretty-printing for gdb",
            "text": "-enable-pretty-printing",
            "ignoreFailures": true
        },
        {
            "description": "Set Disassembly Flavor to Intel",
            "text": "-gdb-set disassembly-flavor intel",
            "ignoreFailures": true
        }
    ], "preLaunchTask": "g++ build exe"
}

```
```preLaunchTask``` here is the task that run before launching, and i set it to build the exe
i made a task that does this in tasks.json:
```json
{	"label": "g++ build exe",
    "type": "cppbuild",
    "command": "C:/msys64/ucrt64/bin/g++.exe",
    "args": [
        "-fdiagnostics-color=always",
        "-g",
        "-Wall",
        "-std=c++20",
        "${fileDirname}/*.cpp",
        "-o",
        "${fileDirname}/${fileDirnameBasename}.exe"
    ],
    "options": {
        "cwd": "C:/msys64/ucrt64/bin"
    },
    "problemMatcher": [
        "$gcc"
    ],
    "group": {
        "kind": "build",
        "isDefault": true
    },
    "detail": "compiles and links the .cpp files in current folder, into .exe file"
},

```

## Programs in this section
- FirstProgram - just gets number from user and prints it back out.
- CompilerErrors - Syntax and semantic errors
- CompilerWarnings - things that can still run but may be dumb, like useless variables
- LinkerErrors - when the .o files cannot be linked, for example having duplicate definitions or extern int x that isnt declared anywhere.

currently, we cant see linker errors in the problems pane, we can only see it in the terminal, which is kinda not ideal..
```shell
 *  Executing task: g++ link all .o files into .exe 

Starting build...
Executing task: g++ link all .o files into .exe 

Starting build...
C:/msys64/ucrt64/bin/g++.exe S:\Programming\UDEMY-CPlusPlus\Section4_Getting_Started\LinkerErrors/*.o -o S:\Programming\UDEMY-CPlusPlus\Section4_Getting_Started\LinkerErrors/LinkerErrors.exe
C:/msys64/ucrt64/bin/../lib/gcc/x86_64-w64-mingw32/13.1.0/../../../../x86_64-w64-mingw32/bin/ld.exe: S:\Programming\UDEMY-CPlusPlus\Section4_Getting_Started\LinkerErrors/main.o:main.cpp:(.rdata$.refptr.x[.refptr.x]+0x0): undefined reference to `x'
collect2.exe: error: ld returned 1 exit status

Build finished with error(s).

 *  The terminal process failed to launch (exit code: -1). 
```

### Runtime Errors
anything like divide by zero, or file not found - stuff that cant be determined at compile time.

### Logic Errors
are not errors per se, but they make our program run not as we intended it, these are tricky to fix.


## Challenge program
user gets prompt for favorite number
program reads number and outputs it back..