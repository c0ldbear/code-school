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


void combat() 
{
    int health = 100;
    int damage = 50;
    
    // some code doing some stuff

    int result = take_damage(health, damage);

    // some code doing some stuff

/* Notes about combat(): stack stuff! How will the program allocate memory space in the stack?
    It will start with adding health and damage to the stack.
    As it goes to line 43 (aka int result = ...), it will then add argument_1 and argument_2 to the stack.
    Once it is inside of take_damage, it will add new_healt and result to the stack too. (?)
    Lastly, the return value is added too so we would have 5 (or 4? 4 is what is stated in the video) variables in the stack
        but once the return value is "done" and "sends the value", we are 'poping' argument_1, argument_2 and return value goes into 'int result'
        so we are left with 3 int variables in the stack.
*/
}

void somethingAboutPointers()
{
    // create a pointer variable on the stack
    int* health; // this is an INT POINTER
    // in the stack, we have space allocated for a INT POINTER (64 bits = 8 bytes address on 64-bit sys, 32 bits = 4 bytes address on 32-bit sys)

    // allocate memory on the heap
    // new return the memory address
    health = new int;

    // * will dereference the pointer
    // this means we "jump" to where
    // the memory is, and store 50 there
    *health = 50;

    // when we're done, we delete
    // because memory allocated by
    // new is not automatically 
    // cleaned when scope is over.
    delete health;

    int* health = new int(50); // "faster, simplier" way of writing a pointer
    delete health;

    /*
    Thinkable illustration:
        the POINTER is a PIECE OF PAPER with the ADDRESS to where you can BUILD A HOUSE.
        The paper holds the info of where the house can be built.

        Pointers are the same. They hold the address to where the value is stored.
        Pointers are stored in STACK, the value it has the address to is in the HEAP.
    */

   // this is the old way of doing pointers, and we'll play around with it next time.
   // we will also learn more about SMART POINTERS which is smarter and better to use.
   // e.g. we do not need to think about deleting the pointer, this is done for us.

}