Programa de Operaciones con Vectores y Polinomios
Este programa se dedica a hacer operaciones con vectores, como suma, resta, multiplicación, producto por un escalar, norma y ángulo entre dos vectores. Además, también realiza operaciones con polinomios de grado n, como valor en un punto, suma, resta, multiplicación, derivada e integral.

Operaciones con Vectores
Suma de Vectores
La suma de dos vectores se realiza componente por componente, es decir, si tenemos dos vectores A y B, su suma C se obtiene de la siguiente manera:

C = (A1 + B1, A2 + B2, ..., An + Bn)

Resta de Vectores
La resta de dos vectores se realiza también componente por componente, es decir, si tenemos dos vectores A y B, su resta C se obtiene de la siguiente manera:

C = (A1 - B1, A2 - B2, ..., An - Bn)

Multiplicación de Vectores por un Escalar
La multiplicación de un vector por un escalar se realiza multiplicando cada componente del vector por el escalar, es decir, si tenemos un vector A y un escalar k, su producto D se obtiene de la siguiente manera:

D = (k * A1, k * A2, ..., k * An)

Norma de un Vector
La norma de un vector se define como la raíz cuadrada de la suma de los cuadrados de sus componentes, es decir, si tenemos un vector A, su norma se obtiene de la siguiente manera:

|A| = sqrt(A1^2 + A2^2 + ... + An^2)

Ángulo entre Dos Vectores
El ángulo entre dos vectores se define como el coseno inverso del producto punto entre los dos vectores dividido por el producto de sus normas, es decir, si tenemos dos vectores A y B, su ángulo se obtiene de la siguiente manera:

cos(theta) = (A * B) / (|A| * |B|)

theta = acos(cos(theta))

Operaciones con Polinomios
Valor en un Punto
El valor de un polinomio en un punto dado se obtiene evaluando el polinomio en ese punto, es decir, si tenemos un polinomio P de grado n, su valor en un punto x se obtiene de la siguiente manera:

P(x) = a0 + a1x + a2x^2 + ... + an*x^n

Suma de Polinomios
La suma de dos polinomios se realiza sumando los coeficientes de los términos de igual grado, es decir, si tenemos dos polinomios P y Q de grado n, su suma R se obtiene de la siguiente manera:

R(x) = P(x) + Q(x) = (a0 + b0) + (a1 + b1)*x + (a2 + b2)*x^2 + ... + (an + bn)*x^n

Resta de Polinomios
La resta de dos polinomios se realiza restando los coeficientes de los términos de igual grado, es decir, si tenemos dos polinomios P y Q de grado n, su resta R se obtiene de la siguiente manera:

R(x) = P(x) - Q(x) = (a0 - b0) + (a1 - b1)*x + (a2 - b2)*x^2 + ... + (an - bn)*x^n

Multiplicación de Polinomios
La multiplicación de dos polinomios se realiza distribuyendo cada término del primer polinomio sobre cada término del segundo polinomio, y luego se suman los términos de igual grado, es decir, si tenemos dos polinomios P y Q de grado n, su producto R se obtiene de la siguiente manera:

R(x) = P(x) * Q(x) = c0 + c1x + c2x^2 + ... + cn*x^n

donde:

c0 = a0*b0

c1 = a0b1 + a1b0

c2 = a0b2 + a1b1 + a2*b0

...

cn = anb0 + an-1b1 + an-2b2 + ... + a1bn-1 + a0*bn

Derivada de un Polinomio
La derivada de un polinomio se obtiene tomando la derivada de cada término y sumándolos, es decir, si tenemos un polinomio P de grado n, su derivada P' se obtiene de la siguiente manera:

P'(x) = a1 + 2a2x + 3a3x^2 + ... + nanx^(n-1)

Integral de un Polinomio
La integral de un polinomio se obtiene integrando cada término y sumándolos, es decir, si tenemos un polinomio P de grado n, su integral ∫P(x)dx se obtiene de la siguiente manera:

∫P(x)dx = C + a0*x + (1/2)a1x^2 + (1/3)a2x^3 + ... + (1/n+1)anx^(n+1)

donde C es la constante de integración.

Uso del Programa
Para utilizar este programa, simplemente descarga el código fuente desde este repositorio de GitHub y compila el programa. Una vez compilado, ejecuta el programa y sigue las instrucciones en pantalla para realizar las operaciones deseadas.

Conclusión
Este programa es una herramienta útil para realizar operaciones con vectores y polinomios de grado n. Las operaciones con vectores son fundamentales en matemáticas y física, mientras que las operaciones con polinomios son importantes en muchas áreas de la ciencia y la ingeniería. Este programa puede ser utilizado por estudiantes, profesores, investigadores y profesionales en una variedad de campos para realizar cálculos precisos y eficientes.
