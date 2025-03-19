n = int(input("Insira um Valor Inteiro N: "))
i = 0
soma = 0.0
while i < n:
    resp = float(input("Insira um Valor Real: "))
    if resp > 0:
        soma += resp
    i += 1
print(f"A soma é: {soma}")
