/** \file sameflips.cpp
 * \brief Probability that a set number of people have the same number of heads
 * after a set number of coin flips.
 */


#include <iostream>
#include <vector>
#include <random>

int main(int argc, char* argv[])
{
	std::vector<int> nr_people_set{2, 3, 4};
	std::vector<int> nr_flips_set{10, 50, 100, 150};

	std::default_random_engine dre(7);
	std::uniform_real_distribution<double> uniform_dist_over_1(0.0,1.0);

	const int nr_trials = 10'000;

	for (int nr_people : nr_people_set)
	{
		for (int nr_flips : nr_flips_set)
		{
			int same_result = 0;
			for (int trial=0; trial<nr_trials; ++trial)
			{
				std::vector<int> nr_headflips_per_person;
				for (int person=0; person<nr_people; ++person)
					nr_headflips_per_person.push_back(0);
				for (int flip=0; flip<nr_flips; flip++)
				{
					for (int person=0; person<nr_people; ++person)
					{
						double flip_result = uniform_dist_over_1(dre);
						if ( flip_result < 0.5 )
							++nr_headflips_per_person[person];
					}
				}
				bool all_same_nr_heads = true;
				for (auto person=0; person<nr_people-1; ++person)
				{
					if ( nr_headflips_per_person[person] != nr_headflips_per_person[person+1] )
						{
							all_same_nr_heads = false;
							break;
						}
				}
				if ( all_same_nr_heads )
					++same_result;
			}
			std::cout << "For " << nr_people << " people and " << nr_flips << " flips the probability is "
				<< static_cast<double>(same_result)/static_cast<double>(nr_trials) << '\n';
		}
	}

	return 0;
}
