/*
 * food.cpp
 *
 * Example showing multiple inheritance
 */

#include<iostream>

using namespace std;

// base class
class food {
   int protein;
   int calories;
   int fat;
public:
   food(void);
   void info (void);  // print out nutrition
};

// base class constructor
food :: food (void)
{
   cout << "Protein: ";
   cin >> protein;
   cout << "Calories: ";
   cin >> calories;
   cout << "Fat: ";
   cin >> fat;
}

// function to print out nutrients in a food
void food :: info (void)
{
   cout << "Nutrients---" << endl;
   cout << "Protein      : " << protein << endl;
   cout << "Calories     : " << calories << endl;
   cout << "Fat          : " << fat << endl;
}


// -------------------------------------------- //


// derived class of food
class vegetable : public food {
   char name[10];
public:
   // the constructor for food is automatically called FIRST
   vegetable (void){cout << "Name: "; cin >> name;}
};


// -------------------------------------------- //


// another base class
class chemicals {
   float calcium_carbonate;
   float alpha_tocepheryl_acetate;
   float propyl_gallate;
public:
   chemicals (void);
   void info (void);    // print out amount of chemicals
};

// constructor
chemicals :: chemicals (void)
{
   cout << "calcium_carbonate: ";
   cin >> calcium_carbonate;
   cout << "alpha_tocepheryl_acetate: ";
   cin >> alpha_tocepheryl_acetate;
   cout << "propyl_gallate: ";
   cin >> propyl_gallate;
}

// function to print out amount of each chemical
void chemicals :: info (void)
{
   cout << "Chemicals---" << endl;
   cout << "calcium_carbonate       : " << calcium_carbonate << endl;
   cout << "alpha_tocepheryl_acetate: " << alpha_tocepheryl_acetate << endl;
   cout << "propyl_gallate          : " << propyl_gallate << endl;
}


// -------------------------------------------- //


// derived class, inheriting members from both 
// and chemicals
class candybar : public food, public chemicals {
   float cost;
public:
   candybar (void) {cout << "Cost? "; cin >> cost;}
   void info (void);     // print out nutrients AND chemicals
};
   

// print out all info for candybar
void candybar :: info (void)
{
   food :: info ();       // must specify which function by
   chemicals :: info ();  // using :: operator
   cout << "All this for " << cost << endl;
}



int main (void)
{
   vegetable pepper;
   candybar kudos;

   cout << "Your vegetable contains:" << endl;
   pepper.info();
   cout << "Your candy bar contains:" << endl;
   kudos.info();

   return 0;
}
