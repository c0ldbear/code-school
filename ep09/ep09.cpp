#include <iostream>

#include "ngon_random.h"

struct player
{
    int health;
    int max_health;

    int damage_min;
    int damage_max;

    int crit_chance;

    player(int aHealth, int aDamageMin, int aDamageMax, int aCritChance);

    int damage();
    bool is_critical_hit();

};

player::player(int aHealth, int aDamageMin, int aDamageMax, int aCritChance)
{
    health = aHealth;
    max_health = aHealth;
    damage_min = aDamageMin;
    damage_max = aDamageMax;
    crit_chance = aCritChance;
}

int player::damage()
// could be called `pure function` since it is not giving a side effect
// but if we would add `std::cout` then we get a side effect.
//
// If we would add a counter for our crits, then that is a side effect too
// since we are changing something else than what the function does.
{
    int damage_result = random_number(damage_min, damage_max);
    if (is_critical_hit())
    {
        return 2*damage_result;
    }

    return damage_result;
}

bool player::is_critical_hit()
{
    int crit_result = random_number(1, 100);
    return crit_result < crit_chance; // think about this. Why is it needed to be "less than"?
}

// could we do duck? block? miss? evade? 
// they should be similar to function is_critical_hit().

int main()
{
    player poly(100, 1, 12, 60);
    player plopp(100, 1, 12, 12);
    
    int poly_wins = 0;    
    int plopp_wins = 0;

    for (int i = 0; i < 100000; ++i)
    {
        while (poly.health > 0 && plopp.health > 0)
        {
            poly.health -= plopp.damage();
            if (poly.health <= 0)
            {
                break;
            }
            plopp.health -= poly.damage();
        }

        if (poly.health > 0)
            poly_wins++;
        
        if (plopp.health > 0)
            plopp_wins++;

        poly.health = poly.max_health;
        plopp.health = plopp.max_health;

    }

    return 0;
}