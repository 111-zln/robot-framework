# Robot Control Framework

//一个基于ros2的机器人控制框架，用现代c++编写。
A ROS2-based robot control framework written in Modern C++.

//本课题的目标是为工业机械臂构建一个模块化、可扩展的机器人控制框架。该框架采用分层结构设计，可以连接仿真和真实机器人硬件。
The goal of this project is to build a modular and scalable robot control framework for industrial robotic arms. The framework is designed with a layered architecture and can be connected to both simulation and real robot hardware.

---

# Project Goals

- Learn ROS2 through real project development.//通过实际项目开发学习ROS2。
- Build a reusable robot control framework.//构建一个可重用的机器人控制框架。
- Support simulation before real hardware.//在实际硬件之前支持仿真
- Integrate with industrial robot SDKs in the future.//未来与工业机器人sdk集成
- Support MoveIt2 and ros2_control.//支持MoveIt2和ros2_control

---

# Features

Current progress:

- [x] Project initialization
- [ ] Robot Controller
- [ ] Joint Controller
- [ ] Hardware Interface
- [ ] Robot Simulation
- [ ] MoveIt2 Integration

---

# Project Structure

robot-control-framework/

├── docs/                  Project documentation

├── robot_bringup/         Launch files

├── robot_control/         Robot controllers

├── robot_description/     URDF models

├── robot_hardware/        Hardware interface

├── robot_interfaces/      ROS2 custom interfaces

├── robot_common/          robot common tool

├── robot_simulation/      Simulation modules

├── scripts/               Helper scripts

└── third_party/           Third-party libraries

---

# Roadmap

V0.1

- Project initialization

V0.2

- Robot Controller

V0.3

- Joint Controller

V0.4

- Simulation

V1.0

- ROS2 Control Framework

---

# Development Environment

- Ubuntu 24.04
- ROS2 Jazzy
- Modern C++17
- CMake
- Git

---

# License

MIT License.