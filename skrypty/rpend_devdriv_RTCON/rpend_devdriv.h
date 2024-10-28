/*
 * rpend_devdriv.h
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

#ifndef RTW_HEADER_rpend_devdriv_h_
#define RTW_HEADER_rpend_devdriv_h_
#include <stddef.h>
#include <string.h>
#include <math.h>
#include <float.h>
#ifndef rpend_devdriv_COMMON_INCLUDES_
# define rpend_devdriv_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "rt_logging.h"
#include "dt_info.h"
#include "ext_work.h"
#endif                                 /* rpend_devdriv_COMMON_INCLUDES_ */

#include "rpend_devdriv_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#include "rt_defines.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
# define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
# define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
# define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
# define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
# define rtmGetRTWExtModeInfo(rtm)     ((rtm)->extModeInfo)
#endif

#ifndef rtmGetRTWLogInfo
# define rtmGetRTWLogInfo(rtm)         ((rtm)->rtwLogInfo)
#endif

#ifndef rtmGetSampleHitArray
# define rtmGetSampleHitArray(rtm)     ((rtm)->Timing.sampleHitArray)
#endif

#ifndef rtmGetStepSize
# define rtmGetStepSize(rtm)           ((rtm)->Timing.stepSize)
#endif

#ifndef rtmGetZCCacheNeedsReset
# define rtmGetZCCacheNeedsReset(rtm)  ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
# define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGet_TimeOfLastOutput
# define rtmGet_TimeOfLastOutput(rtm)  ((rtm)->Timing.timeOfLastOutput)
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

#ifndef rtmGetTStart
# define rtmGetTStart(rtm)             ((rtm)->Timing.tStart)
#endif

#ifndef rtmGetTimeOfLastOutput
# define rtmGetTimeOfLastOutput(rtm)   ((rtm)->Timing.timeOfLastOutput)
#endif

/* Block signals (default storage) */
typedef struct {
  real_T SFunction_o1;                 /* '<S1>/S-Function' */
  real_T SFunction_o2;                 /* '<S1>/S-Function' */
  real_T SFunction_o3;                 /* '<S1>/S-Function' */
  real_T SFunction_o4;                 /* '<S1>/S-Function' */
  real_T SFunction_o5;                 /* '<S1>/S-Function' */
  real_T SFunction_o6;                 /* '<S1>/S-Function' */
  real_T SFunction_o7[2];              /* '<S1>/S-Function' */
  real_T DCAnglerad;                   /* '<S1>/DC Convert to rad' */
  real_T Periodms;                     /* '<S1>/Gain1' */
  real_T DCVelrads;                    /* '<S1>/Divide' */
  real_T ResetEncoders2;               /* '<Root>/Reset Encoders2' */
  real_T Mean;                         /* '<Root>/Mean' */
  real_T PendulumAnglerad;             /* '<S1>/Pendulum Convert to rad' */
  real_T PendPos_ZeroUp;               /* '<S5>/Trigonometric Function3' */
  real_T PendulumVelrads;              /* '<S1>/Divide1' */
  real_T Saturation;                   /* '<Root>/Saturation' */
  real_T Control;                      /* '<Root>/Gain3' */
  real_T PendPos_ZeroDown;             /* '<S5>/Trigonometric Function' */
  real_T DCConverttoA1;                /* '<S1>/DC Convert to [A]1' */
  real_T Gain[2];                      /* '<S1>/Gain' */
  real_T Prescaler;                    /* '<S1>/Prescaler' */
  real_T Saturation_g;                 /* '<S1>/Saturation' */
  real_T ThermFlag;                    /* '<S1>/ThermFlag' */
} B_rpend_devdriv_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T Memory1_PreviousInput;        /* '<S1>/Memory1' */
  real_T Memory_PreviousInput;         /* '<S1>/Memory' */
  real_T Mean_AccVal;                  /* '<Root>/Mean' */
  real_T Memory2_PreviousInput;        /* '<S1>/Memory2' */
  real_T TimeStampA;                   /* '<Root>/Derivative' */
  real_T LastUAtTimeA;                 /* '<Root>/Derivative' */
  real_T TimeStampB;                   /* '<Root>/Derivative' */
  real_T LastUAtTimeB;                 /* '<Root>/Derivative' */
  struct {
    void *LoggedData[8];
  } PlotState_PWORK;                   /* '<Root>/PlotState' */

  struct {
    void *LoggedData[2];
  } Scope_PWORK;                       /* '<Root>/Scope' */

  struct {
    void *LoggedData;
  } Scope1_PWORK;                      /* '<Root>/Scope1' */

  uint32_T Mean_EPHPState;             /* '<Root>/Mean' */
  uint32_T Mean_Iteration;             /* '<Root>/Mean' */
} DW_rpend_devdriv_T;

