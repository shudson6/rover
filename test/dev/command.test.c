#include <check.h>
#include "command.h"
#include "commandbuffer.h"
#include <string.h>

START_TEST(command_clear) {
  Command_t cmdEmpty;
  cmdEmpty.commandCode = CMDCODE_NULL;
  cmdEmpty.driveMotors = 0;
  cmdEmpty.turnMotors = 0;
  cmdEmpty.value = 0;

  Command_t cmd;
  cmd.commandCode = CMDCODE_RUN;
  cmd.driveMotors = 0x57;
  cmd.turnMotors = 0x02;
  cmd.value = 42;

  Command_clear( &cmd );

  // getting 'implicit declaration' warnings when using
  // ck_assert_mem_eq
  ck_assert_int_eq( 0, memcmp( &cmdEmpty, &cmd, sizeof( Command_t )));
}
END_TEST

START_TEST(error_messages_match) {
  ck_assert_str_eq( "none", Command_getErrorMessage( CMDERR_NONE ));
  ck_assert_str_eq( "too long", Command_getErrorMessage( CMDERR_TOO_LONG ));
  ck_assert_str_eq( "unrecognized command", Command_getErrorMessage( CMDERR_UNRECOGNIZED_COMMAND ));
  ck_assert_str_eq( "unrecognized param", Command_getErrorMessage( CMDERR_UNRECOGNIZED_PARAM ));
  ck_assert_str_eq( "unexpected param", Command_getErrorMessage( CMDERR_UNEXPECTED_PARAM ));
  ck_assert_str_eq( "motor expected", Command_getErrorMessage( CMDERR_MOTOR_EXPECTED ));
  ck_assert_str_eq( "time expected", Command_getErrorMessage( CMDERR_TIME_EXPECTED ));
}
END_TEST

Suite* commandTestSuite() {
  Suite *s;
  TCase *tcClear;
  TCase *tcMatch;

  tcClear = tcase_create("clear command");
  tcase_add_test(tcClear, command_clear);

  tcMatch = tcase_create("error messages match codes");
  tcase_add_test(tcMatch, error_messages_match);

  s = suite_create("command parser");
  suite_add_tcase(s, tcClear);
  suite_add_tcase(s, tcMatch);

  return s;
}
