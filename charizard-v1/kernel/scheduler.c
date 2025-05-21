#include "types.h"

#define MAX_TASKS 4
static int current = 0;

void schedule() {
  current = (current + 1) % MAX_TASKS;
  // Context switch stub: save/restore registers
}