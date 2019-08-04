// This program is design to be a part of software for easy access to the library
// The class Book has a members such as ISBN, title, author, and genre for each book
// It also has other interface function for operating on the Book class 
// It read the book from cin and write expected output to cout
// The library users (Patron) can easily check in or check out a book
// The patron can also check his or her balance
// The ISBN is in the format: [n-n-n-x] where n is integer and x is a digit or letter
// The patron ID is in the format: [n-x-n] where n is integer and x is a digit or letter

#include<iostream>
#include<chrono>
#include"exception_header.h"
#include"Library.h"

using namespace std;

extern int kk;



int main(int argc, char* argv[]) {

	try {
	/*	int su=0, ch = 0;

		for (int i = 0; i < 3; ++i) {

			cout << "i: " << i << endl;
			cin >> ch;
			su += ch;*/

//}
		//cout << su << endl;
		Library lib;
		lib.execute(argc, argv);

	//cout << kk << endl;

	}
	catch (exception& e) {
		cerr << e.what() << endl;
	}

	catch (...) {
		cerr << "Some exception occur " << endl;
	}

	keep_window_open();
	return 0;
}