#include <random>
#include <limits>
#include <tuple>
#include <iostream>
#include <typeinfo>

namespace rand_util 
{

float       promote(float);
double      promote(double);
long double promote(long double);
template<typename T> double promote(T x);

extern std::tuple< std::mt19937       ,
		   std::minstd_rand0  ,
		   std::minstd_rand   ,
		   std::mt19937_64    ,
		   std::ranlux24_base ,
		   std::ranlux48_base ,
		   std::ranlux24      ,
		   std::ranlux48      ,
		   std::knuth_b       > rand_generators;      

template<typename GEN = std::mt19937> void rand_seed(std::seed_seq::result_type s0, std::seed_seq::result_type s1 = 0)
{
	std::seed_seq seq{ s0, s1 };
	std::get<GEN>(rand_generators).seed(seq);
}


template<int N>
void rand_seed_recursive(std::seed_seq::result_type s0, std::seed_seq::result_type s1)
{		
#ifdef __cpp_if_constexpr
	if constexpr(N < std::tuple_size<decltype(rand_generators)>::value )
	{	
		std::seed_seq seq{ s0, s1 };	
		std::get<N>(rand_generators).seed(seq);		
		rand_seed_recursive<N + 1>(s0, s1);	
	}
#else
	cout << "rand_seed_recursive not implemented in C++ " << __cplusplus << ".\n";
#endif
}


void rand_seed_all(std::seed_seq::result_type s0, std::seed_seq::result_type s1 = 0)
{	
	
	rand_seed_recursive<0>(s0, s1);
}


template<typename GEN = std::mt19937, typename I> I rand_int   (I a, I b)
{	
	return std::uniform_int_distribution<I>(a, b)(std::get<GEN>(rand_generators));
}

template<typename GEN = std::mt19937, typename R> decltype(promote(R{})) rand_real  (R a, R b)
{
	return std::uniform_real_distribution<decltype(promote(R{}))>(a, b)(std::get<GEN>(rand_generators));
}

template<typename GEN = std::mt19937, typename R> decltype(promote(R{})) rand_normal(R a, R b)
{
	return std::normal_distribution<decltype(promote(R{}))>(a, b)(std::get<GEN>(rand_generators));
}

} 
