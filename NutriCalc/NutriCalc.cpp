//Created by Kavitha, Darren, Evan, and Julianna
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

#include "NutriClass.cpp"

//struct that contains food/nutrient name, amt, and units
struct DV_hold{
  string name;
  double amt;
  string units;
};

//global vectors containing suggested/reccomended foods containing healthy nutrients
vector<string> protein = { "1 egg - 6g", "1 chicken breast - 54g", "1 slice of Bacon - 3g", "pinto beans(1/2 cup) - 20.5g,", "milk(1 cup) - 8g"};
vector<string> fat = {"1 stick butter - 113000mg", "eggs - 5000mg", "salmon - 10500mg", "avacados - 23000mg", "tofu - 6000mg"};
vector<string> carbs = {"crouton", "pasta", "rice", "waffle", "ramen", "whole wheat bread"};
vector<string> dietaryFiber = { "chickpeas(1 tbsp) - 2.2g", "lentils(1tbsp) - 1g", "1 medium apple - 4.4 g", "Broccoli(1 cup chopped) - 5g", "whole wheat pasta - 7g"};
vector<string> VitA = { "1 sweet potato - 1403 mcg,", "1/2 cup spinach - 573 mcg", "raw carrots(1/2) cup - 459 mcg", "beef liver(3 oz) pan fried - 6582 mcg", "1 mango - 112 mcg"};
vector<string> iron = { "Eggs - 0.6 mg", "Chicken breast(3 oz) - 1 mg", "Tomato sauce(1 cup) - 1.9 mg", "Shrimp(3 oz) - 2.5 mg", "Cooked spinach(1 cup) - 6.5 mg"};
vector<string> potassium = {"1 medium banana - 422 mg", "Avocado(1/2) - 487 mg", "Edamame(1 cup) - 676 mg", "Butternut squash(1 cup) - 582 mg", "Rainbow-trout(1 fish) - 57mg"};
vector<string> calcium = {"Cheese - 200mg", "Yogurt - 450mg", "Almonds - 246 mg", "Milk - 300mg", "Sardines - 569mg"};
vector<string> magnesium = {"Pumpkin seed kernels(1 oz) - 168 mg", "Dry roasted almonds(1 oz) - 80 mg", "Boiled spinach(1/2 cup) - 78 mg", "Dry roasted cashews (1 oz) - 74 mg", "Cooked black beans(1/2 cup) - 60 mg"};

//
void createDVReq(vector<DV_hold> &reqDV, string file){
  vector<DV_hold>().swap(reqDV);
  ifstream in;
  in.open(file);
  string next = "";
  DV_hold temp;
  while(in >> next){
    temp.name = next;
    in >> next;
    temp.amt = stod(next);
    in >> next;
    temp.units = next;
    reqDV.push_back(temp);
  }
  in.close();
}

void writePrevious(vector<DV_hold> reqDV){
  ofstream out;
  out.open("previous.txt", ios::out | ios::trunc);
  for(int i = 0; i < reqDV.size(); i++){
    out << reqDV[i].name << " " << reqDV[i].amt << " " << reqDV[i].units << "\n";
  }
  out.close();
}

//creates the list of products that the user can input
void createInput(vector<nutrients> &list){
  ifstream in("foodinputs.txt");
  string next = "";
  nutrients temp;
  while(in >> next){
    temp.setName(next);
    in >> next;
    temp.setMeasure(stod(next));
    in >> next;
    temp.setProtein(stod(next));
    in >> next;
    temp.setCarbohydrate(stod(next));
    in >> next;
    temp.setDietaryFiber(stod(next));
    in >> next;
    temp.setFat(stod(next));
    in >> next;
    temp.setCalcium(stod(next));
    in >> next;
    temp.setIron(stod(next));
    in >> next;
    temp.setPotassium(stod(next));
    in >> next;
    temp.setMagnesium(stod(next));
    in >> next;
    temp.setVitA(stod(next));
    list.push_back(temp);
  }
  in.close();
}

//vector<DV_hold>
void DV_to_meet(nutrients input, vector<DV_hold> &c_DV){
  for (int i = 0; i < c_DV.size(); i++){
    if (c_DV[i].name == "protein"){
      c_DV[i].amt -= input.getProtein();
    }
    else if (c_DV[i].name == "carbohydrate"){
      c_DV[i].amt -= input.getCarbohydrate();
    }
    else if (c_DV[i].name == "dietaryFiber"){
      c_DV[i].amt -= input.getDietaryFiber();
    }
    else if (c_DV[i].name == "fat"){
      c_DV[i].amt -= input.getFat();
    }
    else if (c_DV[i].name == "calcium"){
      c_DV[i].amt -= input.getCalcium();
    }
    else if (c_DV[i].name == "iron"){
      c_DV[i].amt -= input.getIron();
    }
    else if (c_DV[i].name == "potassium"){
      c_DV[i].amt -= input.getPotassium();
    }
    else if (c_DV[i].name == "magnesium"){
      c_DV[i].amt -= input.getMagnesium();
    }
    else if (c_DV[i].name == "VitA"){
      c_DV[i].amt -= input.getVitA();
    }
    //subtract input values from DV values
  }
}

void print_some_elem(vector<string> input){
  for (int i = 0; i < input.size(); i++){
    cout << input[i] << ", ";
  }
  cout << endl;
}

