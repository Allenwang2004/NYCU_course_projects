#include "BattleEvent.h"
#include <iostream>
using namespace std;
void BattleEvent::start(Player &player, Monster &monster) 
{
    while (player.isAlive() && monster.isAlive()) 
    {
        monster.print();
        player.print();
        player.attack(monster);
        cout << player.getName() << " attacks " << monster.getName() << " for " << player.getDamage() << " damage!" << endl;
        cout << monster.getName() << " takes " << player.getDamage() << " damage!" << endl;
        if (monster.isAlive()) 
        {
            monster.attack(player);
            cout << monster.getName() << " attacks " << player.getName() << " for " << monster.getDamage() << " damage!" << endl;
            cout << player.getName() << " takes " << monster.getDamage() << " damage!" << endl;
        }
    }
    if(monster.isAlive()==false)
    {
        cout << monster.getName() << " has been defeated!" << endl;
        cout << player.getName() << " gains " << monster.getExperience() << " experience!" << endl;
        player.gainExperience(monster.getExperience());
    }
    else
    {
        cout << player.getName() << " has been defeated!" << endl;
    }

}
