// Lec1Ex3.cpp
#include "Graph.h"
#include "Simple_window.h"
using namespace Graph_lib;
int main() {
	Point tl{ 100, 100 }; // tl is Top-Left corner of our window
	Point origo{ 40, 255 };
	Simple_window win(tl, 400, 300, "Lecture 1 Example 3");
	Axis xa(Axis::x, origo, 330, 11, "Month (August 2017 .. July 2018)");
	win.attach(xa); // attach xa to the window, win
	xa.set_color(Color::black);
	Axis ya(Axis::y, origo, 210, 7, "Celsius (-5 .. +25)");
	win.attach(ya); // attach ya
	ya.set_color(Color::black);

	// two vectors of max and min temperatures in Trondheim for august 2017 to july 2018
	vector<int> maxTemp{ 17, 16, 9, 3, 1, 0, 0, 1, 9, 19, 15, 23 };
	vector<int> minTemp{ 10, 9, 5, -2, -3, -4, -6, -6, 1, 8, 8, 13 };

	const int span = 35;
	const int yAxisLength = 210;

	Open_polyline oplMax;  // Magic numbers here are bad practice, FIX
	for (int i = 0; i < maxTemp.size(); i++) {
		const int span = 35;
		const int yAxisLength = 210;
		oplMax.add(Point{ origo.x + 30 * i,
			origo.y - (yAxisLength * ((maxTemp[i] - (-10)))/span) });
}
	oplMax.set_color(Color::red);
	win.attach(oplMax);

	Open_polyline oplMin;
	for (int i = 0; i < minTemp.size(); i++) {
		oplMin.add(Point{ origo.x + 30 * i,
			origo.y - (yAxisLength * ((minTemp[i] - (-10))) / span) });
	}
	oplMin.set_color(Color::blue);
	win.attach(oplMin);

	win.wait_for_button();
};