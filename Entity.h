#include <iostream>
#include <string>
#include <fstream>


using namespace std;


class Entity
{

private:
    string _name;
    double _hp;
    double _gold;
    char _condition;
    bool _is_enemy;
    
public:
    Entity();
    Entity(string name, double hp, int gold, char condition, bool is_enemy);
    void printStats() const;

    string getName() const;
    double getHP() const;
    int getGold() const;
    char getCondition() const;
    bool getIsEnemy() const;





    void setName(string name);
    void setHP(double hp);
    void setGold(int gold);
    void setCondition(char condition);
    void setIsEnemy(bool is_enemy);


};