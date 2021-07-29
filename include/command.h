/*******************************************************************************
 * command.h
 *
 * Declarations and #defines for users of the command interpreter.
 */

#ifndef __INCLUDE_COMMAND_INTERPRETER
#define __INCLUDE_COMMAND_INTERPRETER

typedef enum {
  COMMAND_ERROR,
  COMMAND_STATUS,
  COMMAND_ENABLE,
  COMMAND_SETDIR,
  COMMAND_RUN
} CommandCode_t;

typedef enum {
  CMDERR_NONE = 0,
  CMDERR_TOO_LONG,
  CMDERR_UNRECOGNIZED_COMMAND,
  CMDERR_UNRECOGNIZED_PARAM,
  CMDERR_UNEXPECTED_PARAM,
  CMDERR_MOTOR_EXPECTED,
  CMDERR_TIME_EXPECTED
} CommandParseError_t;

typedef struct {
  CommandCode_t commandCode;
  // bits 0-5 indicate which drive motors are affected
  unsigned char driveMotors;
  // bits 0-3 indicate which steering motors are affected
  unsigned char turnMotors;
  // numeric parameter, e.g.:
  // duration for 'run'
  // direction for 'setdir'
  // on/off for 'enable'
  unsigned char value;
} Command_t;

/********************************************************************************
 * const char* Command_getErrorMessage(CommandParseError_t errCode)
 *
 * Get the error message that goes with the error code.
 */
const char* Command_getErrorMessage(CommandParseError_t errCode);

/********************************************************************************
 * CommandParseError_t Command_parse(const char* str, Command_t* cmd) 
 *
 * Parse a string into a Command_t.
 * If str is a valid command string, it will be encoded into cmd and this
 * function will return zero.
 * If parsing fails, return value will be a nonzero error code. A descriptive
 * error message can be obtained by calling Command_getErrorMessage() with the
 * error code.
 */
CommandParseError_t Command_parse(const char* str, Command_t* cmd);

#endif // __INCLUDE_COMMAND_INTERPRETER

