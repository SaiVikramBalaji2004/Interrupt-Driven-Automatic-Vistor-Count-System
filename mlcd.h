#ifndef MLCD_H
#define MLCD_H

void lcd_INIT(void);
void lcd_cmd(unsigned char);
void lcd_data(unsigned char);
void lcd_string(char *);
void lcd_display_count(void);
void lcd_display_total(void);     // add this line

#endif
