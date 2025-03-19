l = []
resp = int(input("Insira um Valor: "))
while resp > 0:
    l.append(resp)
    resp = int(input("Insira um Valor: "))
print("Lista:")
i = 0
for i in range(len(l)):
    print(f"Index {i} = {l[i]}")
