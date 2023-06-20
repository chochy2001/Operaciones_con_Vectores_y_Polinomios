from pyswip import Prolog

prolog = Prolog()

prolog.consult("animales.pl")

consulta = "puede(avestruz,Y)."

list_results = list(prolog.query(consulta))
list_results_bool = bool(list(prolog.query(consulta)))
for result in list_results:
    print(result)

print(list_results_bool)

