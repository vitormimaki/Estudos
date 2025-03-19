#tabela de clientes
import sqlite3

conector = sqlite3.connect('banco.db')
cursor = conector.cursor()

try:
    sql = "drop table clientes"
    cursor.execute(sql)
except sqlite3.OperationalError:
    pass

# criando a tabela de clientes (somente se ela não existir)
sql = """
    CREATE TABLE clientes(
        _idCliente INTEGER PRIMARY KEY AUTOINCREMENT,
        nome STRING,
        rg INTEGER,
        cpf INTEGER,
        endereco STRING,
        email STRING,
        fixo INTEGER,
        celular INTEGER)
    """
cursor.execute(sql)

Cliente = 7 * ['']
Cliente[0] = input('Digite o NOME do cliente: ')
Cliente[1] = int(input('Digite o RG do cliente: '))
Cliente[2] = int(input('Digite o CPF do cliente: '))
Cliente[3] = input('Digite o ENDEREÇO do cliente: ')
Cliente[4] = input('Digite o EMAIL do cliente: ')
Cliente[5] = int(input('Digite o telefone FIXO do cliente: '))
Cliente[6] = int(input('Digite o telefone CELULAR do cliente: '))

# inserindo os dados no banco
sql = """
    INSERT INTO clientes(nome, rg, cpf, endereco, email, fixo, celular)
    VALUES (?, ?, ?, ?, ?, ?, ?)
    """
cursor.execute(sql, Cliente)

conector.commit()
cursor.close()
conector.close()

print("\n\nFim do Programa")
