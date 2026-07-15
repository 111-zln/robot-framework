# Robot Control Framework Architecture

## Software Layers

Application Layer

Responsible for robot task execution.

Controller Layer

Responsible for robot motion control.

Service Layer

Provide shared robot services.

Hardware Layer

Provide unified hardware abstraction.

Driver Layer

Communicate with real robot hardware.

---

## Data Flow

Application

↓

Controller

↓

Hardware Interface

↓

Robot Driver

↓

Robot Hardware

---

Robot Hardware

↓

Robot Driver

↓

Robot State

↓

Controller

↓

Application

---

## Core Modules

RobotController

RobotState

HardwareInterface

Simulation

JointController

MotionPlanner