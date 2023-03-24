'''
    Elaborado por:
       Cortés Alvarado Iván Daniel
       Rodríguez Larios Alejandro
       Salgado Miranda Jorge

'''

import math as m#Se importa la biblioteca math para realizar redobdeos hacia abajo

class PuntoFlotante:#Nombre de nuestra clase principal

    def binAdecimal(numBin):
        '''
        Este método realiza la conversión de binario a decimal.
         1. Separamos el exponente y la mantisa
         01000001100111100010000000000000
         lisAux1 = 10000011
         lisAux2 = 00111100010000000000000

         2.Obtenemos el exponente
         exponente = 131 - 127

         3. Obtenemos la mantisa a partir de la iteración del bloque de 1's y 0's
         si listaEjem[2] == 1
            entonces 
               mantisa = mantisa + 1/2^j+1
         Al final sumamos el 1 implicito

         4. Multiplicamos nuestros tres elementos
         0/1 X 2^4 X mantisa = 19.765625
        '''
        lisAux1 = []
        lisAux2 = []
        exponente = 0
        mantisa = 0
        
        lisBin = list(numBin)
        k = 1
        while k < len(lisBin):
            if k < 9:
                lisAux1.append(lisBin[k])
            else:
                lisAux2.append(lisBin[k])
            k+=1
        
        i = len(lisAux1)-1
        while i > -1:
            if lisAux1[i] == '1':
                exponente += pow(2, 7-i)
            i-=1
        exponente = exponente-127

        j = 0
        while j < len(lisAux2):
            if lisAux2[j] == '1':
                mantisa += 1/pow(2,j+1)
            j+=1
        mantisa = mantisa+1

        decimal = pow(2,exponente)*mantisa

        if lisBin[0] == '1':
            print("-" + decimal)
        else:
            print(decimal)


    def decimalAbin(numFlot):
        '''
         Este método realiza la conversión de decimal a binario.
         1. Separamos la parte entera de la decimal
         19.765625
         si num[i] es diferente a '.'
          entonces se almacena en una variable 
           1+9 = 19 (tomando en cuenta el tipo de dato str)
         Para la parte decimal es la misma solo que de manera inversa

         2.Obtenemos el exponente
         exponente = tamEntero-1 + 127

         3. Unimos todos los binarios tipo str y resulta el numero binario
         01000001100111100010000000000000

        '''
        lisDecimal = list(str(numFlot))
        entero = ""
        decimal = ""
        binEntero = ""
        binDecimal = ""
        resul=""
        for i in lisDecimal:
            if i != '.':
                entero = entero+i
            else:
                break
        
        i = len(lisDecimal)-1
        while i > -1:
            if lisDecimal[i] != '.':
                decimal =lisDecimal[i]+decimal
            elif lisDecimal[i] == '.':
                break
            i-=1
        
        entero = int(entero)
        decimal = float("0." +decimal)

        binEntero = PuntoFlotante.enterosAbinarios(entero)

        while decimal >= 0.05 or decimal >= 1.05:#IMPORTANTE: Esta condición se ideó por acomodo, puesto que algunos decimales no llegar al 0
            #la idea es "truncar" los decimales que ocupan espacios de mas
            '''
            Multiplicamos por 2 los decimales hasta llegar a un unico entero
                La misma parte entera asigna los 0's y 1's necesarios para obtener el binario del numero
            '''
            binDecimal = binDecimal + str(int(decimal*2))
            decimal = decimal*2 - int(decimal*2)
            #decimal = round(decimal,2)#esto de igual manera funciona para no realizar operaciones de mas con decimales "basura"

        exponente = len(binEntero)-1 + 127

        exponente = PuntoFlotante.enterosAbinarios(exponente)

        if numFlot > 0:
            resul = "0" + exponente + binEntero[1:len(binEntero)] + binDecimal
        else:
            resul = "1" + exponente + binEntero[1:len(binEntero)] + binDecimal
        

        if len(resul) == 32:
            print(resul)
        else:
            while len(resul) < 32:
                resul = resul + '0'
            print(resul)



    def enterosAbinarios(entero):
        '''
        Aqui divimos entre 2 hasta llegar a 0
        '''
        binEntero=""
        while entero >= 1:
            binEntero = binEntero + str(entero%2)
            entero = m.floor(entero/2)
        return ''.join(reversed(binEntero))#invertimos la cadena devuelta 




opcion = 0
while opcion != 3 and opcion < 3:
    menu = "\nNOTACION PUNTO FLOTANTE\n 1.PASA DE BINARIO A DECIMAL\n 2.PASA DE DECIMAL A BINARIO\n 3.SALIR"
    print(menu)
    opcion = int(input("\nIngresa el numero de la operacion que quieras realizar: \n"))

    if opcion == 1:
        binario = input("Ingresa tu numero binario a transformar\n") 
        PuntoFlotante.binAdecimal(binario)
       

    elif opcion == 2:
        num = float(input("Ingresa tu numero decimal a transformar\n"))
        PuntoFlotante.decimalAbin(num)

    else:
        print("\nMuchas gracias!")