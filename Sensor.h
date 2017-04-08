#pragma once
#include "Arduino.h"
#include "Logger.h"

class Sensor
{
private:
	static String tag;
	static Logger logger;

public:
	Sensor();
	~Sensor();

	String getJSON();
	static const int sensorNameLen = 20;
	static const int sensorAddressLen = 20;
	static const int sensorTypeLen = 20;

	virtual String getJSONFields();
	virtual String getSensorAddress();

	String sensorname = "sensorname";
	String type = "type";
	bool enabled = true;
	uint8_t pin;
	uint8_t sensorAddr[8]; // indirizzi sensori
	
	Sensor* next = NULL;
};

