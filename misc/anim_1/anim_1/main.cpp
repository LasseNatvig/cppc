// Example program in TDT4102_Graphics template, anim_1.cpp
#include <FL/Fl_Window.H>
#include "Graph.h" 
// #include "Graph_lib.h"
using namespace Graph_lib;
//---------------------------------------------------------
#include <chrono> // Portable sleep-function
#include <thread>
void sleep(int ms) { this_thread::sleep_for(chrono::milliseconds(ms)); }
//---------------------------------------------------------
int main() {
	Fl_Window win{ 100, 100, 500, 500, "Minimalistic animation demo" };
	int x = 200;
	int y = 200;
	win.show();
	for (int i = 0; i < 1000; i++) {
		x += (-4 + (rand() % 9));
		y += (-4 + (rand() % 9));
		Rectangle box{ Point{x, y}, 300, 300 };
		box.set_fill_color(Color::dark_red);
		box.draw();
		// win.attach(box);  // Error	C2039	'attach': is not a member of 'Fl_Double_Window'	

		sleep(10);
		Fl::wait();
		Fl::redraw();
	}
}