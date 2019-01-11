#include <iostream>

#include "dct.h"

void dct_hw( int in[64], float out[64] ){

//#pragma HLS INTERFACE axis port=in
//#pragma HLS INTERFACE axis port=out

	short in_tmp[64];
	short tmp_x, tmp_y;

	for(int index = 0; index < 64; index++ ){
#pragma HLS PIPELINE II=1
		in_tmp[index] = (short)in[index];
	}

	for ( int v = 0; v < 8; v++ ){
//#pragma HLS PIPELINE II=1
#pragma HLS dataflow
		float C_v = ( v == 0 ) ? 1 / sqrt2 : 1;

		for ( int u =0; u < 8; u++ ){
#pragma HLS PIPELINE II=1
			float C_u = ( u == 0 ) ? 1 / sqrt2 : 1;
			tmp_x = 0;

			for(int x = 0; x < 8; x++ ){
//#pragma HLS PIPELINE II=1
				tmp_y = 0;

				for ( int y = 0; y < 8; y++ ){
					tmp_y += in_tmp[ ( y << 3 ) + x ] * cos_tb[y][v] >> 8;
				}// for loop of y

				tmp_x += tmp_y * cos_tb[x][u] >> 8;
			}// for loop of x

			out[ v * 8 + u ] = C_u * C_v * tmp_x / 4.0;

		}// for loop of u
	}// for loop of v

}


