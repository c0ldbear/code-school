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

int main()
{
    int a = 0;
    float b = 1.1230;
    while (a < b)
    {
        a += 10;
    }
    return 0;
}
