#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "modPSK_mod3_capi_host.h"
#define sizeof(s) ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el) ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s) (s)
#ifndef SS_UINT64
#define SS_UINT64 17
#endif
#ifndef SS_INT64
#define SS_INT64 18
#endif
#else
#include "builtin_typeid_types.h"
#include "modPSK_mod3.h"
#include "modPSK_mod3_capi.h"
#include "modPSK_mod3_private.h"
#ifdef LIGHT_WEIGHT_CAPI
#define TARGET_CONST
#define TARGET_STRING(s)               ((NULL))
#else
#define TARGET_CONST                   const
#define TARGET_STRING(s)               (s)
#endif
#endif
static const rtwCAPI_Signals rtBlockSignals [ ] = { { 0 , 0 , TARGET_STRING (
"modPSK_mod3/Canal/Product" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } ,
{ 1 , 0 , TARGET_STRING ( "modPSK_mod3/Canal/Ruido AGWN" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 1 } , { 2 , 0 , TARGET_STRING (
"modPSK_mod3/Canal/Add" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 3
, 0 , TARGET_STRING ( "modPSK_mod3/CodificacionCanal/Product" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 2 } , { 4 , 0 , TARGET_STRING (
"modPSK_mod3/CodificacionCanal/Unbuffer" ) , TARGET_STRING ( "" ) , 0 , 0 , 0
, 0 , 3 } , { 5 , 0 , TARGET_STRING (
"modPSK_mod3/Receptor/Analog Filter Design" ) , TARGET_STRING ( "" ) , 0 , 0
, 0 , 0 , 0 } , { 6 , 0 , TARGET_STRING (
"modPSK_mod3/Transmisor/Add Constant" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 ,
0 , 3 } , { 7 , 0 , TARGET_STRING ( "modPSK_mod3/Transmisor/Product" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 8 , 0 , TARGET_STRING (
"modPSK_mod3/Transmisor/Analog Filter Design" ) , TARGET_STRING ( "" ) , 0 ,
0 , 0 , 0 , 0 } , { 9 , 0 , TARGET_STRING (
"modPSK_mod3/Receptor/Correlación/Integrator" ) , TARGET_STRING ( "" ) , 0 ,
0 , 0 , 0 , 0 } , { 10 , 0 , TARGET_STRING (
"modPSK_mod3/Receptor/Correlación/Product" ) , TARGET_STRING ( "" ) , 0 , 0 ,
0 , 0 , 0 } , { 11 , 0 , TARGET_STRING (
"modPSK_mod3/Receptor/Correlación/Analog Filter Design" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 0 } , { 12 , 0 , TARGET_STRING (
"modPSK_mod3/Receptor/Correlación/Transport Delay" ) , TARGET_STRING ( "" ) ,
0 , 0 , 0 , 0 , 0 } , { 13 , 1 , TARGET_STRING (
"modPSK_mod3/Receptor/Decodificacion del Canal/MATLAB Function" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 14 , 1 , TARGET_STRING (
"modPSK_mod3/Receptor/Decodificacion del Canal/MATLAB Function" ) ,
TARGET_STRING ( "" ) , 1 , 0 , 0 , 0 , 1 } , { 15 , 0 , TARGET_STRING (
"modPSK_mod3/Receptor/Decodificacion del Canal/Delay Line" ) , TARGET_STRING
( "" ) , 0 , 0 , 2 , 0 , 1 } , { 16 , 2 , TARGET_STRING (
"modPSK_mod3/Receptor/Detector/Sample and Hold" ) , TARGET_STRING ( "" ) , 0
, 0 , 0 , 0 , 4 } , { 17 , 0 , TARGET_STRING (
"modPSK_mod3/Receptor/Detector/Sign" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0
, 5 } , { 18 , 0 , TARGET_STRING ( "modPSK_mod3/Receptor/Polar/Multiply" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 19 , 0 , TARGET_STRING (
"modPSK_mod3/Receptor/Sincronismo de Trama/Product4" ) , TARGET_STRING ( "" )
, 0 , 0 , 0 , 0 , 1 } , { 20 , 0 , TARGET_STRING (
"modPSK_mod3/Receptor/Sincronismo de Trama/Add" ) , TARGET_STRING ( "" ) , 0
, 0 , 0 , 0 , 0 } , { 21 , 0 , TARGET_STRING (
"modPSK_mod3/Receptor/Sincronismo de Trama/Switch" ) , TARGET_STRING ( "" ) ,
0 , 0 , 0 , 0 , 0 } , { 22 , 0 , TARGET_STRING (
"modPSK_mod3/Receptor/Sincronismo de Trama/Switch1" ) , TARGET_STRING ( "" )
, 0 , 0 , 0 , 0 , 0 } , { 23 , 0 , TARGET_STRING (
"modPSK_mod3/Receptor/Sincronismo de Trama/Transport Delay1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 24 , 0 , TARGET_STRING (
"modPSK_mod3/Receptor/Sincronismo de Trama/Transport Delay2" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 25 , 0 , TARGET_STRING (
"modPSK_mod3/Receptor/Sincronismo de Trama/Transport Delay3" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 26 , 0 , TARGET_STRING (
"modPSK_mod3/Receptor/Sincronismo de Trama/Transport Delay4" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 27 , 0 , TARGET_STRING (
"modPSK_mod3/Receptor/Sincronismo de Trama/Transport Delay5" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 28 , 0 , TARGET_STRING (
"modPSK_mod3/Receptor/Sincronismo de Trama/Transport Delay6" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 29 , 0 , TARGET_STRING (
"modPSK_mod3/Receptor/Sincronismo de Trama/Transport Delay7" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 30 , 0 , TARGET_STRING (
"modPSK_mod3/Receptor/Sincronismo de Trama/Transport Delay8" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 31 , 0 , TARGET_STRING (
"modPSK_mod3/Receptor/Sincronismo de Trama/Transport Delay9" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 32 , 0 , TARGET_STRING (
"modPSK_mod3/Receptor/Sincronismo de portadora/Product3" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 0 } , { 33 , 0 , TARGET_STRING (
"modPSK_mod3/Receptor/Sincronismo de portadora/Product4" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 0 } , { 34 , 0 , TARGET_STRING (
"modPSK_mod3/Receptor/Sincronismo de portadora/Sign" ) , TARGET_STRING ( "" )
, 0 , 0 , 0 , 0 , 0 } , { 35 , 0 , TARGET_STRING (
"modPSK_mod3/Receptor/Sincronismo de portadora/Add1" ) , TARGET_STRING ( "" )
, 0 , 0 , 0 , 0 , 5 } , { 36 , 11 , TARGET_STRING (
"modPSK_mod3/Receptor/Sincronismo de símbolo/Sample and Hold" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 4 } , { 37 , 12 , TARGET_STRING (
"modPSK_mod3/Receptor/Sincronismo de símbolo/Sample and Hold2" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 4 } , { 38 , 0 , TARGET_STRING (
"modPSK_mod3/Receptor/Sincronismo de símbolo/Abs" ) , TARGET_STRING ( "" ) ,
0 , 0 , 0 , 0 , 5 } , { 39 , 0 , TARGET_STRING (
"modPSK_mod3/Receptor/Sincronismo de símbolo/Integrator" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 0 } , { 40 , 0 , TARGET_STRING (
"modPSK_mod3/Receptor/Sincronismo de símbolo/Integrator1" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 0 } , { 41 , 0 , TARGET_STRING (
"modPSK_mod3/Receptor/Sincronismo de símbolo/Sign" ) , TARGET_STRING ( "" ) ,
0 , 0 , 0 , 0 , 0 } , { 42 , 0 , TARGET_STRING (
"modPSK_mod3/Receptor/Sincronismo de símbolo/Sign1" ) , TARGET_STRING ( "" )
, 0 , 0 , 0 , 0 , 0 } , { 43 , 0 , TARGET_STRING (
"modPSK_mod3/Receptor/Sincronismo de símbolo/Sum" ) , TARGET_STRING ( "" ) ,
0 , 0 , 0 , 0 , 0 } , { 44 , 14 , TARGET_STRING (
"modPSK_mod3/Receptor/Single Modulus Prescaler/integer clock divider" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 4 } , { 45 , 0 , TARGET_STRING (
"modPSK_mod3/Receptor/Single Modulus Prescaler/Switch" ) , TARGET_STRING ( ""
) , 0 , 0 , 0 , 0 , 5 } , { 46 , 0 , TARGET_STRING (
"modPSK_mod3/Receptor/Single Modulus Prescaler/Logic Decision1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 6 } , { 47 , 2 , TARGET_STRING (
"modPSK_mod3/Receptor/Detector/Sample and Hold/In" ) , TARGET_STRING ( "" ) ,
0 , 0 , 0 , 0 , 4 } , { 48 , 0 , TARGET_STRING (
"modPSK_mod3/Receptor/Sincronismo de portadora/ VCO/Sum" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 0 } , { 49 , 6 , TARGET_STRING (
"modPSK_mod3/Receptor/Sincronismo de portadora/D Flip-Flop/D Flip-Flop" ) ,
TARGET_STRING ( "" ) , 0 , 1 , 0 , 0 , 4 } , { 50 , 6 , TARGET_STRING (
"modPSK_mod3/Receptor/Sincronismo de portadora/D Flip-Flop/D Flip-Flop" ) ,
TARGET_STRING ( "" ) , 1 , 1 , 0 , 0 , 4 } , { 51 , 0 , TARGET_STRING (
"modPSK_mod3/Receptor/Sincronismo de símbolo/Continuous-Time VCO/Sum" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 5 } , { 52 , 0 , TARGET_STRING (
"modPSK_mod3/Receptor/Sincronismo de símbolo/Monostable1/Logical Operator2" )
, TARGET_STRING ( "" ) , 0 , 1 , 0 , 0 , 5 } , { 53 , 0 , TARGET_STRING (
"modPSK_mod3/Receptor/Sincronismo de símbolo/Monostable1/Relational Operator"
) , TARGET_STRING ( "" ) , 0 , 1 , 0 , 0 , 0 } , { 54 , 0 , TARGET_STRING (
"modPSK_mod3/Receptor/Sincronismo de símbolo/Monostable3/Logical Operator2" )
, TARGET_STRING ( "" ) , 0 , 1 , 0 , 0 , 5 } , { 55 , 0 , TARGET_STRING (
"modPSK_mod3/Receptor/Sincronismo de símbolo/Monostable3/Relational Operator"
) , TARGET_STRING ( "" ) , 0 , 1 , 0 , 0 , 0 } , { 56 , 11 , TARGET_STRING (
"modPSK_mod3/Receptor/Sincronismo de símbolo/Sample and Hold/In" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 4 } , { 57 , 12 , TARGET_STRING (
"modPSK_mod3/Receptor/Sincronismo de símbolo/Sample and Hold2/In" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 4 } , { 58 , 14 , TARGET_STRING (
"modPSK_mod3/Receptor/Single Modulus Prescaler/integer clock divider/Fcn4" )
, TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 4 } , { 59 , 0 , TARGET_STRING (
"modPSK_mod3/Receptor/Sincronismo de Trama/Monostable/Model/T_monostable" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 5 } , { 60 , 0 , TARGET_STRING (
 "modPSK_mod3/Receptor/Sincronismo de Trama/Monostable/Model/Data Type Conversion2"
) , TARGET_STRING ( "" ) , 0 , 1 , 0 , 0 , 0 } , { 61 , 0 , TARGET_STRING (
"modPSK_mod3/Receptor/Sincronismo de Trama/Monostable/Model/Logical Operator2"
) , TARGET_STRING ( "" ) , 0 , 1 , 0 , 0 , 5 } , { 62 , 0 , TARGET_STRING (
"modPSK_mod3/Receptor/Sincronismo de Trama/Monostable/Model/Relational Operator"
) , TARGET_STRING ( "" ) , 0 , 1 , 0 , 0 , 0 } , { 63 , 6 , TARGET_STRING (
"modPSK_mod3/Receptor/Sincronismo de portadora/D Flip-Flop/D Flip-Flop/D" ) ,
TARGET_STRING ( "" ) , 0 , 1 , 0 , 0 , 4 } , { 64 , 6 , TARGET_STRING (
"modPSK_mod3/Receptor/Sincronismo de portadora/D Flip-Flop/D Flip-Flop/Logic"
) , TARGET_STRING ( "" ) , 0 , 1 , 0 , 0 , 4 } , { 65 , 7 , TARGET_STRING (
 "modPSK_mod3/Receptor/Sincronismo de símbolo/Monostable1/Edge Detector/NEGATIVE Edge"
) , TARGET_STRING ( "" ) , 0 , 1 , 0 , 0 , 0 } , { 66 , 8 , TARGET_STRING (
 "modPSK_mod3/Receptor/Sincronismo de símbolo/Monostable1/Edge Detector/POSITIVE Edge"
) , TARGET_STRING ( "" ) , 0 , 1 , 0 , 0 , 0 } , { 67 , 0 , TARGET_STRING (
"modPSK_mod3/Receptor/Sincronismo de símbolo/Monostable1/Edge Detector/Memory"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 5 } , { 68 , 0 , TARGET_STRING (
 "modPSK_mod3/Receptor/Sincronismo de símbolo/Monostable1/Edge Detector/Multiport Switch"
) , TARGET_STRING ( "" ) , 0 , 0 , 3 , 0 , 7 } , { 69 , 0 , TARGET_STRING (
"modPSK_mod3/Receptor/Sincronismo de símbolo/Monostable1/Sample & Hold/IC=ic"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 5 } , { 70 , 0 , TARGET_STRING (
"modPSK_mod3/Receptor/Sincronismo de símbolo/Monostable1/Sample & Hold/Switch"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 71 , 9 , TARGET_STRING (
 "modPSK_mod3/Receptor/Sincronismo de símbolo/Monostable3/Edge Detector/NEGATIVE Edge"
) , TARGET_STRING ( "" ) , 0 , 1 , 0 , 0 , 0 } , { 72 , 10 , TARGET_STRING (
 "modPSK_mod3/Receptor/Sincronismo de símbolo/Monostable3/Edge Detector/POSITIVE Edge"
) , TARGET_STRING ( "" ) , 0 , 1 , 0 , 0 , 0 } , { 73 , 0 , TARGET_STRING (
"modPSK_mod3/Receptor/Sincronismo de símbolo/Monostable3/Edge Detector/Memory"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 5 } , { 74 , 0 , TARGET_STRING (
 "modPSK_mod3/Receptor/Sincronismo de símbolo/Monostable3/Edge Detector/Multiport Switch"
) , TARGET_STRING ( "" ) , 0 , 0 , 3 , 0 , 7 } , { 75 , 0 , TARGET_STRING (
"modPSK_mod3/Receptor/Sincronismo de símbolo/Monostable3/Sample & Hold/IC=ic"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 5 } , { 76 , 0 , TARGET_STRING (
"modPSK_mod3/Receptor/Sincronismo de símbolo/Monostable3/Sample & Hold/Switch"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 77 , 0 , TARGET_STRING (
 "modPSK_mod3/Receptor/Single Modulus Prescaler/Error checking /Check Static  Lower Bound/min_relop"
) , TARGET_STRING ( "" ) , 0 , 1 , 0 , 0 , 7 } , { 78 , 0 , TARGET_STRING (
 "modPSK_mod3/Receptor/Single Modulus Prescaler/Error checking /Check Static  Upper Bound/max_relop"
) , TARGET_STRING ( "" ) , 0 , 1 , 0 , 0 , 7 } , { 79 , 4 , TARGET_STRING (
 "modPSK_mod3/Receptor/Sincronismo de Trama/Monostable/Model/Continuous Edge Detector/NEGATIVE Edge"
) , TARGET_STRING ( "" ) , 0 , 1 , 0 , 0 , 0 } , { 80 , 5 , TARGET_STRING (
 "modPSK_mod3/Receptor/Sincronismo de Trama/Monostable/Model/Continuous Edge Detector/POSITIVE Edge"
) , TARGET_STRING ( "" ) , 0 , 1 , 0 , 0 , 0 } , { 81 , 0 , TARGET_STRING (
 "modPSK_mod3/Receptor/Sincronismo de Trama/Monostable/Model/Continuous Edge Detector/Logical Operator1"
) , TARGET_STRING ( "" ) , 0 , 1 , 0 , 0 , 0 } , { 82 , 0 , TARGET_STRING (
 "modPSK_mod3/Receptor/Sincronismo de Trama/Monostable/Model/Continuous Edge Detector/Memory"
) , TARGET_STRING ( "" ) , 0 , 1 , 0 , 0 , 5 } , { 83 , 0 , TARGET_STRING (
 "modPSK_mod3/Receptor/Sincronismo de Trama/Monostable/Model/Continuous Edge Detector/Multiport Switch"
) , TARGET_STRING ( "" ) , 0 , 0 , 3 , 0 , 7 } , { 84 , 7 , TARGET_STRING (
 "modPSK_mod3/Receptor/Sincronismo de símbolo/Monostable1/Edge Detector/NEGATIVE Edge/Relational Operator1"
) , TARGET_STRING ( "" ) , 0 , 1 , 0 , 0 , 0 } , { 85 , 8 , TARGET_STRING (
 "modPSK_mod3/Receptor/Sincronismo de símbolo/Monostable1/Edge Detector/POSITIVE Edge/Relational Operator1"
) , TARGET_STRING ( "" ) , 0 , 1 , 0 , 0 , 0 } , { 86 , 9 , TARGET_STRING (
 "modPSK_mod3/Receptor/Sincronismo de símbolo/Monostable3/Edge Detector/NEGATIVE Edge/Relational Operator1"
) , TARGET_STRING ( "" ) , 0 , 1 , 0 , 0 , 0 } , { 87 , 10 , TARGET_STRING (
 "modPSK_mod3/Receptor/Sincronismo de símbolo/Monostable3/Edge Detector/POSITIVE Edge/Relational Operator1"
) , TARGET_STRING ( "" ) , 0 , 1 , 0 , 0 , 0 } , { 88 , 0 , TARGET_STRING (
 "modPSK_mod3/Receptor/Sincronismo de Trama/Monostable/Model/Continuous Edge Detector/Internal dirac generator/Clock"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 89 , 4 , TARGET_STRING (
 "modPSK_mod3/Receptor/Sincronismo de Trama/Monostable/Model/Continuous Edge Detector/NEGATIVE Edge/Relational Operator1"
) , TARGET_STRING ( "" ) , 0 , 1 , 0 , 0 , 0 } , { 90 , 5 , TARGET_STRING (
 "modPSK_mod3/Receptor/Sincronismo de Trama/Monostable/Model/Continuous Edge Detector/POSITIVE Edge/Relational Operator1"
) , TARGET_STRING ( "" ) , 0 , 1 , 0 , 0 , 0 } , { 91 , 0 , TARGET_STRING (
 "modPSK_mod3/Receptor/Sincronismo de Trama/Monostable/Model/Sample and Hold/Model/IC=ic"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 5 } , { 92 , 0 , TARGET_STRING (
 "modPSK_mod3/Receptor/Sincronismo de Trama/Monostable/Model/Sample and Hold/Model/Switch"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 0 , 0 , ( NULL ) , ( NULL
) , 0 , 0 , 0 , 0 , 0 } } ; static const rtwCAPI_BlockParameters
rtBlockParameters [ ] = { { 93 , TARGET_STRING (
"modPSK_mod3/Canal/Ruido AGWN" ) , TARGET_STRING ( "Mean" ) , 0 , 0 , 0 } , {
94 , TARGET_STRING ( "modPSK_mod3/Canal/Ruido AGWN" ) , TARGET_STRING (
"Seed" ) , 0 , 0 , 0 } , { 95 , TARGET_STRING (
"modPSK_mod3/Canal/Transport Delay" ) , TARGET_STRING ( "InitialOutput" ) , 0
, 0 , 0 } , { 96 , TARGET_STRING (
"modPSK_mod3/CodificacionCanal/matrizGeneradora" ) , TARGET_STRING ( "Value"
) , 0 , 4 , 0 } , { 97 , TARGET_STRING (
"modPSK_mod3/CodificacionCanal/Unbuffer" ) , TARGET_STRING ( "ic" ) , 0 , 0 ,
0 } , { 98 , TARGET_STRING ( "modPSK_mod3/Receptor/Constant" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 99 , TARGET_STRING (
"modPSK_mod3/Receptor/Analog Filter Design" ) , TARGET_STRING ( "A_pr" ) , 0
, 1 , 0 } , { 100 , TARGET_STRING (
"modPSK_mod3/Receptor/Analog Filter Design" ) , TARGET_STRING ( "A_ir" ) , 2
, 1 , 0 } , { 101 , TARGET_STRING (
"modPSK_mod3/Receptor/Analog Filter Design" ) , TARGET_STRING ( "A_jc" ) , 2
, 5 , 0 } , { 102 , TARGET_STRING (
"modPSK_mod3/Receptor/Analog Filter Design" ) , TARGET_STRING ( "B_pr" ) , 0
, 0 , 0 } , { 103 , TARGET_STRING (
"modPSK_mod3/Receptor/Analog Filter Design" ) , TARGET_STRING ( "B_ir" ) , 2
, 0 , 0 } , { 104 , TARGET_STRING (
"modPSK_mod3/Receptor/Analog Filter Design" ) , TARGET_STRING ( "B_jc" ) , 2
, 3 , 0 } , { 105 , TARGET_STRING (
"modPSK_mod3/Receptor/Analog Filter Design" ) , TARGET_STRING ( "C_pr" ) , 0
, 0 , 0 } , { 106 , TARGET_STRING (
"modPSK_mod3/Receptor/Analog Filter Design" ) , TARGET_STRING ( "C_ir" ) , 2
, 0 , 0 } , { 107 , TARGET_STRING (
"modPSK_mod3/Receptor/Analog Filter Design" ) , TARGET_STRING ( "C_jc" ) , 2
, 5 , 0 } , { 108 , TARGET_STRING (
"modPSK_mod3/Receptor/Analog Filter Design" ) , TARGET_STRING (
"InitialCondition" ) , 0 , 0 , 0 } , { 109 , TARGET_STRING (
"modPSK_mod3/Signal From Workspace/From Workspace" ) , TARGET_STRING (
"Data0" ) , 0 , 6 , 0 } , { 110 , TARGET_STRING (
"modPSK_mod3/Transmisor/Add Constant" ) , TARGET_STRING ( "Bias" ) , 0 , 0 ,
0 } , { 111 , TARGET_STRING ( "modPSK_mod3/Transmisor/Multiply" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 112 , TARGET_STRING (
"modPSK_mod3/Transmisor/Sine Wave" ) , TARGET_STRING ( "Bias" ) , 0 , 0 , 0 }
, { 113 , TARGET_STRING ( "modPSK_mod3/Transmisor/Sine Wave" ) ,
TARGET_STRING ( "Phase" ) , 0 , 0 , 0 } , { 114 , TARGET_STRING (
"modPSK_mod3/Transmisor/Analog Filter Design" ) , TARGET_STRING ( "A_pr" ) ,
0 , 1 , 0 } , { 115 , TARGET_STRING (
"modPSK_mod3/Transmisor/Analog Filter Design" ) , TARGET_STRING ( "A_ir" ) ,
2 , 1 , 0 } , { 116 , TARGET_STRING (
"modPSK_mod3/Transmisor/Analog Filter Design" ) , TARGET_STRING ( "A_jc" ) ,
2 , 5 , 0 } , { 117 , TARGET_STRING (
"modPSK_mod3/Transmisor/Analog Filter Design" ) , TARGET_STRING ( "B_pr" ) ,
0 , 0 , 0 } , { 118 , TARGET_STRING (
"modPSK_mod3/Transmisor/Analog Filter Design" ) , TARGET_STRING ( "B_ir" ) ,
2 , 0 , 0 } , { 119 , TARGET_STRING (
"modPSK_mod3/Transmisor/Analog Filter Design" ) , TARGET_STRING ( "B_jc" ) ,
2 , 3 , 0 } , { 120 , TARGET_STRING (
"modPSK_mod3/Transmisor/Analog Filter Design" ) , TARGET_STRING ( "C_pr" ) ,
0 , 0 , 0 } , { 121 , TARGET_STRING (
"modPSK_mod3/Transmisor/Analog Filter Design" ) , TARGET_STRING ( "C_ir" ) ,
2 , 0 , 0 } , { 122 , TARGET_STRING (
"modPSK_mod3/Transmisor/Analog Filter Design" ) , TARGET_STRING ( "C_jc" ) ,
2 , 5 , 0 } , { 123 , TARGET_STRING (
"modPSK_mod3/Transmisor/Analog Filter Design" ) , TARGET_STRING (
"InitialCondition" ) , 0 , 0 , 0 } , { 124 , TARGET_STRING (
"modPSK_mod3/Receptor/Correlación/Integrator" ) , TARGET_STRING (
"InitialCondition" ) , 0 , 0 , 0 } , { 125 , TARGET_STRING (
"modPSK_mod3/Receptor/Correlación/Analog Filter Design" ) , TARGET_STRING (
"A_pr" ) , 0 , 7 , 0 } , { 126 , TARGET_STRING (
"modPSK_mod3/Receptor/Correlación/Analog Filter Design" ) , TARGET_STRING (
"A_ir" ) , 2 , 7 , 0 } , { 127 , TARGET_STRING (
"modPSK_mod3/Receptor/Correlación/Analog Filter Design" ) , TARGET_STRING (
"A_jc" ) , 2 , 8 , 0 } , { 128 , TARGET_STRING (
"modPSK_mod3/Receptor/Correlación/Analog Filter Design" ) , TARGET_STRING (
"B_pr" ) , 0 , 0 , 0 } , { 129 , TARGET_STRING (
"modPSK_mod3/Receptor/Correlación/Analog Filter Design" ) , TARGET_STRING (
"B_ir" ) , 2 , 0 , 0 } , { 130 , TARGET_STRING (
"modPSK_mod3/Receptor/Correlación/Analog Filter Design" ) , TARGET_STRING (
"B_jc" ) , 2 , 3 , 0 } , { 131 , TARGET_STRING (
"modPSK_mod3/Receptor/Correlación/Analog Filter Design" ) , TARGET_STRING (
"C_pr" ) , 0 , 0 , 0 } , { 132 , TARGET_STRING (
"modPSK_mod3/Receptor/Correlación/Analog Filter Design" ) , TARGET_STRING (
"C_ir" ) , 2 , 0 , 0 } , { 133 , TARGET_STRING (
"modPSK_mod3/Receptor/Correlación/Analog Filter Design" ) , TARGET_STRING (
"C_jc" ) , 2 , 8 , 0 } , { 134 , TARGET_STRING (
"modPSK_mod3/Receptor/Correlación/Analog Filter Design" ) , TARGET_STRING (
"InitialCondition" ) , 0 , 0 , 0 } , { 135 , TARGET_STRING (
"modPSK_mod3/Receptor/Correlación/Transport Delay" ) , TARGET_STRING (
"DelayTime" ) , 0 , 0 , 0 } , { 136 , TARGET_STRING (
"modPSK_mod3/Receptor/Correlación/Transport Delay" ) , TARGET_STRING (
"InitialOutput" ) , 0 , 0 , 0 } , { 137 , TARGET_STRING (
"modPSK_mod3/Receptor/Polar/Add Constant" ) , TARGET_STRING ( "Bias" ) , 0 ,
0 , 0 } , { 138 , TARGET_STRING ( "modPSK_mod3/Receptor/Polar/Multiply" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 139 , TARGET_STRING (
"modPSK_mod3/Receptor/Sincronismo de Trama/Monostable" ) , TARGET_STRING (
"ic" ) , 1 , 0 , 0 } , { 140 , TARGET_STRING (
"modPSK_mod3/Receptor/Sincronismo de Trama/Constant1" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 141 , TARGET_STRING (
"modPSK_mod3/Receptor/Sincronismo de Trama/Constant10" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 142 , TARGET_STRING (
"modPSK_mod3/Receptor/Sincronismo de Trama/Constant13" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 143 , TARGET_STRING (
"modPSK_mod3/Receptor/Sincronismo de Trama/Constant14" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 144 , TARGET_STRING (
"modPSK_mod3/Receptor/Sincronismo de Trama/Constant15" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 145 , TARGET_STRING (
"modPSK_mod3/Receptor/Sincronismo de Trama/Constant16" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 146 , TARGET_STRING (
"modPSK_mod3/Receptor/Sincronismo de Trama/Constant2" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 147 , TARGET_STRING (
"modPSK_mod3/Receptor/Sincronismo de Trama/Constant3" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 148 , TARGET_STRING (
"modPSK_mod3/Receptor/Sincronismo de Trama/Constant4" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 149 , TARGET_STRING (
"modPSK_mod3/Receptor/Sincronismo de Trama/Constant5" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 150 , TARGET_STRING (
"modPSK_mod3/Receptor/Sincronismo de Trama/Constant6" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 151 , TARGET_STRING (
"modPSK_mod3/Receptor/Sincronismo de Trama/Constant7" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 152 , TARGET_STRING (
"modPSK_mod3/Receptor/Sincronismo de Trama/Constant8" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 153 , TARGET_STRING (
"modPSK_mod3/Receptor/Sincronismo de Trama/Constant9" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 154 , TARGET_STRING (
"modPSK_mod3/Receptor/Sincronismo de Trama/Switch" ) , TARGET_STRING (
"Threshold" ) , 0 , 0 , 0 } , { 155 , TARGET_STRING (
"modPSK_mod3/Receptor/Sincronismo de Trama/Transport Delay1" ) ,
TARGET_STRING ( "InitialOutput" ) , 0 , 0 , 0 } , { 156 , TARGET_STRING (
"modPSK_mod3/Receptor/Sincronismo de Trama/Transport Delay11" ) ,
TARGET_STRING ( "InitialOutput" ) , 0 , 0 , 0 } , { 157 , TARGET_STRING (
"modPSK_mod3/Receptor/Sincronismo de Trama/Transport Delay2" ) ,
TARGET_STRING ( "InitialOutput" ) , 0 , 0 , 0 } , { 158 , TARGET_STRING (
"modPSK_mod3/Receptor/Sincronismo de Trama/Transport Delay3" ) ,
TARGET_STRING ( "InitialOutput" ) , 0 , 0 , 0 } , { 159 , TARGET_STRING (
"modPSK_mod3/Receptor/Sincronismo de Trama/Transport Delay4" ) ,
TARGET_STRING ( "InitialOutput" ) , 0 , 0 , 0 } , { 160 , TARGET_STRING (
"modPSK_mod3/Receptor/Sincronismo de Trama/Transport Delay5" ) ,
TARGET_STRING ( "InitialOutput" ) , 0 , 0 , 0 } , { 161 , TARGET_STRING (
"modPSK_mod3/Receptor/Sincronismo de Trama/Transport Delay6" ) ,
TARGET_STRING ( "InitialOutput" ) , 0 , 0 , 0 } , { 162 , TARGET_STRING (
"modPSK_mod3/Receptor/Sincronismo de Trama/Transport Delay7" ) ,
TARGET_STRING ( "InitialOutput" ) , 0 , 0 , 0 } , { 163 , TARGET_STRING (
"modPSK_mod3/Receptor/Sincronismo de Trama/Transport Delay8" ) ,
TARGET_STRING ( "InitialOutput" ) , 0 , 0 , 0 } , { 164 , TARGET_STRING (
"modPSK_mod3/Receptor/Sincronismo de Trama/Transport Delay9" ) ,
TARGET_STRING ( "InitialOutput" ) , 0 , 0 , 0 } , { 165 , TARGET_STRING (
"modPSK_mod3/Receptor/Sincronismo de portadora/Constant2" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 166 , TARGET_STRING (
"modPSK_mod3/Receptor/Sincronismo de portadora/Constant5" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 167 , TARGET_STRING (
"modPSK_mod3/Receptor/Sincronismo de portadora/Constant6" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 168 , TARGET_STRING (
"modPSK_mod3/Receptor/Sincronismo de portadora/Integrator" ) , TARGET_STRING
( "InitialCondition" ) , 0 , 0 , 0 } , { 169 , TARGET_STRING (
"modPSK_mod3/Receptor/Sincronismo de portadora/Analog Filter Design" ) ,
TARGET_STRING ( "A_pr" ) , 0 , 1 , 0 } , { 170 , TARGET_STRING (
"modPSK_mod3/Receptor/Sincronismo de portadora/Analog Filter Design" ) ,
TARGET_STRING ( "A_ir" ) , 2 , 1 , 0 } , { 171 , TARGET_STRING (
"modPSK_mod3/Receptor/Sincronismo de portadora/Analog Filter Design" ) ,
TARGET_STRING ( "A_jc" ) , 2 , 5 , 0 } , { 172 , TARGET_STRING (
"modPSK_mod3/Receptor/Sincronismo de portadora/Analog Filter Design" ) ,
TARGET_STRING ( "B_pr" ) , 0 , 0 , 0 } , { 173 , TARGET_STRING (
"modPSK_mod3/Receptor/Sincronismo de portadora/Analog Filter Design" ) ,
TARGET_STRING ( "B_ir" ) , 2 , 0 , 0 } , { 174 , TARGET_STRING (
"modPSK_mod3/Receptor/Sincronismo de portadora/Analog Filter Design" ) ,
TARGET_STRING ( "B_jc" ) , 2 , 3 , 0 } , { 175 , TARGET_STRING (
"modPSK_mod3/Receptor/Sincronismo de portadora/Analog Filter Design" ) ,
TARGET_STRING ( "C_pr" ) , 0 , 0 , 0 } , { 176 , TARGET_STRING (
"modPSK_mod3/Receptor/Sincronismo de portadora/Analog Filter Design" ) ,
TARGET_STRING ( "C_ir" ) , 2 , 0 , 0 } , { 177 , TARGET_STRING (
"modPSK_mod3/Receptor/Sincronismo de portadora/Analog Filter Design" ) ,
TARGET_STRING ( "C_jc" ) , 2 , 5 , 0 } , { 178 , TARGET_STRING (
"modPSK_mod3/Receptor/Sincronismo de portadora/Analog Filter Design" ) ,
TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 179 , TARGET_STRING (
"modPSK_mod3/Receptor/Sincronismo de símbolo/Monostable1" ) , TARGET_STRING (
"EdgeDetect" ) , 0 , 0 , 0 } , { 180 , TARGET_STRING (
"modPSK_mod3/Receptor/Sincronismo de símbolo/Monostable1" ) , TARGET_STRING (
"ic" ) , 0 , 0 , 0 } , { 181 , TARGET_STRING (
"modPSK_mod3/Receptor/Sincronismo de símbolo/Monostable3" ) , TARGET_STRING (
"EdgeDetect" ) , 0 , 0 , 0 } , { 182 , TARGET_STRING (
"modPSK_mod3/Receptor/Sincronismo de símbolo/Monostable3" ) , TARGET_STRING (
"ic" ) , 0 , 0 , 0 } , { 183 , TARGET_STRING (
"modPSK_mod3/Receptor/Sincronismo de símbolo/Constant1" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 184 , TARGET_STRING (
"modPSK_mod3/Receptor/Sincronismo de símbolo/Integrator" ) , TARGET_STRING (
"InitialCondition" ) , 0 , 0 , 0 } , { 185 , TARGET_STRING (
"modPSK_mod3/Receptor/Sincronismo de símbolo/Integrator1" ) , TARGET_STRING (
"InitialCondition" ) , 0 , 0 , 0 } , { 186 , TARGET_STRING (
"modPSK_mod3/Receptor/Single Modulus Prescaler/Constant" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 187 , TARGET_STRING (
"modPSK_mod3/Receptor/Single Modulus Prescaler/Switch" ) , TARGET_STRING (
"Threshold" ) , 0 , 0 , 0 } , { 188 , TARGET_STRING (
"modPSK_mod3/Receptor/Single Modulus Prescaler/Logic Decision1" ) ,
TARGET_STRING ( "PropDelay" ) , 0 , 0 , 0 } , { 189 , TARGET_STRING (
"modPSK_mod3/Receptor/Detector/Sample and Hold/ " ) , TARGET_STRING (
"InitialOutput" ) , 0 , 0 , 0 } , { 190 , TARGET_STRING (
"modPSK_mod3/Receptor/Sincronismo de símbolo/Monostable1/Sample & Hold" ) ,
TARGET_STRING ( "ic" ) , 0 , 0 , 0 } , { 191 , TARGET_STRING (
"modPSK_mod3/Receptor/Sincronismo de símbolo/Monostable1/Memory" ) ,
TARGET_STRING ( "InitialCondition" ) , 1 , 0 , 0 } , { 192 , TARGET_STRING (
"modPSK_mod3/Receptor/Sincronismo de símbolo/Monostable3/Sample & Hold" ) ,
TARGET_STRING ( "ic" ) , 0 , 0 , 0 } , { 193 , TARGET_STRING (
"modPSK_mod3/Receptor/Sincronismo de símbolo/Monostable3/Memory" ) ,
TARGET_STRING ( "InitialCondition" ) , 1 , 0 , 0 } , { 194 , TARGET_STRING (
"modPSK_mod3/Receptor/Sincronismo de símbolo/Sample and Hold/ " ) ,
TARGET_STRING ( "InitialOutput" ) , 0 , 0 , 0 } , { 195 , TARGET_STRING (
"modPSK_mod3/Receptor/Sincronismo de símbolo/Sample and Hold2/ " ) ,
TARGET_STRING ( "InitialOutput" ) , 0 , 0 , 0 } , { 196 , TARGET_STRING (
"modPSK_mod3/Receptor/Single Modulus Prescaler/Compare To Zero/Constant" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 197 , TARGET_STRING (
 "modPSK_mod3/Receptor/Single Modulus Prescaler/Error checking /Check Static  Lower Bound"
) , TARGET_STRING ( "min" ) , 0 , 0 , 0 } , { 198 , TARGET_STRING (
 "modPSK_mod3/Receptor/Single Modulus Prescaler/Error checking /Check Static  Upper Bound"
) , TARGET_STRING ( "max" ) , 0 , 0 , 0 } , { 199 , TARGET_STRING (
"modPSK_mod3/Receptor/Single Modulus Prescaler/integer clock divider/clock_out"
) , TARGET_STRING ( "InitialOutput" ) , 0 , 0 , 0 } , { 200 , TARGET_STRING (
"modPSK_mod3/Receptor/Single Modulus Prescaler/integer clock divider/Constant2"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 201 , TARGET_STRING (
"modPSK_mod3/Receptor/Single Modulus Prescaler/integer clock divider/Unit Delay"
) , TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 202 ,
TARGET_STRING (
"modPSK_mod3/Receptor/Sincronismo de Trama/Monostable/Model/Sample and Hold"
) , TARGET_STRING ( "ic" ) , 0 , 0 , 0 } , { 203 , TARGET_STRING (
"modPSK_mod3/Receptor/Sincronismo de Trama/Monostable/Model/Memory" ) ,
TARGET_STRING ( "InitialCondition" ) , 1 , 0 , 0 } , { 204 , TARGET_STRING (
 "modPSK_mod3/Receptor/Sincronismo de portadora/ VCO/Modulo  Integrator/Modulo Integrator"
) , TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 205 ,
TARGET_STRING (
 "modPSK_mod3/Receptor/Sincronismo de portadora/ VCO/Modulo  Integrator/Modulo Integrator"
) , TARGET_STRING ( "WrappedStateUpperValue" ) , 0 , 0 , 0 } , { 206 ,
TARGET_STRING (
 "modPSK_mod3/Receptor/Sincronismo de portadora/ VCO/Modulo  Integrator/Modulo Integrator"
) , TARGET_STRING ( "WrappedStateLowerValue" ) , 0 , 0 , 0 } , { 207 ,
TARGET_STRING (
"modPSK_mod3/Receptor/Sincronismo de portadora/D Flip-Flop/D Flip-Flop/Q" ) ,
TARGET_STRING ( "InitialOutput" ) , 1 , 0 , 0 } , { 208 , TARGET_STRING (
"modPSK_mod3/Receptor/Sincronismo de portadora/D Flip-Flop/D Flip-Flop/!Q" )
, TARGET_STRING ( "InitialOutput" ) , 1 , 0 , 0 } , { 209 , TARGET_STRING (
 "modPSK_mod3/Receptor/Sincronismo de símbolo/Continuous-Time VCO/Modulo  Integrator/Modulo Integrator"
) , TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 210 ,
TARGET_STRING (
 "modPSK_mod3/Receptor/Sincronismo de símbolo/Continuous-Time VCO/Modulo  Integrator/Modulo Integrator"
) , TARGET_STRING ( "WrappedStateUpperValue" ) , 0 , 0 , 0 } , { 211 ,
TARGET_STRING (
 "modPSK_mod3/Receptor/Sincronismo de símbolo/Continuous-Time VCO/Modulo  Integrator/Modulo Integrator"
) , TARGET_STRING ( "WrappedStateLowerValue" ) , 0 , 0 , 0 } , { 212 ,
TARGET_STRING (
 "modPSK_mod3/Receptor/Sincronismo de símbolo/Monostable1/Edge Detector/either edge"
) , TARGET_STRING ( "Value" ) , 0 , 9 , 0 } , { 213 , TARGET_STRING (
 "modPSK_mod3/Receptor/Sincronismo de símbolo/Monostable1/Edge Detector/neg. edge"
) , TARGET_STRING ( "Value" ) , 0 , 9 , 0 } , { 214 , TARGET_STRING (
 "modPSK_mod3/Receptor/Sincronismo de símbolo/Monostable1/Edge Detector/pos. edge"
) , TARGET_STRING ( "Value" ) , 0 , 9 , 0 } , { 215 , TARGET_STRING (
 "modPSK_mod3/Receptor/Sincronismo de símbolo/Monostable3/Edge Detector/either edge"
) , TARGET_STRING ( "Value" ) , 0 , 9 , 0 } , { 216 , TARGET_STRING (
 "modPSK_mod3/Receptor/Sincronismo de símbolo/Monostable3/Edge Detector/neg. edge"
) , TARGET_STRING ( "Value" ) , 0 , 9 , 0 } , { 217 , TARGET_STRING (
 "modPSK_mod3/Receptor/Sincronismo de símbolo/Monostable3/Edge Detector/pos. edge"
) , TARGET_STRING ( "Value" ) , 0 , 9 , 0 } , { 218 , TARGET_STRING (
 "modPSK_mod3/Receptor/Sincronismo de Trama/Monostable/Model/Continuous Edge Detector/Constant1"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 219 , TARGET_STRING (
 "modPSK_mod3/Receptor/Sincronismo de Trama/Monostable/Model/Continuous Edge Detector/either edge"
) , TARGET_STRING ( "Value" ) , 0 , 9 , 0 } , { 220 , TARGET_STRING (
 "modPSK_mod3/Receptor/Sincronismo de Trama/Monostable/Model/Continuous Edge Detector/neg. edge"
) , TARGET_STRING ( "Value" ) , 0 , 9 , 0 } , { 221 , TARGET_STRING (
 "modPSK_mod3/Receptor/Sincronismo de Trama/Monostable/Model/Continuous Edge Detector/pos. edge"
) , TARGET_STRING ( "Value" ) , 0 , 9 , 0 } , { 222 , TARGET_STRING (
 "modPSK_mod3/Receptor/Sincronismo de símbolo/Monostable1/Edge Detector/NEGATIVE Edge/OUT"
) , TARGET_STRING ( "InitialOutput" ) , 1 , 0 , 0 } , { 223 , TARGET_STRING (
 "modPSK_mod3/Receptor/Sincronismo de símbolo/Monostable1/Edge Detector/POSITIVE Edge/OUT"
) , TARGET_STRING ( "InitialOutput" ) , 1 , 0 , 0 } , { 224 , TARGET_STRING (
 "modPSK_mod3/Receptor/Sincronismo de símbolo/Monostable3/Edge Detector/NEGATIVE Edge/OUT"
) , TARGET_STRING ( "InitialOutput" ) , 1 , 0 , 0 } , { 225 , TARGET_STRING (
 "modPSK_mod3/Receptor/Sincronismo de símbolo/Monostable3/Edge Detector/POSITIVE Edge/OUT"
) , TARGET_STRING ( "InitialOutput" ) , 1 , 0 , 0 } , { 226 , TARGET_STRING (
 "modPSK_mod3/Receptor/Sincronismo de Trama/Monostable/Model/Continuous Edge Detector/NEGATIVE Edge/OUT"
) , TARGET_STRING ( "InitialOutput" ) , 1 , 0 , 0 } , { 227 , TARGET_STRING (
 "modPSK_mod3/Receptor/Sincronismo de Trama/Monostable/Model/Continuous Edge Detector/POSITIVE Edge/OUT"
) , TARGET_STRING ( "InitialOutput" ) , 1 , 0 , 0 } , { 228 , TARGET_STRING (
 "modPSK_mod3/Receptor/Sincronismo de Trama/Monostable/Model/Continuous Edge Detector/Internal dirac generator/Triggered Subsystem/Out1"
) , TARGET_STRING ( "InitialOutput" ) , 0 , 0 , 0 } , { 0 , ( NULL ) , ( NULL
) , 0 , 0 , 0 } } ; static int_T rt_LoggedStateIdxList [ ] = { - 1 } ; static
const rtwCAPI_Signals rtRootInputs [ ] = { { 0 , 0 , ( NULL ) , ( NULL ) , 0
, 0 , 0 , 0 , 0 } } ; static const rtwCAPI_Signals rtRootOutputs [ ] = { { 0
, 0 , ( NULL ) , ( NULL ) , 0 , 0 , 0 , 0 , 0 } } ; static const
rtwCAPI_ModelParameters rtModelParameters [ ] = { { 229 , TARGET_STRING (
"Amplitud" ) , 0 , 0 , 0 } , { 230 , TARGET_STRING ( "AmplitudPortadora" ) ,
0 , 0 , 0 } , { 231 , TARGET_STRING ( "Att_Volt_Canal" ) , 0 , 0 , 0 } , {
232 , TARGET_STRING ( "C" ) , 0 , 0 , 0 } , { 233 , TARGET_STRING (
"Frec_port" ) , 0 , 0 , 0 } , { 234 , TARGET_STRING ( "Kv" ) , 0 , 0 , 0 } ,
{ 235 , TARGET_STRING ( "R1" ) , 0 , 0 , 0 } , { 236 , TARGET_STRING ( "R2" )
, 0 , 0 , 0 } , { 237 , TARGET_STRING ( "Rb" ) , 0 , 0 , 0 } , { 238 ,
TARGET_STRING ( "Retraso_Canal" ) , 0 , 0 , 0 } , { 239 , TARGET_STRING (
"Tb" ) , 0 , 0 , 0 } , { 240 , TARGET_STRING ( "b" ) , 0 , 0 , 0 } , { 241 ,
TARGET_STRING ( "kv2" ) , 0 , 0 , 0 } , { 242 , TARGET_STRING ( "varRuido" )
, 0 , 0 , 0 } , { 0 , ( NULL ) , 0 , 0 , 0 } } ;
#ifndef HOST_CAPI_BUILD
static void * rtDataAddrMap [ ] = { & rtB . f2es2rkn4r , & rtB . ailrsbpb25 ,
& rtB . bfrc2rc5zl , & rtB . dxp2tc3fwu [ 0 ] , & rtB . lyj5czwr1t , & rtB .
lrg23dznf5 , & rtB . mxwhtwoxqb , & rtB . hzfal5kgng , & rtB . d4txlaulvr , &
rtB . nihlui3tdy , & rtB . dzwzyjfb3d , & rtB . ncgerps2w1 , & rtB .
pl5zjiseby , & rtB . l1u4z2oxl4 , & rtB . ktacawrolb , & rtB . lno2d3wb5h [ 0
] , & rtB . f5g5ssvz0ob . n0jiemzt0m , & rtB . hs04wl1crq , & rtB .
nutzsr0h3j , & rtB . pznu3l5z1a , & rtB . eancnret3z , & rtB . m2vnyqktog , &
rtB . dxje1nzfb1 , & rtB . kmqtx532fz , & rtB . bhvr0udrsy , & rtB .
lsnuriwz44 , & rtB . hnp1kuefxm , & rtB . ewq0jsmjdj , & rtB . lisuhkiql3 , &
rtB . nz2mzf3abt , & rtB . dv3oqsxz41 , & rtB . geeegghaq4 , & rtB .
ncdgrorzsx , & rtB . awbajcw3bs , & rtB . ao3hvbk03u , & rtB . cjvhltyh5i , &
rtB . amouf3rzmf , & rtB . pokud50mlj . n0jiemzt0m , & rtB . ki1f5bwrru , &
rtB . o0mruwezip , & rtB . pgstwodvgn , & rtB . k0xpbzxvuq , & rtB .
gopo0ay43o , & rtB . o51erkdynh , & rtB . gnsbtz3idv , & rtB . c5lvecx0ln , &
rtB . nk4rw4u2ad , & rtB . f5g5ssvz0ob . n0jiemzt0m , & rtB . pxicmncoih , &
rtB . d0uzclm1vr , & rtB . pet04kmorq , & rtB . asbkydpcdt , & rtB .
bq2qwyyni3 , & rtB . bxjduwjkqo , & rtB . ohloxwa40r , & rtB . lfy2bgoxg0 , &
rtB . amouf3rzmf , & rtB . pokud50mlj . n0jiemzt0m , & rtB . gnsbtz3idv , &
rtB . k0hg52okk1 , & rtB . efvczhdjet , & rtB . p4bwi2pbc0 , & rtB .
fv3qrvs3nd , & rtB . d0uzclm1vr , & rtB . pet04kmorq , & rtB . obgcvvf2c2c .
gcuafzmxgi , & rtB . guziuj3nzou . fncspxqpzn , & rtB . ji14ejc3mp , & rtB .
ck3j1srrxl [ 0 ] , & rtB . agrizcdfza , & rtB . mxxtwp3ieb , & rtB .
ntt0n0z3qa . gcuafzmxgi , & rtB . l2pxsorbc0 . fncspxqpzn , & rtB .
dwgm1iwulr , & rtB . pnagitghhg [ 0 ] , & rtB . h3lftethav , & rtB .
kiqo1dkx4d , & rtB . kowifb0jnq , & rtB . fv5bybewyw , & rtB . octfr53rd1 , &
rtB . i3hvpke3ms , & rtB . hrmk3oqzup , & rtB . ftifgsd50u , & rtB .
kppvt5er43 [ 0 ] , & rtB . obgcvvf2c2c . gcuafzmxgi , & rtB . guziuj3nzou .
fncspxqpzn , & rtB . ntt0n0z3qa . gcuafzmxgi , & rtB . l2pxsorbc0 .
fncspxqpzn , & rtB . c1tvvwnguu , & rtB . octfr53rd1 , & rtB . i3hvpke3ms , &
rtB . k3la20515u , & rtB . jfofwf5qdn , & rtP . RuidoAGWN_Mean , & rtP .
RuidoAGWN_Seed , & rtP . TransportDelay_InitOutput , & rtP .
matrizGeneradora_Value [ 0 ] , & rtP . Unbuffer_ic , & rtP .
Constant_Value_bfe1ms15wt , & rtP . AnalogFilterDesign_A_pr_gc0kz31g5a [ 0 ]
, & rtP . AnalogFilterDesign_A_ir_o3wehlil1t [ 0 ] , & rtP .
AnalogFilterDesign_A_jc_hepc5hv3fw [ 0 ] , & rtP .
AnalogFilterDesign_B_pr_kq1k3m2fjm , & rtP .
AnalogFilterDesign_B_ir_bqybfmsaae , & rtP .
AnalogFilterDesign_B_jc_cfquo51aq1 [ 0 ] , & rtP .
AnalogFilterDesign_C_pr_aqq5iiwnf2 , & rtP .
AnalogFilterDesign_C_ir_ivqqscx0vn , & rtP .
AnalogFilterDesign_C_jc_llcs1qdtjn [ 0 ] , & rtP .
AnalogFilterDesign_InitialCondition_l2mskoueic , & rtP . FromWorkspace_Data0
[ 0 ] , & rtP . AddConstant_Bias_ljcfbacsm3 , & rtP .
Multiply_Gain_ptvyavefxe , & rtP . SineWave_Bias , & rtP . SineWave_Phase , &
rtP . AnalogFilterDesign_A_pr [ 0 ] , & rtP . AnalogFilterDesign_A_ir [ 0 ] ,
& rtP . AnalogFilterDesign_A_jc [ 0 ] , & rtP . AnalogFilterDesign_B_pr , &
rtP . AnalogFilterDesign_B_ir , & rtP . AnalogFilterDesign_B_jc [ 0 ] , & rtP
. AnalogFilterDesign_C_pr , & rtP . AnalogFilterDesign_C_ir , & rtP .
AnalogFilterDesign_C_jc [ 0 ] , & rtP . AnalogFilterDesign_InitialCondition ,
& rtP . Integrator_IC , & rtP . AnalogFilterDesign_A_pr_f4zixacbw1 [ 0 ] , &
rtP . AnalogFilterDesign_A_ir_cx1zj2mhzp [ 0 ] , & rtP .
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
rtP . Constant15_Value , & rtP . Constant16_Value , & rtP .
Constant2_Value_ldvsshgj3v , & rtP . Constant3_Value , & rtP .
Constant4_Value , & rtP . Constant5_Value , & rtP . Constant6_Value , & rtP .
Constant7_Value , & rtP . Constant8_Value , & rtP . Constant9_Value , & rtP .
Switch_Threshold_bmfda2wh42 , & rtP . TransportDelay1_InitOutput , & rtP .
TransportDelay11_InitOutput , & rtP . TransportDelay2_InitOutput , & rtP .
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
Integrator1_IC , & rtP . Constant_Value_i2hydlpkci , & rtP . Switch_Threshold
, & rtP . LogicDecision1_PropDelay , & rtP . f5g5ssvz0ob . _Y0 , & rtP .
SampleHold_ic , & rtP . Memory_InitialCondition_oggd2r4odw , & rtP .
SampleHold_ic_cvpetr2ktj , & rtP . Memory_InitialCondition_ljulw4woig , & rtP
. _Y0 , & rtP . pokud50mlj . _Y0 , & rtP . Constant_Value , & rtP .
CheckStaticLowerBound_min , & rtP . CheckStaticUpperBound_max , & rtP .
clock_out_Y0 , & rtP . Constant2_Value , & rtP . UnitDelay_InitialCondition ,
& rtP . SampleandHold_ic , & rtP . Memory_InitialCondition , & rtP .
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
rtP . negedge_Value [ 0 ] , & rtP . posedge_Value [ 0 ] , & rtP . obgcvvf2c2c
. OUT_Y0 , & rtP . guziuj3nzou . OUT_Y0 , & rtP . ntt0n0z3qa . OUT_Y0 , & rtP
. l2pxsorbc0 . OUT_Y0 , & rtP . OUT_Y0 , & rtP . OUT_Y0_gbikirmbla , & rtP .
Out1_Y0 , & rtP . Amplitud , & rtP . AmplitudPortadora , & rtP .
Att_Volt_Canal , & rtP . C , & rtP . Frec_port , & rtP . Kv , & rtP . R1 , &
rtP . R2 , & rtP . Rb , & rtP . Retraso_Canal , & rtP . Tb , & rtP . b , &
rtP . kv2 , & rtP . varRuido , } ; static int32_T * rtVarDimsAddrMap [ ] = {
( NULL ) } ;
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
rtwCAPI_MATRIX_COL_MAJOR , 2 , 2 , 0 } , { rtwCAPI_VECTOR , 4 , 2 , 0 } , {
rtwCAPI_VECTOR , 6 , 2 , 0 } , { rtwCAPI_VECTOR , 8 , 2 , 0 } , {
rtwCAPI_VECTOR , 10 , 2 , 0 } , { rtwCAPI_VECTOR , 12 , 2 , 0 } , {
rtwCAPI_VECTOR , 14 , 2 , 0 } , { rtwCAPI_VECTOR , 16 , 2 , 0 } } ; static
const uint_T rtDimensionArray [ ] = { 1 , 1 , 7 , 1 , 2 , 1 , 1 , 7 , 5 , 1 ,
24 , 1 , 15 , 1 , 9 , 1 , 1 , 2 } ; static const real_T rtcapiStoredFloats [
] = { 0.0 , 2.5E-7 , 0.0007 , 9.9999999999999991E-5 , 1.0 , - 2.0 } ; static
const rtwCAPI_FixPtMap rtFixPtMap [ ] = { { ( NULL ) , ( NULL ) ,
rtwCAPI_FIX_RESERVED , 0 , 0 , ( boolean_T ) 0 } , } ; static const
rtwCAPI_SampleTimeMap rtSampleTimeMap [ ] = { { ( const void * ) &
rtcapiStoredFloats [ 0 ] , ( const void * ) & rtcapiStoredFloats [ 0 ] , (
int8_T ) 0 , ( uint8_T ) 0 } , { ( const void * ) & rtcapiStoredFloats [ 1 ]
, ( const void * ) & rtcapiStoredFloats [ 0 ] , ( int8_T ) 2 , ( uint8_T ) 0
} , { ( const void * ) & rtcapiStoredFloats [ 2 ] , ( const void * ) &
rtcapiStoredFloats [ 0 ] , ( int8_T ) 4 , ( uint8_T ) 0 } , { ( const void *
) & rtcapiStoredFloats [ 3 ] , ( const void * ) & rtcapiStoredFloats [ 0 ] ,
( int8_T ) 3 , ( uint8_T ) 0 } , { ( NULL ) , ( NULL ) , - 1 , 0 } , { (
const void * ) & rtcapiStoredFloats [ 0 ] , ( const void * ) &
rtcapiStoredFloats [ 4 ] , ( int8_T ) 1 , ( uint8_T ) 0 } , { ( const void *
) & rtcapiStoredFloats [ 5 ] , ( const void * ) & rtcapiStoredFloats [ 0 ] ,
( int8_T ) 5 , ( uint8_T ) 0 } , { ( NULL ) , ( NULL ) , 6 , 0 } } ; static
rtwCAPI_ModelMappingStaticInfo mmiStatic = { { rtBlockSignals , 93 ,
rtRootInputs , 0 , rtRootOutputs , 0 } , { rtBlockParameters , 136 ,
rtModelParameters , 14 } , { ( NULL ) , 0 } , { rtDataTypeMap ,
rtDimensionMap , rtFixPtMap , rtElementMap , rtSampleTimeMap ,
rtDimensionArray } , "float" , { 815223402U , 1087110751U , 1550997493U ,
3421349989U } , ( NULL ) , 0 , ( boolean_T ) 0 , rt_LoggedStateIdxList } ;
const rtwCAPI_ModelMappingStaticInfo * modPSK_mod3_GetCAPIStaticMap ( void )
{ return & mmiStatic ; }
#ifndef HOST_CAPI_BUILD
void modPSK_mod3_InitializeDataMapInfo ( void ) { rtwCAPI_SetVersion ( ( *
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
void modPSK_mod3_host_InitializeDataMapInfo ( modPSK_mod3_host_DataMapInfo_T
* dataMap , const char * path ) { rtwCAPI_SetVersion ( dataMap -> mmi , 1 ) ;
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
