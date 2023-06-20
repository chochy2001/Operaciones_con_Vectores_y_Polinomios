% Declara las predicados que serán dispersos en el código, es decir, sus cláusulas se pueden definir en cualquier orden.
:- discontiguous puede/2.
:- discontiguous no_puede/2.
:- discontiguous tiene/2.
:- discontiguous es/2.
:- discontiguous es_un/2.

% Define que un animal puede respirar, tiene piel y puede moverse.
puede(animal, respirar).
tiene(animal, piel).
puede(animal, moverse).

% Define que un pez puede nadar y tiene aletas.
puede(pez, nadar).
tiene(pez, aletas).

% Define que un ave puede volar y tiene alas y plumas.
puede(ave, volar).
tiene(ave, alas).
tiene(ave, plumas).

% Define que un ave y un pez son tipos de animales.
es_un(ave, animal).
es_un(pez, animal).

% Define que una trucha es un tipo de pez, vive en agua dulce y tiene escamas.
es_un(trucha, pez).
es(trucha, agua_dulce).
tiene(trucha, escamas).

% Define que un salmon es un tipo de pez, vive en agua salada y tiene escamas.
es_un(salmon, pez).
es(salmon, agua_salada).
tiene(salmon, escamas).

% Define que un avestruz es un tipo de ave, no puede volar y es alto.
es_un(avestruz, ave).
no_puede(avestruz, volar).
es(avestruz, alta).

% Define que un canario es un tipo de ave, puede cantar y es amarillo.
es_un(canario, ave).
puede(canario, cantar).
es(canario, amarillo).

% Estas son reglas de inferencia. Permiten concluir que si X es un tipo de Z y Z puede, no puede, tiene o es Y, entonces X también puede, no puede, tiene o es Y. Adicionalmente, si X es un tipo de Y, entonces X es Y.
puede(X, Y) :- es_un(X, Z), puede(Z, Y), \+ no_puede(X, Y).
no_puede(X, Y) :- es_un(X, Z), no_puede(Z, Y).
tiene(X, Y) :- es_un(X, Z), tiene(Z, Y).
es(X, Y) :- es_un(X, Z), es(Z, Y).
es(X, Y) :- es_un(X, Y).

% Estas reglas permiten consultar los atributos de un objeto. Un atributo puede ser que X puede, no puede, tiene o es Y.
atributo(X, puede(Y)) :- puede(X, Y).
atributo(X, no_puede(Y)) :- no_puede(X, Y).
atributo(X, tiene(Y)) :- tiene(X, Y).
atributo(X, es(Y)) :- es(X, Y).

% Esta es una regla de inferencia que define la transitividad de la relación "es_un". Si X es un tipo de Z y Z es un tipo de Y, entonces X es un tipo de Y.
es_un_transitivo(X, Y) :- es_un(X, Y).
es_un_transitivo(X, Y) :- es_un(X, Z), es_un_transitivo(Z, Y).
