//
// Created by Alex on 19.08.2023.
//
#include "Arduino.h"
#include "LedBlinkTask.h"
#include "scheduler/Scheduler.h"

int current = 0;

int ledState = LOW;

LedBlinkTask::LedBlinkTask(unsigned long executionOffset, int pin, unsigned short *pattern,
                           unsigned short patternLength)
        : CompletableTask(executionOffset), ledPin(pin), pattern(pattern), patternLength(patternLength) {
    pinMode(ledPin, OUTPUT);
}


void LedBlinkTask::run() {
    if (current < patternLength) {
        Scheduler::schedule(this, pattern[current]);
        current++;
        ledState = ledState == LOW ? HIGH : LOW;
        digitalWrite(ledPin, ledState);
    } else {
        current = 0;
        digitalWrite(ledPin, HIGH);
        complete();
    }
}



