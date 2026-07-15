# Development Guide

## Project Rules

- Keep modules independent.//模块保持独立
- One class, one responsibility.//一个类只负责一件事情
- Prefer composition over inheritance.//优先组合而不是继承
- Do not mix hardware drivers with business logic.//驱动不能写业务逻辑

## Folder Rules

robot_control/---Robot control logic.

robot_hardware/---Hardware abstraction.

robot_interfaces/---ROS2 interfaces.

robot_description/---URDF and robot models.

robot_bringup/---Launch files.

docs/---Project documentation.

## Git Commit Rules

Examples

- Initialize repository
- Add RobotController
- Add HardwareInterface
- Fix joint state update
- Update documentation

## Development Workflow

Requirement

↓

Design

↓

Documentation

↓

Implementation

↓

Testing

↓

Git Commit

↓

Push