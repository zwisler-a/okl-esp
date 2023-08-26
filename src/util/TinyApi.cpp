//
// Created by Alex on 26.08.2023.
//
#include "TinyApi.h"
#include "Blinker.h"

bool TinyApi::sleep(long duration) {
    Serial.print("S");
    Serial.print(argument_delimiter);
    Serial.print(duration);
    Serial.print(end_of_command);
    String response = Serial.readStringUntil(end_of_command);
    if (response.startsWith("!")) {
        Blinker::play(STATUS_READ_ERROR);
    }
    return response.startsWith("#S:");
}

String TinyApi::getState() {
    {
        String arguments;
        String response;
        short retryCount = 0;
        bool validRead;
        do {
            validRead = false;
            Serial.print("H");
            Serial.print(end_of_command);
            response = Serial.readStringUntil(end_of_command);
            if (response.startsWith("!")) {
                Blinker::play(STATUS_READ_ERROR);
                while (Serial.available() > 0) {
                    Serial.read();
                }
                continue;
            }
            if (response.startsWith("#H")) {
                int idxDelimiter = response.lastIndexOf(argument_delimiter);

                if (idxDelimiter > 0) {
                    arguments = response.substring(idxDelimiter + 1);
                    validRead = true;
                }
            }
            delay(100);
            retryCount++;
        } while ((arguments.isEmpty() || !validRead) && retryCount <= 3);

        if (arguments.isEmpty()) {
            Blinker::play(STATUS_READ_ERROR);
        }

        return arguments;
    }
}

