dados = []
arq = open("dados.txt", "r")
#s = arq.readlines() -> Lê o arquivo inteiro
s = arq.readline().rstrip()
while s != "":
    #s = s.rstrip()# -> Tira o \n da direita
    #s = s.lstrip()# -> Tira o \n da esquerda
    #s = s.strip()#  -> Tira o \n de TUDO
    s = s.split(";")
    d = {"x": float(s[0]),
         "y": float(s[1])
         }
    #x = float(s[0])
    #y = float(s[1])
    dados.append(d)
    s = arq.readline().rstrip()

out = "x = {} e y = {} -> soma = {:.2f} e multiplicação = {:.2f}"
for item in dados:
    soma = item["x"] + item["y"]
    mult = item["x"] * item["y"]
    print(out.format(item["x"], item["y"], soma, mult))

print(s)
arq.close()

print("\n\nFim do Programa")
