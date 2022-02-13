#include "World.h"


World::World() {
	player = new Player();
	maxFights = 3;
	lvl = 1;
	maxLvl = 4;
}


void World::fight() {
	srand((unsigned)time(NULL));
	cout << "A new challenger approaches..." << endl;
	Enemy* enemy = new Enemy(rand() % (50*lvl) + 60,rand() % (5*lvl) + 5, rand() % (3 * lvl) + 4, (float)(rand() % (5*lvl)+10) / 100,0);
	enemy->setReward(enemy->getLives() -100 + lvl * 40);
	enemy->displayStats();
	while (player->getLives() > 0 && enemy->getLives() > 0) {

		if (enemy->getAgility() < (float)rand() / RAND_MAX) {
			float damage = (player->getDmg() * player->getSword()->getDmgMultiplier() - enemy->getDef());
			if (damage > 0) {
			enemy->setLives(enemy->getLives() - damage);
			cout << "Enemy was hit for " << damage << "!" << endl;
			}
			else {
				enemy->setLives(enemy->getLives() - 1);
				cout << "Enemy was hit for " << 1 << "!" << endl;
			}
		}
		else {
			cout << "The enemy dodged!" << endl;
		}
		if (player->getAgility() < (float)rand() / RAND_MAX) {
			float damage = (enemy->getDmg() - player->getDef()*player->getShield()->getDefMultiplier());
			if (damage > 0) {
			player->setLives(player->getLives() - damage);
			cout << "Player was hit for " << damage << "!" << endl;
			}
			else {
				player->setLives(player->getLives() - 1);
				cout << "player was hit for " << 1 << "!" << endl;
			}
		}
		else {
			cout << "The player dodged!" << endl;
		}
	}
	if (player->getLives() > 0) {
	player->setCoins(player->getCoins() + enemy->getReward());
	cout << "You were rewarded " << enemy->getReward() << " coins for defeating the enemy!" << endl;
	}
	delete enemy;
}

void World::shop() {
	srand(time(NULL));
	cout << "You enter a room with 2 chests in the middle."  << endl 
		<<"There's a voice telling you to leave the coin required to purchase an item, \n but you can only pick one..." << endl;
	Shield* shld = new Shield((float)(rand() % (int)(100*player->getShield()->getDefMultiplier()))/100 + player->getShield()->getDefMultiplier());
	Sword* swrd = new Sword((float)(rand() % (int)(100 * player->getSword()->getDmgMultiplier())) / 100 + player->getSword()->getDmgMultiplier());
	shld->setCost(50*lvl + rand() % 50 -50);
	swrd->setCost(50 * lvl + rand() % 50 - 50);
	cout << "Choose by typing 'sword' or 'shield'!" << endl;
	string temp;
	cin >> temp;

	if (temp == "sword" && swrd->getCost() < player->getCoins()) {
		delete player->getSword();
		player->setSword(swrd);
		player->setCoins(player->getCoins() - swrd->getCost());
		delete shld;

	}
	else if (temp == "shield" && shld->getCost() < player->getCoins()) {
		delete player->getShield();
		player->setShield(shld);
		player->setCoins(player->getCoins() - shld->getCost());
		delete swrd;
	}
	else {
		cout << "You don't have enough coin!" << endl;
		delete shld;
		delete swrd;
	}


}


void World::game() {
	srand(time(NULL));
	cout << "You're one of the last adventurers of this world. \n You came from a far away land, your soul striving for adrenaline and plunders."<< endl 
		<<" Walking across the plains, you finally found your calling, a dungeon. "<< endl  
		<<" You take a step inside and the gate closes behind you leaving no way out... " << endl;
	while (lvl < maxLvl && player->getLives() >= 0) {
		if(lvl >1)
			shop();

	for (int i = 0; i < maxFights && player->getLives() >= 0; i++) {
		if (i > 0) {
			float heal = rand() % 40 + 20;


			if (player->getLives() + heal < 100) {
				player->setLives(player->getLives() + heal);
				cout << "The spirit of an old adventurer heals you for " << heal << endl;
			}
			else {
				player->setLives(100);
				cout << "The spirit of an old adventurer fully heals you." << endl;
			}
			
		}
		fight();
		cout << "Your health is " << player->getLives() << endl;
		cin.ignore();

	}
	
	lvl++;

	
}
	if (player->getLives() <= 0) {
	cout << "You've met with a terrible fate..." << endl;
	}
	else {
		cout << "You have bested all enemies! The glory awaits!" << endl;
	}
}

World::~World() {
	delete(player);
}