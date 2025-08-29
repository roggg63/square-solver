#include "constants.h"



int compare (const double a, const double b) {
    //Функция сравнения двух чисел типа double с учетом погрешности//
    return a < b + eps && b - eps < a;
}
