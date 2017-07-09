/** \file glow2.cpp
 * \brief A series-parallel-series of switches should be closed for a light
 * bulb to glow.
 *
 * \details Same logic as glow.cpp but it introduces some standard algorithms
 * although it still is not as efficient as glow.cpp. Also have range-
 * based for loops which are superior in that the indexes are unnecessary.
 * Reads somewhat logically because following the end of each loop is check
 * for "all_of" in the case of serial switches and "any_of" in the case of
 * parallel switches. The breaks in the interior serial and parallel loops
 * save a great deal of time especially as the number of switches per layer
 * increases. The deque was introduced because the vector<bool> is a special
 * bit-oriented implementation that cannot be set as reference in the range-
 * based for loop.
 */

// glow2.cpp

#include <random>
#include <iostream>
#include <algorithm>
#include <deque>
#include <val/montecarlo/Chronology.h>

class Switches {
public:
	std::deque<bool> switch_closed;
public:
	Switches(int nr_switches) {
		for ( int ix = 0; ix < nr_switches; ++ix )
			switch_closed.push_back(false);
	}
};

int main(int argc, char* argv[])
{
	if ( argc != 3 )
		{
			std::cout << "usage: ./a <nr_switches_per_layer> <prob_closed>\n";
			return 1;
		}

	int nr_switch_per_layer = std::atoi(argv[1]);
	double prob_switch_closed = std::atof(argv[2]);

	int nr_trials = 1'000'000;
	int nr_glows = 0;
	std::default_random_engine dre;
	std::uniform_real_distribution<double> uniform_dist_over_1(0.0,1.0);

	Switches exterior_series_switches(nr_switch_per_layer);
	Switches parallel_switches(nr_switch_per_layer);
	Switches interior_series_switches(nr_switch_per_layer);

	StopWatch sw;

	for ( int i = 0; i < nr_trials; ++i )
	{

		for ( bool& exterior_switch : exterior_series_switches.switch_closed ) // series
		{
			for ( bool& parallel_switch : parallel_switches.switch_closed ) // parallel
			{
				for (bool& interior_switch : interior_series_switches.switch_closed )
				{
					auto switch_instance = uniform_dist_over_1(dre);
					interior_switch = switch_instance <= prob_switch_closed;
					if ( !interior_switch ) break;
				}

                parallel_switch = std::all_of(interior_series_switches.switch_closed.begin(),
                    interior_series_switches.switch_closed.end(),
                    [](bool val) { return val; } );

				if ( parallel_switch == true )
                    break;  // break because it is a parallel component
			}

			exterior_switch = std::any_of(parallel_switches.switch_closed.begin(),
                    parallel_switches.switch_closed.end(),
                    [](bool val) { return val; } );
		}

		if ( std::all_of(exterior_series_switches.switch_closed.begin(),
				exterior_series_switches.switch_closed.end(),
				[](bool val) { return val;} ) )
			++nr_glows;
	}

	std::cout << "number of times that light glows = " << nr_glows << '\n';
	std::cout << "prob of light glowing = "
		<< static_cast<double>(nr_glows) / static_cast<double>(nr_trials)
		<< '\n';

	sw.stop();

	return 0;
}
