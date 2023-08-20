//
// Created by Alex on 19.08.2023.
//

#ifndef OAKLAND_ESP01_LEDBLINKTASK_H
#define OAKLAND_ESP01_LEDBLINKTASK_H


#include "scheduler/Task.h"
#include "scheduler/CompletableTask.h"

class LedBlinkTask : public CompletableTask {
public:
    LedBlinkTask(unsigned long executionOffset, int pin, unsigned short *pattern, unsigned short patternLength);

    void run() override;

private:
    int ledPin;
    unsigned short *pattern;
    unsigned short patternLength;

};

#endif //OAKLAND_ESP01_LEDBLINKTASK_H
