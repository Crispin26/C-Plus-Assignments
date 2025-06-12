#include <iostream>
using namespace std;


class Point {
public:
    int x, y;

    Point(int x = 0, int y = 0) : x(x), y(y) {}
    Point(const Point& p) : x(p.x), y(p.y) {}
};


class Circle {
public:
    Point center;
    int radius;

    Circle(Point center = Point(), int radius = 0) : center(center), radius(radius) {}
    Circle(const Circle& c) : center(c.center), radius(c.radius) {}
};

class Rect {
public:
    Point topLeft, bottomRight;

    Rect(Point tl = Point(), Point br = Point()) : topLeft(tl), bottomRight(br) {}
    Rect(const Rect& r) : topLeft(r.topLeft), bottomRight(r.bottomRight) {}
};


class Line {
public:
    Point start, end;

    Line(Point s = Point(), Point e = Point()) : start(s), end(e) {}
    Line(const Line& l) : start(l.start), end(l.end) {}
};


class Picture {
private:
    Circle* circles;
    Rect* rects;
    Line* lines;
    int cNum, rNum, lNum;

public:
    // OuR Default constructor
    Picture() : circles(nullptr), rects(nullptr), lines(nullptr), cNum(0), rNum(0), lNum(0) {}

    // THE Parameterzed constructor
    Picture(Circle* c, Rect* r, Line* l, int circleCount, int rectCount, int lineCount)
        : circles(new Circle[circleCount]), rects(new Rect[rectCount]), lines(new Line[lineCount]),
          cNum(circleCount), rNum(rectCount), lNum(lineCount) {

        for (int i = 0; i < cNum; i++) circles[i] = c[i];
        for (int i = 0; i < rNum; i++) rects[i] = r[i];
        for (int i = 0; i < lNum; i++) lines[i] = l[i];
    }

    // Copy constructor
    Picture(const Picture& p)
        : circles(new Circle[p.cNum]), rects(new Rect[p.rNum]), lines(new Line[p.lNum]),
          cNum(p.cNum), rNum(p.rNum), lNum(p.lNum) {

        for (int i = 0; i < cNum; i++) circles[i] = p.circles[i];
        for (int i = 0; i < rNum; i++) rects[i] = p.rects[i];
        for (int i = 0; i < lNum; i++) lines[i] = p.lines[i];
    }

    // Copy assignment operator
    Picture& operator=(const Picture& p) {
        if (this == &p) return *this;

        delete[] circles;
        delete[] rects;
        delete[] lines;

        cNum = p.cNum;
        rNum = p.rNum;
        lNum = p.lNum;

        circles = new Circle[cNum];
        rects = new Rect[rNum];
        lines = new Line[lNum];

        for (int i = 0; i < cNum; i++) circles[i] = p.circles[i];
        for (int i = 0; i < rNum; i++) rects[i] = p.rects[i];
        for (int i = 0; i < lNum; i++) lines[i] = p.lines[i];

        return *this;
    }

    // OUR Destructor
    ~Picture() {
        delete[] circles;
        delete[] rects;
        delete[] lines;
    }

    // Paint method
    void Paint() {
        cout << "Painting Picture with " << cNum << " Circles, "
             << rNum << " Rects, " << lNum << " Lines.\n";
    }
};


int main() {
    // Create sample shapes
    Circle c(Point(5, 5), 10);
    Rect r(Point(0, 0), Point(10, 10));
    Line l(Point(1, 1), Point(7, 7));

    //  We create our arrays of shapes
    Circle circles[] = {c};
    Rect rects[] = {r};
    Line lines[] = {l};

    // And then we create our  Picture object
    Picture pic1(circles, rects, lines, 1, 1, 1);
    pic1.Paint();

    // Test copy constructor
    Picture pic2 = pic1;
    pic2.Paint();

    // Test copy assignment
    Picture pic3;
    pic3 = pic1;
    pic3.Paint();

    return 0;
}
