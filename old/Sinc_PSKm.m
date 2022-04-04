%Sistema implementado para recuperar el sincronismo de portadora 
% en PSK utilizando un PLL tipo 2
Rb = 1000;                          %Rata en bps
Frec_port = 100 * Rb;                        
Tb = 1 / Rb;                        %Tiempo de bit
Amplitud = 1;                       %Amplitud de los pulsos enviados.
Long_Canal = 10;                    %Distancia del canal [km]
GT = 3   ;                          %Ganancia de antena transmisora [dBi]
Gr = 3   ;                          %Ganancia de antena receptora [dBi]
Lambda = 3e8 / Frec_port ;          %Longitud de onda [m]
Att_dB= 22 + 20 * log10(Long_Canal * 1000 / Lambda)- GT - Gr;
Att_pot_Canal = 10^(Att_dB / 10);
Att_Volt_Canal = 10^(Att_dB / 20);
C_canal = 3e5 ;                     %Velocidad onda electromagnética en el vacio [km/s]
Retraso_Canal = Long_Canal / C_canal+0.5/Frec_port; 
Prob_error=1e-6;                    %Probabilidad de error de bit

switch Prob_error
    case 1e-1
        x = 1.3;
    case 1e-2
        x = 2.4;
    case 1e-3
        x = 3.1;
    case 1e-4
        x = 3.8;
    case 1e-5
        x = 4.3;
    case 1e-6
        x = 4.8;
end

Modulacion = 3 ;            %Tipo de mod:1:ASK, 2:FSK 3:PSK

switch Modulacion
    case 1
        k = 0.5;
        Energia_transmitida = 0.9 * (Amplitud^2) / (2 * Rb);
        Ancho_banda_minimo = Rb / 2;
        Energia_recibida = Energia_transmitida / Att_pot_Canal;
        Umbral = Energia_recibida / 2;
    case 2
        k = 1;
        Energia_transmitida = 0.9 * (Amplitud^2) / (2*Rb);
        Ancho_banda_minimo = Rb / 2;
        Energia_recibida = Energia_transmitida / Att_pot_Canal;
        Umbral = 0;
    case 3
        k = 2;
        Energia_transmitida = 0.9 * (Amplitud^2) /(2 * Rb);
        Ancho_banda_minimo = Rb / 2;
        Energia_recibida = Energia_transmitida / Att_pot_Canal;
        Umbral = 0;
end
eta = k * Energia_recibida / (x^2);
Pot_Ruido = 2*eta * Ancho_banda_minimo;

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
b = 0.6;