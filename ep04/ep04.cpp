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
void Enemy::attacks(enemy* _enemy)
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

int main() 
{


    return 0;
    
}