void printSuggested(string name){
  if (name == "protein"){
    print_some_elem(protein);
  }
  else if (name == "fat"){
    print_some_elem(fat);
  }
  else if (name == "carbohydrate"){
    print_some_elem(carbs);
  }
  else if (name == "dietaryFiber"){
    print_some_elem(dietaryFiber);
  }
  else if (name == "VitA"){
    print_some_elem(VitA);
  }
  else if (name == "iron"){
    print_some_elem(iron);
  }
  else if (name == "potassium"){
    print_some_elem(potassium);
  }
  else if (name == "calcium"){
    print_some_elem(calcium);
  }
  else if (name == "magnesium"){
    print_some_elem(magnesium);
  }
}

void print_report(vector<DV_hold> c_DV){
  vector<DV_hold> to_meet;
  /*
  vector<string> protein = { "1 egg - 6g", "1 chicken breast - 54g", "1 slice of Bacon - 3g", "pinto beans(1/2 cup) - 20.5g,", "milk(1 cup) - 8g"};
  vector<string> fat = {"1 stick butter - 113000mg", "eggs - 5000mg", "salmon - 10500mg", "avacados - 23000mg", "tofu - 6000mg"};
  vector<string> carbs = {"crouton", "pasta", "rice", "waffle", "ramen", "whole wheat bread"};
  vector<string> dietaryFiber = { "chickpeas(1 tbsp) - 2.2g", "lentils(1tbsp) - 1g", "1 medium apple - 4.4 g", "Broccoli(1 cup chopped) - 5g", "whole wheat pasta - 7g"};
  vector<string> VitA = { "1 sweet potato - 1403 mcg,", "1/2 cup spinach - 573 mcg", "raw carrots(1/2) cup - 459 mcg", "beef liver(3 oz) pan fried - 6582 mcg", "1 mango - 112 mcg"};
  vector<string> iron = { "Eggs - 0.6 mg", "Chicken breast(3 oz) - 1 mg", "Tomato sauce(1 cup) - 1.9 mg", "Shrimp(3 oz) - 2.5 mg", "Cooked spinach(1 cup) - 6.5 mg"};
  vector<string> potassium = {"1 medium banana - 422 mg", "Avocado(1/2) - 487 mg", "Edamame(1 cup) - 676 mg", "Butternut squash(1 cup) - 582 mg"};
  vector<string> calcium = {"Cheese - 200mg", "Yogurt - 450mg", "Almonds - 246 mg", "Milk - 300mg", "Sardines - 569mg"};
  vector<string> magnesium = {"Pumpkin seed kernels(1 oz) - 168 mg", "Dry roasted almonds(1 oz) - 80 mg", "Boiled spinach(1/2 cup) - 78 mg", "Dry roasted cashews (1 oz) - 74 mg", "Cooked black beans(1/2 cup) - 60 mg"};
  */

  for (int i = 0; i < c_DV.size(); i++){
    if (c_DV[i].amt > 0){
      to_meet.push_back(c_DV[i]);
    }
  }
  if (to_meet.empty()){
    cout << endl << "You have met all your daily requirements!";
    return;
  }else{
    cout << endl << "You still need to meet these daily requirements: " << endl;
  }
  for (int i = 0; i < to_meet.size(); i++){
    cout << c_DV[i].name <<" "<< c_DV[i].amt << c_DV[i].units << endl;
    cout << "Some foods high in this daily value are: ";
    //report
    printSuggested(c_DV[i].name);
  }
}


void print_recommendation(vector<DV_hold> &cDV){
  vector<DV_hold> newDV;
  createDVReq(newDV, "dailyvaluerequirements.txt");
  int maxIndex = 0;
  double maxPerc = 0.0;
  double tempPerc;

  for(int i = 0; i < cDV.size(); i++){
    tempPerc = cDV[i].amt / newDV[i].amt;
    if(tempPerc > maxPerc && tempPerc > 0){
      maxIndex = i;
      maxPerc = tempPerc;
    }
  }
  if(maxPerc != 1.0) {
    cout << "The nutrient you need most currently is " + cDV[maxIndex].name << endl;
    cout << "You still need ";
    cout << cDV[maxIndex].name <<" "<< cDV[maxIndex].amt << cDV[maxIndex].units <<endl;
    cout << "Some foods high in this daily value are: " << endl;
    printSuggested(cDV[maxIndex].name);
  }
}


void userInput(vector<DV_hold> &cDV){
  //variables for user input
  string input;
  int count = 1;
  bool check = true;
  bool running = true;

  vector<nutrients> list;
  createInput(list);

  cout<<"What have you eaten so far today?\n(use '-' for spaces)\n(type RESET to start a new day)\n(type REPORT to print report)\n(type RECOMMEND to be given a food to eat)\n(type QUIT to end program)"<<endl;

  while(running){
    cout<<"Item "<<count<<": "<<endl;
    cin>>input;
    count++;
    check = true;
    if(input == "QUIT"){
      running = false;
      check = false;
    }
    if(input == "REPORT"){
      print_report(cDV);
      check = false;
    }
    if(input == "RECOMMEND"){
      print_recommendation(cDV);
      check = false;
    }
    if(input == "RESET"){
      createDVReq(cDV, "dailyvaluerequirements.txt");
      count = 1;
      check = false;
    }
    if(check) {
      for (int i = 0; i < list.size(); i++){
        if (input == list[i].getName()){
          //call functions to return data and recommended food intake
          DV_to_meet(list[i], cDV);

          //saves the current session in previous.txt
          writePrevious(cDV);
          check = false;
        }
      }
    }
    if (check) {
      cout << input + " is not a valid entry." << endl;
      count--;
    }
  }
}

int main(){
  //initiates vector of recommended DV of various nutrients
  vector<DV_hold> cDV;
  createDVReq(cDV, "previous.txt");

  //takes in user input of eaten foods
  userInput(cDV);

  //saves the current session in previous.txt
  writePrevious(cDV);

  return 0;
}
