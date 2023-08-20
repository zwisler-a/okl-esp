//
// Created by Alex on 17.08.2023.
//

#include <HardwareSerial.h>
#include "SleepTask.h"
#include "scheduler/Scheduler.h"
#include "LedBlinkTask.h"
#include "global.h"

#define LED_PIN 2
bool wait_for_response = false;

SleepTask::SleepTask(unsigned long executionOffset) : Task(executionOffset) {

}

void SleepTask::run() {
    if (!wait_for_response) {
        Serial.print("S:");
        Serial.println(constants::sleep_time);
    } else if (Serial.available()) {
        String res = Serial.readString();
        Scheduler::schedule(new LedBlinkTask(0, LED_PIN, sleep_response_pattern, sleep_response_pattern_length));
    } else {
        Scheduler::schedule(this, 100);
    }
}

