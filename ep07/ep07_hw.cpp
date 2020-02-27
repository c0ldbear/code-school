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

void OlafurSolution();

int main()
{

    practicePointers();

    player* p1 = new player(100, 5);
    player* p2 = new player(100, 10);

    combat c(p1, p2);
    c.run();

    delete p1;
    delete p2;

    OlafurSolution();

    return 0;
}

// add Olafur's solution here:
struct Player
{
    int* health;
    int* damage;
    
    Player(int aHealth, int aDamage);
    ~Player(); // Not added to Olafur's solution in the video but they talk about it

    bool take_damage(int aDamage);
};

Player::Player(int aHealth, int aDamage)
{
    health = new int(aHealth);
    damage = new int(aDamage);
}

// Not added to Olafur's solution in the video but they talk about it
Player::~Player()
{
    delete health;
    delete damage;
}


bool Player::take_damage(int aDamage)
{
    *health -= aDamage;
    return *health <= 0;
}

struct Combat
{
    Player* playerOne;
    Player* playerTwo;

    Combat(Player* aPlayerOne, Player* aPlayerTwo);

    int fight();
};

Combat::Combat(Player* aPlayerOne, Player* aPlayerTwo)
{
    playerOne = aPlayerOne;
    playerTwo = aPlayerTwo;
}

int Combat::fight()
{
    while (*playerOne->health > 0 && *playerTwo->health > 0)
    {
        if (playerOne->take_damage(*playerTwo->damage)) // they talk about adding this if statement but it is not used in the video
        // and they talk about only using one if-statement and that makes sense because
        // if playerOne dies before it can make damage to playerTwo it should break the loop
        // so that playerTwo does not take any damage from a dead playerOne.
        {
            break;
        }

        playerTwo->take_damage(*playerOne->damage);
    }

    if (*playerOne->health > 0 && *playerTwo->health <= 0)
    {
        return 1;
    }

    if (*playerTwo->health > 0 && *playerOne->health <= 0)
    {
        return 2;
    }

    return 0; // tie in the fight (shouldn't be needed now when the if-statement is added to the while loop but we'll keep it.)
}

void OlafurSolution()
{
    // Olufar's solution from the video
    Player* P1 = new Player(100, 5);
    Player* P2 = new Player(100, 21);

    Combat arena(P1, P2);
    int winner = arena.fight();

    delete P1;
    delete P2;

}