//
// Created by svale on 5/6/2022.
//

#include <random>
#include <vector>
#include <iostream>
#include <val/montecarlo/Histogram.h>

double f(double x, double y)
{
    return std::pow(x, y);
}

int main()
{
    std::default_random_engine dre(0);
    std::uniform_real_distribution<double> urd(0.0, 1.0);

    std::vector<double> f_values;
    Histogram<double, int> histogram(0.0, 1.0, 0.01);
    for (int ix = 0; ix < 100'000; ++ix)
        f_values.push_back(f(urd(dre), urd(dre)));

    for (double x : f_values)
        histogram.increment_if_in_range(x);

    std::cout << histogram;
}
