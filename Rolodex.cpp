// -------------- INFO.2680-061 C++ Programming ----------//
// --------------		 Keith Caram		--------------//
//---------------		ROLODEX PROJECT	    --------------//
/* This is a source file for our Rolodex Project - it covers the definition of all member functions
   for the Rolodex Class. The Rolodex Class handles all of the actions that will be performed on
   the Card objects in our Rolodex Object by using iterators, algorithms, and member functions of 
   the Card class to manipulate card positions, add/remove cards, search cards, flip though cards,
   and print all cards. */

   
/* User Created Header File Declaration */
#include "Rolodex.h"

/* Standard Library Header File Declaration */
#include <algorithm>
#include <iomanip>

/* Member function that adds a card object to the Rolodex */
void Rolodex::add(const Card& addCard) {
	/* Lambda function to place an iterator at the correct spot to insert new card */
	auto itr = find_if(myRolo.begin(), myRolo.end(),//using find_if function
		[addCard](Card const& roloCrd) { return
		( roloCrd.getLsName() >= addCard.getLsName()); });
	/* Case if two entries have the same last name */
	while (itr != myRolo.end() && itr->getLsName() == addCard.getLsName() 
		   && addCard.getFrName() > itr->getFrName() ) {
		itr++;
	};

	myRolo.insert(itr, addCard);	
	it = --itr;//change iterator to location of inserted card
};// end add

/* Rolodex function to erase the current card*/
void Rolodex::remove() {
	it = myRolo.erase(it++);//set iterator to next object
	/* if iterator is at the end of the list loop to the beginning */
	if (it == myRolo.end()) {
		it = myRolo.begin();
	};//end if
};//end remove

/* return the card object that the iterator is pointing to */
Card Rolodex::getCurrentCard() {
	return *it;
};//end getter

/* Move iterator to next card in the Rolodex */
Card Rolodex::flip() {
	it++;
	/* if iterator is at the end of the list loop to the beginning */
	if (it == myRolo.end()) {
		it = myRolo.begin();
	}//end if
	return *it;
};//end flip

/* Member function to search for a specific card by name (first and last) */
bool Rolodex::search(const string& first, const string& last) {
	/* Lambda function to place an iterator at the card that matches search criteria  */
	auto itr = find_if(myRolo.begin(), myRolo.end(),
		[first, last](Card const& crdName){ return (crdName.getFrName() == first && 
		crdName.getLsName() == last); });

	/* only return true if the iterator stopped on a matching card */
	if (itr != myRolo.end()) {
		it = itr;//set iterator to matched card
		return true;
	}
	/* return false because the funtion hit the end of the rolodex without finding a matching card */
	else
		return false;
};//end search

/* Member function that prints all cards in the rolodex */
void Rolodex::show(ostream& Out) {
	cout << "\n" << setw(12) << "First Name" << setw(12) << "Last Name" << setw(40)
		<< "Address" << setw(25) << "Occupation" << setw(15) << "Phone Number" << endl;
	/* For loop that calls the show member function from the Card class 
	   from beginning to end of the rolodex */
	for (list<Card>::iterator print = myRolo.begin(); print != myRolo.end(); print++) {
		print->show(Out);
	};//end for
};//end show