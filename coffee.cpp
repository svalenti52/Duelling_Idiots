//
// Created by svale on 5/2/2022.
//

#include <random>
#include <val/montecarlo/MonteCarloSim_beta.h>

using DistInt = Distribution<int, int, std::uniform_int_distribution>;

int main()
{
    const int nr_events = 6;

    DistInt distribution(0, 1, nr_events);

    auto condition_met = [](DistInt& distInt, int& y, DRE& dre)
    {
        y = 1.0;
        while (std::count(distInt.events.begin(), distInt.events.end(), 0) != 1 &&
            std::count(distInt.events.begin(), distInt.events.end(), 1) != 1)
        {
            ++y;
            distInt.reload_random_values(dre);
        }
        return true;
    };

    MonteCarloSimulation<int, int, int, std::uniform_int_distribution>
            monteCarloSimulation(
            10'000'000,
            1,
            condition_met,
            distribution
    );

    monteCarloSimulation.run();

    monteCarloSimulation.change_message("Number of flip events required = ");

    monteCarloSimulation.print_result();
}
