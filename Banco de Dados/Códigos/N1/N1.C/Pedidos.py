#tabela de pedidos
import sqlite3

conector = sqlite3.connect('banco.db')
cursor = conector.cursor()

try:
    sql = "drop table pedidos"
    cursor.execute(sql)
except sqlite3.OperationalError:
    pass

# criando a tabela de pedidos (somente se ela não existir)
sql = """
    CREATE TABLE pedidos(
        id_pedido INTEGER PRIMARY KEY AUTOINCREMENT,
        nota_fiscal INTEGER,
        valor_total NUMERIC,
        data DATE,
        pecas STRING,
        id_cliente INTEGER,
        CONSTRAINT fk_id_cliente FOREIGN KEY (id_cliente) REFERENCES clientes(id_cliente)) 
    """
cursor.execute(sql)

Pedido = 4 * ['']
Pedido[0] = int(input('Digite a NOTA FISCAL do pedido: '))
Pedido[1] = float(input('Digite o VALOR TOTAL: '))
Pedido[2] = input('Digite a DATA do pedido: ')
Pedido[3] = input('Digite a PEÇA: ')



# inserindo os dados no banco
sql = """
    INSERT INTO pedidos(nota_fiscal, valor_total, data, pecas)
    VALUES (?, ?, ?, ?)
    """
cursor.execute(sql, Pedido)
conector.commit()

cursor.close()
conector.close()

print("\n\nFim do Programa")
