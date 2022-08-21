#pragma once
#ifndef SDDS_LIBAPP_H__
#define SDDS_LIBAPP_H__
#include"Publication.h"
#include"Book.h"
#include"Menu.h"
#include"Lib.h"
namespace sdds {
	class LibApp{
	private:
		bool m_changed;
		Menu m_mainMenu;
		Menu m_exitMenu;
		char file_name[256];
		Publication* PPA[SDDS_LIBRARY_CAPACITY];
		int NOLP;
		int LLRN;
		Menu m_pubMenu;
		bool confirm(const char* message);
		void load();  // prints: "Loading Data"<NEWLINE>
		void save();  // prints: "Saving Data"<NEWLINE>
		int search(int version); 
		void returnPub();  /*  Calls the search() method.
							   prints "Returning publication"<NEWLINE>
							   prints "Publication returned"<NEWLINE>
							   sets m_changed to true;
						   */
	public:
		LibApp(const char*);
		void newPublication();
		void removePublication();
		void checkOutPub();
		void run();
		Publication* getPub(int libRef);
		~LibApp();
	};
}
#endif // !