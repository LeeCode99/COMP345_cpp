#include "OrdersDriver.h"
class Orders;

int testOrdersLists()
{

    OrderList ol;
    Negotiate *negotiate1 = new Negotiate();
    Deploy *deploy1 = new Deploy();
    Airlift *airlift1 = new Airlift();
    Blockade *blockade1 = new Blockade();

    ol.get_order_list().push(negotiate1);
    ol.get_order_list().push(deploy1);
    ol.get_order_list().push(airlift1);
    ol.get_order_list().push(blockade1);
    cout << ol << endl;
    cout << endl;
    ol.move(0, 2);

    cout << ol << endl;

    cout << endl;
    ol.remove();

    cout << ol << endl;
    cout << endl;

    

    deploy1->validate();

    ol.~OrderList();
    
    return 0;
}