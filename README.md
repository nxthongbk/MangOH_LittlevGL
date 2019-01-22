# MangOH: Integrating Graphics Library LittlevGL
<img src="https://user-images.githubusercontent.com/17214533/51513230-630a4800-1e3c-11e9-9d45-39a2c76c2663.jpg" width="350" alt="accessibility text">               <img src="https://user-images.githubusercontent.com/17214533/51510335-40256700-1e2f-11e9-8903-af65c5368326.jpg" width="350" alt="accessibility text">

## Project Set-up
1. Update configure file: `lv_conf.h`:
   * Update default font type: `#define LV_FONT_DEFAULT        &lv_font_monospace_8` for using monochome font.
   * Update font size: `#define USE_LV_FONT_MONOSPACE_8         1` for using font size 8.
2. In your *main.c*: 
      ```c
      #include "lvgl/lvgl.h"
      #include "lv_drivers/display/fbdev.h"

3. In your main function:
  * Init lvgl: 
     ```c
     lv_init();
     
  * Init framebuffer device: 
     ```c
     fbdev_init();
  * Add a display the LittlevGL sing the frame buffer driver:
     ```c
     lv_disp_drv_t disp_drv;
     lv_disp_drv_init(&disp_drv);
  * Flushes the internal graphical buffer to the frame buffer:
     ```c
     disp_drv.disp_flush = fbdev_flush;
     lv_disp_drv_register(&disp_drv);
     
  * Create lable and allign object:
      ```c
      lv_obj_t * label = lv_label_create(lv_scr_act(), NULL);
      lv_label_set_text(label, "Hello World");
      lv_obj_align(label, NULL, LV_ALIGN_CENTER, 0, 0);
    ```
    
  * Handle LitlevGL tasks
    ```c
      while(1) {
          lv_tick_inc(5);
          lv_task_handler();
          usleep(5000);
      }

4. Compile the code and load it to your embedded hardware

## Related repositories
* Littlevgl: https://github.com/littlevgl/lv_projects
* Examples: https://github.com/littlevgl/lv_examples
* Drivers: https://github.com/littlevgl/lv_drivers
