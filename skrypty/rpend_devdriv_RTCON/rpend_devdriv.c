/*
 * rpend_devdriv.c
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
#include "rpend_devdriv_dt.h"

/* Block signals (default storage) */
B_rpend_devdriv_T rpend_devdriv_B;

/* Block states (default storage) */
DW_rpend_devdriv_T rpend_devdriv_DW;

/* Real-time model */
RT_MODEL_rpend_devdriv_T rpend_devdriv_M_;
RT_MODEL_rpend_devdriv_T *const rpend_devdriv_M = &rpend_devdriv_M_;
uint32_T MWDSP_EPH_R_D(real_T evt, uint32_T *sta)
{
  uint32_T retVal;
  int32_T curState;
  int32_T newState;
  int32_T newStateR;
  int32_T lastzcevent;
  uint32_T previousState;

  /* S-Function (sdspstatfcns): '<Root>/Mean' */
  /* Detect rising edge events */
  previousState = *sta;
  retVal = 0U;
  lastzcevent = 0;
  newState = 5;
  newStateR = 5;
  if (evt > 0.0) {
    curState = 2;
  } else {
    curState = !(evt < 0.0);
  }

  if (*sta == 5U) {
    newStateR = curState;
  } else {
    if ((uint32_T)curState != *sta) {
      if (*sta == 3U) {
        if ((uint32_T)curState == 1U) {
          newStateR = 1;
        } else {
          lastzcevent = 2;
          previousState = 1U;
        }
      }

      if (previousState == 4U) {
        if ((uint32_T)curState == 1U) {
          newStateR = 1;
        } else {
          lastzcevent = 3;
          previousState = 1U;
        }
      }

      if ((previousState == 1U) && ((uint32_T)curState == 2U)) {
        retVal = 2U;
      }

      if (previousState == 0U) {
        retVal = 2U;
      }

      if (retVal == (uint32_T)lastzcevent) {
        retVal = 0U;
      }

      if (((uint32_T)curState == 1U) && (retVal == 2U)) {
        newState = 3;
      } else {
        newState = curState;
      }
    }
  }

  if ((uint32_T)newStateR != 5U) {
    *sta = (uint32_T)newStateR;
    retVal = 0U;
  }

  if ((uint32_T)newState != 5U) {
    *sta = (uint32_T)newState;
  }

  /* End of S-Function (sdspstatfcns): '<Root>/Mean' */
  return retVal;
}

real_T rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  int32_T u0_0;
  int32_T u1_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    if (u0 > 0.0) {
      u0_0 = 1;
    } else {
      u0_0 = -1;
    }

    if (u1 > 0.0) {
      u1_0 = 1;
    } else {
      u1_0 = -1;
    }

    y = atan2(u0_0, u1_0);
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }

  return y;
}

