from pyswip import Prolog

prolog = Prolog()

prolog.consult("ejem.pl")

list_results = list(prolog.query("tiene(X,alas)."))
for result in list_results:
    print(result)
