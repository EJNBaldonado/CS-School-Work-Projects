
//#include "Player.cpp"
#include "Chest.hpp" // ADDED
#include "MagicChest.hpp"
#include "PhysicalChest.hpp"
//#include "MonsterFactory.hppi"
#include <iostream>
#include <cstdlib>
using namespace std;

void introduction(Player* &player) { 
	cout << "Welcome to Dungeon Conquest! Would you like to know how to play? Press 'Y/y' if so." << endl;
	char input;
	cin >> input;
	if (input == 'y' || input == 'Y') { 
	    cout << "\nGreat, let's get you started. Dungeon Conquest is a game about adventure and slaying monsters." 
		 << "\nFollow the directions for inputs for each of your character actions. Play to your heart's content! " << endl;

	cout << "What is your name, traveler?" << endl;
	string name;
	cin.ignore();
	getline(cin, name);
	player->setName(name);
	cout << endl;
	cout << "Welcome, " << name << " you have just entered the dungeon!" << endl;
	}
	else{
		exit(1);
	}
}

// a fight method outline that (hopefully) can be used for every enemy the player encounters
void fight(Player* &player, Monster* monster, bool &endOfGame) { 
	cout << "You encounter a " << monster->monsterType() << "!" << endl;
	int option = 0;
	int mHth = monster->getMaxHealth();
	cout << "The monster's health is at " << mHth << endl << "Your player's health is at " << player->getCurrentHealth() << endl;
	cout << endl << "--------------------------------------------------" << endl;
	while( (mHth > 0) && (player->getCurrentHealth() > 0) ){ 
	    cout << "Choose an option: Inspect(1), Physical Attack(2), Magical Attack(3), Player's Stats(4)" << endl;
	    cin >> option;
	    if (option == 1) { 
		cout << endl << "--------------------------------------------------" << endl;
		cout << "MONSTER TYPE: " <<  monster->monsterType() << endl;
		cout << "ATTACK:" << monster->getAttack() << endl;
		cout << "MAGICAL DEF: " << monster->getMagicalDef() << endl;
		cout << "PHYSICAL DEF: " << monster->getPhysicalDef() << endl << endl;
		cout << "The monster's health is at " << mHth << endl << endl << "Your player's health is at " << player->getCurrentHealth();
        	cout << endl << "--------------------------------------------------" << endl;
	    }
	    else if (option == 2) {
		int damage = (player->Stats->getPhysicalAtk() + rand() % player->getLevel())- monster->getPhysicalDef();
		if (damage < 0){
			damage = 0;
		} 
		cout << endl << "--------------------------------------------------" << endl;
		cout << "You attack the monster and deal " << damage << " damage!" << endl;
		mHth -= damage;
		int dmg = monster->monsterHit() - player->Stats->getDefense();
		if (dmg < 0){
			dmg = 0;
		}
		cout << "The monster counter-attacked! You took " << dmg << " damage." << endl; 
		player->setCurrentHealth(player->getCurrentHealth() - dmg);
                if (mHth < 0){
                mHth = 0;
                }
                if (player->getCurrentHealth() < 0){
                player->setCurrentHealth(0);
                }
		cout << endl << "Monster Health : " << mHth << endl;
		cout << endl <<  "Player Health : " << player->getCurrentHealth();	
		cout << endl << "--------------------------------------------------" << endl;
	    }
	    else if (option == 3) {	 
		int damage = (player->Stats->getMagicAtk() + rand() % player->getLevel())- monster->getMagicalDef();
		if (damage < 0){
			damage = 0;
		}
		cout << endl << "--------------------------------------------------" << endl; 
		cout << "You attack the monster and deal " << damage << " damage!" << endl;
                mHth -= damage;
		int dmg = monster->monsterHit() - player->Stats->getDefense();
		if (dmg < 0){
			dmg = 0;
		} 
                cout << "The monster counter-attacked! You took " << dmg << " damage." << endl;
                player->setCurrentHealth(player->getCurrentHealth() - dmg);
		if (mHth < 0){
		mHth = 0;
		}
		if (player->getCurrentHealth() < 0){
		player->setCurrentHealth(0);
		}
                cout << endl << "Monster Health : " << mHth << endl;
                cout << endl <<  "Player Health : " << player->getCurrentHealth();
		cout << endl << "--------------------------------------------------" << endl;
	    }
            else if (option == 4){
                cout << player->getName() << "'s stats: ";
                player->displayPlayerStats();
		cout << endl <<  "The monster's health is at " << mHth << endl << endl << "Your player's health is at " << player->getCurrentHealth();
                cout << endl << "--------------------------------------------------" << endl;
            }
	    else if (!(option == 1 || option == 2 || option == 3 || option == 4)){
		cout << "Invalid input, please try again." << endl;
		cin >> option;
	    }
	}
	if (mHth <= 0 && player->getCurrentHealth() != 0) {
		cout << endl << "--------------------------------------------------" << endl; 
	    	cout << "You have defeated the " << monster->monsterType() << "!" << endl;
		//delete monster;
		player->nextLevel();
		cout << endl << "--------------------------------------------------" << endl;
	    // function for exp allocation is called
	    return;
	}
	else {
	    cout << "YOU DIED" << endl;
	    endOfGame = true;
	    return;
}
}

