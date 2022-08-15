#include <random>
 

namespace rand_util 
{
extern std::default_random_engine rand_util_generator;

inline void seed_rand(std::seed_seq::result_type s0, std::seed_seq::result_type s1 = 0)
{
	std::seed_seq seq{ s0, s1 };
	rand_util_generator.seed(seq);
}

inline float       promote(float value){return value;}
inline double      promote(double value){return value;}
inline long double promote(long double value){return value;}

template<typename T> 
inline double promote(T value){return (double)value;}

template<typename T> inline T rand_int(T min_, T max_)
{	
	std::uniform_int_distribution<T> distribution(min_, max_);
	return distribution(rand_util_generator);
}

template<typename T_> inline decltype(promote(T_())) rand_real(T_ min_, T_ max_)
{	
	using T = decltype(promote(T_()));
	std::uniform_real_distribution<T> distribution((T)(min_), (T)(max_));
	return distribution(rand_util_generator);	
}

template<typename T_> inline decltype(promote(T_())) rand_normal(T_ mean, T_ stddev)
{	
	using T = decltype(promote(T_()));
	std::normal_distribution<T> distribution((T)(mean), (T)(stddev));
	return distribution(rand_util_generator);	
} 

} 
