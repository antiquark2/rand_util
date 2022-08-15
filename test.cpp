#include "rand_util.hpp"
 
#include <iostream>
#include <iomanip>

int main()
{
	using namespace std;
	
	for(int j = 0 ; j < 2 ; j ++)
	{
		cout << "seed_rand" <<endl;
		rand_util::seed_rand(12345, 67890);	 
		for(int i = 0 ; i < 5 + 30 * j ; i ++ )
		{			
			cout << setw(10) << rand_util::rand_int(1,10) << " ";			
			cout << setw(10) << rand_util::rand_real(10, 20) << " ";
			cout << setw(10) << rand_util::rand_real(20.0, 30.0) << " ";
			cout << setw(10) << rand_util::rand_normal(0, 1) << " " ;
			cout << setw(10) << rand_util::rand_normal(10.0, 10.0) << " " ;
			cout << endl;
		}
	} 
}
 