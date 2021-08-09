#include <check.h>
#include "commandbuffer.h"

START_TEST(simple_add_issue) {
  Command_t foo;
  foo.commandCode = 1;

  ck_assert_int_ne( 0, CommandBuffer_add( &foo ));

  Command_t bar = CommandBuffer_getNext();
  ck_assert_int_eq( 0, memcmp( &foo, &bar, sizeof(Command_t)));
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
