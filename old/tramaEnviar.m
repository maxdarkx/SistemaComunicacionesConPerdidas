PBauker = [1 1 1 0 1 1 0 1 0 0 0];
TxBuffer = ones(1,1000);
dataTemp = rand(1,1000);

for i=1:1000
    if(dataTemp(i)>0.5)
    
        TxBuffer(i) = 1;
    else
        TxBuffer(i) = 0;
    end
end
TxBuffer = cat(2,PBauker,TxBuffer)
TxBuffer = cat(2,TxBuffer,PBauker)