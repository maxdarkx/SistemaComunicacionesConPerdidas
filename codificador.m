%% Lectura de archivo
clear all
close all
archivoId = fopen('Laboratorio senales 2\Poema2.txt','r');
formatSpec = "%c";
poema = fscanf(archivoId, formatSpec);

%% Asignacion de variables basica
diccionario = diccionarioEstatico(poema);
diccionarioDinamico = strings(1,length(diccionario));
for i = 1:length(diccionario)
    diccionarioDinamico(i) = convertCharsToStrings(diccionario(i));
end
diccionario1 = diccionarioDinamico';
tamanoPoema = length(poema);
tamanoDinamico = ceil(log2(length(diccionarioDinamico) - 1));
tamanoDiccionario = length(diccionarioDinamico);
indices = int16.empty;
tamanoBusqueda = 1;
tamanoBusquedaTotal = 1;

%% extraccion del diccionario dinamico
i = 1;
while i <= tamanoPoema
    condicion = false;
    if tamanoBusquedaTotal + i > tamanoPoema
        tamanoBusqueda = tamanoPoema - i - 1;
    else
        tamanoBusqueda = tamanoBusquedaTotal;
    end
    while(~condicion)
        buscado = convertCharsToStrings(poema(i:i + tamanoBusqueda));     
        encontrado = contains(diccionarioDinamico, buscado);
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
            diccionarioDinamico = [diccionarioDinamico poema(i:i+tamanoBusqueda)];
            %indices = [indices; length(diccionarioDinamico)];
        else
            tamanoBusqueda = tamanoBusqueda - 1;
        end
        tamanoDinamico = ceil(log2(length(diccionarioDinamico) - 1));
        tamanoDiccionario = length(diccionarioDinamico);
    end
    i = i + tamanoBusqueda + 1;
end
diccionarioDinamico = diccionarioDinamico';