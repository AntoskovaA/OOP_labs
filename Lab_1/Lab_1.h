#ifndef LAB_1_H
#define LAB_1_H

struct money {
    int grn;
    short int cop;
};

struct money Sum(struct money c1, struct money c2);

struct money Mult(struct money c, int num);

struct money Round(struct money c);

void PrintRes(struct money some);

#endif