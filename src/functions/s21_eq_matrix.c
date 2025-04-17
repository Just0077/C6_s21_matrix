#include "../s21_matrix.h"

int s21_eq_matrix(matrix_t* A, matrix_t* B) {
  int result = SUCCESS;
  if (!A || !B) {
    result = FAILURE;
  } else if (A->columns != B->columns || A->rows != B->rows) {
    result = FAILURE;
  } else {
    int columns = A->columns;
    int rows = A->rows;
    for (int i = MATRIX_INDEX; i < rows && result == SUCCESS; ++i) {
      for (int j = MATRIX_INDEX; j < columns && result == SUCCESS; ++j) {
        if (!diff(A->matrix[i][j], B->matrix[i][j])) {
          result = FAILURE;
        }
      }
    }
  }
  return result;
}