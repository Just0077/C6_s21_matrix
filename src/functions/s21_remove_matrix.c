#include "../s21_matrix.h"

void s21_remove_matrix(matrix_t* A) {
  for (int i = MATRIX_INDEX; i < A->rows; ++i) {
    free(A->matrix[i]);
  }
  free(A->matrix);
}