#include "lab3.h"
#include <iostream>
using namespace std;

int main() 
{
    Dyhotomia my_equation;
    NewtonsMethod  my_function;

    double first_bound, second_bound, accuracy, first_dot, some_eps;

    cout << "Enter the points for the interval: ";
    cin >> first_bound >> second_bound;
    cout << "Enter the accuracy: ";
    cin >> accuracy;

    my_equation.setData(first_bound, second_bound, accuracy);
    my_equation.EndRoot();

    cout << "Enter the first Xn and epsulon: ";
    cin >> first_dot >> some_eps;

    my_function.setdata(first_dot, some_eps);
    my_function.Solution();
    
    return 0;

}