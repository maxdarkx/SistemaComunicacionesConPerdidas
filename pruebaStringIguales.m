prueba = true;
for i = 1: length(datoTx)
    if datoTx(i,1) ~= num2str(bin2dec(datoRx(i,1)))
        prueba = false
        i
        break;
    end
end
prueba


pruebaDiccionario = true;
for i = 1: length(diccionarioDinamicoTx)
    if diccionarioDinamicoTx(i,2) ~= diccionarioDinamicoRx(i,2)
        pruebaDiccionario = false
        i
        break;
    end
end
pruebaDiccionario
