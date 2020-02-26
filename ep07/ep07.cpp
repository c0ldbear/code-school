void healthPointer();
void playerStructPointer();

int main() 
{

    healthPointer();
    playerStructPointer();
   
    return 0;
}

void healthPointer()
{
    int* health = new int(50);  // new space allocation in heap
    int* other_health = health; // take the address as the other
    int* another_health = new int(65); // New space allocation in heap

    delete other_health;
    delete another_health;

    // Re-initalize space in the heap
    health = new int(15);
    another_health = new int(61);

    delete health;
    delete another_health;
}

struct player
{
    int health;
    int damage;

    // two constructors depending on what is called
    player(int m_health, int m_damage);
    player();
};

player::player(int m_health, int m_damage)
{
    health = m_health;
    damage = m_damage;

}

player::player()
{
    health = 100;
    damage = 11;
}

void playerStructPointer()
{
    player* teddy = new player();
    player* charlie = new player(120, 20);

    delete teddy;
    delete charlie;

}