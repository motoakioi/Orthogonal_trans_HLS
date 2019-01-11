#ifndef DCT_SW_H
#define DCT_SW_H

#define sqrt2 1.4142
#define SIZE 8

static const double cos_tb_sw[8][8] = { //[x,y][u,v]
		1.0,  0.980785, 0.92388,   0.83147,   0.707107,  0.55557,   0.382683,  0.19509,
		1.0,  0.83147,  0.382683, -0.19509,  -0.707107, -0.980785, -0.92388,  -0.55557,
		1.0,  0.55557, -0.382683, -0.980785, -0.707107,  0.19509,   0.92388,   0.83147,
		1.0,  0.19509, -0.92388,  -0.55557,   0.707107,  0.83147,  -0.382683, -0.980785,
		1.0, -0.19509, -0.92388,   0.55557,   0.707107, -0.83147,  -0.382683,  0.980785,
		1.0, -0.55557, -0.382683,  0.980785, -0.707107, -0.19509,   0.92388,  -0.83147,
		1.0, -0.83147,  0.382683,  0.19509,  -0.707107,  0.980785, -0.92388,   0.55557,
		1.0, -0.980785, 0.92388,  -0.83147,   0.707107, -0.55557,   0.382683, -0.19509
};

void dct_sw( double[8][8], double[8][8] );

#endif
