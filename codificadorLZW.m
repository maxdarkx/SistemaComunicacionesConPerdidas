function [codigoEnviadoString, codigoEnviado, diccionarioDinamico]  = codificadorLZW(texto, diccionario)

    diccionarioDinamico = diccionario;
    tamanoTexto = length(texto);
    tamanoDiccionario = length(diccionarioDinamico);
    tamanoBusqueda = 1;
    tamanoBusquedaTotal = 1;
    codigoEnviado = string.empty;
    codigoEnviadoString = string.empty;
    i = 1;
    j = 1;
    index = length(diccionarioDinamico)-1;
    tamanoDinamico = ceil(log2(length(diccionarioDinamico) - 1));
    indexBin = dec2bin(index, tamanoDinamico);
    
    while i <= tamanoTexto
       
        condicion = false;
        if tamanoBusquedaTotal + i >= tamanoTexto
            tamanoBusqueda = tamanoTexto - i;
        else
            tamanoBusqueda = tamanoBusquedaTotal;
        end

        [i tamanoBusqueda tamanoBusquedaTotal];
        while(~condicion)
            buscado = convertCharsToStrings(texto(i:i + tamanoBusqueda));     
            encontrado = matches(diccionarioDinamico(:, 2), buscado);
            for j = 1:length(encontrado)
                if encontrado(j)
                    condicion = true;
                    break;
                end
            end
            
            if condicion
                codigoEnviado = cat(1, codigoEnviado, diccionarioDinamico(j,:));
                
                tamanoBusqueda = tamanoBusqueda + 1;
                tamanoBusquedaTotal = max(tamanoBusqueda, tamanoBusquedaTotal);
                index = index + 1;
                tamanoDinamico = ceil(log2(length(diccionarioDinamico) - 1));
                indexBin = dec2bin(index, tamanoDinamico);
                
                if i+tamanoBusqueda < tamanoTexto
                    dato = convertCharsToStrings(texto(i:i+tamanoBusqueda));
                    diccionarioDinamico = cat(1, diccionarioDinamico, [indexBin, dato]);
                end              
            else
                tamanoBusqueda = tamanoBusqueda - 1;
            end
        end
        i = i + tamanoBusqueda;
    end

    codigoEnviadoString = codigoEnviado(1,1);
    for i=2:length(codigoEnviado)
        codigoEnviadoString = strcat(codigoEnviadoString, codigoEnviado(i,1));
    end
end