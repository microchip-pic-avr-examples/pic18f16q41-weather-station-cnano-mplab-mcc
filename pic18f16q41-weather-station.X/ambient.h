/* 
 * File:   ambient.h
 * Author: C16783
 *
 * Created on May 13, 2020, 11:56 AM
 */

#ifndef AMBIENT_H
#define	AMBIENT_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <xc.h>
#include "mcc_generated_files/mcc.h"
#include <math.h>

#define ADCC_RESOLUTION         4096
#define ADCC_POS_REFERENCE      4.096
#define POLY1_TERM1             147.2
#define POLY1_TERM0             -9.5  


    float Ambient_ReadSensor(void);
    float AmbientCompensation(void);

#ifdef	__cplusplus
}
#endif

#endif	/* AMBIENT_H */

