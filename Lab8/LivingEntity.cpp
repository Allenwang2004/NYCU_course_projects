#include "LivingEntity.h"
#include <iostream>
using namespace std;
 //write constructor
LivingEntity::LivingEntity(std::string _name, int _health,int _damage)
{
    name=_name;
    health=_health;
    damage=_damage;
}

bool LivingEntity::takeDamage(int damage) 
{
    health-=damage;
    if(health>0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool LivingEntity::isAlive() 
{
    if(health>0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

std::string LivingEntity::getName() const 
{
    return name;
}
int LivingEntity::getHealth()const
{
    return health;
}
void LivingEntity::print()const
{
    std::cout << "\n=== Monster Stats ===" << std::endl;
    std::cout << "Name: " << name<< std::endl;
    std::cout << "Health: " <<health<< std::endl;
     cout<<"====================="<<endl<<endl;
}