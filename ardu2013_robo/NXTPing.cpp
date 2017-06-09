// Do not remove the include below
#include "ardu2013.h"

#include <NewPing.h>

#define MAX_DISTANCE 200 // Maximum distance (in cm) to ping.
#define PING_INTERVAL 33 // Milliseconds between sensor pings (29ms is about the min to avoid cross-sensor echo).
//#define NUM_AVERAGE   5  // Number of values to average

unsigned long pingTimer[NUM_PING_CH]; // Holds the times when the next ping should happen for each sensor.

uint8_t currentSensor = 0; // Keeps track of which sensor is active.

NewPing sonar[NUM_PING_CH] = { // Sensor object array.
		NewPing(2, 3, MAX_DISTANCE), // Each sensor's trigger pin, echo pin, and max distance to ping.
		NewPing(4, 5, MAX_DISTANCE),
		NewPing(7, 8, MAX_DISTANCE),
		//NewPing(12, 11, MAX_DISTANCE),
};

unsigned char g_u8Ping[NUM_PING_CH];

int index; // This keeps track of which value is being updated in the PingVals array
			// if averaging is enabled

#ifdef NUM_AVERAGE

unsigned char pingVals[NUM_PING_CH][NUM_AVERAGE];

unsigned char averageValues(unsigned char vals[NUM_PING_CH][NUM_AVERAGE], int pingNum);

#endif

void echoCheck();
void oneSensorCycle();

//---------------------------------------------------------------------
// Configure the Ping Input code
//---------------------------------------------------------------------
void Init_Ping(void) {
	for (unsigned int i = 0; i < NUM_PING_CH; i++) {
		// init ping values to zero, clear update flags
		g_u8Ping[i] = 0;
		g_PingFlags[i].bUpdate = FALSE;

		index = 0;

#ifdef NUM_AVERAGE
		for(i = 0; i < NUM_PING_CH; i++) {
			for(int j = 0; j < NUM_AVERAGE; j++) {
				pingVals[i][j] = 0;
			}
		}
#endif
	}

	pingTimer[0] = millis() + 75; // First ping starts at 75ms, gives time for the Arduino to chill before starting.
	for (uint8_t i = 1; i < NUM_PING_CH; i++) // Set the starting time for each sensor.
		pingTimer[i] = pingTimer[i - 1] + PING_INTERVAL;

}

//---------------------------------------------------------------------
// Called from loop() to update Ping readings
//---------------------------------------------------------------------
void Ping_Handler(void) {

	for (uint8_t i = 0; i < NUM_PING_CH; i++) { // Loop through all the sensors.
		if (millis() >= pingTimer[i]) { // Is it this sensor's time to ping?
			pingTimer[i] += PING_INTERVAL * NUM_PING_CH; // Set next time this sensor will be pinged.
			if (i == 0 && currentSensor == NUM_PING_CH - 1) {
				oneSensorCycle(); // Sensor ping cycle complete, do something with the results.
			}
			sonar[currentSensor].timer_stop(); // Make sure previous timer is canceled before starting a new ping (insurance).
			currentSensor = i; // Sensor being accessed.
			sonar[currentSensor].ping_timer(echoCheck); // Do the ping (processing continues, interrupt will call echoCheck to look for echo).
		}
	}
	// The rest of your code would go here.
}

//---------------------------------------------------------------------
// Used by NXTI2C class to update fields in the NXT shared memory area
//---------------------------------------------------------------------
unsigned char Ping_getChannel(unsigned char u8Ch) {
	return g_u8Ping[u8Ch];
}

//---------------------------------------------------------------------
void echoCheck() { // If ping received, set the sensor distance to array.
	unsigned int value;
	if (sonar[currentSensor].check_timer()) {
		value = sonar[currentSensor].ping_result
		/ US_ROUNDTRIP_CM;
	} else {
		value = 255; // Make distance 255 in case there's no ping echo for this sensor.
	}
#ifdef NUM_AVERAGE
	pingVals[currentSensor][index] = value;
	g_u8Ping[currentSensor] = averageValues(pingVals, currentSensor);
#else
	g_u8Ping[currentSensor] = value;
#endif
	g_PingFlags[currentSensor].bUpdate = TRUE;
}

void oneSensorCycle() { // Sensor ping cycle complete, do something with the results.
#ifdef NUM_AVERAGE
	if (index < NUM_AVERAGE) { // update index so that readings are stored correctly in pingVals
		index++;
	} else {
		index = 0;
	}
#endif

#if DEBUG != 0
	for (uint8_t i = 0; i < NUM_PING_CH; i++) {
		Serial.print(i);
		Serial.print("=");
		Serial.print(g_u8Ping[i]);
		Serial.print("cm ");
	}
	Serial.println();
#endif

}

#ifdef NUM_AVERAGE
unsigned char averageValues(unsigned char vals[NUM_PING_CH][NUM_AVERAGE], int pingNum) {
	long temp = 0;
	for (int i = 0; i < NUM_AVERAGE; i++) {
		temp += vals[pingNum][i];
	}
	temp /= NUM_AVERAGE;
	return (unsigned char) temp;
}
#endif
