#include "modPSK_acc.h"
#include "rtwtypes.h"
#include "modPSK_acc_private.h"
#include "mwmathutil.h"
#include "multiword_types.h"
#include "simstruc_types.h"
#include <stdio.h>
#include "slexec_vm_simstruct_bridge.h"
#include "slexec_vm_zc_functions.h"
#include "slexec_vm_lookup_functions.h"
#include "slsv_diagnostic_codegen_c_api.h"
#include "simtarget/slSimTgtMdlrefSfcnBridge.h"
#include "simstruc.h"
#include "fixedpoint.h"
#define CodeFormat S-Function
#define AccDefine1 Accelerator_S-Function
#include "simtarget/slAccSfcnBridge.h"
#ifndef __RTW_UTFREE__  
extern void * utMalloc ( size_t ) ; extern void utFree ( void * ) ;
#endif
boolean_T modPSK_acc_rt_TDelayUpdateTailOrGrowBuf ( int_T * bufSzPtr , int_T
* tailPtr , int_T * headPtr , int_T * lastPtr , real_T tMinusDelay , real_T *
* uBufPtr , boolean_T isfixedbuf , boolean_T istransportdelay , int_T *
maxNewBufSzPtr ) { int_T testIdx ; int_T tail = * tailPtr ; int_T bufSz = *
bufSzPtr ; real_T * tBuf = * uBufPtr + bufSz ; real_T * xBuf = ( NULL ) ;
int_T numBuffer = 2 ; if ( istransportdelay ) { numBuffer = 3 ; xBuf = *
uBufPtr + 2 * bufSz ; } testIdx = ( tail < ( bufSz - 1 ) ) ? ( tail + 1 ) : 0
; if ( ( tMinusDelay <= tBuf [ testIdx ] ) && ! isfixedbuf ) { int_T j ;
real_T * tempT ; real_T * tempU ; real_T * tempX = ( NULL ) ; real_T * uBuf =
* uBufPtr ; int_T newBufSz = bufSz + 1024 ; if ( newBufSz > * maxNewBufSzPtr
) { * maxNewBufSzPtr = newBufSz ; } tempU = ( real_T * ) utMalloc ( numBuffer
* newBufSz * sizeof ( real_T ) ) ; if ( tempU == ( NULL ) ) { return ( false
) ; } tempT = tempU + newBufSz ; if ( istransportdelay ) tempX = tempT +
newBufSz ; for ( j = tail ; j < bufSz ; j ++ ) { tempT [ j - tail ] = tBuf [
j ] ; tempU [ j - tail ] = uBuf [ j ] ; if ( istransportdelay ) tempX [ j -
tail ] = xBuf [ j ] ; } for ( j = 0 ; j < tail ; j ++ ) { tempT [ j + bufSz -
tail ] = tBuf [ j ] ; tempU [ j + bufSz - tail ] = uBuf [ j ] ; if (
istransportdelay ) tempX [ j + bufSz - tail ] = xBuf [ j ] ; } if ( * lastPtr
> tail ) { * lastPtr -= tail ; } else { * lastPtr += ( bufSz - tail ) ; } *
tailPtr = 0 ; * headPtr = bufSz ; utFree ( uBuf ) ; * bufSzPtr = newBufSz ; *
uBufPtr = tempU ; } else { * tailPtr = testIdx ; } return ( true ) ; } real_T
modPSK_acc_rt_TDelayInterpolate ( real_T tMinusDelay , real_T tStart , real_T
* uBuf , int_T bufSz , int_T * lastIdx , int_T oldestIdx , int_T newIdx ,
real_T initOutput , boolean_T discrete , boolean_T
minorStepAndTAtLastMajorOutput ) { int_T i ; real_T yout , t1 , t2 , u1 , u2
; real_T * tBuf = uBuf + bufSz ; if ( ( newIdx == 0 ) && ( oldestIdx == 0 )
&& ( tMinusDelay > tStart ) ) return initOutput ; if ( tMinusDelay <= tStart
) return initOutput ; if ( ( tMinusDelay <= tBuf [ oldestIdx ] ) ) { if (
discrete ) { return ( uBuf [ oldestIdx ] ) ; } else { int_T tempIdx =
oldestIdx + 1 ; if ( oldestIdx == bufSz - 1 ) tempIdx = 0 ; t1 = tBuf [
oldestIdx ] ; t2 = tBuf [ tempIdx ] ; u1 = uBuf [ oldestIdx ] ; u2 = uBuf [
tempIdx ] ; if ( t2 == t1 ) { if ( tMinusDelay >= t2 ) { yout = u2 ; } else {
yout = u1 ; } } else { real_T f1 = ( t2 - tMinusDelay ) / ( t2 - t1 ) ;
real_T f2 = 1.0 - f1 ; yout = f1 * u1 + f2 * u2 ; } return yout ; } } if (
minorStepAndTAtLastMajorOutput ) { if ( newIdx != 0 ) { if ( * lastIdx ==
newIdx ) { ( * lastIdx ) -- ; } newIdx -- ; } else { if ( * lastIdx == newIdx
) { * lastIdx = bufSz - 1 ; } newIdx = bufSz - 1 ; } } i = * lastIdx ; if (
tBuf [ i ] < tMinusDelay ) { while ( tBuf [ i ] < tMinusDelay ) { if ( i ==
newIdx ) break ; i = ( i < ( bufSz - 1 ) ) ? ( i + 1 ) : 0 ; } } else { while
( tBuf [ i ] >= tMinusDelay ) { i = ( i > 0 ) ? i - 1 : ( bufSz - 1 ) ; } i =
( i < ( bufSz - 1 ) ) ? ( i + 1 ) : 0 ; } * lastIdx = i ; if ( discrete ) {
double tempEps = ( DBL_EPSILON ) * 128.0 ; double localEps = tempEps *
muDoubleScalarAbs ( tBuf [ i ] ) ; if ( tempEps > localEps ) { localEps =
tempEps ; } localEps = localEps / 2.0 ; if ( tMinusDelay >= ( tBuf [ i ] -
localEps ) ) { yout = uBuf [ i ] ; } else { if ( i == 0 ) { yout = uBuf [
bufSz - 1 ] ; } else { yout = uBuf [ i - 1 ] ; } } } else { if ( i == 0 ) {
t1 = tBuf [ bufSz - 1 ] ; u1 = uBuf [ bufSz - 1 ] ; } else { t1 = tBuf [ i -
1 ] ; u1 = uBuf [ i - 1 ] ; } t2 = tBuf [ i ] ; u2 = uBuf [ i ] ; if ( t2 ==
t1 ) { if ( tMinusDelay >= t2 ) { yout = u2 ; } else { yout = u1 ; } } else {
real_T f1 = ( t2 - tMinusDelay ) / ( t2 - t1 ) ; real_T f2 = 1.0 - f1 ; yout
= f1 * u1 + f2 * u2 ; } } return ( yout ) ; } void rt_ssGetBlockPath (
SimStruct * S , int_T sysIdx , int_T blkIdx , char_T * * path ) {
_ssGetBlockPath ( S , sysIdx , blkIdx , path ) ; } void rt_ssSet_slErrMsg (
void * S , void * diag ) { SimStruct * castedS = ( SimStruct * ) S ; if ( !
_ssIsErrorStatusAslErrMsg ( castedS ) ) { _ssSet_slErrMsg ( castedS , diag )
; } else { _ssDiscardDiagnostic ( castedS , diag ) ; } } void
rt_ssReportDiagnosticAsWarning ( void * S , void * diag ) {
_ssReportDiagnosticAsWarning ( ( SimStruct * ) S , diag ) ; } void
rt_ssReportDiagnosticAsInfo ( void * S , void * diag ) {
_ssReportDiagnosticAsInfo ( ( SimStruct * ) S , diag ) ; } void
modPSK_SampleandHold_Init ( SimStruct * S , B_SampleandHold_modPSK_T * localB
, P_SampleandHold_modPSK_T * localP ) { localB -> B_0_0_0 = localP -> P_0 ; }
void modPSK_SampleandHold ( SimStruct * S , real_T rtu_Trigger , real_T
rtu_In , B_SampleandHold_modPSK_T * localB , DW_SampleandHold_modPSK_T *
localDW , ZCE_SampleandHold_modPSK_T * localZCE ) { ZCEventType zcEvent ; if
( ssIsModeUpdateTimeStep ( S ) ) { zcEvent = rt_ZCFcn ( RISING_ZERO_CROSSING
, & localZCE -> SampleandHold_Trig_ZCE , rtu_Trigger ) ; if ( zcEvent !=
NO_ZCEVENT ) { localB -> B_0_0_0 = rtu_In ; localDW ->
SampleandHold_SubsysRanBC = 4 ; } } } void modPSK_SampleandHold_Term (
SimStruct * const S ) { } void modPSK_NEGATIVEEdge_Init ( SimStruct * S ,
B_NEGATIVEEdge_modPSK_T * localB , P_NEGATIVEEdge_modPSK_T * localP ) {
localB -> B_5_0_0 = localP -> P_0 ; } void modPSK_NEGATIVEEdge_Disable (
SimStruct * S , DW_NEGATIVEEdge_modPSK_T * localDW ) { localDW ->
NEGATIVEEdge_MODE = false ; } void modPSK_NEGATIVEEdge ( SimStruct * S ,
real_T rtu_Enable , real_T rtu_IN , real_T rtu_INprevious ,
B_NEGATIVEEdge_modPSK_T * localB , DW_NEGATIVEEdge_modPSK_T * localDW ) {
int32_T isHit ; isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( ( isHit != 0 ) &&
ssIsModeUpdateTimeStep ( S ) ) { if ( rtu_Enable > 0.0 ) { if ( ! localDW ->
NEGATIVEEdge_MODE ) { if ( ssGetTaskTime ( S , 1 ) != ssGetTStart ( S ) ) {
ssSetBlockStateForSolverChangedAtMajorStep ( S ) ; } localDW ->
NEGATIVEEdge_MODE = true ; } } else if ( localDW -> NEGATIVEEdge_MODE ) {
ssSetBlockStateForSolverChangedAtMajorStep ( S ) ;
modPSK_NEGATIVEEdge_Disable ( S , localDW ) ; } } if ( localDW ->
NEGATIVEEdge_MODE ) { localB -> B_5_0_0 = ( rtu_INprevious > rtu_IN ) ; if (
ssIsModeUpdateTimeStep ( S ) ) { srUpdateBC ( localDW ->
NEGATIVEEdge_SubsysRanBC ) ; } } } void modPSK_NEGATIVEEdge_Term ( SimStruct
* const S ) { } void modPSK_POSITIVEEdge_Init ( SimStruct * S ,
B_POSITIVEEdge_modPSK_T * localB , P_POSITIVEEdge_modPSK_T * localP ) {
localB -> B_6_0_0 = localP -> P_0 ; } void modPSK_POSITIVEEdge_Disable (
SimStruct * S , DW_POSITIVEEdge_modPSK_T * localDW ) { localDW ->
POSITIVEEdge_MODE = false ; } void modPSK_POSITIVEEdge ( SimStruct * S ,
real_T rtu_Enable , real_T rtu_IN , real_T rtu_INprevious ,
B_POSITIVEEdge_modPSK_T * localB , DW_POSITIVEEdge_modPSK_T * localDW ) {
int32_T isHit ; isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( ( isHit != 0 ) &&
ssIsModeUpdateTimeStep ( S ) ) { if ( rtu_Enable > 0.0 ) { if ( ! localDW ->
POSITIVEEdge_MODE ) { if ( ssGetTaskTime ( S , 1 ) != ssGetTStart ( S ) ) {
ssSetBlockStateForSolverChangedAtMajorStep ( S ) ; } localDW ->
POSITIVEEdge_MODE = true ; } } else if ( localDW -> POSITIVEEdge_MODE ) {
ssSetBlockStateForSolverChangedAtMajorStep ( S ) ;
modPSK_POSITIVEEdge_Disable ( S , localDW ) ; } } if ( localDW ->
POSITIVEEdge_MODE ) { localB -> B_6_0_0 = ( rtu_IN > rtu_INprevious ) ; if (
ssIsModeUpdateTimeStep ( S ) ) { srUpdateBC ( localDW ->
POSITIVEEdge_SubsysRanBC ) ; } } } void modPSK_POSITIVEEdge_Term ( SimStruct
* const S ) { } static void mdlOutputs ( SimStruct * S , int_T tid ) { real_T
B_13_42_0 ; B_modPSK_T * _rtB ; DW_modPSK_T * _rtDW ; P_modPSK_T * _rtP ;
PrevZCX_modPSK_T * _rtZCE ; X_modPSK_T * _rtX ; real_T rtb_B_13_16_0 ; real_T
rtb_B_13_21_0 ; real_T rtb_B_13_23_0 ; real_T rtb_B_13_25_0 ; real_T
rtb_B_13_27_0 ; real_T rtb_B_13_29_0 ; real_T rtb_B_13_31_0 ; real_T
rtb_B_13_33_0 ; real_T rtb_B_13_35_0 ; real_T rtb_B_13_37_0 ; real_T
rtb_B_13_39_0 ; real_T rtb_B_13_41_0 ; int32_T isHit ; uint32_T ri ;
boolean_T rtb_B_13_82_0 ; ZCEventType zcEvent ; _rtDW = ( ( DW_modPSK_T * )
ssGetRootDWork ( S ) ) ; _rtZCE = ( ( PrevZCX_modPSK_T * )
_ssGetPrevZCSigState ( S ) ) ; _rtX = ( ( X_modPSK_T * ) ssGetContStates ( S
) ) ; _rtP = ( ( P_modPSK_T * ) ssGetModelRtp ( S ) ) ; _rtB = ( ( B_modPSK_T
* ) _ssGetModelBlockIO ( S ) ) ; isHit = ssIsSampleHit ( S , 2 , 0 ) ; if (
isHit != 0 ) { ssCallAccelRunBlock ( S , 13 , 0 , SS_CALL_MDL_OUTPUTS ) ; }
_rtB -> B_13_1_0 = 0.0 ; for ( ri = _rtP -> P_119 [ 0U ] ; ri < _rtP -> P_119
[ 1U ] ; ri ++ ) { _rtB -> B_13_1_0 += _rtP -> P_4 * _rtX ->
AnalogFilterDesign_CSTATE [ 0U ] ; } for ( ri = _rtP -> P_119 [ 1U ] ; ri <
_rtP -> P_119 [ 2U ] ; ri ++ ) { _rtB -> B_13_1_0 += _rtP -> P_4 * _rtX ->
AnalogFilterDesign_CSTATE [ 1U ] ; } for ( ri = _rtP -> P_119 [ 2U ] ; ri <
_rtP -> P_119 [ 3U ] ; ri ++ ) { _rtB -> B_13_1_0 += _rtP -> P_4 * _rtX ->
AnalogFilterDesign_CSTATE [ 2U ] ; } for ( ri = _rtP -> P_119 [ 3U ] ; ri <
_rtP -> P_119 [ 4U ] ; ri ++ ) { _rtB -> B_13_1_0 += _rtP -> P_4 * _rtX ->
AnalogFilterDesign_CSTATE [ 3U ] ; } { real_T * * uBuffer = ( real_T * * ) &
_rtDW -> TransportDelay_PWORK . TUbufferPtrs [ 0 ] ; real_T simTime = ssGetT
( S ) ; real_T tMinusDelay = simTime - _rtP -> P_6 ; _rtB -> B_13_2_0 =
modPSK_acc_rt_TDelayInterpolate ( tMinusDelay , 0.0 , * uBuffer , _rtDW ->
TransportDelay_IWORK . CircularBufSize , & _rtDW -> TransportDelay_IWORK .
Last , _rtDW -> TransportDelay_IWORK . Tail , _rtDW -> TransportDelay_IWORK .
Head , _rtP -> P_7 , 0 , ( boolean_T ) ( ssIsMinorTimeStep ( S ) && ( ( *
uBuffer + _rtDW -> TransportDelay_IWORK . CircularBufSize ) [ _rtDW ->
TransportDelay_IWORK . Head ] == ssGetT ( S ) ) ) ) ; } _rtB -> B_13_3_0 =
_rtB -> B_13_2_0 * _rtB -> B_13_0_0_m ; _rtB -> B_13_4_0 = _rtB -> B_13_3_0 ;
_rtB -> B_13_5_0 = 0.0 ; for ( ri = _rtP -> P_125 [ 0U ] ; ri < _rtP -> P_125
[ 1U ] ; ri ++ ) { _rtB -> B_13_5_0 += _rtP -> P_10 * _rtX ->
AnalogFilterDesign_CSTATE_f [ 0U ] ; } for ( ri = _rtP -> P_125 [ 1U ] ; ri <
_rtP -> P_125 [ 2U ] ; ri ++ ) { _rtB -> B_13_5_0 += _rtP -> P_10 * _rtX ->
AnalogFilterDesign_CSTATE_f [ 1U ] ; } for ( ri = _rtP -> P_125 [ 2U ] ; ri <
_rtP -> P_125 [ 3U ] ; ri ++ ) { _rtB -> B_13_5_0 += _rtP -> P_10 * _rtX ->
AnalogFilterDesign_CSTATE_f [ 2U ] ; } for ( ri = _rtP -> P_125 [ 3U ] ; ri <
_rtP -> P_125 [ 4U ] ; ri ++ ) { _rtB -> B_13_5_0 += _rtP -> P_10 * _rtX ->
AnalogFilterDesign_CSTATE_f [ 3U ] ; } _rtB -> B_13_6_0 = _rtB -> B_13_23_0 *
_rtB -> B_13_5_0 ; { real_T * * uBuffer = ( real_T * * ) & _rtDW ->
TransportDelay_PWORK_p . TUbufferPtrs [ 0 ] ; real_T simTime = ssGetT ( S ) ;
real_T tMinusDelay = simTime - _rtP -> P_12 ; _rtB -> B_13_7_0 =
modPSK_acc_rt_TDelayInterpolate ( tMinusDelay , 0.0 , * uBuffer , _rtDW ->
TransportDelay_IWORK_k . CircularBufSize , & _rtDW -> TransportDelay_IWORK_k
. Last , _rtDW -> TransportDelay_IWORK_k . Tail , _rtDW ->
TransportDelay_IWORK_k . Head , _rtP -> P_13 , 0 , ( boolean_T ) (
ssIsMinorTimeStep ( S ) && ( ( * uBuffer + _rtDW -> TransportDelay_IWORK_k .
CircularBufSize ) [ _rtDW -> TransportDelay_IWORK_k . Head ] == ssGetT ( S )
) ) ) ; } if ( ssIsModeUpdateTimeStep ( S ) ) { zcEvent = rt_ZCFcn (
RISING_ZERO_CROSSING , & _rtZCE -> Integrator_Reset_ZCE , _rtB -> B_13_7_0 )
; if ( zcEvent != NO_ZCEVENT ) { _rtX -> Integrator_CSTATE = _rtP -> P_14 ;
ssSetBlockStateForSolverChangedAtMajorStep ( S ) ; } _rtB -> B_13_8_0 = _rtX
-> Integrator_CSTATE ; } else { _rtB -> B_13_8_0 = _rtX -> Integrator_CSTATE
; } _rtB -> B_13_9_0 = _rtX -> ModuloIntegrator_CSTATE ; _rtB -> B_13_12_0 =
muDoubleScalarSign ( muDoubleScalarCos ( _rtB -> B_13_9_0 *
6.2831853071795862 + 5.497787143782138 ) ) ; isHit = ssIsSampleHit ( S , 1 ,
0 ) ; if ( isHit != 0 ) { modPSK_SampleandHold ( S , _rtB -> B_13_12_0 , _rtB
-> B_13_8_0 , & _rtB -> SampleandHold , & _rtDW -> SampleandHold , & _rtZCE
-> SampleandHold ) ; _rtB -> B_13_14_0 = muDoubleScalarSign ( _rtB ->
SampleandHold . B_0_0_0 ) ; } { real_T * * uBuffer = ( real_T * * ) & _rtDW
-> TransportDelay_PWORK_k . TUbufferPtrs [ 0 ] ; real_T simTime = ssGetT ( S
) ; real_T tMinusDelay = simTime - _rtP -> P_18 ; _rtB -> B_13_15_0 =
modPSK_acc_rt_TDelayInterpolate ( tMinusDelay , 0.0 , * uBuffer , _rtDW ->
TransportDelay_IWORK_m . CircularBufSize , & _rtDW -> TransportDelay_IWORK_m
. Last , _rtDW -> TransportDelay_IWORK_m . Tail , _rtDW ->
TransportDelay_IWORK_m . Head , _rtP -> P_19 , 0 , ( boolean_T ) (
ssIsMinorTimeStep ( S ) && ( ( * uBuffer + _rtDW -> TransportDelay_IWORK_m .
CircularBufSize ) [ _rtDW -> TransportDelay_IWORK_m . Head ] == ssGetT ( S )
) ) ) ; } rtb_B_13_16_0 = ssGetT ( S ) ; isHit = ssIsSampleHit ( S , 1 , 0 )
; if ( isHit != 0 ) { _rtB -> B_13_18_0 = ! _rtDW -> Memory_PreviousInput_k ;
_rtB -> B_13_19_0 = _rtB -> B_13_14_0 * _rtB -> B_13_1_0_c ; } { real_T * *
uBuffer = ( real_T * * ) & _rtDW -> TransportDelay2_PWORK . TUbufferPtrs [ 0
] ; real_T simTime = ssGetT ( S ) ; real_T tMinusDelay = simTime - _rtP ->
P_20 ; _rtB -> B_13_20_0 = modPSK_acc_rt_TDelayInterpolate ( tMinusDelay ,
0.0 , * uBuffer , _rtDW -> TransportDelay2_IWORK . CircularBufSize , & _rtDW
-> TransportDelay2_IWORK . Last , _rtDW -> TransportDelay2_IWORK . Tail ,
_rtDW -> TransportDelay2_IWORK . Head , _rtP -> P_21 , 1 , ( boolean_T ) (
ssIsMinorTimeStep ( S ) && ( ( * uBuffer + _rtDW -> TransportDelay2_IWORK .
CircularBufSize ) [ _rtDW -> TransportDelay2_IWORK . Head ] == ssGetT ( S ) )
) ) ; } rtb_B_13_21_0 = _rtB -> B_13_20_0 * _rtB -> B_13_9_0_g ; { real_T * *
uBuffer = ( real_T * * ) & _rtDW -> TransportDelay1_PWORK . TUbufferPtrs [ 0
] ; real_T simTime = ssGetT ( S ) ; real_T tMinusDelay = simTime - _rtP ->
P_22 ; _rtB -> B_13_22_0 = modPSK_acc_rt_TDelayInterpolate ( tMinusDelay ,
0.0 , * uBuffer , _rtDW -> TransportDelay1_IWORK . CircularBufSize , & _rtDW
-> TransportDelay1_IWORK . Last , _rtDW -> TransportDelay1_IWORK . Tail ,
_rtDW -> TransportDelay1_IWORK . Head , _rtP -> P_23 , 0 , ( boolean_T ) (
ssIsMinorTimeStep ( S ) && ( ( * uBuffer + _rtDW -> TransportDelay1_IWORK .
CircularBufSize ) [ _rtDW -> TransportDelay1_IWORK . Head ] == ssGetT ( S ) )
) ) ; } rtb_B_13_23_0 = _rtB -> B_13_22_0 * _rtB -> B_13_10_0 ; { real_T * *
uBuffer = ( real_T * * ) & _rtDW -> TransportDelay4_PWORK . TUbufferPtrs [ 0
] ; real_T simTime = ssGetT ( S ) ; real_T tMinusDelay = simTime - _rtP ->
P_24 ; _rtB -> B_13_24_0 = modPSK_acc_rt_TDelayInterpolate ( tMinusDelay ,
0.0 , * uBuffer , _rtDW -> TransportDelay4_IWORK . CircularBufSize , & _rtDW
-> TransportDelay4_IWORK . Last , _rtDW -> TransportDelay4_IWORK . Tail ,
_rtDW -> TransportDelay4_IWORK . Head , _rtP -> P_25 , 0 , ( boolean_T ) (
ssIsMinorTimeStep ( S ) && ( ( * uBuffer + _rtDW -> TransportDelay4_IWORK .
CircularBufSize ) [ _rtDW -> TransportDelay4_IWORK . Head ] == ssGetT ( S ) )
) ) ; } rtb_B_13_25_0 = _rtB -> B_13_24_0 * _rtB -> B_13_11_0 ; { real_T * *
uBuffer = ( real_T * * ) & _rtDW -> TransportDelay3_PWORK . TUbufferPtrs [ 0
] ; real_T simTime = ssGetT ( S ) ; real_T tMinusDelay = simTime - _rtP ->
P_26 ; _rtB -> B_13_26_0 = modPSK_acc_rt_TDelayInterpolate ( tMinusDelay ,
0.0 , * uBuffer , _rtDW -> TransportDelay3_IWORK . CircularBufSize , & _rtDW
-> TransportDelay3_IWORK . Last , _rtDW -> TransportDelay3_IWORK . Tail ,
_rtDW -> TransportDelay3_IWORK . Head , _rtP -> P_27 , 0 , ( boolean_T ) (
ssIsMinorTimeStep ( S ) && ( ( * uBuffer + _rtDW -> TransportDelay3_IWORK .
CircularBufSize ) [ _rtDW -> TransportDelay3_IWORK . Head ] == ssGetT ( S ) )
) ) ; } rtb_B_13_27_0 = _rtB -> B_13_26_0 * _rtB -> B_13_12_0_m ; { real_T *
* uBuffer = ( real_T * * ) & _rtDW -> TransportDelay6_PWORK . TUbufferPtrs [
0 ] ; real_T simTime = ssGetT ( S ) ; real_T tMinusDelay = simTime - _rtP ->
P_28 ; _rtB -> B_13_28_0 = modPSK_acc_rt_TDelayInterpolate ( tMinusDelay ,
0.0 , * uBuffer , _rtDW -> TransportDelay6_IWORK . CircularBufSize , & _rtDW
-> TransportDelay6_IWORK . Last , _rtDW -> TransportDelay6_IWORK . Tail ,
_rtDW -> TransportDelay6_IWORK . Head , _rtP -> P_29 , 0 , ( boolean_T ) (
ssIsMinorTimeStep ( S ) && ( ( * uBuffer + _rtDW -> TransportDelay6_IWORK .
CircularBufSize ) [ _rtDW -> TransportDelay6_IWORK . Head ] == ssGetT ( S ) )
) ) ; } rtb_B_13_29_0 = _rtB -> B_13_28_0 * _rtB -> B_13_13_0 ; { real_T * *
uBuffer = ( real_T * * ) & _rtDW -> TransportDelay5_PWORK . TUbufferPtrs [ 0
] ; real_T simTime = ssGetT ( S ) ; real_T tMinusDelay = simTime - _rtP ->
P_30 ; _rtB -> B_13_30_0 = modPSK_acc_rt_TDelayInterpolate ( tMinusDelay ,
0.0 , * uBuffer , _rtDW -> TransportDelay5_IWORK . CircularBufSize , & _rtDW
-> TransportDelay5_IWORK . Last , _rtDW -> TransportDelay5_IWORK . Tail ,
_rtDW -> TransportDelay5_IWORK . Head , _rtP -> P_31 , 0 , ( boolean_T ) (
ssIsMinorTimeStep ( S ) && ( ( * uBuffer + _rtDW -> TransportDelay5_IWORK .
CircularBufSize ) [ _rtDW -> TransportDelay5_IWORK . Head ] == ssGetT ( S ) )
) ) ; } rtb_B_13_31_0 = _rtB -> B_13_30_0 * _rtB -> B_13_14_0_n ; { real_T *
* uBuffer = ( real_T * * ) & _rtDW -> TransportDelay8_PWORK . TUbufferPtrs [
0 ] ; real_T simTime = ssGetT ( S ) ; real_T tMinusDelay = simTime - _rtP ->
P_32 ; _rtB -> B_13_32_0 = modPSK_acc_rt_TDelayInterpolate ( tMinusDelay ,
0.0 , * uBuffer , _rtDW -> TransportDelay8_IWORK . CircularBufSize , & _rtDW
-> TransportDelay8_IWORK . Last , _rtDW -> TransportDelay8_IWORK . Tail ,
_rtDW -> TransportDelay8_IWORK . Head , _rtP -> P_33 , 0 , ( boolean_T ) (
ssIsMinorTimeStep ( S ) && ( ( * uBuffer + _rtDW -> TransportDelay8_IWORK .
CircularBufSize ) [ _rtDW -> TransportDelay8_IWORK . Head ] == ssGetT ( S ) )
) ) ; } rtb_B_13_33_0 = _rtB -> B_13_32_0 * _rtB -> B_13_15_0_p ; { real_T *
* uBuffer = ( real_T * * ) & _rtDW -> TransportDelay7_PWORK . TUbufferPtrs [
0 ] ; real_T simTime = ssGetT ( S ) ; real_T tMinusDelay = simTime - _rtP ->
P_34 ; _rtB -> B_13_34_0 = modPSK_acc_rt_TDelayInterpolate ( tMinusDelay ,
0.0 , * uBuffer , _rtDW -> TransportDelay7_IWORK . CircularBufSize , & _rtDW
-> TransportDelay7_IWORK . Last , _rtDW -> TransportDelay7_IWORK . Tail ,
_rtDW -> TransportDelay7_IWORK . Head , _rtP -> P_35 , 0 , ( boolean_T ) (
ssIsMinorTimeStep ( S ) && ( ( * uBuffer + _rtDW -> TransportDelay7_IWORK .
CircularBufSize ) [ _rtDW -> TransportDelay7_IWORK . Head ] == ssGetT ( S ) )
) ) ; } rtb_B_13_35_0 = _rtB -> B_13_34_0 * _rtB -> B_13_16_0 ; { real_T * *
uBuffer = ( real_T * * ) & _rtDW -> TransportDelay9_PWORK . TUbufferPtrs [ 0
] ; real_T simTime = ssGetT ( S ) ; real_T tMinusDelay = simTime - _rtP ->
P_36 ; _rtB -> B_13_36_0 = modPSK_acc_rt_TDelayInterpolate ( tMinusDelay ,
0.0 , * uBuffer , _rtDW -> TransportDelay9_IWORK . CircularBufSize , & _rtDW
-> TransportDelay9_IWORK . Last , _rtDW -> TransportDelay9_IWORK . Tail ,
_rtDW -> TransportDelay9_IWORK . Head , _rtP -> P_37 , 0 , ( boolean_T ) (
ssIsMinorTimeStep ( S ) && ( ( * uBuffer + _rtDW -> TransportDelay9_IWORK .
CircularBufSize ) [ _rtDW -> TransportDelay9_IWORK . Head ] == ssGetT ( S ) )
) ) ; } rtb_B_13_37_0 = _rtB -> B_13_36_0 * _rtB -> B_13_2_0_k ; { real_T * *
uBuffer = ( real_T * * ) & _rtDW -> TransportDelay11_PWORK . TUbufferPtrs [ 0
] ; real_T simTime = ssGetT ( S ) ; real_T tMinusDelay = simTime - _rtP ->
P_38 ; _rtB -> B_13_38_0 = modPSK_acc_rt_TDelayInterpolate ( tMinusDelay ,
0.0 , * uBuffer , _rtDW -> TransportDelay11_IWORK . CircularBufSize , & _rtDW
-> TransportDelay11_IWORK . Last , _rtDW -> TransportDelay11_IWORK . Tail ,
_rtDW -> TransportDelay11_IWORK . Head , _rtP -> P_39 , 0 , ( boolean_T ) (
ssIsMinorTimeStep ( S ) && ( ( * uBuffer + _rtDW -> TransportDelay11_IWORK .
CircularBufSize ) [ _rtDW -> TransportDelay11_IWORK . Head ] == ssGetT ( S )
) ) ) ; } rtb_B_13_39_0 = _rtB -> B_13_38_0 * _rtB -> B_13_5_0_p ; { real_T *
* uBuffer = ( real_T * * ) & _rtDW -> TransportDelay10_PWORK . TUbufferPtrs [
0 ] ; real_T simTime = ssGetT ( S ) ; real_T tMinusDelay = simTime - _rtP ->
P_40 ; _rtB -> B_13_40_0 = modPSK_acc_rt_TDelayInterpolate ( tMinusDelay ,
0.0 , * uBuffer , _rtDW -> TransportDelay10_IWORK . CircularBufSize , & _rtDW
-> TransportDelay10_IWORK . Last , _rtDW -> TransportDelay10_IWORK . Tail ,
_rtDW -> TransportDelay10_IWORK . Head , _rtP -> P_41 , 0 , ( boolean_T ) (
ssIsMinorTimeStep ( S ) && ( ( * uBuffer + _rtDW -> TransportDelay10_IWORK .
CircularBufSize ) [ _rtDW -> TransportDelay10_IWORK . Head ] == ssGetT ( S )
) ) ) ; } rtb_B_13_41_0 = _rtB -> B_13_40_0 * _rtB -> B_13_4_0_b ; { real_T *
* uBuffer = ( real_T * * ) & _rtDW -> TransportDelay13_PWORK . TUbufferPtrs [
0 ] ; real_T simTime = ssGetT ( S ) ; real_T tMinusDelay = simTime - _rtP ->
P_42 ; B_13_42_0 = modPSK_acc_rt_TDelayInterpolate ( tMinusDelay , 0.0 , *
uBuffer , _rtDW -> TransportDelay13_IWORK . CircularBufSize , & _rtDW ->
TransportDelay13_IWORK . Last , _rtDW -> TransportDelay13_IWORK . Tail ,
_rtDW -> TransportDelay13_IWORK . Head , _rtP -> P_43 , 0 , ( boolean_T ) (
ssIsMinorTimeStep ( S ) && ( ( * uBuffer + _rtDW -> TransportDelay13_IWORK .
CircularBufSize ) [ _rtDW -> TransportDelay13_IWORK . Head ] == ssGetT ( S )
) ) ) ; } _rtB -> B_13_44_0 = ( ( ( ( ( ( ( ( ( ( ( _rtB -> B_13_19_0 +
rtb_B_13_21_0 ) + rtb_B_13_23_0 ) + rtb_B_13_25_0 ) + rtb_B_13_27_0 ) +
rtb_B_13_29_0 ) + rtb_B_13_31_0 ) + rtb_B_13_33_0 ) + rtb_B_13_35_0 ) +
rtb_B_13_37_0 ) + rtb_B_13_39_0 ) + rtb_B_13_41_0 ) + B_13_42_0 * _rtB ->
B_13_3_0_c ; if ( _rtB -> B_13_44_0 > _rtP -> P_44 ) { _rtB -> B_13_45_0 =
_rtB -> B_13_7_0_f ; } else { _rtB -> B_13_45_0 = _rtB -> B_13_6_0_c ; } _rtB
-> B_13_46_0 = ( _rtB -> B_13_45_0 != 0.0 ) ; isHit = ssIsSampleHit ( S , 1 ,
0 ) ; if ( isHit != 0 ) { _rtB -> B_13_47_0 = _rtDW -> Memory_PreviousInput_o
; if ( ssIsModeUpdateTimeStep ( S ) ) { if ( _rtB -> B_13_21_0 [ 0 ] > 0.0 )
{ if ( ! _rtDW -> POSITIVEEdge_MODE ) { if ( ssGetTaskTime ( S , 1 ) !=
ssGetTStart ( S ) ) { ssSetBlockStateForSolverChangedAtMajorStep ( S ) ; }
_rtDW -> POSITIVEEdge_MODE = true ; } } else if ( _rtDW -> POSITIVEEdge_MODE
) { ssSetBlockStateForSolverChangedAtMajorStep ( S ) ; _rtDW ->
POSITIVEEdge_MODE = false ; } } } if ( _rtDW -> POSITIVEEdge_MODE ) { _rtB ->
B_3_0_0 = ( ( int32_T ) _rtB -> B_13_47_0 < ( int32_T ) _rtB -> B_13_46_0 ) ;
if ( ssIsModeUpdateTimeStep ( S ) ) { srUpdateBC ( _rtDW ->
POSITIVEEdge_SubsysRanBC ) ; } } isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( (
isHit != 0 ) && ssIsModeUpdateTimeStep ( S ) ) { if ( _rtB -> B_13_21_0 [ 1 ]
> 0.0 ) { if ( ! _rtDW -> NEGATIVEEdge_MODE ) { if ( ssGetTaskTime ( S , 1 )
!= ssGetTStart ( S ) ) { ssSetBlockStateForSolverChangedAtMajorStep ( S ) ; }
_rtDW -> NEGATIVEEdge_MODE = true ; } } else if ( _rtDW -> NEGATIVEEdge_MODE
) { ssSetBlockStateForSolverChangedAtMajorStep ( S ) ; _rtDW ->
NEGATIVEEdge_MODE = false ; } } if ( _rtDW -> NEGATIVEEdge_MODE ) { _rtB ->
B_2_0_0 = ( ( int32_T ) _rtB -> B_13_47_0 > ( int32_T ) _rtB -> B_13_46_0 ) ;
if ( ssIsModeUpdateTimeStep ( S ) ) { srUpdateBC ( _rtDW ->
NEGATIVEEdge_SubsysRanBC ) ; } } _rtB -> B_13_50_0 = ( _rtB -> B_3_0_0 ||
_rtB -> B_2_0_0 ) ; isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) {
_rtB -> B_13_52_0 = _rtDW -> ICic_PreviousInput ; } if ( _rtB -> B_13_18_0 &&
_rtB -> B_13_50_0 ) { _rtB -> B_13_53_0 = rtb_B_13_16_0 ; } else { _rtB ->
B_13_53_0 = _rtB -> B_13_52_0 ; } isHit = ssIsSampleHit ( S , 1 , 0 ) ; if (
isHit != 0 ) { _rtB -> B_13_54_0 = _rtP -> P_46 ; } _rtB -> B_13_56_0 = (
_rtB -> B_13_53_0 + _rtB -> B_13_54_0 > rtb_B_13_16_0 ) ; if ( _rtB ->
B_13_56_0 ) { _rtB -> B_13_57_0 = _rtB -> B_13_15_0 ; } else { _rtB ->
B_13_57_0 = _rtB -> B_13_8_0_g ; } ssCallAccelRunBlock ( S , 13 , 58 ,
SS_CALL_MDL_OUTPUTS ) ; isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( ( isHit !=
0 ) && ssIsModeUpdateTimeStep ( S ) ) { zcEvent = rt_ZCFcn (
RISING_ZERO_CROSSING , & _rtZCE -> TriggeredToWorkspace_Trig_ZCE , _rtB ->
B_13_57_0 ) ; if ( zcEvent != NO_ZCEVENT ) { { if ( _rtDW ->
_asyncqueue_inserted_for_ToWorkspace_PWORK_e . AQHandles && ssGetLogOutput (
S ) ) { sdiWriteSignal ( _rtDW ->
_asyncqueue_inserted_for_ToWorkspace_PWORK_e . AQHandles , ssGetTaskTime ( S
, 1 ) , ( char * ) & _rtB -> B_13_14_0 + 0 ) ; } } _rtDW ->
TriggeredToWorkspace_SubsysRanBC = 4 ; } zcEvent = rt_ZCFcn (
RISING_ZERO_CROSSING , & _rtZCE -> TriggeredToWorkspace1_Trig_ZCE , _rtB ->
B_13_15_0 ) ; if ( zcEvent != NO_ZCEVENT ) { { if ( _rtDW ->
_asyncqueue_inserted_for_ToWorkspace_PWORK . AQHandles && ssGetLogOutput ( S
) ) { sdiWriteSignal ( _rtDW -> _asyncqueue_inserted_for_ToWorkspace_PWORK .
AQHandles , ssGetTaskTime ( S , 1 ) , ( char * ) & _rtB -> B_13_14_0 + 0 ) ;
} } _rtDW -> TriggeredToWorkspace1_SubsysRanBC = 4 ; } } ssCallAccelRunBlock
( S , 13 , 61 , SS_CALL_MDL_OUTPUTS ) ; _rtB -> B_13_62_0 = 0.0 ; for ( ri =
_rtP -> P_131 [ 0U ] ; ri < _rtP -> P_131 [ 1U ] ; ri ++ ) { _rtB ->
B_13_62_0 += _rtP -> P_49 * _rtX -> AnalogFilterDesign_CSTATE_e [ 0U ] ; }
for ( ri = _rtP -> P_131 [ 1U ] ; ri < _rtP -> P_131 [ 2U ] ; ri ++ ) { _rtB
-> B_13_62_0 += _rtP -> P_49 * _rtX -> AnalogFilterDesign_CSTATE_e [ 1U ] ; }
for ( ri = _rtP -> P_131 [ 2U ] ; ri < _rtP -> P_131 [ 3U ] ; ri ++ ) { _rtB
-> B_13_62_0 += _rtP -> P_49 * _rtX -> AnalogFilterDesign_CSTATE_e [ 2U ] ; }
for ( ri = _rtP -> P_131 [ 3U ] ; ri < _rtP -> P_131 [ 4U ] ; ri ++ ) { _rtB
-> B_13_62_0 += _rtP -> P_49 * _rtX -> AnalogFilterDesign_CSTATE_e [ 3U ] ; }
ssCallAccelRunBlock ( S , 13 , 63 , SS_CALL_MDL_OUTPUTS ) ; _rtB -> B_13_64_0
= 0.0 ; for ( isHit = 0 ; isHit < 8 ; isHit ++ ) { for ( ri = _rtP -> P_137 [
( uint32_T ) isHit ] ; ri < _rtP -> P_137 [ isHit + 1U ] ; ri ++ ) { _rtB ->
B_13_64_0 += _rtP -> P_53 * _rtX -> AnalogFilterDesign_CSTATE_p [ ( uint32_T
) isHit ] ; } } ssCallAccelRunBlock ( S , 13 , 65 , SS_CALL_MDL_OUTPUTS ) ;
_rtB -> B_13_66_0 = _rtB -> B_13_62_0 * _rtB -> B_13_6_0 ;
ssCallAccelRunBlock ( S , 13 , 67 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 13 , 68 , SS_CALL_MDL_OUTPUTS ) ; _rtB -> B_13_69_0
= ssGetT ( S ) ; isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( ( isHit != 0 ) &&
ssIsModeUpdateTimeStep ( S ) ) { if ( _rtB -> B_13_50_0 && ( _rtZCE ->
TriggeredSubsystem_Trig_ZCE != POS_ZCSIG ) ) { _rtDW ->
TriggeredSubsystem_SubsysRanBC = 4 ; } _rtZCE -> TriggeredSubsystem_Trig_ZCE
= _rtB -> B_13_50_0 ; } _rtB -> B_13_71_0 = _rtX -> ModuloIntegrator_CSTATE_p
; rtb_B_13_16_0 = muDoubleScalarCos ( _rtB -> B_13_71_0 * 6.2831853071795862
) ; _rtB -> B_13_74_0 = _rtB -> B_13_62_0 * _rtB -> B_13_24_0_j ; _rtB ->
B_13_75_0 = _rtB -> B_13_74_0 * _rtB -> B_13_74_0 ; _rtB -> B_13_76_0 = _rtB
-> B_13_75_0 * rtb_B_13_16_0 ; _rtB -> B_13_77_0 = _rtB -> B_13_27_0 * _rtB
-> B_13_76_0 ; _rtB -> B_13_78_0 = _rtX -> Integrator_CSTATE_d ; _rtB ->
B_13_79_0 = _rtB -> B_13_77_0 + _rtB -> B_13_78_0 ; _rtB -> B_13_80_0 = _rtP
-> P_59 * _rtB -> B_13_79_0 ; _rtB -> B_13_81_0 = _rtB -> B_13_80_0 + _rtB ->
B_13_22_0_l ; isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) {
rtb_B_13_82_0 = _rtDW -> TmpLatchAtDFlipFlopInport1_PreviousInput ; } _rtB ->
B_13_83_0 = muDoubleScalarSign ( rtb_B_13_16_0 ) ; isHit = ssIsSampleHit ( S
, 1 , 0 ) ; if ( isHit != 0 ) { zcEvent = NO_ZCEVENT ; if (
ssIsModeUpdateTimeStep ( S ) ) { zcEvent = rt_ZCFcn ( RISING_ZERO_CROSSING ,
& _rtZCE -> DFlipFlop_Trig_ZCE , _rtB -> B_13_83_0 ) ; } if ( _rtB ->
B_13_25_0 > 0.0 ) { if ( ! _rtDW -> DFlipFlop_MODE ) { if ( ssGetTaskTime ( S
, 1 ) != ssGetTStart ( S ) ) { ssSetBlockStateForSolverChangedAtMajorStep ( S
) ; } _rtDW -> DFlipFlop_MODE = true ; } if ( ssIsModeUpdateTimeStep ( S ) &&
( zcEvent != NO_ZCEVENT ) ) { _rtB -> B_4_0_0 = rtb_B_13_82_0 ; _rtB ->
B_4_1_0 = ! _rtB -> B_4_0_0 ; _rtDW -> DFlipFlop_SubsysRanBC = 4 ; } } else
if ( _rtDW -> DFlipFlop_MODE ) { ssSetBlockStateForSolverChangedAtMajorStep (
S ) ; _rtB -> B_4_0_0 = _rtP -> P_140 ; _rtB -> B_4_1_0 = _rtP -> P_141 ;
_rtDW -> DFlipFlop_MODE = false ; } _rtB -> B_13_86_0 = _rtB -> B_13_29_0 * (
real_T ) _rtB -> B_4_0_0 - _rtB -> B_13_28_0_g ; } _rtB -> B_13_87_0 = _rtB
-> B_13_76_0 * _rtB -> B_13_26_0_d ; _rtB -> B_13_88_0 = _rtB -> B_13_30_0_l
* _rtB -> B_13_64_0 ; _rtB -> B_13_89_0 = muDoubleScalarSign ( _rtB ->
B_13_88_0 ) ; if ( ssIsModeUpdateTimeStep ( S ) ) { zcEvent = rt_ZCFcn (
RISING_ZERO_CROSSING , & _rtZCE -> Integrator1_Reset_ZCE , _rtB -> B_13_12_0
) ; if ( zcEvent != NO_ZCEVENT ) { _rtX -> Integrator1_CSTATE = _rtP -> P_60
; ssSetBlockStateForSolverChangedAtMajorStep ( S ) ; } _rtB -> B_13_90_0 =
_rtX -> Integrator1_CSTATE ; } else { _rtB -> B_13_90_0 = _rtX ->
Integrator1_CSTATE ; } rtb_B_13_16_0 = ssGetT ( S ) ; isHit = ssIsSampleHit (
S , 1 , 0 ) ; if ( isHit != 0 ) { _rtB -> B_13_93_0 = ! _rtDW ->
Memory_PreviousInput_a ; _rtB -> B_13_94_0 = _rtDW -> Memory_PreviousInput ;
} modPSK_POSITIVEEdge ( S , _rtB -> B_13_36_0_d [ 0 ] , _rtB -> B_13_12_0 ,
_rtB -> B_13_94_0 , & _rtB -> POSITIVEEdge_l , & _rtDW -> POSITIVEEdge_l ) ;
modPSK_NEGATIVEEdge ( S , _rtB -> B_13_36_0_d [ 1 ] , _rtB -> B_13_12_0 ,
_rtB -> B_13_94_0 , & _rtB -> NEGATIVEEdge_f , & _rtDW -> NEGATIVEEdge_f ) ;
isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { _rtB -> B_13_99_0 =
_rtDW -> ICic_PreviousInput_c ; } if ( _rtB -> B_13_93_0 && ( _rtB ->
POSITIVEEdge_l . B_6_0_0 || _rtB -> NEGATIVEEdge_f . B_5_0_0 ) ) { _rtB ->
B_13_100_0 = rtb_B_13_16_0 ; } else { _rtB -> B_13_100_0 = _rtB -> B_13_99_0
; } _rtB -> B_13_101_0 = _rtB -> B_13_100_0 + _rtB -> B_13_37_0 ; _rtB ->
B_13_102_0 = ( _rtB -> B_13_101_0 > rtb_B_13_16_0 ) ; if (
ssIsModeUpdateTimeStep ( S ) ) { rtb_B_13_82_0 = ( ( ! _rtB -> B_13_102_0 )
&& ( _rtZCE -> Integrator_Reset_ZCE_c != ZERO_ZCSIG ) ) ; _rtZCE ->
Integrator_Reset_ZCE_c = _rtB -> B_13_102_0 ; if ( rtb_B_13_82_0 ) { _rtX ->
Integrator_CSTATE_p = _rtP -> P_63 ;
ssSetBlockStateForSolverChangedAtMajorStep ( S ) ; } _rtB -> B_13_103_0 =
_rtX -> Integrator_CSTATE_p ; } else { _rtB -> B_13_103_0 = _rtX ->
Integrator_CSTATE_p ; } rtb_B_13_16_0 = ssGetT ( S ) ; isHit = ssIsSampleHit
( S , 1 , 0 ) ; if ( isHit != 0 ) { _rtB -> B_13_106_0 = ! _rtDW ->
Memory_PreviousInput_ab ; _rtB -> B_13_107_0 = _rtDW ->
Memory_PreviousInput_p ; } modPSK_POSITIVEEdge ( S , _rtB -> B_13_42_0 [ 0 ]
, _rtB -> B_13_12_0 , _rtB -> B_13_107_0 , & _rtB -> POSITIVEEdge_c , & _rtDW
-> POSITIVEEdge_c ) ; modPSK_NEGATIVEEdge ( S , _rtB -> B_13_42_0 [ 1 ] ,
_rtB -> B_13_12_0 , _rtB -> B_13_107_0 , & _rtB -> NEGATIVEEdge_g , & _rtDW
-> NEGATIVEEdge_g ) ; isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 )
{ _rtB -> B_13_112_0 = _rtDW -> ICic_PreviousInput_f ; } if ( _rtB ->
B_13_106_0 && ( _rtB -> POSITIVEEdge_c . B_6_0_0 || _rtB -> NEGATIVEEdge_g .
B_5_0_0 ) ) { _rtB -> B_13_113_0 = rtb_B_13_16_0 ; } else { _rtB ->
B_13_113_0 = _rtB -> B_13_112_0 ; } _rtB -> B_13_115_0 = ( _rtB -> B_13_113_0
+ _rtB -> B_13_43_0 > rtb_B_13_16_0 ) ; isHit = ssIsSampleHit ( S , 1 , 0 ) ;
if ( isHit != 0 ) { if ( ssIsModeUpdateTimeStep ( S ) ) { if ( ( ! _rtB ->
B_13_115_0 ) && ( _rtZCE -> SampleandHold_Trig_ZCE_a != ZERO_ZCSIG ) ) { _rtB
-> B_9_0_0 = _rtB -> B_13_90_0 ; _rtDW -> SampleandHold_SubsysRanBC = 4 ; }
_rtZCE -> SampleandHold_Trig_ZCE_a = _rtB -> B_13_115_0 ; } _rtB ->
B_13_117_0 = muDoubleScalarAbs ( _rtB -> B_9_0_0 ) ; } _rtB -> B_13_119_0 =
_rtB -> B_13_117_0 - muDoubleScalarAbs ( _rtB -> B_13_103_0 ) ; isHit =
ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { modPSK_SampleandHold ( S ,
_rtB -> B_13_12_0 , _rtB -> B_13_119_0 , & _rtB -> SampleandHold2 , & _rtDW
-> SampleandHold2 , & _rtZCE -> SampleandHold2 ) ; } ssCallAccelRunBlock ( S
, 13 , 121 , SS_CALL_MDL_OUTPUTS ) ; isHit = ssIsSampleHit ( S , 1 , 0 ) ; if
( isHit != 0 ) { { if ( _rtDW ->
TAQSigLogging_InsertedFor_Sign_at_outport_0_PWORK . AQHandles &&
ssGetLogOutput ( S ) ) { sdiWriteSignal ( _rtDW ->
TAQSigLogging_InsertedFor_Sign_at_outport_0_PWORK . AQHandles , ssGetTaskTime
( S , 1 ) , ( char * ) & _rtB -> B_13_89_0 + 0 ) ; } } _rtB -> B_13_124_0 =
_rtP -> P_66 * _rtB -> SampleandHold2 . B_0_0_0 + _rtB -> B_13_31_0 ; } isHit
= ssIsSampleHit ( S , 2 , 0 ) ; if ( isHit != 0 ) { _rtB -> B_13_126_0 = _rtP
-> P_67 * _rtB -> B_13_0_0 + _rtP -> P_68 ; } ssCallAccelRunBlock ( S , 13 ,
127 , SS_CALL_MDL_OUTPUTS ) ; _rtB -> B_13_129_0 = ( muDoubleScalarSin ( _rtP
-> P_71 * ssGetTaskTime ( S , 0 ) + _rtP -> P_72 ) * _rtP -> P_69 + _rtP ->
P_70 ) * _rtB -> B_13_126_0 ; UNUSED_PARAMETER ( tid ) ; } static void
mdlOutputsTID3 ( SimStruct * S , int_T tid ) { B_modPSK_T * _rtB ; P_modPSK_T
* _rtP ; _rtP = ( ( P_modPSK_T * ) ssGetModelRtp ( S ) ) ; _rtB = ( (
B_modPSK_T * ) _ssGetModelBlockIO ( S ) ) ; _rtB -> B_13_0_0_m = _rtP -> P_73
; _rtB -> B_13_1_0_c = _rtP -> P_74 ; _rtB -> B_13_2_0_k = _rtP -> P_75 ;
_rtB -> B_13_3_0_c = _rtP -> P_76 ; _rtB -> B_13_4_0_b = _rtP -> P_77 ; _rtB
-> B_13_5_0_p = _rtP -> P_78 ; _rtB -> B_13_6_0_c = _rtP -> P_79 ; _rtB ->
B_13_7_0_f = _rtP -> P_80 ; _rtB -> B_13_8_0_g = _rtP -> P_81 ; _rtB ->
B_13_9_0_g = _rtP -> P_82 ; _rtB -> B_13_10_0 = _rtP -> P_83 ; _rtB ->
B_13_11_0 = _rtP -> P_84 ; _rtB -> B_13_12_0_m = _rtP -> P_85 ; _rtB ->
B_13_13_0 = _rtP -> P_86 ; _rtB -> B_13_14_0_n = _rtP -> P_87 ; _rtB ->
B_13_15_0_p = _rtP -> P_88 ; _rtB -> B_13_16_0 = _rtP -> P_89 ; switch ( (
int32_T ) _rtP -> P_90 ) { case 1 : _rtB -> B_13_21_0 [ 0 ] = _rtP -> P_91 [
0 ] ; _rtB -> B_13_21_0 [ 1 ] = _rtP -> P_91 [ 1 ] ; break ; case 2 : _rtB ->
B_13_21_0 [ 0 ] = _rtP -> P_92 [ 0 ] ; _rtB -> B_13_21_0 [ 1 ] = _rtP -> P_92
[ 1 ] ; break ; default : _rtB -> B_13_21_0 [ 0 ] = _rtP -> P_93 [ 0 ] ; _rtB
-> B_13_21_0 [ 1 ] = _rtP -> P_93 [ 1 ] ; break ; } _rtB -> B_13_22_0_l =
_rtP -> P_94 ; _rtB -> B_13_23_0 = _rtP -> P_95 ; _rtB -> B_13_24_0_j = _rtP
-> P_96 ; _rtB -> B_13_25_0 = _rtP -> P_97 ; _rtB -> B_13_26_0_d = _rtP ->
P_98 ; _rtB -> B_13_27_0 = _rtP -> P_99 ; _rtB -> B_13_28_0_g = _rtP -> P_100
; _rtB -> B_13_29_0 = _rtP -> P_101 ; _rtB -> B_13_30_0_l = _rtP -> P_102 ;
_rtB -> B_13_31_0 = _rtP -> P_103 ; switch ( ( int32_T ) _rtP -> P_104 ) {
case 1 : _rtB -> B_13_36_0_d [ 0 ] = _rtP -> P_105 [ 0 ] ; _rtB ->
B_13_36_0_d [ 1 ] = _rtP -> P_105 [ 1 ] ; break ; case 2 : _rtB ->
B_13_36_0_d [ 0 ] = _rtP -> P_106 [ 0 ] ; _rtB -> B_13_36_0_d [ 1 ] = _rtP ->
P_106 [ 1 ] ; break ; default : _rtB -> B_13_36_0_d [ 0 ] = _rtP -> P_107 [ 0
] ; _rtB -> B_13_36_0_d [ 1 ] = _rtP -> P_107 [ 1 ] ; break ; } _rtB ->
B_13_37_0 = _rtP -> P_108 ; switch ( ( int32_T ) _rtP -> P_109 ) { case 1 :
_rtB -> B_13_42_0 [ 0 ] = _rtP -> P_110 [ 0 ] ; _rtB -> B_13_42_0 [ 1 ] =
_rtP -> P_110 [ 1 ] ; break ; case 2 : _rtB -> B_13_42_0 [ 0 ] = _rtP ->
P_111 [ 0 ] ; _rtB -> B_13_42_0 [ 1 ] = _rtP -> P_111 [ 1 ] ; break ; default
: _rtB -> B_13_42_0 [ 0 ] = _rtP -> P_112 [ 0 ] ; _rtB -> B_13_42_0 [ 1 ] =
_rtP -> P_112 [ 1 ] ; break ; } _rtB -> B_13_43_0 = _rtP -> P_113 ;
UNUSED_PARAMETER ( tid ) ; }
#define MDL_UPDATE
static void mdlUpdate ( SimStruct * S , int_T tid ) { B_modPSK_T * _rtB ;
DW_modPSK_T * _rtDW ; P_modPSK_T * _rtP ; int32_T isHit ; _rtDW = ( (
DW_modPSK_T * ) ssGetRootDWork ( S ) ) ; _rtP = ( ( P_modPSK_T * )
ssGetModelRtp ( S ) ) ; _rtB = ( ( B_modPSK_T * ) _ssGetModelBlockIO ( S ) )
; { real_T * * uBuffer = ( real_T * * ) & _rtDW -> TransportDelay_PWORK .
TUbufferPtrs [ 0 ] ; real_T simTime = ssGetT ( S ) ; _rtDW ->
TransportDelay_IWORK . Head = ( ( _rtDW -> TransportDelay_IWORK . Head < (
_rtDW -> TransportDelay_IWORK . CircularBufSize - 1 ) ) ? ( _rtDW ->
TransportDelay_IWORK . Head + 1 ) : 0 ) ; if ( _rtDW -> TransportDelay_IWORK
. Head == _rtDW -> TransportDelay_IWORK . Tail ) { if ( !
modPSK_acc_rt_TDelayUpdateTailOrGrowBuf ( & _rtDW -> TransportDelay_IWORK .
CircularBufSize , & _rtDW -> TransportDelay_IWORK . Tail , & _rtDW ->
TransportDelay_IWORK . Head , & _rtDW -> TransportDelay_IWORK . Last ,
simTime - _rtP -> P_6 , uBuffer , ( boolean_T ) 0 , false , & _rtDW ->
TransportDelay_IWORK . MaxNewBufSize ) ) { ssSetErrorStatus ( S ,
"tdelay memory allocation error" ) ; return ; } } ( * uBuffer + _rtDW ->
TransportDelay_IWORK . CircularBufSize ) [ _rtDW -> TransportDelay_IWORK .
Head ] = simTime ; ( * uBuffer ) [ _rtDW -> TransportDelay_IWORK . Head ] =
_rtB -> B_13_1_0 ; } { real_T * * uBuffer = ( real_T * * ) & _rtDW ->
TransportDelay_PWORK_p . TUbufferPtrs [ 0 ] ; real_T simTime = ssGetT ( S ) ;
_rtDW -> TransportDelay_IWORK_k . Head = ( ( _rtDW -> TransportDelay_IWORK_k
. Head < ( _rtDW -> TransportDelay_IWORK_k . CircularBufSize - 1 ) ) ? (
_rtDW -> TransportDelay_IWORK_k . Head + 1 ) : 0 ) ; if ( _rtDW ->
TransportDelay_IWORK_k . Head == _rtDW -> TransportDelay_IWORK_k . Tail ) {
if ( ! modPSK_acc_rt_TDelayUpdateTailOrGrowBuf ( & _rtDW ->
TransportDelay_IWORK_k . CircularBufSize , & _rtDW -> TransportDelay_IWORK_k
. Tail , & _rtDW -> TransportDelay_IWORK_k . Head , & _rtDW ->
TransportDelay_IWORK_k . Last , simTime - _rtP -> P_12 , uBuffer , (
boolean_T ) 0 , false , & _rtDW -> TransportDelay_IWORK_k . MaxNewBufSize ) )
{ ssSetErrorStatus ( S , "tdelay memory allocation error" ) ; return ; } } (
* uBuffer + _rtDW -> TransportDelay_IWORK_k . CircularBufSize ) [ _rtDW ->
TransportDelay_IWORK_k . Head ] = simTime ; ( * uBuffer ) [ _rtDW ->
TransportDelay_IWORK_k . Head ] = _rtB -> B_13_12_0 ; } { real_T * * uBuffer
= ( real_T * * ) & _rtDW -> TransportDelay_PWORK_k . TUbufferPtrs [ 0 ] ;
real_T simTime = ssGetT ( S ) ; _rtDW -> TransportDelay_IWORK_m . Head = ( (
_rtDW -> TransportDelay_IWORK_m . Head < ( _rtDW -> TransportDelay_IWORK_m .
CircularBufSize - 1 ) ) ? ( _rtDW -> TransportDelay_IWORK_m . Head + 1 ) : 0
) ; if ( _rtDW -> TransportDelay_IWORK_m . Head == _rtDW ->
TransportDelay_IWORK_m . Tail ) { if ( !
modPSK_acc_rt_TDelayUpdateTailOrGrowBuf ( & _rtDW -> TransportDelay_IWORK_m .
CircularBufSize , & _rtDW -> TransportDelay_IWORK_m . Tail , & _rtDW ->
TransportDelay_IWORK_m . Head , & _rtDW -> TransportDelay_IWORK_m . Last ,
simTime - _rtP -> P_18 , uBuffer , ( boolean_T ) 0 , false , & _rtDW ->
TransportDelay_IWORK_m . MaxNewBufSize ) ) { ssSetErrorStatus ( S ,
"tdelay memory allocation error" ) ; return ; } } ( * uBuffer + _rtDW ->
TransportDelay_IWORK_m . CircularBufSize ) [ _rtDW -> TransportDelay_IWORK_m
. Head ] = simTime ; ( * uBuffer ) [ _rtDW -> TransportDelay_IWORK_m . Head ]
= _rtB -> B_13_12_0 ; } isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0
) { _rtDW -> Memory_PreviousInput_k = _rtB -> B_13_56_0 ; } { real_T * *
uBuffer = ( real_T * * ) & _rtDW -> TransportDelay2_PWORK . TUbufferPtrs [ 0
] ; real_T simTime = ssGetT ( S ) ; _rtDW -> TransportDelay2_IWORK . Head = (
( _rtDW -> TransportDelay2_IWORK . Head < ( _rtDW -> TransportDelay2_IWORK .
CircularBufSize - 1 ) ) ? ( _rtDW -> TransportDelay2_IWORK . Head + 1 ) : 0 )
; if ( _rtDW -> TransportDelay2_IWORK . Head == _rtDW ->
TransportDelay2_IWORK . Tail ) { if ( !
modPSK_acc_rt_TDelayUpdateTailOrGrowBuf ( & _rtDW -> TransportDelay2_IWORK .
CircularBufSize , & _rtDW -> TransportDelay2_IWORK . Tail , & _rtDW ->
TransportDelay2_IWORK . Head , & _rtDW -> TransportDelay2_IWORK . Last ,
simTime - _rtP -> P_20 , uBuffer , ( boolean_T ) 0 , false , & _rtDW ->
TransportDelay2_IWORK . MaxNewBufSize ) ) { ssSetErrorStatus ( S ,
"tdelay memory allocation error" ) ; return ; } } ( * uBuffer + _rtDW ->
TransportDelay2_IWORK . CircularBufSize ) [ _rtDW -> TransportDelay2_IWORK .
Head ] = simTime ; ( * uBuffer ) [ _rtDW -> TransportDelay2_IWORK . Head ] =
_rtB -> B_13_14_0 ; } { real_T * * uBuffer = ( real_T * * ) & _rtDW ->
TransportDelay1_PWORK . TUbufferPtrs [ 0 ] ; real_T simTime = ssGetT ( S ) ;
_rtDW -> TransportDelay1_IWORK . Head = ( ( _rtDW -> TransportDelay1_IWORK .
Head < ( _rtDW -> TransportDelay1_IWORK . CircularBufSize - 1 ) ) ? ( _rtDW
-> TransportDelay1_IWORK . Head + 1 ) : 0 ) ; if ( _rtDW ->
TransportDelay1_IWORK . Head == _rtDW -> TransportDelay1_IWORK . Tail ) { if
( ! modPSK_acc_rt_TDelayUpdateTailOrGrowBuf ( & _rtDW ->
TransportDelay1_IWORK . CircularBufSize , & _rtDW -> TransportDelay1_IWORK .
Tail , & _rtDW -> TransportDelay1_IWORK . Head , & _rtDW ->
TransportDelay1_IWORK . Last , simTime - _rtP -> P_22 , uBuffer , ( boolean_T
) 0 , false , & _rtDW -> TransportDelay1_IWORK . MaxNewBufSize ) ) {
ssSetErrorStatus ( S , "tdelay memory allocation error" ) ; return ; } } ( *
uBuffer + _rtDW -> TransportDelay1_IWORK . CircularBufSize ) [ _rtDW ->
TransportDelay1_IWORK . Head ] = simTime ; ( * uBuffer ) [ _rtDW ->
TransportDelay1_IWORK . Head ] = _rtB -> B_13_20_0 ; } { real_T * * uBuffer =
( real_T * * ) & _rtDW -> TransportDelay4_PWORK . TUbufferPtrs [ 0 ] ; real_T
simTime = ssGetT ( S ) ; _rtDW -> TransportDelay4_IWORK . Head = ( ( _rtDW ->
TransportDelay4_IWORK . Head < ( _rtDW -> TransportDelay4_IWORK .
CircularBufSize - 1 ) ) ? ( _rtDW -> TransportDelay4_IWORK . Head + 1 ) : 0 )
; if ( _rtDW -> TransportDelay4_IWORK . Head == _rtDW ->
TransportDelay4_IWORK . Tail ) { if ( !
modPSK_acc_rt_TDelayUpdateTailOrGrowBuf ( & _rtDW -> TransportDelay4_IWORK .
CircularBufSize , & _rtDW -> TransportDelay4_IWORK . Tail , & _rtDW ->
TransportDelay4_IWORK . Head , & _rtDW -> TransportDelay4_IWORK . Last ,
simTime - _rtP -> P_24 , uBuffer , ( boolean_T ) 0 , false , & _rtDW ->
TransportDelay4_IWORK . MaxNewBufSize ) ) { ssSetErrorStatus ( S ,
"tdelay memory allocation error" ) ; return ; } } ( * uBuffer + _rtDW ->
TransportDelay4_IWORK . CircularBufSize ) [ _rtDW -> TransportDelay4_IWORK .
Head ] = simTime ; ( * uBuffer ) [ _rtDW -> TransportDelay4_IWORK . Head ] =
_rtB -> B_13_22_0 ; } { real_T * * uBuffer = ( real_T * * ) & _rtDW ->
TransportDelay3_PWORK . TUbufferPtrs [ 0 ] ; real_T simTime = ssGetT ( S ) ;
_rtDW -> TransportDelay3_IWORK . Head = ( ( _rtDW -> TransportDelay3_IWORK .
Head < ( _rtDW -> TransportDelay3_IWORK . CircularBufSize - 1 ) ) ? ( _rtDW
-> TransportDelay3_IWORK . Head + 1 ) : 0 ) ; if ( _rtDW ->
TransportDelay3_IWORK . Head == _rtDW -> TransportDelay3_IWORK . Tail ) { if
( ! modPSK_acc_rt_TDelayUpdateTailOrGrowBuf ( & _rtDW ->
TransportDelay3_IWORK . CircularBufSize , & _rtDW -> TransportDelay3_IWORK .
Tail , & _rtDW -> TransportDelay3_IWORK . Head , & _rtDW ->
TransportDelay3_IWORK . Last , simTime - _rtP -> P_26 , uBuffer , ( boolean_T
) 0 , false , & _rtDW -> TransportDelay3_IWORK . MaxNewBufSize ) ) {
ssSetErrorStatus ( S , "tdelay memory allocation error" ) ; return ; } } ( *
uBuffer + _rtDW -> TransportDelay3_IWORK . CircularBufSize ) [ _rtDW ->
TransportDelay3_IWORK . Head ] = simTime ; ( * uBuffer ) [ _rtDW ->
TransportDelay3_IWORK . Head ] = _rtB -> B_13_24_0 ; } { real_T * * uBuffer =
( real_T * * ) & _rtDW -> TransportDelay6_PWORK . TUbufferPtrs [ 0 ] ; real_T
simTime = ssGetT ( S ) ; _rtDW -> TransportDelay6_IWORK . Head = ( ( _rtDW ->
TransportDelay6_IWORK . Head < ( _rtDW -> TransportDelay6_IWORK .
CircularBufSize - 1 ) ) ? ( _rtDW -> TransportDelay6_IWORK . Head + 1 ) : 0 )
; if ( _rtDW -> TransportDelay6_IWORK . Head == _rtDW ->
TransportDelay6_IWORK . Tail ) { if ( !
modPSK_acc_rt_TDelayUpdateTailOrGrowBuf ( & _rtDW -> TransportDelay6_IWORK .
CircularBufSize , & _rtDW -> TransportDelay6_IWORK . Tail , & _rtDW ->
TransportDelay6_IWORK . Head , & _rtDW -> TransportDelay6_IWORK . Last ,
simTime - _rtP -> P_28 , uBuffer , ( boolean_T ) 0 , false , & _rtDW ->
TransportDelay6_IWORK . MaxNewBufSize ) ) { ssSetErrorStatus ( S ,
"tdelay memory allocation error" ) ; return ; } } ( * uBuffer + _rtDW ->
TransportDelay6_IWORK . CircularBufSize ) [ _rtDW -> TransportDelay6_IWORK .
Head ] = simTime ; ( * uBuffer ) [ _rtDW -> TransportDelay6_IWORK . Head ] =
_rtB -> B_13_26_0 ; } { real_T * * uBuffer = ( real_T * * ) & _rtDW ->
TransportDelay5_PWORK . TUbufferPtrs [ 0 ] ; real_T simTime = ssGetT ( S ) ;
_rtDW -> TransportDelay5_IWORK . Head = ( ( _rtDW -> TransportDelay5_IWORK .
Head < ( _rtDW -> TransportDelay5_IWORK . CircularBufSize - 1 ) ) ? ( _rtDW
-> TransportDelay5_IWORK . Head + 1 ) : 0 ) ; if ( _rtDW ->
TransportDelay5_IWORK . Head == _rtDW -> TransportDelay5_IWORK . Tail ) { if
( ! modPSK_acc_rt_TDelayUpdateTailOrGrowBuf ( & _rtDW ->
TransportDelay5_IWORK . CircularBufSize , & _rtDW -> TransportDelay5_IWORK .
Tail , & _rtDW -> TransportDelay5_IWORK . Head , & _rtDW ->
TransportDelay5_IWORK . Last , simTime - _rtP -> P_30 , uBuffer , ( boolean_T
) 0 , false , & _rtDW -> TransportDelay5_IWORK . MaxNewBufSize ) ) {
ssSetErrorStatus ( S , "tdelay memory allocation error" ) ; return ; } } ( *
uBuffer + _rtDW -> TransportDelay5_IWORK . CircularBufSize ) [ _rtDW ->
TransportDelay5_IWORK . Head ] = simTime ; ( * uBuffer ) [ _rtDW ->
TransportDelay5_IWORK . Head ] = _rtB -> B_13_28_0 ; } { real_T * * uBuffer =
( real_T * * ) & _rtDW -> TransportDelay8_PWORK . TUbufferPtrs [ 0 ] ; real_T
simTime = ssGetT ( S ) ; _rtDW -> TransportDelay8_IWORK . Head = ( ( _rtDW ->
TransportDelay8_IWORK . Head < ( _rtDW -> TransportDelay8_IWORK .
CircularBufSize - 1 ) ) ? ( _rtDW -> TransportDelay8_IWORK . Head + 1 ) : 0 )
; if ( _rtDW -> TransportDelay8_IWORK . Head == _rtDW ->
TransportDelay8_IWORK . Tail ) { if ( !
modPSK_acc_rt_TDelayUpdateTailOrGrowBuf ( & _rtDW -> TransportDelay8_IWORK .
CircularBufSize , & _rtDW -> TransportDelay8_IWORK . Tail , & _rtDW ->
TransportDelay8_IWORK . Head , & _rtDW -> TransportDelay8_IWORK . Last ,
simTime - _rtP -> P_32 , uBuffer , ( boolean_T ) 0 , false , & _rtDW ->
TransportDelay8_IWORK . MaxNewBufSize ) ) { ssSetErrorStatus ( S ,
"tdelay memory allocation error" ) ; return ; } } ( * uBuffer + _rtDW ->
TransportDelay8_IWORK . CircularBufSize ) [ _rtDW -> TransportDelay8_IWORK .
Head ] = simTime ; ( * uBuffer ) [ _rtDW -> TransportDelay8_IWORK . Head ] =
_rtB -> B_13_30_0 ; } { real_T * * uBuffer = ( real_T * * ) & _rtDW ->
TransportDelay7_PWORK . TUbufferPtrs [ 0 ] ; real_T simTime = ssGetT ( S ) ;
_rtDW -> TransportDelay7_IWORK . Head = ( ( _rtDW -> TransportDelay7_IWORK .
Head < ( _rtDW -> TransportDelay7_IWORK . CircularBufSize - 1 ) ) ? ( _rtDW
-> TransportDelay7_IWORK . Head + 1 ) : 0 ) ; if ( _rtDW ->
TransportDelay7_IWORK . Head == _rtDW -> TransportDelay7_IWORK . Tail ) { if
( ! modPSK_acc_rt_TDelayUpdateTailOrGrowBuf ( & _rtDW ->
TransportDelay7_IWORK . CircularBufSize , & _rtDW -> TransportDelay7_IWORK .
Tail , & _rtDW -> TransportDelay7_IWORK . Head , & _rtDW ->
TransportDelay7_IWORK . Last , simTime - _rtP -> P_34 , uBuffer , ( boolean_T
) 0 , false , & _rtDW -> TransportDelay7_IWORK . MaxNewBufSize ) ) {
ssSetErrorStatus ( S , "tdelay memory allocation error" ) ; return ; } } ( *
uBuffer + _rtDW -> TransportDelay7_IWORK . CircularBufSize ) [ _rtDW ->
TransportDelay7_IWORK . Head ] = simTime ; ( * uBuffer ) [ _rtDW ->
TransportDelay7_IWORK . Head ] = _rtB -> B_13_32_0 ; } { real_T * * uBuffer =
( real_T * * ) & _rtDW -> TransportDelay9_PWORK . TUbufferPtrs [ 0 ] ; real_T
simTime = ssGetT ( S ) ; _rtDW -> TransportDelay9_IWORK . Head = ( ( _rtDW ->
TransportDelay9_IWORK . Head < ( _rtDW -> TransportDelay9_IWORK .
CircularBufSize - 1 ) ) ? ( _rtDW -> TransportDelay9_IWORK . Head + 1 ) : 0 )
; if ( _rtDW -> TransportDelay9_IWORK . Head == _rtDW ->
TransportDelay9_IWORK . Tail ) { if ( !
modPSK_acc_rt_TDelayUpdateTailOrGrowBuf ( & _rtDW -> TransportDelay9_IWORK .
CircularBufSize , & _rtDW -> TransportDelay9_IWORK . Tail , & _rtDW ->
TransportDelay9_IWORK . Head , & _rtDW -> TransportDelay9_IWORK . Last ,
simTime - _rtP -> P_36 , uBuffer , ( boolean_T ) 0 , false , & _rtDW ->
TransportDelay9_IWORK . MaxNewBufSize ) ) { ssSetErrorStatus ( S ,
"tdelay memory allocation error" ) ; return ; } } ( * uBuffer + _rtDW ->
TransportDelay9_IWORK . CircularBufSize ) [ _rtDW -> TransportDelay9_IWORK .
Head ] = simTime ; ( * uBuffer ) [ _rtDW -> TransportDelay9_IWORK . Head ] =
_rtB -> B_13_34_0 ; } { real_T * * uBuffer = ( real_T * * ) & _rtDW ->
TransportDelay11_PWORK . TUbufferPtrs [ 0 ] ; real_T simTime = ssGetT ( S ) ;
_rtDW -> TransportDelay11_IWORK . Head = ( ( _rtDW -> TransportDelay11_IWORK
. Head < ( _rtDW -> TransportDelay11_IWORK . CircularBufSize - 1 ) ) ? (
_rtDW -> TransportDelay11_IWORK . Head + 1 ) : 0 ) ; if ( _rtDW ->
TransportDelay11_IWORK . Head == _rtDW -> TransportDelay11_IWORK . Tail ) {
if ( ! modPSK_acc_rt_TDelayUpdateTailOrGrowBuf ( & _rtDW ->
TransportDelay11_IWORK . CircularBufSize , & _rtDW -> TransportDelay11_IWORK
. Tail , & _rtDW -> TransportDelay11_IWORK . Head , & _rtDW ->
TransportDelay11_IWORK . Last , simTime - _rtP -> P_38 , uBuffer , (
boolean_T ) 0 , false , & _rtDW -> TransportDelay11_IWORK . MaxNewBufSize ) )
{ ssSetErrorStatus ( S , "tdelay memory allocation error" ) ; return ; } } (
* uBuffer + _rtDW -> TransportDelay11_IWORK . CircularBufSize ) [ _rtDW ->
TransportDelay11_IWORK . Head ] = simTime ; ( * uBuffer ) [ _rtDW ->
TransportDelay11_IWORK . Head ] = _rtB -> B_13_36_0 ; } { real_T * * uBuffer
= ( real_T * * ) & _rtDW -> TransportDelay10_PWORK . TUbufferPtrs [ 0 ] ;
real_T simTime = ssGetT ( S ) ; _rtDW -> TransportDelay10_IWORK . Head = ( (
_rtDW -> TransportDelay10_IWORK . Head < ( _rtDW -> TransportDelay10_IWORK .
CircularBufSize - 1 ) ) ? ( _rtDW -> TransportDelay10_IWORK . Head + 1 ) : 0
) ; if ( _rtDW -> TransportDelay10_IWORK . Head == _rtDW ->
TransportDelay10_IWORK . Tail ) { if ( !
modPSK_acc_rt_TDelayUpdateTailOrGrowBuf ( & _rtDW -> TransportDelay10_IWORK .
CircularBufSize , & _rtDW -> TransportDelay10_IWORK . Tail , & _rtDW ->
TransportDelay10_IWORK . Head , & _rtDW -> TransportDelay10_IWORK . Last ,
simTime - _rtP -> P_40 , uBuffer , ( boolean_T ) 0 , false , & _rtDW ->
TransportDelay10_IWORK . MaxNewBufSize ) ) { ssSetErrorStatus ( S ,
"tdelay memory allocation error" ) ; return ; } } ( * uBuffer + _rtDW ->
TransportDelay10_IWORK . CircularBufSize ) [ _rtDW -> TransportDelay10_IWORK
. Head ] = simTime ; ( * uBuffer ) [ _rtDW -> TransportDelay10_IWORK . Head ]
= _rtB -> B_13_38_0 ; } { real_T * * uBuffer = ( real_T * * ) & _rtDW ->
TransportDelay13_PWORK . TUbufferPtrs [ 0 ] ; real_T simTime = ssGetT ( S ) ;
_rtDW -> TransportDelay13_IWORK . Head = ( ( _rtDW -> TransportDelay13_IWORK
. Head < ( _rtDW -> TransportDelay13_IWORK . CircularBufSize - 1 ) ) ? (
_rtDW -> TransportDelay13_IWORK . Head + 1 ) : 0 ) ; if ( _rtDW ->
TransportDelay13_IWORK . Head == _rtDW -> TransportDelay13_IWORK . Tail ) {
if ( ! modPSK_acc_rt_TDelayUpdateTailOrGrowBuf ( & _rtDW ->
TransportDelay13_IWORK . CircularBufSize , & _rtDW -> TransportDelay13_IWORK
. Tail , & _rtDW -> TransportDelay13_IWORK . Head , & _rtDW ->
TransportDelay13_IWORK . Last , simTime - _rtP -> P_42 , uBuffer , (
boolean_T ) 0 , false , & _rtDW -> TransportDelay13_IWORK . MaxNewBufSize ) )
{ ssSetErrorStatus ( S , "tdelay memory allocation error" ) ; return ; } } (
* uBuffer + _rtDW -> TransportDelay13_IWORK . CircularBufSize ) [ _rtDW ->
TransportDelay13_IWORK . Head ] = simTime ; ( * uBuffer ) [ _rtDW ->
TransportDelay13_IWORK . Head ] = _rtB -> B_13_40_0 ; } isHit = ssIsSampleHit
( S , 1 , 0 ) ; if ( isHit != 0 ) { _rtDW -> Memory_PreviousInput_o = _rtB ->
B_13_46_0 ; _rtDW -> ICic_PreviousInput = _rtB -> B_13_53_0 ; _rtDW ->
TmpLatchAtDFlipFlopInport1_PreviousInput = _rtB -> B_4_1_0 ; _rtDW ->
Memory_PreviousInput_a = _rtB -> B_13_102_0 ; _rtDW -> Memory_PreviousInput =
_rtB -> B_13_12_0 ; _rtDW -> ICic_PreviousInput_c = _rtB -> B_13_100_0 ;
_rtDW -> Memory_PreviousInput_ab = _rtB -> B_13_115_0 ; _rtDW ->
Memory_PreviousInput_p = _rtB -> B_13_12_0 ; _rtDW -> ICic_PreviousInput_f =
_rtB -> B_13_113_0 ; } UNUSED_PARAMETER ( tid ) ; }
#define MDL_UPDATE
static void mdlUpdateTID3 ( SimStruct * S , int_T tid ) { UNUSED_PARAMETER (
tid ) ; }
#define MDL_DERIVATIVES
static void mdlDerivatives ( SimStruct * S ) { B_modPSK_T * _rtB ; P_modPSK_T
* _rtP ; XDot_modPSK_T * _rtXdot ; X_modPSK_T * _rtX ; int_T is ; uint32_T ri
; _rtXdot = ( ( XDot_modPSK_T * ) ssGetdX ( S ) ) ; _rtX = ( ( X_modPSK_T * )
ssGetContStates ( S ) ) ; _rtP = ( ( P_modPSK_T * ) ssGetModelRtp ( S ) ) ;
_rtB = ( ( B_modPSK_T * ) _ssGetModelBlockIO ( S ) ) ; _rtXdot ->
AnalogFilterDesign_CSTATE [ 0 ] = 0.0 ; _rtXdot -> AnalogFilterDesign_CSTATE
[ 1 ] = 0.0 ; _rtXdot -> AnalogFilterDesign_CSTATE [ 2 ] = 0.0 ; _rtXdot ->
AnalogFilterDesign_CSTATE [ 3 ] = 0.0 ; for ( ri = _rtP -> P_115 [ 0U ] ; ri
< _rtP -> P_115 [ 1U ] ; ri ++ ) { _rtXdot -> AnalogFilterDesign_CSTATE [
_rtP -> P_114 [ ri ] ] += _rtP -> P_2 [ ri ] * _rtX ->
AnalogFilterDesign_CSTATE [ 0U ] ; } for ( ri = _rtP -> P_115 [ 1U ] ; ri <
_rtP -> P_115 [ 2U ] ; ri ++ ) { _rtXdot -> AnalogFilterDesign_CSTATE [ _rtP
-> P_114 [ ri ] ] += _rtP -> P_2 [ ri ] * _rtX -> AnalogFilterDesign_CSTATE [
1U ] ; } for ( ri = _rtP -> P_115 [ 2U ] ; ri < _rtP -> P_115 [ 3U ] ; ri ++
) { _rtXdot -> AnalogFilterDesign_CSTATE [ _rtP -> P_114 [ ri ] ] += _rtP ->
P_2 [ ri ] * _rtX -> AnalogFilterDesign_CSTATE [ 2U ] ; } for ( ri = _rtP ->
P_115 [ 3U ] ; ri < _rtP -> P_115 [ 4U ] ; ri ++ ) { _rtXdot ->
AnalogFilterDesign_CSTATE [ _rtP -> P_114 [ ri ] ] += _rtP -> P_2 [ ri ] *
_rtX -> AnalogFilterDesign_CSTATE [ 3U ] ; } for ( ri = _rtP -> P_117 [ 0U ]
; ri < _rtP -> P_117 [ 1U ] ; ri ++ ) { _rtXdot -> AnalogFilterDesign_CSTATE
[ _rtP -> P_116 ] += _rtP -> P_3 * _rtB -> B_13_129_0 ; } _rtXdot ->
AnalogFilterDesign_CSTATE_f [ 0 ] = 0.0 ; _rtXdot ->
AnalogFilterDesign_CSTATE_f [ 1 ] = 0.0 ; _rtXdot ->
AnalogFilterDesign_CSTATE_f [ 2 ] = 0.0 ; _rtXdot ->
AnalogFilterDesign_CSTATE_f [ 3 ] = 0.0 ; for ( ri = _rtP -> P_121 [ 0U ] ;
ri < _rtP -> P_121 [ 1U ] ; ri ++ ) { _rtXdot -> AnalogFilterDesign_CSTATE_f
[ _rtP -> P_120 [ ri ] ] += _rtP -> P_8 [ ri ] * _rtX ->
AnalogFilterDesign_CSTATE_f [ 0U ] ; } for ( ri = _rtP -> P_121 [ 1U ] ; ri <
_rtP -> P_121 [ 2U ] ; ri ++ ) { _rtXdot -> AnalogFilterDesign_CSTATE_f [
_rtP -> P_120 [ ri ] ] += _rtP -> P_8 [ ri ] * _rtX ->
AnalogFilterDesign_CSTATE_f [ 1U ] ; } for ( ri = _rtP -> P_121 [ 2U ] ; ri <
_rtP -> P_121 [ 3U ] ; ri ++ ) { _rtXdot -> AnalogFilterDesign_CSTATE_f [
_rtP -> P_120 [ ri ] ] += _rtP -> P_8 [ ri ] * _rtX ->
AnalogFilterDesign_CSTATE_f [ 2U ] ; } for ( ri = _rtP -> P_121 [ 3U ] ; ri <
_rtP -> P_121 [ 4U ] ; ri ++ ) { _rtXdot -> AnalogFilterDesign_CSTATE_f [
_rtP -> P_120 [ ri ] ] += _rtP -> P_8 [ ri ] * _rtX ->
AnalogFilterDesign_CSTATE_f [ 3U ] ; } for ( ri = _rtP -> P_123 [ 0U ] ; ri <
_rtP -> P_123 [ 1U ] ; ri ++ ) { _rtXdot -> AnalogFilterDesign_CSTATE_f [
_rtP -> P_122 ] += _rtP -> P_9 * _rtB -> B_13_86_0 ; } _rtXdot ->
Integrator_CSTATE = _rtB -> B_13_64_0 ; _rtXdot -> ModuloIntegrator_CSTATE =
_rtB -> B_13_124_0 ; _rtXdot -> AnalogFilterDesign_CSTATE_e [ 0 ] = 0.0 ;
_rtXdot -> AnalogFilterDesign_CSTATE_e [ 1 ] = 0.0 ; _rtXdot ->
AnalogFilterDesign_CSTATE_e [ 2 ] = 0.0 ; _rtXdot ->
AnalogFilterDesign_CSTATE_e [ 3 ] = 0.0 ; for ( ri = _rtP -> P_127 [ 0U ] ;
ri < _rtP -> P_127 [ 1U ] ; ri ++ ) { _rtXdot -> AnalogFilterDesign_CSTATE_e
[ _rtP -> P_126 [ ri ] ] += _rtP -> P_47 [ ri ] * _rtX ->
AnalogFilterDesign_CSTATE_e [ 0U ] ; } for ( ri = _rtP -> P_127 [ 1U ] ; ri <
_rtP -> P_127 [ 2U ] ; ri ++ ) { _rtXdot -> AnalogFilterDesign_CSTATE_e [
_rtP -> P_126 [ ri ] ] += _rtP -> P_47 [ ri ] * _rtX ->
AnalogFilterDesign_CSTATE_e [ 1U ] ; } for ( ri = _rtP -> P_127 [ 2U ] ; ri <
_rtP -> P_127 [ 3U ] ; ri ++ ) { _rtXdot -> AnalogFilterDesign_CSTATE_e [
_rtP -> P_126 [ ri ] ] += _rtP -> P_47 [ ri ] * _rtX ->
AnalogFilterDesign_CSTATE_e [ 2U ] ; } for ( ri = _rtP -> P_127 [ 3U ] ; ri <
_rtP -> P_127 [ 4U ] ; ri ++ ) { _rtXdot -> AnalogFilterDesign_CSTATE_e [
_rtP -> P_126 [ ri ] ] += _rtP -> P_47 [ ri ] * _rtX ->
AnalogFilterDesign_CSTATE_e [ 3U ] ; } for ( ri = _rtP -> P_129 [ 0U ] ; ri <
_rtP -> P_129 [ 1U ] ; ri ++ ) { _rtXdot -> AnalogFilterDesign_CSTATE_e [
_rtP -> P_128 ] += _rtP -> P_48 * _rtB -> B_13_4_0 ; } for ( is = 0 ; is < 8
; is ++ ) { _rtXdot -> AnalogFilterDesign_CSTATE_p [ is ] = 0.0 ; } for ( is
= 0 ; is < 8 ; is ++ ) { for ( ri = _rtP -> P_133 [ ( uint32_T ) is ] ; ri <
_rtP -> P_133 [ is + 1U ] ; ri ++ ) { _rtXdot -> AnalogFilterDesign_CSTATE_p
[ _rtP -> P_132 [ ri ] ] += _rtP -> P_51 [ ri ] * _rtX ->
AnalogFilterDesign_CSTATE_p [ ( uint32_T ) is ] ; } } for ( ri = _rtP ->
P_135 [ 0U ] ; ri < _rtP -> P_135 [ 1U ] ; ri ++ ) { _rtXdot ->
AnalogFilterDesign_CSTATE_p [ _rtP -> P_134 ] += _rtP -> P_52 * _rtB ->
B_13_66_0 ; } _rtXdot -> ModuloIntegrator_CSTATE_p = _rtB -> B_13_81_0 ;
_rtXdot -> Integrator_CSTATE_d = _rtB -> B_13_87_0 ; _rtXdot ->
Integrator1_CSTATE = _rtB -> B_13_89_0 ; _rtXdot -> Integrator_CSTATE_p =
_rtB -> B_13_89_0 ; } static void mdlInitializeSizes ( SimStruct * S ) {
ssSetChecksumVal ( S , 0 , 2759449342U ) ; ssSetChecksumVal ( S , 1 ,
4237653897U ) ; ssSetChecksumVal ( S , 2 , 4059200132U ) ; ssSetChecksumVal (
S , 3 , 1916353250U ) ; { mxArray * slVerStructMat = ( NULL ) ; mxArray *
slStrMat = mxCreateString ( "simulink" ) ; char slVerChar [ 10 ] ; int status
= mexCallMATLAB ( 1 , & slVerStructMat , 1 , & slStrMat , "ver" ) ; if (
status == 0 ) { mxArray * slVerMat = mxGetField ( slVerStructMat , 0 ,
"Version" ) ; if ( slVerMat == ( NULL ) ) { status = 1 ; } else { status =
mxGetString ( slVerMat , slVerChar , 10 ) ; } } mxDestroyArray ( slStrMat ) ;
mxDestroyArray ( slVerStructMat ) ; if ( ( status == 1 ) || ( strcmp (
slVerChar , "10.5" ) != 0 ) ) { return ; } } ssSetOptions ( S ,
SS_OPTION_EXCEPTION_FREE_CODE ) ; if ( ssGetSizeofDWork ( S ) != sizeof (
DW_modPSK_T ) ) { ssSetErrorStatus ( S ,
"Unexpected error: Internal DWork sizes do "
"not match for accelerator mex file." ) ; } if ( ssGetSizeofGlobalBlockIO ( S
) != sizeof ( B_modPSK_T ) ) { ssSetErrorStatus ( S ,
"Unexpected error: Internal BlockIO sizes do "
"not match for accelerator mex file." ) ; } { int ssSizeofParams ;
ssGetSizeofParams ( S , & ssSizeofParams ) ; if ( ssSizeofParams != sizeof (
P_modPSK_T ) ) { static char msg [ 256 ] ; sprintf ( msg ,
"Unexpected error: Internal Parameters sizes do "
"not match for accelerator mex file." ) ; } } _ssSetModelRtp ( S , ( real_T *
) & modPSK_rtDefaultP ) ; } static void mdlInitializeSampleTimes ( SimStruct
* S ) { slAccRegPrmChangeFcn ( S , mdlOutputsTID3 ) ; } static void
mdlTerminate ( SimStruct * S ) { }
#include "simulink.c"
