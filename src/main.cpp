#include <Arduino.h>
#include "Gldr.h"


auto joystickTransmitter   = gldr::JoystickTransmitter(8, 0, 1);
auto joystickReceiver      = gldr::JoystickReceiver();

auto gyroTransmitter = gldr::GyroTransmitter();
auto gyroReceiver    = gldr::GyroReceiver();

gldr::RemoteTransmitter remoteTransmitter(4, 5, joystickTransmitter, gyroTransmitter, 100);
gldr::RemoteReceiver remoteReceiver(2, 3, joystickReceiver, gyroReceiver);


void setup()
{
    Serial.begin(9600);
    remoteTransmitter.setup();
}


void loop()
{
    remoteTransmitter.transmit();
    remoteReceiver.update();

    Serial.print(remoteReceiver.gyro_x());
    Serial.print("\t");
    Serial.print(remoteReceiver.gyro_y());
    Serial.print("\t");
    Serial.print(remoteReceiver.gyro_z());
    Serial.print("\t");
    Serial.print(remoteReceiver.joystick_switch());
    Serial.print("\t");
    Serial.print(remoteReceiver.joystick_x());
    Serial.print("\t");
    Serial.println(remoteReceiver.joystick_y());

 }
