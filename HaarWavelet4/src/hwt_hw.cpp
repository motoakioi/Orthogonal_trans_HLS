#include <iostream>
//#include <math.h>

#include "hwt_hw.h"

void hwt_hw( int in[SIZE][SIZE], float out[SIZE][SIZE] ){
	float tmp00, tmp10, tmp01, tmp11;
	/*
	 *	| tmp00 tmp10 |
	 *	| tmp01 tmp11 |
	 */

	float tmp_ave1[LEVEL1_SIZE][LEVEL1_SIZE];
	float tmp_ave2[LEVEL1_SIZE][LEVEL2_SIZE];

	// Level 1
	for (int y = 0; y < LEVEL1_SIZE; y++ ){
		for ( int x = 0; x < LEVEL1_SIZE; x++ ){
//#pragma HLS PIPELINE II=1


			tmp00 = (float)in[x * 2]     [y * 2];
			tmp10 = (float)in[x * 2 + 1] [y * 2];
			tmp01 = (float)in[x * 2]     [y * 2 + 1];
			tmp11 = (float)in[x * 2 + 1] [y * 2 + 1];

			tmp_ave1[x][y] = ( tmp00 + tmp10 + tmp01 + tmp11 ) / 4.0;

			out[x + LEVEL1_SIZE] [y]               = ( tmp00 - tmp10 + tmp01 - tmp11 ) / 4.0;
			out[x]               [y + LEVEL1_SIZE] = ( tmp00 + tmp10 - tmp01 - tmp11 ) / 4.0;
			out[x + LEVEL1_SIZE] [y + LEVEL1_SIZE] = ( tmp00 - tmp10 - tmp01 + tmp11 ) / 4.0;

		} // for loop of x
	} // for loop of y

	//Level 2
	for (int y = 0; y < LEVEL2_SIZE; y++ ){
		for ( int x = 0; x < LEVEL2_SIZE; x++ ){
//#pragma HLS PIPELINE II=1

			tmp00 = tmp_ave1[x * 2]     [y * 2];
			tmp10 = tmp_ave1[x * 2 + 1] [y * 2];
			tmp01 = tmp_ave1[x * 2]     [y * 2 + 1];
			tmp11 = tmp_ave1[x * 2 + 1] [y * 2 + 1];

			tmp_ave2[x][y] = ( tmp00 + tmp10 + tmp01 + tmp11 ) / 4.0;

			out[x + LEVEL2_SIZE] [y]               = ( tmp00 - tmp10 + tmp01 - tmp11 ) / 4.0;
			out[x]               [y + LEVEL2_SIZE] = ( tmp00 + tmp10 - tmp01 - tmp11 ) / 4.0;
			out[x + LEVEL2_SIZE] [y + LEVEL2_SIZE] = ( tmp00 - tmp10 - tmp01 + tmp11 ) / 4.0;

		} // for loop of x
	} // for loop of y

	
	// Level 3
	tmp00 = tmp_ave2[0][0];
	tmp10 = tmp_ave2[1][0];
	tmp01 = tmp_ave2[0][1];
	tmp11 = tmp_ave2[1][1];

	out[0]           [0]           = ( tmp00 + tmp10 + tmp01 + tmp11 ) / 4.0;
	out[LEVEL3_SIZE] [0]           = ( tmp00 - tmp10 + tmp01 - tmp11 ) / 4.0;
	out[0]           [LEVEL3_SIZE] = ( tmp00 + tmp10 - tmp01 - tmp11 ) / 4.0;
	out[LEVEL3_SIZE] [LEVEL3_SIZE] = ( tmp00 - tmp10 - tmp01 + tmp11 ) / 4.0;

}
