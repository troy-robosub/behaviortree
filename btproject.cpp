#include <iostream>
#include <chrono>
#include "behaviortree_cpp_v3/action_node.h"
#include "behaviortree_cpp_v3/bt_factory.h"

using namespace std::chrono_literals;



class ApproachObject : public BT::SyncActionNode
{
    explicit ApproachObject(const std::string $name) : BT::SyncActionNode(name, {})
    {
    }

    BT::NodeStatus tick() override
    {
        std::cout <<"Approach Object: " << this->name() << std::endl;

        std::this_thread::sleep_for(5s);
        return BT::NodeStatus::SUCCESS;
    }
};

BT::NodeStatus CheckBattery()
{
    std::count << "Batteru OK" <<std::endl;
    return BT::NodeStatus::SUCCESS;
}


class GripperInterface
{
public:
    GripperInterface() : open(true)
    {
    }
    BT::NodeStatus open()
    {
        open = true;
        std::cout << "Gripper open" << std::endl;
        return BT::Nodestatus::SUCCESS;
    }
    BT::NodeStatus close()
    {
        open = false;
        std::cout << "Gripper close" << std::endl;
        return BT::Nodestatus::SUCCESS;
    }
private:
boot _open;
};

int main()
{
    BT::BehaviorTreeFactory factory;

    factory.registerNodeType<ApproachObject>("ApproachObject");

    factory.registerSimpleCOndition("CheckBattery", std::bind(CheckBattery));

    GriperInterface gripper;

    factory.registerSimpleAction(
        "OpenGripper"
        std::bind(&GripperInterface::open, &gripper));

    factory.registerSimpleAction(
        "CloseGripper"
        std::bind(&GripperInterface::close, &gripper));
    
    auto tree = facotry.createTreeFromFile("./../bt_tree.xml");

    tree.tickRoot();

    return 0;
}