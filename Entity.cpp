    #include "Entity.h"
    #include <iostream>
    #include <string>
    #include <fstream>
    #include <iomanip>


    using namespace std;

    Entity:: Entity(){   

            _gold = 0;

            _hp = 0;
        

            _name = "";
            
            _condition = 'H';

            _is_enemy = false;
            
    }
    Entity:: Entity(string name, double hp, int gold, char condition, bool is_enemy){ 

        _name = name;

        if(hp >= 0 ){

            _hp=hp;
        }
        if(gold >= 0 ){

            _gold=gold;
        }
        if ( condition == 'H'|| condition == 'D'|| condition == 'P'){

            _condition = condition;
        }else
        {
            _condition = 'H';

        }
        _is_enemy = is_enemy;

    }
        void Entity::printStats() const {

        cout<<  _name << "'s stats:"<< endl;
        cout << fixed << setprecision(2)<< "HP: " << _hp<< endl;
        cout << "Condition: " << _condition << endl;
        cout << fixed << setprecision(0)<< "Gold: " << _gold<< endl;
        if (_is_enemy) {
                cout << "Is Enemy: Yes" << endl;
            } else {
                cout << "Is Enemy: No" << endl;
            }

        }   



    // Getters
    string Entity::getName() const {
        return _name;
    }

    double Entity::getHP() const {
        return _hp;
    }

    int Entity::getGold() const {
        return _gold;
    }

    char Entity::getCondition() const {
        return _condition;
    }

    bool Entity::getIsEnemy() const{
        return _is_enemy;
    }

    // Setters
    void Entity::setName(string name) {
        _name = name;
    }

    void Entity::setHP(double hp) {
        if(hp >= 0 ){

            _hp=hp;
        }else {
            _hp = 0;
        }
    }

    void Entity::setGold(int gold) {
        if(gold >= 0 ){

            _gold=gold;
        }
        else if(gold < 0){

            _gold = 0;
        }
    }

    void Entity::setCondition(char condition) {
        
        if ( condition == 'H'|| condition == 'D'|| condition == 'P'){

            _condition = condition;
        }else
        {
            _condition = 'H';

        }
    }

    void Entity::setIsEnemy(bool is_enemy) {
        _is_enemy = is_enemy;
    }