void findChest(Chest* chest, Player* player){
	Item* item = chest->itemFinder();
	item->printItem(item->getRarity());
	cout << "Would you like to equip it? Select 'y/Y' or 'n'/N' to choose what to do with your item." << endl;
	char option;
	cin >> option;
	while(option != 'y' && option != 'n' && option != 'Y' && option != 'N'){
		cout << "Please select 'y/Y' or 'n/N' to choose what to do with your item!" << endl;
		cin >> option;
	}
	if (option == 'y' || option == 'Y'){
		item->equip(player);
		delete item;
                cout << endl << "--------------------------------------------------" << endl;
		return;
	}
	else{
		delete item;
		cout << "You left the item and continued through the dungeon." << endl;
                cout << endl << "--------------------------------------------------" << endl;

		return;
	}
}


// this is a general outline of how the interface should be: as small and modular as possible with lots of helper functions


int main(){
    char input = '0';
    bool endOfGame = false;
    int floor = 1;
    
    srand(time(NULL));    

    Player* player = new Player();	

    introduction(player);

    MonsterFactory* factory = new MonsterFactory(floor);
    
    cout << player->getName() << "'s stats: ";
    
    player->displayPlayerStats();

    cout << endl;	
 
    while (endOfGame != true){	
	    cout << "Where to next? Left door(1), Middle door(2), Right door(3), Player Stats(4)" << endl; 
	    cin >> input;
	    if (input == '1') {
	        cout << endl <<  "--------------------------------------------------" << endl; 
		int outcome = rand() % 2;

		if(player->getLevel() > factory->getFloor()){
		    int nextFloor = rand() % 2;
			if (nextFloor == 1){	
				MonsterFactory* tmp = factory;
				floor = floor + 1;
				factory  = new MonsterFactory(floor);
				delete tmp;
				cout << "You've reached a staircase and have entered a new floor!" << endl;
				player->setCurrentHealth(player->getMaxHealth());
                                cout << "Health is restored! Total health: " << player->getCurrentHealth() << endl;
				//ADDED CODE

				if(floor >= 3){
				int treasureChance = rand() % 3;
				if (treasureChance == 0 || treasureChance == 1){
				cout <<  "--------------------------------------------------" << endl;
				cout << "You found a treasure room! The room is booby-trapped so you may only select one Chest. Press \"1\" for the Physical chest, and \"2\" for the Magical Chest." << endl;
				int chestSelect = 0;
				cin >> chestSelect;
					while (chestSelect != 1 && chestSelect != 2) {
                                        	cout << "Invalid input. Please press \"1\" to open the Physical chest, and \"2\" for the Magical Chest." << endl;
                                        	cin >> chestSelect;
					}
					if (chestSelect == 1){
						cout << endl << "You open the Physical chest!" << endl;
						Chest* chest = new PhysicalChest();
						findChest(chest, player);
						delete chest;	
					}
					else {
						cout << endl << "You open the Magical chest!" << endl;
						Chest* chest = new MagicChest();
						findChest(chest, player);
						delete chest;	
					}	
				}
				}
			}	
		}
	        
		if (outcome == 1){
                   fight(player, factory->getMonster(), endOfGame);
		   cout << endl << "--------------------------------------------------" << endl;
                }
		else {
		   cout << "You tread carefully through the corridor..." << endl;
		   cout << endl << "--------------------------------------------------" << endl;
		}

    	    }
	    else if (input == '2') {
		cout << endl << "--------------------------------------------------" << endl; 
                int outcome = rand() % 2;

                if(player->getLevel() > factory->getFloor()){
                    int nextFloor = rand() % 2;
                        if (nextFloor == 1){
                                MonsterFactory* tmp = factory;
                                floor = floor + 1;
                                factory  = new MonsterFactory(floor);
                                delete tmp;
				cout << "You've reached a staircase and have entered a new floor!" << endl;
				player->setCurrentHealth(player->getMaxHealth());
				cout << "Health is restored! Total health: " << player->getCurrentHealth() << endl;  
				//ADDED CODE
                                if(floor >= 3){
				int treasureChance = rand() % 3;
				if (treasureChance == 0 || treasureChance == 1){
                                cout <<  "--------------------------------------------------" << endl;
                                cout << "You found a treasure room! The room is booby-trapped so you may only select one Chest. Press \"1\" for the Physical chest, and \"2\" for the Magical Chest." << endl;
                                int chestSelect = 0;
                                cin >> chestSelect;
                                        while (chestSelect != 1 && chestSelect != 2) {
                                                cout << "Invalid input. Please press \"1\" to open the Physical chest, and \"2\" for the Magical Chest." << endl;
                                                cin >> chestSelect;
                                        }
                                        if (chestSelect == 1){
                                                cout << endl << "You open the Physical chest!" << endl;
                                                Chest* chest = new PhysicalChest();
                                                findChest(chest, player);
                                                delete chest;
                                        }
                                        else {
                                                cout << endl << "You open the Magical chest!" << endl;
                                                Chest* chest = new MagicChest();
                                                findChest(chest, player);
                                                delete chest;
                                        }
                                }
				}

                        }
                }

                if (outcome == 1){
                   fight(player, factory->getMonster(), endOfGame);
		   cout << endl << "--------------------------------------------------" << endl;
                }
                else {
                   cout << "You hear strange sounds echo throughout the dungeon..." << endl;
		   cout << endl << "--------------------------------------------------" << endl;
                }
	    }
	    else if (input == '3') { 
		cout << endl << "--------------------------------------------------" << endl;
                int outcome = rand() % 2;

                if(player->getLevel() > factory->getFloor()){
                    int nextFloor = rand() % 2;
                        if (nextFloor == 1){
                                MonsterFactory* tmp = factory;
                                floor = floor + 1;
                                factory  = new MonsterFactory(floor);
                                delete tmp;
				cout << "You've reached a staircase and have entered a new floor!" << endl;
				player->setCurrentHealth(player->getMaxHealth());
                                cout << "Health is restored! Total health: " << player->getCurrentHealth() << endl;
				//ADDED CODE
                                if(floor >= 3){
				int treasureChance = rand() % 3;
				if (treasureChance == 0 || treasureChance == 1){
                                	cout <<  "--------------------------------------------------" << endl;
                                	cout << "You found a treasure room! The room is booby-trapped so you may only select one Chest. Press \"1\" for the Physical chest, and \"2\" for the Magical Chest." << endl;
                                	int chestSelect = 0;
                                	cin >> chestSelect;
                                        	while (chestSelect != 1 && chestSelect != 2) {
                                                	cout << "Invalid input. Please press \"1\" to open the Physical chest, and \"2\" for the Magical Chest." << endl;
                                               		cin >> chestSelect;
                                        	}
                                        	if (chestSelect == 1){
                                                	cout << endl << "You open the Physical chest!" << endl;
                                                	Chest* chest = new PhysicalChest();
                                                	findChest(chest, player);
                                                	delete chest;
                                        	}
                                        	else {
                                                	cout << endl << "You open the Magical chest!" << endl;
                                                	Chest* chest = new MagicChest();
                                                	findChest(chest, player);
                                                	delete chest;
                                        	}
                                }
				}

                        }
                }

                if (outcome == 1){
                   fight(player, factory->getMonster(), endOfGame);
		   cout << endl << "--------------------------------------------------" << endl;
                }
                else {
                   cout << "Each step sends a chill down your spine..." << endl;
                   cout << endl << "--------------------------------------------------" << endl;
		}

	    }
            else if (input == '4'){
		cout << player->getName() << "'s stats: ";
		player->displayPlayerStats();
	   	cout << endl << "--------------------------------------------------" << endl; 
	    }
	    else { 
	        cout << "Invalid input, please try again!" << endl;
		cin >> input;
	    }
	}
	delete player;
	delete factory;	
    	return 0;
}

