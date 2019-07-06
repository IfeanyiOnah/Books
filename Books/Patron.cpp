#include "exception_header.h"
#include "Patron.h"
#include <sstream>
#include <vector>
#include "Book.h"

using namespace std;


bool Patron::valid_card(string& s) 
// check for validity of a card no format n:x:n where n is integer and x is either digit or letter
{
	istringstream st(s);
	char ch1, ch2, ch3, ch4, ch5;
	st >> ch1 >> ch2 >> ch3 >> ch4 >> ch5;

	if (st.fail() || st.bad())return false;

	if(!(isalpha(ch3) || isdigit(ch3)))return false;

	if (!(isdigit(ch1) && isdigit(ch5)))return false;

	if (!(ch2 == ':' && ch4 == ':'))return false;

	return true;
}
//operator to read from cin to patron class
istream& operator>>(istream& is, Patron& p)
//read the patron info from istream in the format:
//Name = { Soheil Sotoodeh }
//ID = { 0 - s - 2019}
//Balance = { -29 }

{

	try {
		string name, cd_no, bal;

		//read name
		name = read_expression(is, "name");

		//read card number
		cd_no = read_expression(is, "id");

		//read the balance from the student
		bal = read_expression(is, "balance");

		double f = 0;

		stringstream ss(bal);
		ss >> f;

		if (is.fail() || is.bad())return is;

		if (!p.valid_card(cd_no)) {
			string s = "invalid card detected. Name: " + name + " No: " + cd_no;
			error_msg(s);
		}
		Patron tmp(name, cd_no, f);
		p = tmp;
		return is;
	}
	catch (execution_error& e) {
		is.clear(ios_base::failbit);
		cerr << e.what() << endl;
		return is;
	}
	return is;
}

//operator to write to cout from patron class 
ostream& operator<<(ostream& os, Patron& p) {

	os << "{ Name: " << p.get_name() << " Balance: " << p.get_fee() << " }\n";
	return os;
}

Patron& Patron::operator=(const Patron& b) {
	name = b.name;
	card_no = b.card_no;
	fee = b.fee;
	return *this;
}