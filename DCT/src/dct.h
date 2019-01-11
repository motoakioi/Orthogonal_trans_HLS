#ifndef DCT_H
#define DCT_H

#define sqrt2 1.4142
#define SIZE 8

/*static const float cos_tb[8][8] = { //[x,y][u,v]
		1.0,  0.980785, 0.92388,   0.83147,   0.707107,  0.55557,   0.382683,  0.19509,
		1.0,  0.83147,  0.382683, -0.19509,  -0.707107, -0.980785, -0.92388,  -0.55557,
		1.0,  0.55557, -0.382683, -0.980785, -0.707107,  0.19509,   0.92388,   0.83147,
		1.0,  0.19509, -0.92388,  -0.55557,   0.707107,  0.83147,  -0.382683, -0.980785,
		1.0, -0.19509, -0.92388,   0.55557,   0.707107, -0.83147,  -0.382683,  0.980785,
		1.0, -0.55557, -0.382683,  0.980785, -0.707107, -0.19509,   0.92388,  -0.83147,
		1.0, -0.83147,  0.382683,  0.19509,  -0.707107,  0.980785, -0.92388,   0.55557,
		1.0, -0.980785, 0.92388,  -0.83147,   0.707107, -0.55557,   0.382683, -0.19509
};*/

static const short cos_tb[SIZE][SIZE] = { //[x,y][u,v], >> 8 
	256,  251,  236,  212,  181,  142,   97,   49, 
	256,  212,   97,  -49, -181, -251, -236, -142, 
	256,  142,  -97, -251, -181,   49,  236,  212, 
	256,   49, -236, -142,  181,  212,  -97, -251, 
	256,  -49, -236,  142,  181, -212,  -97,  251, 
	256, -142,  -97,  251, -181,  -49,  236, -212, 
	256, -212,   97,   49, -181,  251, -236,  142, 
	256, -251,  236, -212,  181, -142,   97,  -49
};

void dct_hw( int[64], float[64] );

#endif
