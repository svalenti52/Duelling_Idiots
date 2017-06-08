/** \file util.h
 *
 */

//
// Created by svalenti on 5/30/2017.
//

#ifndef UTIL_H
#define UTIL_H

#include <vector>
#include <chrono>
#include <iostream>

class integral_histogram {
    int min_ix;
    int max_ix;
    int upper_bound;
    std::vector<int> histogram;
    int total_count;
public:
    integral_histogram(int i_min, int i_max)
            : min_ix(i_min), max_ix(i_max), upper_bound(i_max - i_min), total_count(0) {
        for ( int ix = 0; ix < upper_bound; ++ix )
            histogram.push_back(0);
    }
    void increment_bucket(int which_bucket) {
        if ( which_bucket < min_ix || which_bucket > max_ix ) throw;
        which_bucket = which_bucket - min_ix;
        ++histogram[which_bucket];
        ++total_count;
    }
    int get_midpoint() {
        int half_way_count = total_count / 2;
        int running_count = 0;
        int ix = 0;
        for ( ix; ix < max_ix - min_ix; ++ix ) {
            running_count += histogram[ix];
            if ( running_count >= half_way_count )
                break;
        }
        return ix + min_ix;
    }
};

class StopWatch {
    std::chrono::system_clock::time_point start;
    std::chrono::system_clock::time_point finish;
    using duration_type = decltype(start - finish);
    duration_type start_to_finish;
public:

    StopWatch() : start(std::chrono::system_clock::now()) {}
    void stop() {
        finish = std::chrono::system_clock::now();
        start_to_finish = finish - start;
        std::cout << "elapsed time = " <<
                  std::chrono::duration_cast<std::chrono::milliseconds>(start_to_finish).count() <<
                  " milliseconds\n";
    }
};

#endif //UTIL_H
