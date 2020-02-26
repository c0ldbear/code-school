void healthPointer();
void playerStructPointer();
int almostSmartPointer();

int main() 
{

    healthPointer();
    playerStructPointer();
    
    int whatr = almostSmartPointer();
   
    return 0;
}

void healthPointer()
{
    int* health = new int(50);  // new space allocation in heap
    int* other_health = health; // take the address as the other
    int* another_health = new int(65); // New space allocation in heap

    delete other_health;
    delete another_health;

    // Re-initalize space in the heap
    health = new int(15);
    another_health = new int(61);

    delete health;
    delete another_health;
}

struct player
{
    int health;
    int damage;

    // two constructors depending on what is called
    player(int m_health, int m_damage);
    player();
};

player::player(int m_health, int m_damage)
{
    health = m_health;
    damage = m_damage;

}

player::player()
{
    health = 100;
    damage = 11;
}

void playerStructPointer()
{
    player* teddy = new player();
    player* ce = new player(120, 20);

    delete teddy;
    delete ce;

}

// A simple example that shows how a smart pointer works in practice but it is much
// much more complicated than this below. Essentially, it is almost the same.
struct hold_number
{
    int* myNumber;

    hold_number(int aNumber);
    ~hold_number();
}; 

hold_number::hold_number(int aNumber)
{
    myNumber = new int(aNumber);
}

hold_number::~hold_number()
{
    delete myNumber;
}

int almostSmartPointer()
{
    hold_number numberHolder(1337);
    return *(numberHolder.myNumber); // x.myNumber is the `int pointer` 
    // so we need to dereference the whole name: *(x.myNumber) which is the same as *x.myNumber
}