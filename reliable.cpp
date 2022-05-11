//
// Created by svale on 5/11/2022.
//

/**
* reliable.cpp
 *
*/

#include <iostream>
#include <vector>
#include <cmath>

int main()
{
    using namespace std;
    double a = 1.0 / 100.0;
    const int selected_time {69}; // approximate median T for value of a
    vector<double> single_system;
    vector<double> triple_system;

    for (int t = 0; t < 200; ++t) {
        double single_system_calc = 1 - exp(-a * t);
        single_system.emplace_back(single_system_calc);
        triple_system.emplace_back(single_system_calc * single_system_calc * (3.0 - 2.0 * single_system_calc));
    }

    cout << "Single System\n";
    for (double x : single_system)
        cout << x << ' ';
    cout << '\n' << single_system[selected_time] << "\n\n";

    cout << "Triple System\n";
    for (double x : triple_system)
        cout << x << ' ';
    cout  << '\n' << triple_system[selected_time] << '\n';
}
