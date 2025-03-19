l = []
resp = int(input("Insira um Valor: "))
while resp > 0:
    l.append(resp)
    resp = int(input("Insira um Valor: "))
print("Lista: ", end="")
print(l)
