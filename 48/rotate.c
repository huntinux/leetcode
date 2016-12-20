/*
顺时针旋转图像90度， 可以分解成：先按照对角线（从左下到右上）交换，再按照水平线交换
*/

void swap(int* m, int *n) {

	int t = *m;

	*m = *n;

	*n = t;

}





void rotate(int** matrix, int matrixRowSize, int matrixColSize) {

	int n = matrixRowSize < matrixColSize ? matrixRowSize : matrixColSize;

	for(int i = 0; i < n - 1; i++) {

		for(int j = 0; j < n - i - 1; j++) {

			swap(&matrix[i][j], &matrix[n - j - 1][n - i - 1]);

		}

	}    

	for(int i = 0; i < n / 2; i++) {

		for(int j = 0; j < n; j++) {

			swap(&matrix[i][j], &matrix[n - i - 1][j]);

		}

	}

}
