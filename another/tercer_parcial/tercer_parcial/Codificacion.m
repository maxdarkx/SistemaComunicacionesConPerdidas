
%% codificador 

texto='Alimentando_lluvias,_caracolas.'%_y_órganos_mi_dolor_sin_instrumento,_a_las_desalentadas_amapolas_daré_tu_corazón_por_alimento.';
Dicc=[];
ind_dicc=1;
ind_actual=1;
ind_gen=[];
ind_bin=['010'];

for i=1: 256
    dicc1=i;
    pal=string(char(dicc1));
    Dicc=[Dicc pal];
end 

car=texto(ind_actual);
while 1<2
    char2=strcat(car,texto(ind_actual+1));%char2:char anterior + nuevo caracter
    if(compare(char2,Dicc))
       ind_actual=ind_actual+1;
       car=char2;
       %char=strcat(char,texto(ind_actual+1)) 
    else
        char2=string(char2)
        Dicc=[Dicc char2];%agregamos al diccionario la palabra ocurrida(ho,ol,la...)
        ind_dicc=ind_dicc+1;       
        ind_gen=[ind_gen indice(car,Dicc)];%buscamos el indice en el diccionario
        car=texto(ind_actual+1);
        if(car=='.')
            ind_gen=[ind_gen indice(car,Dicc)];
            break
        end
        ind_actual=ind_actual+1;
    end    
end 
for i=1:length(ind_gen) 
        bin=dec2bin(ind_gen(i),9);
        ind_bin=[ind_bin bin];      
end
for i=1:10
    ind_bin=[ind_bin '0'];
end
num_bits=length(ind_bin);
Datos=[];
duracion=50;
for i=1:length(ind_bin)
    if ind_bin(i)=='1'
        aux=ones(1,duracion);
    else
        aux=zeros(1,duracion);
    end 
    Datos=[Datos aux];
end
Datos=[Datos 0];
rb=1.75e3;
tb=1/rb;
tiempo=0:tb/duracion:tb*length(ind_bin);
Datos2=[tiempo',Datos'];
function r= compare(car,Dicc)
    r=0;
    car=string(car);
    for i=1:length(Dicc)
        if(car==Dicc(i))
            r=1;
        end
    end
end
function r= indice(car,Dicc)
    car=string(car);
    for i=1:length(Dicc)
        if(car==Dicc(i))
            r=i;
        end
    end
end
