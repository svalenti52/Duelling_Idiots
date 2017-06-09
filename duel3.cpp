//
// Created by svalenti on 6/9/2017.
//

/** \file duel3.cpp
 * \brief Duel with alternating shots, but increasing by one
 * the number of consecutive shots a duellist takes on each turn.
 *
 * /details A shoots once, B twice, A three times, B four times till
 * someone is shot. This was created since it was desired to preserve
 * the original algorithm (I introduced a hash table for lookup in
 * duel2.cpp.
 */

#include <random>
#include <iostream>
#include "util.h"

int who_was_shot(const int shot_nr)
{

    int shooter = 0;

    int sum = 0;

    for ( int ix = 1; ix < 20; ++ix )
    {
        sum += ix;
        if ( shot_nr < sum )
            break;
        else
            ++shooter;
    }

    return shooter;
}

int main()
{
    std::default_random_engine dre;
    std::uniform_real_distribution<double> uniform_dist_over_1(0.0,1.0);

    const double real_bullet = 1.0/6.0;
    const int nr_trials = 10'000'000;

    double player_b_shot = 0.0;

    int count_too_many_shots = 0;

    StopWatch stopWatch;

    for ( int ix = 0; ix < nr_trials; ++ix )
    {
        bool shot_fired(false);

        int trigger_pull_count = 0;
        while ( !shot_fired )
        {
            if ( uniform_dist_over_1(dre) < real_bullet )
                shot_fired = true;
            else
                ++trigger_pull_count;
        }

        if ( trigger_pull_count > 104 ) ++count_too_many_shots;

        if ( !(who_was_shot(trigger_pull_count) % 2) )
            player_b_shot += 1.0;
    }

    std::cout << "Probability of A winning = "
              << player_b_shot / static_cast<double>(nr_trials) << '\n';

    std::cout << "Too many shots for method: " << count_too_many_shots << '\n';

    stopWatch.stop();

    return 0;
}

