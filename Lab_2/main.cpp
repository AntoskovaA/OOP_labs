#include <iostream>
#include <cmath>
#include "some.h"


using namespace std;

int main() {
    Point P[10];
    Triangle T1;
    int n;

    cout << "Введіть координати трикутника: " << endl << "Точка A " << endl;
    cin >> T1.A.x >> T1.A.y;
    cout << "Точка B " << endl;
    cin >> T1.B.x >> T1.B.y;
    cout << "Точка C " << endl;
    cin >> T1.C.x >> T1.C.y;

    if (T1.IsSingular() || T1.Area() < 0) {
        cout << "Такий трикутник є виродженим. Введіть інші координати";
        return 1;
    }
    
    cout << "Введіть кількість точок для перевірки: ";
    cin >> n;

    cout << "Введіть координати точок: " << endl;
    for (int i = 0; i < n; ++i) {
        cout << i+1 << " точка" << endl;
        cin >> P[i].x >> P[i].y;
    }

    for (int i = 0; i < n; ++i) {
        if(T1.IsContains(P[i])) {
            if (VectorDob(T1.A, T1.B, P[i]) == 0 || VectorDob(T1.B, T1.C, P[i]) == 0 || VectorDob(T1.C, T1.A, P[i]) == 0 ) {
                cout << "Точка "  << i+1<< " лежить на стороні трикутника" << endl;
            }
            else cout << "Точка "  << i+1<<" лежить всередині трикутника" << endl;
        }
        else cout <<"Точка "  << i+1<< " не належить трикутнику" << endl;
    }
    return 0;
}
