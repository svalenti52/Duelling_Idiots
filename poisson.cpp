/**
 * \file poisson.cpp
 * \date 26-Jul-2017
 *
 * \brief Displays contents of poisson random deque
 *
 */

#include <val/montecarlo/MonteCarloSim_beta.h>
#include <val/montecarlo/Histogram.h>

int main() {

    Histogram<int, int> histogram(0, 15, 1);

    const double mean = 3.3;

    const int nr_events = 100;

    Distribution<int, double, std::poisson_distribution>
            distribution(mean, nr_events);

    MonteCarloSimulation<int, int, double, std::poisson_distribution>
            monteCarloSimulation(
            10,
            1,
            nullptr,
            distribution
    );

    monteCarloSimulation.show_distribution();

    std::cout << "\n\n";

    // std::cout << histogram << '\n';
}
