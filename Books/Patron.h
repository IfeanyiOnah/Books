#pragma once
#include<iostream>
#include<string>
#include<exception>

using namespace std;
class Patron
{
public:
	Patron():fee(0.0){}
	enum{INVALID_CARD=1};
	Patron(const std::string& n,const std::string& c,const double f) :name(n), card_no(c), fee(f) {}
	~Patron(){}

	//modifiable member function
	void set_name(std::string& n) { name = n; }
	void set_card_no(std::string& n) { card_no = n; }
	void set_fee(double f) { fee = f; }
	

	//non-modifiable member function
	std::string get_name() { return name; }
	std::string get_card_No() { return card_no; }
	double get_fee() { return fee; }
	bool own_fee() { return (fee ? true : false); }

	 std::string get_name() const { return name; }
	 std::string get_card_No() const { return card_no; }
	double get_fee() const { return fee; }
	bool own_fee() const { return ((fee < 0) ? true : false); }

	//friend function
	friend std::ostream& operator<<(std::ostream& os, Patron& p);

	//check if card is valid or not
	bool valid_card(string& s);


	//exception
	class BadPatron : public std::exception {
		std::string str;
	public:
		int id;
		BadPatron(const std::string& s, int d = 0):str(s),id(d){}
		~BadPatron(){}
		char const* what()const {
			return str.c_str();
		}
	};
private:
	std::string name;
	std::string card_no;
	double fee;
};

//operator to read from cin to patron class
std::istream& operator>>(std::istream& is, Patron& p);

//operator to write to cout from patron class 
std::ostream& operator<<(std::ostream& os, Patron& p);