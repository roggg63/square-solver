#ifndef SOLVE_H
#define SOLVE_H

int solve_equation (const double a, const double b, const double c, double* const ans1, double* const ans2);
double disc (const double a, const double b, const double c);
int roots_quadratic (const double a, const double b, const double c, double* const ans1, double* const ans2);
int roots_liner (const double a, const double b, const double c, double* const ans1, double* const ans2);

#endif
