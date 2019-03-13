#include "U8glib.h"
U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_NONE);  // I2C / TWI 
# define Con_interval 11   
# define Con_pages 1
void u8g_prepare(void) {
  u8g.setFont(u8g_font_6x10);
  u8g.setFontRefHeightExtendedText();
  u8g.setDefaultForegroundColor();
  u8g.setFontPosTop(); 
}
void u8g_print1(unsigned long a) {
  u8g.drawStr( 0, 0-a/8, "Schools apart,");
  u8g.drawStr( 0, 11-a/8, "day after day,");
  u8g.drawStr( 0 ,22-a/8, "And I slowly ");
  u8g.drawStr( 0 ,33-a/8, "go insane.");
  u8g.drawStr( 0 ,44-a/8, "But you left");
  u8g.drawStr( 0, 55-a/8, "which was");
  u8g.drawStr( 0, 66-a/8, "my deep pain.");
  u8g.drawStr( 0, 77-a/8, "Since you've");
  u8g.drawStr( 0, 88-a/8, "broken my heart,");
  u8g.drawStr( 0, 99-a/8, "you need not");
  u8g.drawStr( 0, 110-a/8, "be with me.");
  u8g.drawStr( 0, 121-a/8, "Let's say goodbye");
  u8g.drawStr( 0, 132-a/8, "and depart,");
  u8g.drawStr( 0, 143-a/8, "And I'm what");
  u8g.drawStr( 0, 154-a/8, "I used to be.");
  u8g.drawStr( 0, 165-a/8, "Do not say forever;");
  u8g.drawStr( 0, 176-a/8, "Do not");
  u8g.drawStr( 0, 187-a/8, "meet tomorrow.");
  u8g.drawStr( 0, 198-a/8, "And I see you never,");
  u8g.drawStr( 0, 209-a/8, "I am virtue as snow.");
}
unsigned long draw_state = 0;

void draw(void) {
  u8g_prepare();
  switch(draw_state >> Con_interval) {
    case 0 : u8g_print1 (draw_state); break;
}
}
void setup(void) {
  u8g.setRot180();
}
void loop(void) {
  u8g.firstPage();  
  do {
    draw();
      } 
  while( u8g.nextPage() );
  draw_state++;
  if ( draw_state >= Con_pages * pow(2,Con_interval))
  draw_state = 0;
}
