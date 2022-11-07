#include "Orders.h"
#include <iostream>
#include <string>
using namespace std;

/*
	ORDERS SOURCE
*/

// Constructors ----------------
Orders::Orders() : _orderType(new string("Default Order"))
{ // Defualt Constructor
	_currentState->assign("Order: Default Order");
}

Orders::Orders(const Orders &theOrder)
{ // Copy Constructor
	this->_orderType = new string(*(theOrder._orderType));
}

// Assignment Operator ---------
Orders &Orders::operator=(const Orders &theOrder)
{
	this->_orderType = new string(*(theOrder._orderType));
	return *this;
}

// Methods ---------------------
bool Orders::validate()
{	
	valid = true;
	return valid; // returns false because 'Orders' is not a valid order
}

void Orders::execute()
{
	if (valid)
		cout << "Order validated" << endl;
	else
		cout << "INVALID COMMAND" << endl;
}

Orders::Orders(string orderType)
{ // sets up the type of the order
	this->_orderType = new string(orderType);
}

string Orders::getType() const
{
	return *(_orderType);
}

std::ostream &operator<<(std::ostream &desc, const Orders &theOrder)
{
	return desc << "Order Type: " << theOrder.getType();
}

/*
	DEPLOY SOURCE
*/

// Constructors ----------------
Deploy::Deploy() : Orders("deploy")
{ // default constructo
  //_currentState->assign("Deploy: Place some armies on one of the current player's territories."); // FIX THIS
}

Deploy::Deploy(const Deploy &toDep)
{ // copy constructor
	this->_currentState->assign(*toDep._currentState);
}

// Assignment Operator ---------
Deploy &Deploy::operator=(const Deploy &toDep)
{
	Orders::operator=(toDep);
	return *this;
}

// Methods ---------------------
bool Deploy::validate()
{
	cout << "Deploy: Place some armis on one of the current player's territories." << endl;
}

void Deploy::execute()
{
	if (validate())
		cout << "Deploy: Place some armis on one of the current player's territories." << endl;
	else
		cout << "INVALID ORDER" << endl;
}

/*
	ADVANCE SOURCE
*/

// Constructors ----------------
Advance::Advance() : Orders("Advance")
{
}

Advance::Advance(const Advance &toAdv)
{ // copy constructor
	this->_currentState->assign(*toAdv._currentState);
}

// Assignment Operator ---------
Advance &Advance::operator=(const Advance &toAdv)
{
	Orders::operator=(toAdv);
	return *this;
}

// Methods ---------------------
bool Advance::validate()
{
}

void Advance::execute()
{
	if (valid)
		cout << "Advance validated: " << endl;
	else
		cout << "INVALID ORDER" << endl;
}

/*
	BOMB SOURCE
*/

// Constructors ----------------
Bomb::Bomb() : Orders("Bomb")
{ // default constructor
}

Bomb::Bomb(const Bomb &toBomb)
{ // copy constructor
	this->_currentState->assign(*toBomb._currentState);
}

// Assignment Operator ---------
Bomb &Bomb::operator=(const Bomb &toBomb)
{
	Orders::operator=(toBomb);
	return *this;
}

// Methods ---------------------
bool Bomb::validate()
{
}

void Bomb::execute()
{
	if (valid)
		cout << "Bomb: " << endl;
	else
		cout << "INVALID ORDER" << endl;
}

/*
	BLOCKADE SOURCE
*/

// Constructors ----------------
Blockade::Blockade() : Orders("Blockade")
{ // default constructor
}

Blockade::Blockade(const Blockade &toBlock)
{ // copy constructor
	this->_currentState->assign(*toBlock._currentState);
}

// Assignment Operator ---------
Blockade &Blockade::operator=(const Blockade &toBlock)
{
	Orders::operator=(toBlock);
	return *this;
}

// Methods ---------------------
bool Blockade::validate()
{
}

void Blockade::execute()
{
	if (valid)
		cout << "Blockade: " << endl;
	else
		cout << "INVALID ORDER" << endl;
}

/*
	AIRLIFT SOURCE
*/

// Constructors ----------------
Airlift::Airlift() : Orders("Airlift")
{ // default constructor
}

