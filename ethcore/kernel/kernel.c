#include "kernel/gdt.h"
#include "kernel/idt.h"
#include "kernel/kernel_shell.h"
#include "kernel/keyboard.h"
#include "kernel/timer.h"
#include "kernel/vga.h"
#include "klib/kint.h"
#include "klib/kio.h"

void kmain (void)
{
  initGdt ();
  initIdt ();
  initTimer ();
  vga_init ();
  keyboard_init ();

  __kputs ("Loading Eth-OS...\n");

  kernel_shell_init ();
  kernel_shell_loop ();
}
