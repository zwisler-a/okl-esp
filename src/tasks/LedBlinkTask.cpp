//
// Created by Alex on 19.08.2023.
//
#include "Arduino.h"
#include "LedBlinkTask.h"
#include "scheduler/Scheduler.h"

int current = 0;
int isPause = false;
int ledOnState = LOW;
int ledOffState = HIGH;

LedBlinkTask::LedBlinkTask(unsigned long executionOffset, int pin)
        : CompletableTask(executionOffset), ledPin(pin) {
    pinMode(ledPin, OUTPUT);
    running = false;
    patternLength = 0;
}


void LedBlinkTask::run() {
    if (current < patternLength) {
        running = true;
        if (!isPause) {

            digitalWrite(ledPin, ledOnState);
            Scheduler::schedule(this, pattern[current]);
            current++;
        } else {
            digitalWrite(ledPin, ledOffState);
            Scheduler::schedule(this, 200);
        }
        isPause = !isPause;
    } else {
        current = 0;
        isPause = false;
        running = false;
        digitalWrite(ledPin, ledOffState);
        complete();
    }
}



