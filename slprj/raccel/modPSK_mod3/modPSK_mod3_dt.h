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
DataTypeTransition rtBTransitions [ ] = { { ( char_T * ) ( & rtB . dxp2tc3fwu
[ 0 ] ) , 0 , 0 , 75 } , { ( char_T * ) ( & rtB . p4bwi2pbc0 ) , 8 , 0 , 15 }
, { ( char_T * ) ( & rtB . pokud50mlj . n0jiemzt0m ) , 0 , 0 , 1 } , { (
char_T * ) ( & rtB . l2pxsorbc0 . fncspxqpzn ) , 8 , 0 , 1 } , { ( char_T * )
( & rtB . ntt0n0z3qa . gcuafzmxgi ) , 8 , 0 , 1 } , { ( char_T * ) ( & rtB .
guziuj3nzou . fncspxqpzn ) , 8 , 0 , 1 } , { ( char_T * ) ( & rtB .
obgcvvf2c2c . gcuafzmxgi ) , 8 , 0 , 1 } , { ( char_T * ) ( & rtB .
f5g5ssvz0ob . n0jiemzt0m ) , 0 , 0 , 1 } , { ( char_T * ) ( & rtDW .
adesp1hwj2 [ 0 ] ) , 0 , 0 , 41 } , { ( char_T * ) ( & rtDW . c550b3xklm .
TimePtr ) , 11 , 0 , 62 } , { ( char_T * ) ( & rtDW . gv0a02tm0t ) , 6 , 0 ,
2 } , { ( char_T * ) ( & rtDW . bzmxqssdoq ) , 7 , 0 , 4 } , { ( char_T * ) (
& rtDW . kb5rvgdujd . PrevIndex ) , 10 , 0 , 13 } , { ( char_T * ) ( & rtDW .
olipbciiyt ) , 2 , 0 , 8 } , { ( char_T * ) ( & rtDW . kia112cgkq ) , 8 , 0 ,
8 } , { ( char_T * ) ( & rtDW . pokud50mlj . kw45gvclvl ) , 2 , 0 , 1 } , { (
char_T * ) ( & rtDW . l2pxsorbc0 . mzbzupg3uq ) , 2 , 0 , 1 } , { ( char_T *
) ( & rtDW . l2pxsorbc0 . miqumv2j33 ) , 8 , 0 , 1 } , { ( char_T * ) ( &
rtDW . ntt0n0z3qa . igzqysubwr ) , 2 , 0 , 1 } , { ( char_T * ) ( & rtDW .
ntt0n0z3qa . jfiw2hmwe4 ) , 8 , 0 , 1 } , { ( char_T * ) ( & rtDW .
guziuj3nzou . mzbzupg3uq ) , 2 , 0 , 1 } , { ( char_T * ) ( & rtDW .
guziuj3nzou . miqumv2j33 ) , 8 , 0 , 1 } , { ( char_T * ) ( & rtDW .
obgcvvf2c2c . igzqysubwr ) , 2 , 0 , 1 } , { ( char_T * ) ( & rtDW .
obgcvvf2c2c . jfiw2hmwe4 ) , 8 , 0 , 1 } , { ( char_T * ) ( & rtDW .
f5g5ssvz0ob . kw45gvclvl ) , 2 , 0 , 1 } } ; static DataTypeTransitionTable
rtBTransTable = { 25U , rtBTransitions } ; static DataTypeTransition
rtPTransitions [ ] = { { ( char_T * ) ( & rtP . Amplitud ) , 0 , 0 , 23 } , {
( char_T * ) ( & rtP . Monostable_ic ) , 8 , 0 , 1 } , { ( char_T * ) ( & rtP
. Out1_Y0 ) , 0 , 0 , 159 } , { ( char_T * ) ( & rtP .
AnalogFilterDesign_A_ir [ 0 ] ) , 7 , 0 , 100 } , { ( char_T * ) ( & rtP .
OUT_Y0 ) , 8 , 0 , 8 } , { ( char_T * ) ( & rtP . pokud50mlj . _Y0 ) , 0 , 0
, 1 } , { ( char_T * ) ( & rtP . l2pxsorbc0 . OUT_Y0 ) , 8 , 0 , 1 } , { (
char_T * ) ( & rtP . ntt0n0z3qa . OUT_Y0 ) , 8 , 0 , 1 } , { ( char_T * ) ( &
rtP . guziuj3nzou . OUT_Y0 ) , 8 , 0 , 1 } , { ( char_T * ) ( & rtP .
obgcvvf2c2c . OUT_Y0 ) , 8 , 0 , 1 } , { ( char_T * ) ( & rtP . f5g5ssvz0ob .
_Y0 ) , 0 , 0 , 1 } } ; static DataTypeTransitionTable rtPTransTable = { 11U
, rtPTransitions } ;
