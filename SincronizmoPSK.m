clc
clear all;

%Sistema implementado para recuperar el sincronismo de portadora 
% en PSK utilizando un PLL tipo 2
Rb = 1e4;                          %Rata en bps
Frec_port = 1e6 ;                       
Tb = 1 / Rb;                        %Tiempo de bit
Amplitud = 1;                       %Amplitud de los pulsos enviados.
Long_Canal = 3e2;                    %Distancia del canal [km]
GT = 10   ;                          %Ganancia de antena transmisora [dBi]
Gr = 10  ;                          %Ganancia de antena receptora [dBi]
Lambda = 3e8 / Frec_port ;          %Longitud de onda [m]
Att_dB= 22 + 20 * log10(Long_Canal * 1000 / Lambda)- GT - Gr;
Att_pot_Canal = 10^(Att_dB / 10);
Att_Volt_Canal = 10^(Att_dB / 20);
C_canal = 3e5 ;                     %Velocidad onda electromagnética en el vacio [km/s]
Retraso_Canal = Long_Canal / C_canal+0.5/Frec_port;
Prob_error=1e-2;                    %Probabilidad de error de bit
x = 2.4;
AnchoDeBandaRuido = 2E6;

k = 1.3806e-23;
eta = k * 150;


Ancho_banda_minimo = Rb / 2;
Energia_recibida = (2.3267^2)*(eta/2);
Energia_transmitida = Energia_recibida * Att_pot_Canal ;
PotenciaTransmitida = Energia_transmitida * Rb;
%AmplitudPortadora = sqrt(2*PotenciaTransmitida)
AmplitudPortadora = 2.326*sqrt(eta/Tb);

Umbral = 0;


Pot_Ruido = eta * AnchoDeBandaRuido;

%Pot_Ruido = 2*eta * Ancho_banda_minimo

%Sincronismo de portadora
 
Ts = Tb / 5;                            %Tiempo de establecimiento
zita = 0.6;
Kp = 0.5;
Kv = 1E5;
wn = 4.5 / Ts;
C = 1e-6;                                  %Capacitancia 
R1 = Kp * Kv / (wn^2 * C);
R2 = 2 * zita / (wn * C);

%Sincronismo de reloj usando la compuerta Early Late.

kv2 = Rb^2/10;
b = 0.85;

%Sincronismo de trama

%PBarker = [1 1 1 1 1 0 0 1 1 0 1 0 1];
PBarker = [1 1 1 0 0 0 1 0 0 1 1];
dataTx = round(rand(1,1000),0);
dataBasura1 = round(rand(1,100),0);
dataBasura2 = [1 1 1 0 0 0 1 1 1 0 0 0 1];
dataprecisa = round(rand(1,100),0);
%TxBuffer = [ PBarker, dataprecisa];
TxBuffer = [dataBasura1, PBarker, dataTx, dataBasura2];
%TxBuffer = [PBarker, dataTx];

%verificar el dato desde 1112 hasta terminar el vector

%%
%Pot_Ruido = Pot_Ruido/2000000;
varRuido = eta

%% output a archivo
tx = TxBuffer;
datasize = size(out.Rx)
datasize = datasize(1,3)
rx = reshape(out.Rx(1,1,:),[1, datasize] );
%rx = out.Rx(2:end, :);
%rx = rx(2:end, :)';

writematrix(tx,'tx.txt','Delimiter', ' ', 'WriteMode', 'overwrite');
writematrix(rx,'rx.txt','Delimiter', ' ', 'WriteMode', 'overwrite');

%% calculo datos
tx1 = dataTx
rx1Size = size(out.Rx1)
rx1Size = rx1Size(1,3)
rx1 = reshape(out.Rx(1,1,:),[1, rx1size])
sum(abs(tx1(1:end) - rx))



