codigo = {'A':"90", 'B':"91", 'C':"92", 'D':"93", 'E':"94",
        'F':"80", 'G':"81", 'H':"82", 'I':"83", 'J':"83",
        'K':"84", 'L':"70", 'M':"71", 'N':"72", 'O':"73",
        'P':"74", 'Q':"60", 'R':"61", 'S':"62", 'T':"63",
        'U':"64", 'V':"50", 'W':"51", 'X':"52", 'Y':"53",
        'Z':"54"}#MATRIZ DE CODIGO

class Cripto:

    def norma(cadena):#NORMALIZACION DE CADENAS
        '''
        Este metodo lo que realiza es un tratamiento a las cadenas ingresadas por el usuario, quita
        espacios y letras minusculas, no admite numeros.

        EJEMPLO: Luisa Fernanda, norma = LUISAFERNANDA
        '''
        cadena = cadena.upper()#Pasa todo a mayúsculas
        cadena = cadena.replace(" ", "")#Elimina espacios
        return cadena#Retorna la cadena normalizada

    def codificacion(cadenaN):#CODIFICACION DE CADENAS
        '''
        Este metodo normaliza una cadena para posteriormente pasarla a una lista y asi iterar y comparar
        con la codificación establecida

        EJEMPLO: 
           1. LUISAFERNANDA
           2. ['L','U','I','S','A','F','E','R','N','A','N','D','A']
           3. L == A
                .
                .
                .
              A == A
                resul = 7090
        '''
        cadenaN = Cripto.norma(cadenaN)#Normalización de cadena
        resul=""
        lisAux = list(cadenaN)
        for i in lisAux:#Iteramos la cadena inicial
            for key in codigo:
                if key == i:#Comparamos la cadena introducida con la codificacion
                    resul = resul+codigo[i]#Almacenamos el contenido de la llave del diccionario
                    break
                
        return resul#Regresamos la cadena codificada

    def codiInversa(cadenaN):
        '''
        Este metodo pide una cadena codificada para devolver su significado

        EJEMPLO:
            Ingresa: '70648362908094617290729390'
            Pasamos a lista: ['70', '64'. '83'...]
                '70' == '70'
                    resul = LUI...
        '''
        resul=""
        aux1=""
        aux2=[]
        aux3=[]
        k=2
        lisAux = list(cadenaN)
        while k < len(lisAux)+2:
            aux1 = aux1 + lisAux[k-2]+lisAux[k-1]
            aux2.append(aux1)
            aux1=""
            k+=2

        for i in aux2:
            for clave in codigo:
                if codigo[clave] == i:
                    resul=resul+clave
                    break
            
        '''
        Esta parte del codigo verifica la inclusion de la letra J/I,
        simplimente busca su existencia para mostrar dos posibles resultados

        EJEMPLO:
            LUISAFERNANDA
            ['L','U','I','S','A',...]
            aux3 = LUJSAFERNANDA
            resul = LUISAFERNANDA
        '''
        aux3=list(resul)
        z=0
        for z in range(len(aux3)):
            if aux3[z] == 'I':#Se intercambia la J por la I por otro posble resultado
                aux3[z] = 'J'
        aux3="".join(aux3)

        if resul == aux3:#Compramos si hubo o no intercambio
            print("El mensaje es: "+resul)#Sino hay, pasamos un solo resultado
        else:
            print("\nEl mensaje puede ser: " + resul + " o " + aux3)#SI lo hay, psasmos los posibles resultados


opcion = 0
while opcion != 3 and opcion < 3:
    menu = "\nCODIFICACION DE MENSAJES\n 1.CODIFICA TU MENSAJE\n 2.REVELA TU MENSAJE\n 3.SALIR"
    print(menu)
    opcion = int(input("\nIngresa el numero de la operacion que quieras realizar: \n"))

    if opcion == 1:
        palabra = input("Ingresa tu palabra a codificar\n") 
        palabra = Cripto.codificacion(palabra)
        print("\nMensaje codificado: "+palabra)

    elif opcion == 2:
        codi = input("Ingresa tu codigo a revelar\n") 
        Cripto.codiInversa(codi)

    else:
        print("\nMuchas gracias!")

                       