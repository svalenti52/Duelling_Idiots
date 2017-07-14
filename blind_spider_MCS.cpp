/**
 * \file blind_spider_MCS.cpp
 * \date 8-Jul-2017
 *
 * \brief Expected number of steps to reach an absorbing state on a 2D random walk.
 *
 */

#include <iostream>
#include <val/montecarlo/StateMatrix.h>
#include <val/montecarlo/Chronology.h>

int main(){

    /**
     * Initialized fixed states having canonical IDs and fixed transition
     * matrices. Transition selection is uniform.
     */
    State state0( 0, {3, 6, 7} );
    State state1( 1, {2, 8} );
    State state2( 2, {1, 4, 7} );
    State state3( 3, {0} );
    State state4( 4, {2, 5} );
    State state5( 5, {4, 6} );
    State state6( 6, {0, 5, 7} );
    State state7( 7, {0, 2, 6, 8} );
    State state8( 8, {1, 7} );

    /**
     * Initialized state vector, canonical order is important.
     */
    std::vector<State> states{
            state0,
            state1,
            state2,
            state3,
            state4,
            state5,
            state6,
            state7,
            state8
    };

    /**
     * Construct stateMatrix object with the following states:
     *      - nr_trials
     *      - state vector
     *      - starting state
     *      - absorbing state
     */
    StateMatrix stateMatrix(10'000'000, states, 0, 1);

    std::cout << stateMatrix << '\n';

    StopWatch stopWatch;

    stateMatrix.run();

    stopWatch.stop();

    stateMatrix.print_results();
}
