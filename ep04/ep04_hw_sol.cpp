struct homework
{
    char letter;
    bool is_uppercase;

    bool make_uppercase();
    bool next_letter();
    void set_letter(char a_letter);

    homework(char a_letter);

};

homework::homework(char a_letter)
{
    letter = a_letter;
    if (letter >= 65 && letter <= 90)
    {
        is_uppercase = true;
    }
    else
    {
        is_uppercase = false;
    }
}

bool homework::make_uppercase()
{
    if (letter >= 95 && letter <= 122)
    {
        letter -= 32;
        is_uppercase = true;
        return true;
    }
    return false;
}

bool homework::next_letter()
{
    if ((letter >= 65 && letter <= 89) || (letter >= 97 && letter <= 121)) //check if letter is in the alphabet but only up to 'y' and 'Y'
    {
        letter += 1;
        // return letter; // nja?
        return true; 
    }
    return false;
}

void homework::set_letter(char a_letter)
{
    letter = a_letter;
    if (letter >= 65 && letter <= 90)
    {
        is_uppercase = true;
    }
}

int main()
{

}