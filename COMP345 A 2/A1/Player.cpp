#include "Player.h"
#include <string>
using namespace std;

Player::Player()
{
    string name;
    int reinforcement;
    vector<string *> territories;
    vector<string > playerHand;
    vector<Orders *> OrderList;
}

Player::~Player()
{
    name.clear();
    territories.clear();
    playerHand.clear();
    for (Orders *order : OrderList)
    {
        delete order;
    }
    OrderList.clear();
}
// stream insertion operater




//
Player::Player(int reinforcement, string playerName, vector<string*> territoriesOwned, vector<string> playerHand1, vector<Orders *> ordersIssued)
{
    this->reinforcement = reinforcement;
    this->name = playerName;
    this->territories = territoriesOwned;
    playerHand = playerHand1;
    this->OrderList = ordersIssued;
}

Player::Player(const Player &p)
{
    this->name = p.name;
    this->territories = p.territories;
    this->playerHand = p.playerHand;
    this->OrderList = p.OrderList;
}

void Player::toAttack()
{
    for (int i = 0; i < territories.size(); i++)
    {
        cout << *territories[i] << " ";
    }
}

void Player::toDefend()
{
    for (int i = 0; i < territories.size(); i++)
    {
        cout << *territories[i] << "\n";
    }

}
void Player::issueOrder(string order)
{
    Orders *a = new Orders(order);
    OrderList.push_back(a);
}

vector<Orders *> Player::getOrderList()
{
    return OrderList;
}

void Player::printOrder()
{
    vector<Orders *>::iterator it = OrderList.begin();
    for (; it != OrderList.end(); it++)
    {
        cout << *(*it)->_orderType << "\n";
    }

    // for(Orders *a : OrderList){
    //     cout<< a->_currentState << endl ;
    // }

    cout << endl;
}
string Player::getName()
{
    return name;
}