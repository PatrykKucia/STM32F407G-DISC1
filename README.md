# STM32F407G-DISC1
STM32F407G-DISC1 with STM32F407VGT6 MCU

# FSMC Pinout

| LCD | STM32 | Discription |
|-----------|-----------|-----------|
| D 0  | PD 14  | / |
| D 1  | PD 14  | / |
| D 2  | PD 0  | / |
| D 3  | PD 1  | / |
| D 4  | PE 7  |/|
| D 5  | PE 8  |/|
| D 6  | PE 9  |/ |
| D 7  | PE 10  |/|
| D 8  | PE 11  |/|
| D 9  | PE 12  |/|
| D 10 | PE 13 | /|
| D 11 | PE 14 |/ |
| D 12 | PE 15 |/|
| D 13 | PD 8 | /|
| D 14 | PD 9 | /|
| D 15 | PD 10 | /|
| LCD_CS | PD 7 (NE1) | LCD Chip Selection |
| DC | PD 11 (Ax) | Instruction/Data Register Selection |
| WR | PD 5 (NWE)| Write Action |
| RD | PD 4 (NOE) | Read Action |
| LCD_RST | PB 1???? | Reset |
| BL | PB 0 | Backlight Adjustment |


# USEFULL LINKS
### Display WIKI Page
https://www.waveshare.com/wiki/4inch_Resistive_Touch_LCD

### STM32F4DISCOVERY ST Page
https://www.st.com/en/evaluation-tools/stm32f4discovery.html#tools-software

### STM32F4407vg ST Page
https://www.st.com/en/microcontrollers-microprocessors/stm32f407vg.html#overview

### Example of LCD FMC setup
https://controllerstech.com/stm32-fmc-how-to-configure-for-lcd/

### FSMC STM video 1
https://www.youtube.com/watch?v=0wOWzdmsVlQ&list=LL&index=2&ab_channel=1sand0s

### FSMC setup example video 2
https://www.youtube.com/watch?v=hfeKMZXt2L8&list=LL&index=1&ab_channel=RobertoBenjami

### Understunding FSMC !!!!!!!!!!!!!
https://www.youtube.com/watch?v=Sh2zQbqq5_s&ab_channel=LogicVoltage

### 3.5 inch example
https://mydiyelectronics.wordpress.com/2020/08/03/3-5-lcd-module-development/

### FSMC LCD ALIBABA !!!!!
https://topic.alibabacloud.com/a/re-learning-stm32-vii-fsmclcd_8_8_31261556.html

### LVGL
https://forum.lvgl.io/t/corrupted-display-stm32h743-when-trying-to-optimize-performance/10559

### Korea
https://www.programmersought.com/article/2535598703/

https://www.fwqtg.net/stm32cubemx%E6%95%99%E7%A8%8B22-fsmc-8080%E5%B9%B6%E8%A1%8C%E6%8E%A5%E5%8F%A3tft-lcd%E9%A9%B1%E5%8A%A8.html

https://blog.csdn.net/weixin_44412311/article/details/133891855

### Stack
https://stackoverflow.com/questions/36748271/stm32f4-fsmc-with-tft-lcd