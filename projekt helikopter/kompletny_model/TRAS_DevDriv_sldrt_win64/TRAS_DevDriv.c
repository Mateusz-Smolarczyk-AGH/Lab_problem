/*
 * TRAS_DevDriv.c
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
#include "TRAS_DevDriv_dt.h"

/* list of Simulink Desktop Real-Time timers */
const int SLDRTTimerCount = 1;
const double SLDRTTimers[2] = {
  0.01, 0.0,
};

/* Block signals (default storage) */
B_TRAS_DevDriv_T TRAS_DevDriv_B;

/* Continuous states */
X_TRAS_DevDriv_T TRAS_DevDriv_X;

/* Block states (default storage) */
DW_TRAS_DevDriv_T TRAS_DevDriv_DW;

/* Real-time model */
static RT_MODEL_TRAS_DevDriv_T TRAS_DevDriv_M_;
RT_MODEL_TRAS_DevDriv_T *const TRAS_DevDriv_M = &TRAS_DevDriv_M_;

/*
 * This function updates continuous states using the ODE5 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE5_A[6] = {
    1.0/5.0, 3.0/10.0, 4.0/5.0, 8.0/9.0, 1.0, 1.0
  };

  static const real_T rt_ODE5_B[6][6] = {
    { 1.0/5.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

    { 3.0/40.0, 9.0/40.0, 0.0, 0.0, 0.0, 0.0 },

    { 44.0/45.0, -56.0/15.0, 32.0/9.0, 0.0, 0.0, 0.0 },

    { 19372.0/6561.0, -25360.0/2187.0, 64448.0/6561.0, -212.0/729.0, 0.0, 0.0 },

    { 9017.0/3168.0, -355.0/33.0, 46732.0/5247.0, 49.0/176.0, -5103.0/18656.0,
      0.0 },

    { 35.0/384.0, 0.0, 500.0/1113.0, 125.0/192.0, -2187.0/6784.0, 11.0/84.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE5_IntgData *id = (ODE5_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T *f3 = id->f[3];
  real_T *f4 = id->f[4];
  real_T *f5 = id->f[5];
  real_T hB[6];
  int_T i;
  int_T nXc = 4;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  TRAS_DevDriv_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE5_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE5_A[0]);
  rtsiSetdX(si, f1);
  TRAS_DevDriv_output();
  TRAS_DevDriv_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE5_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE5_A[1]);
  rtsiSetdX(si, f2);
  TRAS_DevDriv_output();
  TRAS_DevDriv_derivatives();

  /* f(:,4) = feval(odefile, t + hA(3), y + f*hB(:,3), args(:)(*)); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE5_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, t + h*rt_ODE5_A[2]);
  rtsiSetdX(si, f3);
  TRAS_DevDriv_output();
  TRAS_DevDriv_derivatives();

  /* f(:,5) = feval(odefile, t + hA(4), y + f*hB(:,4), args(:)(*)); */
  for (i = 0; i <= 3; i++) {
    hB[i] = h * rt_ODE5_B[3][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2] +
                   f3[i]*hB[3]);
  }

  rtsiSetT(si, t + h*rt_ODE5_A[3]);
  rtsiSetdX(si, f4);
  TRAS_DevDriv_output();
  TRAS_DevDriv_derivatives();

  /* f(:,6) = feval(odefile, t + hA(5), y + f*hB(:,5), args(:)(*)); */
  for (i = 0; i <= 4; i++) {
    hB[i] = h * rt_ODE5_B[4][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2] +
                   f3[i]*hB[3] + f4[i]*hB[4]);
  }

  rtsiSetT(si, tnew);
  rtsiSetdX(si, f5);
  TRAS_DevDriv_output();
  TRAS_DevDriv_derivatives();

  /* tnew = t + hA(6);
     ynew = y + f*hB(:,6); */
  for (i = 0; i <= 5; i++) {
    hB[i] = h * rt_ODE5_B[5][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2] +
                   f3[i]*hB[3] + f4[i]*hB[4] + f5[i]*hB[5]);
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function */
void TRAS_DevDriv_output(void)
{
  real_T rtb_Sum;
  real_T rtb_Sum1;
  real_T u0;
  if (rtmIsMajorTimeStep(TRAS_DevDriv_M)) {
    /* set solver stop time */
    if (!(TRAS_DevDriv_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&TRAS_DevDriv_M->solverInfo,
                            ((TRAS_DevDriv_M->Timing.clockTickH0 + 1) *
        TRAS_DevDriv_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&TRAS_DevDriv_M->solverInfo,
                            ((TRAS_DevDriv_M->Timing.clockTick0 + 1) *
        TRAS_DevDriv_M->Timing.stepSize0 + TRAS_DevDriv_M->Timing.clockTickH0 *
        TRAS_DevDriv_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(TRAS_DevDriv_M)) {
    TRAS_DevDriv_M->Timing.t[0] = rtsiGetT(&TRAS_DevDriv_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(TRAS_DevDriv_M)) {
    /* S-Function (TRAS_Encoder): '<S6>/Encoder' */

    /* Level2 S-Function Block: '<S6>/Encoder' (TRAS_Encoder) */
    {
      SimStruct *rts = TRAS_DevDriv_M->childSfunctions[0];
      sfcnOutputs(rts,0);
    }

    /* Gain: '<S6>/Convert to rad' incorporates:
     *  Gain: '<S6>/Encoder 1024 PPR'
     */
    TRAS_DevDriv_B.Converttorad[0] = TRAS_DevDriv_P.Encoder1024PPR_Gain *
      TRAS_DevDriv_B.Encoder[0] * TRAS_DevDriv_P.Converttorad_Gain;
    TRAS_DevDriv_B.Converttorad[1] = TRAS_DevDriv_P.Encoder1024PPR_Gain *
      TRAS_DevDriv_B.Encoder[1] * TRAS_DevDriv_P.Converttorad_Gain;

    /* Gain: '<S3>/Gain' */
    TRAS_DevDriv_B.Gain = TRAS_DevDriv_P.Gain_Gain *
      TRAS_DevDriv_B.Converttorad[0];

    /* S-Function (TRAS_AnalogInput): '<S6>/Analog Input' */

    /* Level2 S-Function Block: '<S6>/Analog Input' (TRAS_AnalogInput) */
    {
      SimStruct *rts = TRAS_DevDriv_M->childSfunctions[1];
      sfcnOutputs(rts,0);
    }

    /* Gain: '<S6>/Convert to RPM' */
    TRAS_DevDriv_B.ConverttoRPM[0] = TRAS_DevDriv_P.ConverttoRPM_Gain *
      TRAS_DevDriv_B.AnalogInput[0];
    TRAS_DevDriv_B.ConverttoRPM[1] = TRAS_DevDriv_P.ConverttoRPM_Gain *
      TRAS_DevDriv_B.AnalogInput[1];
  }

  /* FromWorkspace: '<S5>/FromWs' */
  {
    real_T *pDataValues = (real_T *) TRAS_DevDriv_DW.FromWs_PWORK.DataPtr;
    real_T *pTimeValues = (real_T *) TRAS_DevDriv_DW.FromWs_PWORK.TimePtr;
    int_T currTimeIndex = TRAS_DevDriv_DW.FromWs_IWORK.PrevIndex;
    real_T t = TRAS_DevDriv_M->Timing.t[0];

    /* Get index */
    if (t <= pTimeValues[0]) {
      currTimeIndex = 0;
    } else if (t >= pTimeValues[33]) {
      currTimeIndex = 32;
    } else {
      if (t < pTimeValues[currTimeIndex]) {
        while (t < pTimeValues[currTimeIndex]) {
          currTimeIndex--;
        }
      } else {
        while (t >= pTimeValues[currTimeIndex + 1]) {
          currTimeIndex++;
        }
      }
    }

    TRAS_DevDriv_DW.FromWs_IWORK.PrevIndex = currTimeIndex;

    /* Post output */
    {
      real_T t1 = pTimeValues[currTimeIndex];
      real_T t2 = pTimeValues[currTimeIndex + 1];
      if (t1 == t2) {
        if (t < t1) {
          {
            int_T elIdx;
            for (elIdx = 0; elIdx < 2; ++elIdx) {
              (&TRAS_DevDriv_B.FromWs[0])[elIdx] = pDataValues[currTimeIndex];
              pDataValues += 34;
            }
          }
        } else {
          {
            int_T elIdx;
            for (elIdx = 0; elIdx < 2; ++elIdx) {
              (&TRAS_DevDriv_B.FromWs[0])[elIdx] = pDataValues[currTimeIndex + 1];
              pDataValues += 34;
            }
          }
        }
      } else {
        real_T f1 = (t2 - t) / (t2 - t1);
        real_T f2 = 1.0 - f1;
        real_T d1;
        real_T d2;
        int_T TimeIndex = currTimeIndex;

        {
          int_T elIdx;
          for (elIdx = 0; elIdx < 2; ++elIdx) {
            d1 = pDataValues[TimeIndex];
            d2 = pDataValues[TimeIndex + 1];
            (&TRAS_DevDriv_B.FromWs[0])[elIdx] = (real_T) rtInterpolate(d1, d2,
              f1, f2);
            pDataValues += 34;
          }
        }
      }
    }
  }

  /* Gain: '<Root>/Gain1' */
  TRAS_DevDriv_B.Gain1 = TRAS_DevDriv_P.Gain1_Gain * TRAS_DevDriv_B.FromWs[0];
  if (rtmIsMajorTimeStep(TRAS_DevDriv_M)) {
    /* Gain: '<S4>/Gain' */
    TRAS_DevDriv_B.Gain_p = TRAS_DevDriv_P.Gain_Gain_n *
      TRAS_DevDriv_B.Converttorad[1];

    /* Gain: '<Root>/Multiply1' incorporates:
     *  Constant: '<Root>/Constant1'
     */
    TRAS_DevDriv_B.Multiply1 = TRAS_DevDriv_P.Multiply1_Gain *
      TRAS_DevDriv_P.Constant1_Value;

    /* Sum: '<Root>/Sum1' incorporates:
     *  Constant: '<Root>/Constant3'
     *  Gain: '<Root>/Multiply3'
     */
    rtb_Sum1 = TRAS_DevDriv_P.Multiply3_Gain * TRAS_DevDriv_P.Constant3_Value -
      TRAS_DevDriv_B.Converttorad[0];

    /* Gain: '<S91>/Proportional Gain' */
    TRAS_DevDriv_B.ProportionalGain = TRAS_DevDriv_P.PIDController1_P * rtb_Sum1;

    /* Gain: '<S80>/Derivative Gain' */
    TRAS_DevDriv_B.DerivativeGain = TRAS_DevDriv_P.PIDController1_D * rtb_Sum1;
  }

  /* Gain: '<S89>/Filter Coefficient' incorporates:
   *  Integrator: '<S81>/Filter'
   *  Sum: '<S81>/SumD'
   */
  TRAS_DevDriv_B.FilterCoefficient = (TRAS_DevDriv_B.DerivativeGain -
    TRAS_DevDriv_X.Filter_CSTATE) * TRAS_DevDriv_P.PIDController1_N;

  /* ManualSwitch: '<Root>/Control Type' */
  if (TRAS_DevDriv_P.ControlType_CurrentSetting == 1) {
    /* ManualSwitch: '<Root>/Control Type' */
    TRAS_DevDriv_B.ControlType = TRAS_DevDriv_B.Multiply1;
  } else {
    /* Sum: '<S95>/Sum' incorporates:
     *  Integrator: '<S86>/Integrator'
     */
    u0 = (TRAS_DevDriv_B.ProportionalGain + TRAS_DevDriv_X.Integrator_CSTATE) +
      TRAS_DevDriv_B.FilterCoefficient;

    /* Saturate: '<S93>/Saturation' */
    if (u0 > TRAS_DevDriv_P.PIDController1_UpperSaturationLimit) {
      /* ManualSwitch: '<Root>/Control Type' */
      TRAS_DevDriv_B.ControlType =
        TRAS_DevDriv_P.PIDController1_UpperSaturationLimit;
    } else if (u0 < TRAS_DevDriv_P.PIDController1_LowerSaturationLimit) {
      /* ManualSwitch: '<Root>/Control Type' */
      TRAS_DevDriv_B.ControlType =
        TRAS_DevDriv_P.PIDController1_LowerSaturationLimit;
    } else {
      /* ManualSwitch: '<Root>/Control Type' */
      TRAS_DevDriv_B.ControlType = u0;
    }

    /* End of Saturate: '<S93>/Saturation' */
  }

  /* End of ManualSwitch: '<Root>/Control Type' */
  if (rtmIsMajorTimeStep(TRAS_DevDriv_M)) {
    /* Sum: '<Root>/Sum' incorporates:
     *  Constant: '<Root>/Constant2'
     *  Gain: '<Root>/Multiply2'
     */
    rtb_Sum = TRAS_DevDriv_P.Multiply2_Gain * TRAS_DevDriv_P.Constant2_Value -
      TRAS_DevDriv_B.Converttorad[1];

    /* Gain: '<S43>/Proportional Gain' */
    TRAS_DevDriv_B.ProportionalGain_l = TRAS_DevDriv_P.PIDController_P * rtb_Sum;

    /* Gain: '<S32>/Derivative Gain' */
    TRAS_DevDriv_B.DerivativeGain_n = TRAS_DevDriv_P.PIDController_D * rtb_Sum;
  }

  /* Gain: '<S41>/Filter Coefficient' incorporates:
   *  Integrator: '<S33>/Filter'
   *  Sum: '<S33>/SumD'
   */
  TRAS_DevDriv_B.FilterCoefficient_b = (TRAS_DevDriv_B.DerivativeGain_n -
    TRAS_DevDriv_X.Filter_CSTATE_h) * TRAS_DevDriv_P.PIDController_N;

  /* Sum: '<S47>/Sum' incorporates:
   *  Integrator: '<S38>/Integrator'
   */
  u0 = (TRAS_DevDriv_B.ProportionalGain_l + TRAS_DevDriv_X.Integrator_CSTATE_e)
    + TRAS_DevDriv_B.FilterCoefficient_b;

  /* Saturate: '<S45>/Saturation' */
  if (u0 > TRAS_DevDriv_P.PIDController_UpperSaturationLimit) {
    u0 = TRAS_DevDriv_P.PIDController_UpperSaturationLimit;
  } else if (u0 < TRAS_DevDriv_P.PIDController_LowerSaturationLimit) {
    u0 = TRAS_DevDriv_P.PIDController_LowerSaturationLimit;
  }

  /* End of Saturate: '<S45>/Saturation' */

  /* Gain: '<Root>/Gain' */
  TRAS_DevDriv_B.Gain_m = TRAS_DevDriv_P.Gain_Gain_a * u0;
  if (rtmIsMajorTimeStep(TRAS_DevDriv_M)) {
    /* Gain: '<S35>/Integral Gain' */
    TRAS_DevDriv_B.IntegralGain = TRAS_DevDriv_P.PIDController_I * rtb_Sum;

    /* Gain: '<S83>/Integral Gain' */
    TRAS_DevDriv_B.IntegralGain_a = TRAS_DevDriv_P.PIDController1_I * rtb_Sum1;

    /* ManualSwitch: '<Root>/Reset Encoders' */
    if (TRAS_DevDriv_P.ResetEncoders_CurrentSetting == 1) {
      /* ManualSwitch: '<Root>/Reset Encoders' incorporates:
       *  Constant: '<Root>/Reset'
       */
      TRAS_DevDriv_B.ResetEncoders = TRAS_DevDriv_P.Reset_Value;
    } else {
      /* ManualSwitch: '<Root>/Reset Encoders' incorporates:
       *  Constant: '<Root>/Normal'
       */
      TRAS_DevDriv_B.ResetEncoders = TRAS_DevDriv_P.Normal_Value;
    }

    /* End of ManualSwitch: '<Root>/Reset Encoders' */
  }

  /* Saturate: '<S6>/Saturation' */
  if (TRAS_DevDriv_B.ControlType > TRAS_DevDriv_P.Saturation_UpperSat) {
    /* Saturate: '<S6>/Saturation' */
    TRAS_DevDriv_B.Saturation[0] = TRAS_DevDriv_P.Saturation_UpperSat;
  } else if (TRAS_DevDriv_B.ControlType < TRAS_DevDriv_P.Saturation_LowerSat) {
    /* Saturate: '<S6>/Saturation' */
    TRAS_DevDriv_B.Saturation[0] = TRAS_DevDriv_P.Saturation_LowerSat;
  } else {
    /* Saturate: '<S6>/Saturation' */
    TRAS_DevDriv_B.Saturation[0] = TRAS_DevDriv_B.ControlType;
  }

  /* ManualSwitch: '<Root>/Control Type2' */
  if (TRAS_DevDriv_P.ControlType2_CurrentSetting == 1) {
    rtb_Sum1 = TRAS_DevDriv_B.Gain_m;
  } else {
    rtb_Sum1 = TRAS_DevDriv_B.Gain1;
  }

  /* End of ManualSwitch: '<Root>/Control Type2' */

  /* Saturate: '<S6>/Saturation' */
  if (rtb_Sum1 > TRAS_DevDriv_P.Saturation_UpperSat) {
    /* Saturate: '<S6>/Saturation' */
    TRAS_DevDriv_B.Saturation[1] = TRAS_DevDriv_P.Saturation_UpperSat;
  } else if (rtb_Sum1 < TRAS_DevDriv_P.Saturation_LowerSat) {
    /* Saturate: '<S6>/Saturation' */
    TRAS_DevDriv_B.Saturation[1] = TRAS_DevDriv_P.Saturation_LowerSat;
  } else {
    /* Saturate: '<S6>/Saturation' */
    TRAS_DevDriv_B.Saturation[1] = rtb_Sum1;
  }

  if (rtmIsMajorTimeStep(TRAS_DevDriv_M)) {
    /* S-Function (TRAS_PWM): '<S6>/PWM' */

    /* Level2 S-Function Block: '<S6>/PWM' (TRAS_PWM) */
    {
      SimStruct *rts = TRAS_DevDriv_M->childSfunctions[2];
      sfcnOutputs(rts,0);
    }

    /* S-Function (TRAS_ResetEncoder): '<S6>/ResetEncoder' */

    /* Level2 S-Function Block: '<S6>/ResetEncoder' (TRAS_ResetEncoder) */
    {
      SimStruct *rts = TRAS_DevDriv_M->childSfunctions[3];
      sfcnOutputs(rts,0);
    }

    /* S-Function (TRAS_BitstreamVersion): '<S6>/Bitstream Version' */

    /* Level2 S-Function Block: '<S6>/Bitstream Version' (TRAS_BitstreamVersion) */
    {
      SimStruct *rts = TRAS_DevDriv_M->childSfunctions[4];
      sfcnOutputs(rts,0);
    }

    /* S-Function (TRAS_PWMTherm): '<S6>/Therm Status' */

    /* Level2 S-Function Block: '<S6>/Therm Status' (TRAS_PWMTherm) */
    {
      SimStruct *rts = TRAS_DevDriv_M->childSfunctions[5];
      sfcnOutputs(rts,0);
    }

    /* Constant: '<S6>/PWMPrescalerSource' */
    TRAS_DevDriv_B.PWMPrescalerSource[0] =
      TRAS_DevDriv_P.PWMPrescalerSource_Value[0];
    TRAS_DevDriv_B.PWMPrescalerSource[1] =
      TRAS_DevDriv_P.PWMPrescalerSource_Value[1];

    /* S-Function (TRAS_PWMPrescaler): '<S6>/PWMPrescaler' */

    /* Level2 S-Function Block: '<S6>/PWMPrescaler' (TRAS_PWMPrescaler) */
    {
      SimStruct *rts = TRAS_DevDriv_M->childSfunctions[6];
      sfcnOutputs(rts,0);
    }

    /* Constant: '<S6>/ThermFlagSource' */
    TRAS_DevDriv_B.ThermFlagSource[0] = TRAS_DevDriv_P.ThermFlagSource_Value[0];
    TRAS_DevDriv_B.ThermFlagSource[1] = TRAS_DevDriv_P.ThermFlagSource_Value[1];

    /* S-Function (TRAS_ThermFlag): '<S6>/ThermFlag ' */

    /* Level2 S-Function Block: '<S6>/ThermFlag ' (TRAS_ThermFlag) */
    {
      SimStruct *rts = TRAS_DevDriv_M->childSfunctions[7];
      sfcnOutputs(rts,0);
    }
  }
}

/* Model update function */
void TRAS_DevDriv_update(void)
{
  if (rtmIsMajorTimeStep(TRAS_DevDriv_M)) {
    rt_ertODEUpdateContinuousStates(&TRAS_DevDriv_M->solverInfo);
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++TRAS_DevDriv_M->Timing.clockTick0)) {
    ++TRAS_DevDriv_M->Timing.clockTickH0;
  }

  TRAS_DevDriv_M->Timing.t[0] = rtsiGetSolverStopTime
    (&TRAS_DevDriv_M->solverInfo);

  {
    /* Update absolute timer for sample time: [0.01s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++TRAS_DevDriv_M->Timing.clockTick1)) {
      ++TRAS_DevDriv_M->Timing.clockTickH1;
    }

    TRAS_DevDriv_M->Timing.t[1] = TRAS_DevDriv_M->Timing.clockTick1 *
      TRAS_DevDriv_M->Timing.stepSize1 + TRAS_DevDriv_M->Timing.clockTickH1 *
      TRAS_DevDriv_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void TRAS_DevDriv_derivatives(void)
{
  XDot_TRAS_DevDriv_T *_rtXdot;
  _rtXdot = ((XDot_TRAS_DevDriv_T *) TRAS_DevDriv_M->derivs);

  /* Derivatives for Integrator: '<S86>/Integrator' */
  _rtXdot->Integrator_CSTATE = TRAS_DevDriv_B.IntegralGain_a;

  /* Derivatives for Integrator: '<S81>/Filter' */
  _rtXdot->Filter_CSTATE = TRAS_DevDriv_B.FilterCoefficient;

  /* Derivatives for Integrator: '<S38>/Integrator' */
  _rtXdot->Integrator_CSTATE_e = TRAS_DevDriv_B.IntegralGain;

  /* Derivatives for Integrator: '<S33>/Filter' */
  _rtXdot->Filter_CSTATE_h = TRAS_DevDriv_B.FilterCoefficient_b;
}

/* Model initialize function */
void TRAS_DevDriv_initialize(void)
{
  /* Start for FromWorkspace: '<S5>/FromWs' */
  {
    static real_T pTimeValues0[] = { 0.0, 0.36, 0.36, 0.6, 0.6,
      1.6500000000000001, 1.6500000000000001, 2.5, 2.5, 3.2, 3.2, 3.85, 3.85,
      6.65, 6.65, 7.0, 7.0, 10.05, 10.05, 10.8, 10.8, 11.200000000000001,
      11.200000000000001, 12.05, 12.05, 12.600000000000001, 12.600000000000001,
      13.75, 13.75, 14.3, 14.3, 17.6, 17.6, 20.0 } ;

    static real_T pDataValues0[] = { 0.0, 0.0, 0.495, 0.495, 0.495, 0.495, -0.0,
      0.0, -1.0, -1.0, -0.24, -0.24, -0.24, -0.24, -0.24, -0.24, 0.32, 0.32,
      0.58, 0.58, 0.58, 0.58, 1.0, 1.0, 0.58, 0.58, 0.58, 0.58, 0.0, 0.0, 0.0,
      0.0, 0.0, -0.0, 0.0, 0.0, 0.0, 0.0, 0.27, 0.27, 0.27, 0.27, 0.27, 0.27,
      0.27, 0.27, -0.18, -0.18, -0.32, -0.32, -0.32, -0.32, -0.32, -0.32, 0.28,
      0.28, 0.28, 0.28, 0.28, 0.28, 0.48, 0.48, 0.48, 0.48, -0.16, -0.16, 0.0,
      0.0 } ;

    TRAS_DevDriv_DW.FromWs_PWORK.TimePtr = (void *) pTimeValues0;
    TRAS_DevDriv_DW.FromWs_PWORK.DataPtr = (void *) pDataValues0;
    TRAS_DevDriv_DW.FromWs_IWORK.PrevIndex = 0;
  }

  /* Start for Constant: '<S6>/PWMPrescalerSource' */
  TRAS_DevDriv_B.PWMPrescalerSource[0] =
    TRAS_DevDriv_P.PWMPrescalerSource_Value[0];
  TRAS_DevDriv_B.PWMPrescalerSource[1] =
    TRAS_DevDriv_P.PWMPrescalerSource_Value[1];

  /* Start for Constant: '<S6>/ThermFlagSource' */
  TRAS_DevDriv_B.ThermFlagSource[0] = TRAS_DevDriv_P.ThermFlagSource_Value[0];
  TRAS_DevDriv_B.ThermFlagSource[1] = TRAS_DevDriv_P.ThermFlagSource_Value[1];

  /* InitializeConditions for Integrator: '<S86>/Integrator' */
  TRAS_DevDriv_X.Integrator_CSTATE =
    TRAS_DevDriv_P.PIDController1_InitialConditionForIntegrator;

  /* InitializeConditions for Integrator: '<S81>/Filter' */
  TRAS_DevDriv_X.Filter_CSTATE =
    TRAS_DevDriv_P.PIDController1_InitialConditionForFilter;

  /* InitializeConditions for Integrator: '<S38>/Integrator' */
  TRAS_DevDriv_X.Integrator_CSTATE_e =
    TRAS_DevDriv_P.PIDController_InitialConditionForIntegrator;

  /* InitializeConditions for Integrator: '<S33>/Filter' */
  TRAS_DevDriv_X.Filter_CSTATE_h =
    TRAS_DevDriv_P.PIDController_InitialConditionForFilter;
}

/* Model terminate function */
void TRAS_DevDriv_terminate(void)
{
  /* Terminate for S-Function (TRAS_Encoder): '<S6>/Encoder' */
  /* Level2 S-Function Block: '<S6>/Encoder' (TRAS_Encoder) */
  {
    SimStruct *rts = TRAS_DevDriv_M->childSfunctions[0];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (TRAS_AnalogInput): '<S6>/Analog Input' */
  /* Level2 S-Function Block: '<S6>/Analog Input' (TRAS_AnalogInput) */
  {
    SimStruct *rts = TRAS_DevDriv_M->childSfunctions[1];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (TRAS_PWM): '<S6>/PWM' */
  /* Level2 S-Function Block: '<S6>/PWM' (TRAS_PWM) */
  {
    SimStruct *rts = TRAS_DevDriv_M->childSfunctions[2];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (TRAS_ResetEncoder): '<S6>/ResetEncoder' */
  /* Level2 S-Function Block: '<S6>/ResetEncoder' (TRAS_ResetEncoder) */
  {
    SimStruct *rts = TRAS_DevDriv_M->childSfunctions[3];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (TRAS_BitstreamVersion): '<S6>/Bitstream Version' */
  /* Level2 S-Function Block: '<S6>/Bitstream Version' (TRAS_BitstreamVersion) */
  {
    SimStruct *rts = TRAS_DevDriv_M->childSfunctions[4];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (TRAS_PWMTherm): '<S6>/Therm Status' */
  /* Level2 S-Function Block: '<S6>/Therm Status' (TRAS_PWMTherm) */
  {
    SimStruct *rts = TRAS_DevDriv_M->childSfunctions[5];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (TRAS_PWMPrescaler): '<S6>/PWMPrescaler' */
  /* Level2 S-Function Block: '<S6>/PWMPrescaler' (TRAS_PWMPrescaler) */
  {
    SimStruct *rts = TRAS_DevDriv_M->childSfunctions[6];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (TRAS_ThermFlag): '<S6>/ThermFlag ' */
  /* Level2 S-Function Block: '<S6>/ThermFlag ' (TRAS_ThermFlag) */
  {
    SimStruct *rts = TRAS_DevDriv_M->childSfunctions[7];
    sfcnTerminate(rts);
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/

/* Solver interface called by GRT_Main */
#ifndef USE_GENERATED_SOLVER

void rt_ODECreateIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEDestroyIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEUpdateContinuousStates(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

#endif

void MdlOutputs(int_T tid)
{
  TRAS_DevDriv_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  TRAS_DevDriv_update();
  UNUSED_PARAMETER(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  TRAS_DevDriv_initialize();
}

void MdlTerminate(void)
{
  TRAS_DevDriv_terminate();
}

/* Registration function */
RT_MODEL_TRAS_DevDriv_T *TRAS_DevDriv(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)TRAS_DevDriv_M, 0,
                sizeof(RT_MODEL_TRAS_DevDriv_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&TRAS_DevDriv_M->solverInfo,
                          &TRAS_DevDriv_M->Timing.simTimeStep);
    rtsiSetTPtr(&TRAS_DevDriv_M->solverInfo, &rtmGetTPtr(TRAS_DevDriv_M));
    rtsiSetStepSizePtr(&TRAS_DevDriv_M->solverInfo,
                       &TRAS_DevDriv_M->Timing.stepSize0);
    rtsiSetdXPtr(&TRAS_DevDriv_M->solverInfo, &TRAS_DevDriv_M->derivs);
    rtsiSetContStatesPtr(&TRAS_DevDriv_M->solverInfo, (real_T **)
                         &TRAS_DevDriv_M->contStates);
    rtsiSetNumContStatesPtr(&TRAS_DevDriv_M->solverInfo,
      &TRAS_DevDriv_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&TRAS_DevDriv_M->solverInfo,
      &TRAS_DevDriv_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&TRAS_DevDriv_M->solverInfo,
      &TRAS_DevDriv_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&TRAS_DevDriv_M->solverInfo,
      &TRAS_DevDriv_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&TRAS_DevDriv_M->solverInfo, (&rtmGetErrorStatus
      (TRAS_DevDriv_M)));
    rtsiSetRTModelPtr(&TRAS_DevDriv_M->solverInfo, TRAS_DevDriv_M);
  }

  rtsiSetSimTimeStep(&TRAS_DevDriv_M->solverInfo, MAJOR_TIME_STEP);
  TRAS_DevDriv_M->intgData.y = TRAS_DevDriv_M->odeY;
  TRAS_DevDriv_M->intgData.f[0] = TRAS_DevDriv_M->odeF[0];
  TRAS_DevDriv_M->intgData.f[1] = TRAS_DevDriv_M->odeF[1];
  TRAS_DevDriv_M->intgData.f[2] = TRAS_DevDriv_M->odeF[2];
  TRAS_DevDriv_M->intgData.f[3] = TRAS_DevDriv_M->odeF[3];
  TRAS_DevDriv_M->intgData.f[4] = TRAS_DevDriv_M->odeF[4];
  TRAS_DevDriv_M->intgData.f[5] = TRAS_DevDriv_M->odeF[5];
  TRAS_DevDriv_M->contStates = ((real_T *) &TRAS_DevDriv_X);
  rtsiSetSolverData(&TRAS_DevDriv_M->solverInfo, (void *)
                    &TRAS_DevDriv_M->intgData);
  rtsiSetSolverName(&TRAS_DevDriv_M->solverInfo,"ode5");
  TRAS_DevDriv_M->solverInfoPtr = (&TRAS_DevDriv_M->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap = TRAS_DevDriv_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;

    /* polyspace +2 MISRA2012:D4.1 [Justified:Low] "TRAS_DevDriv_M points to
       static memory which is guaranteed to be non-NULL" */
    TRAS_DevDriv_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    TRAS_DevDriv_M->Timing.sampleTimes =
      (&TRAS_DevDriv_M->Timing.sampleTimesArray[0]);
    TRAS_DevDriv_M->Timing.offsetTimes =
      (&TRAS_DevDriv_M->Timing.offsetTimesArray[0]);

    /* task periods */
    TRAS_DevDriv_M->Timing.sampleTimes[0] = (0.0);
    TRAS_DevDriv_M->Timing.sampleTimes[1] = (0.01);

    /* task offsets */
    TRAS_DevDriv_M->Timing.offsetTimes[0] = (0.0);
    TRAS_DevDriv_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(TRAS_DevDriv_M, &TRAS_DevDriv_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = TRAS_DevDriv_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    TRAS_DevDriv_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(TRAS_DevDriv_M, -1);
  TRAS_DevDriv_M->Timing.stepSize0 = 0.01;
  TRAS_DevDriv_M->Timing.stepSize1 = 0.01;

  /* External mode info */
  TRAS_DevDriv_M->Sizes.checksums[0] = (1633322045U);
  TRAS_DevDriv_M->Sizes.checksums[1] = (1852816840U);
  TRAS_DevDriv_M->Sizes.checksums[2] = (1905297470U);
  TRAS_DevDriv_M->Sizes.checksums[3] = (3483336113U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[3];
    TRAS_DevDriv_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(TRAS_DevDriv_M->extModeInfo,
      &TRAS_DevDriv_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(TRAS_DevDriv_M->extModeInfo,
                        TRAS_DevDriv_M->Sizes.checksums);
    rteiSetTPtr(TRAS_DevDriv_M->extModeInfo, rtmGetTPtr(TRAS_DevDriv_M));
  }

  TRAS_DevDriv_M->solverInfoPtr = (&TRAS_DevDriv_M->solverInfo);
  TRAS_DevDriv_M->Timing.stepSize = (0.01);
  rtsiSetFixedStepSize(&TRAS_DevDriv_M->solverInfo, 0.01);
  rtsiSetSolverMode(&TRAS_DevDriv_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  TRAS_DevDriv_M->blockIO = ((void *) &TRAS_DevDriv_B);

  {
    TRAS_DevDriv_B.Encoder[0] = 0.0;
    TRAS_DevDriv_B.Encoder[1] = 0.0;
    TRAS_DevDriv_B.Converttorad[0] = 0.0;
    TRAS_DevDriv_B.Converttorad[1] = 0.0;
    TRAS_DevDriv_B.Gain = 0.0;
    TRAS_DevDriv_B.AnalogInput[0] = 0.0;
    TRAS_DevDriv_B.AnalogInput[1] = 0.0;
    TRAS_DevDriv_B.ConverttoRPM[0] = 0.0;
    TRAS_DevDriv_B.ConverttoRPM[1] = 0.0;
    TRAS_DevDriv_B.FromWs[0] = 0.0;
    TRAS_DevDriv_B.FromWs[1] = 0.0;
    TRAS_DevDriv_B.Gain1 = 0.0;
    TRAS_DevDriv_B.Gain_p = 0.0;
    TRAS_DevDriv_B.Multiply1 = 0.0;
    TRAS_DevDriv_B.ProportionalGain = 0.0;
    TRAS_DevDriv_B.DerivativeGain = 0.0;
    TRAS_DevDriv_B.FilterCoefficient = 0.0;
    TRAS_DevDriv_B.ControlType = 0.0;
    TRAS_DevDriv_B.ProportionalGain_l = 0.0;
    TRAS_DevDriv_B.DerivativeGain_n = 0.0;
    TRAS_DevDriv_B.FilterCoefficient_b = 0.0;
    TRAS_DevDriv_B.Gain_m = 0.0;
    TRAS_DevDriv_B.IntegralGain = 0.0;
    TRAS_DevDriv_B.IntegralGain_a = 0.0;
    TRAS_DevDriv_B.ResetEncoders = 0.0;
    TRAS_DevDriv_B.Saturation[0] = 0.0;
    TRAS_DevDriv_B.Saturation[1] = 0.0;
    TRAS_DevDriv_B.PWM[0] = 0.0;
    TRAS_DevDriv_B.PWM[1] = 0.0;
    TRAS_DevDriv_B.ResetEncoder[0] = 0.0;
    TRAS_DevDriv_B.ResetEncoder[1] = 0.0;
    TRAS_DevDriv_B.BitstreamVersion = 0.0;
    TRAS_DevDriv_B.ThermStatus[0] = 0.0;
    TRAS_DevDriv_B.ThermStatus[1] = 0.0;
    TRAS_DevDriv_B.PWMPrescalerSource[0] = 0.0;
    TRAS_DevDriv_B.PWMPrescalerSource[1] = 0.0;
    TRAS_DevDriv_B.PWMPrescaler[0] = 0.0;
    TRAS_DevDriv_B.PWMPrescaler[1] = 0.0;
    TRAS_DevDriv_B.ThermFlagSource[0] = 0.0;
    TRAS_DevDriv_B.ThermFlagSource[1] = 0.0;
    TRAS_DevDriv_B.ThermFlag[0] = 0.0;
    TRAS_DevDriv_B.ThermFlag[1] = 0.0;
  }

  /* parameters */
  TRAS_DevDriv_M->defaultParam = ((real_T *)&TRAS_DevDriv_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &TRAS_DevDriv_X;
    TRAS_DevDriv_M->contStates = (x);
    (void) memset((void *)&TRAS_DevDriv_X, 0,
                  sizeof(X_TRAS_DevDriv_T));
  }

  /* states (dwork) */
  TRAS_DevDriv_M->dwork = ((void *) &TRAS_DevDriv_DW);
  (void) memset((void *)&TRAS_DevDriv_DW, 0,
                sizeof(DW_TRAS_DevDriv_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    TRAS_DevDriv_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 18;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* child S-Function registration */
  {
    RTWSfcnInfo *sfcnInfo = &TRAS_DevDriv_M->NonInlinedSFcns.sfcnInfo;
    TRAS_DevDriv_M->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus(TRAS_DevDriv_M)));
    TRAS_DevDriv_M->Sizes.numSampTimes = (2);
    rtssSetNumRootSampTimesPtr(sfcnInfo, &TRAS_DevDriv_M->Sizes.numSampTimes);
    TRAS_DevDriv_M->NonInlinedSFcns.taskTimePtrs[0] = &(rtmGetTPtr
      (TRAS_DevDriv_M)[0]);
    TRAS_DevDriv_M->NonInlinedSFcns.taskTimePtrs[1] = &(rtmGetTPtr
      (TRAS_DevDriv_M)[1]);
    rtssSetTPtrPtr(sfcnInfo,TRAS_DevDriv_M->NonInlinedSFcns.taskTimePtrs);
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(TRAS_DevDriv_M));
    rtssSetTFinalPtr(sfcnInfo, &rtmGetTFinal(TRAS_DevDriv_M));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput(TRAS_DevDriv_M));
    rtssSetStepSizePtr(sfcnInfo, &TRAS_DevDriv_M->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested(TRAS_DevDriv_M));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo,
      &TRAS_DevDriv_M->derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo, &TRAS_DevDriv_M->zCCacheNeedsReset);
    rtssSetContTimeOutputInconsistentWithStateAtMajorStepPtr(sfcnInfo,
      &TRAS_DevDriv_M->CTOutputIncnstWithState);
    rtssSetSampleHitsPtr(sfcnInfo, &TRAS_DevDriv_M->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo,
      &TRAS_DevDriv_M->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &TRAS_DevDriv_M->simMode);
    rtssSetSolverInfoPtr(sfcnInfo, &TRAS_DevDriv_M->solverInfoPtr);
  }

  TRAS_DevDriv_M->Sizes.numSFcns = (8);

  /* register each child */
  {
    (void) memset((void *)&TRAS_DevDriv_M->NonInlinedSFcns.childSFunctions[0], 0,
                  8*sizeof(SimStruct));
    TRAS_DevDriv_M->childSfunctions =
      (&TRAS_DevDriv_M->NonInlinedSFcns.childSFunctionPtrs[0]);

    {
      int_T i;
      for (i = 0; i < 8; i++) {
        TRAS_DevDriv_M->childSfunctions[i] =
          (&TRAS_DevDriv_M->NonInlinedSFcns.childSFunctions[i]);
      }
    }

    /* Level2 S-Function Block: TRAS_DevDriv/<S6>/Encoder (TRAS_Encoder) */
    {
      SimStruct *rts = TRAS_DevDriv_M->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod = TRAS_DevDriv_M->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset = TRAS_DevDriv_M->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap = TRAS_DevDriv_M->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &TRAS_DevDriv_M->NonInlinedSFcns.blkInfo2[0]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &TRAS_DevDriv_M->NonInlinedSFcns.inputOutputPortInfo2[0]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, TRAS_DevDriv_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &TRAS_DevDriv_M->NonInlinedSFcns.methods2[0]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &TRAS_DevDriv_M->NonInlinedSFcns.methods3[0]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &TRAS_DevDriv_M->NonInlinedSFcns.methods4[0]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &TRAS_DevDriv_M->NonInlinedSFcns.statesInfo2[0]);
        ssSetPeriodicStatesInfo(rts,
          &TRAS_DevDriv_M->NonInlinedSFcns.periodicStatesInfo[0]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &TRAS_DevDriv_M->NonInlinedSFcns.Sfcn0.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &TRAS_DevDriv_M->NonInlinedSFcns.Sfcn0.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &TRAS_DevDriv_M->NonInlinedSFcns.Sfcn0.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 2);
          ssSetOutputPortSignal(rts, 0, ((real_T *) TRAS_DevDriv_B.Encoder));
        }
      }

      /* path info */
      ssSetModelName(rts, "Encoder");
      ssSetPath(rts, "TRAS_DevDriv/TRAS/Encoder");
      ssSetRTModel(rts,TRAS_DevDriv_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &TRAS_DevDriv_M->NonInlinedSFcns.Sfcn0.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)TRAS_DevDriv_P.Encoder_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)TRAS_DevDriv_P.Encoder_P2_Size);
      }

      /* registration */
      TRAS_Encoder(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: TRAS_DevDriv/<S6>/Analog Input (TRAS_AnalogInput) */
    {
      SimStruct *rts = TRAS_DevDriv_M->childSfunctions[1];

      /* timing info */
      time_T *sfcnPeriod = TRAS_DevDriv_M->NonInlinedSFcns.Sfcn1.sfcnPeriod;
      time_T *sfcnOffset = TRAS_DevDriv_M->NonInlinedSFcns.Sfcn1.sfcnOffset;
      int_T *sfcnTsMap = TRAS_DevDriv_M->NonInlinedSFcns.Sfcn1.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &TRAS_DevDriv_M->NonInlinedSFcns.blkInfo2[1]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &TRAS_DevDriv_M->NonInlinedSFcns.inputOutputPortInfo2[1]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, TRAS_DevDriv_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &TRAS_DevDriv_M->NonInlinedSFcns.methods2[1]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &TRAS_DevDriv_M->NonInlinedSFcns.methods3[1]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &TRAS_DevDriv_M->NonInlinedSFcns.methods4[1]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &TRAS_DevDriv_M->NonInlinedSFcns.statesInfo2[1]);
        ssSetPeriodicStatesInfo(rts,
          &TRAS_DevDriv_M->NonInlinedSFcns.periodicStatesInfo[1]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &TRAS_DevDriv_M->NonInlinedSFcns.Sfcn1.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &TRAS_DevDriv_M->NonInlinedSFcns.Sfcn1.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &TRAS_DevDriv_M->NonInlinedSFcns.Sfcn1.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 2);
          ssSetOutputPortSignal(rts, 0, ((real_T *) TRAS_DevDriv_B.AnalogInput));
        }
      }

      /* path info */
      ssSetModelName(rts, "Analog Input");
      ssSetPath(rts, "TRAS_DevDriv/TRAS/Analog Input");
      ssSetRTModel(rts,TRAS_DevDriv_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &TRAS_DevDriv_M->NonInlinedSFcns.Sfcn1.params;
        ssSetSFcnParamsCount(rts, 4);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)TRAS_DevDriv_P.AnalogInput_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)TRAS_DevDriv_P.AnalogInput_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)TRAS_DevDriv_P.AnalogInput_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)TRAS_DevDriv_P.AnalogInput_P4_Size);
      }

      /* registration */
      TRAS_AnalogInput(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: TRAS_DevDriv/<S6>/PWM (TRAS_PWM) */
    {
      SimStruct *rts = TRAS_DevDriv_M->childSfunctions[2];

      /* timing info */
      time_T *sfcnPeriod = TRAS_DevDriv_M->NonInlinedSFcns.Sfcn2.sfcnPeriod;
      time_T *sfcnOffset = TRAS_DevDriv_M->NonInlinedSFcns.Sfcn2.sfcnOffset;
      int_T *sfcnTsMap = TRAS_DevDriv_M->NonInlinedSFcns.Sfcn2.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &TRAS_DevDriv_M->NonInlinedSFcns.blkInfo2[2]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &TRAS_DevDriv_M->NonInlinedSFcns.inputOutputPortInfo2[2]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, TRAS_DevDriv_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &TRAS_DevDriv_M->NonInlinedSFcns.methods2[2]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &TRAS_DevDriv_M->NonInlinedSFcns.methods3[2]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &TRAS_DevDriv_M->NonInlinedSFcns.methods4[2]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &TRAS_DevDriv_M->NonInlinedSFcns.statesInfo2[2]);
        ssSetPeriodicStatesInfo(rts,
          &TRAS_DevDriv_M->NonInlinedSFcns.periodicStatesInfo[2]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &TRAS_DevDriv_M->NonInlinedSFcns.Sfcn2.inputPortInfo[0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &TRAS_DevDriv_M->NonInlinedSFcns.Sfcn2.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &TRAS_DevDriv_M->NonInlinedSFcns.Sfcn2.inputPortCoSimAttribute[0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &TRAS_DevDriv_M->NonInlinedSFcns.Sfcn2.UPtrs0;
          sfcnUPtrs[0] = TRAS_DevDriv_B.Saturation;
          sfcnUPtrs[1] = &TRAS_DevDriv_B.Saturation[1];
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 2);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &TRAS_DevDriv_M->NonInlinedSFcns.Sfcn2.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &TRAS_DevDriv_M->NonInlinedSFcns.Sfcn2.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &TRAS_DevDriv_M->NonInlinedSFcns.Sfcn2.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 2);
          ssSetOutputPortSignal(rts, 0, ((real_T *) TRAS_DevDriv_B.PWM));
        }
      }

      /* path info */
      ssSetModelName(rts, "PWM");
      ssSetPath(rts, "TRAS_DevDriv/TRAS/PWM");
      ssSetRTModel(rts,TRAS_DevDriv_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &TRAS_DevDriv_M->NonInlinedSFcns.Sfcn2.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)TRAS_DevDriv_P.PWM_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)TRAS_DevDriv_P.PWM_P2_Size);
      }

      /* registration */
      TRAS_PWM(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: TRAS_DevDriv/<S6>/ResetEncoder (TRAS_ResetEncoder) */
    {
      SimStruct *rts = TRAS_DevDriv_M->childSfunctions[3];

      /* timing info */
      time_T *sfcnPeriod = TRAS_DevDriv_M->NonInlinedSFcns.Sfcn3.sfcnPeriod;
      time_T *sfcnOffset = TRAS_DevDriv_M->NonInlinedSFcns.Sfcn3.sfcnOffset;
      int_T *sfcnTsMap = TRAS_DevDriv_M->NonInlinedSFcns.Sfcn3.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &TRAS_DevDriv_M->NonInlinedSFcns.blkInfo2[3]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &TRAS_DevDriv_M->NonInlinedSFcns.inputOutputPortInfo2[3]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, TRAS_DevDriv_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &TRAS_DevDriv_M->NonInlinedSFcns.methods2[3]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &TRAS_DevDriv_M->NonInlinedSFcns.methods3[3]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &TRAS_DevDriv_M->NonInlinedSFcns.methods4[3]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &TRAS_DevDriv_M->NonInlinedSFcns.statesInfo2[3]);
        ssSetPeriodicStatesInfo(rts,
          &TRAS_DevDriv_M->NonInlinedSFcns.periodicStatesInfo[3]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &TRAS_DevDriv_M->NonInlinedSFcns.Sfcn3.inputPortInfo[0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &TRAS_DevDriv_M->NonInlinedSFcns.Sfcn3.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &TRAS_DevDriv_M->NonInlinedSFcns.Sfcn3.inputPortCoSimAttribute[0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &TRAS_DevDriv_M->NonInlinedSFcns.Sfcn3.UPtrs0;
          sfcnUPtrs[0] = &TRAS_DevDriv_B.ResetEncoders;
          sfcnUPtrs[1] = &TRAS_DevDriv_B.ResetEncoders;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 2);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &TRAS_DevDriv_M->NonInlinedSFcns.Sfcn3.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &TRAS_DevDriv_M->NonInlinedSFcns.Sfcn3.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &TRAS_DevDriv_M->NonInlinedSFcns.Sfcn3.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 2);
          ssSetOutputPortSignal(rts, 0, ((real_T *) TRAS_DevDriv_B.ResetEncoder));
        }
      }

      /* path info */
      ssSetModelName(rts, "ResetEncoder");
      ssSetPath(rts, "TRAS_DevDriv/TRAS/ResetEncoder");
      ssSetRTModel(rts,TRAS_DevDriv_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &TRAS_DevDriv_M->NonInlinedSFcns.Sfcn3.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)TRAS_DevDriv_P.ResetEncoder_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)TRAS_DevDriv_P.ResetEncoder_P2_Size);
      }

      /* registration */
      TRAS_ResetEncoder(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: TRAS_DevDriv/<S6>/Bitstream Version (TRAS_BitstreamVersion) */
    {
      SimStruct *rts = TRAS_DevDriv_M->childSfunctions[4];

      /* timing info */
      time_T *sfcnPeriod = TRAS_DevDriv_M->NonInlinedSFcns.Sfcn4.sfcnPeriod;
      time_T *sfcnOffset = TRAS_DevDriv_M->NonInlinedSFcns.Sfcn4.sfcnOffset;
      int_T *sfcnTsMap = TRAS_DevDriv_M->NonInlinedSFcns.Sfcn4.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &TRAS_DevDriv_M->NonInlinedSFcns.blkInfo2[4]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &TRAS_DevDriv_M->NonInlinedSFcns.inputOutputPortInfo2[4]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, TRAS_DevDriv_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &TRAS_DevDriv_M->NonInlinedSFcns.methods2[4]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &TRAS_DevDriv_M->NonInlinedSFcns.methods3[4]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &TRAS_DevDriv_M->NonInlinedSFcns.methods4[4]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &TRAS_DevDriv_M->NonInlinedSFcns.statesInfo2[4]);
        ssSetPeriodicStatesInfo(rts,
          &TRAS_DevDriv_M->NonInlinedSFcns.periodicStatesInfo[4]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &TRAS_DevDriv_M->NonInlinedSFcns.Sfcn4.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &TRAS_DevDriv_M->NonInlinedSFcns.Sfcn4.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &TRAS_DevDriv_M->NonInlinedSFcns.Sfcn4.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &TRAS_DevDriv_B.BitstreamVersion));
        }
      }

      /* path info */
      ssSetModelName(rts, "Bitstream Version");
      ssSetPath(rts, "TRAS_DevDriv/TRAS/Bitstream Version");
      ssSetRTModel(rts,TRAS_DevDriv_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &TRAS_DevDriv_M->NonInlinedSFcns.Sfcn4.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)TRAS_DevDriv_P.BitstreamVersion_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)TRAS_DevDriv_P.BitstreamVersion_P2_Size);
      }

      /* registration */
      TRAS_BitstreamVersion(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: TRAS_DevDriv/<S6>/Therm Status (TRAS_PWMTherm) */
    {
      SimStruct *rts = TRAS_DevDriv_M->childSfunctions[5];

      /* timing info */
      time_T *sfcnPeriod = TRAS_DevDriv_M->NonInlinedSFcns.Sfcn5.sfcnPeriod;
      time_T *sfcnOffset = TRAS_DevDriv_M->NonInlinedSFcns.Sfcn5.sfcnOffset;
      int_T *sfcnTsMap = TRAS_DevDriv_M->NonInlinedSFcns.Sfcn5.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &TRAS_DevDriv_M->NonInlinedSFcns.blkInfo2[5]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &TRAS_DevDriv_M->NonInlinedSFcns.inputOutputPortInfo2[5]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, TRAS_DevDriv_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &TRAS_DevDriv_M->NonInlinedSFcns.methods2[5]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &TRAS_DevDriv_M->NonInlinedSFcns.methods3[5]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &TRAS_DevDriv_M->NonInlinedSFcns.methods4[5]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &TRAS_DevDriv_M->NonInlinedSFcns.statesInfo2[5]);
        ssSetPeriodicStatesInfo(rts,
          &TRAS_DevDriv_M->NonInlinedSFcns.periodicStatesInfo[5]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &TRAS_DevDriv_M->NonInlinedSFcns.Sfcn5.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &TRAS_DevDriv_M->NonInlinedSFcns.Sfcn5.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &TRAS_DevDriv_M->NonInlinedSFcns.Sfcn5.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 2);
          ssSetOutputPortSignal(rts, 0, ((real_T *) TRAS_DevDriv_B.ThermStatus));
        }
      }

      /* path info */
      ssSetModelName(rts, "Therm Status");
      ssSetPath(rts, "TRAS_DevDriv/TRAS/Therm Status");
      ssSetRTModel(rts,TRAS_DevDriv_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &TRAS_DevDriv_M->NonInlinedSFcns.Sfcn5.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)TRAS_DevDriv_P.ThermStatus_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)TRAS_DevDriv_P.ThermStatus_P2_Size);
      }

      /* registration */
      TRAS_PWMTherm(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: TRAS_DevDriv/<S6>/PWMPrescaler (TRAS_PWMPrescaler) */
    {
      SimStruct *rts = TRAS_DevDriv_M->childSfunctions[6];

      /* timing info */
      time_T *sfcnPeriod = TRAS_DevDriv_M->NonInlinedSFcns.Sfcn6.sfcnPeriod;
      time_T *sfcnOffset = TRAS_DevDriv_M->NonInlinedSFcns.Sfcn6.sfcnOffset;
      int_T *sfcnTsMap = TRAS_DevDriv_M->NonInlinedSFcns.Sfcn6.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &TRAS_DevDriv_M->NonInlinedSFcns.blkInfo2[6]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &TRAS_DevDriv_M->NonInlinedSFcns.inputOutputPortInfo2[6]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, TRAS_DevDriv_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &TRAS_DevDriv_M->NonInlinedSFcns.methods2[6]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &TRAS_DevDriv_M->NonInlinedSFcns.methods3[6]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &TRAS_DevDriv_M->NonInlinedSFcns.methods4[6]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &TRAS_DevDriv_M->NonInlinedSFcns.statesInfo2[6]);
        ssSetPeriodicStatesInfo(rts,
          &TRAS_DevDriv_M->NonInlinedSFcns.periodicStatesInfo[6]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &TRAS_DevDriv_M->NonInlinedSFcns.Sfcn6.inputPortInfo[0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &TRAS_DevDriv_M->NonInlinedSFcns.Sfcn6.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &TRAS_DevDriv_M->NonInlinedSFcns.Sfcn6.inputPortCoSimAttribute[0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &TRAS_DevDriv_M->NonInlinedSFcns.Sfcn6.UPtrs0;
          sfcnUPtrs[0] = TRAS_DevDriv_B.PWMPrescalerSource;
          sfcnUPtrs[1] = &TRAS_DevDriv_B.PWMPrescalerSource[1];
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 2);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &TRAS_DevDriv_M->NonInlinedSFcns.Sfcn6.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &TRAS_DevDriv_M->NonInlinedSFcns.Sfcn6.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &TRAS_DevDriv_M->NonInlinedSFcns.Sfcn6.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 2);
          ssSetOutputPortSignal(rts, 0, ((real_T *) TRAS_DevDriv_B.PWMPrescaler));
        }
      }

      /* path info */
      ssSetModelName(rts, "PWMPrescaler");
      ssSetPath(rts, "TRAS_DevDriv/TRAS/PWMPrescaler");
      ssSetRTModel(rts,TRAS_DevDriv_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &TRAS_DevDriv_M->NonInlinedSFcns.Sfcn6.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)TRAS_DevDriv_P.PWMPrescaler_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)TRAS_DevDriv_P.PWMPrescaler_P2_Size);
      }

      /* registration */
      TRAS_PWMPrescaler(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: TRAS_DevDriv/<S6>/ThermFlag  (TRAS_ThermFlag) */
    {
      SimStruct *rts = TRAS_DevDriv_M->childSfunctions[7];

      /* timing info */
      time_T *sfcnPeriod = TRAS_DevDriv_M->NonInlinedSFcns.Sfcn7.sfcnPeriod;
      time_T *sfcnOffset = TRAS_DevDriv_M->NonInlinedSFcns.Sfcn7.sfcnOffset;
      int_T *sfcnTsMap = TRAS_DevDriv_M->NonInlinedSFcns.Sfcn7.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &TRAS_DevDriv_M->NonInlinedSFcns.blkInfo2[7]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &TRAS_DevDriv_M->NonInlinedSFcns.inputOutputPortInfo2[7]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, TRAS_DevDriv_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &TRAS_DevDriv_M->NonInlinedSFcns.methods2[7]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &TRAS_DevDriv_M->NonInlinedSFcns.methods3[7]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &TRAS_DevDriv_M->NonInlinedSFcns.methods4[7]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &TRAS_DevDriv_M->NonInlinedSFcns.statesInfo2[7]);
        ssSetPeriodicStatesInfo(rts,
          &TRAS_DevDriv_M->NonInlinedSFcns.periodicStatesInfo[7]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &TRAS_DevDriv_M->NonInlinedSFcns.Sfcn7.inputPortInfo[0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &TRAS_DevDriv_M->NonInlinedSFcns.Sfcn7.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &TRAS_DevDriv_M->NonInlinedSFcns.Sfcn7.inputPortCoSimAttribute[0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &TRAS_DevDriv_M->NonInlinedSFcns.Sfcn7.UPtrs0;
          sfcnUPtrs[0] = TRAS_DevDriv_B.ThermFlagSource;
          sfcnUPtrs[1] = &TRAS_DevDriv_B.ThermFlagSource[1];
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 2);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &TRAS_DevDriv_M->NonInlinedSFcns.Sfcn7.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &TRAS_DevDriv_M->NonInlinedSFcns.Sfcn7.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &TRAS_DevDriv_M->NonInlinedSFcns.Sfcn7.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 2);
          ssSetOutputPortSignal(rts, 0, ((real_T *) TRAS_DevDriv_B.ThermFlag));
        }
      }

      /* path info */
      ssSetModelName(rts, "ThermFlag ");
      ssSetPath(rts, "TRAS_DevDriv/TRAS/ThermFlag ");
      ssSetRTModel(rts,TRAS_DevDriv_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &TRAS_DevDriv_M->NonInlinedSFcns.Sfcn7.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)TRAS_DevDriv_P.ThermFlag_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)TRAS_DevDriv_P.ThermFlag_P2_Size);
      }

      /* registration */
      TRAS_ThermFlag(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.01);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }
  }

  /* Initialize Sizes */
  TRAS_DevDriv_M->Sizes.numContStates = (4);/* Number of continuous states */
  TRAS_DevDriv_M->Sizes.numPeriodicContStates = (0);
                                      /* Number of periodic continuous states */
  TRAS_DevDriv_M->Sizes.numY = (0);    /* Number of model outputs */
  TRAS_DevDriv_M->Sizes.numU = (0);    /* Number of model inputs */
  TRAS_DevDriv_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  TRAS_DevDriv_M->Sizes.numSampTimes = (2);/* Number of sample times */
  TRAS_DevDriv_M->Sizes.numBlocks = (58);/* Number of blocks */
  TRAS_DevDriv_M->Sizes.numBlockIO = (29);/* Number of block outputs */
  TRAS_DevDriv_M->Sizes.numBlockPrms = (96);/* Sum of parameter "widths" */
  return TRAS_DevDriv_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
