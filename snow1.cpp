/** \file snow1.cpp
 * \brief Approximates e by TotalNrBins/EmptyBins.
 * 
 * \details Approximates the value of e by dividing the unit interval
 * into N bins of width 1/N, then assigning N random values from the
 * unit interval, using uniform distribution, to the corresponding bin.
 * If the number of bins with zero values in it are then counted and divided
 * into the total number of bins (N), the resulting value should approximate
 * e.
 */

#include <random>
#include <iostream>
#include <algorithm>
#include "util.h"

int main(int argc, char* argv[])
{
	int seed = 0;
	if ( argc == 2 ) seed = std::atoi(argv[1]);

	std::default_random_engine dre;
	dre.seed(static_cast<unsigned long>(seed));
	std::uniform_real_distribution<double> uniform_dist_over_1(0.0,1.0);

	const int nr_bins = 100'000;
	std::vector<double> vec_dbl;
	std::vector<int> vec_int(nr_bins, 0);
	const double bin_width = 1.0 / static_cast<double>(nr_bins);
	
	StopWatch stopWatch;

	for ( int ix = 0; ix < nr_bins; ++ix )
		vec_dbl.push_back(bin_width * static_cast<double>(ix+1));

	for ( int int_val : vec_int )
	{
		double sel_bin = uniform_dist_over_1(dre);

		for ( int sel_bin_idx = 0; sel_bin_idx < nr_bins; ++sel_bin_idx )
			if ( sel_bin < vec_dbl[sel_bin_idx] )
			{
				++vec_int[sel_bin_idx];
				break;
			}
	}

	int nr_zeroes = static_cast<int>(std::count(vec_int.begin(), vec_int.end(), 0));
	std::cout << "nr of zeroes = " << nr_zeroes << '\n';

	std::cout << "estimate for e is = " <<
		static_cast<double>(nr_bins) /
		static_cast<double>(nr_zeroes) <<
		'\n';
	
	stopWatch.stop();

}