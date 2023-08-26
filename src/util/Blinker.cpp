//
// Created by Alex on 20.08.2023.
//

#include "Arduino.h"
#include "Blinker.h"
#include "global.h"
#include "scheduler/Scheduler.h"

static std::deque<Sequence> sequences;
static LedBlinkTask *task = new LedBlinkTask(0, 2);

void Blinker::run() {
    if (!task->running && !sequences.empty()) {
        play(sequences.back());
        sequences.pop_back();
    }
}

void Blinker::play(Sequence sequence) {
    if (task->running) {
        sequences.push_front(sequence);
    } else {

        task->running = true;
        setPattern(sequence);

        task->setOnComplete(new Blinker(0), 1000);

        Scheduler::schedule(task);
    }
}

void Blinker::setPattern(Sequence sequence) {
    switch (sequence) {
        case START: {
            task->pattern = startup_pattern;
            task->patternLength = startup_pattern_length;
            break;
        }
        case WIFI_CONNECTED: {
            task->pattern = wifi_connected_pattern;
            task->patternLength = wifi_connected_pattern_length;
            break;
        }
        case WIFI_CONNECT_FAILED: {
            task->pattern = wifi_connection_failed_pattern;
            task->patternLength = wifi_connection_failed_length;
            break;
        }
        case HTTP_ERROR: {
            task->pattern = http_error_response_pattern;
            task->patternLength = http_error_response_pattern_length;
            break;
        }
        case SLEEP_RESPONSE: {
            task->pattern = sleep_response_pattern;
            task->patternLength = sleep_response_pattern_length;
            break;
        }
        case DATA_SEND: {
            task->pattern = data_send_pattern;
            task->patternLength = data_send_pattern_length;
            break;
        }
        case STATUS_READ_ERROR: {
            task->pattern = status_read_error_pattern;
            task->patternLength = status_read_error_pattern_length;
            break;
        }
    }

}

Blinker::Blinker(unsigned long executionOffset) : Task(executionOffset) {}

