# Books
 This program is design to be a part of software for easy access to the library

The class Book has a members such as ISBN, title, author, and genre for each book

It also has other interface function for operating on the Book class 

 It read the book from file/cin and write expected output to cout

 The library users (Patron) can easily check in or check out a book

 The patron can also check his or her balance

 The ISBN is in the format: [n-n-n-x] where n is integer and x is a digit or letter

 The patron ID is in the format: [n-x-n] where n is integer and x is a digit or letter

//-----------The library is designed as follows:-----------------------------//


Main: 
	Class Library

Class Library:
	Class Book
	Class Patron
	Struct Transaction
	Check_in()
	Check_out()
	Check_balance()
	Add_book()
	Add_patron()
	Execution()


Class Book:
	operator<< (write to cout: Author and ISBN)
	operator>>(read from file )
	check_in_out (function to check the book in or out)


operator>>:
	Author
	Title
	ISBN
	Genre
	check (when true the book is checked out)
	
ISBN:
	format: n-n-n-x
	(where n is integer and x is a digit or letter)

Class Patron:
	operator<< (write to cout: Name and Balance owing )
	operator>>(read from file )

operator>>:
	Name
	Card ID
	Balance
	
Card ID:
	format: n-x-n
	(where n is integer and x is a digit or letter)

Struct Transaction:
	Class Book
	Class Patron
	Date
	(where transaction shows the name and the date a patron check in or out a book)

Check_in():
	Card ID
	ISBN

Check_out():
	Card ID
	ISBN

Execution:
	
	'c' to Check in
	'o' to Check out
	'q' to Quit
	'h' for help Help
	'a' to Check balance
	'b' to Add book
	'p' to Add patron

Check_balance():
	Card ID

Add_book():
	Author
	Title
	ISBN
	Genre

Add_patron():
	Name
	Card ID
	