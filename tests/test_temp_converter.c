#include "unity.h"
#include "temp_converter.h"

void setUp(void) {}
void tearDown(void) {}

void test_raw_to_celsius(void) {
    TEST_ASSERT_EQUAL_FLOAT(-40.0, raw_to_celsius(0));
    TEST_ASSERT_EQUAL_FLOAT(125.0, raw_to_celsius(1023));
    TEST_ASSERT_EQUAL_FLOAT(42.5, raw_to_celsius(511.5));
}

void test_celsius_to_fahrenheit(void) {
    TEST_ASSERT_EQUAL_FLOAT(32.0, celsius_to_fahrenheit(0.0));
    TEST_ASSERT_EQUAL_FLOAT(212.0, celsius_to_fahrenheit(100.0));
}

void test_is_temperature_rising(void) {
    TEST_ASSERT_TRUE(is_temperature_rising(20.0, 25.0, 4.0));
    TEST_ASSERT_FALSE(is_temperature_rising(20.0, 22.0, 3.0));
}
