//
// Created by Alex on 04.06.2023.
//

#ifndef PLAYGROUND_SCHEDULER_H
#define PLAYGROUND_SCHEDULER_H


#include "Task.h"

class Scheduler {
private:
    static Task *getNextTaskToExecute();

    static unsigned long detectSleepTime();

    static void sleep(unsigned long delay);

public:
    static unsigned long averageWaitTime;

    static void schedule(Task *task);

    static void schedule(Task *task, int offset);

    static void loop();
};


#endif //PLAYGROUND_SCHEDULER_H
