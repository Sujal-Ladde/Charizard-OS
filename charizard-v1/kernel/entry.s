#include "multiboot.h"

.section .multiboot
.align 4
.long MULTIBOOT_MAGIC
.long MULTIBOOT_FLAGS
.long -(MULTIBOOT_MAGIC + MULTIBOOT_FLAGS)

.text
.global _start
_start:
  call kmain
.spin:
  cli
  hlt
  jmp .spin