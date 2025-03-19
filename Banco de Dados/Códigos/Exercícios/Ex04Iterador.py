l = []
for i in range(10):
    l.append(int(input(f"Insira o {i+1}º Valor:")))
a = []
for i in range(10):
    a.append(int(input(f"Insira o {i+1}º Valor:")))
b = l
b.extend(a)
print(b)
