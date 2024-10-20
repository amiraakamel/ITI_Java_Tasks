
#include<iostream>
using namespace std;

class Point {
private :
	int x;
	int y;
public:
	Point() {
		x = 0;
		y = 0;
	}
	Point(int a, int b) {
		x = a;
		y = b;
		cout << "cons-->Point" << endl;
	}
	~Point() {
		cout << "destructor-->Point" << endl;
	}
	void setX(int x) {
		x = x;
	}
	void setY(int y) {
		y = y;
	}
	int getX() {
		return x;
	}
	int getY() {
		return y;
	}
	void draw() {
		cout << "Point" << endl;
	}
};
class Line {
private:
	Point start;
	Point end;

public:
	Line() :start(), end() {

	}
	Line(int x, int y, int a, int b):start(x,y),end(a,b){
		cout << "cons__>Line" << endl;
	}
	~Line() {
		cout << "destructor --> Line" << endl;
	}
	void draw() {
		cout << "Start Point" << endl;
		start.draw();
		cout << "end Point" << endl;
		end.draw();
		cout << "draw Line" << endl;

	}
};
class Rect {

private:
	Line l1;
	Line l2;
public:
	Rect() :l1(), l2() {

	}
	Rect(int a, int b, int x, int y) :l1(a,b,x,y), l2(a,b,x,y) {
		cout<<"cons-->rect" << endl;
	}
	~Rect() {
		cout << "destructor--> rect" << endl;
	}
	void draw() {
		cout << " line1" << endl;
		l1.draw();
		cout << " line2" << endl;
		l2.draw();
		cout << "draw rect" << endl;

	}
};

class Pic {
private:
	int numRect;
	int numLine;
	Line* l1;
	Rect* r1;
public:
	Pic() {
		numRect = 0;
		numLine = 0;
		l1 = NULL;
		r1 = NULL;
	}

	Pic(int rn, int ln, Rect* r1, Line* l1) {
		numRect = rn;
		numLine = ln;
		l1 = l1;
		r1 = r1;
		cout << "Pic cons" << endl;
	}
	~Pic() {
		cout << "desrtructor -->Pic" << endl;
	}
	void draw() {
		int i;
		for (i = 0; i < numRect; i++) {
			r1[i].draw();
		}
		for (i = 0; i < numLine; i++) {
			l1[i].draw();
		}
		cout << "pic draw" << endl;
	}

};




int main() {


	Line l1(1, 2, 3, 4);

	cout << "_________________________________________________________________" << endl;

	Rect r1(2, 3, 4, 5);
	cout << "_________________________________________________________________" << endl;

	Rect* rect = new Rect(1, 2, 3, 4);
	Line* line = new Line(1, 3, 4, 5);

    Pic p1(1, 1, rect, line);
    cout << "_________________________________________________________________" << endl;


//cout << "_________________________________________________________________" << endl;

	//delete rect;
	//delete line;


    p1.draw();

	return 0;
}








