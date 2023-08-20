//
// Created by Alex on 05.06.2023.
//

#include "Task.h"
#include <Arduino.h>

Task::Task(unsigned long executionOffset) {
    this->executionTime = millis() + executionOffset;
}

void Task::run() {
}

void Task::updateExecutionTime(unsigned long offset) {
    executionTime = millis() + offset;
}

unsigned long Task::getExecutionTime() const {
    return executionTime;
}

