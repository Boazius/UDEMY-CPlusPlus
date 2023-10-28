# Section 5 - Structure of a C++ Program
In this section we just get acquainted with some c++ basics.
These are the keywords of the language:
![Alt text](images/keywords.png)

C++ has 90 keywords!
Java has 50, C has 32..
most programmers don't use a lot of these.<br>

## The preprocessor directives
for example ```#include``` or ```#ifndef```.
- the #include command replaces the name of the file with the contents of the file, and is very useful!

the c++ preprocessor doesn't understand c++, it just completes the command that has been defined for it

## Comments
explanations in the source code, this doesn't go to compiler at all, its just for the programmers.


```c++
// This is a single line comment

/* This is a multi
            line comment */

```
keep your commenting style consistent! don't keep useless or outdated comments


## The Main Function
![Alt text](images/main.png)

- argc is the number of arguments
- argv[] is an array of the arguments (strings)

## Coding Standards and Best Practices
programmers have certain standards so that code is readable and less error prone
you can read a bunch here
https://isocpp.org/

also, in VSCode use format document, or ```SHIFT+ALT+F``` to format it better. this uses Clang formatter extension that i installed