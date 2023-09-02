#include <iostream>
int** transposeMatrix(int** mat, int dM, int dN) {
   int** tMat = new int*[dN];
   for (int i = 0; i < dN; ++i) {
      *(tMat + i) = new int[dM];
   }
   for (int i = 0; i < dM; ++i) {
      for (int j = 0; j < dN; ++j) {
	 tMat[j][i] = mat[i][j];
      }
   }
   return tMat;
}

void printMatrix(int** mat, int dimM, int dimN) {
   for (int i = 0; i < dimM; ++i) {
      for (int j = 0; j < dimN; ++j) {
	 std::cout << mat[i][j] << " ";
      }
      std::cout << std::endl;
   }
   std::cout << std::endl;
}

int** fillMatrix(int dimM, int dimN) {
   int** mat = new int*[dimM];
   for (int i = 0; i < dimM; ++i) {
      *(mat + i) = new int[dimN];
   }
   for (int i = 0; i < dimM; ++i) {
      for (int j = 0; j < dimN; ++j) {
	 mat[i][j] = std::rand() % 100;
      }
   }
   return mat;
}

int main() {
   int m = 10, n = 2;
   int** mat = fillMatrix(m, n);
   printMatrix(mat, m, n);
   mat = transposeMatrix(mat, m, n);
   printMatrix(mat, n, m);
   return 0;
}
