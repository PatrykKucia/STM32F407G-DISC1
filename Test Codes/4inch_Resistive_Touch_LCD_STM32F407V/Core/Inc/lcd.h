/* @attention
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, QD electronic SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
**************************************************************************************************/
#ifndef __LCD_H
#define __LCD_H
#include "stdlib.h"
#include "stdint.h"

typedef struct
{
    unsigned short 		width;			
    unsigned short 		height;			
    unsigned short 		id;				  
    unsigned char  		dir;			  //0£¬vertical£»1£¬horizontal
    unsigned short	 	wramcmd;		
    unsigned short  	rramcmd;  
    unsigned short  	setxcmd;	
    unsigned short  	setycmd;	
} _lcd_dev;

extern _lcd_dev lcddev;

#define USE_HORIZONTAL  	 0 // 	0-0 degree rotate 1-90 degree rotate 2-180 degree rotate 3-270 degree rotate
#define LCD_W 480
#define LCD_H 800


extern unsigned short  POINT_COLOR;
extern unsigned short  BACK_COLOR; 

typedef struct
{
    volatile unsigned short LCD_REG;
    volatile unsigned short LCD_RAM;
} LCD_TypeDef;

#define LCD_BASE        		((uint32_t)(0x6C000000 | 0x0000FFFE))
#define LCD             		((LCD_TypeDef *) LCD_BASE)

#define WHITE       				0xFFFF
#define BLACK      					0x0000
#define BLUE       					0x001F
#define BRED        				0XF81F
#define GRED 			 					0XFFE0
#define GBLUE			 					0X07FF
#define RED         				0xF800
#define MAGENTA     				0xF81F
#define GREEN       				0x07E0
#define CYAN        				0x7FFF
#define YELLOW      				0xFFE0
#define BROWN 							0XBC40 
#define BRRED 							0XFC07 
#define GRAY  							0X8430 
#define DARKBLUE      	 		0X01CF	
#define LIGHTBLUE      	 		0X7D7C
#define GRAYBLUE       	 		0X5458
#define LIGHTGREEN     			0X841F 
#define LIGHTGRAY     			0XEF5B 
#define LGRAY 			 				0XC618 
#define LGRAYBLUE      			0XA651 
#define LBBLUE          		0X2B12 

void 												lcd_init(void);
unsigned short 							lcd_read(void);
void 												lcd_clear(unsigned short color);
void 												lcd_setcursor(unsigned short xpos, unsigned short ypos);
void 												lcd_drawpoint(unsigned short x,unsigned short y);
unsigned short  						lcd_readpoint(unsigned short x,unsigned short y);
void 												lcd_setwindows(unsigned short xstar, unsigned short ystar,unsigned short xend,unsigned short yend);
unsigned short 							lcd_rd_data(void);
void 												lcd_writereg(unsigned short lcd_reg, unsigned short lcd_regvalue);
void 												lcd_wr_reg(unsigned short data);
void 												lcd_wr_data(unsigned short data);
void 												lcd_readreg(unsigned short lcd_reg,unsigned short *rval,int n);
void 												lcd_writeram_prepare(void);
void 												lcd_readram_prepare(void);
void 												lcd_writedata_16bit(unsigned short data);
unsigned short 							lcd_readdata_16bit(void);
void 												lcd_direction(unsigned char direction );
unsigned short 							lcd_read_id(void);
unsigned short 							color_to_565(unsigned char r, unsigned char g, unsigned char b);

#endif





