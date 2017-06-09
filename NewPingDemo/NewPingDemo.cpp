// Do not remove the include below
#include "NewPingDemo.h"

// ---------------------------------------------------------------------------
// Example NewPing library sketch that does a ping about 20 times per second.
// ---------------------------------------------------------------------------

#include <NewPing.h>

#define TRIGGER_PIN  12  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     11  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define TRIGGER_PIN2  10  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN2      8  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.
NewPing sonar2(TRIGGER_PIN2, ECHO_PIN2, MAX_DISTANCE); // NewPing setup of pins and maximum distance.

void setup() {
	Serial.begin(115200); // Open serial monitor at 115200 baud to see ping results.
}

void loop() {
	unsigned int uS;
#if 0
	delay(100); // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
	uS = sonar.ping();// Send ping, get ping time in microseconds (uS).
	Serial.print("Ping: ");
	Serial.print(uS / US_ROUNDTRIP_CM);// Convert ping time to distance in cm and print result (0 = outside set distance range)
	Serial.print("cm  ");
#endif
#if 1
	delay(100); // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
	uS = sonar2.ping();// Send ping, get ping time in microseconds (uS).
	Serial.print("Ping2: ");
	Serial.print(uS / US_ROUNDTRIP_CM);// Convert ping time to distance in cm and print result (0 = outside set distance range)
	Serial.print("cm");
#endif
	Serial.println("");
}
