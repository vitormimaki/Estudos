       IDENTIFICATION DIVISION.
      *=======================*
       PROGRAM-ID.   CGPRG005.
       AUTHOR.       VITOR MIMAKI.
       DATE-WRITTEN. 02/04/2025.
       DATE-COMPILED. 02/04/2025.
       SECURITY.     NIVEL INTERMEDIARIO.
       INSTALLATION. FATEC SAO CAETANO.
      *--------------------------------------------------------------*
      * DISCIPLINA PROGRAMACAO MAINFRAME
      *--------------------------------------------------------------*
      * OBJETIVO: RECEBER DADOS DA SYSIN(ACCEPT)
      *           CALCULAR A MEDIA ARITMETICA BIMESTRAL
      *--------------------------------------------------------------*
      *------------------> HISTORICO - MANUTENCAO <------------------*
      * VERSAO  MES/ANO  NR.DOC  IDENT.  DESCRICAO
      * ------  -------  ------  ------  -------------------------   *
      *  V01    ABR/2025 010001  SISTEMA MOSTRA SYSOUT
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
       DATA DIVISION.
      *=============*
       FILE SECTION.
      *------------*
       WORKING-STORAGE SECTION.
      *-----------------------*
       77  AS-HIFENS              PIC X(80) VALUE ALL '-'.

      *-----> VARIAVEIS AUXILIARES UTILIZADA NO PROCESSAMENTO
       01  WS-AREA-AUX.
           05  WS-FIM                 PIC X(01).
           05  WS-CTLIDO              PIC 9(02).
           05  WS-MEDIA               PIC 9(02)V99.
           05  WS-CTF                 PIC 9(02).
           05  WS-CTH                 PIC 9(02).
           05  WS-MEDIA-GERAL         PIC Z9,99.
           05  AS-SOMAS-MEDIAS        PIC 9(03)V9(04) VALUE ZEROS.
           05  AS-MEDIA-GERAL         PIC 9(02)V9(04) VALUE ZEROS.
           05  WS-MEDIA-ABAIXO        PIC Z9.
           05  AS-MEDIA-ABAIXO        PIC 99 VALUE ZEROS.
           05  WS-PORCENT-ABAIXO      PIC Z9,99.
           05  AS-PORCENT-ABAIXO      PIC 9(02)V99 VALUE ZEROS.
      *-----> ENTRADA - DADOS VIA SYSIN (NO JCL DE EXECUCAO)
       01  WS-REG-SYSIN.
           05 WS-NUMERO-IN        PIC 9(04).
           05 WS-NOME-IN          PIC X(20).
           05 WS-SEXO-IN          PIC X(01).
           05 WS-IDADE-IN         PIC 9(02).
           05 WS-CURSO-IN         PIC X(12).
           05 WS-NOTA1-IN         PIC 9(02)V99.
           05 WS-NOTA2-IN         PIC 9(02)V99.

       01  WS-REG-SYSOUT.
           05 WS-NUM              PIC 9(04).
           05 FILLER              PIC X(01) VALUE SPACES.
           05 WS-NOM              PIC X(20).
           05 FILLER              PIC X(02) VALUE ALL SPACES.
           05 WS-SEX              PIC X(01).
           05 FILLER              PIC X(04) VALUE ALL SPACES.
           05 WS-IDA              PIC Z9.
           05 FILLER              PIC X(03) VALUE SPACES.
           05 WS-CUR              PIC X(12).
           05 FILLER              PIC X(01) VALUE SPACES.
           05 WS-NT1              PIC Z9,99.
           05 FILLER              PIC X(01) VALUE SPACES.
           05 WS-NT2              PIC Z9,99.
           05 FILLER              PIC X(01) VALUE SPACES.
           05 WS-MED              PIC Z9,99.

       01  WS-CAB.
           05 FILLER              PIC X(03) VALUE 'NUM'.
           05 FILLER              PIC X(02) VALUE SPACES.
           05 FILLER              PIC X(04) VALUE 'NOME'.
           05 FILLER              PIC X(17) VALUE SPACES.
           05 FILLER              PIC X(03) VALUE 'SEX'.
           05 FILLER              PIC X(01) VALUE SPACES.
           05 FILLER              PIC X(05) VALUE 'IDADE'.
           05 FILLER              PIC X(02) VALUE SPACES.
           05 FILLER              PIC X(05) VALUE 'CURSO'.
           05 FILLER              PIC X(08) VALUE SPACES.
           05 FILLER              PIC X(05) VALUE 'NOTA1'.
           05 FILLER              PIC X(01) VALUE SPACES.
           05 FILLER              PIC X(05) VALUE 'NOTA2'.
           05 FILLER              PIC X(01) VALUE SPACES.
           05 FILLER              PIC X(05) VALUE 'MEDIA'.
      *
       PROCEDURE DIVISION.
      *==================*
      *--------------------------------------------------------------*
      *    PROCESSO PRINCIPAL
      *--------------------------------------------------------------*
       000-RSPRG002.

           PERFORM 010-INICIAR
           PERFORM 030-PROCESSAR UNTIL WS-FIM = 'S'
           PERFORM 090-TERMINAR
           STOP RUN
           .
      *--------------------------------------------------------------*
      *    PROCEDIMENTOS INICIAIS
      *--------------------------------------------------------------*
       010-INICIAR.

           DISPLAY AS-HIFENS
           DISPLAY 'PROGRAMA 5'
           DISPLAY 'VITOR MIMAKI - ARTHUR DE QUEIROZ'
           DISPLAY 'CALCULO DA MEDIA DOS ALUNOS A PARTIR DA SYSIN'
           DISPLAY AS-HIFENS
           DISPLAY WS-CAB
           DISPLAY AS-HIFENS
           PERFORM 025-LER-SYSIN
           .
      *--------------------------------------------------------------*
      *    LEITURA DADOS DA SYSIN
      *--------------------------------------------------------------*
       025-LER-SYSIN.

           ACCEPT WS-REG-SYSIN  FROM SYSIN

           IF WS-REG-SYSIN = ALL '9'
              MOVE   'S'     TO  WS-FIM
           ELSE
              ADD 1  TO WS-CTLIDO
           END-IF
           .
      *--------------------------------------------------------------*
      *    PROCESSAR DADOS RECEBIDOS DA SYSIN ATE FIM DOS REGISTROS
      *--------------------------------------------------------------*
       030-PROCESSAR.

           COMPUTE WS-MEDIA = (WS-NOTA1-IN + WS-NOTA2-IN) / 2
           MOVE WS-MEDIA TO WS-MED
           ADD WS-MEDIA TO AS-SOMAS-MEDIAS
           COMPUTE AS-MEDIA-GERAL = AS-SOMAS-MEDIAS / WS-CTLIDO
           MOVE AS-MEDIA-GERAL TO WS-MEDIA-GERAL
           IF WS-MEDIA < 6
               ADD 1 TO AS-MEDIA-ABAIXO
               MOVE AS-MEDIA-ABAIXO TO WS-MEDIA-ABAIXO
           END-IF
           COMPUTE AS-PORCENT-ABAIXO = AS-MEDIA-ABAIXO * 100
                                     / WS-CTLIDO
           MOVE AS-PORCENT-ABAIXO TO WS-PORCENT-ABAIXO
           MOVE WS-NUMERO-IN TO WS-NUM
           MOVE WS-NOME-IN TO WS-NOM
           MOVE WS-SEXO-IN TO WS-SEX
           IF WS-SEXO-IN = 'F'
               ADD 1 TO WS-CTF
           ELSE
               ADD 1 TO WS-CTH
           END-IF
           MOVE WS-IDADE-IN TO WS-IDA
           MOVE WS-CURSO-IN TO WS-CUR
           MOVE WS-NOTA1-IN TO WS-NT1
           MOVE WS-NOTA2-IN TO WS-NT2
           DISPLAY WS-REG-SYSOUT

           PERFORM 025-LER-SYSIN
           .
      *--------------------------------------------------------------*
      *    PROCEDIMENTOS FINAIS
      *--------------------------------------------------------------*
       090-TERMINAR.

           DISPLAY AS-HIFENS
           DISPLAY ' *========================================*'
           DISPLAY ' *   TOTAIS DE CONTROLE - CGPRG005        *'
           DISPLAY ' *----------------------------------------*'
           DISPLAY ' * REGISTROS LIDOS..: ' WS-CTLIDO
           DISPLAY ' * TOTAL MULHERES...: ' WS-CTF
           DISPLAY ' * TOTAL HOMENS.....: ' WS-CTH
           DISPLAY ' * MEDIA GERAL DOS ALUNOS.......: '
                     WS-MEDIA-GERAL
           DISPLAY ' * TOTAL DE ALUNOS COM MEDIA < 6: '
                     WS-MEDIA-ABAIXO
           DISPLAY ' * % DE ALUNOS COM MEDIA < 6....: '
                     WS-PORCENT-ABAIXO '%'
           DISPLAY ' *========================================*'
           DISPLAY ' *----------------------------------------*'
           DISPLAY ' * TERMINO NORMAL DO CGPRG005 *'
           DISPLAY ' *----------------------------------------*'
           .
      *---------------> FIM DO PROGRAMA CGPRG005 <-------------------*
