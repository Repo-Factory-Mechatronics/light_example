#include "light.hpp"
#include <chrono>

LightNode::LightNode() : Node("light")
{
    this->can_client_node = std::make_shared<rclcpp::Node>("raw_send_service_temp");
    this->can_client = can_client_node->create_client<scion_types::srv::SendFrame>("send_can_raw");
    this->timer = this->create_wall_timer(std::chrono::milliseconds(200), [&](){
        CanClient::turnOnLight(this->can_client_node, this->can_client);
        CanClient::turnOffLight(this->can_client_node, this->can_client);
    });
}
