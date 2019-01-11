#include <iostream>

#include "dht.h"

void dht_hw( int in[8][8], float out[8][8] ){

	short in_tmp[SIZE][SIZE];

	for ( int v = 0; v < 8; v++ ){
#pragma HLS PIPELINE II=1
		for ( int u = 0; u < 8; u++ ){
			in_tmp[u][v] = in[u][v];
		}
	}

	for ( int v = 0; v < 8; v++ ){
//#pragma HLS dataflow

		for ( int u =0; u < 8; u++ ){
#pragma HLS PIPELINE II=1
			int tmp_out = 0;

			for ( int y = 0; y < 8; y++ ){
				short yv = y * v;

				for(int x = 0; x < 8; x++ ){
					short xu = x * u;

					tmp_out += in_tmp[x][y] * tb_short[ (yv + xu) % SIZE ];

				}// for loop of y

			}// for loop of x

			out[u][v] = (float)tmp_out / 2024.0;

		}// for loop of u
	}// for loop of v

}
