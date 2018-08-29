// Lec2Ex1.cpp, PPP page 415
#include "Graph.h"
#include "Simple_window.h" 
int main() {
	using namespace Graph_lib;
	cout << "The New \"Hello, Graphi*************** cal World!\" message\n";
	Point tl{ 100, 100 };
	Simple_window win{ tl, 600, 400, "Canvas" };

	// ***** TESTE FJERNES

	vector<int> xValues{ 34, 55, 66, 55, 88 };
	vector<int> yValues{ 55, 34, 77, 77, 88 };

	vector<Circle*> circles;
	for (int i = 0; i < xValues.size(); i++) {
		Circle* c = new Circle{ Point{ xValues[i], yValues[i] }, 20 };
		c->set_color(Color::red);
		circles.push_back(c);
		win.attach(*circles[i]);
	}
	win.wait_for_button();

	// TODO -- som over, men prøv å unngå new og peker senere 
	vector<Circle> circ;
	for (int i = 0; i < xValues.size(); i++) {
	 // Circle c(); // Cannot be used, see error, missing default constructor, MS-VS error C2280
	 // SPØR LASSE EGGEN om dette
	 //
	 Circle c{ Point{ 3 * i,3 * i },4 };
	 c.set_color(Color::red);
	 circ.push_back(c);
	}
	for (int i = 0; i < xValues.size(); i++) {
		circ[i] = Circle{ Point{ xValues[i], yValues[i] }, 2 };
		win.attach(circ[i]);
	}
    win.wait_for_button();
} 