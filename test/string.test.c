#include <check.h>
#include <stdlib.h>
#include "string.h"

START_TEST(test_string_isalnum) {
  ck_assert(isalnum('a') != 0);
}
END_TEST

Suite* stringTestSuite() {
  Suite *s;
  TCase *tcCore;

  s = suite_create("string");
  tcCore = tcase_create("Core");

  tcase_add_test(tcCore, test_string_isalnum);
  suite_add_tcase(s, tcCore);

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
