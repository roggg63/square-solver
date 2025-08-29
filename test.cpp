#include <stdio.h>
#include <math.h>
#include <assert.h>

#include "constants.h"
#include "test.h"
#include "solve.h"
#include "utilits.h"


//Файл с unit-тестами//


int run_tests (int* const all_tests) {
    //Функция для проверки по нужным тестам//

    assert (all_tests != NULL);

    const data_test tests[] = {{.a = 1, .b = -5, .c = 6, .n_roots_ref = 2, .x1_ref = 3, .x2_ref = 2}, \
    {.a = 1, .b = 4, .c = 4, .n_roots_ref = 1, .x1_ref = -2, .x2_ref = 0}, \
    {.a = 0, .b = 0, .c = 0, .n_roots_ref = infinity_roots, .x1_ref = 0, .x2_ref = 0}, \
    {.a = 0, .b = 5, .c = 0, .n_roots_ref = 1, .x1_ref = 0, .x2_ref = 0}, \
    {.a = 0, .b = 0, .c = 7, .n_roots_ref = 0, .x1_ref = 0, .x2_ref = 0}, \
    {.a = 1, .b = 0, .c = 4, .n_roots_ref = 0, .x1_ref = 0, .x2_ref = 0}, \
    {.a = 1, .b = 0, .c = -9, .n_roots_ref = 2, .x1_ref = 3, .x2_ref = -3}, \
    {.a = 0, .b = 6, .c = -9, .n_roots_ref = 1, .x1_ref = 1.5, .x2_ref = 0}, \
    {.a = 1, .b = 8, .c = -9, .n_roots_ref = 2, .x1_ref = 1, .x2_ref = -9}, \
    {.a = 4, .b = 7, .c = -9, .n_roots_ref = 2, .x1_ref = 0.861555, .x2_ref = -2.61156}};

    int passed = 0;

    const size_t size = sizeof (tests) / sizeof (tests[0]);

    for (unsigned long i = 0; i < size; i++) {

        int test_res = test (tests[i]);

        if (test_res == 0) {
            printf ("%s%lu-й тест не пройден%s\n", colour_red, i + 1, base_style);
        }
        else {
            passed += test_res;
        }
        *all_tests += 1;
    }
    return passed;
}


int test (const data_test test) {
    //Функция для проверки конкретного теста//

    double x1 = 0, x2 = 0;

    int n_roots = solve_equation (test.a, test.b, test.c, &x1, &x2);

    if (compare (x1, test.x1_ref) == 1 && compare (x2, test.x2_ref) == 1 && n_roots == test.n_roots_ref) {
        return 1;
    }
    else {
        printf ("%sТест с коэффициентами a = %lg, b = %lg, c = %lg не пройден%s\n", colour_red, test.a, test.b, test.c, base_style);
        return 0;
    }
}
