#include "unity.h"
#include "string.h"

void setUp(void) {
	/* This function runs before each test */
}

void tearDown(void) {
	/* This function runs after each test */
}

/* Test kstrlen with a simple string */
void test_kstrlen_simple_string(void) {
	char* str = "Hello";
	TEST_ASSERT_EQUAL_INT(5, kstrlen(str));
}

/* Test kstrlen with empty string */
void test_kstrlen_empty_string(void) {
	char* str = "";
	TEST_ASSERT_EQUAL_INT(0, kstrlen(str));
}

/* Test kstrlen with single character */
void test_kstrlen_single_character(void) {
	char* str = "A";
	TEST_ASSERT_EQUAL_INT(1, kstrlen(str));
}

/* Test kstrlen with longer string */
void test_kstrlen_longer_string(void) {
	char* str = "The quick brown fox";
	TEST_ASSERT_EQUAL_INT(19, kstrlen(str));
}

void test_katoi_no_sign_positive_integer(void) {
	char* str = "123";
	TEST_ASSERT_EQUAL_INT(123, katoi(str));
}

void test_katoi_negative_integer(void) {
	char* str = "-123";
	TEST_ASSERT_EQUAL_INT(-123, katoi(str));
}

void test_katoi_plus_sign_positive_integer(void) {
	char* str = "+123";
	TEST_ASSERT_EQUAL_INT(123, katoi(str));
}

void test_katoi_leading_whitespace_positive_integer(void) {
	char* str = "   123";
	TEST_ASSERT_EQUAL_INT(123, katoi(str));
}

void test_katoi_stops_at_non_numberic(void) {
	char* str = "123a4";
	TEST_ASSERT_EQUAL_INT(123, katoi(str));
}

void test_katoi_stops_at_middle_space(void) {
	char* str = "123 4";
	TEST_ASSERT_EQUAL_INT(123, katoi(str));
}

void test_katoi_stops_at_invalid_character(void) {
	char* str = "@";
	TEST_ASSERT_EQUAL_INT(0, katoi(str));
}


int main(void) {
	UNITY_BEGIN();
	// kstrlen tests
	RUN_TEST(test_kstrlen_simple_string);
	RUN_TEST(test_kstrlen_empty_string);
	RUN_TEST(test_kstrlen_single_character);
	RUN_TEST(test_kstrlen_longer_string);
	// katoi tests
	RUN_TEST(test_katoi_no_sign_positive_integer);
	RUN_TEST(test_katoi_negative_integer);
	RUN_TEST(test_katoi_plus_sign_positive_integer);
	RUN_TEST(test_katoi_leading_whitespace_positive_integer);
	RUN_TEST(test_katoi_stops_at_non_numberic);
	RUN_TEST(test_katoi_stops_at_middle_space);
	RUN_TEST(test_katoi_stops_at_invalid_character);

	return UNITY_END();
}
