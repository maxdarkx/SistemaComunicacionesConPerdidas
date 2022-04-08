function [datosRx] = decodificadorLZW(diccionario, datosTxString, diccionarioDinamicoTx, datoTx)
    
    totalBits = strlength(datosTxString);
    diccionarioDinamico = diccionario;
    i = 1;
    j = 1;
    datoAnterior = string.empty;
    datoActual = string.empty;
    datosRx = string.empty;
    index = length(diccionarioDinamico)-2;
    while i < totalBits
        condicion = false;
        bitsALeer = strlength(diccionarioDinamico(end,1));
        
        while ~condicion
            buscado = extractBetween(datosTxString,i,i+bitsALeer-1);
            encontrado = matches(diccionarioDinamico(:,1),buscado);
            
            for j = 1:length(encontrado)
                if encontrado(j)
                    condicion = true;
                    break;
                end
            end
    
            if condicion
                index = index + 1;
                datoActual = diccionarioDinamico(j,2);
                datosRx = cat(1, datosRx, [buscado, datoActual]);
                if i > 1
                    tamanoDinamico = ceil(log2(length(diccionarioDinamico) - 1));
                    indexBin = dec2bin(index, tamanoDinamico);
                    dato = strcat(datoAnterior, datoActual);
                    cantidadCaracteresDato = strlength(dato);

                    k = 1;
                    while k <= cantidadCaracteresDato
                        buscado = extractBetween(dato,1,k);
                        encontrado = matches(diccionarioDinamico(:,2),buscado);
                        condicionDiccionario = false;
                        for m = 1:length(encontrado)
                            if encontrado(m)
                                condicionDiccionario = true;
                                break;
                            end
                        end
                        if condicionDiccionario
                            k = k + 1;
                        elseif k >= cantidadCaracteresDato
                            datoBuscado = buscado;
                            break;
                        else
                            datoBuscado = buscado;
                            break;
                        end
                    end
                    diccionarioDinamico = cat(1, diccionarioDinamico, [indexBin, datoBuscado]);
                end
            else
                bitsALeer = bitsALeer - 1;
            end
        end
        datoAnterior = datoActual;
        i = i + bitsALeer;   
    end
end