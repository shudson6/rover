/*******************************************************************************
 * command.h
 *
 * Declarations and #defines for users of the command interpreter.
 */

#ifndef __INCLUDE_COMMAND_INTERPRETER
#define __INCLUDE_COMMAND_INTERPRETER

typedef enum {
  CMDCODE_NULL = 0,
  CMDCODE_ERROR,
  CMDCODE_STATUS,
  CMDCODE_SETEN,
  CMDCODE_SETDIR,
  CMDCODE_RUN,
} CommandCode_t;

typedef enum {
  CMDERR_NONE = 0,
  CMDERR_TOO_LONG,
  CMDERR_UNRECOGNIZED_COMMAND,
  CMDERR_UNRECOGNIZED_PARAM,
  CMDERR_UNEXPECTED_PARAM,
  CMDERR_MOTOR_EXPECTED,
  CMDERR_TIME_EXPECTED,

  // too many commands in the command buffer
  CMDERR_BUFFER_FULL
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
 * void Command_clear(Command_t* cmd)
 *
 * Sets all members of cmd to zero.
 */
void Command_clear(Command_t* cmd);

/********************************************************************************
 * const char* Command_getErrorMessage(CommandParseError_t errCode)
 *
 * Get the error message that goes with the error code.
 */
const char* Command_getErrorMessage(CommandParseError_t errCode);

/********************************************************************************
 * CommandParseError_t Command_parse(const char* str)
 *
 * Parse a string into a Command_t.
 * If str is a valid command string, it will be added to the command buffer and
 * this function will return zero.
 * If parsing fails, return value will be a nonzero error code. A descriptive
 * error message can be obtained by calling Command_getErrorMessage() with the
 * error code.
 */
CommandParseError_t Command_parse(const char* str);

#endif // __INCLUDE_COMMAND_INTERPRETER

