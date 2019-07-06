#pragma once
#include<iostream>
#include<string>

using namespace std;
class Patron
{
public:
	Patron():fee(0.0),name(""),card_no(""){}
	Patron(const Patron& p) :name(p.name),card_no(p.card_no),fee(p.fee){}
	Patron(const std::string& n,const std::string& c,const double f) :name(n), card_no(c), fee(f) {}
	Patron& operator=(const Patron& b);
	~Patron(){}

	//modifiable member function
	void set_name(std::string& n) { name = n; }
	void set_card_no(std::string& n) { card_no = n; }
	void set_fee(double f) { fee = f; }
	

	//non-modifiable member function
	std::string& get_name() { return name; }
	std::string& get_card_No() { return card_no; }
	double get_fee() { return fee; }
	bool own_fee() { return (fee ? true : false); }

	const std::string& get_name() const { return name; }
	const std::string& get_card_No() const { return card_no; }
	double get_fee() const { return fee; }
	bool own_fee() const { return ((fee < 0) ? true : false); }


	//check if card is valid or not
	bool valid_card(string& s);

private:
	std::string name;
	std::string card_no;
	double fee;
};

//operator to read from cin to patron class
std::istream& operator>>(std::istream& is, Patron& p);

//operator to write to cout from patron class 
std::ostream& operator<<(std::ostream& os, Patron& p);