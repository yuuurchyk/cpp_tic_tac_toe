#include "Common.h"

int Common::get_random_number(int l, int r){
    std::mt19937 rng;
    rng.seed(std::random_device()());
    std::uniform_int_distribution<std::mt19937::result_type> res(l,r);

    return res(rng);
}