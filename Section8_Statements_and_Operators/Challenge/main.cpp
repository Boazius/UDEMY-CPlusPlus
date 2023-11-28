/*
write a program that asks the user to enter an integer num of cents
assume that it is >= 0

display how to provide change:

- 1 dollar is 100 cents
- 1 quarter is 25 cents
- 1 dime is 10 cents
- 1 nickel is 5 cents
- 1 penny is 1 cent
*/

#include <iostream>


int main(int argc, char const *argv[])
{
    using std::cout;
    using std::cin;
    using std::endl;

    // consts:
    const int DOLLAR_VALUE{100};
    const int QUARTER_VALUE{25};
    const int DIME_VALUE{10};
    const int NICKEL_VALUE{5};
    const int PENNY_VALUE{1};

    
    //enter cents
    int balance{0};

    cout << "Enter an amount in cents: " <<endl;
    cin >> balance;

    // calculate change

    int dollarCount {balance/DOLLAR_VALUE};
    balance %= DOLLAR_VALUE;
    int quarterCount {balance/QUARTER_VALUE};
    balance %= QUARTER_VALUE;
    int dimeCount {balance/DIME_VALUE};
    balance %= DIME_VALUE;
    int nickelCount {balance/NICKEL_VALUE};
    balance %= NICKEL_VALUE;
    int pennyCount {balance/PENNY_VALUE};
    balance %= PENNY_VALUE;

        
    //display output

    cout << "Here is your change: \n";
    cout << "Dollars: " << dollarCount <<endl;
    cout << "Quarters: " << quarterCount <<endl;
    cout << "Dimes: " << dimeCount <<endl;
    cout << "Nickels: " << nickelCount <<endl;
    cout << "Pennies: " << pennyCount <<endl;



    return 0;
}
