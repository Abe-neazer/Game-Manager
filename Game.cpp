#include "Game.h"
Game:: Game(){

_num_enemies = 0;
_num_players =0;

}
Game::Game(Entity players[], Entity enemies[], int num_players, int num_enemies){

   if (num_players > 2)
        _num_players = 2;
    else
        _num_players = num_players;

    if (num_enemies > 2)
        _num_enemies = 2;
    else
        _num_enemies = num_enemies;


    for (int i =0; i< _num_players; i++){

        _players[i]= players[i];
    }

    for (int i =0; i< _num_enemies; i++){

        _enemies[i]= enemies[i];
    }


}
bool Game::setPlayer(int index, Entity new_player) {
    if (index >= 0 && index < _num_players) {
        _players[index] = new_player;
        return true;
    } else {
        return false;
    }
}
bool Game::setEnemy(int index, Entity new_enemy) {
    if (index >= 0 && index < _num_enemies) {
        _enemies[index] = new_enemy;
        return true;
    } else {
        return false;
    }
}

int Game::findPlayer(string name) {
    for(int i = 0; i < _num_players; ++i) {
        if (_players[i].getName() == name) {
            return i; 
        }
    }
    
    return -1;
}
int Game::findEnemy(string name) {
    for(int i = 0; i < _num_enemies; ++i) {
        if (_enemies[i].getName() == name) {
            return i; 
        }
    }
    
    return -1;
}

void Game::printAllStats(){
   
    
    for (int i = 0; i < _num_players; ++i) {
        _players[i].printStats();
        cout << "----------------------------------------------" << endl;
    }

    
    for (int i = 0; i < _num_enemies; ++i) {
        _enemies[i].printStats();
        cout << "----------------------------------------------" << endl;
    }
}





//getters

int Game:: getNumPlayers(){

        return _num_players;
}
int Game::getNumEnemies(){

    return _num_enemies;
}
Entity Game::getPlayer(string name) {
    for(int i = 0; i < _num_players; ++i) {
        if (_players[i].getName() == name) {
            return _players[i];
        }
    }
    return Entity();
}
Entity Game::getEnemy(string name) {
    for(int i = 0; i < _num_enemies; ++i) {
        if (_enemies[i].getName() == name) {
            return _enemies[i];
        }
    }
    
    return Entity(); 
}


//setter

void Game:: setPlayersList(Entity players[], int num_players) {
    if (num_players > 2)
        _num_players = 2;
    else
        _num_players = num_players;

    for(int i = 0; i < _num_players; ++i) {
        _players[i] = players[i];
    }
}

void Game:: setEnemiesList(Entity enemies[], int num_enemies){
    if (num_enemies > 2)
        _num_enemies = 2;
    else
        _num_enemies = num_enemies;

    for(int i = 0; i < _num_enemies; ++i) {
        _enemies[i] = enemies[i];
    }
}

