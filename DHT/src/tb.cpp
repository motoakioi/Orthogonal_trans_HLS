//#include <stdio.h>
//#include <stdlib.h>

#include <iostream>
//#include <sys/time.h>
#include <chrono>

#include "dht.h"

int main(void){

//	int in_hw[64] = {
//			1, 2, 3, 4, 5, 6, 7, 8,
//			1, 2, 3, 4, 5, 6, 7, 8,
//			1, 2, 3, 4, 5, 6, 7, 8,
//			1, 2, 3, 4, 5, 6, 7, 8,
//			1, 2, 3, 4, 5, 6, 7, 8,
//			1, 2, 3, 4, 5, 6, 7, 8,
//			1, 2, 3, 4, 5, 6, 7, 8,
//			1, 2, 3, 4, 5, 6, 7, 8
//	};
	int in_hw[SIZE][SIZE] = {
		{1, 2, 3, 4, 5, 6, 7, 8},
		{1, 2, 3, 4, 5, 6, 7, 8},
		{1, 2, 3, 4, 5, 6, 7, 8},
		{1, 2, 3, 4, 5, 6, 7, 8},
		{1, 2, 3, 4, 5, 6, 7, 8},
		{1, 2, 3, 4, 5, 6, 7, 8},
		{1, 2, 3, 4, 5, 6, 7, 8},
		{1, 2, 3, 4, 5, 6, 7, 8}
	};
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
	float out_hw[SIZE][SIZE];
	float out_sw[SIZE][SIZE];

/*
	int in_hw[64] = {
		1, 2, 3, 4, 5, 6, 7, 8,
		1, 2, 3, 4, 5, 6, 7, 8,
		1, 2, 3, 4, 5, 6, 7, 8,
		1, 2, 3, 4, 5, 6, 7, 8,
		1, 2, 3, 4, 5, 6, 7, 8,
		1, 2, 3, 4, 5, 6, 7, 8,
		1, 2, 3, 4, 5, 6, 7, 8,
		1, 2, 3, 4, 5, 6, 7, 8
	};
	int out_hw[64];

	int in_sw[8][8] = {
		{1, 2, 3, 4, 5, 6, 7, 8},
		{1, 2, 3, 4, 5, 6, 7, 8},
		{1, 2, 3, 4, 5, 6, 7, 8},
		{1, 2, 3, 4, 5, 6, 7, 8},
		{1, 2, 3, 4, 5, 6, 7, 8},
		{1, 2, 3, 4, 5, 6, 7, 8},
		{1, 2, 3, 4, 5, 6, 7, 8},
		{1, 2, 3, 4, 5, 6, 7, 8}
	};
	int out_sw[8][8];

	double in[8][8] = {
		{1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0},
		{1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0},
		{1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0},
		{1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0},
		{1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0},
		{1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0},
		{1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0},
		{1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0}
	};
	double out_hw[8][8];
	double out_sw[8][8];


	int out_hw[8][8];
	int out_sw[8][8];
*/

	std::chrono::system_clock::time_point start_time_hw, end_time_hw;
	std::chrono::system_clock::time_point start_time_sw, end_time_sw;

	// Hardware
	start_time_hw = std::chrono::system_clock::now();
	dht_hw( in_hw, out_hw );
	end_time_hw = std::chrono::system_clock::now();

	std::cout << "HW time is "
			<< std::chrono::duration_cast< std::chrono::microseconds >( end_time_hw - start_time_hw ).count()
			<< std::endl;

	// Software
	start_time_sw = std::chrono::system_clock::now();
	dht_sw( in_sw, out_sw );
	end_time_sw = std::chrono::system_clock::now();

	std::cout << "SW time is "
				<< std::chrono::duration_cast< std::chrono::microseconds >( end_time_sw - start_time_sw ).count()
				<< std::endl;

	for ( int index = 0; index < 64; index++ ){
		std::cout << out_hw[index % 8][index / 8] << ", ";
	}
	std::cout << std::endl;
	
	for ( int index = 0; index < 64; index++ ){
		std::cout << out_sw[index % 8][index / 8] << ", ";
	}
	std::cout << std::endl;
	
	for ( int index = 0; index < 64; index++ ){
		if ( out_hw[index % 8][index / 8] != out_sw[index % 8][index / 8] ) {
			std::cout << "Error! @" << index << std::endl;
		}
	}

	return 0;
}
