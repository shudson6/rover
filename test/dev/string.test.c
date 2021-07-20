#include <check.h>
#include <stdlib.h>
#include "string.h"


START_TEST(test_string_isalnum) {
  char c = 0;
  do {
    if ((c >= 'A' && c <= 'Z')
       || (c >= 'a' && c <= 'z')
       || (c >= '0' && c <= '9')) {
      ck_assert_uint_ne(isAlphaNum(c), 0);
    }
    else {
      ck_assert_uint_eq(isAlphaNum(c), 0);
    }
    c++;
  } while (c);
}
END_TEST

START_TEST(test_string_isalpha) {
  char c = 0;
  do {
    if ((c >= 'A' && c <= 'Z')
       || (c >= 'a' && c <= 'z')) {
      ck_assert_uint_ne(isAlpha(c), 0);
    }
    else {
      ck_assert_uint_eq(isAlpha(c), 0);
    }
    c++;
  } while (c);
}
END_TEST

START_TEST(test_string_isdigit) {
  char c = 0;
  do {
    if (c >= '0' && c <= '9') {
      ck_assert_uint_ne(isDigit(c), 0);
    }
    else {
      ck_assert_uint_eq(isDigit(c), 0);
    }
    c++;
  } while (c);
}
END_TEST

START_TEST(test_string_islower) {
  char c = 0;
  do {
    if (c >= 'a' && c <= 'z') {
      ck_assert_uint_ne(isLower(c), 0);
    }
    else {
      ck_assert_uint_eq(isLower(c), 0);
    }
    c++;
  } while (c);
}
END_TEST

START_TEST(test_string_isspace) {
  // null at the end is just to let the index go past the valid entries
  char match[] = { 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x20, 0x00 };
  char c = 0;
  int si = 0; // index into match[]
  do {
    if (c == match[si]) {
      ck_assert_uint_ne(isSpace(c), 0);
      si++;
    }
    else {
      ck_assert_uint_eq(isSpace(c), 0);
    }
    c++;
  } while (c);
}
END_TEST

START_TEST(test_string_isupper) {
  char c = 0;
  do {
    if (c >= 'A' && c <= 'Z') {
      ck_assert_uint_ne(isUpper(c), 0);
    }
    else {
      ck_assert_uint_eq(isUpper(c), 0);
    }
    c++;
  } while (c);
}
END_TEST

START_TEST(test_string_isxdigit) {
  char match[] = "0123456789ABCDEFabcdef";
  char c = 0;
  int m = 0; // index into match[]
  do {
    if (c == match[m]) {
      ck_assert_uint_ne(isXdigit(c), 0);
      m++;
    }
    else {
      ck_assert_uint_eq(isXdigit(c), 0);
    }
    c++;
  } while (c);
}
END_TEST

Suite* stringTestSuite() {
  Suite *s;
  TCase *tcIsalnum;
  TCase *tcIsalpha;
  TCase *tcIsdigit;
  TCase *tcIslower;
  TCase *tcIsspace;
  TCase *tcIsupper;
  TCase *tcIsxdigit;

  s = suite_create("string");
  tcIsalnum = tcase_create("isAlphaNum()");
  tcIsalpha = tcase_create("isAlpha()");
  tcIsdigit = tcase_create("isDigit()");
  tcIslower = tcase_create("isLower()");
  tcIsspace = tcase_create("isSpace()");
  tcIsupper = tcase_create("isUpper()");
  tcIsxdigit = tcase_create("isXdigit()");

  tcase_add_test(tcIsalnum, test_string_isalnum);
  suite_add_tcase(s, tcIsalnum);

  tcase_add_test(tcIsalpha, test_string_isalpha);
  suite_add_tcase(s, tcIsalpha);

  tcase_add_test(tcIsdigit, test_string_isdigit);
  suite_add_tcase(s, tcIsdigit);

  tcase_add_test(tcIslower, test_string_islower);
  suite_add_tcase(s, tcIslower);

  tcase_add_test(tcIsspace, test_string_isspace);
  suite_add_tcase(s, tcIsspace);

  tcase_add_test(tcIsupper, test_string_isupper);
  suite_add_tcase(s, tcIsupper);

  tcase_add_test(tcIsxdigit, test_string_isxdigit);
  suite_add_tcase(s, tcIsxdigit);

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
