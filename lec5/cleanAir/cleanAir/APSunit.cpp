#include "APSunit.h"
#include "Graph.h"
#include "Simple_window.h" 
#include "APSunit.h"

APSunit::APSunit(Point loc, string name) : location(loc), name(name) {
	display.push_back(new Rectangle{ loc, APSwidth, APSheigth });
	display[display.size() - 1].set_fill_color(Color::red);
	// display.push_back(new Text{ Point{loc.x + 50, loc.y + 50}, name });
	display.push_back(new Text{ loc, name });
	display[display.size() - 1].set_color(Color::blue);

};

// do not need conditional compilation here since a Simple_window is also a Graph_lib::Window
void APSunit::attach(Graph_lib::Window & win) {
		for (int i = 0; i < display.size(); i++) {
			win.attach(display[i]);
	}
}

void readSensors(Vector_ref<APSunit>& allSensors, const string sensorsFileName) {
	ifstream sensFile;
	sensFile.open(sensorsFileName);
	if (sensFile.fail()) {
		throw exception("Error opening file!");
	}
	else { // Declare variables as local as possible
		string name, tla; // tla means Three Letter Abbreviation (TBF in Norwegian)
		int id, xCoord, yCoord;
		string description;
		sensFile >> id;
		while (id > 0) { // id == 0 terminates loop
			sensFile >> name >> tla >> xCoord >> yCoord;
			getline(sensFile, description); // assure skip to end of line
			cout << tla << " " << description << endl; 
			// id not used yet
			allSensors.push_back(new APSunit(Point{ xCoord, yCoord }, name));
			sensFile >> id;
		}
	}
}