#include <iostream>
#include "lab6.h"
using namespace std;

int main() 
{
    Dyhotomia my_equation;
    NewtonsMethod  my_function;
    int choice;
    double first_bound, second_bound, accuracy, first_dot, some_eps;
    
    cout << "Enter 1 for Dyhotomia or 2 for NewtonsMetod: " << endl;
    cin >> choice;
    if (choice == 1) 
    {
        cout << "Dyhotomia\nEnter the points for the interval: ";
        cin >> first_bound >> second_bound;
        cout << "Enter the accuracy: ";
        cin >> accuracy;
        if (accuracy <= 0) {
            cout << "Bad accuracy. It must be positive" << endl; 
            return 0;
        } 

        my_equation.setData(first_bound, second_bound, accuracy);
        my_equation.EndRoot();
    }
    else if (choice == 2) {
        cout << "Newtons Metod\nEnter the first Xn and epsulon: ";
        cin >> first_dot >> some_eps;
        if (some_eps <= 0) {
            cout << "Bad accuracy. It must be positive" << endl; 
            return 0;
        } 
        my_function.setdata(first_dot, some_eps);
        my_function.Solution();        
    }
    else { cout << "You enterd a wrong number(("; return 0; }
    
    return 0;
}