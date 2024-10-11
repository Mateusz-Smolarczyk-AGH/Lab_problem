/*
 * TRAS_DevDriv_private.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "TRAS_DevDriv".
 *
 * Model version              : 1.125
 * Simulink Coder version : 9.6 (R2021b) 14-May-2021
 * C source code generated on : Tue Apr 16 14:30:42 2024
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_TRAS_DevDriv_private_h_
#define RTW_HEADER_TRAS_DevDriv_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"

/* Used by FromWorkspace Block: '<S5>/FromWs' */
#ifndef rtInterpolate
# define rtInterpolate(v1,v2,f1,f2)    (((v1)==(v2))?((double)(v1)): (((f1)*((double)(v1)))+((f2)*((double)(v2)))))
#endif

#ifndef rtRound
# define rtRound(v)                    ( ((v) >= 0) ? floor((v) + 0.5) : ceil((v) - 0.5) )
#endif

extern void TRAS_Encoder(SimStruct *rts);
extern void TRAS_AnalogInput(SimStruct *rts);
extern void TRAS_PWM(SimStruct *rts);
extern void TRAS_ResetEncoder(SimStruct *rts);
extern void TRAS_BitstreamVersion(SimStruct *rts);
extern void TRAS_PWMTherm(SimStruct *rts);
extern void TRAS_PWMPrescaler(SimStruct *rts);
extern void TRAS_ThermFlag(SimStruct *rts);

/* private model entry point functions */
extern void TRAS_DevDriv_derivatives(void);

#endif                                 /* RTW_HEADER_TRAS_DevDriv_private_h_ */
