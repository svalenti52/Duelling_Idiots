/** \file embarrassing.cpp
 * \brief An embarrassing question is asked probabilistically
 * enabling truth (hopefully) sans embarrassment.
 */

// embarrassing.cpp
// Created by svalenti on 6/9/2017.
//

#include <iostream>
#include <random>
#include <algorithm>
#include <val/montecarlo/Chronology.h>

using namespace std;

class person {
public:
    bool embarrassing;
    person(bool i_embarrassing) : embarrassing(i_embarrassing) {}

    bool isEmbarrassing() const
    {
        return embarrassing;
    }
};

int main(int argc, char** argv)
{

    default_random_engine dre;
    uniform_int_distribution<int> uid(0, 1);
    dre.seed(0);

    const int nr_trials = 10'000;

    const int nr_people = 10'000;
    const int nr_people_embarrassing = 7'460;

    vector<person> people;

    for ( int ix = 0; ix < nr_people; ++ix )
        people.emplace_back(ix < nr_people_embarrassing);

    double cumulative_embarrassing = 0.0;

    StopWatch stopWatch;

    for (int ix = 0; ix<nr_trials; ++ix) {

        for ( int person_idx = 0; person_idx < nr_people; ++person_idx ) {

            int coin_flip1 = uid(dre);

            if ( coin_flip1 == 0 ) {
                int coin_flip2 = uid(dre);
                people[person_idx].embarrassing = (coin_flip2 == 0);
            }
            else {
                people[person_idx].embarrassing = person_idx < nr_people_embarrassing;
            }
        }

        auto how_many_embarrassing = count_if(people.begin(), people.end(),
                [](person p) { return p.isEmbarrassing(); } );

        cumulative_embarrassing += static_cast<double>(how_many_embarrassing);
    }

    auto cumulative_people = static_cast<double>(nr_trials);

    cout << "Number of people reporting embarrassing act = " << cumulative_embarrassing/cumulative_people << '\n';
    cout << "According to numbers should be 6230 reported using probabilistic mechanism.\n";
    cout << "It corresponds to an actual figure of 7460 that perform the embarrassing act.\n";
    cout << "out of a population of " << nr_people << " people\n";

    stopWatch.stop();

    return 0;
}
