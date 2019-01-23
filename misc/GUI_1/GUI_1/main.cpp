// Example program GUI_1.cpp, simple GUI elements  - commented
#include "GUI.h"
#include "Graph.h"
using namespace Graph_lib;

struct MyWindow : Window {
	MyWindow(Point topLeft, int w, int h, const string& title);
private:
	Button start_button;
	Button quit_button;
	string name;  // Stores title of window. TODO is stored somewhere inside, but how to get access to it?
	Menu colorMenu; // Menu from GUI.h is a collection of buttons

	static void cb_start(Address, Address); // callback for start_button
	static void cb_quit(Address, Address); // callback for quit_button
	static void cb_red(Address, Address); // callback for red_button
	static void cb_blue(Address, Address); // callback for blue_button
	static void cb_green(Address, Address); // callback for green_button

	void start(); // action to be done when start_button is pressed, defined below
	void quit() { cout << name + ": quit called\n"; } // action to be done when quit_button is pressed, placed inline

	void red_pressed() { cout << name + ": red pressed\n"; };
	void blue_pressed() { cout << name + ": blue pressed\n"; };
	void green_pressed() { cout << name + ": green pressed\n"; };
};

MyWindow::MyWindow(Point topLeft, int w, int h, const string& title) : Window{ topLeft, w, h, title }, 
	start_button{ Point{10, 10}, 70, 20, "Start", cb_start },
	quit_button{ Point{x_max() - 80, 10}, 70, 20, "Quit", cb_quit }, 
	name(title), 
	colorMenu{ Point{x_max() - 80, 40}, 70, 20, Menu::vertical, "color" } {

	attach(start_button);
	attach(quit_button);
	colorMenu.attach(new Button{ Point{0, 0}, 0, 0, "red", cb_red });
	colorMenu.attach(new Button{ Point{0, 0}, 0, 0, "blue", cb_blue });
	colorMenu.attach(new Button{ Point{0, 0}, 0, 0, "green", cb_green });
	attach(colorMenu);
}
void MyWindow::start() { 
cout << name + ": start called\n";
	// Opprett meny her, som logger i text vindu, med end-valg, eet objekt?
}
void MyWindow::cb_start(Address, Address pw) { reference_to<MyWindow>(pw).start(); }
void MyWindow::cb_quit(Address, Address pw) { reference_to<MyWindow>(pw).quit(); }
void MyWindow::cb_red(Address, Address pw) { reference_to<MyWindow>(pw).red_pressed(); }
void MyWindow::cb_blue(Address, Address pw) { reference_to<MyWindow>(pw).blue_pressed(); }
void MyWindow::cb_green(Address, Address pw) { reference_to<MyWindow>(pw).green_pressed(); }

int main() {
	MyWindow win1{ Point{550, 80}, 300, 400, "MyWindow 1" };
	MyWindow win2{ Point{1000, 80}, 400, 300, "MyWindow 2" };
	return gui_main();
}