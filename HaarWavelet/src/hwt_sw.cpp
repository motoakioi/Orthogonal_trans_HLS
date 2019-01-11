#include <iostream>
//#include <math.h>

#include "hwt_sw.h"

void hwt_sw( int in[SIZE][SIZE], float out[SIZE][SIZE] ){
	float tmp00, tmp10, tmp01, tmp11;
	/*
	 *	| tmp00 tmp10 |
	 *	| tmp01 tmp11 |
	 */

	int level = 2;
	int tmp_size;
	float tmp_ave[SIZE / 2][SIZE / 2];

	for ( level; level <= SIZE; level*=2 ){

		tmp_size = SIZE / level;

		for (int y = 0; y < tmp_size; y++ ){
			for ( int x = 0; x < tmp_size; x++ ){
				if (level == 2){
					tmp00 = (float)in[x * 2]     [y * 2]; 
					tmp10 = (float)in[x * 2 + 1] [y * 2]; 
					tmp01 = (float)in[x * 2]     [y * 2 + 1]; 
					tmp11 = (float)in[x * 2 + 1] [y * 2 + 1]; 
				}else{
					tmp00 = tmp_ave[x * 2]     [y * 2];
					tmp10 = tmp_ave[x * 2 + 1] [y * 2];
					tmp01 = tmp_ave[x * 2]     [y * 2 + 1];
					tmp11 = tmp_ave[x * 2 + 1] [y * 2 + 1];
				}

				if ( level == SIZE){
					out[x][y]     = ( tmp00 + tmp10 + tmp01 + tmp11 ) / 4.0;
				}else{
					tmp_ave[x][y] = ( tmp00 + tmp10 + tmp01 + tmp11 ) / 4.0;
				}

				out[x + tmp_size] [y]            = ( tmp00 - tmp10 + tmp01 - tmp11 ) / 4.0;
				out[x]            [y + tmp_size] = ( tmp00 + tmp10 - tmp01 - tmp11 ) / 4.0;
				out[x + tmp_size] [y + tmp_size] = ( tmp00 - tmp10 - tmp01 + tmp11 ) / 4.0;

			} // for loop of x
	
		} // for loop of y

	} // for loop of level
}
