// -------------- INFO.2680-061 C++ Programming ----------//
// --------------		 Keith Caram		--------------//
//---------------		ROLODEX PROJECT	    --------------//
/* This is a header file for our Rolodex Project - it covers the declaration of all variables and
   function prototypes for the Rolodex Class. The Rolodex Class handles all of the actions that 
   will be performed on the Card objects in our Rolodex Object by using iterators, algorithms, 
   and member functions of the Card class to manipulate card positions, add/remove cards, search 
   cards, flip though cards, and print all cards. */
  
/* Include safeguard to make sure the header is only included once */
#pragma once

/* Standard Library Header File Declaration */
#include <list>

/* User Created Header File Declaration */
#include "Card.h"

/* declaration of Rolodex Class */
class Rolodex {
public:
	/* Public Member function prototype declarations */
	void add(const Card&);
	void remove();
	Card getCurrentCard();
	Card flip();
	bool search(const string&, const string&);
	void show(ostream&);

private:
	/* private instance variable representing the the list of Card objects and an iterator */
	list<Card> myRolo;
	list<Card>::iterator it;
};