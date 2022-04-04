
texto='Alimentando_lluvias,_caracolas_y_órganos_mi_dolor_sin_instrumento,_a_las_desalentadas_amapolas_daré_tu_corazón_por_alimento.';
codifi= [];%bits recibidos de la transmision
%'0000100010000110010000101001100011100001000110001000001001001010000010000010001011001100000011000001001101001110001010001111000001010000000001001111001001000010101001001010010001001010010010010000010011011111001001001101001010000100000001100010100100001000001000010010010000000101000011010000011000011000010101001000000110100001110010000000101100110110011101000100101010110000001010001101101000001000000010100011010011000001110000111100001000011010000000010000100000000100101000110010101011001011100010101000101000001110001011010110010001000000001001011000100101001001110001010001010011000001101010110110001001'
%codifi=  '001100001001101100001101001001101101001100101001101110001110100001100001001101110001100100001101111001011111001101100001101100001110101001110110001101001001100001001110011000101100001011111001100011001100001001110010001100001001100011001101111001101100100010010001011111001111001001011111011110011001110010001100111100001000001101111001110011001011111001101101001101001001011111100001010001101100001101111001110010001011111001110011001101001001101110001011111100110001001110011001110100001110010001110101100000100100000110001101111100010100001100001100001100100011101001100100001100101001110011100000001100000101100000111001100100100011101001100001001101101001100001001110000100011011100111111100010111011101001001011111001110100001110101100010101100101101001100001001111010011110011100110010101001011100101110100000001100000011101000100001101111'
codific=[];
decimal=[];
decodif=[];
dicc_dec=[];
ind_diccd=1;

in=1;
band=1
pal=[];

for i=1: 256 %Creamos el diccionario inicial
    dicc2=i;
    pal1=string(char(dicc2));
    dicc_dec=[dicc_dec pal1];
end 

tiempo2=Datos_salida.time;
valor=Datos_salida.signals.values;
valor=double(valor);

% i=0;
% ban2=1;
% t_inicial=0;
% t_final=0;
% while 1<2
%  i=i+1;
%  if (valor(i)==1 && ban2==1)
%      ban2=0;
%      t_inicial=i;%Datos2(i,1);
%  elseif(valor(i)==0 && ban2==0)
%      ban2=0;
%      t_final=i-1;%Datos2(i-1,1);
%      break 
%  end
% end
j=0;
tiempo_bit2=0
tb
tiempo2(j+1)
while 1<2
    j=j+1;
    if(tiempo2(j)<=tb)
        tiempo_bit2=tiempo_bit2+1;
    else
        break
    end
end
tiempo_bit=t_final-t_inicial-1;%calculamos el tiempo de bit que entrega simulink
for i=1:tiempo_bit:length(valor)%extraemos los bits transmitidos 
    if(valor(i)==1)
        codifi=[codifi,'1'];
    else
        codifi=[codifi,'0'];
    end
end
for i=1: length(codifi)%Calculamos la posicion de los bits erroneos 
    nume=[];
    z=i;
    for j=1:9
        num=codifi(z);
        nume=[nume num];
        z=z+1;
    end
    dec= bin2dec(nume);
    if (dec==0 |dec > 256)
        letra='1'
    else
        letra=dicc_dec(dec)
        letra=char(letra)
    end 
    if(letra==texto(1))
        in=i;
        break
    end    
  end 
w=in;
for i=w:length(codifi)%creamos una nueva cadena(codific) de bits que inicia con los correctos 
    new=codifi(i);
    codific=[codific new];
    
end
    
tama=length(dicc_dec);
paso=9;
cont=length(dicc_dec);

 for i=1:paso:length(codific)
    nume=[];
    if (cont==tama)
        for j=1:9
           num=codific(j);
           nume=[nume num];
        end       
        dec= bin2dec(nume);
        decimal=[decimal dec];
        cont=cont+2;
 
   elseif(cont>tama & cont< 512)
      
       for j=0:8
            indi=i+j;
           if(indi>length(codific))
               break
           else
          
           num=codific(indi);
           nume=[nume num];
           end
       end 
    dec= bin2dec(nume);
    decimal=[decimal dec];
    cont=cont+1; 
   
    elseif(cont==512 );
       
        if(cont>512)
            i=i+1;
        end
       for j=0:8
           indi=i+j;
           if(indi>length(codific))
               break
           else
          
           num=codific(indi);
           nume=[nume num];
           end
       end 
      
        dec= bin2dec(nume);
        decimal=[decimal dec];
        cont=cont+1
        i=i;
        break      
    end  
 end
paso=paso+1
in=i+paso;

 for i=in:paso:length (codific)
    nume=[];
  
   if(cont>512 && cont< 1023)
      
       for j=0:9
           indi=i+j;
         if(indi>length(codific))
               break
          else

           num=codific(indi);
           nume=[nume num];
         end 
       end
    dec= bin2dec(nume);
    decimal=[decimal dec];
       cont=cont+1; 
    
    elseif(cont==1023 );
       
        if(cont>1023)
            i=i+1;
        end
       for j=0:9
           indi=i+j;
           num=codifi(indi);
           nume=[nume num];
       end 
       
        dec= bin2dec(nume);
        decimal=[decimal dec];
        cont=cont+1
        i=i;
        break       
    end
 end 

 tam=length(decimal)-1;
for i=1:tam
    
    val1=decimal(i)
    val2=decimal(i+1)
    if (val1==0 | val2==0 )
        break 
    else 
        uno= dicc_dec(val1);
        dos= dicc_dec(val2); 
        uno=char(uno)%convertStringsToChars(uno);
        dos=char(dos)%convertStringsToChars(dos);
        nume=length(dos);
        if (length(dos)==2)
            dos=dos(1);
        elseif(length(dos)==3)
            dos=dos(1);
        elseif (length(dos)==4)
            dos=dos(1);
        end
        decodif=strcat(decodif,uno);
        chart=strcat(uno,dos);
        dicc_dec=[dicc_dec chart];
    end 
end 
clc
decodif