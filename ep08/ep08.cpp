#include <string>
#include <memory>
#include <iostream> 

void stringExample();
void shared_ptrExample(); // there is another smart pointer too: unique pointer

int main() 
{
    stringExample();
    shared_ptrExample();

    return 0;
}

void stringExample()
// Trying out example from the video before code-along part
{
    std::string name = "Teddy";
    std::cout << name << "\n";

    std::string aLongOne = name + " is the best in the whole world because the person just is that. The best. In. The. World.";
    std::cout << aLongOne << "\n";

    if (name.empty())
    {
        return;
    }

    std::string shortName = name.substr(0, 3);
    std::cout << shortName << "\n";

}

int GetIntFromSharedPtr(std::shared_ptr<int> aPointer);

void shared_ptrExample()
{
    std::shared_ptr<int> health = std::shared_ptr<int>(new  int);
    // the whole `std::shared_ptr<int>` is the DATA TYPE as if it would have been
    // `int` or `char` or `float`.
    *health = 100;

    std::shared_ptr<int> damage = std::shared_ptr<int>(new int(22));
    // another way of assigning a shared_ptr

    std::shared_ptr<int> mana(new int);
    *mana = GetIntFromSharedPtr(health);
    // a third way of assigning a shared_ptr

    auto alive = std::make_shared<bool>(true);
    // a fourth way of assigning a shared_ptr where we also use `auto` which
    // can be thought of as "I don't really care what it is but it needs to be something".

    auto weapon = std::make_shared<std::string>();
    // a fifth way of assigning a shared_ptr (with `auto` again)
    *weapon = "Axe";

    std::cout << "Health\t: " << *health << "\n";
    std::cout << "Mana\t: " << *mana << "\n";
    std::cout << "Damage\t: " << *damage << "\n";
    std::cout << "Alive\t: " << *alive << "\n";
    std::cout << "Weapon\t: " << *weapon << "\n";
    
}

int GetIntFromSharedPtr(std::shared_ptr<int> aPointer)
{
    if (!aPointer)
    {
        return 0;
    }

    return *aPointer;

}
