//
// Created by Alex on 11.08.2023.
//

#ifndef OAKLAND_ESP01_SENDDATATASK_H
#define OAKLAND_ESP01_SENDDATATASK_H


#include "scheduler/Task.h"
#include "scheduler/CompletableTask.h"

class SendDataTask : public CompletableTask {

public:
    explicit SendDataTask(unsigned long executionOffset);

    void run() override;
};


#endif //OAKLAND_ESP01_SENDDATATASK_H
