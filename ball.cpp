//
// Created by svale on 2/25/2022.
//

#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

const int nr_balls = 50;

class Urn
{
    std::vector<bool> urn;
public:
    Urn(bool isBlack)
        {
        for (int ix = 0; ix < nr_balls; ++ix)
            urn.push_back(isBlack);
        }

        void put(bool isBlack, int selected)
        {
            urn[selected] = isBlack;
        }

        bool get(int selected)
        {
            return urn[selected];
        }

        int count()
        {
            return std::count(urn.begin(), urn.end(), true);
        }
};

int main()
{
    Urn urn_init_black(true);
    Urn urn_init_white(false);

    std::default_random_engine dre(0);
    std::uniform_int_distribution<int> x(0, nr_balls-1);

    std::vector<int> results;

    for (int ix = 0; ix < 400; ++ix)
    {
        results.push_back(urn_init_black.count());
        int black_index = x(dre);
        int white_index = x(dre);
        bool is_black_from_black = urn_init_black.get(black_index);
        bool is_black_from_white = urn_init_white.get(white_index);

        urn_init_black.put(is_black_from_white, black_index); // exchange
        urn_init_white.put(is_black_from_black, white_index);
    }

    for (int y : results)
        std::cout << y << ' ';
    std::cout << '\n';
}