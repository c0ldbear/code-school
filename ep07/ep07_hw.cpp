#include <iostream>

// 01 assignment:
// a) Practice creating pointers of the fundamental types 
//      fundamental types: int, float, (double,) void, char
void practicePointers()
{
    char* charP = new char('Z');
    float* floatP = new float(990.91202);
    // int we've done so many times now
    void* voidP = new int(20);
}
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
// end of struct player

struct combat
{
    player* playerOne;
    player* playerTwo;

    combat(player* m_playerOne, player* m_playerTwo);
    ~combat();

    void take_damage(player* attacker, player* enemy);

    void announce_winner();

    void run();
};

combat::combat(player* m_playerOne, player* m_playerTwo)
{
    playerOne = m_playerOne;
    playerTwo = m_playerTwo;
}

combat::~combat()
{
    //delete playerOne;
    //delete playerTwo;

    // We might not need these? 
    // If we do keep them, `combat` takes the ownership of the players
    // otherwise it will just "borrow" the players.
    // It doesn't really make sense to me... Without deleting the
    // players (here or outside of combat) it should inflict a memory leak, no? 
    // it will be a leak if not the "owner" of the players deletes them, so
    // therefore we should always make sure the "owner" deletes the pointers.
}

void combat::take_damage(player* attacker, player* enemy)
{
    *(enemy->health) -= *(attacker->damage);
}

void combat::announce_winner()
{
    if (*(playerOne->health) > *playerTwo->health) // two ways of dereferencing the "dubble pointer"
    {
        std::cout << "Player 1 is the winner!\n";
    }
    else
    {
        std::cout << "Player 2 is the winner!\n";
    }
    
}

void combat::run()
{
    std::cout << "Combat begins!\n";

    while (*(playerOne->health) > 0 && *(playerTwo->health) > 0)
    {
        take_damage(playerOne, playerTwo);
        take_damage(playerTwo, playerOne);
    }
    std::cout << "End of combat: ";
    
    announce_winner();
}

// end of struct combat

int main()
{

    practicePointers();

    player* p1 = new player(100, 5);
    player* p2 = new player(100, 10);

    combat c(p1, p2);
    c.run();

    delete p1;
    delete p2;

    return 0;
}

// add Olafur's solution here:
void OlafurSolution()
{

}

struct Player {};
struct Combat {};