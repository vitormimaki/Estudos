CREATE DATABASE DadosERP

use DadosERP

CREATE TABLE FORNCLIEN (
    CodCliFor     INTEGER NOT NULL,
    TipoCF        INTEGER,
    CodRepres     INTEGER,
    NomeFan       TEXT,
    Cidade        TEXT,
    UF            TEXT,
    CodMunicipio  INTEGER,
    TipoPessoa    INTEGER,
    CobrBanc      INTEGER,
    PrazoPgto     INTEGER,
    PRIMARY KEY(CodCliFor)
);

CREATE TABLE PEDIDOS (
    NumPed        INTEGER NOT NULL,
    DataPed       INTEGER,
    HoraPed       INTEGER,
    CodClien      TEXT,
    ES            TEXT,
    FinalidNFe    TEXT,
    Situacao      INTEGER,
    Peso          INTEGER,
    PrazoPgto     INTEGER,
    ValorProds    REAL,
    ValorDesc     REAL,
    Valor         REAL,
    ValBaseICMS   REAL,
    ValICMS       REAL,
    Comissao      REAL,
    PRIMARY KEY(NumPed)
);

CREATE TABLE PEDIDOSITEM (
    NumPed        INTEGER NOT NULL,
    NumItem       INTEGER NOT NULL,
    CodProd       INTEGER,
    Qtde          REAL,
    ValUnit       REAL,
    Unid          REAL,
    AliqICMS      REAL,
    Comissao      REAL,
    STICMS        INTEGER,
    CFOP          INTEGER,
    ReducBaseICMS REAL,
    PRIMARY KEY(NumPed, NumItem)
);

CREATE TABLE PRODUTOS (
    CodProd       INTEGER NOT NULL,
    NomeProd      TEXT,
    CodForne      INTEGER,
    Unidade       INTEGER,
    AliqICMS      REAL,
    ValCusto      REAL,
    ValVenda      REAL,
    QtdeMin       REAL,
    QtdeEstq      REAL,
    Grupo         INTEGER,
    ClasseEstq    TEXT,
    Comissao      REAL,
    PesoBruto     REAL,
    PRIMARY KEY(CodProd)
);

CREATE TABLE REPRES (
    CodRepres     INTEGER NOT NULL,
    TipoPess      TEXT,
    NomeFan       TEXT,
    ComissaoBase  REAL,
    PRIMARY KEY(CodRepres)
);