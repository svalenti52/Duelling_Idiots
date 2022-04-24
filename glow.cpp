/** \file glow.cpp
 * \brief A series-parallel-series of switches should be closed for a light
 * bulb to glow.
 *
 * \details A sequence of switches is arranged in three layers so that the
 * top layer is a serially connected sequence of N switches, comprised of a
 * middle layer of N switches connected in parallel each of which is comprised
 * of a low layer of N switches connected in series. Note that each of layers
 * has the same number of switches. A series of switches is considered closed
 * when all of the switches making up the series are closed. Switches in
 * parallel are closed if any of the switches are closed.
 */

// glow.cpp

#include <random>
#include <iostream>
#include <val/montecarlo/Chronology.h>

bool is_series_closed( long nr_switches_per_layer, double ps_closed,
	std::default_random_engine& dre,
	std::uniform_real_distribution<double>& uni_dist )
{

	bool whole_switch_close = true;

	for ( int ix = 0; ix < nr_switches_per_layer; ++ix )
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
			std::cout << "usage: ./a <nr_switches_per_layer> <prob_closed>\n";
			return 1;
		}

	long nr_switches_per_layer = std::strtol(argv[1], nullptr, 10);
	double prob_switch_closed = std::strtod(argv[2], nullptr);

	int nr_trials = 1'000'000;
	int nr_glows = 0;
	std::default_random_engine dre;
	std::uniform_real_distribution<double> uniform_dist_over_1(0.0,1.0);
	bool whole_switch_close = false;

	StopWatch stopWatch;

	for ( int i = 0; i < nr_trials; ++i )
	{
		for ( int ix = 0; ix < nr_switches_per_layer; ++ix ) // series
		{
			for ( int jx = 0; jx < nr_switches_per_layer; ++jx ) // parallel
			{
				whole_switch_close =
					is_series_closed( nr_switches_per_layer,
						prob_switch_closed,
						dre, uniform_dist_over_1 );
				if ( whole_switch_close )
					break;
			}
			if ( !whole_switch_close )
				break;
		}

		if ( whole_switch_close )
			++nr_glows;
	}

	std::cout << "number of times that light glows = " << nr_glows << '\n';
	std::cout << "prob of light glowing = "
		<< static_cast<double>(nr_glows) / static_cast<double>(nr_trials)
		<< '\n';

	stopWatch.stop();

	return 0;
}
