#include "Employee.h"													// Defines class Employee
#include "Book.h"
#include "Map.h"														// Defines template Map<Key, Value>
#include "KeyDoesNotExistException.h"														
#include <iostream>

using namespace std;

typedef unsigned int ID; 												// Identification number of employee
typedef Map<ID, Employee> Database; 									// Database of employees

typedef string Title;
typedef Map<Title, Book> BookDatabase;

void testEmployees();
void addEmployees(Database& database);
void modifyEmployees(Database& database);

void testBookDatabase();
void addBooks(BookDatabase& database);
void modifyBookDatabase(BookDatabase& database);

int main() {
	testEmployees();
	testBookDatabase();
}

void testEmployees(){
	Database database;
	addEmployees(database);
	cout << "Original database:" << endl << database << endl;

	Database newDatabase = database;									// Make a copy of database
	newDatabase.add(830505432, Employee("Ewa Nowak", "charwoman", 43));	// Add fourth employee
	modifyEmployees(newDatabase);

	cout << "Modified database:" << endl << newDatabase << endl;

	database = newDatabase;												// Update original database

	cout << "Database after the assignment:" << endl << database << endl;
}

void addEmployees(Database& database) {
	database.add(761028073, Employee("Jan Kowalski", "salesman", 28)); 	// Add first employee: name: Jan Kowalski, position: salseman, age: 28,
	database.add(510212881, Employee("Adam Nowak", "storekeeper", 54));	// Add second employee
	database.add(730505129, Employee("Anna Zaradna", "secretary", 32));	// Add third employee
	database.add(761028073, Employee("Ebenezer Scrooge", "accountant", 60)); // Adding data with the same key as the first employee
}

void modifyEmployees(Database& database) {
	Employee* employeePtr;

	employeePtr = database.find(510212881);								// Find employee using its ID
	employeePtr->position = "salesman";									// Modify the position of employee
	
	employeePtr = database.find(761028073);								// Find employee using its ID
	employeePtr->age = 29;												// Modify the age of employee
	try{
		employeePtr = database.find(761028777);
		employeePtr->age = 7;
	}
	catch(keyDoesNotExistException& noKey){
		cout << noKey.what() << endl;
	}
}

void testBookDatabase(){
	BookDatabase database;
	addBooks(database);
	cout << "Original database:" << endl << database << endl;

	BookDatabase newDatabase = database;
	newDatabase.add("Humans: A Brief History Of How We F*cked It All Up", Book("Tom Phillips", "History", 272, borrowed));
	modifyBookDatabase(newDatabase);

	cout << "Modified database:" << endl << newDatabase << endl;

	database = newDatabase;

	cout << "Database after the assignment:" << endl << database << endl;
}

void addBooks(BookDatabase& database){
	database.add("Good Omens: The Nice And Accurate Prophecies Of Agnes Nutter, Witch", Book("Terry Pratchet", "Fiction", 491, onTheShelf));
	database.add("Taming Demons For Beginners", Book("Annette Marie", "Fiction", 315, onTheShelf));
	database.add("Symposium", Book("Plato", "Philosophy", 109, borrowed));
	database.add("And Then There Were None", Book("Agatha Christie", "Crime", 264, onTheShelf));
}

void modifyBookDatabase(BookDatabase& database){
	Book* libPtr;

	libPtr = database.find("Symposium");
	libPtr->currentStatus = onTheShelf;

	libPtr = database.find("And Then There Were None");
	libPtr->currentStatus = borrowed;

	try{
		libPtr = database.find("Good Omens");
		libPtr->currentStatus = borrowed;
	}
	catch(keyDoesNotExistException& noKey){
		cout << noKey.what() << endl;
	}
}
