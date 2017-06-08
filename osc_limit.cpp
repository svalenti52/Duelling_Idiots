/** \file osc_limit.cpp
 *
 */

// osc_limit.cpp

#include <iostream>
#include <random>
#include "utilities.hpp"

int main()
{
	const int nr_trials = 100'000;
	std::default_random_engine dre;
	std::uniform_real_distribution<double> udo1(0.0,1.0);

	double tot_first_coef = 0.0;
	double tot_second_coef = 0.0;

	Bins bins1(100, 10.0);
	Bins bins2(100, 10.0);

	for ( int trial_ix =0; trial_ix < nr_trials; ++trial_ix )
	{
		//auto C = udo1(dre);
		auto A = udo1(dre);
		auto B = udo1(dre);
		auto C = udo1(dre);

		bins1.inc_bin_by_val(B/A);
		bins2.inc_bin_by_val(C/A);

		tot_first_coef += B/A;
		tot_second_coef += C/A;
	}

	std::cout << "first set of bins\n" << bins1 << "\n\n";
	std::cout << "second set of bins\n" << bins2 << "\n\n";

	std::cout << "mean first coefficient = " <<
		tot_first_coef / static_cast<double>(nr_trials) << '\n';
	std::cout << "mean second coefficient = " <<
		tot_second_coef / static_cast<double>(nr_trials) << '\n';
}
