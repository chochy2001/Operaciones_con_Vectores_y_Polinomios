:- discontiguous puede/2.
:- discontiguous no_puede/2.
:- discontiguous tiene/2.
:- discontiguous es/2.
:- discontiguous es_un/2.

% Atributos de un animal
puede(animal, respirar).
tiene(animal, piel).
puede(animal, moverse).

% Atributos de un pez
puede(pez, nadar).
tiene(pez, aletas).

% Atributos de un ave
puede(ave, volar).
tiene(ave, alas).
tiene(ave, plumas).

% Definir que un ave y un pez son animales
es_un(ave, animal).
es_un(pez, animal).

% Atributos específicos de trucha y salmon
es_un(trucha, pez).
es(trucha, agua_dulce).
tiene(trucha, escamas).

es_un(salmon, pez).
es(salmon, agua_salada).
tiene(salmon, escamas).

% Atributos específicos de avestruz y canario
es_un(avestruz, ave).
no_puede(avestruz, volar).
es(avestruz, alta).

es_un(canario, ave).
puede(canario, cantar).
es(canario, amarillo).

% Reglas para propagar los atributos a través de la relación "es_un"
puede(X, Y) :- es_un(X, Z), puede(Z, Y), \+ no_puede(X, Y).
no_puede(X, Y) :- es_un(X, Z), no_puede(Z, Y).
tiene(X, Y) :- es_un(X, Z), tiene(Z, Y).
es(X, Y) :- es_un(X, Z), es(Z, Y).
es(X, Y) :- es_un(X, Y).

% Reglas recursivas para consultar los atributos de un objeto
atributo(X, puede(Y)) :- puede(X, Y).
atributo(X, no_puede(Y)) :- no_puede(X, Y).
atributo(X, tiene(Y)) :- tiene(X, Y).
atributo(X, es(Y)) :- es(X, Y).

% Regla recursiva para la relación "es_un"
es_un_transitivo(X, Y) :- es_un(X, Y).
es_un_transitivo(X, Y) :- es_un(X, Z), es_un_transitivo(Z, Y).
