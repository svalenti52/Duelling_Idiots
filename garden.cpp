//
// Created by svale on 5/9/2022.
//

/**
* garden.cpp
 *
*/

#include <iostream>
#include <random>
#include <cmath>
#include <val/montecarlo/Histogram.h>



int main()
{
    using namespace std;
    Histogram<double, int> histogram(0.0, 1.5, 0.05);
    default_random_engine dre(0);
    uniform_real_distribution<double> urd(0.0, 1.0);
    uniform_real_distribution<double> urd_pi(0.0, numbers::pi);

    auto rand_len{[](double x, double ang)
        {
            if (ang <= atan(1/(1 - x)))
                return (1 - x) / cos(ang);
            else if (ang <= numbers::pi - atan(1 / x))
                return 1 / sin(ang);
            else
                return -x / cos(ang);
        }};

    vector<double> len_line;
    for (int ix = 0; ix < 100'000; ++ix)
    {
        len_line.emplace_back(rand_len(urd(dre), urd_pi(dre)));
    }

    for (double x : len_line)
        histogram.increment_if_in_range(x);

    cout << histogram;

    vector<int> cdf_line_len;

    for (int ix = 0; ix < histogram.size(); ++ix) {
        int partial_sum = 0;
        for (int jx = 0; jx <= ix; ++jx)
            partial_sum += histogram.get_amount(jx);
        cdf_line_len.emplace_back(partial_sum);
    }

    for (int ix : cdf_line_len)
        cout << ix << ' ';
    cout << '\n';
}
