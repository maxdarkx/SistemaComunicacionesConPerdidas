function [diccionario] = diccionarioEstatico(data)
    tam= length(data);
    indexBin = "0";
    diccionario = [dec2bin(0, 6), convertCharsToStrings(data(1))];
    for i=2:tam
        if ~contains(diccionario, data(i))
            index = i-1; 
            indexBin = dec2bin(index, 6);
            diccionario = cat(1, diccionario, [indexBin, convertCharsToStrings(data(i))]);
        end
    end
end