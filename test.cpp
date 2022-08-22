#include "rand_util.hpp"
 
#include <iostream>
#include <iomanip>

int main()
{
	
	using namespace std;
	const int W = 9;
	
	rand_util::rand_seed_all(111, 222);
	const int C = 5;
	for(int i = 0 ; i < C*7  ; i ++ )
	{		
		cout << setw(3) << i << " " ;
		if(i == C*1)rand_util::rand_seed<std::minstd_rand>(111, 222);
		if(i == C*2)rand_util::rand_seed<std::ranlux48>(111, 222);
		if(i == C*3)rand_util::rand_seed<std::ranlux24>(111, 222);
		if(i == C*4)rand_util::rand_seed<std::knuth_b>(111, 222);
		if(i == C*5)rand_util::rand_seed(111, 222);
		if(i == C*6)rand_util::rand_seed_all(111, 222);
		
		cout << setw(W) << rand_util::rand_int(10, 20)  << " " ;	
		cout << setw(W) << rand_util::rand_real<std::minstd_rand>(20, 30)  << " " ;		
		cout << setw(W) << rand_util::rand_real<std::ranlux48>(30.0, 40.0)  << " " ;		
		cout << setw(W) << rand_util::rand_normal<std::ranlux24>(50, 10)  << " " ;		
		cout << setw(W) << rand_util::rand_normal<std::knuth_b>(60.0, 10.0)  << " " ;	
		cout << endl;
	}
  
}
 
