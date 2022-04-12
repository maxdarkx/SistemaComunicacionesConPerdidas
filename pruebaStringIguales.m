for i = 1: length(datoTx)
    prueba = true;
    if datoTx(i,1) ~= num2str(bin2dec(datoRx(i,1)))
        prueba = false
        i
        break;
    end
end

prueba