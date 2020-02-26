
// 01 assignment:
// a) Practice creating pointers of the fundamental types 
// b) Create a function that creates dynamic memory and returns it
//      for example: a function that returns an int*

// 02 assignment:
// Create two classes:
//  Class 01:
//  - called `player`
//  - has both `health` and `damage` as dynamic memory (pointers)
//      cannot leak memory so remember to add destructor.
//  Class 02:
//  - called `combat`
//  - takes into the constructor two player* pointers (as arguments)
//  - Makes those two players fight until one is dead (loop through!)
//      how else it is done, and how it return values is up to us.

// class 01: player
struct player
{
    int* health;
    int* damage;

    player(int m_health, int m_damage);
    ~player();
};

player::player(int m_health, int m_damage)
{
    health = new int(m_health);
    damage = new int(m_damage);
}

player::~player()
{
    delete health;
    delete damage;
}

int main()
{
    return 0;
}