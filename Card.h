// -------------- INFO.2680-061 C++ Programming ----------//
// --------------		 Keith Caram		--------------//
//---------------		ROLODEX PROJECT	    --------------//
/* This is a header file for our Rolodex Project - it covers the declaration of all variables 
   and function prototypes for the Card Class. The Card Class handles all of the actions that
   will be performed by each Card object including constructors, getters, setters, and a 
   function to print a single Card object */

/* Include safeguard to make sure the header is only included once */
#pragma once

/* Standard Library Header File Declaration */
#include <string>
#include <iostream>

/* namespace Declaration */
using namespace std;

/* declaration of Card Class */
class Card{
public:
	/* Public Member function prototype declarations */
	Card();
	Card (const string, const string, const string, const string, const string);
	string getFrName() const;
	void setFrName(const string);
	string getLsName() const;
	void setLsName(const string);
	string getAddrs () const;
	void setAddrs(const string);
	string getOccup () const;
	void setOccup(const string);
	string getPhoNum() const;
	void setPhoNum(const string);
	void show(ostream&);


private:
	/* private instance variable representing all strings that store data in a card object */
	string frName;
	string lsName;
	string addrs;
	string occup;
	string phoNum;
};