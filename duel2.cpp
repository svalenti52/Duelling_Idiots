/** \file duel2.cpp
 * \brief Duel with alternating shots, but increasing by one
 * the number of consecutive shots a duellist takes on each turn.
 *
 * /details A shoots once, B twice, A three times, B four times till
 * someone is shot. Uses a hash table to find whether A or B is
 * shot.
 */

// duel2.cpp

#include <random>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <val/util.h>

enum class Duellist {
    A,
    B
};

std::unordered_set<int> A_shot_B = {1,
                             4, 5, 6,
                             11, 12, 13, 14, 15,
                             22, 23, 24, 25, 26, 27, 28,
                             37, 38, 39, 40, 41, 42, 43, 44, 45,
                             56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66,
                             79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91};

Duellist who_was_shot(const int shot_nr)
{

    if ( A_shot_B.find(shot_nr + 1 ) != A_shot_B.end() )
        return Duellist::B;
    else
        return Duellist::A;
}

int main()
{
    std::default_random_engine dre;
    std::uniform_real_distribution<double> uniform_dist_over_1(0.0,1.0);

    const double real_bullet = 1.0/6.0;
    const int nr_trials = 10'000'000;

    double player_b_shot = 0.0;

    int count_too_many_shots = 0;

    A_shot_B.max_load_factor(0.7);

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

        if ( who_was_shot(trigger_pull_count) == Duellist::B )
            player_b_shot += 1.0;
    }

    std::cout << "Probability of A winning = "
        << player_b_shot / static_cast<double>(nr_trials) << '\n';

    std::cout << "Too many shots for method: " << count_too_many_shots << '\n';

    stopWatch.stop();

    std::cout << "hash table bucket count = " << A_shot_B.bucket_count() << '\n';
    std::cout << "load factor = " << A_shot_B.load_factor() << '\n';

    return 0;
}
