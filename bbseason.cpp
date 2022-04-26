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

double expected_value(u64 n, double p)
{
    return n * p;
}

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

int main()
{
    std::vector<double> v(100, 0.0);
    std::iota(v.begin(), v.end(), 1.0);

    std::vector<double> numerator, denominator;
    std::ranges::transform(v.begin(), v.end(), v.begin(), [](double x) {return x / 100.0;});
    std::ranges::transform(v, std::back_inserter(numerator), [](double x)
        {return std::ceil(expected_value(81, x));});
    std::ranges::transform(v, std::back_inserter(denominator), [](double x)
        {return std::ceil(expected_value(162, x));});

    std::vector<double> N, D;

    for (u64 ix = 0; ix < v.size(); ++ix)
        N.push_back(binomial_sum_greater_than(81, numerator[ix], (ix+1)/100.0));
    for (u64 ix = 0; ix < v.size(); ++ix)
        D.push_back(binomial_sum_greater_than(162, denominator[ix], (ix+1)/100.0));

    std::vector<double> R;
    for (u64 ix = 0; ix < N.size(); ++ix)
        R.push_back(N[ix] / D[ix]);
/*
    auto numerator = v
            | std::views::transform([](double x){return x / 100.0; })
            | std::views::filter([](double x) {return x != 0.0;})
            | std::views::transform([](double x) {return expected_value(81, x);})
            | std::views::transform([](double x) {return std::ceil(x);});
*/

/*
    auto denominator = v
                     | std::views::transform([](double x){return x / 100.0; })
                     | std::views::filter([](double x) {return x != 0.0;})
                     | std::views::transform([](double x) {return expected_value(162, x);})
                     | std::views::transform([](double x) {return std::ceil(x);});
*/

//    std::vector<double> num, den;
//    for (u64 ix = 0; ix < w.size(); ++ix) {
//        num.push_back(binomial_sum_greater_than(81, numerator[ix], probability_single));
//        den.push_back(binomial_sum_greater_than(162, denominator[ix], probability_single));
//    }
    //auto numerator_bc81 = numerator | std::views::transform([](u64 d) {return binomial_sum_greater_than(81, )})
    for (double x : R)
        std::cout << x << ' ';
}
