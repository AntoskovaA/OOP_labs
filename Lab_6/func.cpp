
#include <iostream>
#include "lab6.h"
using namespace std;

auto f = [](double x){
    return 0.25 * (x * x) + x - 1.2502;
};

void Dyhotomia::setData(double val_a, double val_b, double val_eps)
{
    a = val_a;
    b = val_b;
    eps = val_eps;
}
double Dyhotomia::showRoot () {
    return end_root;
}


void Dyhotomia::EndRoot()
{
    if ((f(a) * f(b)) > 0) {
        cout << "There are no roots in this interval. Bye" << endl;
        return; 
    }

    while (abs(b - a) > eps) 
    {
        c = (a + b) / 2;

        if (f(a) * f(c) < 0) {
            b = c; 
        }
        else {
            a = c; 
        }

        if (f(c) == 0) {
            break; 
        }
    }
    end_root =(a + b ) / 2;
    cout << end_root << " is the root!!" <<endl << "the end!!"<< endl;
}

void NewtonsMethod::Solution() 
{
    auto dx = [](double x, double eps) {
        return (f(x + eps) - f(x)) / eps;
    };

    int count = 0, max_count = 30;

    if(dx(Xn, 1e-6)) {
        next_X = Xn - (f(Xn) / dx(Xn, 1e-6)); 
    }
    else {
        cout << "pohidna = zero and it is bad" << endl;
        return; 
    }

    while (abs (next_X - Xn) > tochnist && count < max_count)
    {
        Xn = next_X;

        if(dx(Xn, 1e-6)) {
            next_X = Xn - (f(Xn) / dx(Xn, 1e-6)); }
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
        cout << Xn << " is the root" << endl; 
    }
}

void NewtonsMethod::setdata (double val_Xn, double val_toch) 
{
    Xn = val_Xn;
    tochnist = val_toch;
}