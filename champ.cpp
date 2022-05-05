//
// Created by svale on 5/3/2022.
//

#include <iostream>
#include <val/montecarlo/MonteCarloSim_beta.h>

using DistributionReal = Distribution<double, double, std::uniform_real_distribution>;

int main()
{
    DistributionReal D(0.0, 1.0, 6);
    const int nr_trials = 1'000'000;
    const double prob_win = 0.6;
    const double prob_draw = 0.1;
    const int common_seed = 7;
    //===========================================
    auto condition_met_draw{[prob_win, prob_draw](DistributionReal& gameset, double& matchres, DRE& dre)
        {
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
    //===========================================

    //===========================================
    auto condition_met_win{[prob_win, prob_draw](DistributionReal& gameset, double& matchres, DRE& dre)
                            {
                                int matchresult = 0;
                                for (double x : gameset.events)
                                {
                                    if (x < prob_win)
                                        matchresult += 2;
                                    else if (x < prob_win+prob_draw)
                                        ++matchresult;
                                }
                                gameset.reload_random_values(dre);
                                if (matchresult > 6) return true;
                                return false;
                            }};
    //===========================================


    std::cout << "\nBased on Probabilities:  Champ Wins = " << prob_win << ",  Drawn Match = " << prob_draw << "\n\n";

    MonteCarloSimulation<double, double, double, std::uniform_real_distribution> monteCarloSimulation_draw
            (nr_trials,
             common_seed,
             condition_met_draw,
             D);

    MonteCarloSimulation<double, double, double, std::uniform_real_distribution> monteCarloSimulation_win
            (nr_trials,
             common_seed,
             condition_met_win,
             D);

    monteCarloSimulation_win.run();

    monteCarloSimulation_win.change_message("Probability Champ wins match = ");

    monteCarloSimulation_win.print_result();

    monteCarloSimulation_draw.run();

    monteCarloSimulation_draw.change_message("Probability of drawn match = ");

    monteCarloSimulation_draw.print_result();
}
