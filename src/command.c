#include "command.h"

#define COMMANDBUF_SIZE 48

const char* const ERROR_MESSAGES[] = {
  "none",
  "too long",
  "unrecognized command",
  "unrecognized param",
  "unexpected param",
  "motor expected",
  "time expected"
};

const char* Command_getErrorMessage(CommandParseError_t errCode) {
  if (errCode < sizeof( ERROR_MESSAGES ) / sizeof(const char*)) {
    return ERROR_MESSAGES[errCode];
  }
  return 0;
}
