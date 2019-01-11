#include <iostream>
//#include <math.h>

#include "hadamard.h"

void hadamard_sw( int in[SIZE][SIZE], float out[SIZE][SIZE] ){

	int in_tmp[SIZE][SIZE];

	for ( int v = 0; v < 8; v++ ){
			for ( int u = 0; u < 8; u++ ){
				in_tmp[u][v] = in[u][v];
			}
	}

	for ( int v = 0; v < 8; v++ ){
		for ( int u = 0; u < 8; u++ ){

			int tmp_y = 0.0;

			for ( int y = 0; y < 8; y++ ){

				int tmp_x = 0.0;

				for ( int x = 0; x < 8; x++ ){

					tmp_x += in_tmp[x][y] * hadamard_tb[x][u];

//					std::cout << tmp_x << ", ";
				} // for loop of x

				tmp_y += tmp_x * hadamard_tb[y][v];
			} // for loop of y

			std::cout << "out : " << tmp_y << std::endl;
			out[u][v] = (float)tmp_y / SIZE ;


		} // for loop of u
	} // for loop of v

}
