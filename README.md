# higrow-mqtt-sender

Firmware for the [HiGrow Plants Monitoring Sensor](https://hackaday.io/project/25253-higrow-plants-monitoring-sensor)
that sends sensor readings to a MQTT broker

## Overview

The firmware will send the following values to a MQTT topic named `higrow_plant_monitor/$device_id/state`:
- `device_id` - equals the MAC address of the builtin ESP32)
- `temperature_celsius` - Air temperature recorded by the DHT11 sensor
- `humidity_percent` - Air humidity recorded by the DHT11 sensor
- `water` - Soil water level (0..1, calibrated with air / a glass of water)
- `light` - Taken from the official firmware, but seems not to work with older versions of the board. Not calibrated.

## Deployment

Declare the following environment variables according to your environment:

    WIFI_SSID
    WIFI_PASS
    MQTT_BROKER_HOST
    MQTT_BROKER_PORT

Connect the device via USB and flash it with platformio:

    platformio run --target upload
