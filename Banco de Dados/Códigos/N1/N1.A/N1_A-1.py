# nome: Eduardo Vollet de Souza
# nome: Arthur de Queiroz
# nome: Vitor Aurélio Saccone Mimaki


arq = open('entrada-N1_A-1.txt', 'r')
s = arq.readline().rstrip() # O s é a linha que ele irá ler do txt
Lista = []

mensagem = 'x = {} e y = {} –> soma = {:.2f} e multiplicação = {:.2f}'

while s != '':
    s = s.split(';') #slipt é usado para dividir uma linha por palavras ou por simbolos determinados
    d = {'x': float(s[0]), 'y': float(s[1])} # 
    Lista.append( d )
    s = arq.readline().rstrip()

for valor in Lista:
    soma = valor['x'] + valor['y']
    mult = valor['x'] * valor['y']
    print(mensagem.format(valor['x'], valor['y'], soma, mult))

arq.close()