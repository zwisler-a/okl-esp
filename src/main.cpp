#include <Arduino.h>
#include "scheduler/Scheduler.h"
#include "tasks/ConnectWifiTask.h"
#include "tasks/SendDataTask.h"
#include "tasks/SleepTask.h"
#include "tasks/LedBlinkTask.h"
#include "global.h"

#define LED_PIN 2

void setup() {
    Serial.begin(constants::attiny_baud);
    pinMode(LED_PIN, OUTPUT);
    digitalWrite(LED_PIN, HIGH);

    auto *startupBlinkTask = new LedBlinkTask(0, LED_PIN, startup_pattern, startup_pattern_length);
    auto *wifiConnectedBlinkTask = new LedBlinkTask(0, LED_PIN, wifi_connected_pattern, wifi_connected_pattern_length);
    auto *connectWifiTask = new ConnectWifiTask(0);
    auto *sendDataTask = new SendDataTask(100);
    auto *sleepTask = new SleepTask(0);

    startupBlinkTask->setOnComplete(connectWifiTask);
    connectWifiTask->setOnComplete(wifiConnectedBlinkTask);
    wifiConnectedBlinkTask->setOnComplete(sendDataTask);
    sendDataTask->setOnComplete(sleepTask);

    Scheduler::schedule(startupBlinkTask, 0);
}

void loop() {
    Scheduler::loop();
}