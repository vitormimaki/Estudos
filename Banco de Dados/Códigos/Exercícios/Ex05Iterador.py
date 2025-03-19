nA = int(input("Insira o Tamanho da Lista A: "))
nB = int(input("Insira o Tamanho da Lista B: "))
A = []
B = []
for i in range(nA):
    A.append(int(input(f"Insira o {i+1}° Valor: ")))
for i in range(nB):
    B.append(int(input(f"Insira o {i+1}° Valor: ")))
nR = nA + nB
R = A + B
print(f"A Lista:  {R} Possui Tamanho: {nR}")
