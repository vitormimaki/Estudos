import sqlite3

def ExibeDados(Dados):
    strSaida = "{:2} {:6} {:32} {:5} {:>6}"
    print(strSaida.format('id', 'Matr.', 'Nome Aluno', 'Idade', 'Peso'))
    for d in Dados:
        print(strSaida.format(d[0], d[1], d[2], d[3], d[4]))



conector = sqlite3.connect("academia.db")
cursor = conector.cursor()

print("Consulta ao banco de dados academia.db")
print("1.")
print("Alunos em ordem natural")
sql = "select _id, MATRICULA, NOMEALU, IDADE, PESO from alunos"
cursor.execute(sql)
alunos = cursor.fetchall()
ExibeDados(alunos)
print("---\n")

print("2.")
print("Alunos em ordem alfabética")
sql = "select _id, MATRICULA, NOMEALU, IDADE, PESO from alunos order by NOMEALU"
cursor.execute(sql)
alunos = cursor.fetchall()
ExibeDados(alunos)
print("---\n")

print("3.")
print("Alunos em ordem decrescente de idade")
sql = "select _id, MATRICULA, NOMEALU, IDADE, PESO from alunos order by IDADE desc"
cursor.execute(sql)
alunos = cursor.fetchall()
ExibeDados(alunos)
print("---\n")

cursor.close()
conector.close()


print("\n\nFim do Programa")
