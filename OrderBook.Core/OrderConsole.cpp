#include "OrderConsole.h"
#include <iostream>

OrderConsole::OrderConsole()
{
}

OrderConsole::~OrderConsole()
{
}

void OrderConsole::PrintOrder(Order order)
{
	std::cout << "************** New Order Arrived" << std::endl;
	std::cout << "Id:		" << order.getId()		<< std::endl;
	std::cout << "IsBuy:	" << order.getIsBuy()	<< std::endl;
	std::cout << "Price:	" << order.getPrice()	<< std::endl;
	std::cout << "Volume:	" << order.getVolume()	<< std::endl;
	std::cout << "Client:	" << order.getClient()	<< std::endl;
	std::cout << "--------------------------------" << std::endl;
}
