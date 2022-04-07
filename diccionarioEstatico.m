function [diccionario] = diccionarioEstatico(data)
    tam= length(data);
    diccionario = [dec2bin(0, 6), convertCharsToStrings(data(1))];
    for i=2:tam
        if ~contains(diccionario, data(i))
            [string(i-1), dec2bin(i-1, 6)]
            diccionario = cat(1, diccionario, [dec2bin(i-1, 6), convertCharsToStrings(data(i))]);
        end
    end
end