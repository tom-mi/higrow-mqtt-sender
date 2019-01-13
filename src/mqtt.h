#ifndef MQTT_H
#define MQTT_H

#include <Arduino.h>
#include <ArduinoJson.h>
#include <PubSubClient.h>

boolean reconnect_mqtt(PubSubClient client, const char* client_id);

#endif
