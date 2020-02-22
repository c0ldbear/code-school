#pragma once

// ifndef works too

struct enemy
{
    int m_health;
    int m_damage;
    // could alternatively name them to:
    // myHealth & myDamage
    // m_health & m_damage

    enemy(int a_health, int a_damage);
};