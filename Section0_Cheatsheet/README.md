# C++ Cheatsheet

This cheat sheet provides a quick reference to important concepts in C++ that might not be immediately apparent to beginners. It's designed to help you understand and remember key concepts as you learn and work with C++.

### Main function

```c++
#include <iostream>

int main(int argc, char *argv[])
{
    return 0;
}
```
---

### Pointers:

- Declaration of pointers: `int* ptr;`
- Address-of operator: `&variable`
- Dereference operator: `*ptr`
- Dynamic memory allocation: `new` and `delete`
- Null pointers: `nullptr` (preferred) or `NULL`

### References:
- Reference declaration: `int& ref = variable;`
- References are aliases, not new variables
- Cannot be reassigned after initialization
- Commonly used for function parameters
---

## Namespaces
```c++
#include <iostream>

using namespace std; //use entire std namespace - NOT RECOMMENDED
using std::cout; // use just cout
using std::cin; // use just cin

int main()
{
    std::cout << "Whats up?"<< std::endl; // without using
    cout << "Whats up?"<< endl; // with using
    return 0;
}

//defining
namespace Q
{
    void f()
    {
        std::cout << "heuy";
    }
}
//using
Q::f();

```

## Consts
For variables:
```c++
const int x = 10;
// x = 20; // Error: Cannot modify a const variable
```
for functions:
```c++
class MyClass {
public:
    void NonConstFunction() { /* ... */ }
    void ConstFunction() const { /* ... */ } // Const member function
};

const MyClass obj;
obj.NonConstFunction(); // Error: Cannot call a non-const function on a const object
obj.ConstFunction();    // Okay: Can call a const function on a const object
```

for function input
```c++
void myFunc(const int a) {
    // a = 10; // Error: Cannot modify a const parameter 'a'
    // You can use 'a' for read-only operations
    int b = a * 2; // Okay: Reading 'a' is allowed
    // ...
}

int main() {
    int x = 5;
    myFunc(x); // Pass 'x' to myFunc as a constant integer
    return 0;
}
```
### constexpr
is evaluated at *compile time*.
```c++
constexpr int Square(int x) {
    return x * x;
}

int result = Square(5); // Computed at compile time
constexpr int y = 20; //compile-time constant
```

## Arrays
We cannot use non constant variables to declare an array size!
```c++
int a;
cin >> a;
int b[a]; // THIS IS INVALID because a is a variable whose value is determined at runtime.

#include <vector>
vector<int> arr(a) // better, arr is of size 5 and initialized to 0
vector<int> allHunderds(300,100) // 300 values , all initialized to 100
```

## casting
```c++
double avg{0.00};
avg = static_cast<double>(100) / 8; // cast 100 (an integer) to 100.0 (double) so that the calculation will work correctly (not integer division)
```