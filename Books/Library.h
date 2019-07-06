#pragma once
// This program is design to be a part of software for easy access to the library
// The class Book has a members such as ISBN, title, author, and genre for each book
// It also has other interface function for operating on the Book class 
// It read the book from cin and write expected output to cout
// The library users (Patron) can easily check in or check out a book
// The patron can also check his or her balance
// The ISBN is in the format: [n-n-n-x] where n is integer and x is a digit or letter
// The patron ID is in the format: [n-x-n] where n is integer and x is a digit or letter

#include "Patron.h"
#include "Book.h"
#include<vector>
#include<string>

class Library
{
public:
	Library(){}
	~Library(){}
	struct Transaction {
		Patron pt;
		Book bk;
		std::string Date;
	};

	//modifiable function
	void add_patron(Patron& p) {patron.push_back(p); }
	void add_book(Book& b) { book.push_back(b); }

	//check out the book 
	void check_out();

	//check in the book
	void check_in();


	//execute library program
	void execute(int argc, char* argv[]);

private:
	vector<Patron> patron;
	std::vector<Book>book;
	std::vector<Transaction> transaction;
	int bk_no;
	int pt_no;
	Transaction t;
//private member function

	bool book_available(std::string& isbn);

	bool patron_available(std::string& cd_no);

	std::string make_date();

	//initialize the library data base
	void initialize(int argc, char* argv[]);

	//instruction
	void instruct();

	//check and print the name and amount of all the patron owing
	void all_patron_owing();

	//individual owing
	void patron_bal();

	//check the valid of staff before adding extra book or patron
	//void staff_valid(string& s);
};

