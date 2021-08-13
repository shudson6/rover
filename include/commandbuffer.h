/********************************************************************************
 * commandbuffer.h
 *
 * Declarations for command buffer functions. 
 * Parsed commands are queued in the command buffer for execution.
 */

#ifndef __INCLUDE_COMMAND_BUFFER
#define __INCLUDE_COMMAND_BUFFER

#include "command.h"

/*******************************************************************************
 * unsigned char CommandBuffer_add(Command_t* command)
 *
 * Copies the pointed-to command object into the command buffer, if there is
 * room for it.
 *
 * Returns:
 * nonzero if the command was added
 * zero if not (due to insufficient capacity)
 */
unsigned char CommandBuffer_add(Command_t* command);

/*******************************************************************************
 * unsigned char CommandBuffer_hasNext()
 *
 * Determines if there is at least one command in the buffer, waiting to be
 * issued.
 * Calling this is the same as
 *   CommandBuffer_capacityLeft() > 0
 *
 * Returns:
 * nonzero if buffer is nonempty
 * zero if it's empty
 */
unsigned char CommandBuffer_hasNext();

/*******************************************************************************
 * Command_t CommandBuffer_getNext()
 *
 * Returns the next command and removes it from the cue.
 */
Command_t CommandBuffer_getNext();

/*******************************************************************************
 * int CommandBuffer_capacityLeft()
 *
 * Gets the remaining capacity of the command buffer, that is, how many more
 * commands can be added to it.
 *
 * Returns:
 * the remaining capacity
 */
int CommandBuffer_capacityLeft();

/*******************************************************************************
 * unsigned char CommandBuffer_hasRoomFor(int num)
 *
 * Determines if command buffer has capacity remaining to add num elements.
 *
 * Returns:
 * nonzero if so
 * zero if not
 */
unsigned char CommandBuffer_hasRoomFor(int num);

/*******************************************************************************
 * void CommandBuffer_clear()
 *
 * Clears the command buffer.
 */
void CommandBuffer_clear();

#endif // __INCLUDE_COMMAND_BUFFER
