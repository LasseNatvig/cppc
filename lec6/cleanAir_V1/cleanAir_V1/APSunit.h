// APSunit.h
#pragma once
#include "Graph.h"
#include "Simple_window.h" 

// The following constants will be placed in a config-file in a later version of cleanAir
const string cityFileName = "Trondheim.jpg";
constexpr int winWidth = 1310;  // is set wide enough to have the next button outside this actual city map
constexpr int winHeigth = 900;  // two lines below shows how adjacent string literals are concatenated by the compiler 
const string cityWinTitle = "Apparatur for m�ling av luftkvalitet i Trondheim"
                            ", en gave fra TDT4102 til Bartebyen, v�ren 2019.";
const string sensorsFileName = "clean_air_trondheim.txt";
constexpr int APSwidth = 70; // APS is short for Air Pollution Sensor
constexpr int APSheigth = 50;
constexpr int maxDescriptionLength = 60; // maximum allowed length of description

enum class APSstate {unknown = 0, planned, calibration, 
				booting, ok, warning, bad, malfunc, flaky};
	// Note, unknown must be first in enum, and flake last, see function APSstate_to_int()

const map<APSstate, Color> colorMap{ // defines the colors showing state
	{APSstate::unknown, Color::white},
	{APSstate::planned, Color::white},
	{APSstate::calibration, Color::light_gray},
	{APSstate::booting, Color::mid_gray},
	{APSstate::ok, Color::green},	
	{APSstate::warning, Color::yellow},	
	{APSstate::bad, Color::red},
	{APSstate::malfunc, Color::black},
	{APSstate::flaky, Color::cyan},
};

// Using this map is not smart, changing the color in one entry here and not in coloMap,
// or vice versa, can cause inconsistent tables. Using colorTextMap (below) is safe
//const map<APSstate, string> textColorMap{
//	{APSstate::unknown, "white"},
//	{APSstate::planned, "white"},
//	{APSstate::calibration, "light_gray"},
//	{APSstate::booting, "mid_gray"},
//	{APSstate::ok, "green"},
//	{APSstate::warning, "yellow"},
//	{APSstate::bad, "red"},
//	{APSstate::malfunc, "black"},
//	{APSstate::flaky, "cyan"},
//};

// A disadvantage of this table is that a new color in colorMap above must be
// followed by an update of this table. However it is possible to check for such an 
// erroneous condition by code (See MARK-A)
const map<Color, string>textColorMap{
	{Color::white, "white"},
	{Color::light_gray, "light_gray"},
	{Color::mid_gray,"mid_gray"},
	{Color::green, "green"},
	{Color::yellow, "yellow"},
	{Color::red, "red"},
	{Color::black, "black"},
	{Color::cyan, "cyan"},
};

class APSunit {
	// These are private by default (in class), but you can also use keyword private
	APSstate state = APSstate::unknown;
	unsigned int ozone = 0;  // the five most common components measured by APS units according to https://en.wikipedia.org/wiki/Air_pollution_sensor
	unsigned int particulateMatter = 0; // we assume thay can all be measured as a positive integer
	unsigned int carbonMonoxide = 0;
	unsigned int sulfurDioxide = 0;
	unsigned int nitrousOxide = 0;
	Point location; // The location as coordinates on the city map, can be updated
	string name; // Name of APS unit display on map, cannot be changed
	string description; // Description of where to find the actual sensor when your are close to the location, can be updated via set_description();
	string nameTag; // Short three letter name, cannot be changed
	int unitSerialNo; // serial number for the given unit, cannot be changed
	int myId; // An unique serial number assigned to the sensors during initialization, cannot be changed
	Vector_ref<Shape> display; 
public:
	APSunit(int sno, string name, string tag, Point loc, string descr);
	static int sensorId;  // must be initialized as global variable since it is static (shared for all objects)
	APSstate get_state() const { return state; };
	string get_name() const { return name; };
	string get_nameTag() const { return nameTag; };
	int get_myId() const { return myId; };
	bool set_description(const string s); // updates the description, returns false if argument is too long.
	void set_state(const APSstate s);
	void attach(Graph_lib::Window & win);  // to make the sensor visible
};

void initSensors(Vector_ref<APSunit>& allSensors, const string sensorsFileName);
APSstate magicReadState();
void updateSensors(Vector_ref<APSunit>& allSensors);