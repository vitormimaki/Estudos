import sqlite3
# Ao fazer a primeira conexão, se o arquivo academia.db não existir será criado
conector = sqlite3.connect("academia.db")

# cria um cursor para executar os comandos sql
cursor = conector.cursor()

# Se a tabela alunos existe, então elimine-a
# Devemos usar try-except pois quando for a primeira execução a tabela não existirá
#   e não poderá ser excluída. O try-except evita que ocorra erro.
try:
    sql = "drop table alunos"
    cursor.execute(sql)
    sql = "drop table professores"
    cursor.execute(sql)
except sqlite3.OperationalError:   
   pass  # na prática, se o erro ocorrer não queremos fazer nada, então colocamos o pass

# cria a tabela alunos
sql = """
  create table alunos (
    _id INTEGER PRIMARY KEY AUTOINCREMENT,
    MATRICULA INTEGER,
    NOMEALU STRING,
    IDADE INTEGER,
    PESO NUMERIC)
  """
cursor.execute(sql)

# insere dados na tabela alunos
sql = """
  insert into alunos (MATRICULA, NOMEALU, IDADE, PESO)
  values (120915, 'Eliane de Castro Alencar Ortega', 37, 63.9)
"""
cursor.execute(sql)
sql = """
  insert into alunos (MATRICULA, NOMEALU, IDADE, PESO)
  values (120916, 'Mário Júlio Ortega', 41, 91.4)
"""
cursor.execute(sql)
sql = """
  insert into alunos (MATRICULA, NOMEALU, IDADE, PESO)
  values (121018, 'Pietro Bonfiglio Antunes', 46, 87.3)
"""
cursor.execute(sql)
sql = """
  insert into alunos (MATRICULA, NOMEALU, IDADE, PESO)
  values (121033, 'Maria Alice Mendonça', 23, 67.2)
"""
cursor.execute(sql)
sql = """
  insert into alunos (MATRICULA, NOMEALU, IDADE, PESO)
  values (121048, 'Flávio Mendonça', 25, 84.3)
"""
cursor.execute(sql)
sql = """
  insert into alunos (MATRICULA, NOMEALU, IDADE, PESO)
  values (121061, 'João Carlos Fernandes', 53, 117.9)
"""
cursor.execute(sql)


sql = """
  CREATE TABLE professores (
    _id           INTEGER PRIMARY KEY AUTOINCREMENT,
    NOMEPROF      STRING,
    ESPECIALIDADE STRING)
  """
cursor.execute(sql)
sql = """
  insert into professores (NOMEPROF, ESPECIALIDADE)
  values ('Juliana Almeida', 'Pilates')
"""
cursor.execute(sql)
sql = """
  insert into professores (NOMEPROF, ESPECIALIDADE)
  values ('Antonio Almeida', 'Natação')
"""
cursor.execute(sql)


conector.commit()   # o commit da conexão é quem efetivamente salva os dados no BD
cursor.close()
conector.close()


print("\n\nFim do Programa")
