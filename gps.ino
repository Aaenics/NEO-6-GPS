#include <TinyGPS++.h>
#include <SoftwareSerial.h>

#define RX_PIN D7
#define TX_PIN D6

TinyGPSPlus gps;
SoftwareSerial gpsSerial(RX_PIN, TX_PIN);

void printLatLong(TinyGPSPlus &gps) {
  if (gps.location.isValid()) {
    Serial.print("Latitude: ");
    Serial.println(gps.location.lat(), 6);
    Serial.print("Longitude: ");
    Serial.println(gps.location.lng(), 6);
  } else {
    Serial.println("Location is not valid");
  }
}

void setup() {
  Serial.begin(115200);
  gpsSerial.begin(9600);
}

void loop() {
  while (gpsSerial.available() > 0) {
    if (gps.encode(gpsSerial.read())) {
      printLatLong(gps);
    }
  }
}

