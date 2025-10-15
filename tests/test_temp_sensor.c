#include "unity.h"
#include "temp_sensor.h"
#include "temp_converter.h" // For mocking

// Mock for raw_to_celsius
float raw_to_celsius(int raw_value) {
    return (raw_value / 1023.0) * 165.0 - 40.0;
}

void setUp(void) {}
void tearDown(void) {}

void test_read_temperature_raw_range(void) {
    int raw = read_temperature_raw();
    TEST_ASSERT_INT_WITHIN(0, 1023, raw);
}

void test_validate_temperature_range_valid(void) {
    TEST_ASSERT_TRUE(validate_temperature_range(25.0));
    TEST_ASSERT_TRUE(validate_temperature_range(-40.0));
    TEST_ASSERT_TRUE(validate_temperature_range(125.0));
}

void test_validate_temperature_range_invalid(void) {
    TEST_ASSERT_FALSE(validate_temperature_range(-41.0));
    TEST_ASSERT_FALSE(validate_temperature_range(126.0));
}

void test_check_temperature_status(void) {
    TEST_ASSERT_EQUAL_STRING("NORMAL", check_temperature_status(25.0));
    TEST_ASSERT_EQUAL_STRING("COLD", check_temperature_status(-20.0));
    TEST_ASSERT_EQUAL_STRING("HOT", check_temperature_status(90.0));
    TEST_ASSERT_EQUAL_STRING("CRITICAL", check_temperature_status(121.0));
}

void test_get_temperature_celsius(void) {
    float temp = get_temperature_celsius();
    // Since the raw value is random, we just check if it's in a plausible range
    TEST_ASSERT_FLOAT_WITHIN(1.0, -40.0, 125.0, temp);
}
