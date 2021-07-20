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
	vector<Shape*> shapes;
	Shape* record;
	char ch;
	ifstream infile("shape");
	ofstream outfile("parameter");
	while (infile >> ch) {
		if (ch == 'T')
			record = new Triangle;
		else if (ch == 'R')
			record = new Rectangle;
		else
			record = new Circle;
		record->read(infile);
		shapes.push_back(record);
	}
	cout << "Area\tCircumference" << endl;
	outfile << "Area\tCircumference" << endl;
	for (vector<Shape*>::size_type i = 0; i != shapes.size(); ++i) {
		try {
			double area = shapes[i]->area();
			double circum = shapes[i]->circumference();
			cout << area << "\t" << circum << endl;
			outfile << area << "\t" << circum << endl;
		}
		catch (domain_error e) {
			cout << e.what() << endl;
			outfile << e.what() << endl;
		}
		delete shapes[i];
	}
	return 0;
}
