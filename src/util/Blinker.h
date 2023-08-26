//
// Created by Alex on 20.08.2023.
//

#ifndef OAKLAND_ESP01_BLINKER_H
#define OAKLAND_ESP01_BLINKER_H

#include <deque>
#include "scheduler/Task.h"
#include "../tasks/LedBlinkTask.h"

enum Sequence {
    START,
    WIFI_CONNECTED,
    WIFI_CONNECT_FAILED,
    DATA_SEND,
    HTTP_ERROR,
    SLEEP_RESPONSE,
    STATUS_READ_ERROR,
};

class Blinker : public Task {
public:
    explicit Blinker(unsigned long executionOffset);

    static void play(Sequence sequence, Task *onComplete);

    static void play(Sequence sequence);

    void run() override;

private:
    static void setPattern(Sequence sequence);
};


#endif //OAKLAND_ESP01_BLINKER_H
