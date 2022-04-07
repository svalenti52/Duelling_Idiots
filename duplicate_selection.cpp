/**
 * \file duplicate_selection.cpp
 * \date 30-Jul-2017
 *
 * \brief When selecting from a list with repetition, how many selections till
 * a number that has been selected is selected again.
 *
 * \details The precise number is the number of time prior to repetition. It
 * is possible for the number to be 1 if the second selection is the same
 * number as the first. Part of Chapter 8 - Ball Madness.
 */

#include <val/montecarlo/MonteCarloSim_beta.h>

using Uniform_Integral = Distribution<int, int, std::uniform_int_distribution>;

int main() {

    const int ub_number_selection = 10'000;

    std::vector<int> selection_tracker(ub_number_selection, 0);

    Uniform_Integral distribution(0, ub_number_selection-1, 1);

    /////////////////////////////////////////////
    auto condition_met = [&selection_tracker]
            (Uniform_Integral& _distribution, double& no_dup_count, DRE& dre) -> bool {

        no_dup_count = 0.0;

        while ( selection_tracker[_distribution.events[0]] == 0 ) { // while number not already marked
            no_dup_count += 1.0;  // increment no duplicate count
            selection_tracker[_distribution.events[0]] = 1;  // mark it
            _distribution.reload_random_values(dre);  // and get next random number
        }

        for ( int& initial_value : selection_tracker ) // unmark all for next calculation
            initial_value = 0;  // the value in no_dup_count is accumulated to eventually determine mean
        return true;
    };
    /////////////////////////////////////////////

    MonteCarloSimulation<int, double, int, std::uniform_int_distribution>
            monteCarloSimulation(
                    100'000,
                    373,
                    condition_met,
                    distribution
            );

    monteCarloSimulation.run();

    monteCarloSimulation.change_message("Average number of selections till first duplicate = ");

    monteCarloSimulation.print_result();

}
