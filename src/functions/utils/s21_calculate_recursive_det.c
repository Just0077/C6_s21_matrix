#include "../../s21_matrix.h"

double s21_calculate_recursive_det(matrix_t* A) {
  double result = 0;
  int size = A->rows;
  if (size == 1) {
    result = A->matrix[MATRIX_INDEX][MATRIX_INDEX];
  } else if (size == 2) {
    result = A->matrix[MATRIX_INDEX][MATRIX_INDEX] *
                 A->matrix[MATRIX_INDEX + 1][MATRIX_INDEX + 1] -
             A->matrix[MATRIX_INDEX][MATRIX_INDEX + 1] *
                 A->matrix[MATRIX_INDEX + 1][MATRIX_INDEX];
  } else {
    int sign = 1;
    matrix_t tmp = {};
    s21_create_matrix(size - 1, size - 1, &tmp);
    for (int i = MATRIX_INDEX; i < size; ++i) {
      s21_remove_matrix_order(A, &tmp, 0, i);
      result += sign * A->matrix[0][i] * s21_calculate_recursive_det(&tmp);
      sign *= -1;
    }
    s21_remove_matrix(&tmp);
  }
  return result;
}