l = []
for i in range(10):
    l.append(int(input(f"Insira o {i+1}º Valor:")))
a = l[:]
a.reverse()
print(a)
