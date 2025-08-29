#ifndef TEST_H
#define TEST_H

struct data_test{
    double a, b, c;
    int n_roots_ref;
    double x1_ref, x2_ref;
};


int run_tests (int* const all_tests);
int test (data_test test);

#endif
