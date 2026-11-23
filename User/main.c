#include "ili9341.h"
#define LCD_SHOW_IMAGE   1

#if LCD_SHOW_IMAGE
#include "image_avatar.h"
#endif

 
static void wait_a_while(uint32_t n)
{
    volatile uint32_t i;
    while (n--) {
        for (i = 0; i < 600000UL; i++) {
        }
    }
}

 
static void show_number(uint16_t x, uint16_t y, const char *num,
                        uint8_t r, uint8_t g, uint8_t b,
                        uint8_t br, uint8_t bg, uint8_t bb,
                        uint8_t size)
{
    LCD_ShowStringAtC(x, y, num,
                      LCD_RGB(r, g, b),
                      LCD_RGB(br, bg, bb),
                      size);
}

 
static void show_letter(uint16_t x, uint16_t y, const char *str,
                        uint8_t r, uint8_t g, uint8_t b,
                        uint8_t br, uint8_t bg, uint8_t bb,
                        uint8_t size)
{
    LCD_ShowStringAtC(x, y, str,
                      LCD_RGB(r, g, b),
                      LCD_RGB(br, bg, bb),
                      size);
}

 
#if LCD_SHOW_IMAGE
static void show_image(void)
{
    IMG_Draw();
}
#endif

int main(void)
{
     
    LCD_SetColors(LCD_RGB(255, 100, 0), LCD_RGB(100, 0, 255));
    LCD_SetBgTransparent(0);       
    LCD_Init();
    show_image();
    while (1) {
         
//        LCD_ClearScreen();
//        show_number(40, 120, "1234",
//                    255, 0, 0,       
//                    0, 0, 255,       
//                    4);              
//        wait_a_while(3);

//         
//        LCD_ClearScreen();
//        show_letter(8,  60,  "ABCDEFGHI", 255,255,255, 0,0,0, 2);
//        show_letter(8,  110, "JKLMNOPQR", 255,255,0, 0,0,0, 2);
//        show_letter(8,  160, "STUVWXYZ",  255,255,0, 0,0,0, 2);
//        wait_a_while(3);
                                                                    
         
#if LCD_SHOW_IMAGE

        wait_a_while(3);
#endif
    }
     
}