/* Model step function */
void rpend_devdriv_step(void)
{
  {
    real_T *lastU;
    real_T rtb_ResetEncoders;
    real_T tmp;

    /* S-Function (rtdacusb2_rpend_dd): '<S1>/S-Function' */

    /* Level2 S-Function Block: '<S1>/S-Function' (rtdacusb2_rpend_dd) */
    {
      SimStruct *rts = rpend_devdriv_M->childSfunctions[0];
      sfcnOutputs(rts,1);
    }

    /* Gain: '<S1>/DC Convert to rad' */
    rpend_devdriv_B.DCAnglerad = rpend_devdriv_P.DCConverttorad_Gain *
      rpend_devdriv_B.SFunction_o3;

    /* Gain: '<S1>/Gain1' incorporates:
     *  Memory: '<S1>/Memory'
     *  Sum: '<S1>/Add'
     */
    rpend_devdriv_B.Periodms = (rpend_devdriv_B.SFunction_o6 -
      rpend_devdriv_DW.Memory_PreviousInput) * rpend_devdriv_P.Gain1_Gain;

    /* Product: '<S1>/Divide' incorporates:
     *  Gain: '<S1>/rad2RPM'
     *  Memory: '<S1>/Memory1'
     *  Sum: '<S1>/Add1'
     */
    rpend_devdriv_B.DCVelrads = (rpend_devdriv_B.DCAnglerad -
      rpend_devdriv_DW.Memory1_PreviousInput) * rpend_devdriv_P.rad2RPM_Gain /
      rpend_devdriv_B.Periodms;

    /* ManualSwitch: '<Root>/Reset Encoders2' incorporates:
     *  Constant: '<Root>/Reset1'
     *  Constant: '<Root>/Reset2'
     */
    if (rpend_devdriv_P.ResetEncoders2_CurrentSetting == 1) {
      rpend_devdriv_B.ResetEncoders2 = rpend_devdriv_P.Reset1_Value;
    } else {
      rpend_devdriv_B.ResetEncoders2 = rpend_devdriv_P.Reset2_Value;
    }

    /* End of ManualSwitch: '<Root>/Reset Encoders2' */

    /* S-Function (sdspstatfcns): '<Root>/Mean' */
    if (MWDSP_EPH_R_D(rpend_devdriv_B.ResetEncoders2,
                      &rpend_devdriv_DW.Mean_EPHPState) != 0U) {
      rpend_devdriv_DW.Mean_Iteration = 0U;
    }

    rpend_devdriv_DW.Mean_Iteration++;
    if (rpend_devdriv_DW.Mean_Iteration > 1U) {
      rpend_devdriv_DW.Mean_AccVal += rpend_devdriv_B.DCVelrads;
      rpend_devdriv_B.Mean = rpend_devdriv_DW.Mean_AccVal / (real_T)
        rpend_devdriv_DW.Mean_Iteration;
    } else {
      if (rpend_devdriv_DW.Mean_Iteration == 0U) {
        rpend_devdriv_DW.Mean_Iteration = 1U;
      }

      rpend_devdriv_DW.Mean_AccVal = rpend_devdriv_B.DCVelrads;
      rpend_devdriv_B.Mean = rpend_devdriv_B.DCVelrads;
    }

    /* End of S-Function (sdspstatfcns): '<Root>/Mean' */

    /* Gain: '<S1>/Pendulum Convert to rad' */
    rpend_devdriv_B.PendulumAnglerad = rpend_devdriv_P.PendulumConverttorad_Gain
      * rpend_devdriv_B.SFunction_o2;

    /* Sum: '<S5>/Add' incorporates:
     *  Constant: '<S5>/Constant'
     */
    rtb_ResetEncoders = rpend_devdriv_B.PendulumAnglerad +
      rpend_devdriv_P.Constant_Value;

    /* Trigonometry: '<S5>/Trigonometric Function3' incorporates:
     *  Trigonometry: '<S5>/Trigonometric Function4'
     *  Trigonometry: '<S5>/Trigonometric Function5'
     */
    rpend_devdriv_B.PendPos_ZeroUp = rt_atan2d_snf(sin(rtb_ResetEncoders), cos
      (rtb_ResetEncoders));

    /* Product: '<S1>/Divide1' incorporates:
     *  Gain: '<S1>/rad2rad//s'
     *  Memory: '<S1>/Memory2'
     *  Sum: '<S1>/Add2'
     */
    rpend_devdriv_B.PendulumVelrads = (rpend_devdriv_B.PendulumAnglerad -
      rpend_devdriv_DW.Memory2_PreviousInput) * rpend_devdriv_P.rad2rads_Gain /
      rpend_devdriv_B.Periodms;

    /* Derivative: '<Root>/Derivative' */
    tmp = rpend_devdriv_M->Timing.t[0];
    if ((rpend_devdriv_DW.TimeStampA >= tmp) && (rpend_devdriv_DW.TimeStampB >=
         tmp)) {
      rtb_ResetEncoders = 0.0;
    } else {
      rtb_ResetEncoders = rpend_devdriv_DW.TimeStampA;
      lastU = &rpend_devdriv_DW.LastUAtTimeA;
      if (rpend_devdriv_DW.TimeStampA < rpend_devdriv_DW.TimeStampB) {
        if (rpend_devdriv_DW.TimeStampB < tmp) {
          rtb_ResetEncoders = rpend_devdriv_DW.TimeStampB;
          lastU = &rpend_devdriv_DW.LastUAtTimeB;
        }
      } else {
        if (rpend_devdriv_DW.TimeStampA >= tmp) {
          rtb_ResetEncoders = rpend_devdriv_DW.TimeStampB;
          lastU = &rpend_devdriv_DW.LastUAtTimeB;
        }
      }

      rtb_ResetEncoders = (rpend_devdriv_B.PendulumVelrads - *lastU) / (tmp -
        rtb_ResetEncoders);
    }

    /* End of Derivative: '<Root>/Derivative' */

    /* Gain: '<Root>/Gain' incorporates:
     *  Constant: '<Root>/Constant'
     *  Sum: '<Root>/Sum'
     */
    rtb_ResetEncoders = (((rpend_devdriv_B.PendPos_ZeroUp - rpend_devdriv_P.xep
      [0]) * -rpend_devdriv_P.K_lqr[0] + (rpend_devdriv_B.PendulumVelrads -
      rpend_devdriv_P.xep[1]) * -rpend_devdriv_P.K_lqr[1]) +
                         (rpend_devdriv_B.DCVelrads - rpend_devdriv_P.xep[2]) *
                         -rpend_devdriv_P.K_lqr[2]) + (rtb_ResetEncoders -
      rpend_devdriv_P.xep[3]) * -rpend_devdriv_P.K_lqr[3];

    /* Saturate: '<Root>/Saturation' incorporates:
     *  Gain: '<Root>/Gain'
     */
    if (rtb_ResetEncoders > rpend_devdriv_P.Saturation_UpperSat) {
      rpend_devdriv_B.Saturation = rpend_devdriv_P.Saturation_UpperSat;
    } else if (rtb_ResetEncoders < rpend_devdriv_P.Saturation_LowerSat) {
      rpend_devdriv_B.Saturation = rpend_devdriv_P.Saturation_LowerSat;
    } else {
      rpend_devdriv_B.Saturation = rtb_ResetEncoders;
    }

    /* End of Saturate: '<Root>/Saturation' */

    /* ManualSwitch: '<Root>/Reset Encoders1' incorporates:
     *  Constant: '<Root>/Normal'
     */
    if (rpend_devdriv_P.ResetEncoders1_CurrentSetting == 1) {
      tmp = rpend_devdriv_B.Saturation;
    } else {
      tmp = rpend_devdriv_P.Normal_Value;
    }

    /* End of ManualSwitch: '<Root>/Reset Encoders1' */

    /* Gain: '<Root>/Gain3' */
    rpend_devdriv_B.Control = rpend_devdriv_P.Gain3_Gain * tmp;

    /* Trigonometry: '<S5>/Trigonometric Function' incorporates:
     *  Trigonometry: '<S5>/Trigonometric Function1'
     *  Trigonometry: '<S5>/Trigonometric Function2'
     */
    rpend_devdriv_B.PendPos_ZeroDown = rt_atan2d_snf(sin
      (rpend_devdriv_B.PendulumAnglerad), cos(rpend_devdriv_B.PendulumAnglerad));

    /* Gain: '<S1>/DC Convert to [A]1' */
    rpend_devdriv_B.DCConverttoA1 = rpend_devdriv_P.DCConverttoA1_Gain *
      rpend_devdriv_B.SFunction_o4;

    /* Scope: '<Root>/PlotState' */
    {
      StructLogVar *svar = (StructLogVar *)
        rpend_devdriv_DW.PlotState_PWORK.LoggedData[0];
      LogVar *var = svar->signals.values;

      /* time */
      {
        double locTime = rpend_devdriv_M->Timing.t[1];
        ;
        rt_UpdateLogVar((LogVar *)svar->time, &locTime, 0);
      }

      /* signals */
      {
        real_T up0[1];
        up0[0] = rpend_devdriv_B.Control;
        rt_UpdateLogVar((LogVar *)var, up0, 0);
        var = var->next;
      }

      {
        real_T up1[1];
        up1[0] = rpend_devdriv_B.PendPos_ZeroDown;
        rt_UpdateLogVar((LogVar *)var, up1, 0);
        var = var->next;
      }

      {
        real_T up2[1];
        up2[0] = rpend_devdriv_B.PendulumAnglerad;
        rt_UpdateLogVar((LogVar *)var, up2, 0);
        var = var->next;
      }

      {
        real_T up3[1];
        up3[0] = rpend_devdriv_B.PendulumVelrads;
        rt_UpdateLogVar((LogVar *)var, up3, 0);
        var = var->next;
      }

      {
        real_T up4[1];
        up4[0] = rpend_devdriv_B.DCAnglerad;
        rt_UpdateLogVar((LogVar *)var, up4, 0);
        var = var->next;
      }

      {
        real_T up5[1];
        up5[0] = rpend_devdriv_B.DCVelrads;
        rt_UpdateLogVar((LogVar *)var, up5, 0);
        var = var->next;
      }

      {
        real_T up6[1];
        up6[0] = rpend_devdriv_B.PendPos_ZeroUp;
        rt_UpdateLogVar((LogVar *)var, up6, 0);
        var = var->next;
      }

      {
        real_T up7[1];
        up7[0] = rpend_devdriv_B.DCConverttoA1;
        rt_UpdateLogVar((LogVar *)var, up7, 0);
      }
    }

    /* Scope: '<Root>/Scope' */
    {
      StructLogVar *svar = (StructLogVar *)
        rpend_devdriv_DW.Scope_PWORK.LoggedData[0];
      LogVar *var = svar->signals.values;

      /* time */
      {
        double locTime = rpend_devdriv_M->Timing.t[1];
        ;
        rt_UpdateLogVar((LogVar *)svar->time, &locTime, 0);
      }

      /* signals */
      {
        real_T up0[1];
        up0[0] = rpend_devdriv_B.DCVelrads;
        rt_UpdateLogVar((LogVar *)var, up0, 0);
        var = var->next;
      }

      {
        real_T up1[1];
        up1[0] = rpend_devdriv_B.Saturation;
        rt_UpdateLogVar((LogVar *)var, up1, 0);
      }
    }

    /* Scope: '<Root>/Scope1' */
    {
      StructLogVar *svar = (StructLogVar *)
        rpend_devdriv_DW.Scope1_PWORK.LoggedData;
      LogVar *var = svar->signals.values;

      /* time */
      {
        double locTime = rpend_devdriv_M->Timing.t[1];
        ;
        rt_UpdateLogVar((LogVar *)svar->time, &locTime, 0);
      }

      /* signals */
      {
        real_T up0[1];
        up0[0] = rpend_devdriv_B.PendulumAnglerad;
        rt_UpdateLogVar((LogVar *)var, up0, 0);
      }
    }

    /* ManualSwitch: '<Root>/Reset Encoders' incorporates:
     *  Constant: '<Root>/Reset'
     *  Step: '<Root>/Step'
     */
    if (rpend_devdriv_P.ResetEncoders_CurrentSetting == 1) {
      rtb_ResetEncoders = rpend_devdriv_P.Reset_Value;
    } else if (rpend_devdriv_M->Timing.t[1] < rpend_devdriv_P.Step_Time) {
      /* Step: '<Root>/Step' */
      rtb_ResetEncoders = rpend_devdriv_P.Step_Y0;
    } else {
      rtb_ResetEncoders = rpend_devdriv_P.Step_YFinal;
    }

    /* End of ManualSwitch: '<Root>/Reset Encoders' */

    /* Gain: '<S1>/Gain' */
    rpend_devdriv_B.Gain[0] = rpend_devdriv_P.Gain_Gain[0] * rtb_ResetEncoders;
    rpend_devdriv_B.Gain[1] = rpend_devdriv_P.Gain_Gain[1] * rtb_ResetEncoders;

    /* Constant: '<S1>/Prescaler' */
    rpend_devdriv_B.Prescaler = rpend_devdriv_P.Prescaler_Value;

    /* Gain: '<S1>/Gain2' */
    rtb_ResetEncoders = rpend_devdriv_P.Gain2_Gain * rpend_devdriv_B.Control;

    /* Saturate: '<S1>/Saturation' */
    if (rtb_ResetEncoders > rpend_devdriv_P.Saturation_UpperSat_d) {
      rpend_devdriv_B.Saturation_g = rpend_devdriv_P.Saturation_UpperSat_d;
    } else if (rtb_ResetEncoders < rpend_devdriv_P.Saturation_LowerSat_e) {
      rpend_devdriv_B.Saturation_g = rpend_devdriv_P.Saturation_LowerSat_e;
    } else {
      rpend_devdriv_B.Saturation_g = rtb_ResetEncoders;
    }

    /* End of Saturate: '<S1>/Saturation' */

    /* Constant: '<S1>/ThermFlag' */
    rpend_devdriv_B.ThermFlag = rpend_devdriv_P.ThermFlag_Value;
  }

  /* Matfile logging */
  rt_UpdateTXYLogVars(rpend_devdriv_M->rtwLogInfo, (rpend_devdriv_M->Timing.t));

  {
    real_T *lastU;

    /* Update for Memory: '<S1>/Memory1' */
    rpend_devdriv_DW.Memory1_PreviousInput = rpend_devdriv_B.DCAnglerad;

    /* Update for Memory: '<S1>/Memory' */
    rpend_devdriv_DW.Memory_PreviousInput = rpend_devdriv_B.SFunction_o6;

    /* Update for Memory: '<S1>/Memory2' */
    rpend_devdriv_DW.Memory2_PreviousInput = rpend_devdriv_B.PendulumAnglerad;

    /* Update for Derivative: '<Root>/Derivative' */
    if (rpend_devdriv_DW.TimeStampA == (rtInf)) {
      rpend_devdriv_DW.TimeStampA = rpend_devdriv_M->Timing.t[0];
      lastU = &rpend_devdriv_DW.LastUAtTimeA;
    } else if (rpend_devdriv_DW.TimeStampB == (rtInf)) {
      rpend_devdriv_DW.TimeStampB = rpend_devdriv_M->Timing.t[0];
      lastU = &rpend_devdriv_DW.LastUAtTimeB;
    } else if (rpend_devdriv_DW.TimeStampA < rpend_devdriv_DW.TimeStampB) {
      rpend_devdriv_DW.TimeStampA = rpend_devdriv_M->Timing.t[0];
      lastU = &rpend_devdriv_DW.LastUAtTimeA;
    } else {
      rpend_devdriv_DW.TimeStampB = rpend_devdriv_M->Timing.t[0];
      lastU = &rpend_devdriv_DW.LastUAtTimeB;
    }

    *lastU = rpend_devdriv_B.PendulumVelrads;

    /* End of Update for Derivative: '<Root>/Derivative' */
  }

  /* External mode */
  rtExtModeUploadCheckTrigger(2);

  {                                    /* Sample time: [0.0s, 0.0s] */
    rtExtModeUpload(0, (real_T)rpend_devdriv_M->Timing.t[0]);
  }

  {                                    /* Sample time: [0.01s, 0.0s] */
    rtExtModeUpload(1, (real_T)rpend_devdriv_M->Timing.t[1]);
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.0s, 0.0s] */
    if ((rtmGetTFinal(rpend_devdriv_M)!=-1) &&
        !((rtmGetTFinal(rpend_devdriv_M)-rpend_devdriv_M->Timing.t[0]) >
          rpend_devdriv_M->Timing.t[0] * (DBL_EPSILON))) {
      rtmSetErrorStatus(rpend_devdriv_M, "Simulation finished");
    }

    if (rtmGetStopRequested(rpend_devdriv_M)) {
      rtmSetErrorStatus(rpend_devdriv_M, "Simulation finished");
    }
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
  if (!(++rpend_devdriv_M->Timing.clockTick0)) {
    ++rpend_devdriv_M->Timing.clockTickH0;
  }

  rpend_devdriv_M->Timing.t[0] = rpend_devdriv_M->Timing.clockTick0 *
    rpend_devdriv_M->Timing.stepSize0 + rpend_devdriv_M->Timing.clockTickH0 *
    rpend_devdriv_M->Timing.stepSize0 * 4294967296.0;

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
    if (!(++rpend_devdriv_M->Timing.clockTick1)) {
      ++rpend_devdriv_M->Timing.clockTickH1;
    }

    rpend_devdriv_M->Timing.t[1] = rpend_devdriv_M->Timing.clockTick1 *
      rpend_devdriv_M->Timing.stepSize1 + rpend_devdriv_M->Timing.clockTickH1 *
      rpend_devdriv_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Model initialize function */
void rpend_devdriv_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)rpend_devdriv_M, 0,
                sizeof(RT_MODEL_rpend_devdriv_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&rpend_devdriv_M->solverInfo,
                          &rpend_devdriv_M->Timing.simTimeStep);
    rtsiSetTPtr(&rpend_devdriv_M->solverInfo, &rtmGetTPtr(rpend_devdriv_M));
    rtsiSetStepSizePtr(&rpend_devdriv_M->solverInfo,
                       &rpend_devdriv_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&rpend_devdriv_M->solverInfo, (&rtmGetErrorStatus
      (rpend_devdriv_M)));
    rtsiSetRTModelPtr(&rpend_devdriv_M->solverInfo, rpend_devdriv_M);
  }

  rtsiSetSimTimeStep(&rpend_devdriv_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&rpend_devdriv_M->solverInfo,"FixedStepDiscrete");
  rpend_devdriv_M->solverInfoPtr = (&rpend_devdriv_M->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap = rpend_devdriv_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    rpend_devdriv_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    rpend_devdriv_M->Timing.sampleTimes =
      (&rpend_devdriv_M->Timing.sampleTimesArray[0]);
    rpend_devdriv_M->Timing.offsetTimes =
      (&rpend_devdriv_M->Timing.offsetTimesArray[0]);

    /* task periods */
    rpend_devdriv_M->Timing.sampleTimes[0] = (0.0);
    rpend_devdriv_M->Timing.sampleTimes[1] = (0.01);

    /* task offsets */
    rpend_devdriv_M->Timing.offsetTimes[0] = (0.0);
    rpend_devdriv_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(rpend_devdriv_M, &rpend_devdriv_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = rpend_devdriv_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    rpend_devdriv_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(rpend_devdriv_M, 999.0);
  rpend_devdriv_M->Timing.stepSize0 = 0.01;
  rpend_devdriv_M->Timing.stepSize1 = 0.01;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = NULL;
    rpend_devdriv_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(rpend_devdriv_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(rpend_devdriv_M->rtwLogInfo, (NULL));
    rtliSetLogT(rpend_devdriv_M->rtwLogInfo, "tout");
    rtliSetLogX(rpend_devdriv_M->rtwLogInfo, "");
    rtliSetLogXFinal(rpend_devdriv_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(rpend_devdriv_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(rpend_devdriv_M->rtwLogInfo, 0);
    rtliSetLogMaxRows(rpend_devdriv_M->rtwLogInfo, 0);
    rtliSetLogDecimation(rpend_devdriv_M->rtwLogInfo, 1);
    rtliSetLogY(rpend_devdriv_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(rpend_devdriv_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(rpend_devdriv_M->rtwLogInfo, (NULL));
  }

  /* External mode info */
  rpend_devdriv_M->Sizes.checksums[0] = (413417902U);
  rpend_devdriv_M->Sizes.checksums[1] = (1930857919U);
  rpend_devdriv_M->Sizes.checksums[2] = (105968771U);
  rpend_devdriv_M->Sizes.checksums[3] = (2354698940U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[4];
    rpend_devdriv_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(rpend_devdriv_M->extModeInfo,
      &rpend_devdriv_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(rpend_devdriv_M->extModeInfo,
                        rpend_devdriv_M->Sizes.checksums);
    rteiSetTPtr(rpend_devdriv_M->extModeInfo, rtmGetTPtr(rpend_devdriv_M));
  }

  rpend_devdriv_M->solverInfoPtr = (&rpend_devdriv_M->solverInfo);
  rpend_devdriv_M->Timing.stepSize = (0.01);
  rtsiSetFixedStepSize(&rpend_devdriv_M->solverInfo, 0.01);
  rtsiSetSolverMode(&rpend_devdriv_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  (void) memset(((void *) &rpend_devdriv_B), 0,
                sizeof(B_rpend_devdriv_T));

  /* states (dwork) */
  (void) memset((void *)&rpend_devdriv_DW, 0,
                sizeof(DW_rpend_devdriv_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    rpend_devdriv_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* child S-Function registration */
  {
    RTWSfcnInfo *sfcnInfo = &rpend_devdriv_M->NonInlinedSFcns.sfcnInfo;
    rpend_devdriv_M->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus(rpend_devdriv_M)));
    rtssSetNumRootSampTimesPtr(sfcnInfo, &rpend_devdriv_M->Sizes.numSampTimes);
    rpend_devdriv_M->NonInlinedSFcns.taskTimePtrs[0] = &(rtmGetTPtr
      (rpend_devdriv_M)[0]);
    rpend_devdriv_M->NonInlinedSFcns.taskTimePtrs[1] = &(rtmGetTPtr
      (rpend_devdriv_M)[1]);
    rtssSetTPtrPtr(sfcnInfo,rpend_devdriv_M->NonInlinedSFcns.taskTimePtrs);
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(rpend_devdriv_M));
    rtssSetTFinalPtr(sfcnInfo, &rtmGetTFinal(rpend_devdriv_M));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput(rpend_devdriv_M));
    rtssSetStepSizePtr(sfcnInfo, &rpend_devdriv_M->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested(rpend_devdriv_M));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo,
      &rpend_devdriv_M->derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo, &rpend_devdriv_M->zCCacheNeedsReset);
    rtssSetContTimeOutputInconsistentWithStateAtMajorStepPtr(sfcnInfo,
      &rpend_devdriv_M->CTOutputIncnstWithState);
    rtssSetSampleHitsPtr(sfcnInfo, &rpend_devdriv_M->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo,
      &rpend_devdriv_M->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &rpend_devdriv_M->simMode);
    rtssSetSolverInfoPtr(sfcnInfo, &rpend_devdriv_M->solverInfoPtr);
  }

  rpend_devdriv_M->Sizes.numSFcns = (1);

  /* register each child */
  {
    (void) memset((void *)&rpend_devdriv_M->NonInlinedSFcns.childSFunctions[0],
                  0,
                  1*sizeof(SimStruct));
    rpend_devdriv_M->childSfunctions =
      (&rpend_devdriv_M->NonInlinedSFcns.childSFunctionPtrs[0]);
    rpend_devdriv_M->childSfunctions[0] =
      (&rpend_devdriv_M->NonInlinedSFcns.childSFunctions[0]);

    /* Level2 S-Function Block: rpend_devdriv/<S1>/S-Function (rtdacusb2_rpend_dd) */
    {
      SimStruct *rts = rpend_devdriv_M->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod = rpend_devdriv_M->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset = rpend_devdriv_M->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap = rpend_devdriv_M->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &rpend_devdriv_M->NonInlinedSFcns.blkInfo2[0]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &rpend_devdriv_M->NonInlinedSFcns.inputOutputPortInfo2[0]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, rpend_devdriv_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &rpend_devdriv_M->NonInlinedSFcns.methods2[0]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &rpend_devdriv_M->NonInlinedSFcns.methods3[0]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &rpend_devdriv_M->NonInlinedSFcns.methods4[0]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &rpend_devdriv_M->NonInlinedSFcns.statesInfo2[0]);
        ssSetPeriodicStatesInfo(rts,
          &rpend_devdriv_M->NonInlinedSFcns.periodicStatesInfo[0]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 4);
        ssSetPortInfoForInputs(rts,
          &rpend_devdriv_M->NonInlinedSFcns.Sfcn0.inputPortInfo[0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &rpend_devdriv_M->NonInlinedSFcns.Sfcn0.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        ssSetInputPortUnit(rts, 1, 0);
        ssSetInputPortUnit(rts, 2, 0);
        ssSetInputPortUnit(rts, 3, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &rpend_devdriv_M->NonInlinedSFcns.Sfcn0.inputPortCoSimAttribute[0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);
        ssSetInputPortIsContinuousQuantity(rts, 1, 0);
        ssSetInputPortIsContinuousQuantity(rts, 2, 0);
        ssSetInputPortIsContinuousQuantity(rts, 3, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &rpend_devdriv_M->NonInlinedSFcns.Sfcn0.UPtrs0;
          sfcnUPtrs[0] = &rpend_devdriv_B.Saturation_g;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }

        /* port 1 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &rpend_devdriv_M->NonInlinedSFcns.Sfcn0.UPtrs1;
          sfcnUPtrs[0] = rpend_devdriv_B.Gain;
          sfcnUPtrs[1] = &rpend_devdriv_B.Gain[1];
          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 2);
        }

        /* port 2 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &rpend_devdriv_M->NonInlinedSFcns.Sfcn0.UPtrs2;
          sfcnUPtrs[0] = &rpend_devdriv_B.Prescaler;
          ssSetInputPortSignalPtrs(rts, 2, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 2, 1);
          ssSetInputPortWidth(rts, 2, 1);
        }

        /* port 3 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &rpend_devdriv_M->NonInlinedSFcns.Sfcn0.UPtrs3;
          sfcnUPtrs[0] = &rpend_devdriv_B.ThermFlag;
          ssSetInputPortSignalPtrs(rts, 3, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 3, 1);
          ssSetInputPortWidth(rts, 3, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &rpend_devdriv_M->NonInlinedSFcns.Sfcn0.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 7);
        _ssSetPortInfo2ForOutputUnits(rts,
          &rpend_devdriv_M->NonInlinedSFcns.Sfcn0.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);
        ssSetOutputPortUnit(rts, 1, 0);
        ssSetOutputPortUnit(rts, 2, 0);
        ssSetOutputPortUnit(rts, 3, 0);
        ssSetOutputPortUnit(rts, 4, 0);
        ssSetOutputPortUnit(rts, 5, 0);
        ssSetOutputPortUnit(rts, 6, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &rpend_devdriv_M->NonInlinedSFcns.Sfcn0.outputPortCoSimAttribute[0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);
        ssSetOutputPortIsContinuousQuantity(rts, 1, 0);
        ssSetOutputPortIsContinuousQuantity(rts, 2, 0);
        ssSetOutputPortIsContinuousQuantity(rts, 3, 0);
        ssSetOutputPortIsContinuousQuantity(rts, 4, 0);
        ssSetOutputPortIsContinuousQuantity(rts, 5, 0);
        ssSetOutputPortIsContinuousQuantity(rts, 6, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &rpend_devdriv_B.SFunction_o1));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidth(rts, 1, 1);
          ssSetOutputPortSignal(rts, 1, ((real_T *)
            &rpend_devdriv_B.SFunction_o2));
        }

        /* port 2 */
        {
          _ssSetOutputPortNumDimensions(rts, 2, 1);
          ssSetOutputPortWidth(rts, 2, 1);
          ssSetOutputPortSignal(rts, 2, ((real_T *)
            &rpend_devdriv_B.SFunction_o3));
        }

        /* port 3 */
        {
          _ssSetOutputPortNumDimensions(rts, 3, 1);
          ssSetOutputPortWidth(rts, 3, 1);
          ssSetOutputPortSignal(rts, 3, ((real_T *)
            &rpend_devdriv_B.SFunction_o4));
        }

        /* port 4 */
        {
          _ssSetOutputPortNumDimensions(rts, 4, 1);
          ssSetOutputPortWidth(rts, 4, 1);
          ssSetOutputPortSignal(rts, 4, ((real_T *)
            &rpend_devdriv_B.SFunction_o5));
        }

        /* port 5 */
        {
          _ssSetOutputPortNumDimensions(rts, 5, 1);
          ssSetOutputPortWidth(rts, 5, 1);
          ssSetOutputPortSignal(rts, 5, ((real_T *)
            &rpend_devdriv_B.SFunction_o6));
        }

        /* port 6 */
        {
          _ssSetOutputPortNumDimensions(rts, 6, 1);
          ssSetOutputPortWidth(rts, 6, 2);
          ssSetOutputPortSignal(rts, 6, ((real_T *) rpend_devdriv_B.SFunction_o7));
        }
      }

      /* path info */
      ssSetModelName(rts, "S-Function");
      ssSetPath(rts, "rpend_devdriv/RP Driver/S-Function");
      ssSetRTModel(rts,rpend_devdriv_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &rpend_devdriv_M->NonInlinedSFcns.Sfcn0.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)rpend_devdriv_P.SFunction_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)rpend_devdriv_P.SFunction_P2_Size);
      }

      /* registration */
      rtdacusb2_rpend_dd(rts);
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
      _ssSetInputPortConnected(rts, 1, 1);
      _ssSetInputPortConnected(rts, 2, 1);
      _ssSetInputPortConnected(rts, 3, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 1, 1);
      _ssSetOutputPortConnected(rts, 2, 1);
      _ssSetOutputPortConnected(rts, 3, 1);
      _ssSetOutputPortConnected(rts, 4, 1);
      _ssSetOutputPortConnected(rts, 5, 1);
      _ssSetOutputPortConnected(rts, 6, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);
      _ssSetOutputPortBeingMerged(rts, 1, 0);
      _ssSetOutputPortBeingMerged(rts, 2, 0);
      _ssSetOutputPortBeingMerged(rts, 3, 0);
      _ssSetOutputPortBeingMerged(rts, 4, 0);
      _ssSetOutputPortBeingMerged(rts, 5, 0);
      _ssSetOutputPortBeingMerged(rts, 6, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
      ssSetInputPortBufferDstPort(rts, 1, -1);
      ssSetInputPortBufferDstPort(rts, 2, -1);
      ssSetInputPortBufferDstPort(rts, 3, -1);
    }
  }

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(rpend_devdriv_M->rtwLogInfo, 0.0,
    rtmGetTFinal(rpend_devdriv_M), rpend_devdriv_M->Timing.stepSize0,
    (&rtmGetErrorStatus(rpend_devdriv_M)));

  /* Start for S-Function (rtdacusb2_rpend_dd): '<S1>/S-Function' */
  /* Level2 S-Function Block: '<S1>/S-Function' (rtdacusb2_rpend_dd) */
  {
    SimStruct *rts = rpend_devdriv_M->childSfunctions[0];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for Scope: '<Root>/PlotState' */
  {
    RTWLogSignalInfo rt_ScopeSignalInfo;
    static int_T rt_ScopeSignalWidths[] = { 1, 1, 1, 1, 1, 1, 1, 1 };

    static int_T rt_ScopeSignalNumDimensions[] = { 1, 1, 1, 1, 1, 1, 1, 1 };

    static int_T rt_ScopeSignalDimensions[] = { 1, 1, 1, 1, 1, 1, 1, 1 };

    static void *rt_ScopeCurrSigDims[] = { (NULL), (NULL), (NULL), (NULL), (NULL),
      (NULL), (NULL), (NULL) };

    static int_T rt_ScopeCurrSigDimsSize[] = { 4, 4, 4, 4, 4, 4, 4, 4 };

    static const char_T *rt_ScopeSignalLabels[] = { "Control",
      "<PendPos_ZeroDown>",
      "<Pendulum Angle [rad]>",
      "<Pendulum Vel [rad/s]>",
      "<DC Angle [rad]>",
      "<DC Vel [rad/s]>",
      "<PendPos_ZeroUp>",
      "" };

    static char_T rt_ScopeSignalTitles[] =
      "Control<PendPos_ZeroDown><Pendulum Angle [rad]><Pendulum Vel [rad/s]><DC Angle [rad]><DC Vel [rad/s]><PendPos_ZeroUp>";
    static int_T rt_ScopeSignalTitleLengths[] = { 7, 18, 22, 22, 16, 16, 16, 0 };

    static boolean_T rt_ScopeSignalIsVarDims[] = { 0, 0, 0, 0, 0, 0, 0, 0 };

    static int_T rt_ScopeSignalPlotStyles[] = { 0, 1, 1, 1, 1, 1, 1, 1 };

    BuiltInDTypeId dTypes[8] = { SS_DOUBLE, SS_DOUBLE, SS_DOUBLE, SS_DOUBLE,
      SS_DOUBLE, SS_DOUBLE, SS_DOUBLE, SS_DOUBLE };

    static char_T rt_ScopeBlockName[] = "rpend_devdriv/PlotState";
    static int_T rt_ScopeFrameData[] = { 0, 0, 0, 0, 0, 0, 0, 0 };

    static RTWPreprocessingFcnPtr rt_ScopeSignalLoggingPreprocessingFcnPtrs[] =
      {
      (NULL), (NULL), (NULL), (NULL), (NULL), (NULL), (NULL), (NULL)
    };

    rt_ScopeSignalInfo.numSignals = 8;
    rt_ScopeSignalInfo.numCols = rt_ScopeSignalWidths;
    rt_ScopeSignalInfo.numDims = rt_ScopeSignalNumDimensions;
    rt_ScopeSignalInfo.dims = rt_ScopeSignalDimensions;
    rt_ScopeSignalInfo.isVarDims = rt_ScopeSignalIsVarDims;
    rt_ScopeSignalInfo.currSigDims = rt_ScopeCurrSigDims;
    rt_ScopeSignalInfo.currSigDimsSize = rt_ScopeCurrSigDimsSize;
    rt_ScopeSignalInfo.dataTypes = dTypes;
    rt_ScopeSignalInfo.complexSignals = (NULL);
    rt_ScopeSignalInfo.frameData = rt_ScopeFrameData;
    rt_ScopeSignalInfo.preprocessingPtrs =
      rt_ScopeSignalLoggingPreprocessingFcnPtrs;
    rt_ScopeSignalInfo.labels.cptr = rt_ScopeSignalLabels;
    rt_ScopeSignalInfo.titles = rt_ScopeSignalTitles;
    rt_ScopeSignalInfo.titleLengths = rt_ScopeSignalTitleLengths;
    rt_ScopeSignalInfo.plotStyles = rt_ScopeSignalPlotStyles;
    rt_ScopeSignalInfo.blockNames.cptr = (NULL);
    rt_ScopeSignalInfo.stateNames.cptr = (NULL);
    rt_ScopeSignalInfo.crossMdlRef = (NULL);
    rt_ScopeSignalInfo.dataTypeConvert = (NULL);
    rpend_devdriv_DW.PlotState_PWORK.LoggedData[0] = rt_CreateStructLogVar(
      rpend_devdriv_M->rtwLogInfo,
      0.0,
      rtmGetTFinal(rpend_devdriv_M),
      rpend_devdriv_M->Timing.stepSize0,
      (&rtmGetErrorStatus(rpend_devdriv_M)),
      "StateData",
      1,
      0,
      1,
      0.01,
      &rt_ScopeSignalInfo,
      rt_ScopeBlockName);
    if (rpend_devdriv_DW.PlotState_PWORK.LoggedData[0] == (NULL))
      return;
  }

  /* Start for Scope: '<Root>/Scope' */
  {
    RTWLogSignalInfo rt_ScopeSignalInfo;
    static int_T rt_ScopeSignalWidths[] = { 1, 1 };

    static int_T rt_ScopeSignalNumDimensions[] = { 1, 1 };

    static int_T rt_ScopeSignalDimensions[] = { 1, 1 };

    static void *rt_ScopeCurrSigDims[] = { (NULL), (NULL) };

    static int_T rt_ScopeCurrSigDimsSize[] = { 4, 4 };

    static const char_T *rt_ScopeSignalLabels[] = { "<DC Vel [rad/s]>",
      "" };

    static char_T rt_ScopeSignalTitles[] = "<DC Vel [rad/s]>";
    static int_T rt_ScopeSignalTitleLengths[] = { 16, 0 };

    static boolean_T rt_ScopeSignalIsVarDims[] = { 0, 0 };

    static int_T rt_ScopeSignalPlotStyles[] = { 1, 0 };

    BuiltInDTypeId dTypes[2] = { SS_DOUBLE, SS_DOUBLE };

    static char_T rt_ScopeBlockName[] = "rpend_devdriv/Scope";
    static int_T rt_ScopeFrameData[] = { 0, 0 };

    static RTWPreprocessingFcnPtr rt_ScopeSignalLoggingPreprocessingFcnPtrs[] =
      {
      (NULL), (NULL)
    };

    rt_ScopeSignalInfo.numSignals = 2;
    rt_ScopeSignalInfo.numCols = rt_ScopeSignalWidths;
    rt_ScopeSignalInfo.numDims = rt_ScopeSignalNumDimensions;
    rt_ScopeSignalInfo.dims = rt_ScopeSignalDimensions;
    rt_ScopeSignalInfo.isVarDims = rt_ScopeSignalIsVarDims;
    rt_ScopeSignalInfo.currSigDims = rt_ScopeCurrSigDims;
    rt_ScopeSignalInfo.currSigDimsSize = rt_ScopeCurrSigDimsSize;
    rt_ScopeSignalInfo.dataTypes = dTypes;
    rt_ScopeSignalInfo.complexSignals = (NULL);
    rt_ScopeSignalInfo.frameData = rt_ScopeFrameData;
    rt_ScopeSignalInfo.preprocessingPtrs =
      rt_ScopeSignalLoggingPreprocessingFcnPtrs;
    rt_ScopeSignalInfo.labels.cptr = rt_ScopeSignalLabels;
    rt_ScopeSignalInfo.titles = rt_ScopeSignalTitles;
    rt_ScopeSignalInfo.titleLengths = rt_ScopeSignalTitleLengths;
    rt_ScopeSignalInfo.plotStyles = rt_ScopeSignalPlotStyles;
    rt_ScopeSignalInfo.blockNames.cptr = (NULL);
    rt_ScopeSignalInfo.stateNames.cptr = (NULL);
    rt_ScopeSignalInfo.crossMdlRef = (NULL);
    rt_ScopeSignalInfo.dataTypeConvert = (NULL);
    rpend_devdriv_DW.Scope_PWORK.LoggedData[0] = rt_CreateStructLogVar(
      rpend_devdriv_M->rtwLogInfo,
      0.0,
      rtmGetTFinal(rpend_devdriv_M),
      rpend_devdriv_M->Timing.stepSize0,
      (&rtmGetErrorStatus(rpend_devdriv_M)),
      "motor_vel",
      1,
      0,
      1,
      0.01,
      &rt_ScopeSignalInfo,
      rt_ScopeBlockName);
    if (rpend_devdriv_DW.Scope_PWORK.LoggedData[0] == (NULL))
      return;
  }

  /* Start for Scope: '<Root>/Scope1' */
  {
    RTWLogSignalInfo rt_ScopeSignalInfo;
    static int_T rt_ScopeSignalWidths[] = { 1 };

    static int_T rt_ScopeSignalNumDimensions[] = { 1 };

    static int_T rt_ScopeSignalDimensions[] = { 1 };

    static void *rt_ScopeCurrSigDims[] = { (NULL) };

    static int_T rt_ScopeCurrSigDimsSize[] = { 4 };

    static const char_T *rt_ScopeSignalLabels[] = { "<Pendulum Angle [rad]>" };

    static char_T rt_ScopeSignalTitles[] = "<Pendulum Angle [rad]>";
    static int_T rt_ScopeSignalTitleLengths[] = { 22 };

    static boolean_T rt_ScopeSignalIsVarDims[] = { 0 };

    static int_T rt_ScopeSignalPlotStyles[] = { 1 };

    BuiltInDTypeId dTypes[1] = { SS_DOUBLE };

    static char_T rt_ScopeBlockName[] = "rpend_devdriv/Scope1";
    static int_T rt_ScopeFrameData[] = { 0 };

    static RTWPreprocessingFcnPtr rt_ScopeSignalLoggingPreprocessingFcnPtrs[] =
      {
      (NULL)
    };

    rt_ScopeSignalInfo.numSignals = 1;
    rt_ScopeSignalInfo.numCols = rt_ScopeSignalWidths;
    rt_ScopeSignalInfo.numDims = rt_ScopeSignalNumDimensions;
    rt_ScopeSignalInfo.dims = rt_ScopeSignalDimensions;
    rt_ScopeSignalInfo.isVarDims = rt_ScopeSignalIsVarDims;
    rt_ScopeSignalInfo.currSigDims = rt_ScopeCurrSigDims;
    rt_ScopeSignalInfo.currSigDimsSize = rt_ScopeCurrSigDimsSize;
    rt_ScopeSignalInfo.dataTypes = dTypes;
    rt_ScopeSignalInfo.complexSignals = (NULL);
    rt_ScopeSignalInfo.frameData = rt_ScopeFrameData;
    rt_ScopeSignalInfo.preprocessingPtrs =
      rt_ScopeSignalLoggingPreprocessingFcnPtrs;
    rt_ScopeSignalInfo.labels.cptr = rt_ScopeSignalLabels;
    rt_ScopeSignalInfo.titles = rt_ScopeSignalTitles;
    rt_ScopeSignalInfo.titleLengths = rt_ScopeSignalTitleLengths;
    rt_ScopeSignalInfo.plotStyles = rt_ScopeSignalPlotStyles;
    rt_ScopeSignalInfo.blockNames.cptr = (NULL);
    rt_ScopeSignalInfo.stateNames.cptr = (NULL);
    rt_ScopeSignalInfo.crossMdlRef = (NULL);
    rt_ScopeSignalInfo.dataTypeConvert = (NULL);
    rpend_devdriv_DW.Scope1_PWORK.LoggedData = rt_CreateStructLogVar(
      rpend_devdriv_M->rtwLogInfo,
      0.0,
      rtmGetTFinal(rpend_devdriv_M),
      rpend_devdriv_M->Timing.stepSize0,
      (&rtmGetErrorStatus(rpend_devdriv_M)),
      "pend_angle",
      1,
      0,
      1,
      0.01,
      &rt_ScopeSignalInfo,
      rt_ScopeBlockName);
    if (rpend_devdriv_DW.Scope1_PWORK.LoggedData == (NULL))
      return;
  }

  /* Start for Constant: '<S1>/Prescaler' */
  rpend_devdriv_B.Prescaler = rpend_devdriv_P.Prescaler_Value;

  /* Start for Constant: '<S1>/ThermFlag' */
  rpend_devdriv_B.ThermFlag = rpend_devdriv_P.ThermFlag_Value;

  /* InitializeConditions for Memory: '<S1>/Memory1' */
  rpend_devdriv_DW.Memory1_PreviousInput =
    rpend_devdriv_P.Memory1_InitialCondition;

  /* InitializeConditions for Memory: '<S1>/Memory' */
  rpend_devdriv_DW.Memory_PreviousInput =
    rpend_devdriv_P.Memory_InitialCondition;

  /* InitializeConditions for S-Function (sdspstatfcns): '<Root>/Mean' */
  rpend_devdriv_DW.Mean_Iteration = 0U;
  rpend_devdriv_DW.Mean_EPHPState = 5U;
  rpend_devdriv_DW.Mean_AccVal = 0.0;

  /* InitializeConditions for Memory: '<S1>/Memory2' */
  rpend_devdriv_DW.Memory2_PreviousInput =
    rpend_devdriv_P.Memory2_InitialCondition;

  /* InitializeConditions for Derivative: '<Root>/Derivative' */
  rpend_devdriv_DW.TimeStampA = (rtInf);
  rpend_devdriv_DW.TimeStampB = (rtInf);
}

/* Model terminate function */
void rpend_devdriv_terminate(void)
{
  /* Terminate for S-Function (rtdacusb2_rpend_dd): '<S1>/S-Function' */
  /* Level2 S-Function Block: '<S1>/S-Function' (rtdacusb2_rpend_dd) */
  {
    SimStruct *rts = rpend_devdriv_M->childSfunctions[0];
    sfcnTerminate(rts);
  }
}

#include <stdio.h>

/* Final time from "Simulation Parameters"   */
real_T finaltime = 999.0;
real_T StepSize = 0.01;

////////////////////////////////////////////////
//
//  Return compilation date and time
//
char *GetDateAndTime( void )
{
  static char AuxStr[ 128 ];
  sprintf( AuxStr, "%s %s", __DATE__, __TIME__ );
  return( AuxStr );
}
