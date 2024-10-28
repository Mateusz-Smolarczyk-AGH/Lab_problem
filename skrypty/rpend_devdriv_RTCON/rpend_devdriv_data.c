/*
 * rpend_devdriv_data.c
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

#include "rpend_devdriv.h"
#include "rpend_devdriv_private.h"

/* Block parameters (default storage) */
P_rpend_devdriv_T rpend_devdriv_P = {
  /* Variable: K_lqr
   * Referenced by: '<Root>/Gain'
   */
  { -268.343316033645, -64.52416890128022, 0.34092619198821589,
    -661.8714804466963 },

  /* Variable: xep
   * Referenced by: '<Root>/Constant'
   */
  { 3.1415926535897931, 0.0, 0.0, 0.0 },

  /* Expression: 0
   * Referenced by: '<Root>/Reset2'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<Root>/Reset1'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<Root>/Reset'
   */
  1.0,

  /* Computed Parameter: SFunction_P1_Size
   * Referenced by: '<S1>/S-Function'
   */
  { 1.0, 1.0 },

  /* Expression: 1
   * Referenced by: '<S1>/S-Function'
   */
  1.0,

  /* Computed Parameter: SFunction_P2_Size
   * Referenced by: '<S1>/S-Function'
   */
  { 1.0, 1.0 },

  /* Expression: 0.01
   * Referenced by: '<S1>/S-Function'
   */
  0.01,

  /* Expression: 2*pi/4096
   * Referenced by: '<S1>/DC Convert to rad'
   */
  0.0015339807878856412,

  /* Expression: 0
   * Referenced by: '<S1>/Memory1'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S1>/rad2RPM'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S1>/Memory'
   */
  0.0,

  /* Expression: 1/20000000
   * Referenced by: '<S1>/Gain1'
   */
  5.0E-8,

  /* Expression: 2*pi/20000
   * Referenced by: '<S1>/Pendulum Convert to rad'
   */
  0.00031415926535897931,

  /* Expression: pi
   * Referenced by: '<S5>/Constant'
   */
  3.1415926535897931,

  /* Expression: 0
   * Referenced by: '<S1>/Memory2'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S1>/rad2rad//s'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<Root>/Saturation'
   */
  1.0,

  /* Expression: -1
   * Referenced by: '<Root>/Saturation'
   */
  -1.0,

  /* Expression: 0
   * Referenced by: '<Root>/Normal'
   */
  0.0,

  /* Expression: 0.5
   * Referenced by: '<Root>/Gain3'
   */
  0.5,

  /* Expression: 1
   * Referenced by: '<S1>/DC Convert to [A]1'
   */
  1.0,

  /* Expression: 0.05
   * Referenced by: '<Root>/Step'
   */
  0.05,

  /* Expression: 1
   * Referenced by: '<Root>/Step'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<Root>/Step'
   */
  0.0,

  /* Expression: [1;1]
   * Referenced by: '<S1>/Gain'
   */
  { 1.0, 1.0 },

  /* Expression: 1
   * Referenced by: '<S1>/Gain2'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S1>/Prescaler'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S1>/Saturation'
   */
  1.0,

  /* Expression: -1
   * Referenced by: '<S1>/Saturation'
   */
  -1.0,

  /* Expression: 0
   * Referenced by: '<S1>/ThermFlag'
   */
  0.0,

  /* Computed Parameter: ResetEncoders2_CurrentSetting
   * Referenced by: '<Root>/Reset Encoders2'
   */
  0U,

  /* Computed Parameter: ResetEncoders1_CurrentSetting
   * Referenced by: '<Root>/Reset Encoders1'
   */
  1U,

  /* Computed Parameter: ResetEncoders_CurrentSetting
   * Referenced by: '<Root>/Reset Encoders'
   */
  0U
};
