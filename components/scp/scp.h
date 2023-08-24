#ifndef SCP_H
#define SCP_H

#include <stdio.h>

// Define start and end patterns
const uint8_t startPattern[] = {0xAA, 0xBB, 0xCC, 0xDD};
const uint8_t endPattern[] = {0xDD, 0xCC, 0xBB, 0xAA};

const uint8_t v1 = 0x01;
const uint8_t MAIN_MODULE_ID = 0x01;
typedef struct
{
  uint8_t version;
  uint8_t moduleId;
  uint8_t commandId;
} Command;

typedef struct
{
  uint8_t reciverId;
  uint8_t senderId;
  Command command;
  uint8_t *data;
  uint16_t checksum;
} Message;

void configure(const uint8_t senderId);
void sendCommand(
    const uint8_t reciverId,
    const Command *commandId,
    const uint8_t *data,
    const uint8_t dataLength);

Command cmdAlive_1 = {v1, MAIN_MODULE_ID, 0x01}; // Version: 1, Command ID: 0x01

#endif