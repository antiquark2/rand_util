#include <random>
#include <tuple>

namespace rand_util 
{
std::tuple<std::mt19937       ,
           std::minstd_rand0  ,
           std::minstd_rand   ,
           std::mt19937_64    ,
           std::ranlux24_base ,
           std::ranlux48_base ,
           std::ranlux24      ,
           std::ranlux48      ,
           std::knuth_b> rand_generators; 
} 
