/*
 * main.cpp
 *
 *  Created on: 13 марта 2015 г.
 *      Author: pavel
 */

#include <iostream>
#include <stdexcept>
#include <fstream>
#include <tuple>
#include <cmath>

using namespace std;

const double EPS = 1e-3;

class Point {
public:
    double x, y;

    double radius(const Point& p) const {
        return sqrt((p.y - y) * (p.y - y) + (p.x - x) * (p.x - x));
    }

    Point normal(const Point& p) const {
        double r = radius(p);
        return {(p.y - y)/r, (p.x - x)/r};
    }

    double dot(const Point& p) const {
        return x * p.x + y * p.y;
    }

    friend ostream& operator<<(ostream& out, const Point& r) {
        return out << "(" << r.x << "; " << r.y << ")";
    }

    friend istream& operator>>(istream& in, Point& r) {
        return in >> r.x >> r.y;
    }
};

class Segment {
public:
    Point s, e;

    bool checkPoint(const Point& point) const {
        return s.normal(e).dot(s.normal(point)) > (1 - EPS) && s.radius(point) < s.radius(e);
    }

    tuple<bool, Point> intersect(const Segment& r) const {
        double Kx =
            ((r.e.x - r.s.x)*(s.y - r.s.y) - (r.e.y - r.s.y)*(s.x - r.s.x)) /
            ((r.e.y - r.s.y)*(e.x -   s.x) - (r.e.x - r.s.x)*(e.y -   s.y));

        double Ky =
            ((  e.x -   s.x)*(s.y - r.s.y) - (  e.y -   s.y)*(s.x - r.s.x)) /
            ((r.e.y - r.s.y)*(e.x -   s.x) - (r.e.x - r.s.x)*(e.y -   s.y));

        Point intersection { s.x + Kx * (e.x - s.x), s.y + Ky * (e.y - s.y) };

        return make_tuple(checkPoint(intersection) && r.checkPoint(intersection), intersection);
    }

    friend ostream& operator<<(ostream& out, const Segment& r) {
        return out << "(" << r.s << "; " << r.e << ")";
    }
    friend istream& operator>>(istream& in, Segment& r) {
        return in >> r.s >> r.e;
    }
};

int main(int argc, char **argv) {
    try {

        if (argc < 2)
            throw invalid_argument("not input file");

        ifstream file(argv [ 1 ]);

        Segment AB, CD;

        while (file >> AB >> CD) {
            cout << "AB " << AB << endl;
            cout << "CD " << CD << endl;

            auto intersection = AB.intersect(CD);

            if (get<0>(intersection)) {
                cout << "intersection " << get<1>(intersection) << endl;
            } else {
                cout << "no intersection" << endl;
            }
        }

    } catch (exception const& e) {
        cerr << e.what() << endl;
    }
}
