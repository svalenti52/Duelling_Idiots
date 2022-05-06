//
// Created by svale on 5/6/2022.
//

#include <vector>
#include <numeric>
#include <cmath>
#include <iostream>

int main()
{
    using namespace std;
    const int max_children = 10'000;
    vector<int> tmplt(101, 0);
    iota(begin(tmplt), end(tmplt), 0);

    vector<double> prob_boy(101, 0.0);
    vector<double> prob_grl(101, 0.0);
    for (int ix = 0; ix < 101; ++ix)
        prob_boy[ix] = tmplt[ix] / 100.0;
    reverse_copy(begin(prob_boy), end(prob_boy), begin(prob_grl));

    vector<double> expected_value;
    for (int ix = 0; ix < 101; ++ix)
    {
        expected_value.push_back(0.0);
        for (int sz_fam = 2; sz_fam < max_children; ++sz_fam)
        {
            expected_value[ix] += (pow(prob_boy[ix], 2) * pow(prob_grl[ix], sz_fam-2) +
                    pow(prob_boy[ix], sz_fam-2) * pow(prob_grl[ix], 2)) * sz_fam;
        }
    }

    for (double x : expected_value)
        cout << x << " ";
    cout << '\n';
}
