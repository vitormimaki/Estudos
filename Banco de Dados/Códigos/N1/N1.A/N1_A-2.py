# nome: Eduardo Vollet de Souza
# nome: Arthur de Queiroz
# nome: Vitor Aurélio Saccone Mimaki

arq = open('vendas.txt', 'r')
s = arq.readline().rstrip()
Lista = []
total_geral = 0

mensagem = 'código = {} - quantidade = {} - preço unitario {} –> Total por produto = {:.2f}'

while s != '':
    s = s.split(';')  # split é usado para dividir uma linha por palavras ou por símbolos determinados
    d = {'código': int(s[0]), 'quantidade': int(s[1]), 'preço unitario': float(s[2])}
    Lista.append(d)
    s = arq.readline().rstrip()

for valor in Lista:
    total_produto = valor['quantidade'] * valor['preço unitario']
    total_geral = total_geral + total_produto
    print(mensagem.format(valor['código'], valor['quantidade'], valor['preço unitario'], total_produto))

print(f'Totoal geral de vendas: {total_geral}')

arq.close()

