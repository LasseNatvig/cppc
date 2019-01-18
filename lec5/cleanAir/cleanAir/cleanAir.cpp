// cleanAir.cpp V1
#include "Graph.h"
#include "Simple_window.h" 
using namespace Graph_lib;

// if SIMPLE_WIN is defined we use Simple_window and the next button for each time-step (here one hour)
// #define SIMPLE_WIN 
// if SIMPLE_WIN is NOT defined we use Window from Graph_lib that does not have the nex-button

//-----------------------------------------------
// from https://stackoverflow.com/questions/4184468/sleep-for-milliseconds
// C++11 standard, should not be dependant on OS
#include <chrono>
#include <thread>
void sleep(int ms) {
	this_thread::sleep_for(chrono::milliseconds(ms));
}
#include "APSunit.h"

int main() try {
	setlocale(LC_ALL, "norwegian");
	cout << "cleanAir bruker C++ for et bedre miljø!\n";

	Point topLeft{ 200,100 };
#ifdef SIMPLE_WIN
	Simple_window win{topLeft, winWidth, winHeigth, cityWinTitle};
#else
	Graph_lib::Window win{topLeft, winWidth-70, winHeigth, cityWinTitle}; // Note size of next-button is hardcoded to 70 in Graph_lib
#endif

	Image cityMap{Point{0,0}, cityFileName};
	win.attach(cityMap);

	Vector_ref<APSunit> allSensors;
	readSensors(allSensors, sensorsFileName);
	for (int i = 0; i < allSensors.size(); i++) {
		allSensors[i].attach(win);
	}

	for (int hour = 0; hour < 24; hour++) {
		Text time{ Point{200, 200}, "Time: " + to_string(hour) + ":00h" };
		time.set_color(Color::dark_red);
		time.set_font(Font::helvetica_bold);
		time.set_font_size(30);
		win.attach(time);
#ifdef SIMPLE_WIN
		win.wait_for_button();
#else
		sleep(1000);
		Fl::wait();
		Fl::redraw();
#endif
	}

}
catch (exception& e) {
	cerr << e.what();
	keep_window_open();
}