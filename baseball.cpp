/** \file baseball.cpp
 * \brief Probabilities for a world series going four, five,
 * six, and seven games, given the probability of a team winning
 * any one game.
 *
 *
 */

// baseball.cpp

#include <random>
#include <iostream>

int main(int argc, char* argv[])
{
	if ( argc != 2 )
		{
			std::cout << "Usage: ./a <stronger teams pct>\n";
			return 1;
		}
	int stronger_inp = std::atoi(argv[1]);
	double stronger_wins_prob =
		static_cast<double>(stronger_inp)/100.0;

	std::default_random_engine dre;
    std::uniform_real_distribution<double> uniform_dist_over_1(0.0,1.0);

	const int nr_trials = 10000000;

	int four_game_series = 0;
	int five_game_series = 0;
	int six_game_series = 0;
	int seven_game_series = 0;

	for ( int ix = 0; ix < nr_trials; ++ix )
	{
		int stronger_wins = 0;
		int weaker_wins = 0;
		for ( int jx = 0; jx < 7; ++jx )
		{
			if ( uniform_dist_over_1(dre) < stronger_wins_prob )
				++stronger_wins;
			else
				++weaker_wins;
			if ( stronger_wins == 4 || weaker_wins == 4 )
				break;
		}
		int tot_wins = stronger_wins + weaker_wins;
		switch (tot_wins)
		{
			case 4:
				++four_game_series;
				break;
			case 5:
				++five_game_series;
				break;
			case 6:
				++six_game_series;
				break;
			case 7:
				++seven_game_series;
				break;
			default:
				std::cout << "should not reach here...\n";
		}
	}

	std::cout << "Four game series == " <<
		static_cast<double>(four_game_series) /
		static_cast<double>(nr_trials) << '\n';
	std::cout << "Five game series == " <<
		static_cast<double>(five_game_series) /
		static_cast<double>(nr_trials) << '\n';
	std::cout << "Six game series == " <<
		static_cast<double>(six_game_series) /
		static_cast<double>(nr_trials) << '\n';
	std::cout << "Seven game series == " <<
		static_cast<double>(seven_game_series) /
		static_cast<double>(nr_trials) << '\n';

	return 0;
}
