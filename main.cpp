#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "SortedLinkedList.h"
using namespace std;

// Intro that reads commands
void intro() {
	cout << "\nCommands:\n(i) - Insert value\n(d) - Delete value\n";
	cout << "(s) - Search value\n(n) - Print next iterator value\n(r) - Reset iterator\n";
	cout << "(a) - Delete alternate nodes\n(m) - Merge two lists\n(t) - Intersection\n";
	cout << "(p) - Print list\n(l) - Print length\n(q) - Quit program" << endl;
} // end intro

void makeList(SortedLinkedList s, string file) {
	ifstream libFile;
	libFile.open(file, ios::in);
	char n;
	string number;
	// While loop to put items into list
	while(libFile.get(n)) {
		ItemType i;
		if (n != ' ' && n != '\n' && n != '\0') {
			number.push_back(n);
		} else {
			stringstream st;
			int nu;
			st << number;
			st >> nu;
			i.initialize(nu);
			s.insertItem(i);
		} // if
	} // while
	libFile.close();
} // end makeList

// Program main
int main(int argc, char **argv) {
	if (argc != 2) { // error check for correct argument number
		cerr << "Usage: main [text_file]" << endl;
		exit (1);
	} // if
	string file = argv[1];
	SortedLinkedList s;
	makeList(s, file);
	intro(); // call function above
	int quit = 0;
	char command = 0;
	int num = 0;
	while (quit == 0) {
		cout << "Enter a command: ";
		cin >> command;
		cout << endl;
		if (command == 105) { // i
			s.printList();
			cout << "Enter number: ";
			cin >> num;
			ItemType i;
			cout << endl;
			i.initialize(num);
			s.insertItem(i);
			s.printList();
		} else if (command == 100) { // d
			s.printList();
			cout << "Enter value to delete: ";
			cin >> num;
			ItemType i;
			cout << endl;
			i.initialize(num);
			s.deleteItem(i);
			s.printList();
		} else if (command == 115) { // s
			cout << "Enter a value to search: ";
			cin >> num;
			ItemType tp;
			tp.initialize(num);
			cout << endl << "Index " << s.searchItem(tp) << endl;
		} else if (command == 110) { // n
			cout << s.GetNextItem().getValue() << endl;
		} else if (command == 114) { // r
			s.ResetList();
			cout << "Iterator reset." << endl;
		} else if (command == 97) { // a
			cout << "List before alternate delete: ";
			s.printList();
			cout << endl << "List after alternate delete: ";
			s.printList();
			cout << endl;
		} else if (command == 108) { // l
			cout << "List length is " << s.length() << endl;
		} else if (command == 109) { // m
			string numsToMerge;
			stringstream ss;
			int nb;
			cout << "Length of list to merge: ";
			cin >> num;
			cout << endl << "List elements separated by spaces in order: ";
			cin >> numsToMerge;
			ss << numsToMerge;
			SortedLinkedList l;
			// While there is another number
			while (ss.peek() != '\0' && ss.peek() != '\n') {
				ItemType t;
				ss >> nb;
				t.initialize(nb);
				l.insertItem(t);
			} // while
			cout << endl << "List 1: ";
			s.printList();
			cout << endl << "List 2: ";
			l.printList();
			s.merge(l); // merge original and user's lists
			cout << endl;
			s.printList();
			cout << endl;
			l.~SortedLinkedList(); // destroy temporary list
		} else if (command == 116) { // t
			string numsToInt;
			stringstream strm;
			int nm;
			cout << "Length of list to find intersection: ";
			cin >> num;
			cout << endl << "List elements separated by spaces in order: ";
			cin >> numsToInt;
			strm << numsToInt;
			SortedLinkedList l;
			// While there is another number
			while (strm.peek() != '\0' && strm.peek() != '\n') {
				ItemType ty;
				strm >> nm;
				ty.initialize(nm);
				l.insertItem(ty);
			} // while
			cout << endl << "List 1: ";
			s.printList();
			cout << endl << "List 2: ";
			l.printList();
			cout << endl << "Intersect: ";
			s.intersection(l);
			cout << endl;
		} else if (command == 112) { // p
			s.printList();
		} else if (command == 113) { // q
			cout << "Quitting program..." << endl;
			quit = 1;
		} else {
			cout << "Invalid command, try again!" << endl;
		} // if/else
	} // while
	return 0; // successfully ended
} // end main
