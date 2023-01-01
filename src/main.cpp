#include <Arduino.h>
#include "Gldr.h"


gldr::JoystickTransmitter joystickTransmitter   = gldr::JoystickTransmitter(8, 3, 2);
gldr::JoystickReceiver joystickReceiver         = gldr::JoystickReceiver();
gldr::RemoteTransmitter remoteTransmitter(4, 5, joystickTransmitter);
gldr::RemoteReceiver remoteReceiver(2, 3, joystickReceiver);


static uint16_t val = 1024;

uint8_t buffer[2];

void setup()
{
    Serial.begin(9600);
}


void loop()
{
    joystickTransmitter.update();
    remoteTransmitter.transmit();
    delay(50);
    remoteReceiver.update();

    Serial.println(joystickReceiver.getY());
}
