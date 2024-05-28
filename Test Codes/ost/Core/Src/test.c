 /* @attention
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, QD electronic SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
**************************************************************************************************/		
#include <stdio.h>
#include "lcd.h"
#include "tim.h"
#include "gui.h"
#include "test.h"
#include <math.h>
#include "pic.h"
#include "pic2.h"

//========================variable==========================//
uint16_t ColorTab[5]={RED,GREEN,BLUE,YELLOW,BRED};
uint16_t ColornTab[8]={RED,MAGENTA,GREEN,DARKBLUE,BLUE,BLACK,LIGHTGREEN};
//=====================end of variable======================//

/*****************************************************************************
 * @name       :void drawtestpage(uint8_t *str)
 * @date       :
 * @function   :Drawing test interface
 * @parameters :str:the start address of the Chinese and English strings
 * @retvalue   :None
******************************************************************************/ 

#define PI 3.14159265

#define CENTER_X lcddev.width / 2
#define CENTER_Y lcddev.height / 2
#define POINTER_LENGTH 200
#define SPEED_RECT_WIDTH 200
#define SPEED_RECT_HEIGHT 100
#define SPEED_RECT_X 20
#define SPEED_RECT_Y 350
// Previous endpoint coordinates to erase the previous pointer position
int prev_end_x, prev_end_y;
float current_speed = 0.0;
float max_speed = 200.0; // Define your maximum speed here

int max(int a, int b) {
    return (a > b) ? a : b;
}


void draw_speed_indicator(float speed) {
    // Calculate the length of the speed indicator rectangle based on the current speed and maximum speed
    float length_ratio = speed / max_speed;
    int rect_length = (int)(SPEED_RECT_WIDTH * length_ratio);

    // Erase the previous pointer position by filling it with white
    lcd_fill(prev_end_x, SPEED_RECT_Y, prev_end_x + POINTER_LENGTH, SPEED_RECT_Y + SPEED_RECT_HEIGHT, WHITE);

    // Draw the changing part of the speed indicator rectangle in red
    lcd_fill(SPEED_RECT_X, SPEED_RECT_Y, SPEED_RECT_X + rect_length, SPEED_RECT_Y + SPEED_RECT_HEIGHT, RED);

    // Update previous endpoint coordinates
    prev_end_x = SPEED_RECT_X + rect_length;
}


void update_speed(float new_speed) {
    // Update the current speed
    current_speed = new_speed;

    // Draw the updated speed indicator
    draw_speed_indicator(current_speed);
}

// Function to simulate changing speed (for demonstration purposes)
void simulate_speed_change(void) {
    // Simulate increasing speed
    for (int i = 0; i <= max_speed; i += 10) {
        update_speed(i);
        //HAL_Delay(1); // Adjust delay as needed
    }

    // Simulate decreasing speed smoothly
    for (int i = max_speed; i >= 0; i -= 10) {
        update_speed(i);
        //HAL_Delay(1); // Adjust delay as needed
    }
}



void draw_rotated_pointer(float angle) {
    // Calculate the endpoint of the pointer after rotation
    int end_x = CENTER_X + (int)(POINTER_LENGTH * cos(angle * PI / 180));
    int end_y = CENTER_Y - (int)(POINTER_LENGTH * sin(angle * PI / 180)); // Note: Y-coordinate inverted

    // Erase the previous pointer position
    POINT_COLOR = WHITE;
    lcd_drawline(CENTER_X, CENTER_Y, prev_end_x, prev_end_y);

    // Draw the new pointer position
    POINT_COLOR = RED; // You can adjust the color as needed
    lcd_drawline(CENTER_X, CENTER_Y, end_x, end_y);

    // Update the previous endpoint coordinates
    prev_end_x = end_x;
    prev_end_y = end_y;
}

