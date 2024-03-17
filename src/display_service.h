#include "lvgl.h"
#include "TFT_eSPI.h"

class display_service {
private:
//    void ICACHE_FLASH_ATTR lv_setup();
//
//    void IRAM_ATTR lv_main();
//
//    static void IRAM_ATTR my_disp_flush(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p);

public:
    display_service();

    ~display_service();

    void IRAM_ATTR setup();

    void IRAM_ATTR loop();
};
