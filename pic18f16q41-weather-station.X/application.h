/* 
 * File:   application.h
 * Author: C16783
 *
 * Created on May 18, 2020, 2:40 PM
 */

#ifndef APPLICATION_H
#define	APPLICATION_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <xc.h>
#include "mcc_generated_files/mcc.h"
#include "ambient.h"
#include "bme280.h"


    //int8_t temp_string; // Temperature
    float temp_string; // Temperature
    //uint8_t press_string; // Pressure
    uint16_t press_string; // Pressure
    uint8_t humid_string; // Humidity
    //uint8_t light_string; // Ambient Light
    uint16_t light_string; // Ambient Light

    void WeatherStation_initialize(void);
    void WeatherClick_readSensors(void);
    float GetLightIntensity(void);
    void WeatherStation_Print(void);

#ifdef	__cplusplus
}
#endif

#endif	/* APPLICATION_H */

