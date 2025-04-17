#include "../../s21_matrix.h"

int s21_alone_mult_number(matrix_t* A, double number) {
  int answer = OK;
  int rows = A->rows;
  int columns = A->columns;
  for (int i = MATRIX_INDEX; i < rows && !answer; ++i) {
    for (int j = MATRIX_INDEX; j < columns && !answer; ++j) {
      if (is_incorrect_value(A->matrix[i][j])) {
        answer = CALCULATION_ERROR;
      } else {
        A->matrix[i][j] = A->matrix[i][j] * number;
      }
    }
  }
  return answer;
}