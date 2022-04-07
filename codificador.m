%% Lectura de archivo
clear all
close all
archivoId = fopen('Poema2.txt','r');
formatSpec = '%c';
poema = fscanf(archivoId, formatSpec);

%% Asignacion de variables basica
diccionario = diccionarioEstatico(poema);
diccionarioDinamico = diccionario;
tamanoPoema = length(poema);
tamanoDinamico = ceil(log2(length(diccionarioDinamico) - 1));
tamanoDiccionario = length(diccionarioDinamico);
indices = int16.empty;
tamanoBusqueda = 1;
tamanoBusquedaTotal = 1;

%% extraccion del diccionario dinamico
i = 1;
index = length(diccionarioDinamico);
tamanoDinamico = ceil(log2(length(diccionarioDinamico) - 1));
indexBin = dec2bin(index, tamanoDinamico);

while i <= tamanoPoema
    condicion = false;
    if tamanoBusquedaTotal + i > tamanoPoema
        tamanoBusqueda = tamanoPoema - i - 1;
    else
        tamanoBusqueda = tamanoBusquedaTotal;
    end
    while(~condicion)
        buscado = convertCharsToStrings(poema(i:i + tamanoBusqueda));     
        encontrado = contains(diccionarioDinamico(:, 2), buscado)
        for j = 1:length(encontrado)
            if encontrado(j)
                condicion = true;
                break;
            end
        end
        condicion;
        if condicion
            tamanoBusqueda = tamanoBusqueda + 1;
            tamanoBusquedaTotal = max(tamanoBusqueda, tamanoBusquedaTotal);
            index = index + 1;
            tamanoDinamico = ceil(log2(length(diccionarioDinamico) - 1));
            indexBin = dec2bin(index, tamanoDinamico);
            dato = convertCharsToStrings(poema(i:i+tamanoBusqueda));
            diccionarioDinamico = cat(1, diccionarioDinamico, [indexBin, dato]);
        else
            tamanoBusqueda = tamanoBusqueda - 1;
        end
    end
    i = i + tamanoBusqueda + 1;
end