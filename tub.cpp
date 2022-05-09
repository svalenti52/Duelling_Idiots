//
// Created by svale on 5/7/2022.
//

/**
* tub.cpp
 *
*/

#include <vector>
#include <ranges>
#include <iostream>

const double prob_ship_find = 0.2;
const int total_nr_ships = 13;

void calc_nr_ships_prof(std::vector<double>& ships)
{
    double prob_ship_not_find = 1.0 - prob_ship_find;

    for (int ix = 0; ix < ships.size(); ++ix)
    {
        double prob_ship_not_find_temp = 1.0;
        for (int jx = 0; jx < ix; ++jx)
            prob_ship_not_find_temp *= prob_ship_not_find;
        ships[ix] = 1.0 - prob_ship_not_find_temp;
    }
}

class Prob_by_nr_ships
{
    int nr_ships;
    double probability;
public:
    explicit Prob_by_nr_ships(int ns, double prob) : nr_ships(ns), probability(prob) {}
    int get_nr_ships() const {return nr_ships;}
    friend bool operator < (Prob_by_nr_ships& lhs, Prob_by_nr_ships& rhs);
    friend std::ostream& operator << (std::ostream& o, Prob_by_nr_ships& pbns);
};

bool operator < (Prob_by_nr_ships& lhs, Prob_by_nr_ships& rhs)
{
    if (lhs.probability < rhs.probability)
        return true;
    return false;
}

std::ostream& operator << (std::ostream& o, Prob_by_nr_ships& pbns)
{
    o << pbns.probability << ' ';
    return o;
}

int main()
{
    using namespace std;

    vector<double> prob_isl_north_prof(101, 0);
    for (int ix = 0; ix <= 100; ++ix)
        prob_isl_north_prof[ix] = ix / 100.0;

    auto prob_isl_south_prof = prob_isl_north_prof;

    reverse(begin(prob_isl_south_prof), end(prob_isl_south_prof));

    vector<double> prob_by_nr_ships_prof(total_nr_ships + 1, 0);
    calc_nr_ships_prof(prob_by_nr_ships_prof);

    vector<Prob_by_nr_ships> nr_ships_send_to_isl_north;

    for (int ix = 0; ix < prob_isl_north_prof.size(); ++ix)
    {
        vector<Prob_by_nr_ships> potential_max_by_nr_ships;
        for (int nr_ships = 0; nr_ships < prob_by_nr_ships_prof.size(); ++nr_ships)
        {
            double north = prob_by_nr_ships_prof[nr_ships] * prob_isl_north_prof[ix];
            double south = prob_by_nr_ships_prof[total_nr_ships - nr_ships] * prob_isl_south_prof[ix];
            potential_max_by_nr_ships.emplace_back(Prob_by_nr_ships(nr_ships, north + south));
        }
        for (Prob_by_nr_ships p : potential_max_by_nr_ships)
            cout << p.get_nr_ships() << '-' << p << ' ';
        cout << '\n';
        auto max_ship_prob = max_element(begin(potential_max_by_nr_ships), end(potential_max_by_nr_ships));
        nr_ships_send_to_isl_north.emplace_back(max_ship_prob->get_nr_ships(), ix);
    }
    for (Prob_by_nr_ships& p : nr_ships_send_to_isl_north)
        cout << p.get_nr_ships() << ' ';
    cout << '\n';
}
