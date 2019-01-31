#include "APSunit.h"

int APSunit::sensorId = 0;

APSstate int_to_APSstate(int n) {
	if ((n < static_cast<int>(APSstate::unknown)) ||
		(n > static_cast<int>(APSstate::flaky))) {
			error("Illegal parameter passed to int_to_APSstate, returns state unknown");
			return APSstate::unknown;
	}
	else {
		return APSstate(n);
	}
}

APSunit::APSunit(int sno, string name, string tag, Point loc, string descr) :
	unitSerialNo{ sno }, name{ name }, nameTag{ tag }, location{ loc }, description{ descr } {
	myId = ++sensorId;
	display.push_back(new Rectangle{ loc, APSwidth, APSheigth });
	display[display.size() - 1].set_fill_color(colorMap.at(state));
	display.push_back(new Text{ loc, name });
	display[display.size() - 1].set_color(Color::blue);
	static_cast<Text&>(display[display.size() - 1]).set_font_size(20); // downcasting using static_cast
};

void APSunit::attach(Graph_lib::Window & win) {
	for (int i = 0; i < display.size(); i++) {
		win.attach(display[i]);
	}
}

bool APSunit::set_description(const string s) {
	if (s.length() > maxDescriptionLength) {
		return false;
	}
	description = s;
	cout << "APS sensor " << myId << " " + name << " got new description:\n" << s;
	return true;
}

void APSunit::set_state(const APSstate s) { 
	state = s; // NOTE, the following is unsafe programming. We assume that the first shape added to display in the constructor is the rectangle
	display[0].set_fill_color(colorMap.at(s));
}

ostream& operator<<(ostream& os, APSunit& unit) {
	return os << unit.get_myId() << " " << unit.get_name() << " "
		<< unit.get_nameTag() << " " << textColorMap.at(unit.get_state());  
			// .at is safer than [ ] since it is rangechecked
}

void initSensors(Vector_ref<APSunit>& allSensors, const string sensorsFileName) {
	ifstream sensFile{ sensorsFileName };
	if (sensFile.fail()) throw exception("Error opening file!");
	else { // Declare variables as local as possible
		string name; // the short name
		string tla; // nameTag. tla means Three Letter Abbreviation (TBF in Norwegian)
		int sno = 0; // serial number read from file, 0 terminates reading
		int xCoord = 0;
		int yCoord = 0;
		string description;
		sensFile >> sno;
		while (sno > 0) { // sno == 0 terminates loop
			sensFile >> name >> tla >> xCoord >> yCoord;
			getline(sensFile, description);
			allSensors.push_back(new APSunit{ sno, name, tla, 
									Point{ xCoord, yCoord }, description});
			cout << "APS sensor loaded: " << allSensors[allSensors.size() - 1] << endl;

			sensFile >> sno; // for next sensor
		}
	}
}

APSstate magicReadState() { // simulates reading data an determination of state
	return static_cast<APSstate>( rand() % ((static_cast<int>(APSstate::flaky) - 
										     static_cast<int>(APSstate::unknown)) + 1));
}

void updateSensors(Vector_ref<APSunit>& allSensors) {
	for (int i = 0; i < allSensors.size(); i ++) {
		APSstate s = magicReadState();
		allSensors[i].set_state(s);
		cout << allSensors[i] << endl; // debug 
	}
}

