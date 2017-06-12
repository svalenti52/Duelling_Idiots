/** \file duel1.cpp
 * \brief Probability that the first of two duellists survives
 * given an alternating single shot.
 */

#include <random>
#include <iostream>
#include <val/util.h>

int main()
{
    std::default_random_engine dre;
    std::uniform_real_distribution<double> uniform_dist_over_1(0.0,1.0);

    const double real_bullet = 1.0/6.0;
    const int nr_trials = 10'000'000;

    double player_b_shot = 0.0;

    StopWatch stopWatch;

    for ( int ix = 0; ix < nr_trials; ++ix )
    {
        bool shot_fired(false);

        int who_was_shot = 0;
        while ( !shot_fired )
        {
            if ( uniform_dist_over_1(dre) < real_bullet )
                shot_fired = true;
            else
                ++who_was_shot;
        }

        if ( who_was_shot % 2 == 0 )
            player_b_shot += 1.0;
    }

    std::cout << "Probability of A winning = "
        << player_b_shot / static_cast<double>(nr_trials) << '\n';

    stopWatch.stop();

    return 0;
}
