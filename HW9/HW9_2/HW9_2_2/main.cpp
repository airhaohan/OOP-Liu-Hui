#include <vector>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include "Shape.h"

using std::cin;				using std::cout;
using std::endl;			using std::vector;
using std::ifstream;		using std::ofstream;
using std::domain_error;

int main () {
	vector<Figure> shapes;
	Figure record;
	ifstream infile("shape");
	ofstream outfile("parameter");
	while (record.read(infile))
		shapes.push_back(record);
	cout << "Area\tCircumference" << endl;
	outfile << "Area\tCircumference" << endl;
	for (vector<Figure>::size_type i = 0; i != shapes.size(); ++i) {
		try {
			double area = shapes[i].area();
			double circum = shapes[i].circumference();
			cout << area << "\t" << circum << endl;
			outfile << area << "\t" << circum << endl;
		}
		catch (domain_error e) {
			cout << e.what() << endl;
			outfile << e.what() << endl;
		}
	}
	return 0;
}
