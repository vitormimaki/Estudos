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
print("Alunos que pesam mais que 70kg")
sql = """
    select _id, MATRICULA, NOMEALU, IDADE, PESO
    from alunos
    where PESO > ?
    order by NOMEALU
"""
param = [70]
cursor.execute(sql, param)
alunos = cursor.fetchall()
ExibeDados(alunos)
print("---\n")

print("2.")
print("Alunos que tem idade menor que 30 anos")
sql = """
    select _id, MATRICULA, NOMEALU, IDADE, PESO
    from alunos
    where IDADE < ?
    order by NOMEALU
"""
param = [30]
cursor.execute(sql, param)
alunos = cursor.fetchall()
ExibeDados(alunos)
print("---\n")

cursor.close()
conector.close()


print("\n\nFim do Programa")
