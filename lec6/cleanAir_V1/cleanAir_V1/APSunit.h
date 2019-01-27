// APSunit.h
#pragma once
#include "Graph.h"
#include "Simple_window.h" 

// The following constants will be placed in a config-file in a later version of cleanAir
const string cityFileName = "Trondheim.jpg";
constexpr int winWidth = 1310;  // is set wide enough to have the next button outside this actual city map
constexpr int winHeigth = 900;  // two lines below shows how adjacent string literals are concatenated by the compiler 
const string cityWinTitle = "Apparatur for måling av luftkvalitet i Trondheim"
                            ", en gave fra TDT4102 til Bartebyen, våren 2019.";
const string sensorsFileName = "clean_air_trondheim.txt";
constexpr int APSwidth = 70; // APS is short for Air Pollution Sensor
constexpr int APSheigth = 50;

class APSunit {
	// These are private by default (in class), but you can also use keyword private
	unsigned int ozone = 0;  // the five most common components measured by APS units according to https://en.wikipedia.org/wiki/Air_pollution_sensor
	unsigned int particulateMatter = 0; // we assume thay can all be measured as a positive integer
	unsigned int carbonMonoxide = 0;
	unsigned int sulfurDioxide = 0;
	unsigned int nitrousOxide = 0;
	Point location; // The location as coordinates on the city map, can be updated
	string name; // Name of APS unit display on map, cannot be changed
	string description; // Description of where to find the actual sensor when your are close to the location, can be updated
	string nameTag; // Short three letter name, cannot be changed
	int myId; // An unique serial number assigned to the sensors during initialization, cannot be changed
	Vector_ref<Shape> display; 
public:
	APSunit(Point loc, string name); // TODO - revise see READ_SENSOR ***************************************************
	static int sensorId;  // must be initialized in main program since it is static (shared for all objects)
	string getName() { return name; }; // TODO -- ADD MORE functions ************************************************************** 
	void attach(Graph_lib::Window & win);  // to make the sensor visible
};

void readSensors(Vector_ref<APSunit>& allSensors, const string sensorsFileName);