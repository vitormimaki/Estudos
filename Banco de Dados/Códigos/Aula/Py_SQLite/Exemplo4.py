import sqlite3

conector = sqlite3.connect("academia.db")

cursor = conector.cursor()
sql = "alter table alunos add ATIVO integer"
cursor.execute(sql)
sql = "update alunos set ATIVO = 1"
cursor.execute(sql)
sql = "update alunos set ATIVO = 0 where MATRICULA < ?"
param = [121000]
cursor.execute(sql, param)

conector.commit()   # o commit da conexão é quem efetivamente salva os dados no BD
cursor.close()
conector.close()


print("\n\nFim do Programa")
