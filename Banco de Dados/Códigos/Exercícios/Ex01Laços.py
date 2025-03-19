n = int(input("Insira a Quantidade de Termos da PG: "))
p = int(input("Insira o Primeiro Termo da PG: "))
r = int(input("Insira a Razão da PG: "))

i = 0
while i < n:
    print(f"{p}", end=" ")
    p *= r
    i += 1
