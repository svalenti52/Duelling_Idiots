/** \file osc_limit.cpp
 * \brief A circuit either decays monotonically or oscillates depending on components.
 *
 * \details Considers the coefficients of a quadratic equation, Ax^2 + Bx + C
 * = 0 in trying  * to determine whether a capacitor discharge will decay
 * monotonically or will  * oscillate. The discriminant should be positive in
 * the decaying monotonically case. It is calculated for both the partially
 * and fully random quadratic equation. The partially random refers to the
 * quadratic equation with x^2 + Bx + C = 0 ( with B and C independently
 * random over the unit interval). Fully random refers to the quadratic
 * equation with Ax^2 + Bx + C = 0 ( with A, B, and C independently
 * random over the unit interval).
 */

// osc_limit.cpp

#include <iostream>
#include <random>
//#include <val/utilities.hpp>
#include <val/montecarlo/Histogram.h>

int main()
{
	const int nr_trials = 1'000'000;
	std::default_random_engine dre;
	std::uniform_real_distribution<double> urd(0.0,1.0);
	dre.seed(0);

	double tot_first_coef = 0.0;
	double tot_second_coef = 0.0;

	Histogram<double, double> histogram1(0.0, 200.0, 8.0);
	Histogram<double, double> histogram2(0.0, 100.0, 1.0);
	//Bins bins1(100, 10.0);
	//Bins bins2(100, 10.0);

	double prob_decay_total = 0.0;
	double prob_decay_partial = 0.0;

	for ( int trial_ix =0; trial_ix < nr_trials; ++trial_ix )
	{
		//auto C = urd(dre);
		auto A = urd(dre);
        auto A1 = urd(dre);
		auto B = urd(dre);
		auto C = urd(dre);

		auto first_coefficient = B / A;
		auto second_coefficient = C / A1;  // make independent

		if ( B * B >= 4.0 * A * C )
			prob_decay_total += 1.0;

		if ( first_coefficient * first_coefficient >= 4.0 * second_coefficient )
			prob_decay_partial += 1.0;



		histogram1.increment_if_in_range(B/A);
		histogram2.increment_if_in_range(C/A);

		tot_first_coef += B/A;
		tot_second_coef += C/A;
	}

	std::cout << "first set of bins\n" << histogram1 << "\n\n";
//	std::cout << "second set of bins\n" << histogram2 << "\n\n";

	std::cout << "mean first coefficient = " <<
		tot_first_coef / static_cast<double>(nr_trials) << '\n';
	std::cout << "mean second coefficient = " <<
		tot_second_coef / static_cast<double>(nr_trials) << '\n';

	std::cout << "Probability of decay (real discriminant) for total random quadratic = "
			  << prob_decay_total /static_cast<double>(nr_trials) << '\n';

	std::cout << "Probability of decay (real discriminant) for partial random quadratic = "
			  << prob_decay_partial /static_cast<double>(nr_trials) << '\n';
}
