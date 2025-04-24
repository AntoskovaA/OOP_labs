#include <iostream>
#include <string>
#include "lab5.h"
using namespace std;

Robot::Robot(){ 
    energy = 0; 
    cout << "Робот\n";
}

Robot::Robot(int energy_){
   energy = energy_;
   cout << "Робот\n";
}

Robot::~Robot() {
    std::cout << "роботт\n";
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

ConstructionRobot::ConstructionRobot() { cout << "Робот будівельник\n";}

ConstructionRobot::~ConstructionRobot() { cout << "робот будівельник\n";}

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
CleaningRobot::CleaningRobot(){ std::cout << "Прибиральник\n"; }

CleaningRobot::~CleaningRobot(){ std::cout << "прибиральник\n"; }

FermerRobot::FermerRobot() { cout << "Робо Фермер\n"; }

FermerRobot::~FermerRobot() { cout << "робо фермер\n"; }

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

ExplorerRobot::ExplorerRobot() {std::cout << "Дослідник\n";}

ExplorerRobot::~ExplorerRobot() {std::cout << "дослідник\n";}

void SpaceExplorer::work(){
    cout << "Чувак досліджує шось класне в космосі\n"; 
}

void SpaceExplorer::work(string place){
    cout << "Чувак досліджує " << place << " в космосі\n"; 
}

void SpaceExplorer::ColectData() {
    cout << "Дослідник збирає дані про якесь космічне тіло.\n";
}

void SpaceExplorer::Move() {
    cout << "Важний роботик летить до далекої планети у космосі. Нам же треба її дослідити\n";
}

void SpaceExplorer::Move(string place) {
    cout << "Важний роботик летить " << place << " у космосі. Нам же треба її дослідити\n";
}

SpaceExplorer::SpaceExplorer() { std::cout << "Дослідник космоса\n"; }

SpaceExplorer::~SpaceExplorer() { std::cout << "дослідник космоса\n"; }

MarsExplorer::MarsExplorer() { std::cout << "Марс Дослідник\n";}

MarsExplorer::~MarsExplorer() { std::cout << "марс дослідник \n";}

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

UniversalRobot::~UniversalRobot() { std::cout << "нніверсальний робо-чувак\n";}

UniversalRobot::UniversalRobot(int energy_) : Robot(energy_) { std::cout << "Універсальний Робо-Чувак\n";}

void FarmBuilder::work() {
    cout << "чувак будує там стіни, може загородки для тварин для майбутньої ферми\n";
}

FarmBuilder::FarmBuilder() {
    cout << "фрам білдер\n";
}

FarmBuilder::~FarmBuilder() {
    cout << "фарм білдер пока\n";
}