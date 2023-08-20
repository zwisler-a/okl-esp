//
// Created by Alex on 20.08.2023.
//

#include "CompletableTask.h"
#include "Scheduler.h"

CompletableTask::CompletableTask(unsigned long executionOffset) : Task(executionOffset) {}

CompletableTask::CompletableTask(unsigned long executionOffset, Task *onComplete) : Task(executionOffset),
                                                                                    onComplete(onComplete) {
}

void CompletableTask::complete() {
    if (onComplete != nullptr) {
        Scheduler::schedule(onComplete);
    }
}

void CompletableTask::setOnComplete(Task *onCompleteTask) {
    onComplete = onCompleteTask;
}


