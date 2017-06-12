/** \file blind_spider.cpp
 * \brief Random walk on spider's web.
 *
 */

#include <iostream>
#include <random>
#include <val/util.h>

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

    vector<vector<int>> state_matrix = {state0, state1, state2, state3, state4,
                                        state5, state6, state7, state8};

    const int nr_trials = 1'000'000;
    default_random_engine dre;

    int current_state = 0;
    int absorb_state = 1;
    double total_nr_transitions = 0.0;

    StopWatch stopWatch;

    for ( int ix =0; ix < nr_trials; ++ix ) {
        double nr_transitions = 0.0;
        int nr_current_transitions = static_cast<int>(state_matrix[current_state].size());
        while ( current_state != absorb_state ) {
            uniform_int_distribution<int> uid(0, nr_current_transitions-1);
            int selected_node = state_matrix[current_state][uid(dre)];
            current_state = selected_node;
            nr_current_transitions = static_cast<int>(state_matrix[current_state].size());
            nr_transitions += 1.0;
        }
        current_state = 0;
        total_nr_transitions += nr_transitions;
    }
    cout << "Requires " << total_nr_transitions /static_cast<double>(nr_trials) << " transitions.\n";

    stopWatch.stop();
}