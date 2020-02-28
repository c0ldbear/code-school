#include <iostream>

#include "ngon_random.h"

struct player
{
    int health;

    int damage_min;
    int damage_max;

    player(int aHealth, int aDamageMin, int aDamageMax);

    int damage();
    bool is_critical_hit();

};

player::player(int aHealth, int aDamageMin, int aDamageMax)
{
    health = aHealth;

    damage_min = aDamageMin;
    damage_max = aDamageMax;
}

int player::damage()
{
    return random_number(damage_min, damage_max);
}

bool player::is_critical_hit()
{
    int crit_result = random_number(1, 100);
    
    return crit_result > 68;
}

int main()
{
    player poly(100, 1, 12);
    
    std::cout << poly.damage() << "\n";
    std::cout << poly.damage() << "\n";
    std::cout << poly.damage() << "\n";
    std::cout << poly.damage() << "\n";

    return 0;
}