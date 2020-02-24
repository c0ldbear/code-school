#include <iostream>

int take_damage(int health, int damage);

int main() 
{

    std::cout << take_damage(100, 11) << " health left after taking damage.\n";

    return 0;
}

int take_damage(int health, int damage)
{
    int new_health = health;

    new_health = new_health - damage; // could have written: `new_health -= damage`

    return new_health;
    // How many variables are there in this function? A: 4 (return is a variable too)
    // How big is the function? A: 4 bytes times 4 variables (int - 4 bytes) = 16 bytes (i.e. how much memory does it take)
    // What is the variable that is returned? A: It is `return new_health`, it does not have a name but it is still a variable (int)
    // How big is the return variable? A: 4 bytes, since it is an int

}

/* Notes from the video! */

    // found in the stack:
    // return value - 4 bytes
    // damage value - 4 bytes
    // health value - 4 bytes
    // new health   - 4 bytes
