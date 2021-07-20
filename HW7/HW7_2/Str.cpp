#include "Str.h"
#include <cctype>
#include <iostream>

using std::cin;			using std::cout;
using std::istream;		using std::ostream;

std::istream& operator>> (std::istream& is, Str& s) {
	s.data.clear();
	char c;
	while (is.get(c) && isspace(c));
	if (is) {
		do {
			s.data.push_back(c);
		} while (is.get(c) && !isspace(c));
		if (is)
			is.unget();
	}
	return is;
}

std::ostream& operator<< (std::ostream& os, const Str& s) {
	for (Str::size_type i = 0; i != s.size(); ++i)
		os << s[i];
	return os;
}

Str operator+ (const Str& s1, const Str& s2) {
	Str ret = s1;
	ret += s2;
	return ret;
}
