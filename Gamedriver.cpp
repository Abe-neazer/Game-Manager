#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <stdexcept>
#include "Game.h"

using namespace std;
bool loadCharacters(string filename, Entity characters[], const int CHARACTERS_SIZE, bool is_enemy) {
    ifstream file(filename);
    if (!file.is_open()) {
        return false; // Return false if the file cannot be opened
    }

    string line;
    getline(file, line); // Read and discard the header line

    int index = 0;
    while (getline(file, line)) {
        if (line.empty()) {
            continue;
        }

        string name;
        double hp = 0; // Initialize hp inside the loop
        int gold = 0;
        char condition;

        // Tokenize the line manually
        size_t pos = line.find('|');
        if (pos != string::npos) {
            name = line.substr(0, pos);
            line = line.substr(pos + 1);

            pos = line.find('|');
            if (pos != string::npos) {
                hp = stod(line.substr(0, pos));
                line = line.substr(pos + 1);

                pos = line.find('|');
                if (pos != string::npos) {
                    gold = stoi(line.substr(0, pos));
                    line = line.substr(pos + 1);

                    if (!line.empty()) {
                        condition = line[0];
                    }
                }
            }
        }

        if (index < CHARACTERS_SIZE) {
            // Set hp to 0 if it's negative
            if (hp < 0) {
                hp = 0;
            }
            if (gold < 0) {
                gold = 0;
            }
            characters[index] = Entity(name, hp, gold, condition, is_enemy);
            index++;
        }
    }

    file.close();
    return true; // Return true if characters are successfully read and stored
}

bool validateint (const string number) {
    if (number.empty() || number == ".") return false; 
    
    bool decimalFound = false;
    for (size_t i = 0; i < number.length(); ++i) {
        if (number[i] == '.') {
            if (decimalFound) return false; 
            decimalFound = true;
        } else if (!isdigit(number[i])) {
            return false; 
        }
    }

    return true;
}



void displayMenu() {
    cout << "Select from the following options:" << endl;
    cout << "1. Select Players and Enemies" << endl;
    cout << "2. Display Players' stats" << endl;
    cout << "3. Display Enemies' stats" << endl;
    cout << "4. Edit a Player's Stats" << endl;
    cout << "5. Edit an Enemy's Stats" << endl;
    cout << "6. Exit" << endl;
}

void displayCharacters(Entity entities[], int count, string name) {
    for (int i = 0; i < count; ++i) {
        if (name == entities[i].getName()) {
            continue;
        }
        entities[i].printStats();
        cout << "----------------------------------------------" << endl;
    }
}

int checker(string name, Entity players[], int size, string name2) {
    for (int i = 0; i < size; i++) {
        if (name == players[i].getName() && name != name2) { 
            return i; 
        }
    }
    return -1; 
}

