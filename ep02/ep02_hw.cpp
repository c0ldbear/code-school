
void preassignemnt(void)
{
    // can you call all types as arguments in a function?
    // a: yes, but only if you keep 'void' for itself but that is
    // the same as to leave the argument blank.

    // can you use all types as return values in a function?
    // a: yes.

    // can you create scopes within functions?
    // a: yes! It is possible to have scopes within functions
    // as we have tried in 'main()' before.

    // can you creater a function within a function?
    // a: no! It is not allowed according to clang.

    // can a function call itself?
    // a: yes, it's a recursive function then.
}

int createFunctionWithinFunctions()
{
    //int add(int num_a, int num_b) { return num_a + num_b;};
    // ^ is not allowed to do within a fucntion

    //int sum = add(1,2);  // this will not work then.
    //if (sum == 3)
   //{
       //sum *= 10;
   //) 
   return 0;
}

// assignment 01:
// write a function that takes in two integers and returns the one that is bigger
int compareNumbers(int num_a, int num_b)
{
    if (num_a > num_b)
    {
        return num_a;
    }
    else
    {
        return num_b;
    }
    
}

// assignment 02:
// write a function that takes in a character and returns true if the character is lowercase
// hint: check ascii table

bool checkLowercase(char whatCase)
{
    if (whatCase > 96 && whatCase < 123)
    {
        return true;
    }
    return false;
}

// assignment 03:
// write a functin that takes a character and makes it uppercase, but only if it was lowercase
char makeUppercase(char lowercase)
{
    int transformToUppercase = 32;
    if (checkLowercase(lowercase))
    {
       return lowercase - transformToUppercase;
    }
   
   return lowercase;
}

int main()
{
    int biggerNum = compareNumbers(2,1);
    biggerNum = compareNumbers(1,3);
    biggerNum = compareNumbers(5,5);
    biggerNum = compareNumbers(-2,-1);
    biggerNum = compareNumbers(-100,-100);

    bool lowercase = checkLowercase('a');
    lowercase = checkLowercase('A');
    //lowercase = checkLowercase('å');
    //lowercase = checkLowercase('Å'); does not work? Lol. they are too big. since max size of char is 128 (0->127)
    lowercase = checkLowercase('z');
    lowercase = checkLowercase('Z');
    lowercase = checkLowercase('z'+1);

    char uppercase = makeUppercase('a');
    uppercase = makeUppercase('z');
    uppercase = makeUppercase('A');
    uppercase = makeUppercase('Z');
}