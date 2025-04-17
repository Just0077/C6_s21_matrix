#include "../../s21_matrix.h"

int s21_alone_transpose(matrix_t* A) {
  int answer = OK;
  if (A == NULL || s21_is_correct_matrix(A)) {
    answer = MATRIX_ERROR;
  } else {
    int rows = A->rows;
    int columns = A->columns;
    for (int i = MATRIX_INDEX; i < rows; ++i) {
      for (int j = i + 1; j < columns; ++j) {
        double temp = A->matrix[i][j];
        A->matrix[i][j] = A->matrix[j][i];
        A->matrix[j][i] = temp;
      }
    }
  }
  return answer;
}