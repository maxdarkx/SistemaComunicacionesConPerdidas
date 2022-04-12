function [patronError] = buscarSindrome (diccionario, buscado)
    
    encontrado = matches(diccionario(:, 2), buscado);
    condicion = false;
    posicion = -1;
    for j = 1:length(encontrado)
        if encontrado(j)
            condicion = true;
            posicion = j;
            break;
        end
    end 
    patronError = diccionario(posicion,2);
end