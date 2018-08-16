// Lec1Ex3.cpp
#include "Graph.h"
#include "Simple_window.h"
using namespace Graph_lib;
int main() {
	Point tl{ 100, 100 }; // top-left corner of our window
	Point origo{ 40, 225 };
	Simple_window win(tl, 450, 250, "Lecture 1 Example 3");
	Axis xa(Axis::x, origo, 360, 12, "Month");
	win.attach(xa); // attach xa to the window, win
	xa.set_color(Color::black);
	Axis ya(Axis::y, origo, 180, 5, "Celsius");
	win.attach(ya); // attach ya
	ya.set_color(Color::black);

	// two vectors of max and min temperatures in Trondheim for year 2017
	vector<int> maxTemp{ -1, -15,  -5,  0, 5, 7, 14, 25, 28, 20, 8, 2 };
	vector<int> minTemp{ -20, -28, -10, -4, 2, 5, 11, 17, 22, 16, 5, -2 };
	Open_polyline oplMax;
	for (int i = 0; i < maxTemp.size(); i++) {
		oplMax.add(Point{ origo.x + 30 * (i + 1),
			origo.y - (90 + ((maxTemp[i] * 30) / 10)) });
	}
	oplMax.set_color(Color::red);
	win.attach(oplMax);

	Open_polyline oplMin;
	for (int i = 0; i < minTemp.size(); i++) {
		oplMin.add(Point{ origo.x + 30 * (i + 1),
			origo.y - (90 + ((minTemp[i] * 30) / 10)) });
	}
	oplMin.set_color(Color::blue);
	win.attach(oplMin);

	win.wait_for_button();

	vector<int> xValues{ 34, 55, 66, 55, 88 };
	vector<int> yValues{ 55, 34, 77, 77, 88 };

	Circle dummy{ Point{ 0, 0 }, 40 };
	dummy.set_color(Color::blue);
	win.attach(dummy);



};