int main() {
    int numplayer = 6;
    int numenemies = 5;
    Entity players[6]; 
    Entity enemies[5];

    Entity players_selected[2]; 
    Entity enemies_selected[2]; 

    int one;
    int two;
    string input_player_one;
    string input_player_two;

    string input_enemies_two;
    string input_enemies_one;

    string choice_name_four;
    string choice;

    int choice_four;

    int choice1;
    int placeholder;
    string one_4_1;
    string one_4_3;

     string one_5_1;
     string one_5_3;
 void DispplayMap();
    do {
        displayMenu();

        getline(cin, choice);

        if (!validateint(choice)) {
            // No action needed here if invalid
        } else {
            choice1 = stoi(choice);
        }
        if (!(choice1 >= 1 && choice1 <= 6)) {
            cout << "Invalid input. Please enter a valid choice (1-6)" << endl;
        }

        switch (choice1) {
            case 1:

                 input_player_one= "";
                 input_player_two= "";

                 input_enemies_two= "";
                  input_enemies_one="";

                loadCharacters("players_full.txt", players, numplayer, false);
                cout << "Player 1" << endl;
                cout << "Here is a list of players you can select from:" << endl;
                displayCharacters(players, numplayer - 1, input_player_one);

                do {
                    getline(cin, input_player_one);
                    one = checker(input_player_one, players, numplayer, "");
                    if (one == -1) {
                        cout<< "The selected character is:"<< endl;
                        cout << "Invalid selection. Select from the list!" << endl;
                    }
                } while (one == -1);
                players_selected[0] = players[one];
                cout << "The selected character is:" << endl;

                cout << "Player 2" << endl;
                cout << "Here is a list of players you can select from:" << endl;
                displayCharacters(players, numplayer - 1, input_player_one);
                do {
                    getline(cin, input_player_two);
                    one = checker(input_player_two, players, numplayer, input_player_one); // Pass input_player_one as the name to exclude
                    if (one == -1) {
                         cout<< "The selected character is:"<< endl;
                        cout << "Invalid selection. Select from the list!" << endl;
                    }
                } while (one == -1);
                players_selected[1] = players[one];
                cout << "The selected character is:" << endl;

                loadCharacters("enemies_full.txt", enemies, numenemies, true);
                cout << "Enemy 1" << endl;
                cout << "Here is a list of enemies you can select from:" << endl;
                displayCharacters(enemies, numenemies - 1, input_enemies_one);

                do {
                    getline(cin, input_enemies_one);
                    two = checker(input_enemies_one, enemies, numenemies, "");
                    if (two == -1) {
                         cout<< "The selected character is:"<< endl;
                        cout << "Invalid selection. Select from the list!" << endl;
                    }
                } while (two == -1);
                enemies_selected[0] = enemies[two];
                cout << "The selected character is:" << endl;

                cout << "Enemy 2" << endl;
                cout << "Here is a list of enemies you can select from:" << endl;
                displayCharacters(enemies, numenemies - 1, input_enemies_one);
                do {
                    getline(cin, input_enemies_two);
                    two = checker(input_enemies_two, enemies, numenemies, input_enemies_one);
                    if (two == -1) {
                         cout<< "The selected character is:"<< endl;
                        cout << "Invalid selection. Select from the list!" << endl;
                    }
                } while (two == -1);
                enemies_selected[1] = enemies[two];
                cout << "The selected character is:" << endl;
                break;

            case 2:
                for (int i = 0; i < 2; ++i) {
                    players_selected[i].printStats();
                    cout << "----------------------------------------------" << endl;
                }
                break;

            case 3:
                for (int i = 0; i < 2; ++i) {
                    enemies_selected[i].printStats();
                    cout << "----------------------------------------------" << endl;
                }
                break;

            case 4:
                cout << "Which player's stats do you want to edit?" << endl;
                for (int i = 0; i < 2; ++i) {
                    players_selected[i].printStats();
                    cout << "----------------------------------------------" << endl;
                }
                do {
                    getline(cin, choice_name_four);
                    if (choice_name_four == players_selected[0].getName()) {
                        placeholder = 0;
                    } else if (choice_name_four == players_selected[1].getName()) {
                        placeholder = 1;
                    }
                } while (choice_name_four != players_selected[0].getName() && choice_name_four != players_selected[1].getName());
                cout << "The selected character is:" << endl;
                cout << "Editing player " << players_selected[placeholder].getName() <<"'s stats:"<<endl;

                
                cout << "1. Edit hp" << endl;
                cout << "2. Edit condition" << endl;
                cout << "3. Edit gold" << endl;
                cin >> choice_four;

                switch (choice_four) {
                    case 1:

                        double one_4;
                        cin.ignore();
                        
                        do {
                            cout << "Enter the new value:" << endl;
                            
                            getline(cin,one_4_1);

                                if (!validateint(one_4_1)) {
                                    cout << "Enter a non-negative value!" << endl;
                                } else {
                                    one_4 = stod(one_4_1);
                                   if (one_4 < 0){
                                            cout << "Enter a non-negative value!" << endl;
                                    
                                         }else {
                                             players_selected[placeholder].setHP(one_4);
                                             break;
                                        }
                                }                  
                                
                        } while (!validateint(one_4_1));
                        break;
                    case 2:
                        char two_4;
                        do {
                            cout << "Enter the new value:" << endl;
                            cin >> two_4;
                            if (two_4 == 'H' || two_4 == 'D' || two_4 == 'P') {
                                players_selected[placeholder].setCondition(two_4);
                            } else {
                                cout << "Enter a value among 'H', 'D' or 'P'!" << endl;
                            }
                        } while (!(two_4 == 'H' || two_4 == 'D' || two_4 == 'P'));
                        break;
                    case 3:
                        double three_4;
                        cin.ignore();
                        do {
                            cout << "Enter the new value:" << endl;
                            getline(cin,one_4_3);

                                if (!validateint(one_4_3)) {
                                    cout << "Enter a non-negative value!" << endl;
                                } else {
                                    
                                    three_4 = stod(one_4_3);
                                    if (three_4 < 0){
                                        cout << "Enter a non-negative value!" << endl;
                                    }else
                                     players_selected[placeholder].setGold(three_4);
                                }     
                            
    
                        } while (!validateint(one_4_3));
                        break;
                }
                break;

            case 5:
                cout << "Which enemy's stats do you want to edit?" << endl;
                for (int i = 0; i < 2; ++i) {
                    enemies_selected[i].printStats();
                    cout << "----------------------------------------------" << endl;
                }
                do {
                    getline(cin, choice_name_four);
                    if (choice_name_four == enemies_selected[0].getName()) {
                        placeholder = 0;
                    } else if (choice_name_four == enemies_selected[1].getName()) {
                        placeholder = 1;
                    }
                } while (choice_name_four != enemies_selected[0].getName() && choice_name_four != enemies_selected[1].getName());
                cout << "The selected character is:" << endl;
                cout << "Editing enemy " << enemies_selected[placeholder].getName() <<"'s stats:"<<endl;

               
                cout << "1. Edit hp" << endl;
                cout << "2. Edit condition" << endl;
                cout << "3. Edit gold" << endl;
                cin >> choice_four;

                switch (choice_four) {
                    case 1:
                        double one_5;
                        cin.ignore();
                        do {
                            cout << "Enter the new value:" << endl;
                          
                            getline(cin,one_5_1);
                            

                                if (!validateint(one_5_1)) {
                                    cout << "Enter a non-negative value!" << endl;
                                } else {
                                    one_5 = stod(one_5_1);
                                    if (one_5 < 0){
                                           cout << "Enter a non-negative value!" << endl;
                                    }else{

                                    enemies_selected[placeholder].setHP(one_5);
                                    }
                                }           
                            
                        } while (!validateint(one_5_1));
                        break;
                    case 2:
                        char two_5;
                        do {
                            cout << "Enter the new value:" << endl;
                            cin >> two_5;
                            if (two_5 == 'H' || two_5 == 'D' || two_5 == 'P') {
                                enemies_selected[placeholder].setCondition(two_5);
                            } else {
                                cout << "Enter a value among 'H', 'D' or 'P'!" << endl;
                            }
                        } while (!(two_5 == 'H' || two_5 == 'D' || two_5 == 'P'));
                        cin.ignore();
                        break;
                    case 3:
                        double three_5;
                        cin.ignore();
                        do {

                             cout << "Enter the new value:" << endl;
                             getline(cin,one_5_3);

                                if (!validateint(one_5_3)) {
                                   cout << "Enter a non-negative value!" << endl;
                                } else {
                                    three_5 = stod(one_5_3);

                                    if (three_5 < 0){
                                           cout << "Enter a non-negative value!" << endl;
                                    }else{
                                     enemies_selected[placeholder].setGold(three_5);
                                    }
                                }    
                            
                
                        } while (!validateint(one_5_3));
                        break;
                }
                break;
        }
    } while (choice1 != 6);
    void DispplayMap();


    cout << "Bye!!" << endl;


    
}
