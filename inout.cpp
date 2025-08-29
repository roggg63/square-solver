#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "constants.h"

//Файл с функциями для ввода и вывода данных//


void scanning_equation_coefficients (double* const a, double* const b, double* const c) {
    //Функция для ввода//

    assert (a != NULL);
    assert (b != NULL);
    assert (c != NULL);

    printf ("ПРОГРАММА ДЛЯ РЕШЕНИЯ КВАДРАТНЫХ УРАВНЕНИЙ\n");

    int correct_input = 0;

    while (correct_input != 1) {
        printf("Введите три числа - коэффициенты уравнения через пробел:\n");

        int res = scanf ("%lg %lg %lg", a, b, c);

        if (res == 3) {
            correct_input = 1;
        }
        else {
            const int input_char = getchar ();

            if (input_char == EOF) {
                printf ("Программа завершена\n");
                break;
            }
            else {
                while (getchar() != '\n');

                printf ("%sНекорректный ввод!!!%s\n", colour_red, base_style);
            }
        }
    }
}


void equation_answer (const int n_roots, double* const ans1, double* const ans2) {
    //Функция для вывода//

    assert (ans1 != NULL);
    assert (ans2 != NULL);

    if (n_roots == error) {
        printf ("%sОшибка%s\n", colour_red, base_style);
    }
    else if (n_roots == infinity_roots) {
        printf ("%sУ уравнения бесконечное количество решений%s\n", colour_green, base_style);
    }
    else if (n_roots == 0) {
        printf ("%sУ уравнения нет решений%s\n", colour_green, base_style);
    }
    else if (n_roots == 1) {
        printf ("%sУ уравнения один корень: %lg%s\n", colour_green, *ans1, base_style);
    }
    else if (n_roots == 2) {
        printf ("%sУ уравнения два корня: x1 = %lg, x2 = %lg%s\n", colour_green, *ans1, *ans2, base_style);
    }
}
