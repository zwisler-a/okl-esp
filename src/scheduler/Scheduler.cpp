//
// Created by Alex on 04.06.2023.
//

#include "Scheduler.h"
#include "Task.h"
#include <Arduino.h>
#include <algorithm>
#include <deque>

std::deque<Task *> tasks;
unsigned long Scheduler::averageWaitTime;

void Scheduler::schedule(Task *task) {
    tasks.push_front(task);
}

void Scheduler::schedule(Task *task, int offset) {
    task->updateExecutionTime(offset);
    tasks.push_front(task);
}

void Scheduler::loop() {
    Task *nextTask = getNextTaskToExecute();
    if (nextTask == nullptr) { return; }
    nextTask->run();
    auto sleepTime = detectSleepTime();
    sleep(sleepTime);
}

void Scheduler::sleep(unsigned long time) {
    if (time < 10) return;
    if (time > 10) {
        delay(time);
    }
//    else {
//        Serial.println("Going to sleep");
//        Serial.println(time);
//        if (time >= INT_MAX) {
//            Serial.println("Shit we need to sleep very long");
//            Watchdog.sleep(INT_MAX);
//        } else {
//            int wasAsleep = Watchdog.sleep((int) time);
//            Serial.println(wasAsleep);
//        }
//        Serial.println("Back again");
//    }
}

unsigned long Scheduler::detectSleepTime() {
    auto nextTask = tasks.back();
    if (nextTask == nullptr) return 0;
    unsigned long nextExecutionTime = nextTask->getExecutionTime();
    if (nextExecutionTime <= millis()) return 0;
    return nextExecutionTime - millis();
}

Task *Scheduler::getNextTaskToExecute() {
    if (tasks.empty()) { return nullptr; }
    std::sort(tasks.begin(), tasks.end(),
              [](const Task *a, const Task *b) { return (a->getExecutionTime() > b->getExecutionTime()); });
    Task *nextTask = tasks.back();
    if (nextTask->getExecutionTime() > millis()) return nullptr;
    tasks.pop_back();
    return nextTask;
}






