'''
Elaborado por:
Rodríguez Larios Alejandro
Salgado Miranda Jorge
'''

class BellmanFordmore:
    def __init__(self):
        '''Inicializamos los atributos del objeto para 
            tomar en cuenta la distancia tentativa,
            nodos visitados y ruta final.'''
        self.dist_tentativa = {}  # Almacena las distancias tentativas de cada nodo
        self.visitados = set()  # Almacena los nodos visitados
        self.rutaFinal = []  # Almacena la ruta final

    def inicializacionConjuntos(self, grafo, inicio):
        ''''Inicializar los conjuntos para el algoritmo con distancias iniciales'''
        for nodo in grafo:
            self.dist_tentativa[nodo] = float("inf")  # Establece la distancia tentativa para cada nodo como infinito
        self.dist_tentativa[inicio] = 0  # Establece la distancia tentativa para el nodo inicial como 0

    def recorrido(self, grafo, inicio):
        self.inicializacionConjuntos(grafo, inicio)  # Inicializar los conjuntos con distancias iniciales
        for i in range(len(grafo) - 1):
            # Actualizar las distancias tentativas
            for nodo in grafo:
                for vecinos, costos in grafo[nodo].items():
                    if self.dist_tentativa[nodo] + costos < self.dist_tentativa[vecinos]:
                        self.dist_tentativa[vecinos] = self.dist_tentativa[nodo] + costos

        # Comprobación de ciclos negativos
        for nodo in grafo:
            for vecinos, costos in grafo[nodo].items():
                if self.dist_tentativa[nodo] + costos < self.dist_tentativa[vecinos]:
                    raise ValueError("ERROR, ciclo de pesos negativos detectados")

        # Ordena las distancias y guarda la ruta final
        ruta = dict(sorted(self.dist_tentativa.items(), key=lambda item: item[1]))
        for nodo in ruta.keys():
            self.rutaFinal.append(nodo)


#Unicamente hay que descomentar el diccionario "grafo" para probar las diferentes graficas

grafo = {
    'a': {'b': 4, 'c': 3},
    'b': {'d': 5},
    'c': {'b': 2, 'd': 3, 'e': 6},
    'd': {'f': 5, 'e': 1},
    'e': {'g': 5},
    'g': {'z': 4},
    'f': {'g': 2, 'z': 7},
    'z': {}
}

'''graph = {
    'A': {'B': 5, 'C': 2},
    'B': {'A': 5, 'C': 1, 'D': 3},
    'C': {'A': 2, 'B': 1, 'D': 2},
    'D': {'B': 3, 'C': 2, 'E': 4},
    'E': {'D': 4}
}'''

'''graph = {
    1: {2: 7, 6: 14, 3: 9},
    2: {1: 7, 3: 10, 4: 15},
    3: {2: 10, 1: 9, 6: 0, 4: 11},
    4: {2: 15, 3: 11, 5: 6},
    5: {6: 9, 4: 6},
    6: {1: 14, 3: 0, 5: 9}
}'''

bell = BellmanFordmore()
bell.recorrido(grafo, 'a')
print(bell.dist_tentativa)  # Imprimir las distancias provisionales
print(bell.rutaFinal)  # Imprimir la ruta final
