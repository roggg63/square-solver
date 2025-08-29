#include <stdio.h>
#include "solve.h"
#include "inout.h"
#include "test.h"
#include "constants.h"

//Основная программа//


int main () {

    printf ("%sMEOW%s\n", colour_peach, base_style);

    double a = 1, b = 1, c = 1;
    double ans1 = 0, ans2 = 0;

    int correct_tests = 0;
    int all_tests = 0;

    correct_tests = run_tests (&all_tests); //проверка unit-тестов//
    printf ("Правильно выполнено %s%d%s тестов из %s%d%s\n", colour_red, correct_tests, base_style, colour_red, all_tests, base_style);

    scanning_equation_coefficients (&a, &b, &c); //ввод коэффициентов//
    int n_roots = solve_equation (a, b, c, &ans1, &ans2); //решение уравнения с заданными коэффициентами//
    equation_answer (n_roots, &ans1, &ans2); //вывод ответа для заданных коэффициентов//

    printf ("%scommit github%s\n", colour_red, base_style);
    return 0;
}



















/*
#include <stdio.h>
#include <math.h>
#include <assert.h>




// #define $_MEOW_$  printf ("%s:%d: %s()\n", __FILE__, __LINE__, __func__);


double disc(const double a, const double b, const double c){
    const double d = b * b - 4 * a * c;
    return d;
}


int compare(const double a, const double b){
    if(a < b + eps && b - eps < a){
        return 1;
    }
    else{
        return 0;
    }
}


int roots_quadratic(const double a, const double b, const double c, double* const ans1, double* const ans2){
    assert(ans1 != NULL);
    assert(ans2 != NULL);
    double d = disc(a, b, c);
    int count = error;
    if(compare(d, 0) == 1){
        double x;
        x = -b / (2*a);
        *ans1 = x;
        count = 1;
    }
    else if(d < 0){
        count = 0;
    }
    else if(d > 0){
        double x1;
        double x2;
        x1 = (-b + sqrt(d)) / (2*a);
        x2 = (-b - sqrt(d)) / (2*a);
        *ans1 = x1;
        *ans2 = x2;
        count = 2;
    }
    return count;
}


int roots_liner(const double a, const double b, const double c, double* const ans1, double* const ans2){
    assert(ans1 != NULL);
    assert(ans2 != NULL);
    int count = error;
    if(compare(b, 0) == 1){
            if(compare(c, 0) == 1){
                count = infinity_roots;
            }
            else{
                count = 0;
            }
    }
    else{
        if(compare(c, 0) == 1){
            *ans1 = 0;
            count = 1;
            }
        else{
            *ans1 = -c/b;
            count = 1;
        }
    }
    return count;
}


int solve(const double a, const double b, const double c, double* const ans1, double* const ans2){
    assert(ans1 != NULL);
    assert(ans2 != NULL);
    int count = error;
    if(compare(a, 0) == 1){
        count = roots_liner(a, b, c, ans1, ans2);
    }
    else{
        count = roots_quadratic(a, b, c, ans1, ans2);
    }
    return count;
}

void scanning(double* const a, double* const b, double* const c){
    assert(a != NULL);
    assert(b != NULL);
    assert(c != NULL);
    printf("ПРОГРАММА ДЛЯ РЕШЕНИЯ КВАДРАТНЫХ УРАВНЕНИЙ\n");
    int correct_input = 0;
    while(correct_input != 1){
        printf("Введите три числа, коэффициенты уравнения:\n");
        int res = scanf("%lg %lg %lg", a, b, c);
        if(res == 3){
            correct_input = 1;
        }
        else{
            char vvod = getchar();
            if(vvod == EOF){
                printf("Программа завершена\n");
                break;
            }
            else{
                while(getchar() != '\n');
                printf("Некорректный ввод!!!\n");
            }
        }
    }
}


void answer(const int nRoots, double* const ans1, double* const ans2){
    assert(ans1 != NULL);
    assert(ans2 != NULL);
    if(nRoots == error){
        printf("Ошибка\n");
    }
    else if(nRoots == infinity_roots){
        printf("У уравнения бесконечное количество решений\n");
    }
    else if(nRoots == 0){
        printf("У уравнения нет решений\n");
    }
    else if(nRoots == 1){
        printf("У уравнения один корень: %lg\n", *ans1);
    }
    else if(nRoots == 2){
        printf("У уравнения два корня: x1 = %lg, x2 = %lg\n", *ans1, *ans2);
    }
}



int Run_tests(int* const all_tests){
    //Функция для проверки по нужным тестам//
    int passed = 0;
    passed += Test(1, -5, 6, 2, 3, 2);
    *all_tests += 1;
    passed += Test(1, 4, 4, 1, -2, 0);
    *all_tests += 1;
    passed += Test(0, 0, 0, infinity_roots, 0, 0);
    *all_tests += 1;
    passed += Test(0, 5, 0, 1, 0, 0);
    *all_tests += 1;
    passed += Test(0, 0, 7, 0, 0, 0);
    *all_tests += 1;
    passed += Test(1, 0, 4, 0, 0, 0);
    *all_tests += 1;
    passed += Test(1, 0, -9, 2, 3, -3);
    *all_tests += 1;
    passed += Test(0, 6, -9, 1, 1.5, 0);
    *all_tests += 1;
    return passed;
}


int Test(double const a, double const b, double const c, int const nRoots_ref, double const x1_ref, double const x2_ref){
    //Функция для проверки конкретного теста//
    double x1 = 0, x2 = 0;
    int nRoots = solve(a, b, c, &x1, &x2);
    if(compare(x1, x1_ref) == 1 && compare(x2, x2_ref) == 1 && nRoots == nRoots_ref){
        return 1;
    }
    else{
        printf("Тест с коэффициентами a = %lg, b = %lg, c = %lg не пройден\n", a, b, c);
        return 0;
    }
}






*/



