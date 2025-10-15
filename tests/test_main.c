#include "unity.h"

// Test prototypes
void test_read_temperature_raw_range(void);
void test_validate_temperature_range_valid(void);
void test_validate_temperature_range_invalid(void);
void test_check_temperature_status(void);
void test_get_temperature_celsius(void);
void test_raw_to_celsius(void);
void test_celsius_to_fahrenheit(void);
void test_is_temperature_rising(void);

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_read_temperature_raw_range);
    RUN_TEST(test_validate_temperature_range_valid);
    RUN_TEST(test_validate_temperature_range_invalid);
    RUN_TEST(test_check_temperature_status);
    RUN_TEST(test_get_temperature_celsius);
    RUN_TEST(test_raw_to_celsius);
    RUN_TEST(test_celsius_to_fahrenheit);
    RUN_TEST(test_is_temperature_rising);
    return UNITY_END();
}
