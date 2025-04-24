#pragma once
class Robot
{
    protected:
    int energy;
    
    public:
    virtual void work()=0;
    Robot(int energy_);
    Robot();
    ~Robot();
    void SetEnergy(int energy_);
    bool IsEnergy();
};

class CleaningRobot : virtual public Robot
{
    public:
    CleaningRobot();
    ~CleaningRobot();
    void work();
};

class ConstructionRobot : virtual public Robot 
{
    public:
    ConstructionRobot(int e) : Robot(e){};
    ConstructionRobot();
    ~ConstructionRobot();
    void work();
};

class FermerRobot : virtual public Robot 
{
    public:
    FermerRobot(int e) : Robot(e){};
    FermerRobot();
    ~FermerRobot();
    void work();
};

class ExplorerRobot : virtual public Robot 
{
    public:
    ExplorerRobot();
    ~ExplorerRobot();
    void work();
    virtual void ColectData();

};

class SpaceExplorer : public ExplorerRobot
{
    public:
    SpaceExplorer();
    ~SpaceExplorer();
    void work();
    void work(std::string place);
    void ColectData();
    virtual void Move();
    void Move(std::string place);
};

class MarsExplorer : public SpaceExplorer
{
    public:
    MarsExplorer();
    ~MarsExplorer();
    void work();
    void ColectData();
    void Move();
    void deployRover();
};

class FarmBuilder : public FermerRobot, public ConstructionRobot
{
    public:
    FarmBuilder();
    ~FarmBuilder();
    void work()override;

};

class UniversalRobot : public CleaningRobot, public FermerRobot, public ConstructionRobot
{
    public:
    UniversalRobot(int energy_);
    ~UniversalRobot();
    void work() override { 
        CleaningRobot::work();
        FermerRobot::work();
        ConstructionRobot::work();}
};  