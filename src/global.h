//
// Created by Alex on 20.08.2023.
//

#ifndef OAKLAND_ESP01_GLOBAL_H
#define OAKLAND_ESP01_GLOBAL_H

namespace constants {
    inline const char *ESP_NAME = "TestESP";
    inline const char *SSID = "<ssid>";
    inline const char *PASS = "<pass>";
    inline const char *ENDPOINT = "http://192.168.178.103:8080/";

    inline const int attiny_baud = 4800;
    inline const int sleep_time = 60;
}


inline unsigned short startup_pattern[] = {200, 200, 200, 200, 1000};
inline unsigned short startup_pattern_length = 5;

inline unsigned short wifi_connected_pattern[] = {1000, 200, 1000};
inline unsigned short wifi_connected_pattern_length = 3;

inline unsigned short http_error_response_pattern[] = {200, 200, 200, 200, 200, 200, 1000, 1000, 1000, 1000};
inline unsigned short http_error_response_pattern_length = 10;

inline unsigned short sleep_response_pattern[] = {200, 200, 200, 200, 200, 200, 1000, 10, 1000};
inline unsigned short sleep_response_pattern_length = 9;


#endif //OAKLAND_ESP01_GLOBAL_H
