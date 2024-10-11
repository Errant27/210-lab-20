// COMSc 210 | Lab 20 | Neil Orton
// IDE used: Xcode
#include <iostream>
#include <iomanip>
#include <random>

using namespace std;
const int SIZE = 3;

class Chair {
private:
    int legs;
    double * prices;
public:
    // constructors
    Chair() {
        random_device randPrice;
        random_device randLeg;
        uniform_int_distribution<int>leg_Range(3, 4);
        uniform_real_distribution<double>price_Range(100.00, 999.99);
        
        prices = new double[SIZE];
        legs = leg_Range(randLeg);
    
        for (int i = 0; i < SIZE; i++)
            prices[i] = price_Range(randPrice);;
    }
    Chair(int l, double *array) {
        prices = array;
        legs = l;
    }

    // setters and getters
    void setLegs(int l)      { legs = l; }
    int getLegs()            { return legs; }

    void setPrices(double p1, double p2, double p3) {
        prices[0] = p1; prices[1] = p2; prices[2] = p3;
    }

    double getAveragePrices() {
        double sum = 0;
        for (int i = 0; i < SIZE; i++)
            sum += prices[i];
        return sum / SIZE;
    }

    void print() {
        cout << "CHAIR DATA - legs: " << legs << endl;
        cout << "Price history: " << endl;
        for (int i = 0; i < SIZE; i++)
            cout << "Price " << i + 1 << ": $" << prices[i] << ", ";
        cout << endl << "Historical avg price: " << endl;
        cout << "$" << getAveragePrices();
        cout << endl << endl;
    }
};    //End of class

int main() {
    double array[SIZE] = {111.11, 222.222, 333.44};
    cout << fixed << setprecision(2);
    
    //creating pointer to first chair object
    Chair *chairPtr = new Chair;
    chairPtr->setLegs(4);
    chairPtr->setPrices(121.21, 232.32, 414.14);
    chairPtr->print();

    //creating dynamic chair object with constructor
    Chair *livingChair = new Chair();
    livingChair->print();
    delete livingChair;
    livingChair = nullptr;
    
    //creating a chair with an array
    Chair *chairWithArray = new Chair(4, array);
    chairWithArray->print();

    //creating dynamic array of chair objects
    Chair *collection = new Chair[SIZE];
    collection[0] = Chair();
    collection[1] = Chair();
    collection[2] = Chair();
    for (int i = 0; i < SIZE; i++)
        collection[i].print();
    
    return 0;
}
