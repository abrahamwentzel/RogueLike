// Entity Types

class Entity
{

public:
    void move();
    void jump();

private:
    int x;
    int y;
    int health;

};

class Player: Entity
{

public:
    void shoot();
    void melee();

private:

};

class Companion: Entity
{

public:
    void bite();

private:

};

class Zombie: Entity
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