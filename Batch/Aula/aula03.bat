chcp 65001
@echo off
color 0a
title CRUD Em Uma Lista

:menu
echo.
title MENU
cls
echo ------------- Cadastro de Clientes -------------
echo [N] Novo Cliente
echo [L] Listagem Geral de Clientes
echo [C] Consulta de Clientes
echo [E] Exclusao de Clientes
echo [F] Finalizar Programa
echo ------------------------------------------------
set /p op= Digite sua opçao: 
if /i %op% equ n (goto:gravar)
if /i %op% equ l (goto:listar)
if /i %op% equ c (goto:consultar)
if /i %op% equ e (goto:excluir)
if /i %op% equ f (exit) else (
	echo.
	echo ----- OPÇAO INVALIDA! ----- 
	echo.
	 
	goto:menu)


:gravar
cls
title Novo Cliente
echo.
set /p cpf= Digite o CPF do cliente: 
set /p nome= Digite o NOME do cliente: 
echo %cpf%     %nome% >> lista_cli.txt
echo.
echo ----- Cadastro Realizado com Sucesso! -----
echo.
set /p resp= Deseja cadastrar novo cliente? [s/n]: 
if /i %resp% equ s (goto:gravar) else (goto:menu)

:listar
cls
title Listagem de Clientes
echo.
echo ----- Relaçao Geral de Clientes -----
echo       CPF          NOME DO CLIENTE
echo -------------------------------------
type lista_cli.txt
echo -------------------------------------
echo.
pause > nul
goto:menu

:consultar
cls
title Consulta de Clientes
echo.
set /p busca= Digite um parametro de busca: 
echo.
echo ----- Relaçao Geral de Clientes -----
echo       CPF          NOME DO CLIENTE
echo -------------------------------------
findstr /i "%busca%" lista_cli.txt
echo -------------------------------------
echo.
set /p resp= Deseja cadastrar nova consulta? [s/n]: 
if /i %resp% equ s (goto:consulta) else (goto:menu)
pause > nul
goto:menu

:excluir
cls
title Exclusao de Clientes
echo.
set /p busca= Digite o CPF ou NOME do Cliente: 
findstr /i "%busca%" lista_cli.txt
::errorlevel 1 (existe o dado)
::errorlevel 0 (nao existe o dado)
if %errorlevel% equ 0 (
	findstr /i /v "%busca%" lista_cli.txt > lista_lixo.txt
	del lista_cli.txt
	rename lista_lixo.txt lista_cli.txt
	echo.
	echo ----- Registro Excluido com Sucesso! -----
	echo.
	pause > nul
	goto:menu) else (
	echo.
	echo ----- Dado nao Encontrado! -----
	echo.
	pause > nul
	goto:menu)


pause > nul
goto:menu