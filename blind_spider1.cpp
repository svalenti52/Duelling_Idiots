/**
 * \file blind_spider1.cpp
 * \date 7-Jul-2017
 *
 * \brief Version with vectorized distributions.
 */

#include <iostream>
#include <random>
#include <val/montecarlo/Chronology.h>

using namespace std;

int main() {
    vector<int> state0 = {3, 6, 7};
    vector<int> state1 = {2, 8};
    vector<int> state2 = {1, 4, 7};
    vector<int> state3 = {0};
    vector<int> state4 = {2, 5};
    vector<int> state5 = {4, 6};
    vector<int> state6 = {0, 5, 7};
    vector<int> state7 = {0, 2, 6, 8};
    vector<int> state8 = {1, 7};

    uniform_int_distribution<int> uid_1state(0, static_cast<int>(state3.size()-1));
    uniform_int_distribution<int> uid_2states(0, static_cast<int>(state1.size()-1));
    uniform_int_distribution<int> uid_3states(0, static_cast<int>(state0.size()-1));
    uniform_int_distribution<int> uid_4states(0, static_cast<int>(state7.size()-1));

    vector<vector<int>> state_matrix = {state0, state1, state2, state3, state4,
                                        state5, state6, state7, state8};

    vector<uniform_int_distribution<int>> transitions = {
            uid_3states, uid_2states, uid_3states,
            uid_1state, uid_2states, uid_2states,
            uid_3states, uid_4states, uid_2states
    };

    const int nr_trials = 1'000'000;
    default_random_engine dre;

    int current_state = 0;
    int absorb_state = 1;
    double total_nr_transitions = 0.0;

    StopWatch stopWatch;

    for ( int ix =0; ix < nr_trials; ++ix ) {
        double nr_transitions = 0.0;
        while ( current_state != absorb_state ) {
            int selected_node = state_matrix[current_state][transitions[current_state](dre)];
            current_state = selected_node;
            nr_transitions += 1.0;
        }
        current_state = 0;
        total_nr_transitions += nr_transitions;
    }
    cout << "Requires " << total_nr_transitions /static_cast<double>(nr_trials) << " transitions.\n";

    stopWatch.stop();
}
