#include "boot/multiboot.h"

//Define Macros
#define CHECK_FLAG(flags,bit)   ((flags) & (1 << (bit)))

void framebuffer_check(multiboot_info_t* multiboot){
  int framebuffer_type;
  if (CHECK_FLAG (multiboot->flags, 12)){
    suspend(1);
    qemu_printf_string("Framebuffer flags(12) checked! \\/");
    switch (mbi->framebuffer_type){
      case MULTIBOOT_FRAMEBUFFER_TYPE_RGB:
        qemu_printf_string("Framebuffer type is rgb");
        framebuffer_type = 1;
        return framebuffer_type;
    }
    return framebuffer_type;
  }
  return framebuffer_type;
}

void init_framebuffer(multiboot_info_t* mbi){
  if(framebuffer_check(mbi)==1){
    framebuffer_buffer = (uint32_t*)((uintptr_t)mbi->framebuffer_addr);
    framebuffer_bpp = mbi->framebuffer_bpp;
    framebuffer_pitch = mbi->framebuffer_pitch;
    framebuffer_height = mbi->framebuffer_height;
    framebuffer_width = mbi->framebuffer_width;
  }
}
