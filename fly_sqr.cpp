//
// Created by svale on 5/9/2022.
//

/**
* fly_sqr.cpp
*/

#include <iostream>
#include <random>

class Point
{
    double x;
    double y;
public:
    Point(double ix, double iy) : x(ix), y(iy) {}
    friend double distance(Point& lhs, Point& rhs);
};

double distance(Point& lhs, Point& rhs)
{
    using namespace std;
    double sqr_dist = pow(lhs.x-rhs.x, 2) + pow(lhs.y-rhs.y, 2);
    return sqrt(sqr_dist);
}

int main()
{
    using namespace std;
    default_random_engine dre(0);
    uniform_real_distribution<double> urd(0.0, 1.0);

    const int nr_events = 10'000'000;

    double fav_event_count = 0;

    for (int ix = 0; ix < nr_events; ++ix) {
        Point point1(urd(dre), urd(dre));
        Point point2(urd(dre), urd(dre));
        if (distance(point1, point2) > 1.0)
            fav_event_count += 1.0;
    }

    cout << "Probability more 1 apart = " << fav_event_count / nr_events;
}
