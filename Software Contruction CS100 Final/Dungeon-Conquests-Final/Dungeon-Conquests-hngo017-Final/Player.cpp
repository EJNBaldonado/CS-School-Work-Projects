#include "Player.hpp"


		Player::Player(){
			this->name = "";
			//this->expPoints = 0;
			this->level = 1;
			this->expPoints = 0;
			this->freePoints = 0;
			this->Stats = new Stat();
			this->currentHealth = getMaxHealth();
		}
		
		Player::~Player(){
			delete Stats;
			delete this;
		}
		void Player::setExp(int _exp){
			this->expPoints = _exp;
		}

		int Player::getExp(){
			return this->expPoints;
		}
		void Player::setLevel(int _level){
			this->level = _level;
		}
		int Player::getLevel(){
			return this->level;
		}
		int  Player::getMaxHealth(){
			return Stats->getMaxHealth();
		}
		void Player::setName(string _name){
			this->name = _name;
		}
		string Player::getName(){
			return this->name;
		}
		void Player::setCurrentHealth(int _currentHealth){
			this->currentHealth = _currentHealth;
		}
		int Player::getCurrentHealth(){
			return this->currentHealth;
		}
		void Player::nextLevel(){
			static const int exp_cap[] = {0 ,0, 500, 1000, 3000, 6000, 10000, 15000, 21000, 30000, 50000, 80000, 100000, 999999};
			expPoints += 250 * level;
			cout << "EXP EARNED / EXP CAP: " << expPoints  << " / " << exp_cap[level] << endl;
			cout << "CURRENT LEVEL: " << level << endl;

			while (expPoints >= exp_cap[level]){
				cout << endl << "--------------------------------------------------" << endl;
				level++;
				freePoints += 10;
				cout << "LEVEL UP!" << endl;
				cout << "CURRENT LEVEL: " << level << endl;
				cout << freePoints << " Stat points available for allocation! Distribute them through Body, Mind and Spirit. Choose wisely!" << endl;
				cout << this->distributePoints() << "\nNEW STATS:"; 
				this->displayPlayerStats();
			}
		}

		string Player::distributePoints() { 
			int bodyAllocation = 0;
			int mindAllocation = 0;
			int spiritAllocation = 0;

			cout << "\nHow many points would you like to invest in Body? ";
			cin >> bodyAllocation;	
			cout << "\nHow many points would you like to invest in Mind? ";
			cin >> mindAllocation;
			cout << "\nHow many points would you like to invest in Spirit? ";
			cin >> spiritAllocation;
			cout << endl;
			while ( freePoints < (bodyAllocation + mindAllocation + spiritAllocation)){
				cout << "\nHow many points would you like to invest in Body? ";
				cin >> bodyAllocation;	
				cout << "\nHow many points would you like to invest in Mind? ";
				cin >> mindAllocation;
				cout << "\nHow many points would you like to invest in Spirit? ";
				cin >> spiritAllocation;
				cout << endl;
                        	if ( freePoints < (bodyAllocation + mindAllocation + spiritAllocation) ) {
                                	cout <<  "Insufficient free points! Try Again, you have " << freePoints <<  " available to allocate to Body, Mind and Spirit." << endl;
                        	}
			}
			freePoints -= bodyAllocation + mindAllocation + spiritAllocation;
			Stats->allocatePoints(bodyAllocation, mindAllocation, spiritAllocation);
			cout << endl << "--------------------------------------------------" << endl;
	
			return "Stats successfully allocated.";
		}

		void Player::displayPlayerStats() {
			cout << "\n________________\n" << "Level: " << this->getLevel() << "\nBody: " << Stats->getBody() << "\nMind: " << Stats->getMind()<< "\nSpirit: " << Stats->getSpirit()
			<< "\nPhysicalAttack Damage: " << Stats->getPhysicalAtk()<< "\nMagicalAttack Damage: " << Stats->getMagicAtk() 
			<< "\nDefense: " << Stats->getDefense() << "\nHealth: " << currentHealth << " / " <<  Stats->getMaxHealth() << "\n_______________" << endl;
		}

