int attack(int health, int damage)
// This is a pure function since it is modifying the data within it.
{
    health -= damage;
    if (health < 0)
    {
        health = 0;
    }

    return 0;
}

int main()
{
    int player_health = 100;
    int player_damage = 8;
    bool player_alive = true;

    int enemy_health = 50;
    int enemy_damage = 4;
    bool enemy_alive = true;

    player_health -= enemy_damage;
    if (player_health < 0)
    {
        player_health = 0;
        player_alive = false;
    }

    enemy_health -= player_damage;
    if (enemy_health < 0)
    {
        enemy_health = 0;
        enemy_alive = false;
    }

}