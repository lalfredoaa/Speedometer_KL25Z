
#ifndef LCD_H_
#define LCD_H_

void delayMs(int);
void LCD_nibble_write(unsigned char, unsigned char);
void LCD_command(unsigned char);
void LCD_data(unsigned char);
void LCD_init(void);
void printChar(int);

#endif /* LCD_H_ */
