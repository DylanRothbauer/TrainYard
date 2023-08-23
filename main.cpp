/*
 * A program that models the activities at a Train yard
 * Dylan Rothbauer
 * 05-04-22
 */ 
#include <iostream>
#include <string>
#include <vector>
#include "Depot.h"
using namespace std;

// Found in the BoxCar class, this static int is global and shared with all BoxCar's
int BoxCar::staticId = 1000;

int main(int argc, char **argv) {
    
    string knapfordCargo[] = {"lumber", "pulp", "barley", "millet", "ammonia", "chlorine", "steel"};
    string brendomCargo[] = {"coal", "corn", "soybeans", "cattle", "oil"};
    string elsbridgeCargo[] = {"wheat", "nitrogen"};
    
    Depot knapford("Knapford", knapfordCargo, 7);
    Depot brendom("Brendom", brendomCargo, 5);
    Depot elsbridge("Elsbridge", elsbridgeCargo, 2);
    Depot tidmouth("Tidmouth", {}, 0);
    
    cout << endl << "Good morning for another day of work in Sodor!" << endl << endl;
    
    knapford.print();
    cout << endl;
    brendom.print();
    cout << endl;
    elsbridge.print();
    cout << endl;
    tidmouth.print();
    cout << endl;
    
    
    // All 3 trains should then travel to Tidmouth
    
    
    /**
    * Make train Thomas
    * Load train to knapford
    * have Thomas travel to Tidmouth depot
    */
    Train thomas("Thomas", "Blue"); // 1
    knapford.loadTrain(&thomas);
    thomas.travelTo("Tidmouth");
    
    
    /**
    * Make train Percy
    * Load train to brendom
    * have Percy travel to Tidmouth depot
    */
    Train percy("Percy", "Green"); // 2
    brendom.loadTrain(&percy);
    percy.travelTo("Tidmouth");
    
    
    /**
    * Make train Rebecca
    * Load train to elsbridge
    * have Rebecca travel to Tidmouth depot
    */
    Train rebecca("Rebecca", "Yellow"); // 3
    elsbridge.loadTrain(&rebecca);
    rebecca.travelTo("Tidmouth");
    
    // Thomas and Percy should unload cargo at Tidmouth
    tidmouth.unloadTrain(&thomas);
    tidmouth.unloadTrain(&percy);
    cout << endl << endl;
    
    /** NOTICE
     * Rebecca did not make it to Tidmouth
     * Once our Destructor is called, it will output name and color with message
     */
     
     
    tidmouth.print();
    cout << endl;
    
    cout << "Rebecca's engine has broken down, oh no, what will happen?? ..." << endl;
    
    cout << endl << "The sun is setting, good day!" << endl << endl;
    
	return 0;
}
