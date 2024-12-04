/*
 * File:   display.c
 * Author: C16783
 *
 * Created on May 20, 2020, 11:11 AM
 */

#include "display.h"

void display_clearScreen(void) {
    oledC_setColumnAddressBounds(0, 96);
    oledC_setRowAddressBounds(0, 96);
    for (uint8_t x = 0; x < 96; x++) {
        for (uint8_t y = 0; y < 96; y++) {
            oledC_sendColorInt(background_color);
        }
    }
}

void display_setBackground(uint16_t color) {
    background_color = color;
    display_clearScreen();
}

void display_Splash(void) {
    display_setBackground(OLEDC_COLOR_BLACK);
    shape_params_t params;

    params.bitmap.color = OLEDC_COLOR_RED;
    params.bitmap.x = 30;
    params.bitmap.y = 60;
    params.bitmap.sx = 1;
    params.bitmap.sy = 1;
    params.bitmap.bit_array = logo;
    params.bitmap.array_length = 23;
    oledC_addShape(0, OLED_SHAPE_BITMAP, &params);

    params.string.color = OLEDC_COLOR_WHITE;
    params.string.x = 2;
    params.string.y = 2;
    params.string.scale_x = 1;
    params.string.scale_y = 2;
    params.string.string = "PIC18F16Q41";
    oledC_addShape(1, OLED_SHAPE_STRING, &params);

    params.string.color = OLEDC_COLOR_WHITE;
    params.string.x = 2;
    params.string.y = 19;
    params.string.scale_x = 1;
    params.string.scale_y = 2;
    params.string.string = "Curiosity Nano";
    oledC_addShape(2, OLED_SHAPE_STRING, &params);

    params.string.color = OLEDC_COLOR_WHITE;
    params.string.x = 2;
    params.string.y = 36;
    params.string.scale_x = 1;
    params.string.scale_y = 2;
    params.string.string = "Weather Station";
    oledC_addShape(3, OLED_SHAPE_STRING, &params);

    oledC_redrawIndex(1);
    oledC_redrawIndex(2);
    oledC_redrawIndex(3);
    oledC_redrawIndex(0);

    splashInitialized = true;
}

void display_PrintLabels(void) {
    shape_params_t params;

    params.string.color = OLEDC_COLOR_YELLOW;
    params.string.x = 4;
    params.string.y = 5;
    params.string.scale_x = 1;
    params.string.scale_y = 2;
    params.string.string = "Temp: ";
    oledC_addShape(4, OLED_SHAPE_STRING, &params);

    params.string.color = OLEDC_COLOR_YELLOW;
    params.string.x = 4;
    params.string.y = 25;
    params.string.scale_x = 1;
    params.string.scale_y = 2;
    params.string.string = "Press: ";
    oledC_addShape(5, OLED_SHAPE_STRING, &params);

    params.string.color = OLEDC_COLOR_YELLOW;
    params.string.x = 4;
    params.string.y = 45;
    params.string.scale_x = 1;
    params.string.scale_y = 2;
    params.string.string = "Humidity: ";
    oledC_addShape(6, OLED_SHAPE_STRING, &params);

    params.string.color = OLEDC_COLOR_YELLOW;
    params.string.x = 4;
    params.string.y = 65;
    params.string.scale_x = 1;
    params.string.scale_y = 2;
    params.string.string = "Light: ";
    oledC_addShape(7, OLED_SHAPE_STRING, &params);

    oledC_redrawIndex(4);
    oledC_redrawIndex(5);
    oledC_redrawIndex(6);
    oledC_redrawIndex(7);
    __delay_ms(500);
}

void display_PrintWeatherString(void) {
        shape_params_t params;
    
        params.string.color = OLEDC_COLOR_YELLOW;
        params.string.x = 4;
        params.string.y = 5;
        params.string.scale_x = 1;
        params.string.scale_y = 2;
        params.string.string = str_temp;
        oledC_addShape(8, OLED_SHAPE_STRING, &params);
    
        params.string.color = OLEDC_COLOR_YELLOW;
        params.string.x = 4;
        params.string.y = 25;
        params.string.scale_x = 1;
        params.string.scale_y = 2;
        params.string.string = str_press;
        oledC_addShape(9, OLED_SHAPE_STRING, &params);
    
        params.string.color = OLEDC_COLOR_YELLOW;
        params.string.x = 4;
        params.string.y = 45;
        params.string.scale_x = 1;
        params.string.scale_y = 2;
        params.string.string = str_hum;
        oledC_addShape(10, OLED_SHAPE_STRING, &params);
    
        params.string.color = OLEDC_COLOR_YELLOW;
        params.string.x = 4;
        params.string.y = 65;
        params.string.scale_x = 1;
        params.string.scale_y = 2;
        params.string.string = str_light;
        oledC_addShape(11, OLED_SHAPE_STRING, &params);
    
        weatherInitialized = true;
}

void display_eraseValues(void) {
    oledC_eraseShape(8, background_color);
    oledC_eraseShape(9, background_color);
    oledC_eraseShape(10, background_color);
    oledC_eraseShape(11, background_color);
}

void display_Print_Splash(void) {
    if (!splashInitialized) {
        //printf("Display not yet initialised!\nDisplaying splash screen\n\n");
        display_Splash();
    }
    __delay_ms(5000); // Hold Splash Screen;
    display_clearScreen(); // Clear Screen;
}

void display_Print_Weather(void) {
    if (!weatherInitialized) {
        display_setBackground(OLEDC_COLOR_BLACK);
        display_PrintLabels();
        display_PrintWeatherString();
    }
    oledC_redrawIndex(8);
    oledC_redrawIndex(9);
    oledC_redrawIndex(10);
    oledC_redrawIndex(11);
}