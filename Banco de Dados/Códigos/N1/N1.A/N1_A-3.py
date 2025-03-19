# nome: Eduardo Vollet de Souza
# nome: Arthur de Queiroz
# nome: Vitor Aurélio Saccone Mimaki

arq_e = open('entrada.txt', 'r')
s = arq_e.readline().rstrip()
Lista = []
cont = 0

num = int(input('Qual número deseja pesquisar? '))

while s != '':
    s = s.split(';')  # split é usado para dividir uma linha por palavras ou por símbolos determinados
    d = {'a': int(s[0]), 'b': int(s[1]), 'c': int(s[2]), 'd': float(s[3]), 'e': float(s[4])}
    Lista.append(d)
    s = arq_e.readline().rstrip()

arq_s = open('saida.txt', 'w') 

#if a = x entáo ache só o que tem a 5

for valor in Lista:
    if num == valor['a']:
        linha_correta = f'{valor['a']};{valor['b']};{valor['c']};{valor['d']:.2f};{valor['e']:.2f}'
        arq_s.write(linha_correta)
        arq_s.write('\n')
    cont = cont + 1

print('Arquivo gerado com sucesso!')

arq_e.close()
arq_s.close()
    

