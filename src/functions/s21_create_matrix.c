#include "../s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int answer = OK;
  if (rows < 1 || columns < 1) {
    answer = MATRIX_ERROR;
  } else {
    result->rows = rows;
    result->columns = columns;
    result->matrix = (double **)calloc(rows, sizeof(double **));
    if (!result->matrix) {
      answer = MATRIX_ERROR;
    } else {
      int memory_allocated = 1;
      for (int i = MATRIX_INDEX; i < rows && memory_allocated; ++i) {
        result->matrix[i] = (double *)calloc(columns, sizeof(double *));
        if (!(result->matrix)[i]) {
          memory_allocated = 0;
          answer = MATRIX_ERROR;
        }
      }
    }
  }
  return answer;
}