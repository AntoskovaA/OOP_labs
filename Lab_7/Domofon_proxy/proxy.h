#pragma once
#include <string>

class Visitor;

class IDoor {
    public:
    virtual void interact(Visitor& visitor) = 0;
};

class Resident : public IDoor {
    private:
    std::string name;

    public:
    Resident(std::string name_);
    void interact(Visitor& visitor) override;
};

class IntercomeProxy : public IDoor {
    private:
    Resident* resident;
    public:
    IntercomeProxy(Resident* resid);
    void interact(Visitor& visitor) override;
};

class Visitor {
    private:
    std::string name;
    std::string type;
    public:
    Visitor (std::string v_name, std::string v_type);
    void requestAccess(IDoor& door);
    std::string GetName();
    std::string GetType();
};