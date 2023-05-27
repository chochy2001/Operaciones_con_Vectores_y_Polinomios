def evalua(fp, epa):
    epa['T'] = True  #Clave 1 del diccionario
    epa['F'] = False #Clave 2 del diccionario 
    
    #Diccionarios de operadores binarios y unarios
    dic_o_bin = {'|':' or ', '&':' and ', '=>': ' '}
    dic_o_una = {'!':' not '}
    
    #Método que permite separar la expresión lógica
    data = fp.split()
    
    def eval_expresion(data):
        #Pilas de operadores y valores
        ops, val = [], []
        
        while len(data) > 0:
            e = data.pop(0)
            if e == '(':
                val.append(eval_expresion(data))
            elif (e in dic_o_una) or (e in dic_o_bin):
                ops.append(e)
            elif e == ')':
                if not ops:
                    return val[0]

                op, va= ops.pop(), val.pop()
                if op in dic_o_una:
                    va = eval(dic_o_una[op] + str(va))
                elif op == '=>':
                    va = eval("not " + str(val.pop()) + ' or ' + str(va))
                else: 
                    va2 = val.pop()
                    va = eval(str(va2) + dic_o_bin[op] + str(va))
                val.append(va)
            else:
                val.append(epa[e])
        return val[0]

    return eval_expresion(data)

# Ciclo for en el que se evalua una expresión lógica
for p in {True,False}:
    for q in {True,False}:
        for r in {True,False}:
            # Expresión lógica a evaluar 
            #print(evalua('( ( p => q ) => ( ( p | r ) => ( q | r ) ) )',{'p': p, 'q': q, 'r': r}) == False)
            
            # Segunda expresión lógica a evaluar
            #print(evalua('( p & ( q => r ) )',{'p': p, 'q': q, 'r': r}) == (p and (not q or r)))
            
            # Tercera expresión lógica a evaluar
            print(evalua('( ( p & q ) => ( r | ! r ) )',{'p': p, 'q': q, 'r': r}) == True)
           
#Pruebas que permiten evaluar distintas expresiones lógicas proposicionales.
print("***********TDD******************")
print(evalua('( p | q )',{'p':False,'q':True}) == True)
print(evalua('( p & q )',{'p':False,'q':True}) == False)
print(evalua('( ! p )',{'p':False,'q':True}) == True)
print(evalua('( p => q )',{'p':True,'q':True}) == True)
print(evalua('( ! T )',{}) == False)
print(evalua('( ! F )',{}) == True)
print(evalua('F',{}) == False)
print(evalua('T',{}) == True)
