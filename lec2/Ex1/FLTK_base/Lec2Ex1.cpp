// Lec2Ex1.cpp, PPP page 415
#include "Graph.h"
#include "Simple_window.h" 

int main() {
	using namespace Graph_lib;

	cout << "Testing Vector_rev ---\n";
	Point tl{ 100, 100 };
	Simple_window win{ tl, 600, 400, "Canvas" };
	vector<int> xValues{ 34, 55, 66, 55, 88 };
	vector<int> yValues{ 55, 34, 77, 77, 88 };
	Vector_ref<Circle> circ;
	for (int i = 0; i < xValues.size(); i++) {
		 circ.push_back(new Circle{ Point{ 30 * i, 30 * i }, 20 });
		 circ[i].set_color(Color::red);
		 win.attach(circ[i]);
	}  // TODO KANSKJE er dette godt eksempel på at vi trenger indeks i og ikke bruker auto
    win.wait_for_button();
} 