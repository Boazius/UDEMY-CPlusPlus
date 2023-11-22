#include <iostream>

int main() {
    

    //get room width
    int room_width {0};
    std::cout << "Enter the width of the room" << std::endl;
    std::cin >> room_width;
    
    //get room length
    int room_length {0};
    std::cout << "Enter the length of the room" << std::endl;
    std::cin >> room_length;

    // get area of the room
    std::cout << "The Area of the room is " << room_length*room_width << std::endl;


    
}