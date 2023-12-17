#include <iostream>
#include <vector>

int main()
{
    using std::cin;
    using std::cout;
    using std::endl;
    using std::vector;

    vector<int> vector1;
    vector<int> vector2;
    vector1.push_back(10);
    vector1.push_back(20);
    cout << "vector1 is {" << vector1.at(0) << "," << vector1.at(1) << "}\n";
    cout << "The size of vector1 is " << vector1.size() << endl;

    vector2.push_back(100);
    vector2.push_back(200);
    cout << "vector2 is {" << vector2.at(0) << "," << vector2.at(1) << "}\n";
    cout << "The size of vector2 is " << vector2.size() << endl;

    vector<vector<int>> vector_2d;
    vector_2d.push_back(vector1);
    vector_2d.push_back(vector2);

    // display vector_2d:
    cout << "vector_2d is \n{\n"
         << "   {" << vector_2d.at(0).at(0) << ',' << vector_2d.at(0).at(1) << "},\n"
         << "   {" << vector_2d.at(1).at(0) << ',' << vector_2d.at(1).at(1) << "}\n"
         << "}\n";

    vector1.at(0) = 1000;

    // display vector_2d:
    cout << "vector_2d is \n{\n"
         << "   {" << vector_2d.at(0).at(0) << ',' << vector_2d.at(0).at(1) << "},\n"
         << "   {" << vector_2d.at(1).at(0) << ',' << vector_2d.at(1).at(1) << "}\n"
         << "}\n";

    cout << "vector1 is {" << vector1.at(0) << "," << vector1.at(1) << "}\n";

    return 0;
}