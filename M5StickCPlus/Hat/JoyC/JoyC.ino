/*
 * @LastEditTime: 2022-08-24 06:27:50
 * @Description: M5Stack project
 * @FilePath: /M5Family/M5StickCPlus/Hat/JoyC/JoyC.ino
 */

#include "JoyC.h"
#include "M5StickCPlus.h"
#define vertical   240
#define horizontal 135
#define horizontalCenter 67.5

JoyC joyc;
TFT_eSprite img = TFT_eSprite(&M5.Lcd);

uint8_t show_flag = 0;


void setup() {
    M5.begin();
    Wire.begin(0, 26, 400000UL);
    img.createSprite(horizontal, vertical);
}

void loop() {
    char text_buff[100];

    M5.update();
    img.fillSprite(TFT_BLACK);
    if (show_flag == 0) {
        img.drawCentreString("angle right", horizontalCenter, 6, 2);
        sprintf(text_buff, "%d", joyc.GetAngle(1));
        img.drawCentreString(text_buff, horizontalCenter, 20, 2);

        img.drawCentreString("dis right", horizontalCenter, 34, 2);
        sprintf(text_buff, "%d", joyc.GetDistance(1));
        img.drawCentreString(text_buff, horizontalCenter, 48, 2);

        img.drawCentreString("x right", horizontalCenter, 62, 2);
        sprintf(text_buff, "%d", joyc.GetX(1));
        img.drawCentreString(text_buff, horizontalCenter, 76, 2);

        img.drawCentreString("y right", horizontalCenter, 90, 2);
        sprintf(text_buff, "%d", joyc.GetY(1));
        img.drawCentreString(text_buff, horizontalCenter, 104, 2);

        img.drawCentreString("press right", horizontalCenter, 118, 2);
        sprintf(text_buff, "%d", joyc.GetPress(1));
        img.drawCentreString(text_buff, horizontalCenter, 132, 2);
    } else {
        img.drawCentreString("angle left", horizontalCenter, 6, 2);
        sprintf(text_buff, "%d", joyc.GetAngle(0));
        img.drawCentreString(text_buff, horizontalCenter, 20, 2);

        img.drawCentreString("dis left", horizontalCenter, 34, 2);
        sprintf(text_buff, "%d", joyc.GetDistance(0));
        img.drawCentreString(text_buff, horizontalCenter, 48, 2);

        img.drawCentreString("x left", horizontalCenter, 62, 2);
        sprintf(text_buff, "%d", joyc.GetX(0));
        img.drawCentreString(text_buff, horizontalCenter, 76, 2);

        img.drawCentreString("y left", horizontalCenter, 90, 2);
        sprintf(text_buff, "%d", joyc.GetY(0));
        img.drawCentreString(text_buff, horizontalCenter, 104, 2);

        img.drawCentreString("press left", horizontalCenter, 118, 2);
        sprintf(text_buff, "%d", joyc.GetPress(0));
        img.drawCentreString(text_buff, horizontalCenter, 132, 2);
    }
    img.pushSprite(0, 0);

    if (M5.BtnA.wasPressed()) {
        joyc.SetLedColor(0x100010);
        show_flag = 1 - show_flag;
    }

    delay(10);
}