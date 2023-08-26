//
// Created by Alex on 11.08.2023.
//

#include <WiFiClient.h>
#include <ESP8266HTTPClient.h>
#include "SendDataTask.h"
#include "global.h"
#include "util/Blinker.h"
#include "util/TinyApi.h"

SendDataTask::SendDataTask(unsigned long executionOffset) : CompletableTask(executionOffset) {

}


void SendDataTask::run() {
    WiFiClient client;
    HTTPClient http;

    String serverPath = constants::ENDPOINT;
    serverPath.concat(constants::ESP_NAME);

    // Your Domain name with URL path or IP address with path
    http.begin(client, serverPath.c_str());

    String payload = R"({"attiny": ")";
    payload.concat(TinyApi::getState());
    payload.concat("\"}");
    // Send HTTP GET request
    http.addHeader("Content-Type", "application/json");
    int httpResponseCode = http.POST(payload);

    if (httpResponseCode < 0) {
        Blinker::play(HTTP_ERROR);
    }

    Blinker::play(DATA_SEND);

    // Free resources
    http.end();
    complete();
}
