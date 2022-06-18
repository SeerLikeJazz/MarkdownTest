#include "lcd.h"
#include "string.h"
//#include "font.h"
#include "spi.h"
#include "GUI.h"
#include "dma.h"
#include "lvgl.h"

void GUI_Fill(u16 xsta,u16 ysta,u16 xend,u16 yend,u16 *color)
{
    u32 num;
    num=(xend-xsta+1)*(yend-ysta+1)*sizeof(lv_color_t);
    LCD_Address_Set(xsta,ysta,xend,yend);//设置显示窗口
    LCD_CS_CLR;
    LCD_RS_SET;
//    SPI1->CR1|=1<<11;//设置SPI16位传输模式
//    SPI_Cmd(SPI1, ENABLE);//使能SPI
//    MYDMA_Config1(color,num);
    HAL_SPI_Transmit_DMA(&hspi1,color,num);

}

extern lv_disp_drv_t * disp_drv_p;		//屏幕驱动结构体地址，在lv_port_disp.c中定义，disp_flush()函数中被赋值
void HAL_SPI_TxCpltCallback(SPI_HandleTypeDef *hspi)
{
    LCD_CS_SET;
    lv_disp_flush_ready(disp_drv_p);


}

