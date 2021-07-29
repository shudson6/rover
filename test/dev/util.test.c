#include <check.h>
#include <stdlib.h>
#include "util.h"

START_TEST(test_strToInt_valid_positive_numerals) {
  ck_assert_int_eq(1, strToInt("1"));
  ck_assert_int_eq(42, strToInt("42"));
  ck_assert_int_eq(32767, strToInt("32767"));
  ck_assert_int_eq(0, strToInt("0"));
}
END_TEST

START_TEST(test_strToInt_valid_negative_numerals) {
  ck_assert_int_eq(-1, strToInt("-1"));
  ck_assert_int_eq(-32768, strToInt("-32768"));
  ck_assert_int_eq(-42, strToInt("-42"));
}
END_TEST

START_TEST(test_strToInt_leading_whitespace) {
  ck_assert_int_eq(1337, strToInt("  1337"));
  ck_assert_int_eq(1337, strToInt("\t\n +1337"));
  ck_assert_int_eq(-1337, strToInt(" \f-1337"));
}
END_TEST

START_TEST(test_strToInt_trailing_nonnumeral) {
  ck_assert_int_eq(1337, strToInt("1337x.4"));
  ck_assert_int_eq(42, strToInt("42 42"));
  ck_assert_int_eq(91, strToInt("91$$$"));
}
END_TEST

START_TEST(test_strToInt_invalid_input) {
  ck_assert_int_eq(0, strToInt("  a"));
  ck_assert_int_eq(0, strToInt("+-4"));
  ck_assert_int_eq(0, strToInt("x460"));
}
END_TEST

Suite* stringTestSuite() {
  Suite *s;
  TCase *tcStrToInt;

  s = suite_create("string");
  tcStrToInt = tcase_create("strToInt()");

  tcase_add_test(tcStrToInt, test_strToInt_valid_positive_numerals);
  tcase_add_test(tcStrToInt, test_strToInt_valid_negative_numerals);
  tcase_add_test(tcStrToInt, test_strToInt_leading_whitespace);
  tcase_add_test(tcStrToInt, test_strToInt_trailing_nonnumeral);
  tcase_add_test(tcStrToInt, test_strToInt_invalid_input);
  suite_add_tcase(s, tcStrToInt);

  return s;
}

int main() {
  int numberFailed;
  Suite *s;
  SRunner *sr;

  s = stringTestSuite();
  sr = srunner_create(s);

  srunner_run_all(sr, CK_NORMAL);
  numberFailed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (numberFailed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
