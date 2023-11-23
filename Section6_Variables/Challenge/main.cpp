#include <iostream>

const unsigned short HUNDRED {100};

int main(int argc, const char** argv)
{
    using namespace std;
    const unsigned short smallRoomPrice {25};
    const unsigned short largeRoomPrice {35};
    const unsigned short salesTaxPercentage {6};
    const unsigned short estimateValidTime {30};


    // Greet user
    cout << "Welcome to Boaz's cleaning service\n";
    cout << "Charges:\n";
    cout << "   $"<<smallRoomPrice<<" per small room\n";
    cout << "   $"<<largeRoomPrice<<" per large room\n";
    cout << "Sales tax rate is "<< salesTaxPercentage << "%\n";
    cout << "Estimates are valid for "<<estimateValidTime <<" days\n";

    // Get data from user 
    cout << "Please enter how many small rooms would you like cleaned\n";
    short smallRoomCount {0};
    cin >> smallRoomCount;
    cout << "Please enter how many large rooms would you like cleaned\n";
    short largeRoomCount {0};
    cin >> largeRoomCount;

    // output estimate to user
    cout << "Estimate for carpet cleaning service:\n";
    cout << "Number of small rooms: " << smallRoomCount <<endl;
    cout << "Number of large rooms: " << largeRoomCount <<endl;
    cout << "Price per small room: $" << smallRoomPrice << endl;
    cout << "Price per small room: $" << largeRoomPrice << endl;

    int costBeforeTax = smallRoomPrice * smallRoomCount + largeRoomPrice * largeRoomCount;
    int taxCost = costBeforeTax * salesTaxPercentage / HUNDRED;
    int totalCost = taxCost + costBeforeTax;

    cout << "Cost : $" << costBeforeTax << endl;
    cout << "Tax : $" << taxCost <<endl;
    cout << "===================================\n";
    cout << "Total estimate: $" << totalCost <<endl;
    cout << "This estimate is valid for "<<estimateValidTime << " days\n";


    return 0;
}