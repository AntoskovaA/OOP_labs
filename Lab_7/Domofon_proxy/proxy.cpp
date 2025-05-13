#include <iostream>
#include <string>
#include "proxy.h"

using namespace std;

Resident::Resident (string name_) {
    name = name_;
}

void Resident::interact(Visitor& visitor) {
    cout <<  name << " дивиться на екран домофона і бачить чувака: " << visitor.GetName() << " (" << visitor.GetType() << ")" << std::endl;
    string choice;
    cout << name <<" пустиш його чи нє? ";
    cin >> choice;
    if (choice == "да"){ cout << visitor.GetName() << " Проходь в хату." << endl; }
    else { cout << "Не хочу тебе пускати. Пока" << endl;}

}

Visitor::Visitor (std::string v_name, std::string v_type) {
    name = v_name;
    type = v_type;
}

void Visitor::requestAccess(IDoor& door) {
    cout << "Хтось якогось дива дзвонить в двері...\n";
    door.interact(*this);
    
}

std::string Visitor::GetName() {
    return name;
}
std::string Visitor::GetType() {
    return type;
}


void IntercomeProxy::interact(Visitor& visitor) {
    cout << "Прийшла людинка " << visitor.GetType() << " " << visitor.GetName() << endl;
    if (visitor.GetType() == "друг" || visitor.GetType() == "сусідка" || visitor.GetType() == "подруга" || visitor.GetType() == "мама" || visitor.GetType() == "майстер по інтернету") {
        resident->interact(visitor);
    } else {
        std::cout << "Вибач, я тебе не знаю. Не можу впустити." << std::endl;
    }
}

IntercomeProxy::IntercomeProxy (Resident* resid) {
    resident = resid;
}