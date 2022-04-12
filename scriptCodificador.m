%% Lectura de archivo
clearvars
close all
archivoId = fopen('Poema2.txt','r');
formatSpec = '%c';
poema = fscanf(archivoId, formatSpec);

%% codificacion del mensaje mediante LZW
diccionario = diccionarioEstatico(poema);
[datoTxString, datoTx, diccionarioDinamicoTx] = codificadorLZW(poema, diccionario);

%% decodificacion del mensaje mediante LZW
strlength(datoTxString)
[datoRx, diccionarioDinamicoRx] = decodificadorLZW(diccionario, datoTxString);