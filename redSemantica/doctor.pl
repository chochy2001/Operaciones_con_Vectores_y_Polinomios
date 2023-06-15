%hechos
tiene_sintoma(alicia,cansansio).
tiene_sintoma(manuel,fiebre).
sintoma_de(fiebre,gripe).
sintoma_de(tos,gripe).
sintoma_de(cansancio,anemia).
elimina(vitaminas,cansancio).
elimina(aspirinas,fiebre).
elimina(jarabe,tos).


% Reglas
recetar_a(X,Y) :- enfermo_de(Y,A), alivia(X,A).
% puede recetar medicamento X a la persona Y
% si la persona Y esta enfermo de A
% y el medicamento X aliva A


alivia(X,Y) :- elimina(X,A), sintoma_de(A,Y).

enfermo_de(X,Y) :- tiene_sintoma(X,Z),sintoma_de(Z,Y).

