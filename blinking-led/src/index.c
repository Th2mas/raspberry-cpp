#include <pigpio.h>

int main() {
    // Initialize the library
    if (gpioInitialise() < 0) {
        return 1;
    }

    // Set the LED pin
    int pinNumber = 24;
    int speedInSeconds = 1;
    gpioSetMode(pinNumber, PI_OUTPUT);

    for (int i = 0; i < 3; i++) {
        gpioWrite(pinNumber, 1);    // on
        time_sleep(speedInSeconds);
        gpioWrite(pinNumber, 0);    // off
        time_sleep(speedInSeconds);
    }

    // Stop the library
    gpioTerminate();

    return 0;
}
