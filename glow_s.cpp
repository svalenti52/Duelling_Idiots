// glow_s.cpp

#include <random>
#include <iostream>
#include <vector>
#include <algorithm>

bool is_series_closed( int nspd, double ps_closed,
	std::default_random_engine& dre,
	std::uniform_real_distribution<double>& uni_dist )
{

	bool inner_series_closed = true;

	for ( int ix = 0; ix < nspd; ++ix )
	{
		auto switch_instance = uni_dist(dre);
		if ( switch_instance > ps_closed )
			{
				inner_series_closed = false;
				break;
			}
	}
	return inner_series_closed;
}

/*
bool is_parallel_closed( int nspd, double ps_closed,
	std::default_random_engine& dre,
	std::uniform_real_distribution<double>& uni_dist )
{

	bool whole_swit_close = false;

	for ( int ix = 0; ix < nspd; ++ix )
	{
		auto switch_instance = uni_dist(dre);
		if ( switch_instance < ps_closed )
			{
				whole_swit_close = true;
				break;
			}
	}
	return whole_swit_close;
}
*/

int main(int argc, char* argv[])
{
	if ( argc != 3 )
		{
			std::cout << "usage: ./a <nr_switches_per_dimension> <prob_closed>\n";
			return 1;
		}

	int nr_swit_per_dim = std::atoi(argv[1]);
	double prob_swit_closed = std::atof(argv[2]);
//	double prob_swit_open = 1.0 - prob_swit_close;
//	bool whole_swit_close = true;

	int nr_trials = 1000000;
	int nr_glows = 0;
	std::default_random_engine dre;
	std::uniform_real_distribution<double> uniform_dist_over_1(0.0,1.0);
	bool inner_series_closed;

	for ( int i = 0; i < nr_trials; ++i )
	{
		std::vector<bool> series_glows;

		for ( int ix = 0; ix < nr_swit_per_dim; ++ix ) // series for outermost
		{
			bool parallel_glows = false;

			for ( int jx = 0; jx < nr_swit_per_dim; ++jx ) // parallel middle
			{
				inner_series_closed =
					is_series_closed( nr_swit_per_dim,
						prob_swit_closed,
						dre, uniform_dist_over_1 );
				if ( inner_series_closed )
				{
					parallel_glows = true;
					break;  // optimization since if one inner series is closed, the parallel unit glows
				}
			}
			if ( parallel_glows )
				series_glows.push_back(true);
			else
				series_glows.push_back(false);
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
