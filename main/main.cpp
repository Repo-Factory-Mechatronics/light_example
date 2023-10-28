#include "light.hpp"

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<LightNode>());
    rclcpp::shutdown();
    return 0;
}
