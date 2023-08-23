#ifndef BOXCAR_H
#define BOXCAR_H
#include <string>
#include <iostream>
using namespace std;

class BoxCar {
public:
    // My static variable to give each BoxCar a unique id
    static int staticId;
    
    /**
     * BoxCar Constructor that sets private member variables apon Construction
     * @param some string as cargo
     * @param rand() weight integer
    */
    BoxCar(string cargo, int weight) {
        this->cargo = cargo;
        this->weight = weight;
        nextCar = nullptr;
        this->id = staticId;
        staticId++;
    }
    
    /**
     * getId() returns the this->id (private member variable)
    */
    int getId() const {
        
        return id;
    }
    
    /**
     * print() - Our print function
    */
    void print() {
        if (weight <= 0) {
            cout << "-BoxCar " << id << " is empty" << endl;
        } else {
            cout << "-BoxCar " << id << " has " << weight << " lbs of " << cargo << endl;
        }
    }
    
    /**
     * setNextCar sets passed parameter pointer to this->nextCar pointer
     * @param a BoxCar pointer
    */
    void setNextCar(BoxCar* nextCar) {
        this->nextCar = nextCar;
    }
    
    /**
     * getNextCar() returns this->nextCar BoxCar pointer 
    */
    BoxCar* getNextCar() {
        return nextCar;
    }
    
    
    /**
     * getCaboose() returns a pointer to the last BoxCar
    */
    BoxCar* getCaboose() {
        // returning last car (caboose)
        BoxCar* temp = this;
        if (temp->nextCar == nullptr) {
            return temp;
        }
        
        while (temp->nextCar != nullptr) {
            temp = temp->nextCar;
        }
        return temp;
    }
    
    
private:
    int id;
    string cargo;
    int weight;
    BoxCar* nextCar;
};

#endif // BOXCAR_H
