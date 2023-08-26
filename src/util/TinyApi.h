//
// Created by Alex on 26.08.2023.
//

#ifndef OAKLAND_ESP01_TINYAPI_H
#define OAKLAND_ESP01_TINYAPI_H
#include <Arduino.h>

class TinyApi {
private:
    const static char end_of_command = ';';
    const static char argument_delimiter = ':';

public:
    static bool sleep(long duration);

    static String getState();


};


#endif //OAKLAND_ESP01_TINYAPI_H
