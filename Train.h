#ifndef TRAIN_H
#define TRAIN_H

#include <string>
#include <iostream>
using namespace std;

class Train {
public:

    /**
     * Train Constructor
     * @param name the train 
     * @param color of the train
    */
    Train(string name, string color) {
        this->name = name;
        this->color = color;
        firstCar = nullptr; 
    }
    
    /**
     * Train Deconstructor
     * Destructor is called apon objects getting out of scope
     * Using detach() function to delete each BoxCar
    */
    ~Train() {
        if (firstCar != nullptr) {
            cout << "Oh No " << name << " the " << color  << " train! ";
            cout << "You didn't make it to the depot and your cargo has spoiled, we need to destroy these BoxCar(s) ";
             while (firstCar != nullptr) {
                 cout << firstCar->getId() << " ";
                 delete detach();
            }
        }
        cout << endl;
    }
    
    /**
     * travelTo() 
     * @param a string (name) of our destination (depot)
    */
    void travelTo(string depotName) {
        cout << name << " the " << color << " train is on their way to " << depotName << " hauling: " << endl;
        BoxCar* temp = firstCar;
        
        while(temp != nullptr) {
            temp->print();
            temp = temp->getNextCar();
        }
        cout<<"\n";
    }
    
    /**
     * getTrainName() returns this->name
    */
    string getTrainName() const {
        
        return name;
    }
    
    /**
     * getCarCount() returns a count of how many BoxCar's
    */
    int getCarCount() const {
        
        // first car ... getNextCar ... count++ nextCar != nullptr
        int count = 0;
        BoxCar* temp = firstCar;
        
        while(temp != nullptr) {
            count++;
            temp = temp->getNextCar();
        }
        
        return count;
    }
    
    /**
     * attach() attaches a BoxCar pointer to the end of the list
     * @param a BoxCar pointer
    */
    void attach(BoxCar* passedPtr) {
        // use getCaboose to append passedPtr to end of train
        // if no box cars attached? ... set passedPtr to firstCar
        
        if (firstCar == nullptr) {
            firstCar = passedPtr;
        } else {
            firstCar->getCaboose()->setNextCar(passedPtr);
        }
    }
    
    /**
     * detach() detaches the first BoxCar and sets the next one to the first
    */
    BoxCar* detach() {
        // second box car = first box car
        BoxCar* temp = firstCar;
        if (temp != nullptr) {
            firstCar = firstCar->getNextCar();
            temp->setNextCar(nullptr);
        }
        return temp;
    }
    
private:
    string name;
    string color;
    BoxCar* firstCar;
};

#endif // TRAIN_H
