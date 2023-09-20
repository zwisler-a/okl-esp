//
// Created by Alex on 17.08.2023.
//

#ifndef OAKLAND_ESP01_SLEEPTASK_H
#define OAKLAND_ESP01_SLEEPTASK_H


#include "scheduler/Task.h"

class SleepTask : public Task {
private:
    long sleepTime;
protected:
    void run() override;

public:
    explicit SleepTask(unsigned long executionOffset, long sleepTime);
    explicit SleepTask(unsigned long executionOffset);
};


#endif //OAKLAND_ESP01_SLEEPTASK_H
