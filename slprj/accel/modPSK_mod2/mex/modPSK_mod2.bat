@echo off
set MATLAB=C:\Program Files\MATLAB\R2022a
"%MATLAB%\bin\win64\gmake" -f modPSK_mod2.mk  OPTS="-DTID01EQ=0"
