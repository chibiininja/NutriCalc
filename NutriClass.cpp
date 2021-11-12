//Created by Kavitha, Darren, Evan, and Julianna

#include <iostream>
using namespace std;

//Nutrient class to keep track of nutrients in each food
class nutrients{
public:
    //constructors
    nutrients(): name(" "), measure(0), protein(0), carbohydrate(0), dietaryFiber(0), fat(0), calcium(0), iron(0), potassium(0), magnesium(0), VitA(0){}
    nutrients(string n, double m, double p, double c, double d, double f, double ca, double i, double po, double ma, double a): name(n), measure(m), protein(p), carbohydrate(c), dietaryFiber(d), fat(f), calcium(ca), iron(i), potassium(po), magnesium(ma), VitA(a) {}

    //setter and getter methods
    void setName(string n){ name = n;}
    string getName(){return name;}

    void setMeasure(double m){ measure = m;};
    double getMeasure(){return measure;}

    void setProtein(double p){ protein = p;};
    double getProtein(){return protein;}

    void setCarbohydrate(double c){ carbohydrate = c;};
    double getCarbohydrate(){return carbohydrate;}

    void setDietaryFiber(double d){dietaryFiber = d;};
    double getDietaryFiber(){return dietaryFiber;}

    void setFat(double f){fat = f;};
    double getFat(){return fat;}

    void setCalcium(double ca){ calcium = ca;};
    double getCalcium(){return calcium;}

    void setIron(double i){ iron = i;};
    double getIron(){return iron;}

    void setPotassium(double p){ potassium = p;};
    double getPotassium(){return potassium;}

    void setMagnesium(double m){ magnesium = m;};
    double getMagnesium(){return magnesium;}

    void setVitA(double a){ VitA = a;};
    double getVitA(){return VitA;}

protected: //accessable by derived classes
    string name;
    double measure;

    //nurtrient values
    double protein;//51000 mg
    double carbohydrate;//275000 mg
    double dietaryFiber;//27500 mg
    double fat;//60500 mg
    double calcium;//1250 mg
    double iron;//17 mg
    double potassium;//4700 mg
    double magnesium;//250 mg
    double VitA;//0.9 mg
};
