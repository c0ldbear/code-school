int do_damage(int health, int damage)
// naming functions is hard because at the moment it can make sense.
// not necessarily in the long run.
{
    return health - damage;
}

int main()
{
    //while(true) will have an infinite amount of fights
    {
        int player_health = 100;
        int player_damage = 11;

        int enemy_health = 100;
        int enemy_damage = 50;
        
        // while (true) outside will just make the code run infinitly
        // since it will be always satisfied meanwhile the inside-while loop
        // will be done when one of the health is zero (or below).
        while (enemy_health > 0 && player_health > 0)
        {
            enemy_health = do_damage(enemy_health, player_damage);
            player_health = do_damage(player_health, enemy_damage);
        }
    }
}
