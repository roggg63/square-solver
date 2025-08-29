#include "utilits.h"
#include "constants.h"
#include <math.h>
#include <assert.h>


//Файл с функцими, решающими квадратное уравнение с заданными коэффициентами//


double disc (const double a, const double b, const double c) {
    //Функция вычисления дискриминанта//
    const double d = b * b - 4 * a * c;
    return d;
}


int roots_quadratic (const double a, const double b, const double c, double* const ans1, double* const ans2) {
    //функция для решения квадратного уравнения//

    int count = error;

    assert (ans1 != NULL);
    assert (ans2 != NULL);

    if (compare(c, 0) == 1) {
        count = 2;
        *ans2 = -b / a;
    }
    else {

        const double d = disc (a, b, c);

        if (compare (d, 0) == 1) {
            double x = 0;
            x = -b / (2 * a);

            *ans1 = x;

            count = 1;
        }
        else if (d < 0) {
            count = 0;
        }
        else if (d > 0) {
            double x1 = 0;
            double x2 = 0;

            const double d_sqrt = sqrt(d);

            x1 = (-b + d_sqrt) / (2 * a);
            x2 = (-b - d_sqrt) / (2 * a);

            *ans1 = x1;
            *ans2 = x2;

            count = 2;
        }
    }
    return count;
}


int roots_liner (const double a, const double b, const double c, double* const ans1, double* const ans2) {
    //Функция для решения линейного уравнения//

    assert (ans1 != NULL);
    assert (ans2 != NULL);

    int count = error;

    if (compare (b, 0) == 1) {
            if (compare (c, 0) == 1) {
                count = infinity_roots;
            }
            else {
                count = 0;
            }
    }
    else {
        if (compare (c, 0) == 1) {
            *ans1 = 0;
            count = 1;
            }
        else {
            *ans1 = -c/b;
            count = 1;
        }
    }
    return count;
}


int solve_equation (const double a, const double b, const double c, double* const ans1, double* const ans2) {
    //Функция для разделения случаев решения квадратного и линейного уравнений//

    assert (ans1 != NULL);
    assert (ans2 != NULL);

    int count = error;

    if (compare (a, 0) == 1) {
        count = roots_liner (a, b, c, ans1, ans2);
    }
    else {
        count = roots_quadratic (a, b, c, ans1, ans2);
    }
    return count;
}
