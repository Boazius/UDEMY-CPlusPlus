# Section 6 - Variables
![Alt text](images/whatIsVar.png)
It's basically a location in memory (RAM), we give a name to so that we dont need to specify the address.
![Alt text](images/WhatIsVar2.png)

## Declaring Variables and Initializing 

To declare a variable, the syntax is ```VariableType VariableName;```
```c++
//builtin types
int num;
bool yes_or_no;
char letter;
string str;

// our own declared types
Account franks_Acc;
```

![Alt text](images/rulesNamingVar.png)
these are the laws, but its important to have a consistent style:
- camelCase or under_score_names, not both
- dont begin names with _, this is reserved for certain special variables
- not too long/short/noMeaning
- never use a variable before init, because it has some garbage data
- dont use obscure abbrivieations
- declare variables right before you use them

![Alt text](images/initVar.png)
the instructor encourages the int age {21} style, because it is consistent in c++11 and onwards

