//
// Created by svale on 4/29/2022.
//

// snow_pi.cpp

#include <val/montecarlo/MonteCarloSim_beta.h>

using REAL_X_REAL_P_DISTRIBUTION = Distribution<double, double, std::uniform_real_distribution>;

int main()
{
    using namespace std;

    const int nr_components_per_point = 2;

    REAL_X_REAL_P_DISTRIBUTION distribution(0.0, 1.0, nr_components_per_point);

    auto condition_met{[](REAL_X_REAL_P_DISTRIBUTION& point, double& in_inscribed_circle, DRE& dre)
                       {
                           return point.events[0] * point.events[0] + point.events[1] * point.events[1] < 1.0;
                       }};

    MonteCarloSimulation<double, double, double, std::uniform_real_distribution>
            monteCarloSimulation(
            10'000'000,
            8,
            condition_met,
            distribution
    );

    monteCarloSimulation.run();

    auto pi = monteCarloSimulation.return_result() * 4.0;

    cout << "PI is approximated by = " << pi;
}
