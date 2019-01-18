// Example program in TDT4102_Graphics template, from PPP page 415
#include "Graph.h"
#include "Simple_window.h" 
int main() {
	using namespace Graph_lib;
	cout << "The New \"Hello, Graphical World!\" message\n";
	Point tl{ 100, 100 };
	Simple_window win{ tl, 600, 400, "Canvas" }; 

	Text t{ Point{200,200}, "Tekst uten font-problemer" };
	t.set_color(Color::dark_blue);
	t.set_font(Font::helvetica_bold);
	t.set_font_size(30);

	win.attach(t);
	win.wait_for_button();
}

