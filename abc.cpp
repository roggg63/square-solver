#include <stdio.h>
#include <math.h>

float disc(float a, float b, float c){
    float d;
    d = b * b - 4 * a * c;
    return d;
}
float corni(float a, float b, float c, float d){
    if(d > 0){
    float x1;
    float x2;
    x1 = (-b + sqrt(d)) / (2*a);
    x2 = (-b - sqrt(d)) / (2*a);
    printf("Первый корень %f\n", x1);
    printf("Второй корень %f\n", x2);
    }
    else if(d == 0){
    float x;
    x = -b / (2*a);
    printf("Корень %f\n", x);
    }
    else if(d < 0){
        printf("Нет действительных корней\n");
    }
    return 0;
}


int main(){
    float a, b, c, d;
    printf("Введите три целых числа, разделенных пробелами:\n");
    scanf("%f %f %f", &a, &b, &c);
    if(a == 0){
        printf("Ваше уравнение не является квадратным, его корень: %f\n", -c/b);
    }
    else{
        d = disc(a, b, c);
        corni(a, b, c, d);
    }
}
