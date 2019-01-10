// APSunit.h
#pragma once
#include "Graph.h"
#include "Simple_window.h" 
#include "APSunit.h"

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
	APSunit(Vector_ref<Shape> & plot, Point loc, string name) : location(loc), name(name) {
		plot.push_back(new Rectangle{ loc, APSwidth, APSheigth });
		plot[plot.size() - 1].set_fill_color(Color::red);
	};
	void attach(Simple_window & win);
};