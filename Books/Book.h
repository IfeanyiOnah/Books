#pragma once
#include<iostream>
#include<string>
#include<exception>
class Book
{
public:

	enum Genre { FICTION, NONFICTION, PERIODICAL,BIOGRAPHY,CHILDREN,SCIENCE };
	enum{INVALID_GEN, INVALID_ISBN};
	Book(){}

	/*Book(const Book& b)
		:title(b.title),author(b.author),isbn(b.isbn),genre(b.genre),chk_t(b.chk_t){}*/

	Book(std::string& t,std::string& a,std::string& i, int g,bool ch = 0)
		:title(t),author(a),isbn(i),genre(g),chk_t(ch){}


	~Book(){}

	//modifiable function
	void set_title(std::string& s) { title = s; }
	void set_author(std::string& s) { author = s; }
	void set_isbn(std::string& s) { isbn = s; }

	//function to check in the book
	void check_in_out(bool f);


	//non-modifiable function
	std::string get_title() { return title; }
	std::string get_author() { return author; }
	std::string get_isbn() { return isbn; }

	//return true is book is available
	bool is_check_out() { return chk_t; }

	//function to check out the book
	 std::string get_title() const { return title; }
	 std::string get_author() const { return author; }
	 std::string get_isbn() const { return isbn; }
	 bool is_check_out() const { return chk_t; }

	bool isbn_valid(std::string isbn);

	class BadBook : public std::exception {
		std::string str;
	public:
		int id;
		BadBook(const std::string& s, int i):str(s),id(i){}
		virtual const char* what()const { return str.c_str(); }
	};
private:


	//private data member
	std::string title;
	std::string author;
	std::string isbn;
	int genre;
	bool chk_t;
};

//helper function for the book library
// operator for comparing two books
bool operator==(Book& a, Book& b);

bool operator!=(Book& a, Book& b);

std::istream& operator>>(std::istream& os, Book& b);

std::ostream& operator<<(std::ostream& os, Book& b);

std::string read_expression(std::istream& is, const std::string& s);