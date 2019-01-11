//#include <stdio.h>
//#include <stdlib.h>

#include <iostream>

#include "hwt_sw.h"

int main(void){

	int in_sw[SIZE][SIZE] = {
		{1, 2, 3, 4, 5, 6, 7, 8},
		{1, 2, 3, 4, 5, 6, 7, 8},
		{1, 2, 3, 4, 5, 6, 7, 8},
		{1, 2, 3, 4, 5, 6, 7, 8},
		{1, 2, 3, 4, 5, 6, 7, 8},
		{1, 2, 3, 4, 5, 6, 7, 8},
		{1, 2, 3, 4, 5, 6, 7, 8},
		{1, 2, 3, 4, 5, 6, 7, 8}
	};
	float out_sw[SIZE][SIZE];

	hwt_sw( in_sw, out_sw );

	for ( int index = 0; index < 64; index++ ){
		std::cout << out_sw[index % 8][index / 8] << ", ";
	}
	std::cout << std::endl;


/*
	for (int y = 0; y < SIZE; y++){
		for (int x = 0; x < SIZE; x++){
			std::cout << test_in4[x][y] << ",";
		}
		std::cout << std::endl;
	}

	std::cout << " out "<< std::endl;
	for (int y = 0; y < SIZE; y++){
		for (int x = 0; x < SIZE; x++){
			std::cout << test_out4[x][y] << ",";
		}
		std::cout << std::endl;
	}
*/

	return 0;
}
