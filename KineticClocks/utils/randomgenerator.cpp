#include "randomgenerator.hpp"
#include <random>
#include <chrono>

namespace twentysixapps
{
    struct seeded_rng : public std::default_random_engine {
        seeded_rng() : std::default_random_engine(std::random_device()()) {}
    };


     seeded_rng rnd;

    int random_int(int n)
    {
        return  std::uniform_int_distribution<int>(0,n-1)(rnd);
    }

    int random_range_inclusive(int a, int b)
    {
        return std::uniform_int_distribution<int>(a,b)(rnd);
    }

    int random_sign() {
        return 2*random_int(2)-1;
    }

}
