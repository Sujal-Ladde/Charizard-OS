#include "vga.h"

void vga_clear() {
  for (u32 y = 0; y < VGA_HEIGHT; y++) {
    for (u32 x = 0; x < VGA_WIDTH; x++) {
      VGA_BUFFER[y * VGA_WIDTH + x] = vga_entry(' ', 0x07);
    }
  }
  cursor_row = cursor_col = 0;
}

void vga_putc(char c) {
  if (c == '\n') {
    cursor_col = 0;
    cursor_row++;
  } else {
    VGA_BUFFER[cursor_row * VGA_WIDTH + cursor_col] = vga_entry(c, 0x07);
    cursor_col++;
    if (cursor_col >= VGA_WIDTH) {
      cursor_col = 0;
      cursor_row++;
    }
  }
  // scrolling not implemented
}

void vga_write_string(const char* str) {
  while (*str) vga_putc(*str++);
}