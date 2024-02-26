#include <iostream>
#include "BookConsole.h"

BookConsole::BookConsole()
{
}

BookConsole::~BookConsole()
{
}


void BookConsole::place(Order& bid, Order& ask)
{
	// Bid.
	std::cout << "******************* Order placed"	<< std::endl;
	std::cout << "IsBuy:	" << bid.getIsBuy()		<< std::endl;
	std::cout << "Id:		" << bid.getId()		<< std::endl;
	std::cout << "Price:	" << bid.getPrice()		<< std::endl;
	std::cout << "Volume:	" << bid.getVolume()	<< std::endl;
	
	std::cout << "                                " << std::endl;
	
	// Ask.
	std::cout << "IsBuy:	" << ask.getIsBuy()		<< std::endl;
	std::cout << "Id:		" << ask.getId()		<< std::endl;
	std::cout << "Price:	" << ask.getPrice()		<< std::endl;
	std::cout << "Volume:	" << ask.getVolume()	<< std::endl;
	std::cout << "--------------------------------" << std::endl;
}
