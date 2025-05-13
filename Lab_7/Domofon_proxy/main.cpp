#include <iostream>
#include <string>
#include "proxy.h"

using namespace std;

int main() {
    Resident res("Аліна");
    IntercomeProxy proxy(&res);

    Visitor Andriy("Андрій", "майстер по інтернету");
    Andriy.requestAccess(proxy);
    return 0;
}