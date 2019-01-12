// APSunit.h
#pragma once
#include "Graph.h"
#include "Simple_window.h" 
#include "APSunit.h"

constexpr int APSwidth = 60; // APS is short for Air Pollution Sensor
constexpr int APSheigth = 20;
const string cityFileName = "Trondheim.jpg";
const string cityWinTitle = "Apparatur for måling av luftkvalitet i Trondheim, en gave fra TDT4102 til Bartebyen, våren 2019.";
const string sensorsFileName = "clean_air_trondheim.txt";

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
	void attach(Simple_window & win);
	Vector_ref<Shape> display;  // error message when this message was private: fltk fl_line_style(): could not create GDI pen object
};

void readSensors(Vector_ref<APSunit>& allSensors, const string sensorsFileName);