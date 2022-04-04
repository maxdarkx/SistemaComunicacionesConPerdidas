#ifndef RTW_HEADER_modPSK_acc_h_
#define RTW_HEADER_modPSK_acc_h_
#ifndef modPSK_acc_COMMON_INCLUDES_
#define modPSK_acc_COMMON_INCLUDES_
#include <stdlib.h>
#define S_FUNCTION_NAME simulink_only_sfcn
#define S_FUNCTION_LEVEL 2
#ifndef RTW_GENERATED_S_FUNCTION
#define RTW_GENERATED_S_FUNCTION
#endif
#include "sl_AsyncioQueue/AsyncioQueueCAPI.h"
#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
#endif
#include "modPSK_acc_types.h"
#include "mwmathutil.h"
#include <stddef.h>
#include <float.h>
#include "rt_defines.h"
#include "simstruc_types.h"
typedef struct { real_T B_0_0_0 ; } B_SampleandHold_modPSK_T ; typedef struct
{ int32_T SampleandHold_sysIdxToRun ; int8_T SampleandHold_SubsysRanBC ;
char_T pad_SampleandHold_SubsysRanBC [ 3 ] ; } DW_SampleandHold_modPSK_T ;
typedef struct { ZCSigState SampleandHold_Trig_ZCE ; }
ZCE_SampleandHold_modPSK_T ; typedef struct { boolean_T B_5_0_0 ; char_T
pad_B_5_0_0 [ 7 ] ; } B_NEGATIVEEdge_modPSK_T ; typedef struct { int32_T
NEGATIVEEdge_sysIdxToRun ; int8_T NEGATIVEEdge_SubsysRanBC ; boolean_T
NEGATIVEEdge_MODE ; char_T pad_NEGATIVEEdge_MODE [ 2 ] ; }
DW_NEGATIVEEdge_modPSK_T ; typedef struct { boolean_T B_6_0_0 ; char_T
pad_B_6_0_0 [ 7 ] ; } B_POSITIVEEdge_modPSK_T ; typedef struct { int32_T
POSITIVEEdge_sysIdxToRun ; int8_T POSITIVEEdge_SubsysRanBC ; boolean_T
POSITIVEEdge_MODE ; char_T pad_POSITIVEEdge_MODE [ 2 ] ; }
DW_POSITIVEEdge_modPSK_T ; typedef struct { real_T B_13_0_0 ; real_T B_13_1_0
; real_T B_13_2_0 ; real_T B_13_3_0 ; real_T B_13_4_0 ; real_T B_13_5_0 ;
real_T B_13_6_0 ; real_T B_13_7_0 ; real_T B_13_8_0 ; real_T B_13_9_0 ;
real_T B_13_12_0 ; real_T B_13_14_0 ; real_T B_13_15_0 ; real_T B_13_19_0 ;
real_T B_13_20_0 ; real_T B_13_22_0 ; real_T B_13_24_0 ; real_T B_13_26_0 ;
real_T B_13_28_0 ; real_T B_13_30_0 ; real_T B_13_32_0 ; real_T B_13_34_0 ;
real_T B_13_36_0 ; real_T B_13_38_0 ; real_T B_13_40_0 ; real_T B_13_44_0 ;
real_T B_13_45_0 ; real_T B_13_52_0 ; real_T B_13_53_0 ; real_T B_13_54_0 ;
real_T B_13_57_0 ; real_T B_13_62_0 ; real_T B_13_64_0 ; real_T B_13_66_0 ;
real_T B_13_69_0 ; real_T B_13_71_0 ; real_T B_13_74_0 ; real_T B_13_75_0 ;
real_T B_13_76_0 ; real_T B_13_77_0 ; real_T B_13_78_0 ; real_T B_13_79_0 ;
real_T B_13_80_0 ; real_T B_13_81_0 ; real_T B_13_83_0 ; real_T B_13_86_0 ;
real_T B_13_87_0 ; real_T B_13_88_0 ; real_T B_13_89_0 ; real_T B_13_90_0 ;
real_T B_13_94_0 ; real_T B_13_99_0 ; real_T B_13_100_0 ; real_T B_13_101_0 ;
real_T B_13_103_0 ; real_T B_13_107_0 ; real_T B_13_112_0 ; real_T B_13_113_0
; real_T B_13_117_0 ; real_T B_13_119_0 ; real_T B_13_124_0 ; real_T
B_13_126_0 ; real_T B_13_129_0 ; real_T B_13_0_0_m ; real_T B_13_1_0_c ;
real_T B_13_2_0_k ; real_T B_13_3_0_c ; real_T B_13_4_0_b ; real_T B_13_5_0_p
; real_T B_13_6_0_c ; real_T B_13_7_0_f ; real_T B_13_8_0_g ; real_T
B_13_9_0_g ; real_T B_13_10_0 ; real_T B_13_11_0 ; real_T B_13_12_0_m ;
real_T B_13_13_0 ; real_T B_13_14_0_n ; real_T B_13_15_0_p ; real_T B_13_16_0
; real_T B_13_21_0 [ 2 ] ; real_T B_13_22_0_l ; real_T B_13_23_0 ; real_T
B_13_24_0_j ; real_T B_13_25_0 ; real_T B_13_26_0_d ; real_T B_13_27_0 ;
real_T B_13_28_0_g ; real_T B_13_29_0 ; real_T B_13_30_0_l ; real_T B_13_31_0
; real_T B_13_36_0_d [ 2 ] ; real_T B_13_37_0 ; real_T B_13_42_0 [ 2 ] ;
real_T B_13_43_0 ; real_T B_9_0_0 ; boolean_T B_13_18_0 ; boolean_T B_13_46_0
; boolean_T B_13_47_0 ; boolean_T B_13_50_0 ; boolean_T B_13_56_0 ; boolean_T
B_13_93_0 ; boolean_T B_13_102_0 ; boolean_T B_13_106_0 ; boolean_T
B_13_115_0 ; boolean_T B_4_0_0 ; boolean_T B_4_1_0 ; boolean_T B_3_0_0 ;
boolean_T B_2_0_0 ; char_T pad_B_2_0_0 [ 3 ] ; B_SampleandHold_modPSK_T
SampleandHold2 ; B_POSITIVEEdge_modPSK_T POSITIVEEdge_c ;
B_NEGATIVEEdge_modPSK_T NEGATIVEEdge_g ; B_POSITIVEEdge_modPSK_T
POSITIVEEdge_l ; B_NEGATIVEEdge_modPSK_T NEGATIVEEdge_f ;
B_SampleandHold_modPSK_T SampleandHold ; } B_modPSK_T ; typedef struct {
real_T ICic_PreviousInput ; real_T Memory_PreviousInput ; real_T
ICic_PreviousInput_c ; real_T Memory_PreviousInput_p ; real_T
ICic_PreviousInput_f ; struct { real_T modelTStart ; } TransportDelay_RWORK ;
struct { real_T modelTStart ; } TransportDelay_RWORK_o ; struct { real_T
modelTStart ; } TransportDelay_RWORK_h ; struct { real_T modelTStart ; }
TransportDelay2_RWORK ; struct { real_T modelTStart ; } TransportDelay1_RWORK
; struct { real_T modelTStart ; } TransportDelay4_RWORK ; struct { real_T
modelTStart ; } TransportDelay3_RWORK ; struct { real_T modelTStart ; }
TransportDelay6_RWORK ; struct { real_T modelTStart ; } TransportDelay5_RWORK
; struct { real_T modelTStart ; } TransportDelay8_RWORK ; struct { real_T
modelTStart ; } TransportDelay7_RWORK ; struct { real_T modelTStart ; }
TransportDelay9_RWORK ; struct { real_T modelTStart ; }
TransportDelay11_RWORK ; struct { real_T modelTStart ; }
TransportDelay10_RWORK ; struct { real_T modelTStart ; }
TransportDelay13_RWORK ; void * FromWorkspace_PWORK [ 3 ] ; struct { void *
TUbufferPtrs [ 2 ] ; } TransportDelay_PWORK ; struct { void * TUbufferPtrs [
2 ] ; } TransportDelay_PWORK_p ; struct { void * TUbufferPtrs [ 2 ] ; }
TransportDelay_PWORK_k ; struct { void * TUbufferPtrs [ 2 ] ; }
TransportDelay2_PWORK ; struct { void * TUbufferPtrs [ 2 ] ; }
TransportDelay1_PWORK ; struct { void * TUbufferPtrs [ 2 ] ; }
TransportDelay4_PWORK ; struct { void * TUbufferPtrs [ 2 ] ; }
TransportDelay3_PWORK ; struct { void * TUbufferPtrs [ 2 ] ; }
TransportDelay6_PWORK ; struct { void * TUbufferPtrs [ 2 ] ; }
TransportDelay5_PWORK ; struct { void * TUbufferPtrs [ 2 ] ; }
TransportDelay8_PWORK ; struct { void * TUbufferPtrs [ 2 ] ; }
TransportDelay7_PWORK ; struct { void * TUbufferPtrs [ 2 ] ; }
TransportDelay9_PWORK ; struct { void * TUbufferPtrs [ 2 ] ; }
TransportDelay11_PWORK ; struct { void * TUbufferPtrs [ 2 ] ; }
TransportDelay10_PWORK ; struct { void * TUbufferPtrs [ 2 ] ; }
TransportDelay13_PWORK ; void * DatosFinales_PWORK [ 8 ] ; void * Canal_PWORK
[ 3 ] ; void * Scope_PWORK [ 3 ] ; void * Scope_PWORK_o [ 2 ] ; void *
Scope_PWORK_p [ 4 ] ; void * Scope1_PWORK [ 5 ] ; void * Scope1_PWORK_n [ 4 ]
; struct { void * AQHandles ; }
TAQSigLogging_InsertedFor_Sign_at_outport_0_PWORK ; void * Transmisor_PWORK [
3 ] ; struct { void * AQHandles ; }
_asyncqueue_inserted_for_ToWorkspace_PWORK ; struct { void * AQHandles ; }
_asyncqueue_inserted_for_ToWorkspace_PWORK_e ; int32_T
TriggeredToWorkspace1_sysIdxToRun ; int32_T TriggeredToWorkspace_sysIdxToRun
; int32_T SampleandHold_sysIdxToRun ; int32_T DFlipFlop_sysIdxToRun ; int32_T
POSITIVEEdge_sysIdxToRun ; int32_T NEGATIVEEdge_sysIdxToRun ; int32_T
TriggeredSubsystem_sysIdxToRun ; int_T FromWorkspace_IWORK ; struct { int_T
Tail ; int_T Head ; int_T Last ; int_T CircularBufSize ; int_T MaxNewBufSize
; } TransportDelay_IWORK ; struct { int_T Tail ; int_T Head ; int_T Last ;
int_T CircularBufSize ; int_T MaxNewBufSize ; } TransportDelay_IWORK_k ;
struct { int_T Tail ; int_T Head ; int_T Last ; int_T CircularBufSize ; int_T
MaxNewBufSize ; } TransportDelay_IWORK_m ; struct { int_T Tail ; int_T Head ;
int_T Last ; int_T CircularBufSize ; int_T MaxNewBufSize ; }
TransportDelay2_IWORK ; struct { int_T Tail ; int_T Head ; int_T Last ; int_T
CircularBufSize ; int_T MaxNewBufSize ; } TransportDelay1_IWORK ; struct {
int_T Tail ; int_T Head ; int_T Last ; int_T CircularBufSize ; int_T
MaxNewBufSize ; } TransportDelay4_IWORK ; struct { int_T Tail ; int_T Head ;
int_T Last ; int_T CircularBufSize ; int_T MaxNewBufSize ; }
TransportDelay3_IWORK ; struct { int_T Tail ; int_T Head ; int_T Last ; int_T
CircularBufSize ; int_T MaxNewBufSize ; } TransportDelay6_IWORK ; struct {
int_T Tail ; int_T Head ; int_T Last ; int_T CircularBufSize ; int_T
MaxNewBufSize ; } TransportDelay5_IWORK ; struct { int_T Tail ; int_T Head ;
int_T Last ; int_T CircularBufSize ; int_T MaxNewBufSize ; }
TransportDelay8_IWORK ; struct { int_T Tail ; int_T Head ; int_T Last ; int_T
CircularBufSize ; int_T MaxNewBufSize ; } TransportDelay7_IWORK ; struct {
int_T Tail ; int_T Head ; int_T Last ; int_T CircularBufSize ; int_T
MaxNewBufSize ; } TransportDelay9_IWORK ; struct { int_T Tail ; int_T Head ;
int_T Last ; int_T CircularBufSize ; int_T MaxNewBufSize ; }
TransportDelay11_IWORK ; struct { int_T Tail ; int_T Head ; int_T Last ;
int_T CircularBufSize ; int_T MaxNewBufSize ; } TransportDelay10_IWORK ;
struct { int_T Tail ; int_T Head ; int_T Last ; int_T CircularBufSize ; int_T
MaxNewBufSize ; } TransportDelay13_IWORK ; int8_T
TriggeredToWorkspace1_SubsysRanBC ; int8_T TriggeredToWorkspace_SubsysRanBC ;
int8_T SampleandHold_SubsysRanBC ; int8_T DFlipFlop_SubsysRanBC ; int8_T
POSITIVEEdge_SubsysRanBC ; int8_T NEGATIVEEdge_SubsysRanBC ; int8_T
TriggeredSubsystem_SubsysRanBC ; boolean_T Memory_PreviousInput_k ; boolean_T
Memory_PreviousInput_o ; boolean_T TmpLatchAtDFlipFlopInport1_PreviousInput ;
boolean_T Memory_PreviousInput_a ; boolean_T Memory_PreviousInput_ab ;
boolean_T DFlipFlop_MODE ; boolean_T POSITIVEEdge_MODE ; boolean_T
NEGATIVEEdge_MODE ; char_T pad_NEGATIVEEdge_MODE [ 5 ] ;
DW_SampleandHold_modPSK_T SampleandHold2 ; DW_POSITIVEEdge_modPSK_T
POSITIVEEdge_c ; DW_NEGATIVEEdge_modPSK_T NEGATIVEEdge_g ;
DW_POSITIVEEdge_modPSK_T POSITIVEEdge_l ; DW_NEGATIVEEdge_modPSK_T
NEGATIVEEdge_f ; DW_SampleandHold_modPSK_T SampleandHold ; } DW_modPSK_T ;
typedef struct { real_T AnalogFilterDesign_CSTATE [ 4 ] ; real_T
AnalogFilterDesign_CSTATE_f [ 4 ] ; real_T Integrator_CSTATE ; real_T
ModuloIntegrator_CSTATE ; real_T AnalogFilterDesign_CSTATE_e [ 4 ] ; real_T
AnalogFilterDesign_CSTATE_p [ 8 ] ; real_T ModuloIntegrator_CSTATE_p ; real_T
Integrator_CSTATE_d ; real_T Integrator1_CSTATE ; real_T Integrator_CSTATE_p
; } X_modPSK_T ; typedef int_T PeriodicIndX_modPSK_T [ 2 ] ; typedef real_T
PeriodicRngX_modPSK_T [ 4 ] ; typedef struct { real_T
AnalogFilterDesign_CSTATE [ 4 ] ; real_T AnalogFilterDesign_CSTATE_f [ 4 ] ;
real_T Integrator_CSTATE ; real_T ModuloIntegrator_CSTATE ; real_T
AnalogFilterDesign_CSTATE_e [ 4 ] ; real_T AnalogFilterDesign_CSTATE_p [ 8 ]
; real_T ModuloIntegrator_CSTATE_p ; real_T Integrator_CSTATE_d ; real_T
Integrator1_CSTATE ; real_T Integrator_CSTATE_p ; } XDot_modPSK_T ; typedef
struct { boolean_T AnalogFilterDesign_CSTATE [ 4 ] ; boolean_T
AnalogFilterDesign_CSTATE_f [ 4 ] ; boolean_T Integrator_CSTATE ; boolean_T
ModuloIntegrator_CSTATE ; boolean_T AnalogFilterDesign_CSTATE_e [ 4 ] ;
boolean_T AnalogFilterDesign_CSTATE_p [ 8 ] ; boolean_T
ModuloIntegrator_CSTATE_p ; boolean_T Integrator_CSTATE_d ; boolean_T
Integrator1_CSTATE ; boolean_T Integrator_CSTATE_p ; } XDis_modPSK_T ;
typedef struct { real_T AnalogFilterDesign_CSTATE [ 4 ] ; real_T
AnalogFilterDesign_CSTATE_f [ 4 ] ; real_T Integrator_CSTATE ; real_T
ModuloIntegrator_CSTATE ; real_T AnalogFilterDesign_CSTATE_e [ 4 ] ; real_T
AnalogFilterDesign_CSTATE_p [ 8 ] ; real_T ModuloIntegrator_CSTATE_p ; real_T
Integrator_CSTATE_d ; real_T Integrator1_CSTATE ; real_T Integrator_CSTATE_p
; } CStateAbsTol_modPSK_T ; typedef struct { real_T AnalogFilterDesign_CSTATE
[ 4 ] ; real_T AnalogFilterDesign_CSTATE_f [ 4 ] ; real_T Integrator_CSTATE ;
real_T ModuloIntegrator_CSTATE ; real_T AnalogFilterDesign_CSTATE_e [ 4 ] ;
real_T AnalogFilterDesign_CSTATE_p [ 8 ] ; real_T ModuloIntegrator_CSTATE_p ;
real_T Integrator_CSTATE_d ; real_T Integrator1_CSTATE ; real_T
Integrator_CSTATE_p ; } CXPtMin_modPSK_T ; typedef struct { real_T
AnalogFilterDesign_CSTATE [ 4 ] ; real_T AnalogFilterDesign_CSTATE_f [ 4 ] ;
real_T Integrator_CSTATE ; real_T ModuloIntegrator_CSTATE ; real_T
AnalogFilterDesign_CSTATE_e [ 4 ] ; real_T AnalogFilterDesign_CSTATE_p [ 8 ]
; real_T ModuloIntegrator_CSTATE_p ; real_T Integrator_CSTATE_d ; real_T
Integrator1_CSTATE ; real_T Integrator_CSTATE_p ; } CXPtMax_modPSK_T ;
typedef struct { ZCSigState Integrator_Reset_ZCE ; ZCSigState
Integrator1_Reset_ZCE ; ZCSigState Integrator_Reset_ZCE_c ; ZCSigState
TriggeredToWorkspace1_Trig_ZCE ; ZCSigState TriggeredToWorkspace_Trig_ZCE ;
ZCE_SampleandHold_modPSK_T SampleandHold2 ; ZCSigState
SampleandHold_Trig_ZCE_a ; ZCSigState DFlipFlop_Trig_ZCE ; ZCSigState
TriggeredSubsystem_Trig_ZCE ; ZCE_SampleandHold_modPSK_T SampleandHold ; }
PrevZCX_modPSK_T ; struct P_SampleandHold_modPSK_T_ { real_T P_0 ; } ; struct
P_NEGATIVEEdge_modPSK_T_ { boolean_T P_0 ; char_T pad_P_0 [ 7 ] ; } ; struct
P_POSITIVEEdge_modPSK_T_ { boolean_T P_0 ; char_T pad_P_0 [ 7 ] ; } ; struct
P_modPSK_T_ { real_T P_0 ; real_T P_1 ; real_T P_2 [ 7 ] ; real_T P_3 ;
real_T P_4 ; real_T P_5 ; real_T P_6 ; real_T P_7 ; real_T P_8 [ 7 ] ; real_T
P_9 ; real_T P_10 ; real_T P_11 ; real_T P_12 ; real_T P_13 ; real_T P_14 ;
real_T P_15 ; real_T P_16 ; real_T P_17 ; real_T P_18 ; real_T P_19 ; real_T
P_20 ; real_T P_21 ; real_T P_22 ; real_T P_23 ; real_T P_24 ; real_T P_25 ;
real_T P_26 ; real_T P_27 ; real_T P_28 ; real_T P_29 ; real_T P_30 ; real_T
P_31 ; real_T P_32 ; real_T P_33 ; real_T P_34 ; real_T P_35 ; real_T P_36 ;
real_T P_37 ; real_T P_38 ; real_T P_39 ; real_T P_40 ; real_T P_41 ; real_T
P_42 ; real_T P_43 ; real_T P_44 ; real_T P_45 ; real_T P_46 ; real_T P_47 [
7 ] ; real_T P_48 ; real_T P_49 ; real_T P_50 ; real_T P_51 [ 15 ] ; real_T
P_52 ; real_T P_53 ; real_T P_54 ; real_T P_55 ; real_T P_56 ; real_T P_57 ;
real_T P_58 ; real_T P_59 ; real_T P_60 ; real_T P_61 ; real_T P_62 ; real_T
P_63 ; real_T P_64 ; real_T P_65 ; real_T P_66 ; real_T P_67 ; real_T P_68 ;
real_T P_69 ; real_T P_70 ; real_T P_71 ; real_T P_72 ; real_T P_73 ; real_T
P_74 ; real_T P_75 ; real_T P_76 ; real_T P_77 ; real_T P_78 ; real_T P_79 ;
real_T P_80 ; real_T P_81 ; real_T P_82 ; real_T P_83 ; real_T P_84 ; real_T
P_85 ; real_T P_86 ; real_T P_87 ; real_T P_88 ; real_T P_89 ; real_T P_90 ;
real_T P_91 [ 2 ] ; real_T P_92 [ 2 ] ; real_T P_93 [ 2 ] ; real_T P_94 ;
real_T P_95 ; real_T P_96 ; real_T P_97 ; real_T P_98 ; real_T P_99 ; real_T
P_100 ; real_T P_101 ; real_T P_102 ; real_T P_103 ; real_T P_104 ; real_T
P_105 [ 2 ] ; real_T P_106 [ 2 ] ; real_T P_107 [ 2 ] ; real_T P_108 ; real_T
P_109 ; real_T P_110 [ 2 ] ; real_T P_111 [ 2 ] ; real_T P_112 [ 2 ] ; real_T
P_113 ; uint32_T P_114 [ 7 ] ; uint32_T P_115 [ 5 ] ; uint32_T P_116 ;
uint32_T P_117 [ 2 ] ; uint32_T P_118 ; uint32_T P_119 [ 5 ] ; uint32_T P_120
[ 7 ] ; uint32_T P_121 [ 5 ] ; uint32_T P_122 ; uint32_T P_123 [ 2 ] ;
uint32_T P_124 ; uint32_T P_125 [ 5 ] ; uint32_T P_126 [ 7 ] ; uint32_T P_127
[ 5 ] ; uint32_T P_128 ; uint32_T P_129 [ 2 ] ; uint32_T P_130 ; uint32_T
P_131 [ 5 ] ; uint32_T P_132 [ 15 ] ; uint32_T P_133 [ 9 ] ; uint32_T P_134 ;
uint32_T P_135 [ 2 ] ; uint32_T P_136 ; uint32_T P_137 [ 9 ] ; boolean_T
P_138 ; boolean_T P_139 ; boolean_T P_140 ; boolean_T P_141 ; boolean_T P_142
; boolean_T P_143 ; boolean_T P_144 ; boolean_T P_145 ; boolean_T P_146 ;
char_T pad_P_146 [ 7 ] ; P_SampleandHold_modPSK_T SampleandHold2 ;
P_POSITIVEEdge_modPSK_T POSITIVEEdge_c ; P_NEGATIVEEdge_modPSK_T
NEGATIVEEdge_g ; P_POSITIVEEdge_modPSK_T POSITIVEEdge_l ;
P_NEGATIVEEdge_modPSK_T NEGATIVEEdge_f ; P_SampleandHold_modPSK_T
SampleandHold ; } ; extern P_modPSK_T modPSK_rtDefaultP ;
#endif
