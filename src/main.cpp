#include <Arduino.h>
#include "scheduler/Scheduler.h"
#include "tasks/ConnectWifiTask.h"
#include "tasks/SendDataTask.h"
#include "global.h"
#include "util/Blinker.h"

#define LED_PIN 2

void setup() {
    Serial.begin(constants::attiny_baud);
    pinMode(LED_PIN, OUTPUT);
    digitalWrite(LED_PIN, HIGH);
    delay(1000);

    auto *connectWifiTask = new ConnectWifiTask(0);
    auto *sendDataTask = new SendDataTask(0);
    Blinker::play(START);
    connectWifiTask->setOnComplete(sendDataTask, 1000);
    Scheduler::schedule(connectWifiTask);
}

void loop() {
    Scheduler::loop();
}