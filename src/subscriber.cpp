//
// Created by basavraj-n on 11/16/21.
//

#include <memory>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
void call_back(const std_msgs::msg::String::SharedPtr msg){
    RCLCPP_INFO(rclcpp::get_logger("logger"), "Received: %s", msg->data.c_str());
}
int main(int argc, char * argv[]){
    rclcpp::init(argc,argv);
    std::shared_ptr<rclcpp::Node> node = rclcpp::Node::make_unique("subber");
    std::shared_ptr<rclcpp::Subscription<std_msgs::msg::String>> publisher_;
    publisher_ = node->create_subscription<std_msgs::msg::String>("/asd", 10, call_back);
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}