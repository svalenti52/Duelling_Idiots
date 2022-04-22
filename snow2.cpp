/** \file snow2.cpp
 * \brief Approximates e by averaging how many numbers selected from the unit
 * interval it takes to sum up greater than one.
 *
 * \details
*/

#include <random>
#include <iostream>
#include <val/montecarlo/Chronology.h>

int main(int argc, char* argv[])
{
	long seed = 0;
	if ( argc == 2 ) seed = std::strtol(argv[1], nullptr, 10);

	std::default_random_engine dre;
	dre.seed(static_cast<unsigned long>(seed));
	std::uniform_real_distribution<double> uniform_dist_over_1(0.0,1.0);

	const int nr_trials = 10'000'000;

	int tot_sum_gt_one = 0;

	StopWatch stopWatch;

	for ( int ix = 0; ix < nr_trials; ++ix )
	{
		double rnd_sum = uniform_dist_over_1(dre);
		int sum_gt_one = 1;

		while ( rnd_sum < 1.0 )
		{
			rnd_sum += uniform_dist_over_1(dre);
			++sum_gt_one;
		}
		tot_sum_gt_one += sum_gt_one;
	}

	std::cout << "estimate for e is = " <<
		static_cast<double>(tot_sum_gt_one) /
		static_cast<double>(nr_trials) <<
		'\n';

	stopWatch.stop();
}