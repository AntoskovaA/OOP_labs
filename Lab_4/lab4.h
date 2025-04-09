#ifndef LAB4_H
#define LAB4_H


class Robot
{
    protected:
    int energy;
    
    public:
    virtual void work()=0;
    Robot(int energy_);
    Robot();
    void SetEnergy(int energy_);
    bool IsEnergy();
};

class CleaningRobot : public Robot
{
    public:
    CleaningRobot(int e) : Robot(e){};
    void work();
};

class ConstructionRobot : public Robot 
{
    public:
    ConstructionRobot(int e) : Robot(e){};
    void work();
};

class FermerRobot : public Robot 
{
    public:
    FermerRobot(int e) : Robot(e){};
    void work();
};

class ExplorerRobot : public Robot 
{
    public:
    ExplorerRobot() : Robot(100){};
    void work();
    virtual void ColectData();

};

class SpaceExplorer : public ExplorerRobot
{
    public:
    SpaceExplorer() : ExplorerRobot(){ };
    void work();
    void ColectData();
    virtual void Move();
};

class MarsExplorer : public SpaceExplorer
{
    public:
    MarsExplorer(): SpaceExplorer(){};
    void work();
    void ColectData();
    void Move();
    void deployRover();
};
#endif