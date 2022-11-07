#pragma once

#include "Cards.h"
#include "Map.h"
#include "Orders.h"
#include <iostream>
#include <string>
#include <vector>

class Map;

using namespace std;

class Player
{
public:
    Player();  // default constructor
    ~Player(); // destructor
    Player(int reinforcement,string playerName, vector<string *> territoriesOwned, vector<string > playerHand, vector<Orders *> ordersIssued);
    Player(const Player &p); // copy constructor

    void toDefend();
    void toAttack();

    void issueOrder(string);

    vector<Orders *> getOrderList();
    void printOrder();
    string getName();
    string name;
    int reinforcement;
    vector<string> playerHand;
private:
    vector<string *> territories;

    vector<Orders *> OrderList;
};
