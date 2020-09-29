// -------------- INFO.2680-061 C++ Programming ----------//
// --------------		 Keith Caram		--------------//
//---------------		ROLODEX PROJECT	    --------------//
/* This is a source file for our Rolodex Project - it covers the user interaction and runtime
   actions for the Rolodex class in the main function. The main function starts by adding a number
   of names to our Rolodex. Then it prompts the user to enter a command from a list of commands.
   Based on the command that the user enters, the program will add a card, remove a card, show the
   current card to the user, flip to the next card, show all cards, show a list of commands, search
   for a specific card by its name and quit the program */

/* User Created Header File Declaration */
#include "Rolodex.h"

/* Standard Library Header File Declaration */
#include <iomanip>

/*Start Main*/
int main() {
    int flag = 1;//set while loop flag
    string cmd;//variable to store interactive command
    Rolodex rolo;//declare new rolodex

    /* Adding all of the default rolodex entries to rolodex */
    rolo.add(Card("Tony", "Hansen", "Writer", "12 E. St. NY, NY 33333", "555-9999"));
    rolo.add(Card("Jon", "Smyth", "Computer Hardware", "CMU Computer Services Pittsburgh, PA", "555-1324"));
    rolo.add(Card("Alonza", "Heard", "Mechanic", "123 Anyplace Ave Malden, MA", "555-5678"));
    rolo.add(Card("Jen", "Reyes", "Graphic artist", "325 Oak Rd Wilmington, MA", "555-4950"));
    rolo.add(Card("Alan", "Lupine", "Vet", "1 Bigelow Ave. Lawrence, MA", "555-7654"));
    rolo.add(Card("Jewel", "Proverb", "Landscaper", "34 Washington St. Waltham, MA", "555-3333"));
    rolo.add(Card("Paul", "Revere", "Radical Revolutionary", "45 Commonwealth Ave. Boston, MA", "555-1776"));
    rolo.add(Card("Adolf", "Coors", "Beer Manufacturer", "Boston MA", "555-2337"));
    rolo.add(Card("Seymour", "Papert", "Lego Professor", "MIT", "555-1111"));
    rolo.add(Card("Fred", "Milton", "Sales", "12 Freedom Way Nashua, NH", "555-9981"));

    /* Welcome message */
    cout << "Welcome to Keith's Rolodex!" << endl;

    /* Start While loop to ask for user commands */
    while (flag != 0) {
        cout << "\nEnter a command (enter 'help' for a list of commands): ";
        cin >> cmd;

        /* If tree for the 'add' command to create a new card */
        if (cmd == "add" || cmd == "Add") {

            //create new Card object and variables to store user info
            Card addCard;
            string first, last, address, occupation, phone;

            cout << "\n**Enter Card Information**" << endl;
            //add first namd
            cout << "Enter First Name: ";
            cin >> first;
            addCard.setFrName(first);
            //add last name
            cout << "Enter Last Name: ";
            cin >> last;
            addCard.setLsName(last);
            //add occupation
            cout << "Enter Occupation: ";
            cin.ignore();
            getline(cin, occupation);
            addCard.setOccup(occupation);
            //add address
            cout << "Enter Address: ";
            getline(cin, address);
            addCard.setAddrs(address);
            //add phone number
            cout << "Enter Phone Number: ";
            cin >> phone;
            addCard.setPhoNum(phone);
            //add new card to the rolodex
            rolo.add(addCard);
            cout << "**New Card Successfully Added**" << endl;
        }//end add

        /* If tree for the 'list' command to list all card */
        else if (cmd == "list" || cmd == "List") {
            rolo.show(cout);
        }//end list

        /* If tree for the 'view' command to show the current card*/
        else if (cmd == "view" || cmd == "View") {
            /* formatted header*/
            cout << "\n" << setw(12) << "First Name" << setw(12) << "Last Name" << setw(40)
                << "Address" << setw(25) << "Occupation" << setw(15) << "Phone Number" << endl;
            rolo.getCurrentCard().show(cout);
        }//end view

        /* If tree for the 'flip' command to flip to and show the next card in the rolodex */
        else if (cmd == "flip" || cmd == "Flip") {
            /* formatted header */
            cout << "\n" << setw(12) << "First Name" << setw(12) << "Last Name" << setw(40)
                << "Address" << setw(25) << "Occupation" << setw(15) << "Phone Number" << endl;
            rolo.flip().show(cout);
        }//end flip

        /* If tree for the 'remove' command to remove the current card from the rolodex */
        else if (cmd == "remove" || cmd == "Remove") {
            string yesNo;
            /* formatted header */
            cout << "\n" << setw(12) << "First Name" << setw(12) << "Last Name" << setw(40)
                << "Address" << setw(25) << "Occupation" << setw(15) << "Phone Number" << endl;
            rolo.getCurrentCard().show(cout);
            /* promt user if this is the desired delete card */
            cout << "\nRemove this card (y/n): ";
            cin >> yesNo;
            if (yesNo == "yes" || yesNo == "Yes" || yesNo == "Y" || yesNo == "y") {//if yes
                rolo.remove();
                cout << "\n**Card removed from the Rolodex**" << endl;
            };//end if
            if (yesNo == "no" || yesNo == "No" || yesNo == "N" || yesNo == "n") {//if no
                cout << "\n**Card was not removed from the Rolodex**" << endl;
            };//end if
        }//end remove

        /* If tree for 'search' command to search for a card by name values */
        else if (cmd == "search" || cmd == "Search") {
            string first;
            string last;
            /* Prompt user for info they'd like to search */
            cout << "\n**Enter the name you'd like to search**" << endl;
            cout << "\nFirst Name: ";
            cin >> first;
            cout << "Last Name: ";
            cin >> last;
            /* search tree */
            if (rolo.search(first, last) == true) {//found
                cout << "\n**Entry Found**" << endl;
                /*formatted header*/
                cout << "\n" << setw(12) << "First Name" << setw(12) << "Last Name" << setw(40)
                    << "Address" << setw(25) << "Occupation" << setw(15) << "Phone Number" << endl;
                rolo.getCurrentCard().show(cout);
            }
            else {//not found
                cout << "\n**Entry Not Found :(**" << endl;
            };//end if/else
        }//end search

        /* If tree for 'quit' command to exit program */
        else if (cmd == "quit" || cmd == "Quit") {
            flag = 0;
        }//end quit

        /* If tree for 'help' command to list all possible commands */
        else if (cmd == "help" || cmd == "Help") {
            cout << "\n**List of Commands**" << endl;
            cout << setw(10) << "List - " << "List all cards in Rolodex." << endl;
            cout << setw(10) << "View - " << "View current card in Rolodex." << endl;
            cout << setw(10) << "Flip - " << "Flip to next card in Rolodex" << endl;
            cout << setw(10) << "Add - " << "Add new card to Rolodex." << endl;
            cout << setw(10) << "Remove - " << "Remove current card in Rolodex." << endl;
            cout << setw(10) << "Search - "<< "Search for card in Rolodex by Name." << endl;
            cout << setw(10) << "Quit - " << "Exit program." << endl;
        }//end help

        /* Default command to catch any invalid commands */
        else {
            cout << "\n**Invalid Command**" << endl;
        };//end else
    };//end while loop
};//end main