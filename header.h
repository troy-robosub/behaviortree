#include <iostream>
#include <chrono>
#include "behaviortree_cpp_v3/action_node.h"
#include "behaviortree_cpp_v3/bt_factory.h"

/*
- change NodeStatus tick() (you cound put logic there or in the cpp file)
- change sdt::cout stuff if you wanna print something more useful
- change "return { InputPort<float>("thing") };" stuff based on return type or if necessary
*/

// Action Node
class MoveForward : public SyncActionNode
{
public:
  MoveForward(const std::string& name, const NodeConfig& config)
    : SyncActionNode(name, config)
  { }

  static PortsList providedPorts()
  {
    return { InputPort<float>("time") };
  }

  NodeStatus tick() override
  {
    std::cout << "MoveForward" << std::endl;
    return NodeStatus::SUCCESS;
  }
};


// Action Node
class FindGateDetector : public SyncActionNode
{
public:
  FindGateDetector(const std::string& name, const NodeConfig& config)
    : SyncActionNode(name, config)
  { }

  static PortsList providedPorts()
  {
    return { InputPort<float>("gate") };
  }

  NodeStatus tick() override
  {
    std::cout << "FindGateDetector" << std::endl;
    return NodeStatus::SUCCESS;
  }
};

  // Override the virtual function tick()
  NodeStatus tick() override
  {
    std::cout << "Spin360" << std::endl;
    return NodeStatus::SUCCESS;
  }
};

// Action Node
class AdjustHeading : public SyncActionNode
{
public:
  AdjustHeading(const std::string& name, const NodeConfig& config)
    : SyncActionNode(name, config)
  { }

  static PortsList providedPorts()
  {
    return { InputPort<float>("heading") };
  }

  NodeStatus tick() override
  {
    std::cout << "AdjustHeading" << std::endl;
    return NodeStatus::SUCCESS;
  }
};

// Action Node
class Spin360 : public SyncActionNode
{
public:
  Spin360(const std::string& name, const NodeConfig& config)
    : SyncActionNode(name, config)
  { }

  NodeStatus tick() override
  {
    std::cout << "Spin360" << std::endl;
    return NodeStatus::SUCCESS;
  }
};

// Action Node
class FindSymbol : public SyncActionNode
{
public:
  FindSymbol(const std::string& name, const NodeConfig& config)
    : SyncActionNode(name, config)
  { }

  static PortsList providedPorts()
  {
    return { InputPort<float>("heading") };
  }

  NodeStatus tick() override
  {
    std::cout << "FindSymbol" << std::endl;
    return NodeStatus::SUCCESS;
  }
};

// Action Node
class FindBuoy : public SyncActionNode
{
public:
  FindBuoy(const std::string& name, const NodeConfig& config)
    : SyncActionNode(name, config)
  { }

  static PortsList providedPorts()
  {
    return { InputPort<float>("heading") };
  }

  NodeStatus tick() override
  {
    std::cout << "FindBuoy" << std::endl;
    return NodeStatus::SUCCESS;
  }
};

// Action Node
class FindOctagon : public SyncActionNode
{
public:
  FindOctagon(const std::string& name, const NodeConfig& config)
    : SyncActionNode(name, config)
  { }

  static PortsList providedPorts()
  {
    return { InputPort<float>("heading") };
  }

  NodeStatus tick() override
  {
    std::cout << "FindOctagon" << std::endl;
    return NodeStatus::SUCCESS;
  }
};

// Action Node
class AdjustAltitude : public SyncActionNode
{
public:
  AdjustAltitude(const std::string& name, const NodeConfig& config)
    : SyncActionNode(name, config)
  { }

  NodeStatus tick() override
  {
    std::cout << "AdjustAltitude" << std::endl;
    return NodeStatus::SUCCESS;
  }
};

// Action Node
class AdjustYaw : public SyncActionNode
{
public:
  AdjustYaw(const std::string& name, const NodeConfig& config)
    : SyncActionNode(name, config)
  { }

  static PortsList providedPorts()
  {
    return { InputPort<float>("yaw") };
  }

  NodeStatus tick() override
  {
    std::cout << "AdjustYaw" << std::endl;
    return NodeStatus::SUCCESS;
  }
};

// Action Node
class MoveBackwards : public SyncActionNode
{
public:
  MoveBackwards(const std::string& name, const NodeConfig& config)
    : SyncActionNode(name, config)
  { }

  static PortsList providedPorts()
  {
    return { InputPort<float>("backwards") };
  }

  NodeStatus tick() override
  {
    std::cout << "MoveBackwards" << std::endl;
    return NodeStatus::SUCCESS;
  }
};

// Action Node
class MoveUp : public SyncActionNode
{
public:
  MoveUp(const std::string& name, const NodeConfig& config)
    : SyncActionNode(name, config)
  { }

  static PortsList providedPorts()
  {
    return { InputPort<float>("up") };
  }

  NodeStatus tick() override
  {
    std::cout << "MoveUp" << std::endl;
    return NodeStatus::SUCCESS;
  }
};

// Conditional Node
class CheckDistance : public ConditionNode
{
public:
  CheckDistance(const std::string& name, const NodeConfig& config)
    : ConditionNode(name, config)
  { }

  static PortsList providedPorts()
  {
    return { InputPort<float>("distance") };
  }

  NodeStatus tick() override
  {
    std::cout << "CheckDistance" << std::endl;
    bool condition = false;

    return condition ? NodeStatus::SUCCESS : NodeStatus::FAILURE;
  }
};


// Conditional Node
class CheckDepth : public ConditionNode
{
public:
  CheckDepth(const std::string& name, const NodeConfig& config)
    : ConditionNode(name, config)
  { }

  static PortsList providedPorts()
  {
    return { InputPort<float>("depth") };
  }

  NodeStatus tick() override
  {
    std::cout << "CheckDepth" << std::endl;
    bool condition = false;

    return condition ? NodeStatus::SUCCESS : NodeStatus::FAILURE;
  }
};

// Conditional Node
class SeeBuoy : public ConditionNode
{
public:
  SeeBuoy(const std::string& name, const NodeConfig& config)
    : ConditionNode(name, config)
  { }

  static PortsList providedPorts()
  {
    return { InputPort<float>("buoy") };
  }

  NodeStatus tick() override
  {
    std::cout << "SeeBuoy" << std::endl;
    bool condition = false;

    return condition ? NodeStatus::SUCCESS : NodeStatus::FAILURE;
  }
};

// Conditional Node
class SeeOctagon : public ConditionNode
{
public:
  SeeOctagon(const std::string& name, const NodeConfig& config)
    : ConditionNode(name, config)
  { }

  static PortsList providedPorts()
  {
    return { InputPort<float>("octagon") };
  }

  NodeStatus tick() override
  {
    std::cout << "SeeOctagon" << std::endl;
    bool condition = false;

    return condition ? NodeStatus::SUCCESS : NodeStatus::FAILURE;
  }
};

/*

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
*/
int main() {
  
}
