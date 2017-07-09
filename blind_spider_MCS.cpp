/**
 * \file blind_spider_MCS.cpp
 * \date 8-Jul-2017
 *
 *
 */

#include <iostream>
#include <val/montecarlo/StateMatrix.h>
#include <val/montecarlo/Chronology.h>

int main(){

    State state0(0, {3, 6, 7}, 0 , 2);
    State state1(1, {2, 8}, 0, 1);
    State state2(2, {1, 4, 7}, 0, 2);
    State state3(3, {0}, 0, 0);
    State state4(4, {2, 5}, 0, 1);
    State state5(5, {4, 6}, 0, 1);
    State state6(6, {0, 5, 7}, 0, 2);
    State state7(7, {0, 2, 6, 8}, 0, 3);
    State state8(8, {1, 7}, 0, 1);

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

    StateMatrix stateMatrix(10'000'000, states, 0, 1);

    std::cout << stateMatrix << '\n';

    StopWatch stopWatch;

    stateMatrix.run();

    stopWatch.stop();

    stateMatrix.print_results();

}
