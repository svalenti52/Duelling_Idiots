//
// Created by svale on 4/29/2022.
//

#include <random>
#include <iostream>
#include <algorithm>
#include <val/montecarlo/Chronology.h>

int main(int argc, char* argv[])
{
    long seed = 0;
    if ( argc == 2 ) seed = std::strtol(argv[1], nullptr, 10);
    const int nr_bins = 1'000'000;

    std::default_random_engine dre(seed);
    std::uniform_int_distribution<int> rand_index(0, nr_bins-1);
    std::vector<int> vec_int(nr_bins, 0);

    StopWatch stopWatch;

    for (int int_val : vec_int)
    {
        int sel_int = rand_index(dre);
        ++vec_int[sel_int];
    }

    int nr_zeroes = static_cast<int>(std::count(vec_int.begin(), vec_int.end(), 0));

    std::cout << "nr of zeroes = " << nr_zeroes << '\n';

    std::cout << "estimate for e is = " <<
              static_cast<double>(nr_bins) /
              static_cast<double>(nr_zeroes) <<
              '\n';

    stopWatch.stop();
}
