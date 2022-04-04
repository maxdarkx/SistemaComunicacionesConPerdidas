%%clear all,close all, clc
%% Transmision
rata_bit=1.75e3;% frecuencia de trasmision de datos 
tb=1/rata_bit;%tiempo de bit 
ancho_filtro=rata_bit/2;%ancho del filtro en el transmisor 
fc=175e3;%frecuancia de la portadora 
Potencia=0.4;%Potencia de transmision 
Amplitud=sqrt(Potencia);%amplitud de la portadora 
Gt=10^(0.6)%Ganacia de transmisor 
Ener_transmitida=0.9*Amplitud^2*tb/2% energia transmitida 
%% Canal 
lambda=3e8/fc%longitud deonda 
long=20*lambda%distancia entre transmisor y receptor 
Gr=Gt%Ganancia del receptor 
atenua_potencia=(4*pi*long/lambda)^2/(Gt*Gr)%Atenuacion en Potencia 
atenua_voltaje=sqrt(atenua_potencia);%atenuacion voltaje 
retardo_canal=long/3e8%retardo del canal 
%%
proba_error=1e-3;%probabilidad error presente en el sistema 
switch proba_error
    case 1e-1
        x=1.3;
    case 1e-2
        x=2.4;
    case 1e-3
        x=3.1;
    case 1e-4
        x=3.8;
    case 1e-5
        x=4.3;
    case 1e-6
        x=4.8;
    case 1e-7
        x=5.2;
    case 1e-8
        x=5.7;
end
%% Receptor 
Ener_recibida=Ener_transmitida/atenua_potencia%energia recibida en el receptor 
eta=2*Ener_recibida/x^2%densidad espectral de ruido 
Potencia_ruido=eta*ancho_filtro;%Potencia del ruido

%% PLL
R1=200e3%valor de resistencia para el filtro de lazo
R2=9e3%valor de resistencia para el filtro de lazo
C=1.5e-9%valor de capacitancia para el filtro de lazo

%% Compuerta early
b=tb*0.2;%tiempo de retardo para los integradores 
%% Deteccion de error 
retardo_filtro=1.7/rata_bit;%retardo debido a los filtros 
retardo_decision=1/rata_bit;%retardo en la tomada de decision 
