
#include <iostream>
#include "Entity.h"
using namespace std;


class Game {
private:
    Entity _players[2];
    Entity _enemies[2];
    int _num_players;
    int _num_enemies;

public:
    Game();
    Game(Entity[], Entity[], int, int);

    int getNumPlayers();
    int getNumEnemies();
    Entity getPlayer(string);
    Entity getEnemy(string);
    int findPlayer(string);
    int findEnemy(string);
   
    void printAllStats();
    bool setEnemy(int, Entity);
    bool setPlayer(int, Entity);
    void setPlayersList(Entity[], int);
    void setEnemiesList(Entity[], int);
};