void dynamic_rotation_test(void) {
    float angle = 0.0;
    float angle_increment = 1.0;

    // Initialize previous endpoint coordinates to the initial position
    prev_end_x = CENTER_X + POINTER_LENGTH;
    prev_end_y = CENTER_Y;

    while (1) {
        // Draw the background or any other content here

        // Draw the rotated pointer
        draw_rotated_pointer(angle);

        // Update the angle for the next frame
        angle += angle_increment;
        if (angle >= 360.0) {
            angle -= 360.0;
        }

       // HAL_Delay(2); // Adjust the delay as needed for desired rotation speed
    }
}

void drawtestpage(uint8_t *str)
{

	lcd_clear(WHITE);
	lcd_fill(0,0,lcddev.width-1,20,BLUE);

	lcd_fill(0,lcddev.height-20,lcddev.width-1,lcddev.height-1,BLUE);
	POINT_COLOR=WHITE;
	gui_strcenter(0,2,WHITE,BLUE,str,16,1);
	gui_strcenter(0,lcddev.height-18,WHITE,BLUE,(uint8_t *)"http://www.waveshare.net",16,1);
	
}

/*****************************************************************************
 * @name       :void main_test(void)
 * @date       :
 * @function   :Drawing the main Interface of the Comprehensive Test Program
 * @parameters :None
 * @retvalue   :None
******************************************************************************/
void main_test(void)
{
	drawtestpage((uint8_t *)"΢ѩ�����ۺϲ��Գ���");	
	gui_strcenter(0,30,RED,BLUE,(uint8_t *)"΢ѩ����",16,1);
	gui_strcenter(0,60,RED,BLUE,(uint8_t *)"�ۺϲ��Գ���",16,1);
	gui_strcenter(0,90,MAGENTA,BLUE,(uint8_t *)"4\" NT35510 480X800",16,1);
	gui_strcenter(0,120,BLUE,BLUE,(uint8_t *)"wavesshare 2019-11-28",16,1);
	HAL_Delay(1500);		
}

/*****************************************************************************
 * @name       :void test_color(void)
 * @date       :
 * @function   :Color fill test(white,black,red,green,blue)
 * @parameters :None
 * @retvalue   :None
******************************************************************************/
void test_color(void)
{
	lcd_fill(0,0,lcddev.width-1,lcddev.height-1,WHITE);
	show_str(20,30,BLUE,YELLOW,(uint8_t *)"BL Test",16,1);HAL_Delay(1500);
	lcd_fill(0,0,lcddev.width-1,lcddev.height-1,RED);
	show_str(20,30,BLUE,YELLOW,(uint8_t *)"RED ",16,1);HAL_Delay(1500);
	lcd_fill(0,0,lcddev.width-1,lcddev.height-1,GREEN);
	show_str(20,30,BLUE,YELLOW,(uint8_t *)"GREEN ",16,1);HAL_Delay(1500);
	lcd_fill(0,0,lcddev.width-1,lcddev.height-1,BLUE);
	show_str(20,30,RED,YELLOW,(uint8_t *)"BLUE ",16,1);HAL_Delay(1500);
}

/*****************************************************************************
 * @name       :void test_fillrec(void)
 * @date       :
 * @function   :Rectangular display and fill test
								Display red,green,blue,yellow,pink rectangular boxes in turn,
								1500 milliseconds later,
								Fill the rectangle in red,green,blue,yellow and pink in turn
 * @parameters :None
 * @retvalue   :None
******************************************************************************/
void test_fillrec(void)
{
	uint8_t i=0;
	drawtestpage((uint8_t *)"����3:GUI����������");
	lcd_fill(0,20,lcddev.width-1,lcddev.height-20,WHITE);
	for (i=0; i<5; i++) 
	{
		POINT_COLOR=ColorTab[i];
		lcd_drawrectangle(lcddev.width/2-80+(i*15),lcddev.height/2-80+(i*15),lcddev.width/2-80+(i*15)+60,lcddev.height/2-80+(i*15)+60); 
	}
	HAL_Delay(1500);	
	lcd_fill(0,20,lcddev.width-1,lcddev.height-20,WHITE); 
	for (i=0; i<5; i++) 
	{
		POINT_COLOR=ColorTab[i];
		lcd_drawfillrectangle(lcddev.width/2-80+(i*15),lcddev.height/2-80+(i*15),lcddev.width/2-80+(i*15)+60,lcddev.height/2-80+(i*15)+60); 
	}
	HAL_Delay(1500);
}

