#include <iostream>
#include <stdio.h>
#include "Lab_1.h"

using namespace std;


int main() {

    FILE *my_file = fopen("my_file.txt", "r+");

    struct money ALL = {0, 0};

    int grn, num;
    short int cop;

    if (my_file) {

        while (fscanf(my_file, "%d %d %d", &grn, &cop, &num) == 3) {
            money one_thing = {grn, cop};
            money things_total = Mult(one_thing, num);
            ALL = Sum(ALL, things_total);
            
        }
        fclose(my_file);
    }
    else {  cout << "Помилка відкриття файлу";
        return 1; }

    cout << "Загальна сума чеку: ";

    PrintRes(ALL);

    ALL = Round(ALL); 
    cout << "Сума до оплати після заокруглення: ";
    
    PrintRes(ALL);   
    
    return 0; }