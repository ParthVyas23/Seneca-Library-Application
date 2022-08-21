#include <iostream>
using namespace std;
#include "Utils.h"
namespace sdds {
	unsigned int getIntInRange(int min, int max) {
		int i;
		cin >> i;
		if (cin.fail() || i<min || i>max) {
			cin.clear();
			char ch;
			while (cin.get(ch) && ch != '\n') {
				;//flushing keyboard
			}
			cout << "Invalid Selection, try again: ";
			return getIntInRange(min, max);
		}
		else {
			return i;
		}
	}


}