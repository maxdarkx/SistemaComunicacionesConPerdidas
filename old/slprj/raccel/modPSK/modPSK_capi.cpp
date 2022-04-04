#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "modPSK_capi_host.h"
#define sizeof(s) ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el) ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s) (s)
#else
#include "builtin_typeid_types.h"
#include "modPSK.h"
#include "modPSK_capi.h"
#include "modPSK_private.h"
#ifdef LIGHT_WEIGHT_CAPI
#define TARGET_CONST
#define TARGET_STRING(s)               ((NULL))
#else
#define TARGET_CONST                   const
#define TARGET_STRING(s)               (s)
#endif
#endif
static const rtwCAPI_Signals rtBlockSignals [ ] = { { 0 , 0 , TARGET_STRING (
"modPSK/Canal/Ruido AGWN" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , {
1 , 0 , TARGET_STRING ( "modPSK/Canal/Add" ) , TARGET_STRING ( "" ) , 0 , 0 ,
0 , 0 , 1 } , { 2 , 0 , TARGET_STRING (
"modPSK/Signal From Workspace/From Workspace" ) , TARGET_STRING ( "" ) , 0 ,
0 , 0 , 0 , 2 } , { 3 , 0 , TARGET_STRING ( "modPSK/Transmisor/Add Constant"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 2 } , { 4 , 0 , TARGET_STRING (
"modPSK/Transmisor/Product" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } ,
{ 5 , 0 , TARGET_STRING ( "modPSK/Transmisor/Analog Filter Design" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 6 , 0 , TARGET_STRING (
"modPSK/Receptor/Correlación/Integrator" ) , TARGET_STRING ( "" ) , 0 , 0 ,
0 , 0 , 1 } , { 7 , 0 , TARGET_STRING (
"modPSK/Receptor/Correlación/Product" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 ,
0 , 1 } , { 8 , 0 , TARGET_STRING (
"modPSK/Receptor/Correlación/Analog Filter Design" ) , TARGET_STRING ( "" )
, 0 , 0 , 0 , 0 , 1 } , { 9 , 0 , TARGET_STRING (
"modPSK/Receptor/Correlación/Transport Delay" ) , TARGET_STRING ( "" ) , 0 ,
0 , 0 , 0 , 1 } , { 10 , 1 , TARGET_STRING (
"modPSK/Receptor/Detector/Sample and Hold" ) , TARGET_STRING ( "" ) , 0 , 0 ,
0 , 0 , 3 } , { 11 , 0 , TARGET_STRING ( "modPSK/Receptor/Detector/Sign" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 4 } , { 12 , 0 , TARGET_STRING (
"modPSK/Receptor/Polar/Multiply" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 4
} , { 13 , 0 , TARGET_STRING (
"modPSK/Receptor/Sincronismo de Trama/Product4" ) , TARGET_STRING ( "" ) , 0
, 0 , 0 , 0 , 4 } , { 14 , 0 , TARGET_STRING (
"modPSK/Receptor/Sincronismo de Trama/Add" ) , TARGET_STRING ( "" ) , 0 , 0 ,
0 , 0 , 1 } , { 15 , 0 , TARGET_STRING (
"modPSK/Receptor/Sincronismo de Trama/Switch" ) , TARGET_STRING ( "" ) , 0 ,
0 , 0 , 0 , 1 } , { 16 , 0 , TARGET_STRING (
"modPSK/Receptor/Sincronismo de Trama/Switch1" ) , TARGET_STRING ( "" ) , 0 ,
0 , 0 , 0 , 1 } , { 17 , 0 , TARGET_STRING (
"modPSK/Receptor/Sincronismo de Trama/Transport Delay1" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 1 } , { 18 , 0 , TARGET_STRING (
"modPSK/Receptor/Sincronismo de Trama/Transport Delay12" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 1 } , { 19 , 0 , TARGET_STRING (
"modPSK/Receptor/Sincronismo de Trama/Transport Delay2" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 1 } , { 20 , 0 , TARGET_STRING (
"modPSK/Receptor/Sincronismo de Trama/Transport Delay3" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 1 } , { 21 , 0 , TARGET_STRING (
"modPSK/Receptor/Sincronismo de Trama/Transport Delay4" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 1 } , { 22 , 0 , TARGET_STRING (
"modPSK/Receptor/Sincronismo de Trama/Transport Delay5" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 1 } , { 23 , 0 , TARGET_STRING (
"modPSK/Receptor/Sincronismo de Trama/Transport Delay6" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 1 } , { 24 , 0 , TARGET_STRING (
"modPSK/Receptor/Sincronismo de Trama/Transport Delay7" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 1 } , { 25 , 0 , TARGET_STRING (
"modPSK/Receptor/Sincronismo de Trama/Transport Delay8" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 1 } , { 26 , 0 , TARGET_STRING (
"modPSK/Receptor/Sincronismo de Trama/Transport Delay9" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 1 } , { 27 , 0 , TARGET_STRING (
"modPSK/Receptor/Sincronismo de portadora/Product3" ) , TARGET_STRING ( "" )
, 0 , 0 , 0 , 0 , 1 } , { 28 , 0 , TARGET_STRING (
"modPSK/Receptor/Sincronismo de portadora/Product4" ) , TARGET_STRING ( "" )
, 0 , 0 , 0 , 0 , 1 } , { 29 , 0 , TARGET_STRING (
"modPSK/Receptor/Sincronismo de portadora/Add1" ) , TARGET_STRING ( "" ) , 0
, 0 , 0 , 0 , 4 } , { 30 , 10 , TARGET_STRING (
"modPSK/Receptor/Sincronismo de símbolo/Sample and Hold" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 3 } , { 31 , 11 , TARGET_STRING (
"modPSK/Receptor/Sincronismo de símbolo/Sample and Hold2" ) , TARGET_STRING
( "" ) , 0 , 0 , 0 , 0 , 3 } , { 32 , 0 , TARGET_STRING (
"modPSK/Receptor/Sincronismo de símbolo/Abs" ) , TARGET_STRING ( "" ) , 0 ,
0 , 0 , 0 , 4 } , { 33 , 0 , TARGET_STRING (
"modPSK/Receptor/Sincronismo de símbolo/Integrator" ) , TARGET_STRING ( "" )
, 0 , 0 , 0 , 0 , 1 } , { 34 , 0 , TARGET_STRING (
"modPSK/Receptor/Sincronismo de símbolo/Integrator1" ) , TARGET_STRING ( ""
) , 0 , 0 , 0 , 0 , 1 } , { 35 , 0 , TARGET_STRING (
"modPSK/Receptor/Sincronismo de símbolo/Product2" ) , TARGET_STRING ( "" ) ,
0 , 0 , 0 , 0 , 1 } , { 36 , 0 , TARGET_STRING (
"modPSK/Receptor/Sincronismo de símbolo/Sign" ) , TARGET_STRING ( "" ) , 0 ,
0 , 0 , 0 , 4 } , { 37 , 0 , TARGET_STRING (
"modPSK/Receptor/Sincronismo de símbolo/Sign1" ) , TARGET_STRING ( "" ) , 0
, 0 , 0 , 0 , 4 } , { 38 , 0 , TARGET_STRING (
"modPSK/Receptor/Sincronismo de símbolo/Sum" ) , TARGET_STRING ( "" ) , 0 ,
0 , 0 , 0 , 1 } , { 39 , 1 , TARGET_STRING (
"modPSK/Receptor/Detector/Sample and Hold/In" ) , TARGET_STRING ( "" ) , 0 ,
0 , 0 , 0 , 3 } , { 40 , 0 , TARGET_STRING (
"modPSK/Receptor/Sincronismo de portadora/ VCO/Inherit Shape" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 41 , 0 , TARGET_STRING (
"modPSK/Receptor/Sincronismo de portadora/ VCO/Sum" ) , TARGET_STRING ( "" )
, 0 , 0 , 0 , 0 , 1 } , { 42 , 5 , TARGET_STRING (
"modPSK/Receptor/Sincronismo de portadora/D Flip-Flop/D Flip-Flop" ) ,
TARGET_STRING ( "" ) , 0 , 1 , 0 , 0 , 3 } , { 43 , 5 , TARGET_STRING (
"modPSK/Receptor/Sincronismo de portadora/D Flip-Flop/D Flip-Flop" ) ,
TARGET_STRING ( "" ) , 1 , 1 , 0 , 0 , 3 } , { 44 , 0 , TARGET_STRING (
"modPSK/Receptor/Sincronismo de símbolo/Continuous-Time VCO/Inherit Shape" )
, TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 45 , 0 , TARGET_STRING (
"modPSK/Receptor/Sincronismo de símbolo/Continuous-Time VCO/Sum" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 4 } , { 46 , 0 , TARGET_STRING (
"modPSK/Receptor/Sincronismo de símbolo/Monostable1/Clock" ) , TARGET_STRING
( "" ) , 0 , 0 , 0 , 0 , 1 } , { 47 , 0 , TARGET_STRING (
"modPSK/Receptor/Sincronismo de símbolo/Monostable1/Logical Operator1" ) ,
TARGET_STRING ( "" ) , 0 , 1 , 0 , 0 , 4 } , { 48 , 0 , TARGET_STRING (
"modPSK/Receptor/Sincronismo de símbolo/Monostable1/Relational Operator" ) ,
TARGET_STRING ( "" ) , 0 , 1 , 0 , 0 , 4 } , { 49 , 0 , TARGET_STRING (
"modPSK/Receptor/Sincronismo de símbolo/Monostable1/Sum" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 1 } , { 50 , 0 , TARGET_STRING (
"modPSK/Receptor/Sincronismo de símbolo/Monostable3/Clock" ) , TARGET_STRING
( "" ) , 0 , 0 , 0 , 0 , 1 } , { 51 , 0 , TARGET_STRING (
"modPSK/Receptor/Sincronismo de símbolo/Monostable3/Logical Operator1" ) ,
TARGET_STRING ( "" ) , 0 , 1 , 0 , 0 , 4 } , { 52 , 0 , TARGET_STRING (
"modPSK/Receptor/Sincronismo de símbolo/Monostable3/Relational Operator" ) ,
TARGET_STRING ( "" ) , 0 , 1 , 0 , 0 , 4 } , { 53 , 0 , TARGET_STRING (
"modPSK/Receptor/Sincronismo de símbolo/Monostable3/Sum" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 1 } , { 54 , 10 , TARGET_STRING (
"modPSK/Receptor/Sincronismo de símbolo/Sample and Hold/In" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 3 } , { 55 , 11 , TARGET_STRING (
"modPSK/Receptor/Sincronismo de símbolo/Sample and Hold2/In" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 3 } , { 56 , 0 , TARGET_STRING (
"modPSK/Receptor/Sincronismo de Trama/Monostable/Model/Clock" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 57 , 0 , TARGET_STRING (
"modPSK/Receptor/Sincronismo de Trama/Monostable/Model/T_monostable" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 4 } , { 58 , 0 , TARGET_STRING (
"modPSK/Receptor/Sincronismo de Trama/Monostable/Model/Data Type Conversion2"
) , TARGET_STRING ( "" ) , 0 , 1 , 0 , 0 , 1 } , { 59 , 0 , TARGET_STRING (
"modPSK/Receptor/Sincronismo de Trama/Monostable/Model/Logical Operator1" ) ,
TARGET_STRING ( "" ) , 0 , 1 , 0 , 0 , 4 } , { 60 , 0 , TARGET_STRING (
"modPSK/Receptor/Sincronismo de Trama/Monostable/Model/Relational Operator" )
, TARGET_STRING ( "" ) , 0 , 1 , 0 , 0 , 4 } , { 61 , 0 , TARGET_STRING (
"modPSK/Receptor/Sincronismo de Trama/Monostable/Model/Sum" ) , TARGET_STRING
( "" ) , 0 , 0 , 0 , 0 , 1 } , { 62 , 5 , TARGET_STRING (
"modPSK/Receptor/Sincronismo de portadora/D Flip-Flop/D Flip-Flop/D" ) ,
TARGET_STRING ( "" ) , 0 , 1 , 0 , 0 , 3 } , { 63 , 5 , TARGET_STRING (
"modPSK/Receptor/Sincronismo de portadora/D Flip-Flop/D Flip-Flop/Logic" ) ,
TARGET_STRING ( "" ) , 0 , 1 , 0 , 0 , 3 } , { 64 , 6 , TARGET_STRING (
 "modPSK/Receptor/Sincronismo de símbolo/Monostable1/Edge Detector/NEGATIVE Edge"
) , TARGET_STRING ( "" ) , 0 , 1 , 0 , 0 , 4 } , { 65 , 7 , TARGET_STRING (
 "modPSK/Receptor/Sincronismo de símbolo/Monostable1/Edge Detector/POSITIVE Edge"
) , TARGET_STRING ( "" ) , 0 , 1 , 0 , 0 , 4 } , { 66 , 0 , TARGET_STRING (
 "modPSK/Receptor/Sincronismo de símbolo/Monostable1/Edge Detector/Multiport Switch"
) , TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 5 } , { 67 , 0 , TARGET_STRING (
"modPSK/Receptor/Sincronismo de símbolo/Monostable1/Sample & Hold/IC=ic" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 4 } , { 68 , 0 , TARGET_STRING (
"modPSK/Receptor/Sincronismo de símbolo/Monostable1/Sample & Hold/Switch" )
, TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 69 , 8 , TARGET_STRING (
 "modPSK/Receptor/Sincronismo de símbolo/Monostable3/Edge Detector/NEGATIVE Edge"
) , TARGET_STRING ( "" ) , 0 , 1 , 0 , 0 , 4 } , { 70 , 9 , TARGET_STRING (
 "modPSK/Receptor/Sincronismo de símbolo/Monostable3/Edge Detector/POSITIVE Edge"
) , TARGET_STRING ( "" ) , 0 , 1 , 0 , 0 , 4 } , { 71 , 0 , TARGET_STRING (
 "modPSK/Receptor/Sincronismo de símbolo/Monostable3/Edge Detector/Multiport Switch"
) , TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 5 } , { 72 , 0 , TARGET_STRING (
"modPSK/Receptor/Sincronismo de símbolo/Monostable3/Sample & Hold/IC=ic" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 4 } , { 73 , 0 , TARGET_STRING (
"modPSK/Receptor/Sincronismo de símbolo/Monostable3/Sample & Hold/Switch" )
, TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 74 , 3 , TARGET_STRING (
 "modPSK/Receptor/Sincronismo de Trama/Monostable/Model/Continuous Edge Detector/NEGATIVE Edge"
) , TARGET_STRING ( "" ) , 0 , 1 , 0 , 0 , 4 } , { 75 , 4 , TARGET_STRING (
 "modPSK/Receptor/Sincronismo de Trama/Monostable/Model/Continuous Edge Detector/POSITIVE Edge"
) , TARGET_STRING ( "" ) , 0 , 1 , 0 , 0 , 4 } , { 76 , 0 , TARGET_STRING (
 "modPSK/Receptor/Sincronismo de Trama/Monostable/Model/Continuous Edge Detector/Multiport Switch"
) , TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 5 } , { 77 , 6 , TARGET_STRING (
 "modPSK/Receptor/Sincronismo de símbolo/Monostable1/Edge Detector/NEGATIVE Edge/Relational Operator1"
) , TARGET_STRING ( "" ) , 0 , 1 , 0 , 0 , 4 } , { 78 , 7 , TARGET_STRING (
 "modPSK/Receptor/Sincronismo de símbolo/Monostable1/Edge Detector/POSITIVE Edge/Relational Operator1"
) , TARGET_STRING ( "" ) , 0 , 1 , 0 , 0 , 4 } , { 79 , 8 , TARGET_STRING (
 "modPSK/Receptor/Sincronismo de símbolo/Monostable3/Edge Detector/NEGATIVE Edge/Relational Operator1"
) , TARGET_STRING ( "" ) , 0 , 1 , 0 , 0 , 4 } , { 80 , 9 , TARGET_STRING (
 "modPSK/Receptor/Sincronismo de símbolo/Monostable3/Edge Detector/POSITIVE Edge/Relational Operator1"
) , TARGET_STRING ( "" ) , 0 , 1 , 0 , 0 , 4 } , { 81 , 2 , TARGET_STRING (
 "modPSK/Receptor/Sincronismo de Trama/Monostable/Model/Continuous Edge Detector/Internal dirac generator/Triggered Subsystem"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 3 } , { 82 , 0 , TARGET_STRING (
 "modPSK/Receptor/Sincronismo de Trama/Monostable/Model/Continuous Edge Detector/Internal dirac generator/Clock"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 83 , 0 , TARGET_STRING (
 "modPSK/Receptor/Sincronismo de Trama/Monostable/Model/Continuous Edge Detector/Internal dirac generator/Sum"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 4 } , { 84 , 3 , TARGET_STRING (
 "modPSK/Receptor/Sincronismo de Trama/Monostable/Model/Continuous Edge Detector/NEGATIVE Edge/Relational Operator1"
) , TARGET_STRING ( "" ) , 0 , 1 , 0 , 0 , 4 } , { 85 , 4 , TARGET_STRING (
 "modPSK/Receptor/Sincronismo de Trama/Monostable/Model/Continuous Edge Detector/POSITIVE Edge/Relational Operator1"
) , TARGET_STRING ( "" ) , 0 , 1 , 0 , 0 , 4 } , { 86 , 0 , TARGET_STRING (
 "modPSK/Receptor/Sincronismo de Trama/Monostable/Model/Sample and Hold/Model/IC=ic"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 4 } , { 87 , 0 , TARGET_STRING (
 "modPSK/Receptor/Sincronismo de Trama/Monostable/Model/Sample and Hold/Model/Switch"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 88 , 2 , TARGET_STRING (
 "modPSK/Receptor/Sincronismo de Trama/Monostable/Model/Continuous Edge Detector/Internal dirac generator/Triggered Subsystem/In1"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 3 } , { 0 , 0 , ( NULL ) , ( NULL
) , 0 , 0 , 0 , 0 , 0 } } ; static const rtwCAPI_BlockParameters
rtBlockParameters [ ] = { { 89 , TARGET_STRING ( "modPSK/Canal/Ruido AGWN" )
, TARGET_STRING ( "Mean" ) , 0 , 0 , 0 } , { 90 , TARGET_STRING (
"modPSK/Canal/Ruido AGWN" ) , TARGET_STRING ( "Seed" ) , 0 , 0 , 0 } , { 91 ,
TARGET_STRING ( "modPSK/Canal/Transport Delay" ) , TARGET_STRING (
"InitialOutput" ) , 0 , 0 , 0 } , { 92 , TARGET_STRING (
"modPSK/Signal From Workspace/From Workspace" ) , TARGET_STRING ( "Data0" ) ,
0 , 2 , 0 } , { 93 , TARGET_STRING ( "modPSK/Transmisor/Add Constant" ) ,
TARGET_STRING ( "Bias" ) , 0 , 0 , 0 } , { 94 , TARGET_STRING (
"modPSK/Transmisor/Multiply" ) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , {
95 , TARGET_STRING ( "modPSK/Transmisor/Sine Wave" ) , TARGET_STRING ( "Bias"
) , 0 , 0 , 0 } , { 96 , TARGET_STRING ( "modPSK/Transmisor/Sine Wave" ) ,
TARGET_STRING ( "Phase" ) , 0 , 0 , 0 } , { 97 , TARGET_STRING (
"modPSK/Transmisor/Analog Filter Design" ) , TARGET_STRING ( "A_pr" ) , 0 , 3
, 0 } , { 98 , TARGET_STRING ( "modPSK/Transmisor/Analog Filter Design" ) ,
TARGET_STRING ( "A_ir" ) , 2 , 3 , 0 } , { 99 , TARGET_STRING (
"modPSK/Transmisor/Analog Filter Design" ) , TARGET_STRING ( "A_jc" ) , 2 , 4
, 0 } , { 100 , TARGET_STRING ( "modPSK/Transmisor/Analog Filter Design" ) ,
TARGET_STRING ( "B_pr" ) , 0 , 0 , 0 } , { 101 , TARGET_STRING (
"modPSK/Transmisor/Analog Filter Design" ) , TARGET_STRING ( "B_ir" ) , 2 , 0
, 0 } , { 102 , TARGET_STRING ( "modPSK/Transmisor/Analog Filter Design" ) ,
TARGET_STRING ( "B_jc" ) , 2 , 1 , 0 } , { 103 , TARGET_STRING (
"modPSK/Transmisor/Analog Filter Design" ) , TARGET_STRING ( "C_pr" ) , 0 , 0
, 0 } , { 104 , TARGET_STRING ( "modPSK/Transmisor/Analog Filter Design" ) ,
TARGET_STRING ( "C_ir" ) , 2 , 0 , 0 } , { 105 , TARGET_STRING (
"modPSK/Transmisor/Analog Filter Design" ) , TARGET_STRING ( "C_jc" ) , 2 , 4
, 0 } , { 106 , TARGET_STRING ( "modPSK/Transmisor/Analog Filter Design" ) ,
TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 107 , TARGET_STRING (
"modPSK/Receptor/Correlación/Integrator" ) , TARGET_STRING (
"InitialCondition" ) , 0 , 0 , 0 } , { 108 , TARGET_STRING (
"modPSK/Receptor/Correlación/Analog Filter Design" ) , TARGET_STRING (
"A_pr" ) , 0 , 5 , 0 } , { 109 , TARGET_STRING (
"modPSK/Receptor/Correlación/Analog Filter Design" ) , TARGET_STRING (
"A_ir" ) , 2 , 5 , 0 } , { 110 , TARGET_STRING (
"modPSK/Receptor/Correlación/Analog Filter Design" ) , TARGET_STRING (
"A_jc" ) , 2 , 6 , 0 } , { 111 , TARGET_STRING (
"modPSK/Receptor/Correlación/Analog Filter Design" ) , TARGET_STRING (
"B_pr" ) , 0 , 0 , 0 } , { 112 , TARGET_STRING (
"modPSK/Receptor/Correlación/Analog Filter Design" ) , TARGET_STRING (
"B_ir" ) , 2 , 0 , 0 } , { 113 , TARGET_STRING (
"modPSK/Receptor/Correlación/Analog Filter Design" ) , TARGET_STRING (
"B_jc" ) , 2 , 1 , 0 } , { 114 , TARGET_STRING (
"modPSK/Receptor/Correlación/Analog Filter Design" ) , TARGET_STRING (
"C_pr" ) , 0 , 0 , 0 } , { 115 , TARGET_STRING (
"modPSK/Receptor/Correlación/Analog Filter Design" ) , TARGET_STRING (
"C_ir" ) , 2 , 0 , 0 } , { 116 , TARGET_STRING (
"modPSK/Receptor/Correlación/Analog Filter Design" ) , TARGET_STRING (
"C_jc" ) , 2 , 6 , 0 } , { 117 , TARGET_STRING (
"modPSK/Receptor/Correlación/Analog Filter Design" ) , TARGET_STRING (
"InitialCondition" ) , 0 , 0 , 0 } , { 118 , TARGET_STRING (
"modPSK/Receptor/Correlación/Transport Delay" ) , TARGET_STRING (
"DelayTime" ) , 0 , 0 , 0 } , { 119 , TARGET_STRING (
"modPSK/Receptor/Correlación/Transport Delay" ) , TARGET_STRING (
"InitialOutput" ) , 0 , 0 , 0 } , { 120 , TARGET_STRING (
"modPSK/Receptor/Polar/Add Constant" ) , TARGET_STRING ( "Bias" ) , 0 , 0 , 0
} , { 121 , TARGET_STRING ( "modPSK/Receptor/Polar/Multiply" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 122 , TARGET_STRING (
"modPSK/Receptor/Sincronismo de Trama/Monostable" ) , TARGET_STRING ( "ic" )
, 1 , 0 , 0 } , { 123 , TARGET_STRING (
"modPSK/Receptor/Sincronismo de Trama/Constant1" ) , TARGET_STRING ( "Value"
) , 0 , 0 , 0 } , { 124 , TARGET_STRING (
"modPSK/Receptor/Sincronismo de Trama/Constant10" ) , TARGET_STRING ( "Value"
) , 0 , 0 , 0 } , { 125 , TARGET_STRING (
"modPSK/Receptor/Sincronismo de Trama/Constant13" ) , TARGET_STRING ( "Value"
) , 0 , 0 , 0 } , { 126 , TARGET_STRING (
"modPSK/Receptor/Sincronismo de Trama/Constant14" ) , TARGET_STRING ( "Value"
) , 0 , 0 , 0 } , { 127 , TARGET_STRING (
"modPSK/Receptor/Sincronismo de Trama/Constant15" ) , TARGET_STRING ( "Value"
) , 0 , 0 , 0 } , { 128 , TARGET_STRING (
"modPSK/Receptor/Sincronismo de Trama/Constant16" ) , TARGET_STRING ( "Value"
) , 0 , 0 , 0 } , { 129 , TARGET_STRING (
"modPSK/Receptor/Sincronismo de Trama/Constant2" ) , TARGET_STRING ( "Value"
) , 0 , 0 , 0 } , { 130 , TARGET_STRING (
"modPSK/Receptor/Sincronismo de Trama/Constant3" ) , TARGET_STRING ( "Value"
) , 0 , 0 , 0 } , { 131 , TARGET_STRING (
"modPSK/Receptor/Sincronismo de Trama/Constant4" ) , TARGET_STRING ( "Value"
) , 0 , 0 , 0 } , { 132 , TARGET_STRING (
"modPSK/Receptor/Sincronismo de Trama/Constant5" ) , TARGET_STRING ( "Value"
) , 0 , 0 , 0 } , { 133 , TARGET_STRING (
"modPSK/Receptor/Sincronismo de Trama/Constant6" ) , TARGET_STRING ( "Value"
) , 0 , 0 , 0 } , { 134 , TARGET_STRING (
"modPSK/Receptor/Sincronismo de Trama/Constant7" ) , TARGET_STRING ( "Value"
) , 0 , 0 , 0 } , { 135 , TARGET_STRING (
"modPSK/Receptor/Sincronismo de Trama/Constant8" ) , TARGET_STRING ( "Value"
) , 0 , 0 , 0 } , { 136 , TARGET_STRING (
"modPSK/Receptor/Sincronismo de Trama/Constant9" ) , TARGET_STRING ( "Value"
) , 0 , 0 , 0 } , { 137 , TARGET_STRING (
"modPSK/Receptor/Sincronismo de Trama/Switch" ) , TARGET_STRING ( "Threshold"
) , 0 , 0 , 0 } , { 138 , TARGET_STRING (
"modPSK/Receptor/Sincronismo de Trama/Transport Delay1" ) , TARGET_STRING (
"InitialOutput" ) , 0 , 0 , 0 } , { 139 , TARGET_STRING (
"modPSK/Receptor/Sincronismo de Trama/Transport Delay11" ) , TARGET_STRING (
"InitialOutput" ) , 0 , 0 , 0 } , { 140 , TARGET_STRING (
"modPSK/Receptor/Sincronismo de Trama/Transport Delay12" ) , TARGET_STRING (
"InitialOutput" ) , 0 , 0 , 0 } , { 141 , TARGET_STRING (
"modPSK/Receptor/Sincronismo de Trama/Transport Delay2" ) , TARGET_STRING (
"InitialOutput" ) , 0 , 0 , 0 } , { 142 , TARGET_STRING (
"modPSK/Receptor/Sincronismo de Trama/Transport Delay3" ) , TARGET_STRING (
"InitialOutput" ) , 0 , 0 , 0 } , { 143 , TARGET_STRING (
"modPSK/Receptor/Sincronismo de Trama/Transport Delay4" ) , TARGET_STRING (
"InitialOutput" ) , 0 , 0 , 0 } , { 144 , TARGET_STRING (
"modPSK/Receptor/Sincronismo de Trama/Transport Delay5" ) , TARGET_STRING (
"InitialOutput" ) , 0 , 0 , 0 } , { 145 , TARGET_STRING (
"modPSK/Receptor/Sincronismo de Trama/Transport Delay6" ) , TARGET_STRING (
"InitialOutput" ) , 0 , 0 , 0 } , { 146 , TARGET_STRING (
"modPSK/Receptor/Sincronismo de Trama/Transport Delay7" ) , TARGET_STRING (
"InitialOutput" ) , 0 , 0 , 0 } , { 147 , TARGET_STRING (
"modPSK/Receptor/Sincronismo de Trama/Transport Delay8" ) , TARGET_STRING (
"InitialOutput" ) , 0 , 0 , 0 } , { 148 , TARGET_STRING (
"modPSK/Receptor/Sincronismo de Trama/Transport Delay9" ) , TARGET_STRING (
"InitialOutput" ) , 0 , 0 , 0 } , { 149 , TARGET_STRING (
"modPSK/Receptor/Sincronismo de portadora/Constant2" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 150 , TARGET_STRING (
"modPSK/Receptor/Sincronismo de portadora/Constant5" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 151 , TARGET_STRING (
"modPSK/Receptor/Sincronismo de portadora/Constant6" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 152 , TARGET_STRING (
"modPSK/Receptor/Sincronismo de portadora/Integrator" ) , TARGET_STRING (
"InitialCondition" ) , 0 , 0 , 0 } , { 153 , TARGET_STRING (
"modPSK/Receptor/Sincronismo de portadora/Analog Filter Design" ) ,
TARGET_STRING ( "A_pr" ) , 0 , 3 , 0 } , { 154 , TARGET_STRING (
"modPSK/Receptor/Sincronismo de portadora/Analog Filter Design" ) ,
TARGET_STRING ( "A_ir" ) , 2 , 3 , 0 } , { 155 , TARGET_STRING (
"modPSK/Receptor/Sincronismo de portadora/Analog Filter Design" ) ,
TARGET_STRING ( "A_jc" ) , 2 , 4 , 0 } , { 156 , TARGET_STRING (
"modPSK/Receptor/Sincronismo de portadora/Analog Filter Design" ) ,
TARGET_STRING ( "B_pr" ) , 0 , 0 , 0 } , { 157 , TARGET_STRING (
"modPSK/Receptor/Sincronismo de portadora/Analog Filter Design" ) ,
TARGET_STRING ( "B_ir" ) , 2 , 0 , 0 } , { 158 , TARGET_STRING (
"modPSK/Receptor/Sincronismo de portadora/Analog Filter Design" ) ,
TARGET_STRING ( "B_jc" ) , 2 , 1 , 0 } , { 159 , TARGET_STRING (
"modPSK/Receptor/Sincronismo de portadora/Analog Filter Design" ) ,
TARGET_STRING ( "C_pr" ) , 0 , 0 , 0 } , { 160 , TARGET_STRING (
"modPSK/Receptor/Sincronismo de portadora/Analog Filter Design" ) ,
TARGET_STRING ( "C_ir" ) , 2 , 0 , 0 } , { 161 , TARGET_STRING (
"modPSK/Receptor/Sincronismo de portadora/Analog Filter Design" ) ,
TARGET_STRING ( "C_jc" ) , 2 , 4 , 0 } , { 162 , TARGET_STRING (
"modPSK/Receptor/Sincronismo de portadora/Analog Filter Design" ) ,
TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 163 , TARGET_STRING (
"modPSK/Receptor/Sincronismo de símbolo/Monostable1" ) , TARGET_STRING (
"EdgeDetect" ) , 0 , 0 , 0 } , { 164 , TARGET_STRING (
"modPSK/Receptor/Sincronismo de símbolo/Monostable1" ) , TARGET_STRING (
"ic" ) , 0 , 0 , 0 } , { 165 , TARGET_STRING (
"modPSK/Receptor/Sincronismo de símbolo/Monostable3" ) , TARGET_STRING (
"EdgeDetect" ) , 0 , 0 , 0 } , { 166 , TARGET_STRING (
"modPSK/Receptor/Sincronismo de símbolo/Monostable3" ) , TARGET_STRING (
"ic" ) , 0 , 0 , 0 } , { 167 , TARGET_STRING (
"modPSK/Receptor/Sincronismo de símbolo/Constant1" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 168 , TARGET_STRING (
"modPSK/Receptor/Sincronismo de símbolo/Integrator" ) , TARGET_STRING (
"InitialCondition" ) , 0 , 0 , 0 } , { 169 , TARGET_STRING (
"modPSK/Receptor/Sincronismo de símbolo/Integrator1" ) , TARGET_STRING (
"InitialCondition" ) , 0 , 0 , 0 } , { 170 , TARGET_STRING (
"modPSK/Receptor/Detector/Sample and Hold/ " ) , TARGET_STRING (
"InitialOutput" ) , 0 , 0 , 0 } , { 171 , TARGET_STRING (
"modPSK/Receptor/Sincronismo de símbolo/Monostable1/Sample & Hold" ) ,
TARGET_STRING ( "ic" ) , 0 , 0 , 0 } , { 172 , TARGET_STRING (
"modPSK/Receptor/Sincronismo de símbolo/Monostable1/Memory" ) ,
TARGET_STRING ( "InitialCondition" ) , 1 , 0 , 0 } , { 173 , TARGET_STRING (
"modPSK/Receptor/Sincronismo de símbolo/Monostable3/Sample & Hold" ) ,
TARGET_STRING ( "ic" ) , 0 , 0 , 0 } , { 174 , TARGET_STRING (
"modPSK/Receptor/Sincronismo de símbolo/Monostable3/Memory" ) ,
TARGET_STRING ( "InitialCondition" ) , 1 , 0 , 0 } , { 175 , TARGET_STRING (
"modPSK/Receptor/Sincronismo de símbolo/Sample and Hold/ " ) , TARGET_STRING
( "InitialOutput" ) , 0 , 0 , 0 } , { 176 , TARGET_STRING (
"modPSK/Receptor/Sincronismo de símbolo/Sample and Hold2/ " ) ,
TARGET_STRING ( "InitialOutput" ) , 0 , 0 , 0 } , { 177 , TARGET_STRING (
"modPSK/Receptor/Sincronismo de Trama/Monostable/Model/Sample and Hold" ) ,
TARGET_STRING ( "ic" ) , 0 , 0 , 0 } , { 178 , TARGET_STRING (
"modPSK/Receptor/Sincronismo de Trama/Monostable/Model/Memory" ) ,
TARGET_STRING ( "InitialCondition" ) , 1 , 0 , 0 } , { 179 , TARGET_STRING (
 "modPSK/Receptor/Sincronismo de portadora/ VCO/Modulo  Integrator/Modulo Integrator"
) , TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 180 ,
TARGET_STRING (
 "modPSK/Receptor/Sincronismo de portadora/ VCO/Modulo  Integrator/Modulo Integrator"
) , TARGET_STRING ( "WrappedStateUpperValue" ) , 0 , 0 , 0 } , { 181 ,
TARGET_STRING (
 "modPSK/Receptor/Sincronismo de portadora/ VCO/Modulo  Integrator/Modulo Integrator"
) , TARGET_STRING ( "WrappedStateLowerValue" ) , 0 , 0 , 0 } , { 182 ,
TARGET_STRING (
"modPSK/Receptor/Sincronismo de portadora/D Flip-Flop/D Flip-Flop/Q" ) ,
TARGET_STRING ( "InitialOutput" ) , 1 , 0 , 0 } , { 183 , TARGET_STRING (
"modPSK/Receptor/Sincronismo de portadora/D Flip-Flop/D Flip-Flop/!Q" ) ,
TARGET_STRING ( "InitialOutput" ) , 1 , 0 , 0 } , { 184 , TARGET_STRING (
 "modPSK/Receptor/Sincronismo de símbolo/Continuous-Time VCO/Modulo  Integrator/Modulo Integrator"
) , TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 185 ,
TARGET_STRING (
 "modPSK/Receptor/Sincronismo de símbolo/Continuous-Time VCO/Modulo  Integrator/Modulo Integrator"
) , TARGET_STRING ( "WrappedStateUpperValue" ) , 0 , 0 , 0 } , { 186 ,
TARGET_STRING (
 "modPSK/Receptor/Sincronismo de símbolo/Continuous-Time VCO/Modulo  Integrator/Modulo Integrator"
) , TARGET_STRING ( "WrappedStateLowerValue" ) , 0 , 0 , 0 } , { 187 ,
TARGET_STRING (
"modPSK/Receptor/Sincronismo de símbolo/Monostable1/Edge Detector/either edge"
) , TARGET_STRING ( "Value" ) , 0 , 7 , 0 } , { 188 , TARGET_STRING (
"modPSK/Receptor/Sincronismo de símbolo/Monostable1/Edge Detector/neg. edge"
) , TARGET_STRING ( "Value" ) , 0 , 7 , 0 } , { 189 , TARGET_STRING (
"modPSK/Receptor/Sincronismo de símbolo/Monostable1/Edge Detector/pos. edge"
) , TARGET_STRING ( "Value" ) , 0 , 7 , 0 } , { 190 , TARGET_STRING (
"modPSK/Receptor/Sincronismo de símbolo/Monostable3/Edge Detector/either edge"
) , TARGET_STRING ( "Value" ) , 0 , 7 , 0 } , { 191 , TARGET_STRING (
"modPSK/Receptor/Sincronismo de símbolo/Monostable3/Edge Detector/neg. edge"
) , TARGET_STRING ( "Value" ) , 0 , 7 , 0 } , { 192 , TARGET_STRING (
"modPSK/Receptor/Sincronismo de símbolo/Monostable3/Edge Detector/pos. edge"
) , TARGET_STRING ( "Value" ) , 0 , 7 , 0 } , { 193 , TARGET_STRING (
 "modPSK/Receptor/Sincronismo de Trama/Monostable/Model/Continuous Edge Detector/Constant1"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 194 , TARGET_STRING (
 "modPSK/Receptor/Sincronismo de Trama/Monostable/Model/Continuous Edge Detector/either edge"
) , TARGET_STRING ( "Value" ) , 0 , 7 , 0 } , { 195 , TARGET_STRING (
 "modPSK/Receptor/Sincronismo de Trama/Monostable/Model/Continuous Edge Detector/neg. edge"
) , TARGET_STRING ( "Value" ) , 0 , 7 , 0 } , { 196 , TARGET_STRING (
 "modPSK/Receptor/Sincronismo de Trama/Monostable/Model/Continuous Edge Detector/pos. edge"
) , TARGET_STRING ( "Value" ) , 0 , 7 , 0 } , { 197 , TARGET_STRING (
 "modPSK/Receptor/Sincronismo de símbolo/Monostable1/Edge Detector/NEGATIVE Edge/OUT"
) , TARGET_STRING ( "InitialOutput" ) , 1 , 0 , 0 } , { 198 , TARGET_STRING (
 "modPSK/Receptor/Sincronismo de símbolo/Monostable1/Edge Detector/POSITIVE Edge/OUT"
) , TARGET_STRING ( "InitialOutput" ) , 1 , 0 , 0 } , { 199 , TARGET_STRING (
 "modPSK/Receptor/Sincronismo de símbolo/Monostable3/Edge Detector/NEGATIVE Edge/OUT"
) , TARGET_STRING ( "InitialOutput" ) , 1 , 0 , 0 } , { 200 , TARGET_STRING (
 "modPSK/Receptor/Sincronismo de símbolo/Monostable3/Edge Detector/POSITIVE Edge/OUT"
) , TARGET_STRING ( "InitialOutput" ) , 1 , 0 , 0 } , { 201 , TARGET_STRING (
 "modPSK/Receptor/Sincronismo de Trama/Monostable/Model/Continuous Edge Detector/Internal dirac generator/Constant"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 202 , TARGET_STRING (
 "modPSK/Receptor/Sincronismo de Trama/Monostable/Model/Continuous Edge Detector/NEGATIVE Edge/OUT"
) , TARGET_STRING ( "InitialOutput" ) , 1 , 0 , 0 } , { 203 , TARGET_STRING (
 "modPSK/Receptor/Sincronismo de Trama/Monostable/Model/Continuous Edge Detector/POSITIVE Edge/OUT"
) , TARGET_STRING ( "InitialOutput" ) , 1 , 0 , 0 } , { 204 , TARGET_STRING (
 "modPSK/Receptor/Sincronismo de Trama/Monostable/Model/Continuous Edge Detector/Internal dirac generator/Triggered Subsystem/Out1"
) , TARGET_STRING ( "InitialOutput" ) , 0 , 0 , 0 } , { 0 , ( NULL ) , ( NULL
) , 0 , 0 , 0 } } ; static int_T rt_LoggedStateIdxList [ ] = { - 1 } ; static
const rtwCAPI_Signals rtRootInputs [ ] = { { 0 , 0 , ( NULL ) , ( NULL ) , 0
, 0 , 0 , 0 , 0 } } ; static const rtwCAPI_Signals rtRootOutputs [ ] = { { 0
, 0 , ( NULL ) , ( NULL ) , 0 , 0 , 0 , 0 , 0 } } ; static const
rtwCAPI_ModelParameters rtModelParameters [ ] = { { 205 , TARGET_STRING (
"Amplitud" ) , 0 , 0 , 0 } , { 206 , TARGET_STRING ( "Att_Volt_Canal" ) , 0 ,
0 , 0 } , { 207 , TARGET_STRING ( "C" ) , 0 , 0 , 0 } , { 208 , TARGET_STRING
( "Frec_port" ) , 0 , 0 , 0 } , { 209 , TARGET_STRING ( "Kv" ) , 0 , 0 , 0 }
, { 210 , TARGET_STRING ( "Pot_Ruido" ) , 0 , 0 , 0 } , { 211 , TARGET_STRING
( "R1" ) , 0 , 0 , 0 } , { 212 , TARGET_STRING ( "R2" ) , 0 , 0 , 0 } , { 213
, TARGET_STRING ( "Rb" ) , 0 , 0 , 0 } , { 214 , TARGET_STRING (
"Retraso_Canal" ) , 0 , 0 , 0 } , { 215 , TARGET_STRING ( "Tb" ) , 0 , 0 , 0
} , { 216 , TARGET_STRING ( "b" ) , 0 , 0 , 0 } , { 217 , TARGET_STRING (
"kv2" ) , 0 , 0 , 0 } , { 0 , ( NULL ) , 0 , 0 , 0 } } ;
#ifndef HOST_CAPI_BUILD
static void * rtDataAddrMap [ ] = { & rtB . p5kktr1wyk , & rtB . mvhgymrwqe ,
& rtB . ee42tgof2b , & rtB . df1ir0te5a , & rtB . nag5slvt33 , & rtB .
o5tdwwqd3u , & rtB . ijwiii2est , & rtB . c2cnah1c34 , & rtB . atcqfparc4 , &
rtB . d4ytgmijes , & rtB . nrqkqpzimhq . olytfz4wp1 , & rtB . fpr0eiute3 , &
rtB . kqemtml2w3 , & rtB . ooymnwvq5a , & rtB . kxicx45q5w , & rtB .
i0rkndmb13 , & rtB . jkw11eafiz , & rtB . nryqbxo330 , & rtB . da4cqxiizn , &
rtB . ijuklwld0a , & rtB . hcmaylj25a , & rtB . hihmi4odjo , & rtB .
gmgguax0lb , & rtB . cyqeay1yht , & rtB . ggvs3qvpfu , & rtB . e0stmf0wje , &
rtB . mdt0d44sb1 , & rtB . gqtvp2z5yf , & rtB . apaian0okb , & rtB .
bqly4iysyb , & rtB . nylejvpk25 , & rtB . cmjzvpvpsf . olytfz4wp1 , & rtB .
nnbbyhuwe5 , & rtB . n2wkjomta0 , & rtB . max2gpqnqf , & rtB . c1co2zjsgy , &
rtB . ktfxpbuyoi , & rtB . exkkdo4tfp , & rtB . pjddsfuka3 , & rtB .
nrqkqpzimhq . olytfz4wp1 , & rtB . acvegdxqsb , & rtB . c1quq2kkeo , & rtB .
bhwit4pfgp , & rtB . lb3j4jh0k1 , & rtB . krai04vzyy , & rtB . gpdt1s5m43 , &
rtB . ewn2wlainw , & rtB . owu2nywhc4 , & rtB . lgqv4rlpjm , & rtB .
blc3ahlqoa , & rtB . f14htfpour , & rtB . pehstkjnkd , & rtB . hehncpsx5o , &
rtB . e2pyl4rib3 , & rtB . nylejvpk25 , & rtB . cmjzvpvpsf . olytfz4wp1 , &
rtB . owsmsehx52 , & rtB . jyhhxwku5j , & rtB . djf3ji5ytw , & rtB .
bkyaf0nkhx , & rtB . pzi0oq2mxf , & rtB . jers21a5nu , & rtB . bhwit4pfgp , &
rtB . lb3j4jh0k1 , & rtB . ggca33mvdun . e5aa54psh5 , & rtB . msxjrffonnn .
k0x4is02ar , & rtB . nhjc2m3cbx [ 0 ] , & rtB . jxbxouhvpz , & rtB .
m0n2ncikto , & rtB . hdzoplw4kn . e5aa54psh5 , & rtB . jdw3pbikft .
k0x4is02ar , & rtB . ap3kp501sl [ 0 ] , & rtB . k3ehqfnhji , & rtB .
dxkeuerubi , & rtB . p0reyhkgec , & rtB . po2rfexerf , & rtB . fxorr2mhne [ 0
] , & rtB . ggca33mvdun . e5aa54psh5 , & rtB . msxjrffonnn . k0x4is02ar , &
rtB . hdzoplw4kn . e5aa54psh5 , & rtB . jdw3pbikft . k0x4is02ar , & rtB .
g5n3z2eyy3 , & rtB . fpmqgmj2cy , & rtB . gnebrkauvk , & rtB . p0reyhkgec , &
rtB . po2rfexerf , & rtB . nsdd2hdqf1 , & rtB . a34p2x24w2 , & rtB .
g5n3z2eyy3 , & rtP . RuidoAGWN_Mean , & rtP . RuidoAGWN_Seed , & rtP .
TransportDelay_InitOutput , & rtP . FromWorkspace_Data0 [ 0 ] , & rtP .
AddConstant_Bias_ljcfbacsm3 , & rtP . Multiply_Gain_ptvyavefxe , & rtP .
SineWave_Bias , & rtP . SineWave_Phase , & rtP . AnalogFilterDesign_A_pr [ 0
] , & rtP . AnalogFilterDesign_A_ir [ 0 ] , & rtP . AnalogFilterDesign_A_jc [
0 ] , & rtP . AnalogFilterDesign_B_pr , & rtP . AnalogFilterDesign_B_ir , &
rtP . AnalogFilterDesign_B_jc [ 0 ] , & rtP . AnalogFilterDesign_C_pr , & rtP
. AnalogFilterDesign_C_ir , & rtP . AnalogFilterDesign_C_jc [ 0 ] , & rtP .
AnalogFilterDesign_InitialCondition , & rtP . Integrator_IC , & rtP .
AnalogFilterDesign_A_pr_f4zixacbw1 [ 0 ] , & rtP .
AnalogFilterDesign_A_ir_cx1zj2mhzp [ 0 ] , & rtP .
AnalogFilterDesign_A_jc_h5xar20tzm [ 0 ] , & rtP .
AnalogFilterDesign_B_pr_by1sufu2fg , & rtP .
AnalogFilterDesign_B_ir_nneewrak4c , & rtP .
AnalogFilterDesign_B_jc_acwf2d2gj0 [ 0 ] , & rtP .
AnalogFilterDesign_C_pr_e3t31otpuq , & rtP .
AnalogFilterDesign_C_ir_cqrtf32rbd , & rtP .
AnalogFilterDesign_C_jc_d2bgogmalx [ 0 ] , & rtP .
AnalogFilterDesign_InitialCondition_gxj5snzs0v , & rtP . TransportDelay_Delay
, & rtP . TransportDelay_InitOutput_m3b1lj5lye , & rtP . AddConstant_Bias , &
rtP . Multiply_Gain , & rtP . Monostable_ic , & rtP . Constant1_Value , & rtP
. Constant10_Value , & rtP . Constant13_Value , & rtP . Constant14_Value , &
rtP . Constant15_Value , & rtP . Constant16_Value , & rtP . Constant2_Value ,
& rtP . Constant3_Value , & rtP . Constant4_Value , & rtP . Constant5_Value ,
& rtP . Constant6_Value , & rtP . Constant7_Value , & rtP . Constant8_Value ,
& rtP . Constant9_Value , & rtP . Switch_Threshold , & rtP .
TransportDelay1_InitOutput , & rtP . TransportDelay11_InitOutput , & rtP .
TransportDelay12_InitOutput , & rtP . TransportDelay2_InitOutput , & rtP .
TransportDelay3_InitOutput , & rtP . TransportDelay4_InitOutput , & rtP .
TransportDelay5_InitOutput , & rtP . TransportDelay6_InitOutput , & rtP .
TransportDelay7_InitOutput , & rtP . TransportDelay8_InitOutput , & rtP .
TransportDelay9_InitOutput , & rtP . Constant2_Value_mwviqzbxqh , & rtP .
Constant5_Value_hu2bresth1 , & rtP . Constant6_Value_dkmziwbikw , & rtP .
Integrator_IC_oxpanuusbm , & rtP . AnalogFilterDesign_A_pr_jsdcqwampi [ 0 ] ,
& rtP . AnalogFilterDesign_A_ir_gqpywhsxtr [ 0 ] , & rtP .
AnalogFilterDesign_A_jc_fyftqxybap [ 0 ] , & rtP .
AnalogFilterDesign_B_pr_om0jg41jmb , & rtP .
AnalogFilterDesign_B_ir_gklrfvy2xp , & rtP .
AnalogFilterDesign_B_jc_nk0ranamkl [ 0 ] , & rtP .
AnalogFilterDesign_C_pr_d0qgd0zcfa , & rtP .
AnalogFilterDesign_C_ir_jr05e5amzn , & rtP .
AnalogFilterDesign_C_jc_jc5wcv0wk2 [ 0 ] , & rtP .
AnalogFilterDesign_InitialCondition_bizf0yluzm , & rtP .
Monostable1_EdgeDetect , & rtP . Monostable1_ic , & rtP .
Monostable3_EdgeDetect , & rtP . Monostable3_ic , & rtP .
Constant1_Value_hcjo4f4r5j , & rtP . Integrator_IC_a5b0eygpkp , & rtP .
Integrator1_IC , & rtP . nrqkqpzimhq . _Y0 , & rtP . SampleHold_ic , & rtP .
Memory_InitialCondition_oggd2r4odw , & rtP . SampleHold_ic_cvpetr2ktj , & rtP
. Memory_InitialCondition_ljulw4woig , & rtP . _Y0 , & rtP . cmjzvpvpsf . _Y0
, & rtP . SampleandHold_ic , & rtP . Memory_InitialCondition , & rtP .
ModuloIntegrator_IC_g1vo2kap3u , & rtP .
ModuloIntegrator_WrappedStateUpperValue_pzfggn2fu5 , & rtP .
ModuloIntegrator_WrappedStateLowerValue_ph0x13ofwk , & rtP . Q_Y0 , & rtP .
Q_Y0_ngs1cr5pq5 , & rtP . ModuloIntegrator_IC , & rtP .
ModuloIntegrator_WrappedStateUpperValue , & rtP .
ModuloIntegrator_WrappedStateLowerValue , & rtP . eitheredge_Value_nntils3rkv
[ 0 ] , & rtP . negedge_Value_fef1hh2jz4 [ 0 ] , & rtP .
posedge_Value_av2r5ustik [ 0 ] , & rtP . eitheredge_Value_gsipsgs54b [ 0 ] ,
& rtP . negedge_Value_lnmee3h1ob [ 0 ] , & rtP . posedge_Value_j0croo5cnv [ 0
] , & rtP . Constant1_Value_afssjxve00 , & rtP . eitheredge_Value [ 0 ] , &
rtP . negedge_Value [ 0 ] , & rtP . posedge_Value [ 0 ] , & rtP . ggca33mvdun
. OUT_Y0 , & rtP . msxjrffonnn . OUT_Y0 , & rtP . hdzoplw4kn . OUT_Y0 , & rtP
. jdw3pbikft . OUT_Y0 , & rtP . Constant_Value , & rtP . OUT_Y0 , & rtP .
OUT_Y0_gbikirmbla , & rtP . Out1_Y0 , & rtP . Amplitud , & rtP .
Att_Volt_Canal , & rtP . C , & rtP . Frec_port , & rtP . Kv , & rtP .
Pot_Ruido , & rtP . R1 , & rtP . R2 , & rtP . Rb , & rtP . Retraso_Canal , &
rtP . Tb , & rtP . b , & rtP . kv2 , } ; static int32_T * rtVarDimsAddrMap [
] = { ( NULL ) } ;
#endif
static TARGET_CONST rtwCAPI_DataTypeMap rtDataTypeMap [ ] = { { "double" ,
"real_T" , 0 , 0 , sizeof ( real_T ) , ( uint8_T ) SS_DOUBLE , 0 , 0 , 0 } ,
{ "unsigned char" , "boolean_T" , 0 , 0 , sizeof ( boolean_T ) , ( uint8_T )
SS_BOOLEAN , 0 , 0 , 0 } , { "unsigned int" , "uint32_T" , 0 , 0 , sizeof (
uint32_T ) , ( uint8_T ) SS_UINT32 , 0 , 0 , 0 } } ;
#ifdef HOST_CAPI_BUILD
#undef sizeof
#endif
static TARGET_CONST rtwCAPI_ElementMap rtElementMap [ ] = { { ( NULL ) , 0 ,
0 , 0 , 0 } , } ; static const rtwCAPI_DimensionMap rtDimensionMap [ ] = { {
rtwCAPI_SCALAR , 0 , 2 , 0 } , { rtwCAPI_VECTOR , 2 , 2 , 0 } , {
rtwCAPI_VECTOR , 4 , 2 , 0 } , { rtwCAPI_VECTOR , 6 , 2 , 0 } , {
rtwCAPI_VECTOR , 8 , 2 , 0 } , { rtwCAPI_VECTOR , 10 , 2 , 0 } , {
rtwCAPI_VECTOR , 12 , 2 , 0 } , { rtwCAPI_VECTOR , 14 , 2 , 0 } } ; static
const uint_T rtDimensionArray [ ] = { 1 , 1 , 2 , 1 , 1111 , 1 , 7 , 1 , 5 ,
1 , 15 , 1 , 9 , 1 , 1 , 2 } ; static const real_T rtcapiStoredFloats [ ] = {
1.0 , 0.0 , 0.0001 } ; static const rtwCAPI_FixPtMap rtFixPtMap [ ] = { { (
NULL ) , ( NULL ) , rtwCAPI_FIX_RESERVED , 0 , 0 , ( boolean_T ) 0 } , } ;
static const rtwCAPI_SampleTimeMap rtSampleTimeMap [ ] = { { static_cast <
const void * > ( & rtcapiStoredFloats [ 0 ] ) , static_cast < const void * >
( & rtcapiStoredFloats [ 1 ] ) , static_cast < int8_T > ( 3 ) , static_cast <
uint8_T > ( 0 ) } , { static_cast < const void * > ( & rtcapiStoredFloats [ 1
] ) , static_cast < const void * > ( & rtcapiStoredFloats [ 1 ] ) ,
static_cast < int8_T > ( 0 ) , static_cast < uint8_T > ( 0 ) } , {
static_cast < const void * > ( & rtcapiStoredFloats [ 2 ] ) , static_cast <
const void * > ( & rtcapiStoredFloats [ 1 ] ) , static_cast < int8_T > ( 2 )
, static_cast < uint8_T > ( 0 ) } , { ( NULL ) , ( NULL ) , - 1 , 0 } , {
static_cast < const void * > ( & rtcapiStoredFloats [ 1 ] ) , static_cast <
const void * > ( & rtcapiStoredFloats [ 0 ] ) , static_cast < int8_T > ( 1 )
, static_cast < uint8_T > ( 0 ) } , { ( NULL ) , ( NULL ) , 4 , 0 } } ;
static rtwCAPI_ModelMappingStaticInfo mmiStatic = { { rtBlockSignals , 89 ,
rtRootInputs , 0 , rtRootOutputs , 0 } , { rtBlockParameters , 116 ,
rtModelParameters , 13 } , { ( NULL ) , 0 } , { rtDataTypeMap ,
rtDimensionMap , rtFixPtMap , rtElementMap , rtSampleTimeMap ,
rtDimensionArray } , "float" , { 3134493899U , 3043254526U , 4272357070U ,
1867159465U } , ( NULL ) , 0 , ( boolean_T ) 0 , rt_LoggedStateIdxList } ;
const rtwCAPI_ModelMappingStaticInfo * modPSK_GetCAPIStaticMap ( void ) {
return & mmiStatic ; }
#ifndef HOST_CAPI_BUILD
void modPSK_InitializeDataMapInfo ( void ) { rtwCAPI_SetVersion ( ( *
rt_dataMapInfoPtr ) . mmi , 1 ) ; rtwCAPI_SetStaticMap ( ( *
rt_dataMapInfoPtr ) . mmi , & mmiStatic ) ; rtwCAPI_SetLoggingStaticMap ( ( *
rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ; rtwCAPI_SetDataAddressMap ( ( *
rt_dataMapInfoPtr ) . mmi , rtDataAddrMap ) ; rtwCAPI_SetVarDimsAddressMap (
( * rt_dataMapInfoPtr ) . mmi , rtVarDimsAddrMap ) ;
rtwCAPI_SetInstanceLoggingInfo ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArray ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( ( * rt_dataMapInfoPtr ) . mmi , 0 ) ; }
#else
#ifdef __cplusplus
extern "C" {
#endif
void modPSK_host_InitializeDataMapInfo ( modPSK_host_DataMapInfo_T * dataMap
, const char * path ) { rtwCAPI_SetVersion ( dataMap -> mmi , 1 ) ;
rtwCAPI_SetStaticMap ( dataMap -> mmi , & mmiStatic ) ;
rtwCAPI_SetDataAddressMap ( dataMap -> mmi , ( NULL ) ) ;
rtwCAPI_SetVarDimsAddressMap ( dataMap -> mmi , ( NULL ) ) ; rtwCAPI_SetPath
( dataMap -> mmi , path ) ; rtwCAPI_SetFullPath ( dataMap -> mmi , ( NULL ) )
; rtwCAPI_SetChildMMIArray ( dataMap -> mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( dataMap -> mmi , 0 ) ; }
#ifdef __cplusplus
}
#endif
#endif
