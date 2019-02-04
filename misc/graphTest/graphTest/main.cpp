// Example program in TDT4102_Graphics template, from PPP page 415
//#include "Graph.h"
//#include "Simple_window.h" 
//
//usng namespace Graph_lib;

struct Point {
	// a Point is simply a pair of ints (the coordinates)
	int x, y;
	Point(int xx, int yy) : x(xx), y(yy) { }
};

struct Shape {
	// hold lines represented as pairs of points
	// knows how to display lines
	void add(Point p) {};
};

struct Line : Shape {
	// a Line is a Shape defined by just two Points
	Line(Point p1, Point p2);
};
Line::Line(Point p1, Point p2) {
	// construct a line from p1 to p2
	add(p1); // add p1 to this shape (add() is provided by Shape)
	add(p2); // add p2 to this shape
}

struct Lines : Shape {	// a Lines object is a set of lines
		// We use Lines when we want to manipulate
		// all the lines as one shape, e.g. move them all
		// together with one move statement
	void add(Point p1, Point p2); // add line from p1 to p2
	void draw_lines() const; // to be called by Window to draw Lines
};

void Lines::add(Point p1, Point p2) {}

void Lines::draw_lines() const{}



int main() {
	Shape s;
}
