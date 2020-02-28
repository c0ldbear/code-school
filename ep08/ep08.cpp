#include <string>
#include <memory>
#include <iostream> 

void stringExample();

int main() 
{
    stringExample();

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
