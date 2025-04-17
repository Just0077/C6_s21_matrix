#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define OK 0
#define MATRIX_ERROR 1
#define CALCULATION_ERROR 2

#define SUCCESS 1
#define FAILURE 0

#define MATRIX_INDEX 0
#define EPS 1e-7
#define POSITIVE_INF 1.0 / 0.0
#define NEGATIVE_INF -1.0 / 0.0

#define diff(x, y) (fabs(x - y) <= EPS)
#define is_inf(x) (x == POSITIVE_INF || x == NEGATIVE_INF)
#define is_nan(x) (x != x)
#define is_incorrect_value(x) (is_nan(x) || is_inf(x))

typedef struct matrix_struct {
  double** matrix;
  int rows;
  int columns;
} matrix_t;

int s21_arithmetic_matrix(matrix_t* A, matrix_t* B, matrix_t* result,
                          char sign);
void s21_remove_matrix_order(matrix_t* A, matrix_t* tmp, int row, int column);
int s21_is_correct_matrix(matrix_t* A);
void s21_print_matrix(matrix_t A);
double s21_calculate_recursive_det(matrix_t* A);
int s21_alone_transpose(matrix_t* A);
int s21_alone_mult_number(matrix_t* A, double number);
void s21_calc_wo_create(matrix_t* A, matrix_t* result);

int s21_create_matrix(int rows, int columns, matrix_t* result);
void s21_remove_matrix(matrix_t* A);
int s21_eq_matrix(matrix_t* A, matrix_t* B);
int s21_sum_matrix(matrix_t* A, matrix_t* B, matrix_t* result);
int s21_sub_matrix(matrix_t* A, matrix_t* B, matrix_t* result);
int s21_mult_number(matrix_t* A, double number, matrix_t* result);
int s21_mult_matrix(matrix_t* A, matrix_t* B, matrix_t* result);
int s21_transpose(matrix_t* A, matrix_t* result);
int s21_determinant(matrix_t* A, double* result);
int s21_calc_complements(matrix_t* A, matrix_t* result);
int s21_inverse_matrix(matrix_t* A, matrix_t* result);
