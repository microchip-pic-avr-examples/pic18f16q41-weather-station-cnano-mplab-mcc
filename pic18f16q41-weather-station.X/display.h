/* 
 * File:   display.h
 * Author: C16783
 *
 * Created on May 20, 2020, 11:11 AM
 */

#ifndef DISPLAY_H
#define	DISPLAY_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <xc.h>
#include "mcc_generated_files/mcc.h"
#include "mcc_generated_files/oledC.h"
#include "mcc_generated_files/oledC_colors.h"
#include "mcc_generated_files/oledC_shapeHandler.h"
#include "mcc_generated_files/oledC_shapes.h"
#include "bme280.h"
#include <stdint.h>
#include <stdbool.h>

    bool splashInitialized = false;
    bool weatherInitialized = false;
    uint16_t background_color;


    static const uint32_t logo[] = {
        0b11111111111000000000011111111111,
        0b11111111100000000000001111111111,
        0b11111111000000000000000111111111,
        0b11111110000000000000000111111111,
        0b11111100000000000000000011111111,
        0b11111000000010000000100011111111,
        0b11111000000110000001100001111111,
        0b11110000001111000011110000111111,
        0b11110000001111100011111000111111,
        0b11110000000111100001111000011111,
        0b11110000000111110001111100001111,
        0b11110001000011110000111110001111,
        0b11110001100011111000111110001111,
        0b11110011110001111100011111001111,
        0b11110111110000111100001111001111,
        0b11111111100000111100001111111111,
        0b11111111100000011100000111111111,
        0b11111111000000011000000011111111,
        0b11111110000000000000000011111111,
        0b11111110000000000000000001111111,
        0b11111110000000000000000001111111,
        0b11111111100000000000000111111111,
        0b11111111111000000000011111111111
    };

    // Macro Declaration;
    void display_clearScreen(void);
    void display_setBackground(uint16_t color);
    void display_Splash(void);
    void display_PrintLabels(void);
    void display_PrintWeatherString(void);
    display_eraseValues(void);
    display_Print_Splash(void);
    oledC_Print_Weather(void);

#ifdef	__cplusplus
}
#endif

#endif	/* DISPLAY_H */

