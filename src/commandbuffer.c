/*******************************************************************************
 * commandbuffer.c
 *
 * Definitions for command buffer functions.
 */

#include "commandbuffer.h"

#define BUF_SIZE 8

// circular buffer
Command_t commandBuffer[ BUF_SIZE ];
Command_t *cbNextIssue = commandBuffer;
Command_t *cbNextAdd = commandBuffer;
unsigned char commandsQueued = 0;

/**
 * increments a pointer within the circular buffer.
 * intended for use with cbNextIssue, cbNextAdd
 */
Command_t* incrementIndex(Command_t** ptr) {
  (*ptr)++;
  if (*ptr == commandBuffer + BUF_SIZE) {
    *ptr = commandBuffer;
  }
  return *ptr;
}

// 'clears' the command buffer by setting pointers and commandsQueued to zero
void CommandBuffer_clear() {
  cbNextIssue = commandBuffer;
  cbNextAdd = commandBuffer;
  commandsQueued = 0;
}

unsigned char CommandBuffer_hasNext() {
  return commandsQueued > 0;
}

Command_t CommandBuffer_getNext() {
  Command_t cmd = *cbNextIssue;

  // normally, increment issue index and decrement count
  if (commandsQueued > 0) {
    incrementIndex( &cbNextIssue );
    commandsQueued--;
  }
  // but if the queue is empty, don't do that. instead set the command to null
  else {
    cmd.commandCode = CMDCODE_NULL;
  }

  return cmd;
}

unsigned char CommandBuffer_add(Command_t* command) {
  if (commandsQueued >= BUF_SIZE) {
    return 0;
  }

  *cbNextAdd = *command;
  incrementIndex( &cbNextAdd );
  commandsQueued++;

  return 1;
}

int CommandBuffer_capacityLeft() {
  return BUF_SIZE - commandsQueued;
}

unsigned char CommandBuffer_hasRoomFor(int num) {
  return num <= CommandBuffer_capacityLeft();
}
