// cleanAir.cpp V1
#include "Graph.h"
#include "Simple_window.h" 
using namespace Graph_lib;

#include "APSunit.h"
constexpr int winWidth = 1310;
constexpr int winHeigth = 900;

int main() try {
	setlocale(LC_ALL, "norwegian");
	cout << "cleanAir bruker C++ for et bedre miljø!\n";

	Simple_window win{Point{100,50}, winWidth, winHeigth, cityWinTitle};
	Image cityMap{Point{0,0}, cityFileName};
	win.attach(cityMap);
	Vector_ref<APSunit> allSensors;
	readSensors(allSensors, sensorsFileName);

	for (int hour = 0; hour < 24; hour++) {

		for (int i = 0; i < allSensors.size(); i++) {
			// prøv flytt litt, prøv endre farge
			// skriv en overskrift ute i havet med klokkeslett
			// prøv eget vindu ekstra med tekstrapport // evt- i senere eksempel
			allSensors[i].attach(win);
		}
		win.wait_for_button();
	}
}
catch (exception& e) {
	cerr << e.what();
	keep_window_open();
}