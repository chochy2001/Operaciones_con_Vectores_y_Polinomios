% Atributos de un animal
puede(animal, respirar).
tiene(animal, piel).
puede(animal, moverse).

% Atributos de un ave
puede(ave, volar).
tiene(ave, alas).
tiene(ave, plumas).

% Definir que un ave y un pez son animales
es_un(ave, animal).
es_un(pez, animal).

% Atributos específicos de avestruz y canario
es_un(avestruz, ave).
no_puede(avestruz, volar).
es(avestruz, alta).

es_un(canario, ave).
puede(canario, cantar).
es(canario, amarillo).

% Reglas para propagar los atributos a través de la relación "es_un"
puede(X, Y) :- es_un(X, Z), puede(Z, Y), \+ no_puede(X, Y).
tiene(X, Y) :- es_un(X, Z), tiene(Z, Y).
es(X, Y) :- es_un(X, Z), es(Z, Y).
