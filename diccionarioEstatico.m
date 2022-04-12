function [diccionario] = diccionarioEstatico(data)
    tam= length(data);
    index = 0;
    diccionario = [index, convertCharsToStrings(data(1))];
    for i=2:tam
        if ~contains(diccionario, data(i))           
            index = index + 1;
            diccionario = cat(1, diccionario, [num2str(index), convertCharsToStrings(data(i))]);
        end
    end
end