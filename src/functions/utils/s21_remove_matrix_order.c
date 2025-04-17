#include "../../s21_matrix.h"

void s21_remove_matrix_order(matrix_t* A, matrix_t* tmp, int row, int column) {
  int size_A = A->columns;
  int size_tmp = tmp->rows;
  int tmp_i = 0;
  int tmp_j = 0;
  for (int i = MATRIX_INDEX; i < size_A; ++i) {
    for (int j = MATRIX_INDEX; j < size_A; ++j) {
      if (j != column && i != row) {
        tmp->matrix[tmp_i][tmp_j++] = A->matrix[i][j];
        if (tmp_j == size_tmp) {
          ++tmp_i;
          tmp_j = 0;
        }
      }
    }
  }
}