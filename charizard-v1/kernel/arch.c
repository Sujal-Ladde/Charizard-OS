#include "multiboot.h"
#include "types.h"

// GDT setup
extern void gdt_flush(u32);

struct gdt_entry {
  u16 limit_low;
  u16 base_low;
  u8  base_middle;
  u8  access;
  u8  granularity;
  u8  base_high;
} __attribute__((packed));

struct gdt_ptr {
  u16 limit;
  u32 base;
} __attribute__((packed));

static struct gdt_entry gdt[3];
static struct gdt_ptr   gp;

static void init_gdt() {
  gp.limit = (sizeof(struct gdt_entry) * 3) - 1;
  gp.base  = (u32)&gdt;

  // Null descriptor
  gdt[0] = (struct gdt_entry){0,0,0,0,0,0};
  // Code segment
  gdt[1] = (struct gdt_entry){
    .limit_low    = 0xFFFF,
    .base_low     = 0,
    .base_middle  = 0,
    .access       = 0x9A,
    .granularity  = 0xCF,
    .base_high    = 0
  };
  // Data segment
  gdt[2] = (struct gdt_entry){
    .limit_low    = 0xFFFF,
    .base_low     = 0,
    .base_middle  = 0,
    .access       = 0x92,
    .granularity  = 0xCF,
    .base_high    = 0
  };

  gdt_flush((u32)&gp);
}

void arch_init() {
  init_gdt();
  // IDT & PIC init would go here
}