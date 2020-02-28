#include "ngon_random.h"

#include <random>

static std::random_device rd;   // better way of generating random numbers compared to `rand()`
static std::mt19937 gen(rd());  // called the Mersenne twister which is a mathematical algorithm to get a random number but it needs a generator(random device `rd` is the generator)

int random_number(int start, int end)
{
    std::uniform_int_distribution<int> dis(start, end);

    return dis(gen);
}