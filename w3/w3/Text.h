#pragma once

#include <iostream>
#include <fstream>
#include <string>
using namespace std;


namespace w3{
	class Text {
		size_t count = 0 ;
		string* dataTable = nullptr;

	public:
		Text::Text();
		Text(char* filename);
		~Text();
		Text(const Text& rhs);
		Text& operator=(const Text& rhs);
		Text(Text&& rhs);
		Text& operator=(Text&& rhs);

		size_t size() const;
	};
}