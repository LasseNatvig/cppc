#include "APSunit.h"

int APSunit::sensorId = 0;

APSunit::APSunit(int sno, string name, string tag, Point loc, string descr) :
		unitSerialNo(sno), name(name), nameTag(tag), location(loc), description(descr) {
	myId = ++sensorId;
	display.push_back(new Rectangle{ loc, APSwidth, APSheigth });
	display[display.size() - 1].set_fill_color(Color::red);
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


ostream& operator<<(ostream& os, APSunit& unit) {
	return os << unit.get_myId() << " " << unit.get_name() << " " << unit.get_nameTag() ;
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

void updateSensors(Vector_ref<APSunit>& allSensors) {

}
