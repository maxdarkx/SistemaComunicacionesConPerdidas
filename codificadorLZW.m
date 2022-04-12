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
        tamanoDinamicoActual = ceil(log2(length(diccionarioDinamico) - 1));

        if tamanoBusquedaTotal + i >= tamanoTexto
            tamanoBusqueda = tamanoTexto - i;
        else
            tamanoBusqueda = tamanoBusquedaTotal;
        end

        [i tamanoBusqueda tamanoBusquedaTotal]
        while(~condicion)
            buscado = convertCharsToStrings(texto(i:i + tamanoBusqueda));     
            
            [posicion, condicion] = buscarDato (diccionarioDinamico, buscado)
            
            if condicion
                codigoEnviadoFila = horzcat(diccionarioDinamico(posicion, :), num2str(tamanoDinamicoActual));
                codigoEnviado = vertcat(codigoEnviado, codigoEnviadoFila);
                tamanoBusqueda = tamanoBusqueda + 1;
                tamanoBusquedaTotal = max(tamanoBusqueda, tamanoBusquedaTotal);
                index = index + 1;
                indexBin = dec2bin(index, tamanoDinamicoActual);

                
                if i+tamanoBusqueda < tamanoTexto
                    dato = convertCharsToStrings(texto(i:i+tamanoBusqueda));
                    diccionarioDinamico = cat(1, diccionarioDinamico, [num2str(index), dato]);
                end              
            else
                tamanoBusqueda = tamanoBusqueda - 1;
            end
        end
        i = i + tamanoBusqueda;
    end

    binarioEnviado = dec2bin(str2num(codigoEnviado(1,1)),str2num(codigoEnviado(1,3)));
    codigoEnviadoString = binarioEnviado;
    for i=2:length(codigoEnviado)
        binarioEnviado = dec2bin(str2num(codigoEnviado(i,1)),str2num(codigoEnviado(i,3)));
        codigoEnviadoString = strcat(codigoEnviadoString, binarioEnviado);
    end
end