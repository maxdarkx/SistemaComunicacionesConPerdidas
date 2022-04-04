%CODIFICACIÓN DE FUENTE----------------------------------------------------
%--------------------------------------------------------------------------
archivo=fopen('Poema.txt','r');
Poema=fgetl(archivo);
Poema=double(Poema);
Si=readtable('CodificaciónF.xlsx','Range','B5:B38');
Si=table2array(Si);
Si=cell2mat(Si);
Si=double(Si);
Codigos=readtable('CodificaciónF.xlsx','Range','E5:E38');
Codigos=table2array(Codigos);
a=1;
f=1;
Pbarker=[1 1 1 1 1 0 0 1 1 0 1 0 1];

while a<=size(Poema,2)
    while f<=size(Si,1)
        if Si(f,1)~=Poema(1,a)
            f=f+1;
        else 
            Matriz(1,a)=string(Codigos(f,1));
            break
        end
    end
    a=a+1;
    f=1;
end

Trama='';

for i=1:size(Matriz,2)
    aux=string(Matriz(1,i));
    i=i+1;
    Trama=strcat(Trama,aux);
end

caracteres=convertStringsToChars(Trama);

for  k=1:size(caracteres,2)
    Vector(k)=str2double((caracteres(k)));
end

Codificacionf=Vector';



%CODIFICACIÓN DE CANAL-----------------------------------------------------
%--------------------------------------------------------------------------
Terna=readtable('CodificaciónC.xlsx','Range','C3:C11');
Terna=table2array(Terna);
Codigo=readtable('CodificaciónC.xlsx','Range','D3:D11');
Codigo=table2array(Codigo);
ceros=0;

while mod(size(Codificacionf,1),3)~=0
    Codificacionf=[0; Codificacionf]
    ceros=1+ceros;
end

j=1;

for i=1:3:(size(Codificacionf,1))
    Tramaaux='';
    aux2=string(Codificacionf(i,1));
    Tramaaux=strcat(Tramaaux,aux2);
    i=i+1;
    aux2=string(Codificacionf(i,1));
    Tramaaux=strcat(Tramaaux,aux2);
    i=i+1;
    aux2=string(Codificacionf(i,1));
    Tramaaux=strcat(Tramaaux,aux2);
    Trama2(j,1)=string(Tramaaux);
    j=j+1;
end

x=1;
y=1;

while x<=size(Trama2,1)
    while y<=size(Terna,1)
        if Terna(y,1)~=Trama2(x,1)
            y=y+1;
        else 
            Codificacionc(x,1)=string(Codigo(y,1));
            break
        end
    end
    x=x+1;
    y=1;
end

Envio='';

for z=1:size(Codificacionc,1)
    aux3=string(Codificacionc(z,1));
    z=z+1;
    Envio=strcat(Envio,aux3);
end

caracteres2=convertStringsToChars(Envio);

for  p=1:size(caracteres2,2)
    Vector2(p)=str2double((caracteres2(p)));
end

Bits=Vector2';


%TRANSMISIÓN---------------------------------------------------------------
%--------------------------------------------------------------------------

TX.time = [];
TX.signals.values = [Pbarker';Bits];
TX.signals.dimensions = 1;

%--------------------------------------------------------------------------
Tsim=925*Tb;
