// Lec2Ex1.cpp, PPP page 415
#include "Graph.h"
#include "Simple_window.h" 
int main() {
	using namespace Graph_lib;
	cout << "The New \"Hello, Graphi*************** cal World!\" message\n";
	Point tl{ 100, 100 };
	Simple_window win{ tl, 600, 400, "Canvas" };

	Polygon poly;
	poly.add(Point{ 30, 200 });
	poly.add(Point{ 35, 100 });
	poly.add(Point{ 40, 200 });
	poly.set_color(Color::green);

	win.attach(poly);
    win.wait_for_button();
} 