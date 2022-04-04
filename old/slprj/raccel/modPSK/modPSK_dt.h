#include "ext_types.h"
static DataTypeInfo rtDataTypeInfoTable [ ] = { { "real_T" , 0 , 8 } , {
"real32_T" , 1 , 4 } , { "int8_T" , 2 , 1 } , { "uint8_T" , 3 , 1 } , {
"int16_T" , 4 , 2 } , { "uint16_T" , 5 , 2 } , { "int32_T" , 6 , 4 } , {
"uint32_T" , 7 , 4 } , { "boolean_T" , 8 , 1 } , { "fcn_call_T" , 9 , 0 } , {
"int_T" , 10 , 4 } , { "pointer_T" , 11 , 8 } , { "action_T" , 12 , 8 } , {
"timer_uint32_pair_T" , 13 , 8 } , { "physical_connection" , 14 , 8 } , {
"uint64_T" , 15 , 8 } , { "int64_T" , 16 , 8 } , { "char_T" , 17 , 8 } , {
"uchar_T" , 18 , 8 } , { "time_T" , 19 , 8 } } ; static uint_T
rtDataTypeSizes [ ] = { sizeof ( real_T ) , sizeof ( real32_T ) , sizeof (
int8_T ) , sizeof ( uint8_T ) , sizeof ( int16_T ) , sizeof ( uint16_T ) ,
sizeof ( int32_T ) , sizeof ( uint32_T ) , sizeof ( boolean_T ) , sizeof (
fcn_call_T ) , sizeof ( int_T ) , sizeof ( pointer_T ) , sizeof ( action_T )
, 2 * sizeof ( uint32_T ) , sizeof ( int32_T ) , sizeof ( uint64_T ) , sizeof
( int64_T ) , sizeof ( char_T ) , sizeof ( uchar_T ) , sizeof ( time_T ) } ;
static const char_T * rtDataTypeNames [ ] = { "real_T" , "real32_T" ,
"int8_T" , "uint8_T" , "int16_T" , "uint16_T" , "int32_T" , "uint32_T" ,
"boolean_T" , "fcn_call_T" , "int_T" , "pointer_T" , "action_T" ,
"timer_uint32_pair_T" , "physical_connection" , "uint64_T" , "int64_T" ,
"char_T" , "uchar_T" , "time_T" } ; static DataTypeTransition rtBTransitions
[ ] = { { ( char_T * ) ( & rtB . ee42tgof2b ) , 0 , 0 , 63 } , { ( char_T * )
( & rtB . djf3ji5ytw ) , 8 , 0 , 11 } , { ( char_T * ) ( & rtB . cmjzvpvpsf .
olytfz4wp1 ) , 0 , 0 , 1 } , { ( char_T * ) ( & rtB . jdw3pbikft . k0x4is02ar
) , 8 , 0 , 1 } , { ( char_T * ) ( & rtB . hdzoplw4kn . e5aa54psh5 ) , 8 , 0
, 1 } , { ( char_T * ) ( & rtB . msxjrffonnn . k0x4is02ar ) , 8 , 0 , 1 } , {
( char_T * ) ( & rtB . ggca33mvdun . e5aa54psh5 ) , 8 , 0 , 1 } , { ( char_T
* ) ( & rtB . nrqkqpzimhq . olytfz4wp1 ) , 0 , 0 , 1 } , { ( char_T * ) ( &
rtDW . bssa0c1myd ) , 0 , 0 , 19 } , { ( char_T * ) ( & rtDW . f5j5cwamx4 .
TimePtr ) , 11 , 0 , 49 } , { ( char_T * ) ( & rtDW . afqavbs5ty ) , 7 , 0 ,
1 } , { ( char_T * ) ( & rtDW . eidamkhewj . PrevIndex ) , 10 , 0 , 18 } , {
( char_T * ) ( & rtDW . izid4kf2wl ) , 2 , 0 , 6 } , { ( char_T * ) ( & rtDW
. ezpzvynldc ) , 8 , 0 , 11 } , { ( char_T * ) ( & rtDW . cmjzvpvpsf .
j13iuzvksk ) , 2 , 0 , 1 } , { ( char_T * ) ( & rtDW . jdw3pbikft .
o3j2yaswp3 ) , 2 , 0 , 1 } , { ( char_T * ) ( & rtDW . hdzoplw4kn .
o0iconal0v ) , 2 , 0 , 1 } , { ( char_T * ) ( & rtDW . msxjrffonnn .
o3j2yaswp3 ) , 2 , 0 , 1 } , { ( char_T * ) ( & rtDW . ggca33mvdun .
o0iconal0v ) , 2 , 0 , 1 } , { ( char_T * ) ( & rtDW . nrqkqpzimhq .
j13iuzvksk ) , 2 , 0 , 1 } } ; static DataTypeTransitionTable rtBTransTable =
{ 20U , rtBTransitions } ; static DataTypeTransition rtPTransitions [ ] = { {
( char_T * ) ( & rtP . Amplitud ) , 0 , 0 , 20 } , { ( char_T * ) ( & rtP .
Monostable_ic ) , 8 , 0 , 1 } , { ( char_T * ) ( & rtP . Out1_Y0 ) , 0 , 0 ,
1222 } , { ( char_T * ) ( & rtP . AnalogFilterDesign_A_ir [ 0 ] ) , 7 , 0 ,
79 } , { ( char_T * ) ( & rtP . OUT_Y0 ) , 8 , 0 , 8 } , { ( char_T * ) ( &
rtP . cmjzvpvpsf . _Y0 ) , 0 , 0 , 1 } , { ( char_T * ) ( & rtP . jdw3pbikft
. OUT_Y0 ) , 8 , 0 , 1 } , { ( char_T * ) ( & rtP . hdzoplw4kn . OUT_Y0 ) , 8
, 0 , 1 } , { ( char_T * ) ( & rtP . msxjrffonnn . OUT_Y0 ) , 8 , 0 , 1 } , {
( char_T * ) ( & rtP . ggca33mvdun . OUT_Y0 ) , 8 , 0 , 1 } , { ( char_T * )
( & rtP . nrqkqpzimhq . _Y0 ) , 0 , 0 , 1 } } ; static
DataTypeTransitionTable rtPTransTable = { 11U , rtPTransitions } ;
