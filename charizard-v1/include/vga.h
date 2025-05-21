#ifndef VGA_H
#define VGA_H

#include "types.h"

#define VGA_WIDTH 80
#define VGA_HEIGHT 25
static volatile u16* const VGA_BUFFER = (u16*)0xB8000;

static u8 cursor_row = 0;
static u8 cursor_col = 0;

static inline u16 vga_entry(u8 ch, u8 color) {
  return (u16)ch | (u16)color << 8;
}

void vga_clear();
void vga_putc(char c);
void vga_write_string(const char* str);

#endif // VGA_H