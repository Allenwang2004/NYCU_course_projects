#include "Player.h"
#include <iostream>
using namespace std;

//write player constructor
Player::Player(std::string _name, int _health, int _damage):LivingEntity(_name,_health,_damage)
{
    experience=0;
    level=1;
}

//use damage to attack monsters, if defeatingit ,you get the experience = original health of monster *0.5
void Player::attack(Monster &monster) 
{
    monster.takeDamage(damage);
    if(monster.isAlive()==false)
    {
        gainExperience(monster.getHealth()*0.5);
    }
}

//Increases player experience points,ifyour experience >=level*level*20 -> level up.Don’t need to initial the experience
void Player::gainExperience(int amount) 
{
    experience+=amount;
    if(experience>=level*level*20)
    {
        levelUp();
    } 
}

void  Player::restoreHealth(int amount) 
{
    health+=amount;
    cout << name << " restores " << amount << " health!" << endl;
}

// Levels up the player, increasing health =health+level*20 and damage=level*20.
void Player::levelUp() 
{
    level++;
    health+=level*20;
    damage=level*20;
    cout<<name<<" levels up to level "<<level<<"!"<<endl;
}


void Player::print()const
{ 
    std::cout << "\n=== Player Stats ===" << std::endl;
    std::cout << "Name: " << name<< std::endl;
    std::cout << "Health: " <<health<< std::endl;
    std::cout << "Level: " << level << std::endl;
    std::cout << "Experience: " <<experience  << std::endl;
    std::cout << "Attack damage: " << damage << std::endl;
    cout<<"==================="<<endl<<endl;
}