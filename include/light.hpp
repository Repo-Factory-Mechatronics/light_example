#include <robot_libraries/public_service_apis.hpp>
#include <robot_libraries/custom_ros_types.hpp>
#include <robot_libraries/can_client.hpp>

class LightNode: public rclcpp::Node
{
    public:
        LightNode();
    private:
        RTL::node_t can_client_node;
        RTL::send_frame_client_t can_client;
        RTL::ros_timer_t timer;
};
