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
    
5. Display Data in realtime:
   * In your *main.c*:
   ```c
   lv_obj_t * label;
   uint32_t adc_value;

   void label_refresher_task(void * p)
   {
       if(lv_obj_get_screen(label) == lv_scr_act())
       {
           char buf[32];
           sprintf(buf,"Vol: %dV", adc_value);
           lv_label_set_text(label, buf);
       }
   }
       
       
  * In main function:
    ```c
    label = lv_label_create(lv_scr_act(), NULL);
    lv_obj_align(label, NULL, LV_ALIGN_CENTER, -20, 0);
    lv_task_create(label_refresher_task, 1000, LV_TASK_PRIO_MID, NULL);
    
     while(1) {
        lv_tick_inc(5);
        lv_task_handler();
        usleep(1000);

        static uint32_t cnt;
        cnt++;
        if(cnt > 500)
        {
             cnt = 0;
             adc_value++;
        }
    }
   
   
6. Display Another Object:
  * Arc:
   ```c
      /*Create style for the Arcs*/
       lv_style_t style;
       lv_style_copy(&style, &lv_style_plain);
       style.line.color = LV_COLOR_BLACK;           /*Arc color*/
       style.line.width = 8;                       /*Arc width*/

       /*Create an Arc*/
       lv_obj_t * arc = lv_arc_create(lv_scr_act(), NULL);
       lv_arc_set_style(arc, LV_ARC_STYLE_MAIN, &style);          Use the new style
       lv_arc_set_angles(arc, 0, 270);
       lv_obj_set_size(arc, 80, 80);
       lv_obj_align(arc, NULL, LV_ALIGN_CENTER, 0, 0);
 
 * Line Metter:
  ```c
   static lv_style_t style_lmeter1;
   lv_style_copy(&style_lmeter1, &lv_style_pretty_color);
   style_lmeter1.line.width = 2;
   style_lmeter1.line.color = LV_COLOR_BLACK;
   style_lmeter1.body.main_color = LV_COLOR_BLACK;         /*Light blue*/
   style_lmeter1.body.grad_color = LV_COLOR_WHITE;         /*Dark blue*/

   /*Create the first line meter */
   lv_obj_t * lmeter;
   lmeter = lv_lmeter_create(lv_scr_act(), NULL);
   lv_lmeter_set_range(lmeter, 0, 100);                   /*Set the range*/
   lv_lmeter_set_value(lmeter, 80);                       /*Set the current value*/
   lv_lmeter_set_style(lmeter, &style_lmeter1);           /*Apply the new style*/
   lv_obj_set_size(lmeter, 80, 80);
   lv_obj_align(lmeter, NULL, LV_ALIGN_IN_BOTTOM_LEFT, 20, -80);
   
   // /*Add a label to show the current value*/
   lv_obj_t * label;
   label = lv_label_create(lmeter, NULL);
   lv_label_set_text(label, "30%");
   lv_label_set_style(label, &lv_style_pretty);
   lv_obj_align(label, NULL, LV_ALIGN_CENTER, 0, 0);
  


## Related repositories
* Littlevgl: https://github.com/littlevgl/lvgl
* Examples: https://github.com/littlevgl/lv_examples
* Drivers: https://github.com/littlevgl/lv_drivers
