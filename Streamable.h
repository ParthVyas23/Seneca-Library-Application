#ifndef SDDS_STREAMABLE_H_
#define SDDS_STREAMABLE_H_
#include<iostream>
using namespace std;
namespace sdds {
	class Streamable{
	public:
		virtual ostream& write(ostream&)const=0;
		virtual istream& read(istream&) = 0;
		virtual bool conIO(ios&)const = 0;
		virtual operator bool()const = 0;
		~Streamable(){};
	};


}
#endif