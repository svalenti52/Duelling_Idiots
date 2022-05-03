//
// Created by svale on 5/3/2022.
//

#include <iostream>
#include <vector>
#include <numeric>
#include <random>

int main()
{
    std::default_random_engine dre(0);
    std::uniform_real_distribution<double> urd(0.0, 1.0);
    const int nr_trials = 100'000;

    std::vector<double> no_ends;
    std::vector<double> one_end;
    std::vector<double> two_ends;

    std::vector<int> i(100, 0);
    std::iota(std::begin(i), std::end(i), 1);
    std::vector<double> needle_length;
    for (int xx : i)
        needle_length.push_back(xx/100.0);

    for (double nl : needle_length)
    {
        int nr_no_end = 0;
        int nr_one_end = 0;
        int nr_two_end = 0;

        for (int ix = 0; ix < nr_trials; ++ix)
        {
            double x = urd(dre);
            double y = urd(dre);

            while (x * x + y * y >= 1.0)
            {
                x = urd(dre);
                y = urd(dre);
            }

            if ((x+nl) * (x+nl) + y * y < 1.0)
                ++nr_no_end;
            else if ((x-nl) * (x-nl) + y * y >= 1.0)
                ++nr_two_end;
            else
                ++nr_one_end;
        }

        no_ends.push_back(static_cast<double>(nr_no_end)/nr_trials);
        one_end.push_back(static_cast<double>(nr_one_end)/nr_trials);
        two_ends.push_back(static_cast<double>(nr_two_end)/nr_trials);
    }

    for (double x : no_ends)
        std::cout << x << ' ';
    std::cout << '\n';
    for (double x : one_end)
        std::cout << x << ' ';
    std::cout << '\n';
    for (double x : two_ends)
        std::cout << x << ' ';
    std::cout << '\n';
}
