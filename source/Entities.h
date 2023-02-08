// Entity Types

class Entity
{

public:
    void move();

private:
    int x;
    int y;
    int health;

};

class Player : Entity
{

public:
    void shoot();
    void melee();

private:

};

class Companion : Entity
{

public:
    void bite();

private:

};

class Zombie : Entity
{

public:
    void infect();

private:

};

class ZombieCompanion : Entity
{

public:
    void infect();

private:

};

// Buffs for Player

class Perks
{
public:
    void ammo();
    void health();
    void invincible();
    void one_shot();

};

// Functions

void Entity :: move()
{

}

void Player :: shoot()
{

}

void Player :: melee()
{

}

void Companion :: bite()
{

}

void Perks :: ammo()
{

}

void Perks :: health()
{

}

void Perks :: invincible()
{

}

void Perks :: one_shot()
{

}