
 /* @attention
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, QD electronic SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
**************************************************************************************************/		
#ifndef __TOUCH_H__
#define __TOUCH_H__
#include "stdint.h"
#include "gpio.h"
#include "stm32f4xx_hal_gpio.h"
#include "lcd.h"

#define TP_PRES_DOWN 0x80  
#define TP_CATH_PRES 0x40 
										    
typedef struct
{
	uint8_t (*init)(void);			
	uint8_t (*scan)(uint8_t);				
	void 		(*adjust)(void);		
	uint16_t x0;						
	uint16_t y0;
	uint16_t x; 						
	uint16_t y;						   	    
	uint8_t  sta;					
									  					
	float xfac;					
	float yfac;
	short xoff;
	short yoff;	   

	uint8_t touchtype;
}_m_tp_dev;

extern _m_tp_dev tp_dev;	 	



#define PEN  				HAL_GPIO_ReadPin(GPIOC,TP_IRQ_Pin)
#define DOUT 				HAL_GPIO_ReadPin(GPIOB,TP_MISO_Pin)
#define TDIN_H() 		HAL_GPIO_WritePin(GPIOB,TP_MOSI_Pin,GPIO_PIN_SET)
#define TDIN_L() 		HAL_GPIO_WritePin(GPIOB,TP_MOSI_Pin,GPIO_PIN_RESET)
#define TCLK_H() 		HAL_GPIO_WritePin(GPIOB,TP_SCK_Pin,GPIO_PIN_SET)
#define TCLK_L() 		HAL_GPIO_WritePin(GPIOB,TP_SCK_Pin,GPIO_PIN_RESET)
#define TCS_H()  		HAL_GPIO_WritePin(GPIOC,TP_CS_Pin,GPIO_PIN_SET)
#define TCS_L()  		HAL_GPIO_WritePin(GPIOC,TP_CS_Pin,GPIO_PIN_RESET)
     

void 						tp_write_byte(uint8_t num);						
uint16_t 				tp_read_ad(uint8_t cmd);							
uint16_t 				tp_read_xoy(uint8_t xy);							
uint8_t 				tp_read_xy(uint16_t *x,uint16_t *y);					
uint8_t 				tp_read_xy2(uint16_t *x,uint16_t *y);					
void 						tp_drow_touch_point(uint16_t x,uint16_t y,uint16_t color);
void 						tp_draw_big_point(uint16_t x,uint16_t y,uint16_t color);
uint8_t 				tp_scan(uint8_t tp);						
void 						tp_adjust(void);							
uint8_t 				tp_init(void);							
void 						tp_adj_info_show(uint16_t x0,uint16_t y0,uint16_t x1,uint16_t y1,uint16_t x2,uint16_t y2,uint16_t x3,uint16_t y3,uint16_t fac);
void 						touch_test(void);
#endif

















