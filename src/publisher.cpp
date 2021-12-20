
#include "rclcpp/rclcpp.hpp"
#include <string>
#include "std_msgs/msg/string.hpp"
int main(int argc, char **argv){
    rclcpp::init(argc, argv);
    std::shared_ptr<rclcpp::Node> node = rclcpp::Node::make_shared("pubber");
    std::shared_ptr<rclcpp::Publisher<std_msgs::msg::String>> publisher_;
    publisher_ =node->create_publisher<std_msgs::msg::String>("/asd", 1);
    rclcpp::Rate loop_rate(10);
    std_msgs::msg::String str;

    size_t count_ = 0;
    while(rclcpp::ok()){
        str.data = "Hello! " + std::to_string(count_++);
        publisher_->publish(str);
        RCLCPP_INFO(rclcpp::get_logger("logger"), "Published: %s", str.data.c_str());
        loop_rate.sleep();
        rclcpp::spin_some(node);
    }
    return 0;
}