# Section 0 - Setting up
In this section im just figuring out how to set up the c++ compiler.

- I'm gonna be using [Visual Studio code IDE](https://code.visualstudio.com/).
- I used [MSYS2](https://www.msys2.org/) to install the relevant compilers.
  - and then added \msys64\ucrt64\bin to PATH for easy access to g++
- I installed the recommended C/C++ extetension pack on VSCode


## Building and running using VSCode

### Make folders and files
- Open the *Section* folder using VSCode
- Create a new folder for the Project inside the SectionX, i.e Section1/Proj1
- Create .cpp file inside the proj1 folder, i.e main.cpp
- open it and configure the intellisence for g++ if needed
- make some Hello world program:

```c++
// hello world!
#include <iostream>
using namespace std;

int main()
{
    cout << "Hello from main proj1" << endl;
    return 0;
}
```

### Configure
- Select the main.cpp file
- Press Ctrl+Shift+P for the Command palette
  - Select C/C++: Edit Configurations (UI)
- Compiler Path should be g++, not gcc
- Intellisense mode should be windows-gcc-x64
- For the c++ standard, course says to use c++17, but im gonna be bold and use **C++20**
  - This creates a .vscode folder in sectionx, and a file called c_cpp_properties.json file for these configs. they must be done for each **section** we will open in vscode, but are not needed for each **project**


#### Now, we will configure Default Build Task for building the c++ files:
Click on Terminal and press Configure Default Build Task
  - use g++
- This created a tasks.json file.
  In this file, after the "-g" arg, add these args: "-Wall", "-std:=c++20"
- and instead of ${file}, use ${fileDirname}\\*.cpp  , to compile *Every* cpp file in the folder where our active cpp file is located

### Run Build

Click on Terminal, and Run Build Task (or just CTRL+SHIFT+B) to build the file(s) into an exe

now to run the exe simply navigate in the terminal to the project folder and ```./main.exe```


## Debugging:
