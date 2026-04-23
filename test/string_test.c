#include "unity.h"
#include "string.h"

void setUp(void) {
	/* This function runs before each test */
}

void tearDown(void) {
	/* This function runs after each test */
}

/* Test strlen with a simple string */
void test_strlen_simple_string(void) {
	char* str = "Hello";
	TEST_ASSERT_EQUAL_INT(5, strlen(str));
}

/* Test strlen with empty string */
void test_strlen_empty_string(void) {
	char* str = "";
	TEST_ASSERT_EQUAL_INT(0, strlen(str));
}

/* Test strlen with single character */
void test_strlen_single_character(void) {
	char* str = "A";
	TEST_ASSERT_EQUAL_INT(1, strlen(str));
}

/* Test strlen with longer string */
void test_strlen_longer_string(void) {
	char* str = "The quick brown fox";
	TEST_ASSERT_EQUAL_INT(19, strlen(str));
}

int main(void) {
	UNITY_BEGIN();
	RUN_TEST(test_strlen_simple_string);
	RUN_TEST(test_strlen_empty_string);
	RUN_TEST(test_strlen_single_character);
	RUN_TEST(test_strlen_longer_string);
	return UNITY_END();
}
