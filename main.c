#include "lvgl/lvgl.h"
#include "lv_drivers/display/fbdev.h"
#include "lv_examples/lv_apps/demo/demo.h"
#include <unistd.h>
#include "lv_examples/lv_tutorial/1_hello_world/lv_tutorial_hello_world.h"
#include "lv_examples/lv_tutorial/7_fonts/lv_tutorial_fonts.h"
#include "lv_examples/lv_tutorial/2_objects/lv_tutorial_objects.h"
#include "lv_examples/lv_tutorial/4_themes/lv_tutorial_themes.h"
#include "lv_examples/lv_tutorial/6_images/lv_tutorial_images.h"
#include "lv_examples/lv_tutorial/5_antialiasing/lv_tutorial_antialiasing.h"
#include "lv_examples/lv_tests/lv_test_objx/lv_test_chart/lv_test_chart.h"
#include "lv_examples/lv_tests/lv_test_objx/lv_test_img/lv_test_img.h"
#include "lv_examples/lv_tests/lv_test_objx/lv_test_preload/lv_test_preload.h"
#include "lv_examples/lv_tests/lv_test_objx/lv_test_arc/lv_test_arc.h"


static  lv_res_t btn_rel_action(lv_obj_t * btn);
static  lv_res_t ddlist_action(lv_obj_t * ddlist);

int main(void)
{
    /*LittlevGL init*/
    lv_init();

    /*Linux frame buffer device init*/
    fbdev_init();

    /*Add a display the LittlevGL sing the frame buffer driver*/
    lv_disp_drv_t disp_drv;
    lv_disp_drv_init(&disp_drv);
    disp_drv.disp_flush = fbdev_flush;      /*It flushes the internal graphical buffer to the frame buffer*/
    lv_disp_drv_register(&disp_drv);

    //Line -worked ---------------------------------
    // static lv_point_t line_points[] = { {0, 5}, {20, 5}, {40, 5}, {80, 5}, {120, 5} };
    // /*Create line with default style*/
    // lv_obj_t * line1;
    // line1 = lv_line_create(lv_scr_act(), NULL);
    // lv_line_set_points(line1, line_points, 5);     /*Set the points*/
    // lv_obj_align(line1, NULL, LV_ALIGN_IN_TOP_LEFT, 0, 20);
    //END LINE-------------------------------------

    

//SYMBOL - NOTWORK---------------------------------
    //lv_obj_t * cursor_obj =  lv_img_create(lv_scr_act(), NULL);
    // Create an image for the cursor 
   // lv_img_set_src(cursor_obj, SYMBOL_POWER);                 /*For simlicity add a built in symbol not an image*/
//END SYMBOL--------------------------------------

 //CHART - WORKED---------------------------------
   //  lv_obj_t * scr = lv_page_create(NULL, NULL);
   //  lv_scr_load(scr);

   //  lv_obj_t * label = lv_label_create(scr, NULL); /*First parameters (scr) is the parent*/
   //  lv_label_set_text(label, "Chart Demo");  /*Set the text*/
   //  lv_obj_set_x(label, 0); 

   // lv_obj_t * chart = lv_chart_create(lv_scr_act(), NULL);                         /*Create the chart*/
   //  lv_obj_set_size(chart, lv_obj_get_width(scr) , lv_obj_get_width(scr)/2);   /*Set the size*/
   //  lv_obj_align(chart, label, LV_ALIGN_OUT_BOTTOM_LEFT, 0, 20);                   /*Align below the slider*/
   //  lv_chart_set_series_width(chart, 1); 

   //  lv_chart_series_t * dl1 = lv_chart_add_series(chart, LV_COLOR_BLACK);
   //  lv_chart_set_next(chart, dl1, 0);
   //  lv_chart_set_next(chart, dl1, 15);
   //  lv_chart_set_next(chart, dl1, 45);
   //  lv_chart_set_next(chart, dl1, 120);

   

//END CHART--------------------------------------

    /*Create a style for the Preloader*/
    // static lv_style_t style;
    // lv_style_copy(&style, &lv_style_plain);
    // style.line.width = 10;                         /*10 px thick arc*/
    // style.line.color = LV_COLOR_BLACK;       /*Blueish arc color*/

    // style.body.border.color = LV_COLOR_BLACK; /*Gray background color*/
    // style.body.border.width = 10;
    // style.body.padding.hor = 0;

    // /*Create a Preloader object*/
    // lv_obj_t * preload = lv_preload_create(lv_scr_act(), NULL);
    // lv_obj_set_size(preload, 100, 100);
    // lv_obj_align(preload, NULL, LV_ALIGN_CENTER, 0, 0);
    // lv_preload_set_style(preload, LV_PRELOAD_STYLE_MAIN, &style);

    lv_test_img_1();

//BUTTON------------------------------------------
    ///*Create a normal button*/
    /*Create a title label*/
    // lv_obj_t * label = lv_label_create(lv_scr_act(), NULL);
    // lv_label_set_text(label, "Default");
    // lv_obj_align(label, NULL, LV_ALIGN_IN_TOP_MID, 0, 5);

    //lv_obj_t * btn1 = lv_btn_create(lv_scr_act(), NULL);
  //  lv_cont_set_fit(btn1, true, true); /*Enable resizing horizontally and vertically*/
   // lv_obj_align(btn1, label, LV_ALIGN_OUT_BOTTOM_MID, 0, 10);
   // lv_obj_set_free_num(btn1, 1);   /*Set a unique number for the button*/
   //END BUTTON-------------------------------------------------
    
    //lv_tutorial_hello_world();

    /*Handle LitlevGL tasks (tickless mode)*/
    while(1) {
        lv_tick_inc(5);
        lv_task_handler();
        usleep(5000);
    }

    return 0;
}


/**
 * Called when a button is released
 * @param btn pointer to the released button
 * @return LV_RES_OK because the object is not deleted in this function
 */
static  lv_res_t btn_rel_action(lv_obj_t * btn)
{
    /*Increase the button width*/
    lv_coord_t width = lv_obj_get_width(btn);
    lv_obj_set_width(btn, width + 20);

    return LV_RES_OK;
}

/**
 * Called when a new option is chosen in the drop down list
 * @param ddlist pointer to the drop down list
 * @return LV_RES_OK because the object is not deleted in this function
 */
static  lv_res_t ddlist_action(lv_obj_t * ddlist)
{
    uint16_t opt = lv_ddlist_get_selected(ddlist);      /*Get the id of selected option*/

    lv_obj_t * slider = lv_obj_get_free_ptr(ddlist);      /*Get the saved slider*/
    lv_slider_set_value(slider, (opt * 100) / 4);       /*Modify the slider value according to the selection*/

    return LV_RES_OK;
}