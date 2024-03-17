#include <Arduino.h>
#include "soc/timer_group_reg.h"
#include "display_service.h"

TaskHandle_t cpu0 = NULL;
TaskHandle_t cpu1 = NULL;
display_service display;


inline void feedTheDog() {}

inline void loop_cpu0(void) {
    display.loop();
}

inline void loop_cpu1(void) {
}

void setup_cpu0(void *pvParameters) {
    display.setup();
    for (;;) {
        loop_cpu0();
    }
}

void setup_cpu1(void *pvParameters) {
    // debug
    Serial.begin(115200);

    for (;;) {
        loop_cpu1();
    }
}

void setup() {
    xTaskCreatePinnedToCore(
            setup_cpu0, /* Task function. */
            "cpu0", /* name of task. */
            10000, /* Stack size of task */
            NULL, /* parameter of the task */
            1, /* priority of the task */
            &cpu0, /* Task handle to keep track of created task */
            0); /* pin task to core 0 */

    xTaskCreatePinnedToCore(
            setup_cpu1, /* Task function. */
            "cpu1", /* name of task. */
            10000, /* Stack size of task */
            NULL, /* parameter of the task */
            1, /* priority of the task */
            &cpu1, /* Task handle to keep track of created task */
            1); /* pin task to core 1 */
}

void loop(void) {
    feedTheDog();

    static uint32_t time1;
    uint32_t time2 = millis();
    if (time2 - time1 >= 1000) {
        time1 = time2;
    }
}
