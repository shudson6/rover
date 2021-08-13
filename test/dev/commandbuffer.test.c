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

START_TEST(report_accurate_capacity) {
  int capacity = CommandBuffer_capacityLeft();
  Command_t cmd;
  for (int i = 1; i <= capacity; i++) {
    CommandBuffer_add( &cmd );
    ck_assert_int_eq( capacity - i, CommandBuffer_capacityLeft());
    ck_assert_int_ne( 0, CommandBuffer_hasRoomFor( capacity - i ));
    ck_assert_int_eq( 0, CommandBuffer_hasRoomFor( capacity - i + 1 ));
  }
  for (int i = 1; i <= capacity; i++) {
    CommandBuffer_getNext();
    ck_assert_int_eq( i, CommandBuffer_capacityLeft());
    ck_assert_int_ne( 0, CommandBuffer_hasRoomFor( i ));
    ck_assert_int_eq( 0, CommandBuffer_hasRoomFor( i + 1 ));
  }
}
END_TEST

START_TEST(results_of_clear) {
  int capacity = CommandBuffer_capacityLeft();
  Command_t cmd;
  cmd.commandCode = 3;
  CommandBuffer_add( &cmd );
  CommandBuffer_add( &cmd );
  CommandBuffer_add( &cmd );
  ck_assert_int_eq( capacity - 3, CommandBuffer_capacityLeft());
  CommandBuffer_clear();
  ck_assert_int_eq( 0, CommandBuffer_hasNext());
  ck_assert_int_eq( capacity, CommandBuffer_capacityLeft());
  
  cmd = CommandBuffer_getNext();
  ck_assert_int_eq( 0, cmd.commandCode );
}
END_TEST

START_TEST(null_command_when_empty) {
  int capacity = CommandBuffer_capacityLeft();
  Command_t cmd = CommandBuffer_getNext();
  ck_assert_int_eq( CMDCODE_NULL, cmd.commandCode );

  // fill the buffer
  cmd.commandCode = 3;
  while ( CommandBuffer_hasRoomFor( 1 )) {
    CommandBuffer_add( &cmd );
  }
  // get back a bunch of 3s
  while ( CommandBuffer_capacityLeft() < capacity ) {
    cmd = CommandBuffer_getNext();
    ck_assert_int_eq( 3, cmd.commandCode );
  }
  // should be empty
  ck_assert_int_eq( 0, CommandBuffer_hasNext());
  cmd = CommandBuffer_getNext();
  ck_assert_int_eq( CMDCODE_NULL, cmd.commandCode );
  ck_assert_int_eq( capacity, CommandBuffer_capacityLeft());
}
END_TEST

Suite* commandBufferTestSuite() {
  Suite *s;
  TCase *tcSimpleAddIssue;
  TCase *tcFullBuffer;
  TCase *tcCycleBuffer;
  TCase *tcCapReport;
  TCase *tcResultClear;
  TCase *tcEmpty;

  tcSimpleAddIssue = tcase_create("add and issue");
  tcase_add_test(tcSimpleAddIssue, simple_add_issue);
  
  tcFullBuffer = tcase_create("can't add to full buffer");
  tcase_add_test(tcFullBuffer, cant_add_to_full_buffer);

  tcCycleBuffer = tcase_create("cycling buffer at capacity");
  tcase_add_test(tcCycleBuffer, cycle_buffer_at_capacity);

  tcCapReport = tcase_create("accuracy of reported capacity");
  tcase_add_test(tcCapReport, report_accurate_capacity);

  tcResultClear = tcase_create("clear buffer");
  tcase_add_test(tcResultClear, results_of_clear);

  tcEmpty = tcase_create("empty buffer issues null command");
  tcase_add_test(tcEmpty, null_command_when_empty);

  s = suite_create("command buffer");
  suite_add_tcase(s, tcSimpleAddIssue);
  suite_add_tcase(s, tcFullBuffer);
  suite_add_tcase(s, tcCycleBuffer);
  suite_add_tcase(s, tcCapReport);
  suite_add_tcase(s, tcResultClear);
  suite_add_tcase(s, tcEmpty);

  return s;
}
