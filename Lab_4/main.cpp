#include <iostream>
#include "lab4.h"
using namespace std;

int main()
{
    FermerRobot *farmer = new FermerRobot(0);
    MarsExplorer *marsRobot = new MarsExplorer;

    farmer->work();
    farmer->SetEnergy(68);
    farmer->work();
    marsRobot->ColectData();
    marsRobot->deployRover();

    delete farmer;
    delete marsRobot;
    return 0;
}