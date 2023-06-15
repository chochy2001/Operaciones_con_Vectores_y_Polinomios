'''
    Recibe k muestras (bidimensionales) y determina las
    funciones discriminantes de las k clases para
    un un clasificador estadístico a priori.
    En el programa se debe implementar el cálculo de la
    matriz de covarianzas; para el resto
    (inversa y función discriminante con las componentes del
    vector genérico X), se puede utilizar alguna función
    propia del lenguaje elegido.
'''

# Importando las bibliotecas necesarias
import numpy as np
from scipy.stats import multivariate_normal


# Función para calcular la media de un conjunto de muestras
def compute_mean_manual(W):
    W_array = np.array(W)  # Convertir lista de tuplas en array numpy
    W_array = np.mean(W_array, axis=0)  # Es axis = 0 por que si es diferente a 0 como 1,
    # entonces saca el promedio de cada tupla
    return W_array  # Calcular la media


# Función para calcular la matriz de covarianza de un conjunto de muestras
def compute_covariance_manual(samples):
    # Convertir lista de tuplas en array numpy
    samples_array = np.array(samples)
    # Calcular la media de cada característica
    samples_mean = samples_array.mean(axis=0)
    # Centrar las muestras restando la media
    centered_samples = samples_array - samples_mean
    # Calcular la matriz de covarianza
    covariance_matrix = np.matmul(centered_samples.T,
                                  centered_samples)  # así se saca el cuadrado de los componentes de la matriz
    covariance_matrix /= len(
        samples) - 1  # como empieza de cero por eso se resta 1 y así se saca el promedio para la covarianza
    # (entre el numero de elementos de la muestra). (parte roja en el documento)

    # Añadir un pequeño valor a la diagonal para estabilizar los cálculos
    regularization_value = 1e-6  # se usa para asegurar que la matriz es invertible (tiene inverso)
    stabilized_covariance = covariance_matrix + np.eye(samples_array.shape[1]) * regularization_value
    return stabilized_covariance


# Función para calcular la probabilidad a priori de una clase
def compute_prior(W, total_samples):
    return len(W) / total_samples  # Proporción de muestras que pertenecen a la clase


# Función para calcular la función discriminante de una clase
def compute_discriminant_function(mean, covariance, prior):
    rv = multivariate_normal(mean, covariance)  # Crear distribución normal multivariada con media y covarianza dadas
    return lambda X: np.log(prior) + rv.logpdf(X)  # Función discriminante


# Función para entrenar el clasificador
def train(distributions):
    total_samples = sum(len(W) for W in distributions)  # Total de muestras
    discriminant_functions = []  # Lista para guardar las funciones discriminantes
    for W in distributions:  # Para cada clase
        mean = compute_mean_manual(W)  # Calcular la media
        covariance = compute_covariance_manual(W)  # Calcular la matriz de covarianza
        prior = compute_prior(W, total_samples)  # Calcular la probabilidad a priori
        discriminant_functions.append(
            compute_discriminant_function(mean, covariance, prior))  # Añadir función discriminante a la lista
    return discriminant_functions


# Función para clasificar muestras
def classify_samples(discriminant_functions, samples):
    X = np.array(samples)  # Convertir lista de tuplas en array numpy
    scores = np.array([f(X) for f in discriminant_functions])  # Calcular los scores para cada clase
    return np.argmax(scores, axis=0)  # Devolver la clase con mayor score para cada muestra


# Aquí es donde ingresamos las muestras. Cada muestra es una tupla de dos números.
w1 = [(1, 2), (2, 2), (3, 1), (2, 3), (3, 2)]
w2 = [(8, 10), (9, 8), (9, 9), (8, 9), (7, 9)]
distributions = [w1, w2]  # Lista de clases

# Entrenamos el clasificador
discriminant_functions = train(distributions)

# Clasificamos algunas muestras
samples_to_classify = [(2, 2), (2, 4)]
# Imprimiendo las distribuciones
print(str(distributions) + "\n")

# Entrenando el clasificador
discriminant_functions = train(distributions)

# Imprimiendo las salidas de las funciones discriminantes para cada muestra
for sample in samples_to_classify:
    print(f"Sample {sample} classification scores:")
    for i, function in enumerate(discriminant_functions):
        print(f"Class {i}: {function(np.array(sample))}")

# Clasificando algunas muestras
classification_results = classify_samples(discriminant_functions, samples_to_classify)

# Imprimiendo las clasificaciones
print("Classification results:")
for i, result in enumerate(classification_results):
    print(f"Sample {samples_to_classify[i]} was classified as belonging to class {result}")
