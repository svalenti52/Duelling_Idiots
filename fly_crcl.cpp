//
// Created by svale on 5/9/2022.
//

/**
* fly_crcl.cpp
 *
*/

#include <iostream>
#include <random>

struct Point
{
    double x;
    double y;
public:
    Point(double ix, double iy) : x(ix), y(iy) {}
    double distance_from_origin() {return sqrt(std::pow(x, 2) + std::pow(y, 2));}
    friend double distance(Point& lhs, Point& rhs);
};

double distance(Point& lhs, Point& rhs)
{
    using namespace std;
    double sqr_dist = pow(lhs.x-rhs.x, 2) + pow(lhs.y-rhs.y, 2);
    double dist = sqrt(sqr_dist);
    // cout << "dist=" << dist << ";\n";
    return dist;
}

std::ostream& operator << (std::ostream& o, Point& p)
{
    o << "x=" << p.x << " y=" << p.y << "; ";
    return o;
}

int main()
{
    using namespace std;
    default_random_engine dre(7);
    uniform_real_distribution<double> urd_rad(0.0, 1.0/ sqrt(numbers::pi));
    uniform_real_distribution<double> urd_ang(0.0, 2.0*numbers::pi);

    const int nr_events = 100000;

    double fav_event_count = 0;

    for (int ix = 0; ix < nr_events; ++ix) {
        double p1_rad = urd_rad(dre); double p1_ang = urd_ang(dre);
        double p2_rad = urd_rad(dre); double p2_ang = urd_ang(dre);
        // double p1_rad = sqrt(urd_rad(dre)); double p1_ang = urd_ang(dre);
        // double p2_rad = sqrt(urd_rad(dre)); double p2_ang = urd_ang(dre);
        // cout << p1_rad << " " << p1_ang << '\n';
        Point point1(p1_rad*cos(p1_ang), p1_rad*sin(p1_ang));
        Point point2(p2_rad*cos(p2_ang), p2_rad*sin(p2_ang));
        // cout << point1 << "  " << point2;
        if (distance(point1, point2) > 1.0)
            fav_event_count += 1.0;
    }
    // cout << "inverse sqrt of pi = " << 1/sqrt(numbers::pi) << '\n';
    cout << "Probability more than 1 apart = " << fav_event_count / nr_events;
}
