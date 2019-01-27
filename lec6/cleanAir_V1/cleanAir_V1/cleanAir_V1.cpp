// cleanAir_V1 (Several files)
#include "Graph.h"
#include "Simple_window.h" 

#include "APSunit.h"

int main() try {
	setlocale(LC_ALL, "norwegian");
	cout << "cleanAir bruker C++ for et bedre miljø!\n\n";
	Point topLeft{ 200, 100 };
	Simple_window win{ topLeft, winWidth, winHeigth, cityWinTitle };
	cout << "... laster bykart\n";
	Image cityMap{ Point{0,0}, cityFileName };
	win.attach(cityMap);
	keep_window_open(); // debug

	Vector_ref<APSunit> allSensors;
	cout << "... leser inn sensorer\n";
	readSensors(allSensors, sensorsFileName);
	for (int i = 0; i < allSensors.size(); i++) {
		allSensors[i].attach(win);
	}
	keep_window_open(); // debug

	cout << "... simulerer siste døgn\n";
	for (int hour = 0; hour < 24; hour++) {
		Text time{ Point{200, 200}, "Time: " + to_string(hour) + ":00h" };
		time.set_color(Color::dark_red);
		time.set_font(Font::helvetica_bold);
		time.set_font_size(30);
		win.attach(time);
		win.wait_for_button();
	}
}
catch (exception& e) {
	cerr << e.what();
	keep_window_open();
}