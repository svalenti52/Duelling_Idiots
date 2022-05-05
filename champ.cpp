//
// Created by svale on 5/3/2022.
//

#include <iostream>
#include <random>
#include <val/montecarlo/MonteCarloSim_beta.h>

using DistributionReal = Distribution<double, double, std::uniform_real_distribution>;

int main()
{
    DistributionReal D(0.0, 1.0, 6);

auto condition_met{[](DistributionReal& gameset, double& matchres, DRE& dre)
        {
            const double prob_win = 0.8;
            const double prob_draw = 0.1;
            int matchresult = 0;
            for (double x : gameset.events)
            {
                if (x < prob_win)
                    matchresult += 2;
                else if (x < prob_win+prob_draw)
                    ++matchresult;
            }
            gameset.reload_random_values(dre);
            if (matchresult == 6) return true;
            return false;
        }};

    MonteCarloSimulation<double, double, double, std::uniform_real_distribution> monteCarloSimulation
            (1'000'000,
             7,
             condition_met,
             D);

    monteCarloSimulation.run();

    monteCarloSimulation.print_result();
}
