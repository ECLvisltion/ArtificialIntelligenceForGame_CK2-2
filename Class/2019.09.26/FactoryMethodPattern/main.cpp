#include "Pizza.h"
#include "PizzaStore.h"
#include "CKPizzaStore.h"
#include "NYPizzaStore.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	PizzaStore * ckStore = new CKPizzaStore();
	PizzaStore * nyStore = new NYPizzaStore();

	Pizza * pizza = ckStore->OrderPizza("Cheese");
	cout << "Order : " << pizza->GetPizzaName() << endl;

	pizza = nyStore->OrderPizza("Pepperoni");
	cout << "Order : " << pizza->GetPizzaName() << endl;

	delete ckStore, nyStore;

	return 0;
}