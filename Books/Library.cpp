#include "Library.h"
#include "exception_header.h"
#include <chrono>
#include <fstream>
using namespace std;


int kk = 2;
void Library::all_patron_owing() {
	cout << "The name(s) of people owing.." << endl;

	for (vector<Patron>::size_type i = 0; i < patron.size(); i++) {
		if (patron.at(i).own_fee()) {
			//cout << "Name: " << patron.at(i).get_name() << " Amount owing: " << patron.at(i).get_fee() << endl;
			cout << patron.at(i);
		}
	}
}


void Library::check_out() {
	//cin.exceptions(cin.exceptions() | ios_base::badbit);

	//Prompt the user to enter card number
	string card_no;
	cout << "Please enter your card no: " << endl;
	cin >> card_no;
	if (!cin)error_msg("invalid input");


	//make sure that both the user and the book are in the library
	if (!patron_available(card_no))
		throw Patron::BadPatron("Invalid card no: " + card_no, Patron::INVALID_CARD);


	//Prompt the user to enter the isbn of the book
	string isbn;
	cout << "Please enter the book isbn number" << endl;
	cin >> isbn;

	if (!book_available(isbn))
		throw Book::BadBook("invalid ISBN number: "+isbn, Book::INVALID_ISBN);

	//make sure that the user is not owing a fee
	if (patron.at(pt_no).get_fee() < 0) {
		stringstream own;
		own << "Please pay up your bills and try again. Balance: " << patron.at(pt_no).get_fee() << " Euros";
		error_msg(own.str());
	}
	
	//update the transaction
	if (book.at(bk_no).is_check_out())error_msg("Error: book aready checked out");
	book.at(bk_no).check_in_out(true);
	t.bk = book.at(bk_no);
	t.pt = patron.at(pt_no);
	t.Date = make_date();
	transaction.push_back(t);
	cout << "book checked out! Enjoy reading the book\n";
}

bool Library::book_available(string& isbn) {

	typedef vector<Book>::iterator bk_it;
	bk_no = 0;
	//loop accross the book 
	for (bk_it it = book.begin(); it != book.end(); ++it,++bk_no) {
		if (it->get_isbn() == isbn) {
			return true;
		}
		
	}
	return false;
}

bool Library::patron_available(string& cd_no) {
	typedef vector<Patron>::iterator P_it;
	pt_no = 0;
	//loop accross the book 
	for (P_it it = patron.begin(); it != patron.end(); ++it,++pt_no) {
		if (it->get_card_No() == cd_no) {
			return true;
		}
	
	}
	return false;
}

std::string Library::make_date() {
	//get the current time
	auto now = chrono::system_clock::now();
	time_t ttm = chrono::system_clock::to_time_t(now);

	//change to standard time format asuse in the computer
	char ch[27];
	 ctime_s(ch, sizeof(ch), &ttm);

	 //copy the character to string
	 string s(ch, ch + sizeof(ch));
	return s;
}

void Library::check_in() {

	//cin.exceptions(cin.exceptions() | ios_base::badbit);

//Prompt the user to enter card number
	string card_no;
	cout << "Please enter your card no: " << endl;
	cin >> card_no;
	if (!cin)error_msg("invalid input");

	//make sure that both the user and the book are in the library
	if (!patron_available(card_no))
		throw Patron::BadPatron("Invalid card no: " + card_no, Patron::INVALID_CARD);

	//Prompt the user to enter the isbn of the book
	string isb;
	cout << "Please enter the book isbn number\n";

	cin >> isb;


	if (!book_available(isb))
		throw Book::BadBook("invalid ISBN number: " + isb, Book::INVALID_ISBN);

	//update the transaction
	if (!book.at(bk_no).is_check_out())error_msg("Error: book aready checked in");
	book.at(bk_no).check_in_out(false);
	t.bk = book.at(bk_no);
	t.pt = patron.at(pt_no);
	t.Date = make_date();
	transaction.push_back(t);
	cout << "book checked in! Thanks for returning the book\n";
}

void Library::patron_bal() {
	//Prompt the user to enter card number
	string card_no;
	cout << "Please enter your card no: " << endl;

	getline(cin, card_no);
	
	//cin >> card_no;
	if (!cin)error_msg("invalid input");

	//make sure that both the user and the book are in the library
	if (!patron_available(card_no))
		throw Patron::BadPatron("Invalid card no: " + card_no, Patron::INVALID_CARD);
	cout << patron.at(pt_no);

}
void Library::initialize(int argc, char* argv[]) {

	//two file where the first contain the list of books and the second contain the list of patron
	if (argc != 3)error_msg("invalid input file arguement");

	ifstream ifs(argv[1]);
	if (!ifs)error_msg("error open the book file");

	//load the book list from file
	Book b;
	while (ifs >> b)book.push_back(b);
	if (!ifs.eof() && (ifs.fail() || ifs.bad()))error_msg("error reading from the book file");
	ifs.close();

	//load the Pathron list
	Patron p;
	ifs.open(argv[2]);
	if (!ifs)error_msg("error opening the patron file ");

	while (ifs >> p)patron.push_back(p);
	if (!ifs.eof() && (ifs.fail() || ifs.bad()))error_msg("error reading from the pathron file");

}

void Library::execute(int argc, char* argv[]) {

	//initialize the library
	initialize(argc, argv);


	cout << "---------Welcome to the Library interaction section-------" << endl;
	cout << "In this library, you can easily: " << endl;
	cout << "1. Check out the interesting book you wishes to read\n";
	cout << "2. Check in the book after usage" << endl;
	cout << "3. check how much is your balance: Please go to the info section for payment\n";
	cout << "4. For further instruction: please type 'h' followed by enter button\n";

	while (1) {
		char flag = 0;
		try {
			(cin >> flag).get();


			switch (flag) {
			case 'C': case 'c':
				check_in();
				break;
			case 'O': case 'o':
				check_out();
				break;
			case 'A': case 'a':
				patron_bal();
				break;
			case 'p': case 'P':
				break;
			case 'b': case 'B':

				break;
			case 'H': case 'h':
				instruct();
				break;
			case 'q':case 'Q':
				return;

			default:
				cerr << "invalid input detected" << endl;
			while (cin.get() != '\n')continue;
				break;
		}

		}
		catch (Patron::BadPatron& p) {
			cerr << p.what() << endl;
		}

		catch (Book::BadBook& b) {
			cerr << b.what() << endl;
		}

		catch (exception& e) {
			throw;
		}

		catch (...) {
			throw;
		}

	}
}

void Library::instruct() {
	cout << "1. Please enter 'C' button to check-in a book" << endl;
	cout << "2. Please enter 'O' button to check-out a book" << endl;
	cout << "3. To quit the program enter 'q' button" << endl;
	cout << "4. To check how much is your balance please enter 'A' button" << endl << endl;
	cout << "----Note: the next two instruction is applicable only for staff---\n";
	cout << "5. Private access: enter 'b' button to add more book to the data base\n";
	cout << "6. Private access: enter 'p' button to add more patron to the data base\n";
	cout << "-------------------------Good luck!-----------------------------------\n";
}