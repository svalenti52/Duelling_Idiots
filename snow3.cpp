/** \file snow3.cpp
 * \brief random left subdivisions of the unit interval and
 * the resulting sum of the sequence of right endpoints.
 *
 * \details Take a sequence of left sub-intervals (0..x1), (0..x2),
 * (0..x3), ..., where x1 > x2 > x3 > ... (note: these are selected at
 * random from ever smaller intervals (0..1), (0..x1), (0..x2) ...).
 * The real distribution is uniform as well. Form the infinite sum of
 * the right endpoints (x1+x2+x3+...). For s on the unit interval where
 * S represents the sum, P(S <= s) = e^-gamma * s where gamma is Euler's
 * constant (gamma = 0.57721566490153286...). Note that for bin[99] below,
 * it should approximate e^-gamma * 1 ~ 0.5615.
 */

// snow3.cpp
// g++ -std=c++14

#include <random>
#include <iostream>

int main(int argc, char* argv[])
{
	long seed = 0;
	if ( argc == 2 ) seed = std::strtol(argv[1], nullptr, 10);

	std::default_random_engine dre;
	dre.seed(static_cast<unsigned long>(seed));

	const int nr_bins{100};
	std::vector<double> bin(nr_bins, 0.0);
	double bin_width = 1.0 / nr_bins;
	int right_end_index = 1;
	for ( double& value : bin )
	{
		value = static_cast<double>(right_end_index) * bin_width;
		++right_end_index;
	}

	const int nr_trials = 5'000'000;
	const int nr_slices = 10;

	std::vector<int> cum_bin(nr_bins, 0);

	for ( int ix = 0; ix < nr_trials; ++ix )
	{
		double right_endpoint = 1.0;
		double sum_of_right_endpoints = 0.0;

		for ( int jx = 0; jx < nr_slices; ++jx )
		{
			std::uniform_real_distribution<double> uniform_dist(0.0,right_endpoint);
			right_endpoint = uniform_dist(dre);
			sum_of_right_endpoints += right_endpoint;
		}

		for ( int jx = 0; jx < nr_bins; ++jx )
		{
			if ( sum_of_right_endpoints < bin[jx] )
				++cum_bin[jx];
		}
	}

	for ( int value : cum_bin )
		std::cout << "  " << value;
	std::cout << "\n\n";

	std::cout << "cumulative probability at 1 = " <<
		static_cast<double>(cum_bin[99]) /
		static_cast<double>(nr_trials) << '\n';

}
