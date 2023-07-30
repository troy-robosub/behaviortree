#include <iostream>

// Action Node
class MoveForward {
public:
    void execute(float time) {
        std::cout << "Moving forward";
        // Code to move forward for time seconds
    }
};

// Action Node
class FindGateDetector {
public:
    void execute() {
        std::cout << "Finding gate";
        // Code to find the gate
    }
};

// Action Node
class AdjustHeading {
public:
    void execute(float heading) {
        std::cout << "Adjusting heading";
        // Code to adjust the heading to the specified angle
    }
};

// Action Node
class Spin360 {
public: 
    void execute() {
        std::cout << "Spinning 360 degrees";
        // Code to spin 360 deg
    }
};

// Action Node
class FindSymbol {
public:
    bool execute() {
        bool heading=true;
        std::cout << "Finding symbol, returning if found";
        // Code to find sdymbol and return heading angle
        // If symbol is not found, turn 15 degrees
        return heading;
    }
};

// Action Node
class FindBuoy {
public:
    float execute() {
        float heading = 0.0f;
        std::cout << "Finding buoy, returning heading angle";
        // Code to find buoy
        return heading
    }
};

// Action Node
class FindOctagon {
public:
    float execute() {
        float heading = 0.0f;
        std::cout << "Finding octagon, returning heading angle";
        // Code to find octagon
        return heading
    }
};

// Action Node
class AdjustAltitude {
public:
    void execute() {
        std::cout << "Adjusting altitude";
        // Code to adjust altittude
    }
};

// Action Node
class AdjustYaw {
public:
    void execute(float heading) {
        std::cout << "Adjusting yaw to heading angle";
        // Code to adjust yaw
    }
};

// Action Node
class MoveBackward {
public:
    void execute(float time) {
        std::cout << "Moving backward";
        // Code to move backward time seconds
    }
};

// Action Node
class MoveUp {
public:
    void execute(float time) {
        std::cout << "Moving up";
        // Code to move up time seconds
    }
};

// Conditional Node
class CheckDistance {
public:
    bool execute(float distance) {
        std::cout << "Checking distance";
        // Code to check distance, if checked distance == distance, return true
        return true;
    }
};

// Conditional Node
class CheckDepth {
public:
    bool execute(float distance) {
        std::cout << "Checking depth";
        // Code to check depth
        return true;
    }
};

// Conditional Node
class SeeBuoy {
public:
    bool execute() {
        std::cout << "Checking for buoy";
        // Code to see buoy, if it does return true
        return true;
    }
};

// Conditional Node
class SeeOctagon {
public:
    bool execute() {
        std::cout << "Checking for octagon";
        // Code to check for octagon, return true if seen
        return true;
    }
};

//Sequence: StyleTask
class StyleTask {
public:
    bool execute(float distance) {
        CheckDistance checkDistance;
        Spin360 spin360;
        if (checkDistance.execute(distance)) {
            spin360.execute(); spin360.execute(); return true;
        }
        else {
            return false;
        }
    }
};

// Sequence: GetBuoy
class GetBuoy {
public:
    bool execute() {
        AdjustHeading adjustHeading;
        AdjustAltitude adjustAltitude;
        MoveForward moveForward;
        CheckDistance checkDistance;
        FindBuoy findBuoy;

        adjustHeading.execute(findBuoy.execute());
        adjustAltitude.execute();
        moveForward.execute(5.0f);
        return checkDistance.execute(1.0f);
    }
};

// Sequence: GetOctagon
class GetOctagon {
public:
    bool execute() {
        FindOctagon findOctagon;
        MoveForward moveForward;
        CheckDistance checkDistance;
        AdjustYaw adjustYaw;

        adjustYaw.execute(findOctagon.execute());
        moveForward.execute(5.0f);
        return checkDistance.execute(2.0f);
    }
};

// Sequence: FindGate
class FindGate {
public:
    bool execute() {
        MoveForward moveForward;
        FindGateDetector findGateDetector;
        AdjustHeading adjustHeading;
        StyleTask styleTask;

        moveForward.execute(3.0f);
        findGateDetector.execute();
        adjustHeading.execute(0.0f);
        return styleTask.execute(2.0f);
    }
};

//Sequence: Enter Gate
class EnterGate {
public: 
    bool execute() {
        FindSymbol findSymbol;
        AdjustHeading adjustHeading;
        AdjustAltitude adjustAltitude;
        MoveForward moveForward;

        if (!findSymbol.execute()) {
            adjustHeading.execute(15.0f);
        }
        else {
            adjustHeading.execute(0.0f);
            adjustAltitude.execute()
            moveForward.execute(10.0f)
            return true;
        }
        return false;
    }
};

// Sequence: Buoy Repeater
class BuoyRepeater {
public:
    void execute() {
        MoveForward moveForward;
        SeeBuoy seeBuoy;
        FindBuoy findBuoy;
        GetBuoy getBuoy;
        MoveBackward moveBackward;
        MoveUp moveUp;

        while (!seeBuoy.execute()) {
            moveForward.execute(5.0f)
        }
        while (!getBuoy.execute()) {
            sleep(1);
        }
        moveForward.execute(10.0f);
        moveBackward.execute(10.0f);
        moveUp.execute(3.0f);
    }
};

// Sequence: Octagon Repeater
class OctagonRepeater {
public:
    void execute() {
        MoveForward moveForward;
        SeeOctagon seeOctagon;
        GetOctagon getOctagon;

        moveForward.execute(5.0f);
        while (!seeOctagon.execute()) {
            moveForward.execute(5.0f);
        }
        while (!getOctagon.execute()) {
            sleep(1);
        }
    }
};

// Sequence: Conclude
class Conclude {
public:
    bool execute() {
        MoveUp moveUp;
        CheckDepth checkDepth;

        moveUp.execute(1.0f);
        return checkDepth.execute(-2.0f);
    }
};

void main() {
    // Branch 1
    FindGate findGate;
    while (!findGate.execute()) {
        sleep(1);
    }
    
    //Branch 2
    EnterGate enterGate;
    while (!enterGate.execute()) {
        sleep(1);
    }

    //Branch 3
    BuoyRepeater buoyRepeater;
    buoyRepeater.execute();

    // Branch 4
    OctagonRepeater octagonRepeater;
    octagonRepeater.execute();

    //Branch 5
    Conclude conclude;
    while (!conclude.execute()) {
        sleep(1);
    }
}
