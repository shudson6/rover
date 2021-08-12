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

START_TEST(cant_add_to_full_buffer) {
  Command_t cmd;
  cmd.commandCode = CMDCODE_NULL;
  cmd.value = 1;
  while ( CommandBuffer_capacityLeft() > 0 ) {
    ck_assert_int_ne( 0, CommandBuffer_add( &cmd ));
    cmd.value++;
  }
  ck_assert_int_eq( 0, CommandBuffer_add( &cmd ));
}
END_TEST

START_TEST(cycle_buffer_at_capacity) {
  int capacity = CommandBuffer_capacityLeft();
  int nextValue = 1;
  Command_t cmd;
  cmd.commandCode = CMDCODE_NULL;
  // fill buffer then
  // go around a few times, issuing and checking a command, and adding another
  int loops = capacity * 4 + 1;
  for (int i = 0; i < loops; i++) {
    if (i >= capacity) {
      Command_t issued = CommandBuffer_getNext();
      int checkVal = nextValue - capacity;
      ck_assert_int_eq( checkVal, issued.value );
      ck_assert_int_eq( 1, CommandBuffer_capacityLeft());
      ck_assert_int_ne( 0, CommandBuffer_hasRoomFor( 1 ));
    }
    cmd.value = nextValue;
    CommandBuffer_add( &cmd );
    nextValue++;
  }
}
END_TEST

Suite* commandBufferTestSuite() {
  Suite *s;
  TCase *tcSimpleAddIssue;
  TCase *tcFullBuffer;
  TCase *tcCycleBuffer;

  tcSimpleAddIssue = tcase_create("add and issue");
  tcase_add_test(tcSimpleAddIssue, simple_add_issue);
  
  tcFullBuffer = tcase_create("can't add to full buffer");
  tcase_add_test(tcFullBuffer, cant_add_to_full_buffer);

  tcCycleBuffer = tcase_create("cycling buffer at capacity");
  tcase_add_test(tcCycleBuffer, cycle_buffer_at_capacity);

  s = suite_create("command buffer");
  suite_add_tcase(s, tcSimpleAddIssue);
  suite_add_tcase(s, tcFullBuffer);
  suite_add_tcase(s, tcCycleBuffer);

  return s;
}
