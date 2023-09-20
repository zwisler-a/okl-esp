//
// Created by Alex on 11.08.2023.
//

#include <WiFiClientSecure.h>
#include <ESP8266HTTPClient.h>
#include "SendDataTask.h"
#include "global.h"
#include "util/Blinker.h"
#include "util/TinyApi.h"
#include "scheduler/Scheduler.h"
#include "SleepTask.h"
#include <ArduinoJson.h>

SendDataTask::SendDataTask(unsigned long executionOffset) : CompletableTask(executionOffset) {

}


void SendDataTask::run() {
    WiFiClientSecure client;

    client.setInsecure();
    client.connect(constants::ENDPOINT, 443);

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
    http.addHeader("Authorization", constants::BASIC_AUTH);

    int httpResponseCode = http.POST(payload);

    if (httpResponseCode == 200) {
        StaticJsonDocument<96> config;

        String response = http.getString();
        DeserializationError error = deserializeJson(config, response.c_str(), response.length());

        if (error) {
            Blinker::play(HTTP_ERROR);
            return;
        }

        int sleep_time = config["s"];
        Blinker::play(DATA_SEND);
        Scheduler::schedule(new SleepTask(5000, sleep_time));

    } else if (httpResponseCode == 400) {
        Blinker::play(HTTP_ERROR);
        Scheduler::schedule(this, 1000 * 10);
        return;
    } else if (httpResponseCode < 0) {
        Blinker::play(HTTP_ERROR);
        Scheduler::schedule(new SleepTask(5000));
        return;
    } else {
        Scheduler::schedule(new SleepTask(4000));
        Blinker::play(HTTP_ERROR);
    }



    // Free resources
    http.end();
    complete();
}
