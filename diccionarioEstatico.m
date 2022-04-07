function [diccionario] = diccionarioEstatico(data)
    tam= length(data);
    index = 0;
    indexBin = dec2bin(index, 6);
    diccionario = [indexBin, convertCharsToStrings(data(1))];
    for i=2:tam
        if ~contains(diccionario, data(i))           
            index = index + 1;
            indexBin = dec2bin(index, 6);
            diccionario = cat(1, diccionario, [indexBin, convertCharsToStrings(data(i))]);
        end
    end
end