Airlift::Airlift(const Airlift &toAir)
{ // copy constructor
	this->_currentState->assign(*toAir._currentState);
}

// Assignment Operator ---------
Airlift &Airlift::operator=(const Airlift &toAir)
{
	Orders::operator=(toAir);
	return *this;
}

// Methods ---------------------
bool Airlift::validate()
{
}

void Airlift::execute()
{
	if (valid)
		cout << "Airlift: " << endl;
	else
		cout << "INVALID ORDER" << endl;
}

/*
	NEGOTIATE SOURCE
*/

// Constructors ----------------
Negotiate::Negotiate() : Orders("Negotiate")
{ // default constructor
  //*this->_currentState = "Negotiate";
}

Negotiate::Negotiate(const Negotiate &toNegotiate)
{ // copy constructor
	this->_currentState->assign(*toNegotiate._currentState);
}

// Assignment Operator ---------
Negotiate &Negotiate::operator=(const Negotiate &toNegotiate)
{
	Orders::operator=(toNegotiate);
	return *this;
}

// Methods ---------------------
bool Negotiate::validate()
{
}

void Negotiate::execute()
{
	if (valid)
		cout << "Negotiate: " << endl;
	else
		cout << "INVALID ORDER" << endl;
}

/*
	ORDERLIST CLASS
*/

// Constructors ----------------
OrderList::OrderList()
{ // default constructor
	_theList = new queue<Orders *>();
}
OrderList::~OrderList()
{
	delete _theList;
	_theList = NULL;
}
// copy constructor
OrderList::OrderList(const OrderList &list)
{
	this->_theList = new queue<Orders *>();

	for (int i = 0; i < list._theList->size(); i++)
	{
		Orders *order = list._theList->front();
		list._theList->pop();
		list._theList->push(order);
		this->_theList->push(order);
	}
}

// Assignment Operator ---------
OrderList &OrderList::operator=(const OrderList &list)
{
	for (int i = 0; i < _theList->size(); i++)
		_theList->pop();

	for (int i = 0; i < list._theList->size(); i++)
	{
		Orders *order = list._theList->front();
		list._theList->pop();
		list._theList->push(order);
		this->_theList->push(order);
	}
}

// Methods ---------------------
void OrderList::remove()
{
	_theList->pop();
}

void OrderList::move(int first, int second)
{

	int a = _theList->size();
	cout << a << endl;
	if (first < a && second < a && first != second)
	{
		Orders *f;
		Orders *l;
		for (int i = 0; i < first; i++)
		{
			Orders *order = _theList->front();
			_theList->pop();
			_theList->push(order);
		}
		f = _theList->front();
		_theList->pop();

		for (int i = first; i < second - 1; i++)
		{
			Orders *order = _theList->front();
			_theList->pop();
			_theList->push(order);
		}
		l = _theList->front();
		_theList->pop();
		bool check = false;

		// cout << *f->_orderType << endl; // moving objects
		// cout << *l->_orderType << endl;

		_theList->push(l);
		for (int i = 0; i < first; i++)
		{
			Orders *order = _theList->front();
			_theList->pop();
			_theList->push(order);
		}
		if (second == a - 1)
			_theList->push(f);
		else
		{
			for (int i = 0; i <= second - first; i++)
			{
				Orders *order = _theList->front();
				_theList->pop();
				_theList->push(order);
			}
			_theList->push(f);
			for (int i = 0; i < a - second; i++)
			{
				Orders *order = _theList->front();
				_theList->pop();
				_theList->push(order);
			}
		}

		return;
	}
	cout << "The move order list has not correct input.\n";
	exit(0);
}

int OrderList::size()
{
	return _theList->size();
}

std::queue<Orders *> &OrderList::get_order_list()
{
	return *this->_theList;
}

std::ostream &operator<<(std::ostream &out, const OrderList &list)
{
	out << "OrderList contants: " << endl;
	cout << "in the stream insertion" << endl;

	for (int i = 0; i < list._theList->size(); i++)
	{
		Orders *order = list._theList->front();
		out << *order->_orderType << endl;
		list._theList->pop();
		list._theList->push(order);
	}
	return out;
}
