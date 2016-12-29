#pragma once
#include "Actuator.h"
#include "Program.h"

class HeaterActuator :
	public Actuator
{
private:
	String tag;
	const int relestatus_off = 0;
	const int relestatus_on = 1;
	const int relestatus_disabled = 2;
	const int relestatus_enabled = 3;

	
	int manualMode;

	String subaddress = "HeaterActuator-";

	const int relePin = D5; // rel? pin
	const bool RELE_ON = HIGH;//LOW
	const bool RELE_OFF = LOW;//LOW
	static int const sensor_local = 0;
	unsigned long last_RemoteSensor = 0;
	unsigned long remoteSensorTimeout = 36000; // tempo dopo il quale il programa si disattiva

public:
	static const int MANUALMODE_DISABLED = 0;
	static const int MANUALMODE_AUTO = 1;
	static const int MANUALMODE_OFF = 2;

	HeaterActuator();
	~HeaterActuator();
	void updateReleStatus();
	virtual String getJSON() override;
	void setStatus(int status);
	void setManualMode(int status, int mode);
	int getStatus();
	int getManualMode();
	void setReleStatus(int status);
	int getReleStatus();
	void enableRele(boolean on);
	bool statusChanged();
	bool releStatusChanged();
	void saveOldReleStatus();
	void saveOldStatus();
	void init(String MACAddress);
	void setTargetTemperature(float target);
	float getTargetTemperature();
	void setRemoteTemperature(float remote);
	float getRemoteTemperature();
	float getLocalTemperature();
	void setSensorRemote(bool enable, int sensorId);
	int getRemoteSensorId();
	bool sensorIsRemote();
	int getLocalSensorId();
	bool programEnded();
	time_t getRemaininTime();
	int getActiveProgram();
	int getActiveTimeRange();
	void setLocalTemperature(float temperature);
	void changeProgram(int status, long duration, int manual, bool sensorRemote, float remotetemperature, int sensorId, float target, int program, int timerange, int localsensor);
	virtual String getSensorAddress();

	time_t programStartTime = 0;
	time_t programDuration = 30000;

	Program programSettings;
private:
	int currentStatus = Program::STATUS_IDLE;
	int oldCurrentStatus = currentStatus;
	bool releStatus = false;
	bool oldReleStatus = false;
	float targetTemperature = 0.0;
	float remoteTemperature = 0;
	int remoteSensorId = 0; //indica se il sensore � locale o remoto
	int localSensorId = 0;
	bool sensorRemote = false;
	int activeProgram = -1;
	int activeTimerange = -1;

	unsigned long totalConsumptionTime = 0;
	unsigned long lastConsumptionEnableTime = 0;
	unsigned long ConsumptionStartTime;

	float localAvTemperature = 0;
	float oldLocalAvTemperature = 0;
	
};


