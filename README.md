# Integrate with littlevGL on mangOH

<img src="https://user-images.githubusercontent.com/17214533/51510335-40256700-1e2f-11e9-8903-af65c5368326.jpg" width="350" alt="accessibility text">

## Project Set-up
1. Update configure file: `lv_conf.h`:
   * Update default font type: `#define LV_FONT_DEFAULT        &lv_font_monospace_8` for using monochome display.
   * Update font size: `#define USE_LV_FONT_MONOSPACE_8        1` for using font size 8.
2. In your *main.c*: *#include "lvgl/lvgl.h"
3. In your main function:
 * Init lvgl: 
     ```c
     lv_init();
     ```
 * Init framebuffer device: 
     ```c
     fbdev_init();
     ```
 * Add a display the LittlevGL sing the frame buffer driver:
     ```c
     lv_disp_drv_t disp_drv;
     lv_disp_drv_init(&disp_drv);
     ```
 * Flushes the internal graphical buffer to the frame buffer:
     ```c
     disp_drv.disp_flush = fbdev_flush;
     lv_disp_drv_register(&disp_drv);
     ```
