//#include <stdio.h>
//#include <stdlib.h>

#include <iostream>
#include <chrono>

#include "hwt_hw.h"
#include "hwt_sw.h"

int main(void){

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
	float out_hw[SIZE][SIZE];
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

	std::chrono::system_clock::time_point start_time_hw, end_time_hw;
	std::chrono::system_clock::time_point start_time_sw, end_time_sw;

	// Hardware
	start_time_hw = std::chrono::system_clock::now();
	hwt_hw( in_hw, out_hw );
	end_time_hw = std::chrono::system_clock::now();

	std::cout << "HW time is "
			<< std::chrono::duration_cast< std::chrono::microseconds >( end_time_hw - start_time_hw ).count()
			<< std::endl;

	// Software
	start_time_sw = std::chrono::system_clock::now();
	hwt_sw( in_sw, out_sw );
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
