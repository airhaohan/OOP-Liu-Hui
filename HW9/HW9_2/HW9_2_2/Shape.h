#ifndef GUARD_Shape_h
#define GUARD_Shape_h

#include <iostream>
#include <stdexcept>

class Shape {
	friend class Figure;
	public:
		virtual double circumference() const = 0;
		virtual double area() const = 0;
		virtual std::istream& read(std::istream&) = 0;
	protected:
		virtual Shape* clone () = 0;
};

class Triangle : public Shape {
	public:
		Triangle(std::istream& is) { read(is); }
		double circumference() const;
		double area() const;
		std::istream& read(std::istream&);
		
	protected:
		virtual Triangle* clone () { return new Triangle(*this); } 
		
	private:
		double a, b, c;
};

class Rectangle : public Shape {
	public:
		Rectangle(std::istream& is) { read(is); }
		double circumference() const;
		double area() const;
		std::istream& read(std::istream&);
		
	protected:
		virtual Rectangle* clone () { return new Rectangle(*this); } 
		
	private:
		double lenth, width;
};

class Circle : public Shape {
	public:
		Circle(std::istream& is) { read(is); }
		double circumference() const;
		double area() const;
		std::istream& read(std::istream&);
		
	protected:
		virtual Circle* clone () { return new Circle(*this); } 
		
	private:
		double radius;
};

class Figure {
	public:
		Figure() : s(0) { }
		Figure(std::istream& is) : s(0) { read(is); }
		Figure (const Figure&);
		Figure& operator=(const Figure&); 
		~Figure() { delete s; }
		double circumference() const {
			if (s)
				return s->circumference();
			else
				throw std::runtime_error ("uninitialized shape");
		}
		double area() const {
			if (s)
				return s->area();
			else
				throw std::runtime_error ("uninitialized shape");
		}
		std::istream& read(std::istream&);
		
	private:
		Shape* s;
};

#endif
#pragma once

