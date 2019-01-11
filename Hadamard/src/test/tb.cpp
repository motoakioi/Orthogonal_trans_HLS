//#include <stdio.h>
//#include <stdlib.h>

#include <iostream>

#include "../hadamard.h"

int main(void){

	int in_hw[SIZE2] = {
			1, 2, 3, 4, 5, 6, 7, 8,
			1, 2, 3, 4, 5, 6, 7, 8,
			1, 2, 3, 4, 5, 6, 7, 8,
			1, 2, 3, 4, 5, 6, 7, 8,
			1, 2, 3, 4, 5, 6, 7, 8,
			1, 2, 3, 4, 5, 6, 7, 8,
			1, 2, 3, 4, 5, 6, 7, 8,
			1, 2, 3, 4, 5, 6, 7, 8
	};
	float out_hw[SIZE2];
	/*int in_hw[SIZE][SIZE] = {
			{1, 2, 3, 4, 5, 6, 7, 8},
			{1, 2, 3, 4, 5, 6, 7, 8},
			{1, 2, 3, 4, 5, 6, 7, 8},
			{1, 2, 3, 4, 5, 6, 7, 8},
			{1, 2, 3, 4, 5, 6, 7, 8},
			{1, 2, 3, 4, 5, 6, 7, 8},
			{1, 2, 3, 4, 5, 6, 7, 8},
			{1, 2, 3, 4, 5, 6, 7, 8}
	};
	float out_hw[SIZE][SIZE];*/
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
	int in_inve[SIZE][SIZE];
	float out_inve[SIZE][SIZE];


	hadamard_hw( in_hw, out_hw );

	hadamard_sw( in_sw, out_sw );

	for ( int index = 0; index < 64; index++ ){
		if( index % 8 == 0 ){
			std::cout << std::endl;
		}
		std::cout << out_hw[index] << ", ";
	}
	std::cout << std::endl;

	for ( int index = 0; index < 64; index++ ){
		if( index % 8 == 0 ){
			std::cout << std::endl;
		}
		std::cout << out_sw[index % 8][index / 8] << ", ";
		in_inve[index % 8][index / 8] = out_sw[index % 8][index / 8];

	}
	std::cout << std::endl;

	for ( int index = 0; index < 64; index++ ){
		if ( out_hw[index] != out_sw[index % 8][index / 8] ) {
			std::cout << "Error! @" << index << std::endl;
		}
	}

	hadamard_sw(in_inve, out_inve);

	for ( int index = 0; index < 64; index++ ){
		if( index % 8 == 0 ){
			std::cout << std::endl;
		}
		std::cout << out_inve[index % 8][index / 8] << ", ";
	}
	std::cout << std::endl;
	
	return 0;
}
