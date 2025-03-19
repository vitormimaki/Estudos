#tabela de fornecedores
import sqlite3

conector = sqlite3.connect('banco.db')
cursor = conector.cursor()

try:
    sql = "drop table fornecedor"
    cursor.execute(sql)
except sqlite3.OperationalError:
    pass

# criando a tabela de fornecedores (somente se ela não existir)
sql = """
    CREATE TABLE fornecedor(
        cod_interno INTEGER PRIMARY KEY,
        razao_social STRING,
        nome STRING,
        cnpj INTEGER,
        telefone_central INTEGER)
    """
cursor.execute(sql)


Fornecedor = 5 * ['']
Fornecedor[0] = int(input('Digite o CODIGO do fornecedor: '))
Fornecedor[1] = input('Digite a RAZÃO SOCIAL: ')
Fornecedor[2] = input('Digite o NOME: ')
Fornecedor[3] = int(input('Digite o CNPJ: '))
Fornecedor[4] = int(input('Digite o TELEFONE: '))


# inserindo os dados no banco
sql = """
    INSERT INTO fornecedor(cod_interno, razao_social, nome, cnpj, telefone_central)
    VALUES (?, ?, ?, ?, ?)
    """
cursor.execute(sql, Fornecedor)
conector.commit()

cursor.close()
conector.close()

print("\n\nFim do Programa")
