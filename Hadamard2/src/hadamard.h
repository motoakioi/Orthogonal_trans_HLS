#ifndef HADAMARD_H
#define HADAMARD_H

#define SIZE 8
#define SIZE2 64
#define LEVEL1_SIZE 4
#define LEVEL2_SIZE 2
#define LEVEL3_SIZE 1

static const int hadamard_tb[SIZE][SIZE] = {
	{ 1,  1,  1,  1,  1,  1,  1,  1},
	{ 1, -1,  1, -1,  1, -1,  1, -1},
	{ 1,  1, -1, -1,  1,  1, -1, -1},
	{ 1, -1, -1,  1,  1, -1, -1,  1},
	{ 1,  1,  1,  1, -1, -1, -1, -1},
	{ 1, -1,  1, -1, -1,  1, -1,  1},
	{ 1,  1, -1, -1, -1, -1,  1,  1},
	{ 1, -1, -1,  1, -1,  1,  1, -1}
};

void hadamard_hw( int[SIZE2], float[SIZE2] );
void hadamard_sw( int[SIZE][SIZE], float[SIZE][SIZE] );

#endif
