       IDENTIFICATION DIVISION.
      *=======================*
       PROGRAM-ID.   CGPRG004.
       AUTHOR. VITOR A. S. MIMAKI.
       INSTALLATION. FATEC SAO CAETANO.
       DATE-WRITTEN. 19/03/2025.
       DATE-COMPILED. 19/03/2025.
       SECURITY. NIVEL BASICO.
      *--------------------------------------------------------------*
       ENVIRONMENT DIVISION.
      *====================*
       CONFIGURATION SECTION.
      *---------------------*
       SPECIAL-NAMES.
           DECIMAL-POINT IS COMMA
           CURRENCY SIGN IS "R$ " WITH PICTURE SYMBOL "$"
           .
       INPUT-OUTPUT SECTION.
      *---------------------*
       FILE-CONTROL.
      *==> LOCAL PARA O SELECT DOS ARQUVOS

       DATA DIVISION.
      *=============*
       FILE SECTION.
      *------------*
      *==> LOCAL PARA A FD (DESCRICAO DOS ARQUIVOS)

       WORKING-STORAGE SECTION.
      *-----------------------*

      *-----> AREA AUXILIAR
       77  WS-FIM                 PIC X(01) VALUE 'N'.
       77  WS-CTEXIB              PIC 9(02).
       77  AS-CEP                 PIC 9(08).
       77  AS-FRENTE              PIC 9(03)V9(02).
       77  AS-COMP                PIC 9(03)V9(02).
       77  AS-VAL-M2              PIC 9(05)V9(02).
       77  AS-VAL-VENDA           PIC 9(08)V9(02).
       77  AS-COMISSAO            PIC 9(07)V9(02).
       77  AS-DATA                PIC 9(08).
       77  AS-HORA                PIC 99.99.9999.
       77  AS-HIFENS              PIC X(80) VALUE ALL '-'.
      *-----> DADOS DE SAIDA VIA SYSOUT
       01  WS-REG-SYSOUT.
           05 WS-CEP              PIC 9(08).
           05 FILLER              PIC X(01) VALUE SPACE.
           05 WS-FRENTE           PIC ZZ9,99.
           05 FILLER              PIC X(02) VALUE 'M '.
           05 WS-COMP             PIC ZZ9,99.
           05 FILLER              PIC X(02) VALUE 'M '.
           05 WS-VAL-M2           PIC $$.$$9,99.
           05 FILLER              PIC X(01) VALUE SPACE.
           05 WS-VAL-VENDA        PIC $$.$$$.$$9,99.
           05 FILLER              PIC X(01) VALUE SPACE.
           05 WS-COMISSAO         PIC $.$$$.$$9,99.
           05 FILLER              PIC X(01) VALUE SPACE.
           05 WS-MENSAGEM         PIC X(12).
       01  WS-CAB.
           05 FILLER              PIC X(03) VALUE 'CEP'.
           05 FILLER              PIC X(07) VALUE SPACES.
           05 FILLER              PIC X(06) VALUE 'FRENTE'.
           05 FILLER              PIC X(02) VALUE SPACES.
           05 FILLER              PIC X(04) VALUE 'COMP'.
           05 FILLER              PIC X(03) VALUE SPACES.
           05 FILLER              PIC X(11) VALUE 'PRECO-DO-M2'.
           05 FILLER              PIC X(01) VALUE SPACES.
           05 FILLER              PIC X(14) VALUE 'PRECO-DE-VENDA'.
           05 FILLER              PIC X(04) VALUE SPACES.
           05 FILLER              PIC X(08) VALUE 'COMISSAO'.
           05 FILLER              PIC X(05) VALUE SPACES.
           05 FILLER              PIC X(08) VALUE 'MENSAGEM'.

       LINKAGE SECTION.
      *----------------*
       01  LK-PARAMETROS.
           05 LK-NR-DPTO             PIC 9(04).
           05 LK-NOME-DPTO           PIC X(15).
           05 LK-COD-RETORNO         PIC 99.
      *
       PROCEDURE DIVISION.
      *==================*
      *--------------------------------------------------------------*
      *    PROCESSO PRINCIPAL                                        *
      *--------------------------------------------------------------*

           PERFORM 010-INICIAR
           PERFORM 030-PROCESSAR UNTIL WS-FIM = 'S'
           PERFORM 050-TERMINAR
           STOP RUN
           .
      *--------------------------------------------------------------*
      *    PROCEDIMENTOS INICIAIS                                    *
      *--------------------------------------------------------------*
       010-INICIAR.
           ACCEPT AS-DATA FROM DATE
           ADD 20000000 TO AS-DATA
           ACCEPT AS-HORA FROM TIME
           DISPLAY "ATIVIDADE 4**"
           DISPLAY 'VITOR A. S. MIMAKI'
           DISPLAY 'CALCULO DO PRECO DE VENDA DE '
                   'UM TERRENO RETANGULAR'
           DISPLAY 'DATA DO CALCULO: ' AS-DATA(7:2)
                   '/' AS-DATA(5:2) '/' AS-DATA(1:4)
           DISPLAY 'HORA DO CALCULO: ' AS-HORA
           DISPLAY AS-HIFENS
           MOVE  ZEROS  TO  WS-CTEXIB
           .
      *--------------------------------------------------------------*
      *    PROCESSAR DADOS RECEBIDOS DA SYSIN                        *
      *--------------------------------------------------------------*
       030-PROCESSAR.

           MOVE 09000300           TO   AS-CEP
           MOVE AS-CEP TO WS-CEP
           MOVE 12,35              TO   AS-FRENTE
           MOVE AS-FRENTE TO WS-FRENTE
           MOVE 52,00              TO   AS-COMP
           MOVE AS-COMP TO WS-COMP
           MOVE 2315,00            TO   AS-VAL-M2
           MOVE AS-VAL-M2 TO WS-VAL-M2
           COMPUTE AS-VAL-VENDA = AS-FRENTE * AS-COMP
           * AS-VAL-M2
           MOVE AS-VAL-VENDA TO WS-VAL-VENDA
           IF AS-VAL-VENDA > 1500000
                COMPUTE AS-COMISSAO = AS-VAL-VENDA * 0,04
                MOVE 'ALTO PADRAO' TO WS-MENSAGEM
           ELSE
                COMPUTE AS-COMISSAO = AS-VAL-VENDA * 0,06
                MOVE 'MEDIO PADRAO' TO WS-MENSAGEM
           END-IF
           MOVE AS-COMISSAO TO WS-COMISSAO
           DISPLAY WS-CAB
           DISPLAY WS-REG-SYSOUT
           ADD 1 TO WS-CTEXIB
           MOVE 'S' TO WS-FIM
           .
      *--------------------------------------------------------------*
      *    PROCEDIMENTOS FINAIS                                      *
      *--------------------------------------------------------------*
       050-TERMINAR.

           DISPLAY AS-HIFENS
           DISPLAY '** ENCERRANDO A EXECUCAO **'
           DISPLAY "REGISTROS EXIBIDOS = " WS-CTEXIB
           DISPLAY "TERMINO NORMAL DO PROGRAMA CGPRG004"
           .
      *---------------> FIM DO PROGRAMA CGPRG004 <-------------------*
