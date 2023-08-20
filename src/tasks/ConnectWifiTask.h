//
// Created by Alex on 11.08.2023.
//

#ifndef OAKLAND_ESP01_CONNECTWIFITASK_H
#define OAKLAND_ESP01_CONNECTWIFITASK_H


#include "scheduler/Task.h"
#include "scheduler/CompletableTask.h"

class ConnectWifiTask : public CompletableTask {
public:
    explicit ConnectWifiTask(unsigned long executionOffset);

protected:
    void run() override;
};


#endif //OAKLAND_ESP01_CONNECTWIFITASK_H
