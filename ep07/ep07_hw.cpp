#include <iostream>

// 01 assignment:
// a) Practice creating pointers of the fundamental types 
//      fundamental types: int, float, (double,) void, char

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
    delete playerOne;
    delete playerTwo;
}

void combat::take_damage(player* attacker, player* enemy)
{
    *(enemy->health) -= *(attacker->damage);
}

void combat::announce_winner()
{
    if (*(playerOne->health) > *(playerTwo->health))
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
    player* p1 = new player(100, 5);
    player* p2 = new player(100, 10);

    combat c(p1, p2);
    c.run();

    return 0;
}