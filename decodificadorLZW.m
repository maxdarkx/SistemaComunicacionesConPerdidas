function [datosRx, diccionarioDinamico] = decodificadorLZW(diccionario, datosTxString)
    
    totalBits = strlength(datosTxString);
    diccionarioDinamico = diccionario;
    i = 1;
    datoAnterior = string.empty;
    datoActual = string.empty;
    datosRx = string.empty;
    index = length(diccionarioDinamico)-2;

    while i < totalBits
        estaEnElDiccionarioDinamico = false;
        bitsALeer = ceil(log2(length(diccionarioDinamico)));
        
        while ~estaEnElDiccionarioDinamico
            buscado = extractBetween(datosTxString,i,i+bitsALeer-1);
            indiceEnteroBuscado = bin2dec(buscado);
            [posicion, estaEnElDiccionarioDinamico] = buscarIndiceDeDato(diccionarioDinamico, indiceEnteroBuscado);
            
            if estaEnElDiccionarioDinamico 
                index = index + 1;
                datoActual = diccionarioDinamico(posicion,2);
                datosRx = cat(1, datosRx, [buscado, datoActual]);

                if i > 1
                    tamanoDinamico = ceil(log2(length(diccionarioDinamico) - 1));
                    indexBin = dec2bin(index, tamanoDinamico);
                    dato = strcat(datoAnterior, datoActual);
                    cantidadCaracteresDato = strlength(dato);

                    k = 1;
                    while k <= cantidadCaracteresDato
                        buscado = extractBetween(dato,1,k);
                        [~, estaEnElDiccionario] = buscarDato (diccionarioDinamico, buscado);
                        
                        if estaEnElDiccionario
                            k = k + 1;
                        else
                            datoBuscado = buscado;
                            break;
                        end
                    end
                    diccionarioDinamico = cat(1, diccionarioDinamico, [num2str(bin2dec(indexBin)), datoBuscado]);
                end
            end
        end
        datoAnterior = datoActual;
        i = i + bitsALeer;   
    end
end