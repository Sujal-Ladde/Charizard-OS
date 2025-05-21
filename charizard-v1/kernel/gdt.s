// Assembly for gdt_flush
.global gdt_flush
.type gdt_flush, @function
// ptr in eax
gdt_flush:
    lgdt [eax]
    mov ax, 0x10      // data segment selector
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov ss, ax
    jmp 0x08:flush_ret
flush_ret:
    ret