/*****************************************************************************
 * @name       :void test_circle(void)
 * @date       :
 * @function   :circular display and fill test
								Display red,green,blue,yellow,pink circular boxes in turn,
								1500 milliseconds later,
								Fill the circular in red,green,blue,yellow and pink in turn
 * @parameters :None
 * @retvalue   :None
******************************************************************************/
void test_circle(void)
{
	uint8_t i=0;
	drawtestpage((uint8_t *)"����4:GUI��Բ������");
	lcd_fill(0,20,lcddev.width-1,lcddev.height-20,WHITE);
	for (i=0; i<5; i++)  
		gui_circle(lcddev.width/2-80+(i*25),lcddev.height/2-50+(i*25),ColorTab[i],30,0);
	HAL_Delay(1500);	
	lcd_fill(0,20,lcddev.width-1,lcddev.height-20,WHITE); 
	for (i=0; i<5; i++) 
	  	gui_circle(lcddev.width/2-80+(i*25),lcddev.height/2-50+(i*25),ColorTab[i],30,1);
	HAL_Delay(1500);
}

/*****************************************************************************
 * @name       :void english_font_test(void)
 * @date       :
 * @function   :English display test
 * @parameters :None
 * @retvalue   :None
******************************************************************************/
void english_font_test(void)
{
	drawtestpage((uint8_t *)"����6:Ӣ����ʾ����");
	show_str(10,30,BLUE,YELLOW,(uint8_t *)"6X12:abcdefghijklmnopqrstuvwxyz0123456789",12,0);
	show_str(10,45,BLUE,YELLOW,(uint8_t *)"6X12:ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789",12,1);
	show_str(10,60,BLUE,YELLOW,(uint8_t *)"6X12:~!@#$%^&*()_+{}:<>?/|-+.",12,0);
	show_str(10,80,BLUE,YELLOW,(uint8_t *)"8X16:abcdefghijklmnopqrstuvwxyz0123456789",16,0);
	show_str(10,100,BLUE,YELLOW,(uint8_t *)"8X16:ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789",16,1);
	show_str(10,120,BLUE,YELLOW,(uint8_t *)"8X16:~!@#$%^&*()_+{}:<>?/|-+.",16,0); 
	HAL_Delay(1200);
}

/*****************************************************************************
 * @name       :void test_triangle(void)
 * @date       :
 * @function   :triangle display and fill test
								Display red,green,blue,yellow,pink triangle boxes in turn,
								1500 milliseconds later,
								Fill the triangle in red,green,blue,yellow and pink in turn
 * @parameters :None
 * @retvalue   :None
******************************************************************************/
void test_triangle(void)
{
	uint8_t i=0;
	drawtestpage((uint8_t *)"����5:GUI Triangle������");//china footer
	lcd_fill(0,20,lcddev.width-1,lcddev.height-20,WHITE);
	for(i=0;i<5;i++)
	{
		POINT_COLOR=ColorTab[i];
		draw_triangel(lcddev.width/2-80+(i*20),lcddev.height/2-20+(i*15),lcddev.width/2-50-1+(i*20),lcddev.height/2-20-52-1+(i*15),lcddev.width/2-20-1+(i*20),lcddev.height/2-20+(i*15));
	}
	HAL_Delay(1500);
	lcd_fill(0,20,lcddev.width-1,lcddev.height-20,WHITE);
	for(i=0;i<5;i++)
	{
		POINT_COLOR=ColorTab[i];
		fill_triangel(lcddev.width/2-80+(i*20),lcddev.height/2-20+(i*15),lcddev.width/2-50-1+(i*20),lcddev.height/2-20-52-1+(i*15),lcddev.width/2-20-1+(i*20),lcddev.height/2-20+(i*15));
	}
	HAL_Delay(1500);
}

