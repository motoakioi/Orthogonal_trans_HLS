#include <iostream>

#include "slant.h"

void slant_sw( int in[SIZE2], float out[SIZE2] ){

	short in_tmp[SIZE2];

//#pragma HLS ALLOCATION instances=fadd limit=8 operation
//#pragma HLS ALLOCATION instances=fmul limit=8 operation

	for ( int index = 0; index < SIZE2; index++ ){
		in_tmp[index] = in[index];
	}
	std::cout << "begin " << std::endl;

	for ( int v = 0; v < 8; v++ ){
		for ( int u = 0; u < 8; u++ ){
			int tmp_y = 0.0;

			for ( int y = 0; y < 8; y++ ){
				short tmp_x = 0;

				for ( int x = 0; x < 8; x++ ){
					//tmp_x += in_tmp[ x + y * 8 ] * slant_tb[x][u] >> 8;
					//tmp_x += in_tmp[ x + y * 8 ] * slant_tb[u][x] >> 8;
					tmp_x += in_tmp[ y + x * 8 ] * slant_tb[u][x];

				} // for loop of x

				//tmp_y += tmp_x * slant_tb[y][v] >> 8;
				tmp_y +=  tmp_x * slant_tb[v][y];

			} // for loop of y

			out[u + v * 8] = (float)tmp_y / 256.0 / 256.0 ;
		} // for loop of u
	} // for loop of v
	std::cout << "end " << std::endl;

}
