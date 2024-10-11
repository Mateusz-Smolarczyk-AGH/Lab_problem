/*
 * TRAS_DevDriv_data.c
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

#include "TRAS_DevDriv.h"
#include "TRAS_DevDriv_private.h"

/* Block parameters (default storage) */
P_TRAS_DevDriv_T TRAS_DevDriv_P = {
  /* Mask Parameter: PIDController1_D
   * Referenced by: '<S80>/Derivative Gain'
   */
  1.152,

  /* Mask Parameter: PIDController_D
   * Referenced by: '<S32>/Derivative Gain'
   */
  0.9464,

  /* Mask Parameter: PIDController_I
   * Referenced by: '<S35>/Integral Gain'
   */
  0.4392,

  /* Mask Parameter: PIDController1_I
   * Referenced by: '<S83>/Integral Gain'
   */
  0.0367,

  /* Mask Parameter: PIDController1_InitialConditionForFilter
   * Referenced by: '<S81>/Filter'
   */
  0.0,

  /* Mask Parameter: PIDController_InitialConditionForFilter
   * Referenced by: '<S33>/Filter'
   */
  0.0,

  /* Mask Parameter: PIDController1_InitialConditionForIntegrator
   * Referenced by: '<S86>/Integrator'
   */
  0.0,

  /* Mask Parameter: PIDController_InitialConditionForIntegrator
   * Referenced by: '<S38>/Integrator'
   */
  0.0,

  /* Mask Parameter: PIDController1_LowerSaturationLimit
   * Referenced by: '<S93>/Saturation'
   */
  -1.0,

  /* Mask Parameter: PIDController_LowerSaturationLimit
   * Referenced by: '<S45>/Saturation'
   */
  -1.43,

  /* Mask Parameter: PIDController1_N
   * Referenced by: '<S89>/Filter Coefficient'
   */
  100.0,

  /* Mask Parameter: PIDController_N
   * Referenced by: '<S41>/Filter Coefficient'
   */
  100.0,

  /* Mask Parameter: PIDController1_P
   * Referenced by: '<S91>/Proportional Gain'
   */
  1.2465,

  /* Mask Parameter: PIDController_P
   * Referenced by: '<S43>/Proportional Gain'
   */
  0.9978,

  /* Mask Parameter: PIDController1_UpperSaturationLimit
   * Referenced by: '<S93>/Saturation'
   */
  1.0,

  /* Mask Parameter: PIDController_UpperSaturationLimit
   * Referenced by: '<S45>/Saturation'
   */
  1.43,

  /* Expression: 1
   * Referenced by: '<Root>/Reset'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<Root>/Normal'
   */
  0.0,

  /* Computed Parameter: Encoder_P1_Size
   * Referenced by: '<S6>/Encoder'
   */
  { 1.0, 1.0 },

  /* Expression: BaseAddress
   * Referenced by: '<S6>/Encoder'
   */
  57088.0,

  /* Computed Parameter: Encoder_P2_Size
   * Referenced by: '<S6>/Encoder'
   */
  { 1.0, 1.0 },

  /* Expression: T0
   * Referenced by: '<S6>/Encoder'
   */
  0.01,

  /* Expression: 1
   * Referenced by: '<S6>/Encoder 1024 PPR'
   */
  1.0,

  /* Expression: 2*pi/4096
   * Referenced by: '<S6>/Convert to rad'
   */
  0.0015339807878856412,

  /* Expression: 180/pi
   * Referenced by: '<S3>/Gain'
   */
  57.295779513082323,

  /* Computed Parameter: AnalogInput_P1_Size
   * Referenced by: '<S6>/Analog Input'
   */
  { 1.0, 1.0 },

  /* Expression: BaseAddress
   * Referenced by: '<S6>/Analog Input'
   */
  57088.0,

  /* Computed Parameter: AnalogInput_P2_Size
   * Referenced by: '<S6>/Analog Input'
   */
  { 1.0, 2.0 },

  /* Expression: [1 0]
   * Referenced by: '<S6>/Analog Input'
   */
  { 1.0, 0.0 },

  /* Computed Parameter: AnalogInput_P3_Size
   * Referenced by: '<S6>/Analog Input'
   */
  { 1.0, 2.0 },

  /* Expression: [1 1]
   * Referenced by: '<S6>/Analog Input'
   */
  { 1.0, 1.0 },

  /* Computed Parameter: AnalogInput_P4_Size
   * Referenced by: '<S6>/Analog Input'
   */
  { 1.0, 1.0 },

  /* Expression: T0
   * Referenced by: '<S6>/Analog Input'
   */
  0.01,

  /* Expression: 1000/0.52/2
   * Referenced by: '<S6>/Convert to RPM'
   */
  961.53846153846155,

  /* Expression: 1
   * Referenced by: '<Root>/Gain1'
   */
  1.0,

  /* Expression: 180/pi
   * Referenced by: '<S4>/Gain'
   */
  57.295779513082323,

  /* Expression: 1
   * Referenced by: '<Root>/Constant1'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<Root>/Multiply1'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<Root>/Constant3'
   */
  1.0,

  /* Expression: 0.02716049382716057
   * Referenced by: '<Root>/Multiply3'
   */
  0.02716049382716057,

  /* Expression: 1
   * Referenced by: '<Root>/Constant2'
   */
  1.0,

  /* Expression: -0.01234567901234573
   * Referenced by: '<Root>/Multiply2'
   */
  -0.01234567901234573,

  /* Expression: -1
   * Referenced by: '<Root>/Gain'
   */
  -1.0,

  /* Expression: 1
   * Referenced by: '<S6>/Saturation'
   */
  1.0,

  /* Expression: -1
   * Referenced by: '<S6>/Saturation'
   */
  -1.0,

  /* Computed Parameter: PWM_P1_Size
   * Referenced by: '<S6>/PWM'
   */
  { 1.0, 1.0 },

  /* Expression: BaseAddress
   * Referenced by: '<S6>/PWM'
   */
  57088.0,

  /* Computed Parameter: PWM_P2_Size
   * Referenced by: '<S6>/PWM'
   */
  { 1.0, 1.0 },

  /* Expression: T0
   * Referenced by: '<S6>/PWM'
   */
  0.01,

  /* Computed Parameter: ResetEncoder_P1_Size
   * Referenced by: '<S6>/ResetEncoder'
   */
  { 1.0, 1.0 },

  /* Expression: BaseAddress
   * Referenced by: '<S6>/ResetEncoder'
   */
  57088.0,

  /* Computed Parameter: ResetEncoder_P2_Size
   * Referenced by: '<S6>/ResetEncoder'
   */
  { 1.0, 1.0 },

  /* Expression: T0
   * Referenced by: '<S6>/ResetEncoder'
   */
  0.01,

  /* Computed Parameter: BitstreamVersion_P1_Size
   * Referenced by: '<S6>/Bitstream Version'
   */
  { 1.0, 1.0 },

  /* Expression: BaseAddress
   * Referenced by: '<S6>/Bitstream Version'
   */
  57088.0,

  /* Computed Parameter: BitstreamVersion_P2_Size
   * Referenced by: '<S6>/Bitstream Version'
   */
  { 1.0, 1.0 },

  /* Expression: T0
   * Referenced by: '<S6>/Bitstream Version'
   */
  0.01,

  /* Computed Parameter: ThermStatus_P1_Size
   * Referenced by: '<S6>/Therm Status'
   */
  { 1.0, 1.0 },

  /* Expression: BaseAddress
   * Referenced by: '<S6>/Therm Status'
   */
  57088.0,

  /* Computed Parameter: ThermStatus_P2_Size
   * Referenced by: '<S6>/Therm Status'
   */
  { 1.0, 1.0 },

  /* Expression: T0
   * Referenced by: '<S6>/Therm Status'
   */
  0.01,

  /* Expression: [0 0]
   * Referenced by: '<S6>/PWMPrescalerSource'
   */
  { 0.0, 0.0 },

  /* Computed Parameter: PWMPrescaler_P1_Size
   * Referenced by: '<S6>/PWMPrescaler'
   */
  { 1.0, 1.0 },

  /* Expression: BaseAddress
   * Referenced by: '<S6>/PWMPrescaler'
   */
  57088.0,

  /* Computed Parameter: PWMPrescaler_P2_Size
   * Referenced by: '<S6>/PWMPrescaler'
   */
  { 1.0, 1.0 },

  /* Expression: T0
   * Referenced by: '<S6>/PWMPrescaler'
   */
  0.01,

  /* Expression: [1 1]
   * Referenced by: '<S6>/ThermFlagSource'
   */
  { 1.0, 1.0 },

  /* Computed Parameter: ThermFlag_P1_Size
   * Referenced by: '<S6>/ThermFlag '
   */
  { 1.0, 1.0 },

  /* Expression: BaseAddress
   * Referenced by: '<S6>/ThermFlag '
   */
  57088.0,

  /* Computed Parameter: ThermFlag_P2_Size
   * Referenced by: '<S6>/ThermFlag '
   */
  { 1.0, 1.0 },

  /* Expression: T0
   * Referenced by: '<S6>/ThermFlag '
   */
  0.01,

  /* Computed Parameter: ControlType_CurrentSetting
   * Referenced by: '<Root>/Control Type'
   */
  1U,

  /* Computed Parameter: ControlType2_CurrentSetting
   * Referenced by: '<Root>/Control Type2'
   */
  0U,

  /* Computed Parameter: ResetEncoders_CurrentSetting
   * Referenced by: '<Root>/Reset Encoders'
   */
  0U
};
