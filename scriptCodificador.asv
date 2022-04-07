%% Lectura de archivo
clear all
close all
archivoId = fopen('Poema2.txt','r');
formatSpec = '%c';
poema = fscanf(archivoId, formatSpec);

%% Asignacion de variables basica
diccionario = diccionarioEstatico(poema);
[datoTx, diccionarioDinamico] = codificadorLZW(poema, diccionario);