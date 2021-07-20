#ifndef GUARD_Shape_h
#define GUARD_Shape_h

#include <iostream>

class Shape {
	public:
		virtual double circumference() const = 0;
		virtual double area() const = 0;
		virtual ~Shape() { }
		virtual std::istream& read(std::istream&) = 0;
};

class Triangle : public Shape {
	public:
		double circumference() const;
		double area() const;
		std::istream& read(std::istream&);
		
	private:
		double a, b, c;
};

class Rectangle : public Shape {
	public:
		double circumference() const;
		double area() const;
		std::istream& read(std::istream&);
	private:
		double lenth, width;
};

class Circle : public Shape {
	public:
		double circumference() const;
		double area() const;
		std::istream& read(std::istream&);
	private:
		double radius;
};


#endif
#pragma once

