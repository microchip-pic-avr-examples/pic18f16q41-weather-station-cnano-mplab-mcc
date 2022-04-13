/*
 * File:   ambient.c
 * Author: C16783
 *
 * Created on May 13, 2020, 11:56 AM
 */


#include "ambient.h"
#include "mcc_generated_files/adcc.h"

float Ambient_ReadSensor(void) {
    ADPCH = AMBIENT; // Select AMBIENT analog channel as ADCC positive input;
    ADCON0bits.ADGO = 1; // Trigger burst-average ADCC conversions;
    while (ADCON0bits.ADGO); // Wait for ADC Threshold Interrupt Flag to set;
    while (!PIR2bits.ADTIF); // Wait for ADC Threshold Interrupt Flag to set;
    return (ADCC_GetFilterValue()); // Return ADC Burst Average Result;
}

float AmbientCompensation(void) {
    float Ambient_Raw, Ambient_Volt, Light_Intensity;
    Ambient_Raw = Ambient_ReadSensor();
    Ambient_Volt = (Ambient_Raw / ADCC_RESOLUTION)*(ADCC_POS_REFERENCE); // Calculate ADC voltage using conversion result;
    Light_Intensity = (POLY1_TERM1 * Ambient_Volt) + POLY1_TERM0; // Calculate ambient light intensity;
    return (Light_Intensity); // Return light intensity (uW/cm^2);
}