//
// Created by Alex on 20.08.2023.
//

#ifndef OAKLAND_ESP01_COMPLETABLETASK_H
#define OAKLAND_ESP01_COMPLETABLETASK_H


#include "Task.h"

class CompletableTask : public Task {
public:
    CompletableTask(unsigned long executionOffset, Task *onComplete);

    explicit CompletableTask(unsigned long executionOffset);

    void setOnComplete(Task *onCompleteTask, long delay);

protected:
    void complete();

private:
    Task *onComplete;
    long delay;
};


#endif //OAKLAND_ESP01_COMPLETABLETASK_H
