#include "light.hpp"
#include <chrono>
#include <thread>

#define BLINK_PERIOD 200

LightNode::LightNode() : Node("light")
{
    this->can_client_node = std::make_shared<rclcpp::Node>("send_can_raw_temp");
    this->can_client = can_client_node->create_client<scion_types::srv::SendFrame>("send_can_raw");
    this->timer = this->create_wall_timer(std::chrono::milliseconds(BLINK_PERIOD), [&](){
        CanClient::turnOnLight(this->can_client_node, this->can_client);
        std::this_thread::sleep_for(std::chrono::milliseconds(BLINK_PERIOD/2));
        CanClient::turnOffLight(this->can_client_node, this->can_client);
    });
}
