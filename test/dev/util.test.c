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

START_TEST(test_isNumeric) {
  ck_assert_int_eq(0, isNumeric("+"));
  ck_assert_int_eq(1, isNumeric("95"));
  ck_assert_int_eq(1, isNumeric("-0"));
  ck_assert_int_eq(1, isNumeric("   +12"));
  ck_assert_int_eq(0, isNumeric("  19e"));
}
END_TEST

START_TEST(test_fitsInt16) {
  ck_assert_int_ne(0, fitsInt16("32767"));
  ck_assert_int_ne(0, fitsInt16("+32767"));
  ck_assert_int_ne(0, fitsInt16("\t+32767\t"));

  ck_assert_int_ne(0, fitsInt16("-32768"));
  ck_assert_int_ne(0, fitsInt16("\t-32768"));
  ck_assert_int_ne(0, fitsInt16("-32768\n"));

  ck_assert_int_eq(0, fitsInt16("Hello World!"));
  ck_assert_int_eq(0, fitsInt16("32768"));
  ck_assert_int_eq(0, fitsInt16("-32769"));
  ck_assert_int_eq(0, fitsInt16("100000"));

  ck_assert_int_ne(0, fitsInt16("0"));
  ck_assert_int_ne(0, fitsInt16("-0)"));
  ck_assert_int_ne(0, fitsInt16("+0)"));
  ck_assert_int_ne(0, fitsInt16("256"));
  ck_assert_int_ne(0, fitsInt16("-59"));
  
  ck_assert_int_eq(0, fitsInt16(""));
  ck_assert_int_eq(0, fitsInt16("+f00"));
}
END_TEST

Suite* stringTestSuite() {
  Suite *s;
  TCase *tcStrToInt;
  TCase *tcIsNumeric;
  TCase *tcFitsInt16;

  tcStrToInt = tcase_create("strToInt()");
  tcase_add_test(tcStrToInt, test_strToInt_valid_positive_numerals);
  tcase_add_test(tcStrToInt, test_strToInt_valid_negative_numerals);
  tcase_add_test(tcStrToInt, test_strToInt_leading_whitespace);
  tcase_add_test(tcStrToInt, test_strToInt_trailing_nonnumeral);
  tcase_add_test(tcStrToInt, test_strToInt_invalid_input);

  tcIsNumeric = tcase_create("isNumeric()");
  tcase_add_test(tcIsNumeric, test_isNumeric);

  tcFitsInt16 = tcase_create("fitsInt16()");
  tcase_add_test(tcFitsInt16, test_fitsInt16);

  s = suite_create("string");
  suite_add_tcase(s, tcStrToInt);
  suite_add_tcase(s, tcIsNumeric);
  suite_add_tcase(s, tcFitsInt16);

  return s;
}

