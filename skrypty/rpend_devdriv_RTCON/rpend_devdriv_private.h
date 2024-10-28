/*
 * rpend_devdriv_private.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "rpend_devdriv".
 *
 * Model version              : 1.449
 * Simulink Coder version : 9.0 (R2018b) 24-May-2018
 * C source code generated on : Thu Oct 24 18:39:39 2024
 *
 * Target selection: rtcon_rpend_usb2.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_rpend_devdriv_private_h_
#define RTW_HEADER_rpend_devdriv_private_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmIsMajorTimeStep
# define rtmIsMajorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
# define rtmIsMinorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmSetTFinal
# define rtmSetTFinal(rtm, val)        ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmSetTPtr
# define rtmSetTPtr(rtm, val)          ((rtm)->Timing.t = (val))
#endif

extern uint32_T MWDSP_EPH_R_D(real_T evt, uint32_T *sta);
extern real_T rt_atan2d_snf(real_T u0, real_T u1);
extern void rtdacusb2_rpend_dd(SimStruct *rts);

#endif                                 /* RTW_HEADER_rpend_devdriv_private_h_ */
