# Escreva um programa que leia três números reais.
# Em seguida mostre na tela se eles formam um triângulo
# ou não. Caso formem, mostre também o tipo de triângulo
# equilátero, isóceles ou escaleno.

a = float(input("Digite o Valor do Lado A: "))
b = float(input("Digite o Valor do Lado B: "))
c = float(input("Digite o Valor do Lado C: "))

if a + b > c and a + c > b and b + c > a:
    print(f"\nOs valores {a}, {b}, {c} Formam um Triângulo: ", end="")
    if a == b == c: # and b == c:
        print("Equilátero")
    elif a != b and a != c and b != c:
        print("Escaleno")
    else:
        print("Isóceles")
else:
    print(f"\nOs valores {a}, {b}, {c} Não Formam um Triângulo")

print("\n\nFim do Programa")
