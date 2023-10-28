cmake_minimum_required(VERSION 3.5)
project(light)

set(CMAKE_CXX_STANDARD 20)

find_library(CAN_CLIENT can_client)
find_library(CORE_DEPENDENCIES core_dependencies)
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(scion_types REQUIRED)

add_executable(${PROJECT_NAME}_exec
    src/light.cpp
    main/main.cpp
)

target_link_libraries(
  ${PROJECT_NAME}_exec
  ${CAN_CLIENT}
  ${CORE_DEPENDENCIES}
)

target_include_directories(${PROJECT_NAME}_exec
    PUBLIC 
    include
)

ament_target_dependencies(${PROJECT_NAME}_exec scion_types rclcpp)

# Install the executable
install(TARGETS ${PROJECT_NAME}_exec
  DESTINATION bin/robot/c
)

ament_package() 
