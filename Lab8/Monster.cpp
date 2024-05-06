#include "Monster.h"
#include "Player.h" // Add this include directive to access the full definition of the Player class
#include <iostream>
using namespace std;

//write constructor
Monster::Monster(std::string _name, int _health, int _damage):LivingEntity(_name,_health,_damage)
{
    getexperience=0;
}


void Monster::attack(Player &player) 
{
    std::cout << name << " attacks for " << damage << " damage!" << std::endl;
    player.takeDamage(damage);
}

int Monster::getExperience() 
{
    return getexperience;
}

BossMonster::BossMonster(std::string _name, int _health, int _damage):Monster(_name,_health,_damage)
{
    getexperience=health*0.5;
}

FlyingMonster::FlyingMonster(std::string _name, int _health, int _damage):Monster(_name,_health,_damage)
{
    getexperience=health*0.3;
}

GroundMonster::GroundMonster(std::string _name, int _health, int _damage):Monster(_name,_health,_damage)
{
    getexperience=health*0.2;
}

MagicMonster::MagicMonster(std::string _name, int _health, int _damage):Monster(_name,_health,_damage)
{
    getexperience=health*0.4;
}


