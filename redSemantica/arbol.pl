%Árbol genealógico

% Hechos
hombre(pedro).
hombre(paco).
hombre(juan).
hombre(jose).
hombre(jorge).
hombre(larios).
mujer(luz).
mujer(maria).
mujer(ana).
mujer(rosa).
progenitor(pedro, paco).
progenitor(pedro, maria).
progenitor(luz, paco).
progenitor(luz, maria).
progenitor(juan, pedro).
progenitor(ana, pedro).
progenitor(jose, luz).
progenitor(rosa, luz).
progenitor(rosa,jorge).
progenitor(jorge,larios).
progenitor(jose,jorge).


% Reglas

madre(X,Y) :- mujer(X), progenitor(X,Y).
padre(X,Y) :- hombre(X), progenitor(X,Y).

abuela(X,Y) :- madre(X,Z), progenitor(Z,Y).
abuelo(X,Y) :- padre(X,Z), progenitor(Z,Y).

hijo(X,Y) :- progenitor(Y,X), hombre(X).
hija(X,Y) :- progenitor(Y,X), mujer(X).

hermano(X,Y) :- progenitor(Z,X), progenitor(Z,Y), hombre(X), X\=Y.
hermana(X,Y) :- progenitor(Z,X), progenitor(Z,Y), mujer(X), X\=Y.

tio(X,Y) :- hermano(X,Z), progenitor(Z,Y).
tia(X,Y) :- hermana(X,Z), progenitor(Z,Y).

primo(X,Y) :- hombre(X), progenitor(Z,X), (hermano(Z,W); hermana(Z,W)), progenitor(W,Y), X\=Y.
prima(X,Y) :- mujer(X), progenitor(Z,X), (hermano(Z,W); hermana(Z,W)), progenitor(W,Y), X\=Y.
