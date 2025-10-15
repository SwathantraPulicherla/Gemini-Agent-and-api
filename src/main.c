#include <stdio.h>
#include "temp_sensor.h"

int main() {
    float temp_c = get_temperature_celsius();
    printf("Current temperature: %.2f°C\n", temp_c);
    printf("Temperature status: %s\n", check_temperature_status(temp_c));
    return 0;
}
