// *************************************************
// Saffron Birch
// 100795118
// Lab 05 Activity #1
// October 25th, 2020
// *************************************************


/* The purpose of this program is to display the number of units
produced by each factory. The production data and number of units along
with a negative number are input, and the output is the total production
for that particular plant. This is repeated for the number of plants there
are. Once this information is provided, the program outputs the total units
produced by each factory in thousands of units. */


#include <iostream>
#include <cmath>

using namespace std;
const int NUM_OF_FACTORIES = 3;

void prod_data(int prodPerPlant[], int totalFactories);

void units_produced(int prodPerPlant[], int numOfPlants);

void total_prod_for_company(const int factories[], int totalFactories);

void find_total_prod(int& totalProduction);

int cast_to_int(double number); void display_prod(int n);

int main( ) {
    int production[NUM_OF_FACTORIES];
    cout << "This program displays a graph showing\n"
         << "production for each factory in the company.\n";
    prod_data(production, NUM_OF_FACTORIES);
    units_produced(production, NUM_OF_FACTORIES);
    total_prod_for_company(production, NUM_OF_FACTORIES);
    return 0;
}

/*This function takes in two parameters, the first one is a list of
all the production data for each plant, and the second is the total
number of factories. The function uses a for loop along with the
"find_total_prod" function to find the total production for a particular
factory */

void prod_data(int prodPerPlant[], int totalFactories) {
    for (int plantNumber = 1; plantNumber <= totalFactories; plantNumber++) {
      cout << endl << "Enter production data for plant number "
           << plantNumber << endl;
      find_total_prod(prodPerPlant[plantNumber - 1]);
    }
}

/* This function takes in one parameter, which is the total production
(sum of the input values: production data and number of units produced).
The function then calculates the total production using a while loop, which
takes the total production and adds the input production data. It then
outputs the total. */

void find_total_prod(int& totalProduction) {
  totalProduction = 0;
  int prodData;

    cout << "Enter number of units produced by each department.\n"
         << "Append a negative number to the end of the list.\n";
    cin >> prodData;

    while (prodData >= 0) {
    totalProduction = totalProduction + prodData;
    cin >> prodData;
    }
    cout << "Total = " << totalProduction << endl;
}

/* This function takes in two parameters, a list which contains the
production per plant, as well as the number of plants in total. The function
then uses a for loop to go through the index of the first parameter
and typecast the values as integers, while also dividing them by 1000,
since the production units are given in thousands. This way, the displayed
graph of the total production is reasonable. */

void units_produced(int prodPerPlant[], int numOfPlants) {
  for (int index = 0; index < numOfPlants; index++) {
    prodPerPlant[index] = cast_to_int(prodPerPlant[index]/1000.0);
  }
}

/* This function takes in one parameter, which is then to typecasted to
 an integer, and then returned + 0.5. */

int cast_to_int(double number) {
  return static_cast<int>(floor(number + 0.5));
}

/* This function takes in two parameters, a list of the factories, as well
as the factories. The function then uses a for loop to display the total
production using the "display_prod" function. It outputs the factory number
along with the graph of the production. */

void total_prod_for_company(const int factories[], int totalFactories) {
    cout << "\nUnits produced in thousands of units:\n";

    for (int plantNumber = 1; plantNumber <= totalFactories; plantNumber++) {
        cout << "Factory #" << plantNumber << " ";
        display_prod(factories[plantNumber - 1]);
        cout << endl;
    }
}

/* This function takes in one parameter, the total production units, and
creates a visual to display the total production of each factory using a "*"
to represent each 1000 units. */

void display_prod(int units) {
    for (int count = 1; count <= units; count++) {
      cout << "*";
    }
}
