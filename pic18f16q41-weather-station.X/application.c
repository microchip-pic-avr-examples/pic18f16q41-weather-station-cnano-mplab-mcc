/*
 * File:   weather_application.c
 * Author: C16783
 *
 * Created on May 18, 2020, 2:39 PM
 */

#include "application.h"
#include "display.h"

/**
  Section: Variable Definitions
 */

#define DEFAULT_STANDBY_TIME    BME280_STANDBY_HALFMS
#define DEFAULT_FILTER_COEFF    BME280_FILTER_COEFF_OFF
#define DEFAULT_TEMP_OSRS       BME280_OVERSAMP_X1
#define DEFAULT_PRESS_OSRS      BME280_OVERSAMP_X1
#define DEFAULT_HUM_OSRS        BME280_OVERSAMP_X1
#define DEFAULT_SENSOR_MODE     BME280_FORCED_MODE

bool weather_initialized = 0;
float LightIntensity;
bool label_initial = false;

/**
  Section: Driver APIs
 */

void WeatherClick_readSensors(void) {
    if (DEFAULT_SENSOR_MODE == BME280_FORCED_MODE) {
        BME280_startForcedSensing();
    }
    BME280_readMeasurements();
}

//void GetLightIntensity(void) {
//    LightIntensity = AmbientCompensation();
//}

void WeatherStation_initialize(void) {
    BME280_reset();
    __delay_ms(50);
    BME280_readFactoryCalibrationParams();
    BME280_config(BME280_STANDBY_HALFMS, BME280_FILTER_COEFF_OFF);
    BME280_ctrl_meas(BME280_OVERSAMP_X1, BME280_OVERSAMP_X1, BME280_FORCED_MODE);
    BME280_ctrl_hum(BME280_OVERSAMP_X1);
    BME280_initializeSensor();
    printf("PIC18F16Q40 Weather Station \r\n");
    printf("Curiosity Nano Development Board \r\n\n");
    weather_initialized = 1;
}

void WeatherStation_Print(void) {
    if (label_initial == true) {
        display_eraseValues();
    }

    WeatherClick_readSensors();

    //temp_string = (int8_t) BME280_getTemperature();
    temp_string = BME280_getTemperature();
    //press_string = (uint8_t) BME280_getPressure();
    press_string = BME280_getPressure();    // using float
    humid_string = (uint8_t) BME280_getHumidity();
    //light_string = (uint8_t) AmbientCompensation();
    light_string = (uint16_t) AmbientCompensation();

    //sprintf(str_temp, "      %i C", temp_string); // Temperature to String Conversion;
    sprintf(str_temp, "      %.1fC", temp_string); // Temperature to String Conversion;
    //sprintf(str_press, "       %u inHg", press_string); // Pressure to String Conversion;
    sprintf(str_press, "       %u hPa", press_string); // Pressure to String Conversion;
    sprintf(str_hum, "          %u%%", humid_string); // Humidity to String Conversion;
    //sprintf(str_light, "       %iuW/cm2", light_string); // Light to String Conversion;
    sprintf(str_light, "       %uuW/cm2", light_string); // Light to String Conversion;

    //printf("Temperature: %i C \r\n", temp_string);
    printf("Temperature: %.1f°C \r\n", temp_string);
    printf("Pressure: %u hPa\r\n", press_string);
    printf("Relative Humidity: %u%% \r\n", humid_string);
    printf("Light Intensity: %u (uW/cm2) \r\n\n", light_string);

    display_Print_Weather();
    label_initial = true;
}