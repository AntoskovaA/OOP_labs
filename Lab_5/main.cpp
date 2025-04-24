#include <iostream>
#include "lab5.h"
using namespace std;

int main()
{
    
    UniversalRobot* bot = new UniversalRobot(100);
    cout << "\n";
    bot->work();
    cout << "\n";
    cout << "Тепер вже хватить з цього робота\n";
    cout << "\n";
    cout << "Знищуємо чувака: \n";
    delete bot;
    return 0;
}