//
// Created by Alex on 17.08.2023.
//

#include "SleepTask.h"
#include "scheduler/Scheduler.h"
#include "util/TinyApi.h"
#include "global.h"

#define LED_PIN 2

SleepTask::SleepTask(unsigned long executionOffset, long sleepTime) : Task(executionOffset), sleepTime(sleepTime) {

}

SleepTask::SleepTask(unsigned long executionOffset) : Task(executionOffset) {
    sleepTime = constants::default_sleep_time;
}


void SleepTask::run() {
    bool success = TinyApi::sleep(sleepTime);
    if (!success) {
        Scheduler::schedule(this, 20 * 1000);
    }
}


