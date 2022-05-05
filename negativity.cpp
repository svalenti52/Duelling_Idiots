//
// Created by svale on 5/5/2022.
//

#include <random>
#include <vector>
#include <iostream>

double f(double x, double y)
{
    return x / (x - y);
}

int main()
{
    std::default_random_engine dre(7);
    std::uniform_real_distribution<double> urd(0.0, 1.0);

    std::vector<double> f_values;
    for (int ix = 0; ix < 100'000; ++ix)
        f_values.push_back(f(urd(dre), urd(dre)));

    std::sort(begin(f_values), end(f_values));

    std::vector<long> bin;
    for (int ix = -3; ix < 3; ++ix)
        bin.push_back(std::count_if(std::begin(f_values), end(f_values),
                                    [ix](double x)
                                    {
                                        if (static_cast<double>(ix) <= x && static_cast<double>(ix+1) > x)
                                            return true;
                                        return false;
                                    }));

    for (long i : bin)
        std::cout << i << " ";
    std::cout << '\n';
}

