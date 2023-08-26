//
// Created by Alex on 11.08.2023.
//

#include <ESP8266WiFi.h>
#include "ConnectWifiTask.h"
#include "scheduler/Scheduler.h"
#include "global.h"
#include "LedBlinkTask.h"
#include "util/Blinker.h"

bool wait_for_connection = false;

ConnectWifiTask::ConnectWifiTask(unsigned long executionOffset) : CompletableTask(executionOffset) {}


void ConnectWifiTask::run() {
    if (!wait_for_connection) {
        WiFi.begin(constants::SSID, constants::PASS);
        wait_for_connection = true;
    }
    if (WiFi.status() == WL_CONNECT_FAILED) {
        Blinker::play(WIFI_CONNECT_FAILED);
        wait_for_connection = false;
        Scheduler::schedule(this, 5000);
        return;
    }

    if (WiFi.status() == WL_CONNECTED) {
        Blinker::play(WIFI_CONNECTED);
        complete();
        return;
    }
    Scheduler::schedule(this, 500);
}

