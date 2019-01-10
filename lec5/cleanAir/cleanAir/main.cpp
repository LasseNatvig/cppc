// cleanAir idea - kladd 
#include "Graph.h"
#include "Simple_window.h" 
#include "APSunit.h"

// målesensor som sammensatt grafikk-object, bruk arv og vectorsom i bil-tegne-eksempel

constexpr int winWidth = 1200;
constexpr int winHeigth = 900;

int main() try {
	using namespace Graph_lib;
	setlocale(LC_ALL, "norwegian");
	cout << "cleanAir - utprøving\n";

	Point tl{ 100, 50 };
	Simple_window win{ tl, winWidth, winHeigth, "Apparatur for måling av luftkvalitet i Trondheim, en gave fra TDT4102 til Bartebyen, våren 2019." };
	Image trondheim{ Point{0,0}, "Trondheim.jpg" };
	
	// Blir helt ny struktur nå ... la readSensors lese fil og opprette vector av sensorer ...
	Vector_ref<Shape> allSensors;

	ifstream sensors;
	sensors.open("clean_air_trondheim.txt");
	if (sensors.fail()) {
		throw exception("Error opening file!");
	}
	// Lese disse fra fil, ha kode for navn, som i rapport oversettes via map fra kort-navn til langt navn
	// skrive kode navnet inne i boksen, kan jeg ha noe som arver fra shape og har flere komponenter?
	APSunit sens1{ allSensors, Point{400, 400}, "Samfundet" };
	APSunit sens2{ allSensors, Point{600, 300}, "Pirbadet" };
	APSunit sens3{ allSensors, Point{800, 700}, "Marinen" };

	win.attach(trondheim);


	for (int i = 0; i < allSensors.size(); i++)
		win.attach(allSensors[i]);
	win.wait_for_button();

}
catch (exception& e) {
	cerr << e.what();
	keep_window_open();
}

