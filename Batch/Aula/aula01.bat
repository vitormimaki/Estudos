chcp 65001
rem codificacao da tabela ascii
@echo off
rem oculta os scripts para o usuario, apenas ve o front
title Aula 01 - Sistemas de Informaçao
color 0A
rem color -> trabalha com cores
:inicio
rem : -> nomeia uma funçao
cls
rem cls -> limpa a tela
echo.
rem echo. -> pula linha no front
rem echo -> montar tela
echo     ( 0   0 )
echo ======= U =======
echo  Menu Principal
echo =================
echo [W] Executar o Word
echo [E] Executar o Excel
echo [P] Executar o PowerPoint
echo [A] Executar o Access
echo [C] Executar a Calculadora
echo [T] Teclado Virtual
echo [N] Navegador
echo [R] Testar Conexao Rede
echo [Y] Youtube
echo [O] Outra Tela
echo [F] Finalizar Programa
echo ===========================
rem set /p -> entrada de dados
set /p op= Digite a opcao desejada: 
rem if/i -> Ignora Caps
rem % -> Concatena; equ == -> igual
if /i %op% == w (goto:word)
if /i %op% == e (goto:excel)
if /i %op% == p (goto:slides)
if /i %op% == a (goto:banco)
if /i %op% == c (goto:calculo)
if /i %op% == t (goto:teclado)
if /i %op% == n (goto:web)
if /i %op% == r (goto:conexao)
if /i %op% == y (goto:youtube)
if /i %op% == o (call tela2.bat)
if /i %op% == f (exit) else (
	echo.
	echo ---------------------
	echo   Opcao Invalida !
	echo ---------------------
	echo.
	pause
	rem pause > nul -> tira a frase bonitinha (nao use esta porra)
	goto inicio)
	
:word
start winword.exe
goto inicio

:excel
start excel.exe
goto inicio

:slides
start powerpnt.exe
goto inicio

:banco
start msaccess.exe
goto inicio

:calculo
start calc.exe
goto inicio

:teclado
start osk.exe
goto inicio

:web
echo.
set /p site= Digite o endereco da pagina web: 
start chrome.exe %site%
goto inicio

:conexao
echo.
set /p teste= Digite o IP da maquina ou endereco web: 
ping %teste% -t
goto inicio

:youtube
echo.
set /p busca= Digite o conteudo a ser pesquisado: 
start chrome.exe https://www.youtube.com/results?search_query=%busca%
goto inicio