// APSunit.h
#pragma once
#include "Graph.h"
#include "Simple_window.h" 
#include "APSunit.h"

const string cityFileName = "Trondheim.jpg"; 
constexpr int winWidth = 1310;  // is set wide enough to have the next button outside this actual city map
constexpr int winHeigth = 900;
const string cityWinTitle = "Apparatur for måling av luftkvalitet i Trondheim, en gave fra TDT4102 til Bartebyen, våren 2019.";

const string sensorsFileName = "clean_air_trondheim.txt";
constexpr int APSwidth = 60; // APS is short for Air Pollution Sensor
constexpr int APSheigth = 20;

class APSunit {
	// These are private by default (in class), but you can also use keyword private
	unsigned int ozone = 0;
	unsigned int particulateMatter = 0;
	unsigned int carbonMonoxide = 0;
	unsigned int sulfurDioxide = 0;
	unsigned int nitrousOxide = 0;
	Point location;
	string name;
public:
	APSunit() {};
	APSunit(Point loc, string name);
	string getName() { return name; };
	void attach(Graph_lib::Window & win);  // works for both versions of cleanAir
	Vector_ref<Shape> display;  // TODO-ask-LE: error message when this variable was private: fltk fl_line_style(): could not create GDI pen object
};

void readSensors(Vector_ref<APSunit>& allSensors, const string sensorsFileName);