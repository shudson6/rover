/********************************************************************************
 * commandbuffer.h
 *
 * Declarations for command buffer functions. 
 * Parsed commands are queued in the command buffer for execution.
 */

#ifndef __INCLUDE_COMMAND_BUFFER
#define __INCLUDE_COMMAND_BUFFER

#include "command.h"

unsigned char CommandBuffer_add(Command_t* command);

unsigned char CommandBuffer_hasNext();

Command_t CommandBuffer_getNext();

int CommandBuffer_capacityLeft();

unsigned char CommandBuffer_hasRoomFor(int num);

void CommandBuffer_clear();

#endif // __INCLUDE_COMMAND_BUFFER
