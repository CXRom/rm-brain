#ifndef SCP_H
#define SCP_H

#include <stdio.h>

// Define start and end patterns
const uint8_t startPattern[] = {0xAA, 0xBB, 0xCC, 0xDD};
const uint8_t endPattern[] = {0xDD, 0xCC, 0xBB, 0xAA};

typedef struct
{
  uint8_t moduleId;
  uint8_t senderId;
  uint8_t version;
  uint8_t commandId;
  uint8_t dataLength;
  uint8_t *data;
  uint16_t checksum;
} Message;

void initialConfig();

#endif