#include <iostream>

#include "slant.h"

void slant_hw( int in[SIZE2], float out[SIZE2] ){

	short in_tmp[SIZE2];
	short tmp_x;
	int tmp_y;

//#pragma HLS ALLOCATION instances=fadd limit=8 operation
//#pragma HLS ALLOCATION instances=fmul limit=8 operation

	for ( int index = 0; index < SIZE2; index++ ){
#pragma HLS pipeline
		in_tmp[index] = in[index];
	}

	for ( int v = 0; v < 8; v++ ){
//#pragma HLS dataflow
		for ( int u = 0; u < 8; u++ ){

			tmp_y = 0.0;

			for ( int y = 0; y < 8; y++ ){
//#pragma HLS pipeline
				tmp_x = 0;

				for ( int x = 0; x < 8; x++ ){
					tmp_x += in_tmp[ y + x * 8 ] * slant_tb[u][x];
				} // for loop of x

				tmp_y +=  tmp_x * slant_tb[v][y];
			} // for loop of y

			out[u + v * 8] = (float)tmp_y / 65536.0;
		} // for loop of u
	} // for loop of v

}