/*****************************************************************************
 * @name       :void chinese_font_test(void)
 * @date       :
 * @function   :chinese display test
 * @parameters :None
 * @retvalue   :None
******************************************************************************/
void chinese_font_test(void)
{	
	drawtestpage((uint8_t *)"����7:������ʾ����");
	show_str(10,30,BLUE,YELLOW,(uint8_t *)"16X16:΢ѩ�������޹�˾��ӭ��",16,0);
	show_str(10,50,BLUE,YELLOW,(uint8_t *)"16X16:Welcome΢ѩ����",16,0);
	show_str(10,70,BLUE,YELLOW,(uint8_t *)"24X24:���������Ĳ���",24,1);
	show_str(10,100,BLUE,YELLOW,(uint8_t *)"32X32:�������",32,1);
	HAL_Delay(1200);
}

/*****************************************************************************
 * @name       :void pic_test(void)
 * @date       :
 * @function   :picture display test
 * @parameters :None
 * @retvalue   :None
******************************************************************************/
//void pic_test(void)
//{
//	drawtestpage((uint8_t *)"����8:ͼƬ��ʾ����");
//
//	gui_drawbmp16(50,300,360,100,gImage_waveshare);
//	show_str(200,75,BLUE,YELLOW,(uint8_t *)"waveshare",16,1);
//	HAL_Delay(1200);
//	HAL_Delay(1200);
//}

void pic_test(void)
{
		gui_drawbmp16(0,0,360,100,gImage_waveshare);
		HAL_Delay(1200);
		gui_drawbmp16(0,0,650,279 ,gImage_LOGO);
		//drawtestpage((uint8_t *)"����8:ͼƬ��ʾ����");


		//gui_drawbmp16(0,0,360,100,gImage_waveshare);
		show_str(200,75,BLUE,YELLOW,(uint8_t *)"waveshare",16,1);

	//HAL_Delay(1200);
	//HAL_Delay(1200);
}

/*****************************************************************************
 * @name       :void rotate_test(void)
 * @date       :
 * @function   :rotate test
 * @parameters :None
 * @retvalue   :None
******************************************************************************/
void rotate_test(void)
{
	uint8_t i=0;
	char *Direction[4]={"Rotation:0","Rotation:90","Rotation:180","Rotation:270"};
	
	for(i=0;i<4;i++)
	{
		lcd_direction(i);
		drawtestpage((uint8_t *)"����9:��Ļ��ת����");
		show_str(240,30,BLUE,YELLOW,(uint8_t *)Direction[i],16,1);
		gui_drawbmp16(30,50,360,100,gImage_waveshare);
		HAL_Delay(1000);HAL_Delay(1000);
	}
	lcd_direction(USE_HORIZONTAL);
}

/*****************************************************************************
 * @name       :void touch_test(void)
 * @date       :
 * @function   :touch test
 * @parameters :None
 * @retvalue   :None
******************************************************************************/

/*****************************************************************************
 * @name       :void test_read(void)
 * @date       :
 * @function   :read test
 * @parameters :None
 * @retvalue   :None
******************************************************************************/
void test_read(void)
{
	uint16_t lcd_id,color;
	uint8_t buf[10] = {0},i;
	uint8_t cbuf[20] = {0};
	drawtestpage((uint8_t *)"����2:��ID����ɫֵ����");
	lcd_fill(0,20,lcddev.width,lcddev.height-20,WHITE);
	lcd_id = lcd_read_id();
	sprintf((char *)buf,"ID:0x%x",lcd_id);
	show_str(50,25,BLUE,YELLOW,buf,16,1);
	for (i=0; i<7; i++) 
	{
		POINT_COLOR=ColornTab[i];
		lcd_drawfillrectangle(40-10,55+i*25-10,40+10,55+i*25+10);
		color = lcd_readpoint(40,55+i*25);
		sprintf((char *)cbuf,"read color:0x%04X",color);
		show_str(40+20,55+i*25-8,POINT_COLOR,YELLOW,cbuf,16,1);
	}
	HAL_Delay(1500);
}



