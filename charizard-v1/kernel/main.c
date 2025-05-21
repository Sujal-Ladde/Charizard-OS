#include "types.h"
#include "vga.h"

void arch_init();
void schedule();

void kmain() {
  vga_clear();
  arch_init();
  vga_write_string("Charizard OS v1.0\n");
  while (1) {
    // Idle loop; scheduling via timer IRQ (not yet hooked)
  }
}