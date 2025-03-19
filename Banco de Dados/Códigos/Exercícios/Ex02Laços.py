resp = 1
somaP = 0
somaN = 0
while resp != 0:
    resp = int(input("Insira um Valor: "))
    if resp > 0:
        somaP += resp
    else:
        somaN += resp
print(f"Total dos Positivos: {somaP}")
print(f"Total dos Negativos: {somaN}")
