// -------------- INFO.2680-061 C++ Programming ----------//
// --------------		 Keith Caram		--------------//
//---------------		ROLODEX PROJECT	    --------------//
/* This is a source file for our Rolodex Project - it covers the definition of all member functions
   for the Card Class. The Card Class handles all of the actions that will be performed by each 
   Card object including constructors, getters, setters, and a function to  print a single 
   Card object */

/* User Created Header File Declaration */
#include "Card.h"

/* Standard Library Header File Declaration */
#include <iomanip>

/* Default Constructor */
Card::Card()
{};/*end default constructor*/

/* Custom constructor when all data variables are passed */
Card::Card(const string first, const string last, 
	const string occupation, const string address, const string phone) 
	: frName(first), lsName(last), occup(occupation), addrs(address), phoNum(phone)
{};/*end constructor*/

/* First Name getter */
string Card::getFrName() const{
	return frName;
};/* end getter */

/* First Name setter */
void Card::setFrName(const string usrFr) {
	frName = usrFr;
};/* end setter */

/* Last Name getter */
string Card::getLsName() const{
	return lsName;
};/* end getter */

/* Last Name setter */
void Card::setLsName(const string usrLs) {
	lsName = usrLs;
};/* end setter */

/* Address getter */
string Card::getAddrs() const{
	return addrs;
};/* end getter */

/* Address setter */
void Card::setAddrs(const string usrAddrs) {
	addrs = usrAddrs;
};/* end setter */

/* Occupation getter */
string Card::getOccup() const{
	return occup;
};/* end getter */

/* Occupation setter */
void Card::setOccup(const string usrOccup) {
	occup = usrOccup;
};/* end setter */

/* Phone Number getter */
string Card::getPhoNum() const{
	return phoNum;
};/* end getter */

/* Phone Number setter */
void Card::setPhoNum(const string usrNum) {
	phoNum = usrNum;
};/* end setter */

/* Member function that formats and sends all data from a single card to an ostream object
   in order to print said card */
void Card::show(ostream& out) {
	out << setw(12) << getFrName() << setw(12) << getLsName() << setw(40) 
		<< getAddrs() << setw(25) << getOccup() << setw(15) << getPhoNum() << endl;
};/*end show*/