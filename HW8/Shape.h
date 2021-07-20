#ifndef GUARD_Shape_h
#define GUARD_Shape_h

#include <iostream>

class Shape {
	public:
		double circumference() const;
		double area() const;
};

class Triangle : public Shape {
	friend std::istream& operator>> (std::istream&, Triangle&);
	public:
		double circumference() const;
		double area() const;
		
	private:
		double a, b, c;
};

class Rectangle : public Shape {
	friend std::istream& operator>> (std::istream&, Rectangle&);
	public:
		double circumference() const;
		double area() const;
		
	private:
		double lenth, width;
};

class Circle : public Shape {
	friend std::istream& operator>> (std::istream&, Circle&);
	public:
		double circumference() const;
		double area() const;
		
	private:
		double radius;
};


#endif
#pragma once

