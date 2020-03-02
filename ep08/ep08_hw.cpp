#include <iostream> // add output to console (std::cout)
#include <string>   // add strings! (std::string)

// HOMEWORK
// 1. Practice using std::string
//  a) use the .empty(), .size(), .clear(), and .replace() functions
//  b) How would you combine 2 strings into 1? (A: just add together with +)
//      "Olafur" "Gabe" into "OlafurGabe" for example
void stringPractice();
// 2. Practice using std::shared_ptr
//  a) Create a std::shared_ptr for all fundamental types
//  b) Make one using std::string
//  c) Send a std::shared_ptr to a function and also make a function return a std::shared_ptr 
void shared_ptrPractice();
// 3. Practice using std::vector
//  a) Create a std::vector for all fundamental types
//  b) Use the .empty(), .size(), .clear(), [] operator, and .front() function
//  c) Try creating a std::vector of std::shared_ptr
void vectorPractice();

int main()
{
    stringPractice();
    return 0;
}

void displayString(std::string aString)
{
    if (aString.empty())
    {
        std::cout << "This string is empty!\n";
    }
    else
    {
        std::cout << aString << "\n";
    }
}

std::string concatenateStrings(std::string stringA, std::string stringB)
{
    // concatenate = fancier word for add. 
    return stringA + stringB;
}

void stringPractice()
{
    //  a) use the .empty(), .size(), .clear(), and .replace() functions
    std::string myString = "That says a thing or two about anything.";
    std::string myEmptyString = "";
    displayString(myString);
    displayString(myEmptyString);

    std::cout << myString.size() << "\n";

    std::string str = myString;
    displayString(str);
    str.replace(str.begin(), str.begin()+4, "A string that");
    displayString(str);
    myString.clear();
    displayString(myString);
    myString.replace(myString.begin(), myString.end(), " This is a new thing.");

//  b) How would you combine 2 strings into 1? (A: just add together with +)
//      "Olafur" "Gabe" into "OlafurGabe" for example
    displayString(concatenateStrings(str, myString));

}

void shared_ptrPractice()
{

}

void vectorPractice()
{

}