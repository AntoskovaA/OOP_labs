#include <iostream>
#include <stdio.h>
#include "Lab_1.h"

using namespace std;

 struct money Sum(struct money c1, struct money c2) {
    struct money res;
    res.grn = c1.grn + c2.grn;
    res.cop = c1.cop + c2.cop;
    if(res.cop > 99) {
        res.grn ++;
        res.cop -= 100;
    }
    return res;
 }

 struct money Mult(struct money c, int num) {
    struct money res;
    res.grn = c.grn * num;
    res.cop = c.cop * num;
    while (res.cop > 99) { 
        res.grn++;
        res.cop -= 100;
    }
    return res;
 }


 struct money Round(struct money c) {
    struct money round;
    struct money temp;
    if (c.cop %10 != 0) {
        round.grn = c.grn;
        temp.cop = 10 - c.cop % 10;
        round.cop = c.cop + temp.cop;
        if(round.cop > 99) { round.grn ++; round.cop -=100; }
        return round;
    }
    else { return c; }

 }


 void PrintRes(struct money some) {
    cout << some.grn  << " грн " << some.cop << " к.\n";

 }

