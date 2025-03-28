#include "lab3.h"
#include <iostream>
using namespace std;

void Dyhotomia::setData(double val_a, double val_b, double val_eps)
{
    a = val_a;
    b = val_b;
    eps = val_eps;
}

double funcValue(double x)
{
    return 0.25 * (x * x) + x - 1.2502;
}

double NewtonsMethod::Pohidna(double x, double eps)
{
    return (funcValue(x + eps) - funcValue(x)) / eps;
}

void Dyhotomia::EndRoot()
{
    if ((funcValue(a) * funcValue(b)) > 0) {
        cout << "There are no roots in this interval. Bye";
        return; 
    }

    while (abs(b - a) > eps) 
    {
        c = (a + b) / 2;

        if (funcValue(a) * funcValue(c) < 0) {
            b = c; 
        }
        else {
            a = c; 
        }

        if (funcValue(c) == 0) {
            break; 
        }
    }
    end_root =(a + b ) / 2;
    cout << end_root << " is the root!!" <<endl << "the end!!"<< endl;
}

void NewtonsMethod::Solution() 
{
    int count = 0, max_count = 30;

    if(Pohidna(Xn, 1e-6)) {
        next_X = Xn - (funcValue(Xn) / Pohidna(Xn, 1e-6)); 
    }
    else {
        cout << "pohidna = zero and it is bad" << endl;
        return; 
    }

    while (abs (next_X - Xn) > tochnist && count < max_count)
    {
        Xn = next_X;

        if(Pohidna(Xn, 1e-6)) {
            next_X = Xn - (funcValue(Xn) / Pohidna(Xn, 1e-6)); }
        else {
            cout << "pohidna = zero and it is bad" << endl;
            return; 
        }
        ++count;
    }

    if (count == max_count) {
        cout << "unfortunately, the method did not find the root after the given number of iterations" << endl; 
    }
    else {
        cout << "it looks like " << Xn << " is a root" << endl; 
    }
}

void NewtonsMethod::setdata (double val_Xn, double val_toch) 
{
    Xn = val_Xn;
    tochnist = val_toch;
}