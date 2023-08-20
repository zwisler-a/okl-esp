//
// Created by Alex on 05.06.2023.
//

#ifndef PLAYGROUND_TASK_H
#define PLAYGROUND_TASK_H


class Task {
private:
    unsigned long executionTime;
public:
    explicit Task(unsigned long executionOffset);
    virtual void run();

    void updateExecutionTime(unsigned long execTime);

    unsigned long getExecutionTime() const;
};


#endif //PLAYGROUND_TASK_H
