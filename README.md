# Logging

Experimental module for logging. With this logging module you register your devices where you want to log and call log function with severity level.

## Example

A example of usage

```cpp

#include "logging.h"

int main(void) {
    logging::registerDevices(std::cout, "log.txt"); // Log to cout and log.txt text file
    // ...
    INFO("This is a info log message"); // Log with info severity
}

```
