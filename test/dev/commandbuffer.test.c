#include <check.h>
#include "commandbuffer.h"

START_TEST(simple_add_issue) {
}
END_TEST

Suite* commandBufferTestSuite() {
  Suite *s;
  TCase *tcSimpleAddIssue;

  tcSimpleAddIssue = tcase_create("add and issue");
  tcase_add_test(tcSimpleAddIssue, simple_add_issue);

  s = suite_create("command buffer");
  suite_add_tcase(s, tcSimpleAddIssue);

  return s;
}
