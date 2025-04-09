#include <XboxSeriesXControllerESP32_asukiaaa.hpp>
#include <XboxControllerNotificationParser.h>

// Required to replace with your xbox address
 XboxSeriesXControllerESP32_asukiaaa::Core
 xboxController("F4:6A:D7:7E:18:C5");

// any xbox controller
//XboxSeriesXControllerESP32_asukiaaa::Core xboxController;

void setup() {
  Serial.begin(115200);
  Serial.println("Starting NimBLE Client");
  xboxController.begin();
}

void loop() {
  xboxController.onLoop();
  if (xboxController.isConnected()) {
    if (xboxController.isWaitingForFirstNotification()) {
      Serial.println("waiting for first notification");
    } else {
      Serial.println("Address: " + xboxController.buildDeviceAddressStr());
      Serial.print(xboxController.xboxNotif.toString());

      float lx = xboxController.xboxNotif.joyLHori;  // Joystick izquierdo - eje X
      float ly = xboxController.xboxNotif.joyLVert;  // Joystick izquierdo - eje Y
      float rx = xboxController.xboxNotif.joyRHori;  // Joystick derecho - eje X
      float ry = xboxController.xboxNotif.joyRVert;  // Joystick derecho - eje Y

      // Imprimir valores en el monitor serial
      Serial.print("Joystick Izquierdo - X: ");
      Serial.print(lx/65535);
      Serial.print(", Y: ");
      Serial.println(ly/65535);

      Serial.print("Joystick Derecho - X: ");
      Serial.print(rx/65535);
      Serial.print(", Y: ");
      Serial.println(ry/65535);


    }
  } else {
    Serial.println("not connected");
    if (xboxController.getCountFailedConnection() > 2) {
      ESP.restart();
    }
  }
  Serial.println("at " + String(millis()));
  delay(500);
}
