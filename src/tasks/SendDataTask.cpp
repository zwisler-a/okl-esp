//
// Created by Alex on 11.08.2023.
//

#include <WiFiClient.h>
#include <ESP8266HTTPClient.h>
#include "SendDataTask.h"
#include "scheduler/Scheduler.h"
#include "LedBlinkTask.h"
#include "global.h"

SendDataTask::SendDataTask(unsigned long executionOffset) : CompletableTask(executionOffset) {

}


void SendDataTask::run() {
    WiFiClient client;
    HTTPClient http;

    String serverPath = constants::ENDPOINT;
    serverPath.concat(constants::ESP_NAME);

    // Your Domain name with URL path or IP address with path
    http.begin(client, serverPath.c_str());

    Serial.println("H");

    String res = Serial.readString();
    String payload = R"({"attiny": ")";
    payload.concat(res);
    payload.concat("\"}");
    // Send HTTP GET request
    http.addHeader("Content-Type", "application/json");
    int httpResponseCode = http.POST(payload);

    if (httpResponseCode < 0) {
        Scheduler::schedule(new LedBlinkTask(0, 2, http_error_response_pattern, http_error_response_pattern_length));
    }

    // Free resources
    http.end();
    complete();
}
