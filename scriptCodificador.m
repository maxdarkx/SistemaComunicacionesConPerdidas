%% Lectura de archivo
clear all
close all
archivoId = fopen('Poema2.txt','r');
formatSpec = '%c';
poema = fscanf(archivoId, formatSpec);

%% codificacion del mensaje mediante LZW
diccionario = diccionarioEstatico(poema);
[datoTxString, datoTx, diccionarioDinamicoTx] = codificadorLZW(poema, diccionario);

%% decodificacion del mensaje mediante LZW
strlength(datoTxString)
[datoRx] = decodificadorLZW(diccionario, datoTxString, diccionarioDinamicoTx, datoTx)