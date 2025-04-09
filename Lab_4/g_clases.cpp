#include <iostream>
#include <string>
#include "lab4.h"
using namespace std;
Robot::Robot(){ 
    energy = 0; }

Robot::Robot(int energy_){
    energy = energy_;
}

void Robot::SetEnergy(int energy_) {
    cout << "Робот заряджається.... заряджається... Зарядився." << endl;
    energy = energy_;
}

bool Robot::IsEnergy() {
    if (energy > 15) {
        return true;
    }
    else {
        cout << "Зарядіть робота спочатку!" << endl; return false;
    } 
}

void CleaningRobot::work() 
{
    if (IsEnergy()) {
        cout << "Прибиральник шось там прибирає..."<< endl;
    }
    else  return; 
}

void ConstructionRobot::work() 
{
    if (IsEnergy()) {
        cout << "Робот-будівельник переносить важкі матеріали... складає... будує шось..." << endl;
    }
    else  return; 
}

void FermerRobot::work() 
{
    if (IsEnergy()) {
        cout << "Робо-фермер обробляє поле... копає грядки... треба ж картоплю садити..." << endl;
    }
    else  return; 
}

void ExplorerRobot::work() {
    cout << "Роботик працює, досліджує щось цікавеньке\n";
}

void ExplorerRobot::ColectData() {
    cout << "Дослідник збирає всякі дані про свої експерименти\n";
}

void SpaceExplorer::work(){
    cout << "Чувак досліджує шось класне в космосі\n"; 
}

void SpaceExplorer::ColectData() {
    cout << "Дослідник збирає дані про якесь космічне тіло.\n";
}

void SpaceExplorer::Move() {
    cout << "Важний роботик летить до далекої планети у космосі. Нам же треба її дослідити\n";
}

void MarsExplorer::deployRover() {
    cout << "Дослідник Марса випускає марсохід на поверхню.\n";
}

void MarsExplorer::ColectData() {
    cout << "Робот збирає дані про поверхню Марса, робить експерименти з різними речовинами" << endl;
}

void MarsExplorer::Move() {
    cout << "Дослідник Марса рухається кудись по поверхні планети. Десь в іншому місці тоже треба покопатись\n";
}

void MarsExplorer::work() {
    cout << "Чувак досліджує Марс. То нелегка робота\n";
}