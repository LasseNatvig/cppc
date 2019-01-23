#include <FL/Fl.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Widget.H>
#include <FL/fl_draw.H>
#include <cmath>

class MyObject : public Fl_Widget {
public:
	MyObject(int X, int Y, int W, int H, Fl_Color c) :
		Fl_Widget(X, Y, W, H), color(c) {}

	void draw() override {							//Denne vert kalla kvar iterasjon av Fl::redraw()
		static int i = 0;
		position(400 + 150 * cos(i++ / 1000.0) - w() / 2,
			300 + 150 * sin(i / 1000.0) - h() / 2);

		fl_rectf(x(), y(), w(), h(), color);
	}

	int handle(int event) override {					//Trengs for å handtere tastaturet
		if (event == FL_KEYBOARD && Fl::event_key('f')) {//Dette gjer at fargen endrar seg når ein trykkjer på f
			color++;
		}
		if (event == FL_FOCUS || event == FL_UNFOCUS) return 1;	//For å motta tastaturtrykk, må desse to hendingene returnere 1
		return 0;
	}
private:
	Fl_Color color;
};

int main(int argc, char ** argv)
{
	Fl_Double_Window window(800, 600, "FLTK Test");
	MyObject rect(100, 100, 150, 150, FL_RED);

	window.end();
	window.show();
	while (true)
	{
		Fl::check();
		Fl::redraw();
	}
}