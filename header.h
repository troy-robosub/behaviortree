#include <iostream>
#include <chrono>
#include "behaviortree_cpp_v3/action_node.h"
#include "behaviortree_cpp_v3/bt_factory.h"

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
    auto time = getInput<float>("time");
    if (!time) 
    {
      throw BT::RuntimeError("missing required input [time]: ", time.error());
    }

    std::cout << "Moving forward for " << time.value() << " seconds" << std::endl;

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
    return { InputPort<float>("heading") };
  }

  NodeStatus tick() override
  {
    auto heading = getInput<float>("heading");
    if (!heading) 
    {
      throw BT::RuntimeError("missing required input [heading]: ", heading.error());
    }

    std::cout << "Adjusting Heading to " << heading.value() << std::endl;

    return NodeStatus::SUCCESS;
  }
};

  // Override the virtual function tick()
  NodeStatus tick() override
  {
    Expected<std::string> msg = getInput<std::string>("message");
    // Check if expected is valid. If not, throw its error
    if (!msg)
    {
      throw BT::RuntimeError("missing required input [message]: ", 
                              msg.error() );
    }
    // use the method value() to extract the valid message.
    std::cout << "Robot says: " << msg.value() << std::endl;
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
    auto heading = getInput<float>("heading");
    if (!heading) 
    {
      throw BT::RuntimeError("missing required input [heading]: ", heading.error());
    }

    std::cout << "Adjusting Heading to " << heading.value() << std::endl;

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
    std::cout << "Spinning 360 degrees" << std::endl;
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
    auto heading = getInput<float>("heading");
    if (!heading) 
    {
      throw BT::RuntimeError("missing required input [heading]: ", heading.error());
    }

    std::cout << "Adjusting Heading to " << heading.value() << std::endl;

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
    auto heading = getInput<float>("heading");
    if (!heading) 
    {
      throw BT::RuntimeError("missing required input [heading]: ", heading.error());
    }

    std::cout << "Adjusting Heading to " << heading.value() << std::endl;

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
    auto heading = getInput<float>("heading");
    if (!heading) 
    {
      throw BT::RuntimeError("missing required input [heading]: ", heading.error());
    }

    std::cout << "Adjusting Heading to " << heading.value() << std::endl;

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
    std::cout << "Adjusting Altitude" << std::endl;
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
    return { InputPort<float>("heading") };
  }

  NodeStatus tick() override
  {
    auto heading = getInput<float>("heading");
    if (!heading) 
    {
      throw BT::RuntimeError("missing required input [heading]: ", heading.error());
    }

    std::cout << "Adjusting Heading to " << heading.value() << std::endl;

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
    return { InputPort<float>("heading") };
  }

  NodeStatus tick() override
  {
    auto heading = getInput<float>("heading");
    if (!heading) 
    {
      throw BT::RuntimeError("missing required input [heading]: ", heading.error());
    }

    std::cout << "Adjusting Heading to " << heading.value() << std::endl;

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
    return { InputPort<float>("heading") };
  }

  NodeStatus tick() override
  {
    auto heading = getInput<float>("heading");
    if (!heading) 
    {
      throw BT::RuntimeError("missing required input [heading]: ", heading.error());
    }

    std::cout << "Adjusting Heading to " << heading.value() << std::endl;

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
    auto distance = getInput<float>("distance");
    if (!distance)
    {
      throw BT::RuntimeError("missing required input [distance]: ", distance.error());
    }

    std::cout << "Checking distance: " << distance.value() << " meters" << std::endl;

    // Here, replace `false` with the actual condition check.
    // If distance is less than or equal to the input, return SUCCESS.
    // Otherwise, return FAILURE.
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
    auto depth = getInput<float>("depth");
    if (!depth)
    {
      throw BT::RuntimeError("missing required input [depth]: ", depth.error());
    }

    std::cout << "Checking depth: " << depth.value() << " meters" << std::endl;

    // Replace `false` with the actual condition check.
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
    return { InputPort<float>("depth") };
  }

  NodeStatus tick() override
  {
    auto depth = getInput<float>("depth");
    if (!depth)
    {
      throw BT::RuntimeError("missing required input [depth]: ", depth.error());
    }

    std::cout << "Checking depth: " << depth.value() << " meters" << std::endl;

    // Replace `false` with the actual condition check.
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
    return { InputPort<float>("depth") };
  }

  NodeStatus tick() override
  {
    auto depth = getInput<float>("depth");
    if (!depth)
    {
      throw BT::RuntimeError("missing required input [depth]: ", depth.error());
    }

    std::cout << "Checking depth: " << depth.value() << " meters" << std::endl;

    // Replace `false` with the actual condition check.
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
}
