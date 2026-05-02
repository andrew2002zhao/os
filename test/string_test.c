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

void test_kitoa_positive_integer(void) {
	int number = 123;
	TEST_ASSERT_EQUAL_STRING("123", kitoa(number));
}

void test_kitoa_negative_integer(void) {
	int number = -123;
	TEST_ASSERT_EQUAL_STRING("-123", kitoa(number));
}

void test_kitoa_zero(void) {
	int number = 0;
	TEST_ASSERT_EQUAL_STRING("0", kitoa(number));
}

void test_kstrcat_regular_strings(void) {
	char* destination = "abc";
	char* source = "123";
	TEST_ASSERT_EQUAL_STRING("abc123", kstrcat(destination, source));
}

void test_kstrcat_empty_source_string(void) {
	char* destination = "abc";
	char* source = "";
	TEST_ASSERT_EQUAL_STRING("abc", kstrcat(destination, source));
}

void test_kstrcat_empty_destination_string(void) {
	char* destination = "";
	char* source = "123";
	TEST_ASSERT_EQUAL_STRING("123", kstrcat(destination, source));
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
