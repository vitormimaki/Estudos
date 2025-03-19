#taela de mercadorias
import sqlite3

conector = sqlite3.connect('banco.db')
cursor = conector.cursor()

try:
    sql = "drop table mercadorias"
    cursor.execute(sql)
except sqlite3.OperationalError:
    pass

# criando a tabela de mercadorias (somente se ela não existir)
sql = """
    CREATE TABLE mercadorias(
        cod_mercadoria INTEGER PRIMARY KEY AUTOINCREMENT,
        descricao STRING,
        preco_mercadoria NUMERIC,
        qtd_estoque INTEGER,
        cod_interno INTEGER,
        CONSTRAINT fk_cod_interno FOREIGN KEY (cod_interno) REFERENCES fornecedor(cod_interno))
    """
cursor.execute(sql)


Mercadoria = 4 * ['']
Mercadoria[0] = input('Digite a DESCRICAO da mercadoria: ')
Mercadoria[1] = float(input('Digite o PREÇO: '))
Mercadoria[2] = int(input('Digite a QUANTIDADE em estoque: '))
Mercadoria[3] = int(input('Digite o CODIGO INTERNO da mercadoria: '))


# inserindo os dados no banco
sql = """
    INSERT INTO mercadorias(descricao, preco_mercadoria, qtd_estoque, cod_interno)
    VALUES (?, ?, ?, ?)
    """
cursor.execute(sql, Mercadoria)

conector.commit()
cursor.close()
conector.close()

print("\n\nFim do Programa")
