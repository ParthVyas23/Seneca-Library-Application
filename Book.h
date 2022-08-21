#ifndef SDDS_BOOK_H__
#define SDDS_BOOK_H__
#include"Publication.h"
#include <iostream>
namespace sdds {
	class Book :public Publication {
	private:
		char* auth;
	public:	
		Book();
		Book(const Book& other);
		Book& operator = (const Book& other);
		char type()const;
		ostream& write(ostream&)const;
		istream& read(istream&);
		void set(int member_id);
		operator bool()const;
		~Book();
	};
}
#endif