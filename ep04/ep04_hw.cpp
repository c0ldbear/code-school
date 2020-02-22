
// preassignment questions

// can you use all (data)types as member variables in a class?
// a: you can use the usual data types as normal.

// can you use all types as return variables of class functions?
// a: yes, as normal.

// can a class have no member variables?
// a: yes. It is possible but why would you?
struct no_members {};

// can a class have a member variable that is of another class?
// a: yes

// can you use a class type has an argument in a function?
// a: yes

// can you use a class type as a return value of a function?
// a: yes

// assignment:
// create a class that contains:
// [x] 1 char variable called 'letter'
// [x] 1 bool variable called 'is_uppercase'
// [x] 1 constructor that takes in 1 char variable called 'a_letter'
// [] 1 function called 'bool make_uppercase();'
//      if the letter is uppercase, it should do nothing and return false
//      if the letter is lowercase, it should change it to uppercase and return true
// [] 1 function called 'bool next_letter();'
//      if the letter is between 'A' and 'Z', and 'a' and 'z', it should return a next letter
//      otherwise it should not do anything. If success: return true, otherwise false
// [] 1 function called 'void set_letter(char a_letter);'

struct character
{
    char letter;
    bool is_uppercase;

    character(char a_letter);

    void set_letter(char a_letter);
    bool check_uppercase();
    bool make_uppercase();

    bool has_next_letter();
    char next_letter();
};

void character::set_letter(char a_letter)
{
    letter = a_letter;
}

character::character(char a_letter)
{
    letter = a_letter;
    is_uppercase = check_uppercase();
}

bool character::check_uppercase()
{
    if (letter >= 'A' && letter <= 'Z')
    {
        return true;
    }
    return false;
}

bool character::make_uppercase()
{

    if (is_uppercase)
    {
        return false;
    }
    else
    {
        letter -= 32;
        is_uppercase = true;
        return true;
    }

}

bool character::has_next_letter()
{
    if (letter >= 'A' && letter < 'Z')
    {
        return true;
        //return letter + 1;
    }
    else if (letter >= 'a' && letter < 'z')
    {
        return true;
        //return letter + 1;
    }
    return false;
}

char character::next_letter()
{
    if (has_next_letter())
    {
        return letter + 1;
    }
    return '\0';
}

int main()
{
    no_members members;

    character letter('q');
    char next_letter = letter.next_letter();
    bool makeUppercase = letter.make_uppercase();
    next_letter = letter.next_letter();

    letter.set_letter('\\');
    next_letter = letter.next_letter();

}