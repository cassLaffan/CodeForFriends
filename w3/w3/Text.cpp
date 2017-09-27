#include "Text.h"

using namespace w3;

namespace w3 {
	Text::Text() {
		
	}

	Text::Text(char* filename) {

		// open file
		fstream in(filename, std::ios::in);			
		
		if (in.is_open()) {

			// count the number of lines in the file
			std::string line;
			while (getline(in, line)) {
				count++;
			}

			// allocate a table to hold the data
			dataTable = new string[count];
			
			// read the data
			in.clear();  //clear the end-of-file (EOF) error state
			in.seekp(0); // go back to beginning of file
			for (size_t i = 0; i < count; i++) {
				getline(in, dataTable[i]);
			}

			// close the file
			in.close();
		} 
		else {
			std::cerr << "Cannot Open file '" << filename << "' \n";
			exit(99);
		}
	}
	Text::~Text() {
		delete[] dataTable;
	}

	Text::Text(const Text& rhs) {				//cpy constructor
		*this = rhs;
	}
	Text& Text::operator=(const Text& rhs){		//cpy assignment operator
		if (this != &rhs) {
			delete[] dataTable;
			dataTable = nullptr;
			count = 0;
			if (rhs.dataTable) {
				count = rhs.count;
				dataTable = new string[count];
				memcpy(dataTable, rhs.dataTable, count * sizeof(string));
			}
		}
		return *this;
	}
	Text::Text(Text&& rhs){					// move constructor
		*this = std::move(rhs);
	}
	Text& Text::operator=(Text&& rhs) {		// move assignment operator
		if (this != &rhs) {
			delete[] dataTable;
			dataTable = rhs.dataTable;
			count = rhs.count;
			rhs.dataTable = nullptr;
			rhs.count = 0;
		}
		return *this;
	}

	size_t Text::size() const {
		return count;
	}

}
