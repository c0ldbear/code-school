// inspiration from the slides used in the video of this episode
struct Enemy
{
    int health;
    int damage;
    
    Enemy(int _health, int _damage);
    void take_damage(int _damage);

    void attacks(Enemy* _enemy);
};

Enemy::Enemy(int _health, int _damage)
{
    health = _health;
    damage = _damage;
}

void Enemy::take_damage(int _damage)
{
    health -= _damage;
}

// extra function which uses pointers. Might be dangerous at this point but fun!
// the code could be more readable now? Maybe? At this time it is because now we can use
// it as something.attacks(&anotherThing);
void Enemy::attacks(Enemy* _enemy)
{
    _enemy->health -= this->damage;
}

void trySlideCode()
{
    Enemy t(100,5);
    Enemy tt(102,10);

    t.take_damage(tt.damage);   // t.health - 10 == 90
    tt.take_damage(t.damage);   // tt.health - 5 == 97

    t.attacks(&tt);     // tt.health - 5 == 92
    tt.attacks(&tt);    // self attack, tt.health - 10 == 82

}

// code along part here
struct enemy
{
    // member variables
    int health;
    int damage;

    // class function
    enemy(int a_health, int a_damage);
    void take_damage(int a_damage);
};

enemy::enemy(int a_health, int a_damage)
{
    health = a_health;
    damage = a_damage;
}

void enemy::take_damage(int a_damage)
{
    health -= a_damage; // same as `health = health - a_damage`
}

int main() 
{

    enemy will(100, 50);
    //will.damage = 50;

    enemy stacking(50, 100);
    //stacking.health = 100;

    will.take_damage(stacking.damage);
    stacking.take_damage(will.damage);

    return 0;
    
}