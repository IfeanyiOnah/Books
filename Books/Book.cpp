#include "Book.h"
#include <sstream>
#include"exception_header.h"

using namespace std;

void Book::check_in_out(bool f) {
	chk_t = f; // make check out true
}


bool Book::isbn_valid(std::string isbn) {
	istringstream s(isbn);
	// the isbn format [n - n - n - x]
	char ch1, ch2, ch3,ch4,ch5,ch6,ch7;

	s >> ch1 >> ch2 >> ch3 >> ch4 >> ch5 >> ch6 >> ch7;

	if (!(isdigit(ch1) && isdigit(ch3) && isdigit(ch5))) return false;
	
	if (!(isalpha(ch7) || isdigit(ch7)))return false;

	if (!(ch2 != '-' && ch4 != '-' && ch6 != '-')) return false;

	return true;

}

bool operator==(Book& a, Book& b) {

	return (a.get_isbn() == b.get_isbn());
}

bool operator!=(Book& a, Book& b) {

	return !(a.get_isbn() == b.get_isbn());
}

std::ostream& operator<<(std::ostream& os, Book& b) {

	os << "Author: " << b.get_author() << "\n\nISBN: " << b.get_isbn() << endl;
	return os;
}

Book::Genre to_genre(const string& s) {
	if (s == "fiction")return Book::FICTION;

	if (s == "science")return Book::SCIENCE;

	if (s == "children")return Book::CHILDREN;

	if (s == "biography")return Book::BIOGRAPHY;

	string ss = "Invalid genre detected: " + s;
	throw Book::BadBook(ss, Book::INVALID_GEN);
	return Book::SCIENCE;
}

std::string read_expression(istream& is, const string& s) 
//this function read sub expression at each line of the file 
// it compare the starting name with giving constant name s before reading
// Otherwise it will return error when failed
{
	string tmp;
	char ch1, ch2;
	is.exceptions(is.exceptions() | ios_base::badbit);
	while (is >> ch1 && ch1 != '=')tmp += tolower(ch1);

	if (is.eof()) {
		return "";
	}
	
	if (is.fail() || is.bad() || ch1 != '=') {
		error_msg("error reading from file with search name: ", s);
	}

	is >> ch2;
	if (ch2 != '{') {
		error_msg("error! expected: '{'  at read_expression() with search name: ", s);
	}
		


	if (tmp == s) { //check if the giving is same as the read value
		tmp = "";
		while (is.get(ch2) && ch2 != '}' && ch2 != '\n') {
			tmp += ch2;
		}
	}
	else {
		tmp = "'" + tmp + "'" +  "read. expected '" + s + "'  at read_expression()";
		error_msg(tmp);
	}

	if (ch2 != '}') {
		error_msg("error! expected: '}'  at read_expression() with search name: ", s);
	}

	return tmp;

}
std::istream& operator>>(std::istream& is, Book& b) 
//read the book info from istream in the format:
//Author = { Soheil Sotoodeh }
//title = { Outlier detection in laser scanner point clouds }
//ISBN = { 0 - 0 - 1 - s }
//Genre = { science }
{
	string tit, aut, isb;
	string gen;
	try {

		is.exceptions(is.exceptions() | ios_base::badbit);
		//get auhot
		tit = read_expression(is, "author");

		//get title
		aut = read_expression(is, "title");

		//get isbn
		isb = read_expression(is, "isbn");

		//get genre
		gen = read_expression(is, "genre");

		if (is.fail())return is;


		if (b.isbn_valid(isb)) {
			string s = "invalid ISBN number: " + isb + " Title: " + tit;
			throw Book::BadBook(s, Book::INVALID_ISBN);
		}
		Book tmp(tit, aut, isb, to_genre(gen));
		b = tmp;
		return is;
	}
	catch (execution_error& e) {
		cerr << e.what() << endl;
		is.clear(ios_base::failbit);
		return is;
		
	}
	return is;
}