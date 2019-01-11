#include <iostream>
//#include <math.h>

#include "hadamard.h"

void hadamard_hw( int in[SIZE2], float out[SIZE2] ){

	short in_tmp[SIZE2];
//#pragma HLS resource variable=in_tmp core=RAM_S2P_BRAM

//#pragma HLS ALLOCATION instances=fadd limit=8 operation
//#pragma HLS ALLOCATION instances=fmul limit=8 operation

	for ( int index = 0; index < SIZE2; index++ ){
//#pragma HLS PIPELINE II=1
		in_tmp[index] = in[index];
	}

	for ( int v = 0; v < 8; v++ ){
//#pragma HLS PIPELINE II=1
		for ( int u = 0; u < 8; u++ ){

			short tmp_y = 0.0;

			for ( int y = 0; y < 8; y++ ){

				short tmp_x = 0.0;

				for ( int x = 0; x < 8; x++ ){

					tmp_x += in_tmp[ x + y * 8 ] * hadamard_tb[x][u];

				} // for loop of x

				tmp_y += tmp_x * hadamard_tb[y][v];
			} // for loop of y

			out[u + v * 8] = (float)tmp_y / SIZE ;


		} // for loop of u
	} // for loop of v

}
