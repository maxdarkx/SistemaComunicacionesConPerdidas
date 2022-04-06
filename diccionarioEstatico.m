function [diccionario] = diccionarioEstatico(data)
    tam= length(data);
    diccionario = data(1);
    for i=2:tam
        if ~contains(diccionario, data(i))
            diccionario = [diccionario data(i)];
        end
    end
end