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


int main(int argc, char* argv[]) {

	try {
		Library lib;

		lib.execute(argc, argv);

		////get the current time
		//auto now = chrono::system_clock::now();
		//time_t ttm = chrono::system_clock::to_time_t(now);
		//char ch[26];
		//ctime_s(ch, sizeof(ch), &ttm);
		//string s(ch, ch + sizeof(ch));
		//cout << s << endl;

		//istream& d = cin;
		//d.exceptions(d.exceptions() | ios_base::badbit);

		//int ch1;
		//d >> ch1;

	}
	catch (exception&e) {
		cerr << e.what() << endl;
	}

	catch (execution_error& e) {
		cerr << e.what() << endl;
	}

	catch (...) {
		cerr << "Some exception occur " << endl;
	}
	keep_window_open();
	return 0;
}