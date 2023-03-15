#pragma once

#include <iostream>

using namespace std;

class Car{
    private:
        int power;
        float weight;
        string tab;
        char type_engine;
    public:
        Car(string,int,float,char);
        Car(){};
        void displayCarNamePower();
        int getPower();
        float getWeight();
        
        friend bool operator<(const Car& a, const Car& b);
        friend bool operator==(const Car& a, const Car& b);
};

bool operator<(const Car& a, const Car& b) {
    if (a.power == b.power) return a.weight < b.weight;
    else return a.power < b.power;
}

bool operator==(const Car& a, const Car& b) {
    return (a.power == b.power && a.weight == b.weight && a.tab == b.tab && a.type_engine == b.type_engine);
}

Car::Car(string t,int p,float w,char ta)
: tab(t), power(p), weight(w), type_engine(ta) 
{
    //cout<<"siema "<<t;
}
void Car::displayCarNamePower()
{
    cout<<tab<<" "<<power<<" "<<weight<< " " << type_engine;
}
int Car::getPower()
{
     return power;
        
}
float Car::getWeight()
{
      return weight;
        
}