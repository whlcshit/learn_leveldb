#include <iostream>
#include <stdio.h>
#include "util/random.h"

int main(){
    printf("test random\n");
	leveldb::Random t_rand(4);
	int i = 0;
	int a = 0;
	while (1){
	    std::cin >> a;
	    for (i = 0; i<5; i++){
		    std::cout << "Uniform: " << t_rand.Uniform(a) << std::endl;
		    std::cout << "Skewed: " << t_rand.Skewed(a) << std::endl;
		    std::cout << std::endl;
	    }
	}
}
