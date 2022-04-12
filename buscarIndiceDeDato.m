function [posicion, condicion] = buscarIndiceDeDato (diccionario, buscado)
    
    encontrado = matches(diccionario(:, 1), num2str(buscado));
    condicion = false;
    posicion = -1;
    for j = 1:length(encontrado)
        if encontrado(j)
            condicion = true;
            posicion = j;
            break;
        end
    end 
end