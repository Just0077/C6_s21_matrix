#include "../s21_matrix.h"

int s21_mult_number(matrix_t* A, double number, matrix_t* result) {
  int answer = OK;
  if (A == NULL || s21_is_correct_matrix(A)) {
    answer = MATRIX_ERROR;
  } else if (is_incorrect_value(number)) {
    answer = CALCULATION_ERROR;
  } else {
    int rows = A->rows;
    int columns = A->columns;
    s21_create_matrix(rows, columns, result);
    for (int i = MATRIX_INDEX; i < rows && !answer; ++i) {
      for (int j = MATRIX_INDEX; j < columns && !answer; ++j) {
        if (is_incorrect_value(A->matrix[i][j])) {
          answer = CALCULATION_ERROR;
        } else {
          result->matrix[i][j] = A->matrix[i][j] * number;
        }
      }
    }
  }
  return answer;
}