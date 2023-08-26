//
// Created by Alex on 17.08.2023.
//

#include "SleepTask.h"
#include "scheduler/Scheduler.h"
#include "global.h"
#include "util/TinyApi.h"

#define LED_PIN 2

SleepTask::SleepTask(unsigned long executionOffset) : Task(executionOffset) {

}

void SleepTask::run() {
    bool success = TinyApi::sleep(constants::sleep_time);
    if (!success) {
        Scheduler::schedule(this, 20 * 1000);
    }
}

