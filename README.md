# MangOH: Integrating Graphics Library LittlevGL
<img src="https://user-images.githubusercontent.com/17214533/51513230-630a4800-1e3c-11e9-9d45-39a2c76c2663.jpg" width="350" alt="accessibility text">               <img src="https://user-images.githubusercontent.com/17214533/51510335-40256700-1e2f-11e9-8903-af65c5368326.jpg" width="350" alt="accessibility text">

## Project Set-up
1. clone lvgl library and create project:
    * lvgl: https://github.com/littlevgl/lvgl
    * lvgl drivers: https://github.com/littlevgl/lv_drivers
    * lvgl examples: https://github.com/littlevgl/lv_examples
    * Copy `lvgl/lv_conf_templ.h` change the name to `lv_conf.h` and place next to the lvgl folder
    * Copy `lvgl/lv_ex_conf_templ.h` change the name to `lv_ex_conf.h` and place next to the lvgl folder
    * We have project tree like that:
    * <img src="https://user-images.githubusercontent.com/17214533/51661409-612eb900-1fe3-11e9-9b20-0aaa71168f5f.png" width="200" alt="accessibility text"> 

2. Update configure file for monochome display in `lv_conf.h`:
   * Update default font type: `#define LV_FONT_DEFAULT        &lv_font_monospace_8` for using monochome font.
   * Update font size: `#define USE_LV_FONT_MONOSPACE_8         1` for using font size 8.
3. Create a application to display a label:
   * In your *main.c*: 
      ```c
      #include "lvgl/lvgl.h"
      #include "lv_drivers/display/fbdev.h"

   * In main function:
     
     ```c
     //Init lvgl 
     lv_init();
     
     //Init framebuffer device
     fbdev_init();
     
     //Add a display the LittlevGL sing the frame buffer driver
     lv_disp_drv_t disp_drv;
     lv_disp_drv_init(&disp_drv);
     
     //Flush the internal graphical buffer to the frame buffer
     disp_drv.disp_flush = fbdev_flush;
     lv_disp_drv_register(&disp_drv);
     
     //Display a label
     lv_obj_t * label = lv_label_create(lv_scr_act(), NULL);
     lv_label_set_text(label, "Hello World");
     lv_obj_align(label, NULL, LV_ALIGN_CENTER, 0, 0);
   
4. Compile the code and load it to your embedded hardware:
      <img src="https://user-images.githubusercontent.com/17214533/51663543-a6ee8000-1fe9-11e9-8416-18bc5bb6fce1.png" width="150" alt="accessibility text"> 
    
  * Handle LitlevGL tasks
    ```c
      while(1) {
          lv_tick_inc(5);
          lv_task_handler();
          usleep(5000);
      }


## Related repositories
* Littlevgl: https://github.com/littlevgl/lvgl
* Examples: https://github.com/littlevgl/lv_examples
* Drivers: https://github.com/littlevgl/lv_drivers
