/** \file glow2.cpp
 *
 */

// glow2.cpp

#include <random>
#include <iostream>
#include <algorithm>

bool is_series_closed( int nr_switches_per_dim, double ps_closed,
	std::default_random_engine& dre,
	std::uniform_real_distribution<double>& uni_dist )
{

	bool whole_switch_close = true;

	for ( int ix = 0; ix < nr_switches_per_dim; ++ix )
	{
		auto switch_instance = uni_dist(dre);
		if ( switch_instance > ps_closed )
			{
				whole_switch_close = false;
				break;
			}
	}
	return whole_switch_close;
}

int main(int argc, char* argv[])
{
	if ( argc != 3 )
		{
			std::cout << "usage: ./a <nr_switches_per_dimension> <prob_closed>\n";
			return 1;
		}

	int nr_switch_per_dim = std::atoi(argv[1]);
	double prob_switch_closed = std::atof(argv[2]);

	int nr_trials = 1'000'000;
	int nr_glows = 0;
	std::default_random_engine dre;
	std::uniform_real_distribution<double> uniform_dist_over_1(0.0,1.0);
	bool whole_switch_close = false;

	for ( int i = 0; i < nr_trials; ++i )
	{
		std::vector<bool> series_glows;

		for ( int ix = 0; ix < nr_switch_per_dim; ++ix ) // series
		{
			for ( int jx = 0; jx < nr_switch_per_dim; ++jx ) // parallel
			{
				whole_switch_close =
					is_series_closed( nr_switch_per_dim,
						prob_switch_closed,
						dre, uniform_dist_over_1 );
				if ( whole_switch_close )
					break;  // break because it is a parallel component
			}
			series_glows.push_back(whole_switch_close);
		}

		if ( std::all_of(series_glows.begin(), series_glows.end(), [](bool val) {return val;}) )
			++nr_glows;
	}

	std::cout << "number of times that light glows = " << nr_glows << '\n';
	std::cout << "prob of light glowing = "
		<< static_cast<double>(nr_glows) / static_cast<double>(nr_trials)
		<< '\n';

	return 0;
}
