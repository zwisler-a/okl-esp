//
// Created by Alex on 11.08.2023.
//

#include <ESP8266WiFi.h>
#include "ConnectWifiTask.h"
#include "scheduler/Scheduler.h"
#include "global.h"

bool wait_for_connection = false;

ConnectWifiTask::ConnectWifiTask(unsigned long executionOffset) : CompletableTask(executionOffset) {}


void ConnectWifiTask::run() {
    if (!wait_for_connection) {
        WiFi.begin(constants::SSID, constants::PASS);
        wait_for_connection = true;
    }
    if (WiFi.status() != WL_CONNECTED) {
        Scheduler::schedule(this, 500);
    } else {
        complete();
    }
}

