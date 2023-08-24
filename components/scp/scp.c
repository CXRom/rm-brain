#include "scp.h"

#include <stdio.h>

uint8_t senderId = 0;

void configure(const uint8_t senderId)
{
}

void sendCommand(
    const uint8_t reciverId,
    const Command *command,
    const uint8_t *data,
    const uint8_t dataLength)
{
  Message message;
  message.reciverId = reciverId;
  message.senderId = senderId; // Set the sender ID
  message.command = *command;
  message.data = (uint8_t *)malloc(dataLength); // Allocate memory for data
  memcpy(message.data, data, dataLength);       // Copy the data
  message.checksum = calculateChecksum(&message, sizeof(Message) - sizeof(message.checksum));

  // TODO: Implement sending the message over your communication interface

  free(message.data); // Free the allocated memory for data
}