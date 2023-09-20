//
// Created by Alex on 20.08.2023.
//

#ifndef OAKLAND_ESP01_GLOBAL_H
#define OAKLAND_ESP01_GLOBAL_H


namespace constants {
    inline const char *ESP_NAME = "TestESP3";
    inline const char *SSID = "<ssid>";
    inline const char *PASS = "<pw>";
    inline const char *BASIC_AUTH = "Basic <auth>";

    inline const char *ENDPOINT = "<endpoint>";

    inline const int attiny_baud = 4800;
    inline const int default_sleep_time = 60;
}

inline unsigned short LONG = 2000;
inline unsigned short SHORT = 300;

inline unsigned short startup_pattern[] = {SHORT, LONG};
inline unsigned short startup_pattern_length = 2;

inline unsigned short wifi_connected_pattern[] = {SHORT, SHORT, LONG};
inline unsigned short wifi_connected_pattern_length = 3;

inline unsigned short data_send_pattern[] = {SHORT, SHORT, SHORT, LONG};
inline unsigned short data_send_pattern_length = 4;

inline unsigned short wifi_connection_failed_pattern[] = {SHORT, SHORT, SHORT, SHORT, LONG};
inline unsigned short wifi_connection_failed_length = 5;

inline unsigned short http_error_response_pattern[] = {SHORT, SHORT, SHORT, SHORT, SHORT, LONG};
inline unsigned short http_error_response_pattern_length = 6;

inline unsigned short sleep_response_pattern[] = {SHORT, SHORT, SHORT, SHORT, SHORT, SHORT, LONG};
inline unsigned short sleep_response_pattern_length = 7;

inline unsigned short status_read_error_pattern[] = {SHORT, SHORT, SHORT, SHORT, SHORT, SHORT, SHORT, LONG};
inline unsigned short status_read_error_pattern_length = 8;


#endif //OAKLAND_ESP01_GLOBAL_H