/* Parameters (default storage) */
struct P_rpend_devdriv_T_ {
  real_T K_lqr[4];                     /* Variable: K_lqr
                                        * Referenced by: '<Root>/Gain'
                                        */
  real_T xep[4];                       /* Variable: xep
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Reset2_Value;                 /* Expression: 0
                                        * Referenced by: '<Root>/Reset2'
                                        */
  real_T Reset1_Value;                 /* Expression: 1
                                        * Referenced by: '<Root>/Reset1'
                                        */
  real_T Reset_Value;                  /* Expression: 1
                                        * Referenced by: '<Root>/Reset'
                                        */
  real_T SFunction_P1_Size[2];         /* Computed Parameter: SFunction_P1_Size
                                        * Referenced by: '<S1>/S-Function'
                                        */
  real_T SFunction_P1;                 /* Expression: 1
                                        * Referenced by: '<S1>/S-Function'
                                        */
  real_T SFunction_P2_Size[2];         /* Computed Parameter: SFunction_P2_Size
                                        * Referenced by: '<S1>/S-Function'
                                        */
  real_T SFunction_P2;                 /* Expression: 0.01
                                        * Referenced by: '<S1>/S-Function'
                                        */
  real_T DCConverttorad_Gain;          /* Expression: 2*pi/4096
                                        * Referenced by: '<S1>/DC Convert to rad'
                                        */
  real_T Memory1_InitialCondition;     /* Expression: 0
                                        * Referenced by: '<S1>/Memory1'
                                        */
  real_T rad2RPM_Gain;                 /* Expression: 1
                                        * Referenced by: '<S1>/rad2RPM'
                                        */
  real_T Memory_InitialCondition;      /* Expression: 0
                                        * Referenced by: '<S1>/Memory'
                                        */
  real_T Gain1_Gain;                   /* Expression: 1/20000000
                                        * Referenced by: '<S1>/Gain1'
                                        */
  real_T PendulumConverttorad_Gain;    /* Expression: 2*pi/20000
                                        * Referenced by: '<S1>/Pendulum Convert to rad'
                                        */
  real_T Constant_Value;               /* Expression: pi
                                        * Referenced by: '<S5>/Constant'
                                        */
  real_T Memory2_InitialCondition;     /* Expression: 0
                                        * Referenced by: '<S1>/Memory2'
                                        */
  real_T rad2rads_Gain;                /* Expression: 1
                                        * Referenced by: '<S1>/rad2rad//s'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 1
                                        * Referenced by: '<Root>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: -1
                                        * Referenced by: '<Root>/Saturation'
                                        */
  real_T Normal_Value;                 /* Expression: 0
                                        * Referenced by: '<Root>/Normal'
                                        */
  real_T Gain3_Gain;                   /* Expression: 0.5
                                        * Referenced by: '<Root>/Gain3'
                                        */
  real_T DCConverttoA1_Gain;           /* Expression: 1
                                        * Referenced by: '<S1>/DC Convert to [A]1'
                                        */
  real_T Step_Time;                    /* Expression: 0.05
                                        * Referenced by: '<Root>/Step'
                                        */
  real_T Step_Y0;                      /* Expression: 1
                                        * Referenced by: '<Root>/Step'
                                        */
  real_T Step_YFinal;                  /* Expression: 0
                                        * Referenced by: '<Root>/Step'
                                        */
  real_T Gain_Gain[2];                 /* Expression: [1;1]
                                        * Referenced by: '<S1>/Gain'
                                        */
  real_T Gain2_Gain;                   /* Expression: 1
                                        * Referenced by: '<S1>/Gain2'
                                        */
  real_T Prescaler_Value;              /* Expression: 0
                                        * Referenced by: '<S1>/Prescaler'
                                        */
  real_T Saturation_UpperSat_d;        /* Expression: 1
                                        * Referenced by: '<S1>/Saturation'
                                        */
  real_T Saturation_LowerSat_e;        /* Expression: -1
                                        * Referenced by: '<S1>/Saturation'
                                        */
  real_T ThermFlag_Value;              /* Expression: 0
                                        * Referenced by: '<S1>/ThermFlag'
                                        */
  uint8_T ResetEncoders2_CurrentSetting;/* Computed Parameter: ResetEncoders2_CurrentSetting
                                         * Referenced by: '<Root>/Reset Encoders2'
                                         */
  uint8_T ResetEncoders1_CurrentSetting;/* Computed Parameter: ResetEncoders1_CurrentSetting
                                         * Referenced by: '<Root>/Reset Encoders1'
                                         */
  uint8_T ResetEncoders_CurrentSetting;/* Computed Parameter: ResetEncoders_CurrentSetting
                                        * Referenced by: '<Root>/Reset Encoders'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_rpend_devdriv_T {
  struct SimStruct_tag * *childSfunctions;
  const char_T *errorStatus;
  SS_SimMode simMode;
  RTWLogInfo *rtwLogInfo;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;
  RTWSolverInfo *solverInfoPtr;
  void *sfcnInfo;

  /*
   * NonInlinedSFcns:
   * The following substructure contains information regarding
   * non-inlined s-functions used in the model.
   */
  struct {
    RTWSfcnInfo sfcnInfo;
    time_T *taskTimePtrs[2];
    SimStruct childSFunctions[1];
    SimStruct *childSFunctionPtrs[1];
    struct _ssBlkInfo2 blkInfo2[1];
    struct _ssSFcnModelMethods2 methods2[1];
    struct _ssSFcnModelMethods3 methods3[1];
    struct _ssSFcnModelMethods4 methods4[1];
    struct _ssStatesInfo2 statesInfo2[1];
    ssPeriodicStatesInfo periodicStatesInfo[1];
    struct _ssPortInfo2 inputOutputPortInfo2[1];
    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[4];
      struct _ssInPortUnit inputPortUnits[4];
      struct _ssInPortCoSimAttribute inputPortCoSimAttribute[4];
      real_T const *UPtrs0[1];
      real_T const *UPtrs1[2];
      real_T const *UPtrs2[1];
      real_T const *UPtrs3[1];
      struct _ssPortOutputs outputPortInfo[7];
      struct _ssOutPortUnit outputPortUnits[7];
      struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[7];
      uint_T attribs[2];
      mxArray *params[2];
    } Sfcn0;
  } NonInlinedSFcns;

  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
    uint32_T options;
    int_T numContStates;
    int_T numU;
    int_T numY;
    int_T numSampTimes;
    int_T numBlocks;
    int_T numBlockIO;
    int_T numBlockPrms;
    int_T numDwork;
    int_T numSFcnPrms;
    int_T numSFcns;
    int_T numIports;
    int_T numOports;
    int_T numNonSampZCs;
    int_T sysDirFeedThru;
    int_T rtwGenSfcn;
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T stepSize;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    time_T stepSize1;
    time_T tStart;
    time_T tFinal;
    time_T timeOfLastOutput;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *sampleTimes;
    time_T *offsetTimes;
    int_T *sampleTimeTaskIDPtr;
    int_T *sampleHits;
    int_T *perTaskSampleHits;
    time_T *t;
    time_T sampleTimesArray[2];
    time_T offsetTimesArray[2];
    int_T sampleTimeTaskIDArray[2];
    int_T sampleHitArray[2];
    int_T perTaskSampleHitsArray[4];
    time_T tArray[2];
  } Timing;
};

/* Block parameters (default storage) */
extern P_rpend_devdriv_T rpend_devdriv_P;

/* Block signals (default storage) */
extern B_rpend_devdriv_T rpend_devdriv_B;

/* Block states (default storage) */
extern DW_rpend_devdriv_T rpend_devdriv_DW;

/* Model entry point functions */
extern void rpend_devdriv_initialize(void);
extern void rpend_devdriv_step(void);
extern void rpend_devdriv_terminate(void);

/* Real-time Model object */
extern RT_MODEL_rpend_devdriv_T *const rpend_devdriv_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'rpend_devdriv'
 * '<S1>'   : 'rpend_devdriv/RP Driver'
 * '<S2>'   : 'rpend_devdriv/Signal Builder1'
 * '<S3>'   : 'rpend_devdriv/Signal Builder2'
 * '<S4>'   : 'rpend_devdriv/Signal Builder3'
 * '<S5>'   : 'rpend_devdriv/RP Driver/Alfa Normalization'
 */
#endif                                 /* RTW_HEADER_rpend_devdriv_h_ */
