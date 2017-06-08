/** \file duel2.cpp
 * \brief Duel with alternating shots, but increasing by one
 * the number of consecutive shots a duellist takes on each turn.
 *
 * /details A shoots once, B twice, A three times, B four times till
 * someone is shot.
 */

// duel2.cpp

#include <random>
#include <iostream>

int who_was_shot(const int shot_nr)
{
    int A_shot = 0;

    int sum = 0;

    for ( int ix = 1; ix < 20; ++ix )
    {
        sum += ix;
        if ( shot_nr < sum )
            break;
        else
            ++A_shot;
    }

    return A_shot;
}

int main()
{
    std::default_random_engine dre;
    std::uniform_real_distribution<double> uniform_dist_over_1(0.0,1.0);

    const double real_bullet = 1.0/6.0;
    const int nr_trials = 10'000'000;

    double player_b_shot = 0.0;

    for ( int ix = 0; ix < nr_trials; ++ix )
    {
        bool shot_fired(false);

        int trigger_pull = 0;
        while ( !shot_fired )
        {
            if ( uniform_dist_over_1(dre) < real_bullet )
                shot_fired = true;
            else
                ++trigger_pull;
        }

        if ( who_was_shot(trigger_pull) % 2 == 0 )
            player_b_shot += 1.0;
    }

    std::cout << "Probability of A winning = "
        << player_b_shot / static_cast<double>(nr_trials) << '\n';

    return 0;
}
