#include <Arduino.h>
#include "Gldr.h"


auto joystickTransmitter   = gldr::JoystickTransmitter(9, 2, 3);
auto joystickReceiver      = gldr::JoystickReceiver();

auto gyroTransmitter = gldr::GyroTransmitter();

gldr::RemoteTransmitter remoteTransmitter(4, 5, joystickTransmitter, gyroTransmitter);
gldr::RemoteReceiver remoteReceiver(2, 3, joystickReceiver);


void setup()
{
    Serial.begin(9600);
    gyroTransmitter.setup();
}


void loop()
{
    remoteTransmitter.transmit();
    remoteReceiver.update();

    Serial.print(joystickReceiver.getSwitch());
    Serial.print("\t");
    Serial.print(joystickReceiver.getX());
    Serial.print("\t");
    Serial.println(joystickReceiver.getY());
}
