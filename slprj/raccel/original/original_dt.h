#include "ext_types.h"
static DataTypeInfo rtDataTypeInfoTable [ ] = { { "real_T" , 0 , 8 } , {
"real32_T" , 1 , 4 } , { "int8_T" , 2 , 1 } , { "uint8_T" , 3 , 1 } , {
"int16_T" , 4 , 2 } , { "uint16_T" , 5 , 2 } , { "int32_T" , 6 , 4 } , {
"uint32_T" , 7 , 4 } , { "boolean_T" , 8 , 1 } , { "fcn_call_T" , 9 , 0 } , {
"int_T" , 10 , 4 } , { "pointer_T" , 11 , 8 } , { "action_T" , 12 , 8 } , {
"timer_uint32_pair_T" , 13 , 8 } , { "physical_connection" , 14 , 8 } , {
"int64_T" , 15 , 8 } , { "uint64_T" , 16 , 8 } , { "uint64_T" , 17 , 8 } , {
"int64_T" , 18 , 8 } , { "char_T" , 19 , 8 } , { "uchar_T" , 20 , 8 } , {
"time_T" , 21 , 8 } } ; static uint_T rtDataTypeSizes [ ] = { sizeof ( real_T
) , sizeof ( real32_T ) , sizeof ( int8_T ) , sizeof ( uint8_T ) , sizeof (
int16_T ) , sizeof ( uint16_T ) , sizeof ( int32_T ) , sizeof ( uint32_T ) ,
sizeof ( boolean_T ) , sizeof ( fcn_call_T ) , sizeof ( int_T ) , sizeof (
pointer_T ) , sizeof ( action_T ) , 2 * sizeof ( uint32_T ) , sizeof (
int32_T ) , sizeof ( int64_T ) , sizeof ( uint64_T ) , sizeof ( uint64_T ) ,
sizeof ( int64_T ) , sizeof ( char_T ) , sizeof ( uchar_T ) , sizeof ( time_T
) } ; static const char_T * rtDataTypeNames [ ] = { "real_T" , "real32_T" ,
"int8_T" , "uint8_T" , "int16_T" , "uint16_T" , "int32_T" , "uint32_T" ,
"boolean_T" , "fcn_call_T" , "int_T" , "pointer_T" , "action_T" ,
"timer_uint32_pair_T" , "physical_connection" , "int64_T" , "uint64_T" ,
"uint64_T" , "int64_T" , "char_T" , "uchar_T" , "time_T" } ; static
DataTypeTransition rtBTransitions [ ] = { { ( char_T * ) ( & rtB . pczptaloqn
) , 0 , 0 , 62 } , { ( char_T * ) ( & rtB . orn3venhnk ) , 8 , 0 , 11 } , { (
char_T * ) ( & rtB . o0byjwoyow . lzgwbwuubl ) , 0 , 0 , 1 } , { ( char_T * )
( & rtB . llvx0kbake . elss3awww2 ) , 8 , 0 , 1 } , { ( char_T * ) ( & rtB .
iewfgzwb31 . o3dp55eklq ) , 8 , 0 , 1 } , { ( char_T * ) ( & rtB .
ligjpsfhvtg . elss3awww2 ) , 8 , 0 , 1 } , { ( char_T * ) ( & rtB .
mjqilvpgl54 . o3dp55eklq ) , 8 , 0 , 1 } , { ( char_T * ) ( & rtB .
mnr2afncj2u . lzgwbwuubl ) , 0 , 0 , 1 } , { ( char_T * ) ( & rtDW .
eflcwal1mu ) , 0 , 0 , 18 } , { ( char_T * ) ( & rtDW . g24kh0yl0d . TimePtr
) , 11 , 0 , 49 } , { ( char_T * ) ( & rtDW . kqimps20tr . PrevIndex ) , 10 ,
0 , 18 } , { ( char_T * ) ( & rtDW . n1tmln402w ) , 2 , 0 , 6 } , { ( char_T
* ) ( & rtDW . fgt0gfkzzs ) , 8 , 0 , 11 } , { ( char_T * ) ( & rtDW .
o0byjwoyow . bmw2hixe1f ) , 2 , 0 , 1 } , { ( char_T * ) ( & rtDW .
llvx0kbake . idqwe24upn ) , 2 , 0 , 1 } , { ( char_T * ) ( & rtDW .
iewfgzwb31 . fulyjjxmue ) , 2 , 0 , 1 } , { ( char_T * ) ( & rtDW .
ligjpsfhvtg . idqwe24upn ) , 2 , 0 , 1 } , { ( char_T * ) ( & rtDW .
mjqilvpgl54 . fulyjjxmue ) , 2 , 0 , 1 } , { ( char_T * ) ( & rtDW .
mnr2afncj2u . bmw2hixe1f ) , 2 , 0 , 1 } } ; static DataTypeTransitionTable
rtBTransTable = { 19U , rtBTransitions } ; static DataTypeTransition
rtPTransitions [ ] = { { ( char_T * ) ( & rtP . Amplitud ) , 0 , 0 , 19 } , {
( char_T * ) ( & rtP . Monostable_ic ) , 8 , 0 , 1 } , { ( char_T * ) ( & rtP
. Out1_Y0 ) , 0 , 0 , 1233 } , { ( char_T * ) ( & rtP .
AnalogFilterDesign_A_ir [ 0 ] ) , 7 , 0 , 79 } , { ( char_T * ) ( & rtP .
OUT_Y0 ) , 8 , 0 , 8 } , { ( char_T * ) ( & rtP . o0byjwoyow . _Y0 ) , 0 , 0
, 1 } , { ( char_T * ) ( & rtP . llvx0kbake . OUT_Y0 ) , 8 , 0 , 1 } , { (
char_T * ) ( & rtP . iewfgzwb31 . OUT_Y0 ) , 8 , 0 , 1 } , { ( char_T * ) ( &
rtP . ligjpsfhvtg . OUT_Y0 ) , 8 , 0 , 1 } , { ( char_T * ) ( & rtP .
mjqilvpgl54 . OUT_Y0 ) , 8 , 0 , 1 } , { ( char_T * ) ( & rtP . mnr2afncj2u .
_Y0 ) , 0 , 0 , 1 } } ; static DataTypeTransitionTable rtPTransTable = { 11U
, rtPTransitions } ;
