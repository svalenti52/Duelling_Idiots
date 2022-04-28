//
// Created by svale on 4/24/2022.
//

/** \file bbseason.cpp
 * \brief Calculate the ratio of expected wins for halfway vs a complete season
 * for a given probability of winning a single game.

*/

#include <iostream>
#include <vector>
#include <boost/math/special_functions/binomial.hpp>
#include <numeric>
#include <ranges>
#include <algorithm>

using u64 = uint64_t;
using namespace boost::math;

//===============================================

double expected_value(u64 n, double p)
{
    return n * p;
}

//===============================================

double binomial_sum_greater_than(u64 n, u64 k, double p)
{
    double binomial_sum = 0.0;

    for (u64 kx = k; kx <= n; ++kx)
    {
        auto bin_coeff = binomial_coefficient<double>(n, kx);
        binomial_sum = binomial_sum + bin_coeff * pow(p, kx) * pow((1.0-p), n-kx);
    }

    return binomial_sum;
}

//===============================================
//===============================================

int main()
{
    std::vector<double> v(100, 0.0);
    std::iota(v.begin(), v.end(), 1.0);

    std::vector<double> N_100, D_100, R_100;


    std::vector<double> vec_100(100, 0.0);
    std::iota(vec_100.begin(), vec_100.end(), 1.0);

    auto frac_100 = vec_100 | std::views::transform([](double x){return x / 100.0; });
    auto num = frac_100 | std::views::transform([](double x) {return std::ceil(expected_value(81, x));});
    auto den = frac_100 | std::views::transform([](double x) {return std::ceil(expected_value(162, x));});

    for (u64 ix = 0; ix < v.size(); ++ix)
        N_100.push_back(binomial_sum_greater_than(81, num[ix], (ix + 1) / 100.0));
    for (u64 ix = 0; ix < v.size(); ++ix)
        D_100.push_back(binomial_sum_greater_than(162, den[ix], (ix + 1) / 100.0));
    for (u64 ix = 0; ix < N_100.size(); ++ix)
        R_100.push_back(N_100[ix] / D_100[ix]);

    for (double x : R_100)
        std::cout << x << ' ';
}
