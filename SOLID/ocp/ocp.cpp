#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

/*
OCR:
    Avoid writing code where you need to modify existing code to
    meet new requirements.
    Easy way: use abstract class wherever possible, so extension using abstract classess is easily possible.
    Other way could be using templates (this makes code readability and debugging difficult)
*/

// Below code violates ocp. Not suitable for extension
enum class SensorModel {  // prefer to use enum classes than enums to avoid default conversion to 'int' types.
   Good,
   Better
};

/*
    In this snippet we have a DistanceSensor class, that depending on the way we have initialized it,
    it effectively represents a different sensor.Unfortunately, our class design does not allow the
    behavior to be extended unless we modify the source.
    If we want to add a new sensor model, we would have to change the DistanceSensor class
    switch statement to accommodate the new functionality.
    Becomes inconvinient as and when we want to extend it
*/
class DistanceSensor {
   public:
   SensorModel mModel;
   DistanceSensor(SensorModel model) : mModel{model} {}
   int getDistance() {
       switch (mModel) {
           case SensorModel::Good :
               // Business logic for "Good" model
           case SensorModel::Better :
               // Business logic for "Better" model
       }
   }
};


// Solution. use abstract class interface for Distance sensoe class.

/*
    Extension is easy: You can easily add another interface function, or define another class
    for new sensor
*/
class DistanceSensor {
   virtual ~DistanceSensor() = default;
   virtual int getDistance() = 0;
};

class GoodDistanceSensor : public DistanceSensor {
   int getDistance() override {
       // Business logic for "Good" model
   }
};

struct BetterDistanceSensor : public DistanceSensor {
   int getDistance() override {
       // Business logic for "Better" model
   }
};
