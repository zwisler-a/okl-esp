//
// Created by Alex on 19.08.2023.
//

#ifndef OAKLAND_ESP01_LEDBLINKTASK_H
#define OAKLAND_ESP01_LEDBLINKTASK_H


#include "scheduler/Task.h"
#include "scheduler/CompletableTask.h"

class LedBlinkTask : public CompletableTask {
public:
    LedBlinkTask(unsigned long executionOffset, int pin);

    void run() override;

    bool running;



    unsigned short patternLength;
    unsigned short *pattern;
private:
    int ledPin;


};

#endif //OAKLAND_ESP01_LEDBLINKTASK_H
