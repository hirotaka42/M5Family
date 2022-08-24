#include <M5StickCPlus.h>
#include "efont.h"
#include "efontM5StickCPlus.h"
#include "efontEnableJa.h"

uint8_t show_flag = 0;
uint8_t action = 0;

void setup(){
  M5.begin();
  M5.Lcd.setRotation(3);
  // LCD display.  Lcd显示
  printEfont("Hello World!!");
    
}

void loop() {
  M5.update(); // Buttonの状態更新のため必要
  if(M5.BtnA.wasPressed()){
    printEfont("こんにちは", 0, 16*1);
    printEfont("Hello World!!");

    printEfont("こんにちは", 0, 16*2);
    printEfont("Hello World!!", 0, 16*3);

    
  }

}
