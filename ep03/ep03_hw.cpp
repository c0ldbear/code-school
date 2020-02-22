#include <iostream>

// can you use all types as conditions in a while loop?
// a: no, not void

// can you make an infinite while loop?
// a: yes (while(true))

// can you put scopes inside a while loop?
// a: yes

// can you put a while loop inside of a while loop?
// a: yes

// can you put a while loop inside a function? 
// a: yes

// assignment 01:
// create a loop that goes through the entire alphabet from lowercase a to lowercase z
void displayCharacter(char character)
{
    std::cout << character << std::endl;
}

void loopLowercaseAlphabet()
{
    char character = 'a';
    while (character <= 'z')
    {
        displayCharacter(character);
        character++;
    }
}

// assignment 02:
// create a loop that goes through the entire alphabet from lowercase a to lowercase z,
// THEN goes through uppercase A to uppercase Z

void loopLowercaseThenUppercaseAlphabetWeird()
{
    char character = 'a';
    while (character != 'Z'+1) // not the most beautiful solution there is but...
    {
        if (character > 'z')
        {
            character -= ':'; 
        }
        displayCharacter(character);
        character++;
    }
}

void loopAlphabet()
{
    char character = 'a';

    while (true)
    {
        displayCharacter(character);

        // break condition for while-true
        if (character == 'Z')
        {
            break;
        }

        character++;

        if (character > 'z')
        {
            character = 'A';
        }
    }
}

// code{}school's solution:
void loopAlphabetCodeSchool()
{
    char letter_increment = 'a';
    while (letter_increment != '[')
    {
        char letter = letter_increment; // be able to put breakpoint here to see what has happened.
        displayCharacter(letter);

        if (letter_increment == 'z')
        {
            letter_increment = 'A';
        }
        else
        {
            letter_increment++;
        }
    }
}

int main()
{
    int a = 0;
    float b = 1.1230;
    while (a < b)
    {
        a += 10;
    }

    loopLowercaseAlphabet();
    std::cout << "Next assignment\n" << std::endl;
    loopLowercaseThenUppercaseAlphabetWeird();

    std::cout << "\nAnother solution:" << std::endl;
    loopAlphabet();

    std::cout << "\ncode school solution:" << std::endl;
    loopAlphabetCodeSchool();

    return 0;
}
