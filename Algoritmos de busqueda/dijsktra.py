'''
Elaborado por:
Rodríguez Larios Alejandro
Salgado Miranda Jorge
'''

class Dijkstra:
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
        while len(self.visitados) < len(grafo):
            # Visita el nodo no visitado con la distancia tentativa mínima
            min_dist = float('inf')
            min_nodo = None
            for nodo in grafo:
                if nodo not in self.visitados and self.dist_tentativa[nodo] < min_dist:#Preguntamos por la distancia minima y vamos buscando a los vecinos
                    min_dist = self.dist_tentativa[nodo]
                    min_nodo = nodo
            self.visitados.add(min_nodo)  # Marcar el nodo como visitado

            # Actualizar las distancias tentativas de los vecinos del nodo actual
            for vecinos, costos in grafo[min_nodo].items():
                sobreEscritura = self.dist_tentativa[min_nodo] + costos
                if sobreEscritura < self.dist_tentativa[vecinos]:#si hay un costo menor se intercambia
                    self.dist_tentativa[vecinos] = sobreEscritura

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

dijkstra = Dijkstra()
dijkstra.recorrido(grafo, 'a')
print(dijkstra.dist_tentativa)  # Imprimir las distancias provisionales
print(dijkstra.rutaFinal)  # Imprimir la ruta final






      
      

        



        

    



        


