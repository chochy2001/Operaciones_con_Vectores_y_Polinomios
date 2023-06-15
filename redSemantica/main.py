from pyswip import Prolog

prolog = Prolog()

prolog.consult("ejem.pl")

list_results = list(prolog.query("es(salmon,X)."))
list_results_bool = bool(list(prolog.query("es(salmon,X).")))
for result in list_results:
    print(result)

print(list_results_bool)