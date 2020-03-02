#include <iostream>

int main() {
    // Part 01 of Episode
    int numberOfMonkeys = 10;
    bool True = false;
    char A = 'A';
    float money = 104.52;

    // Display the output of the variables
    std::cout << "int numberOfMonkeys = " << numberOfMonkeys << std::endl;
    std::cout << "bool True = " << True << std::endl;
    std::cout << "char A = " << A << std::endl;
    std::cout << "float money = " << money << std::endl;

    // Part 02 of Episode
    int health = 100;

    if (health > 50)
    {
        health = 0;
    }
    else
    {
        health = 100;
    }

    {
        int dmg = 25;
        health -= dmg;
    }
    
    // "homework"
    int i = 10;
    float f = 200.2123;
    std::cout << "int + float = " << i + f << std::endl;

    char c = 'a';
    std::cout << "char c = " << c << ", ";
    std::cout << "int + char = " << i + c << std::endl;

    if (i < c)
    {
        std::cout << "smaller!" << std::endl;
    }
    else
    {
        std::cout << "bigger!" << std::endl;
    }
    
    bool b = true;
    bool not_b = false;
    std::cout << "int + bool = " << i + b << " and int + not bool = " << i + not_b << std::endl;

    std::cout << "not_b = " << not_b << " as int? " << (int)not_b << std::endl;
    {
        not_b = true;
        std::cout << "not_b changed! " << not_b << std::endl;
        int q = 120;
        std::cout << "q = " << q << std::endl;
    }

    int q = 80;
    std::cout << "q = " << q << std::endl; // ERROR: q only exists in above 

    std::cout << std::endl;
}

