#define _CRT_SECURE_NO_WARNINGS
#include"Book.h"
#include<iostream>
#include<iomanip>
#include<string.h>
using namespace std;
namespace sdds {
	Book::Book():Publication(){
		auth = nullptr;
	}
	Book::Book(const Book& other):Publication(other) {
		auth = nullptr;
		if (other.auth != nullptr) {
			auth = new char[strlen(other.auth)+1];
			strcpy(auth, other.auth);
		}
	}
	Book& Book::operator=(const Book& other)
	{
		this->Publication::operator=(other);
		if (auth != nullptr)
			delete[] auth;
		auth = nullptr;
		if (other.auth != nullptr) {
			auth = new char[strlen(other.auth)+1];
			strcpy(auth, other.auth);
		}
		return *this;
	}
	char Book::type() const
	{
		return 'B';
	}
	ostream& Book::write(ostream& os) const
	{
		Publication::write(os);
		if (conIO(os)) {
			os << " ";
			string str = auth;
			if (strlen(auth) > SDDS_AUTHOR_WIDTH) {
				os << str.substr(0, SDDS_AUTHOR_WIDTH);
			}
			else {
				os <<left << setw(SDDS_AUTHOR_WIDTH) << auth;
			}
			os<< " |";
		}
		else {
			os << "\t" << auth;
		}
		return os;
	}
	istream& Book::read(istream& is)
	{
		Publication::read(is);
		if (auth != nullptr)
			delete[] auth;
		auth = nullptr;
		char author[257];
		if (conIO(is)) {
			is.ignore();
			cout << "Author: ";
			is.getline(author,250);
		}
		else {
			is.ignore();
			is.get(author,250,'\n');
		}

		if (!is.fail()) {
			auth = new char[strlen(author)+1];
			strcpy(auth, author);
		}
		return is;
	}
	void Book::set(int member_id)
	{
		Publication::set(member_id);
		resetDate();
	}
	Book::operator bool() const
	{
		return (this->Publication::operator bool()  && auth !=nullptr );
	}
	Book::~Book()
	{
		if(auth!=nullptr) {
			delete[] auth;
		}
	}
}