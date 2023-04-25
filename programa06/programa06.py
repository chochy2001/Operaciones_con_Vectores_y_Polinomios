
#Evaluación de expresiones lógicas proposicionales
#Recursividad
#
#
#

#Programa original hecho en clase
"""Función evalua: tiene como parámetro una expresión lógica y un diccionario.
   Esta función permite llevar a cabo la evaluación de la expresión lógica y 
   devolver un resultado."""
def evalua(fp, epa):
    epa['T'] = True  #Clave 1 del diccionario
    epa['F'] = False #Clave 2 del diccionario 
    
    #Método que permite separar la expresión lógica
    data = fp.split()

    #Diccionarios de operadores binarios y unarios
    dic_o_bin = {'|':' or ', '&':' and ', '=>':' '}
    dic_o_una = {'!':' not '}

    #Pilas de operadores y valores
    ops,val=[],[]
    
    #Ciclo for que permite recorrer cada elemento de la expresión lógica e irlo evaluando
    for e in data:
        if e == '(':pass
        elif (e in dic_o_una) or (e in dic_o_bin) : ops.append(e)
        elif e == ')': 
            op,va = ops.pop(),val.pop()
            if op in dic_o_una: va=eval(dic_o_una[op]+str(va))
            elif op == '=>': va = eval("not "+str(val.pop())+' or '+str(va)) 
            else: 
                va2= val.pop()
                print(str(va2)+dic_o_bin[op]+str(va))
                va=eval(str(va2)+dic_o_bin[op]+str(va))
            val.append(va)
        else: val.append(epa[e])
    return val

"""Función tdd: tiene como parámetro una función, una expresión lógica, un 
   diccionario y un resultado."""
def tdd(f,fp,epa,r):
    return f(fp,epa) == r

#Ciclo for en el que se evalua una expresión lógica
for p in {True,False}:
    for q in {True,False}:
        for r in {True,False}:
            #Expresión lógica a evaluar 
            print(tdd(evalua,'( ( p => q ) => ( ( p | r ) => ( q | r ) ) )',{'p': p, 'q': q, 'r': r},[False]))


#Pruebas que permiten evaluar distintas expresiones lógicas proposicionales.
print("***********TDD******************")
print(tdd(evalua,'( p | q )',{'p':False,'q':True},[True]))
print(tdd(evalua,'( p & q )',{'p':False,'q':True},[False]))
print(tdd(evalua,'( ! p )',{'p':False,'q':True},[True]))
print(tdd(evalua,'( p => q )',{'p':True,'q':True},[True]))
print(tdd(evalua,'( ! T )',{},[False]))
print(tdd(evalua,'( ! F )',{},[True]))
print(tdd(evalua,'F',{},[False]))
print(tdd(evalua,'T',{},[True]))

