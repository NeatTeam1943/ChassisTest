// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include <frc/XboxController.h>
#include <frc/TimedRobot.h>
#include <frc/motorcontrol/MotorControllerGroup.h>
#include <frc/drive/DifferentialDrive.h>
#include <ctre/Phoenix.h>

/**
 * This is a demo program showing the use of the DifferentialDrive class.
 * Runs the motors with tank steering.
 */
class Robot : public frc::TimedRobot {
  WPI_TalonSRX m_rearRightMotor{1};
  WPI_TalonSRX m_frontRightMotor{2};
  WPI_TalonSRX m_rearLeftMotor{3};
  WPI_TalonSRX m_frontLeftMotor{4};
  frc::MotorControllerGroup m_right{m_rearRightMotor, m_frontRightMotor};
  frc::MotorControllerGroup m_left{m_rearLeftMotor, m_frontLeftMotor};
  frc::DifferentialDrive m_robotDrive{m_left, m_right};

  frc::XboxController m_controller{0};

 public:
  void RobotInit() override {
    // We need to invert one side of the drivetrain so that positive voltages
    // result in both sides moving forward. Depending on how your robot's
    // gearbox is constructed, you might have to invert the left side instead.
    m_rearLeftMotor.SetInverted(true);
    m_frontLeftMotor.SetInverted(true);
  }

  void TeleopPeriodic() override {
    // Drive with tank style
    m_robotDrive.TankDrive(m_controller.GetRightX(), m_controller.GetRightX());
  }
};

#ifndef RUNNING_FRC_TESTS
int main() {
  return frc::StartRobot<Robot>();
}
#endif
