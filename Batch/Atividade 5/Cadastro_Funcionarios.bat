chcp 65001
@echo off
color 0a

:menu
echo.
title MENU
cls
echo ------------- Cadastro de Funcionários -------------
echo [N] Novo Funcionário
echo [L] Listagem Geral de Funcionários
echo [C] Consulta de Funcionários
echo [E] Exclusão de Funcionários
echo [F] Finalizar Programa
echo ------------------------------------------------
set /p op= Digite sua opçao: 
if /i %op% equ n (goto:gravar)
if /i %op% equ l (goto:listar)
if /i %op% equ c (goto:consultar)
if /i %op% equ e (goto:excluir)
if /i %op% equ f (exit) else (
	echo.
	echo ----- OPÇÃO INVÁLIDA! ----- 
	echo.
	 
	goto:menu)


:gravar
cls
title Novo Funcionário
echo.
set /p reg= Digite o REGISTRO do Funcionário: 
set /p nome= Digite o NOME do Funcionário: 
set /p data= Digite a DATA DE ADMISSÃO do Funcionário: 
set /p cargo= Digite o CARGO do Funcionário: 
set /p qtde= Digite a QUANTIDADE DE SALÁRIOS MÍNIMOS do Funcionário: 
set /a qtde=%qtde%
set /a sal_b= %qtde%*1320
if %sal_b% geq 1500 (
	set /a inss= %sal_b% * 11 / 100) else (
	set /a inss=0)
set /a sal_l=%sal_b% - %inss%
set sal_b= R$%sal_b%
set inss= R$%inss%
set sal_l= R$%sal_l%
echo %reg%      %nome%      %data%    %cargo%    %qtde%   %sal_b%   %inss%    %sal_l% >> lista_fun.txt
echo.
echo ----- Cadastro Realizado com Sucesso! -----
echo.
set /p resp= Deseja Cadastrar Novo Funcionário? [s/n]: 
if /i %resp% equ s (goto:gravar) else (goto:menu)

:listar
cls
title Listagem de Funcionários
echo.
echo ----------------------- Relação Geral de Funcionários -----------------------
echo REG      NOME DO CLIENTE      DATA    CARGO    QTDE   BRUTO   INSS    LÍQUIDO
echo -----------------------------------------------------------------------------
type lista_fun.txt
echo -----------------------------------------------------------------------------
echo.
pause > nul
goto:menu

:consultar
cls
title Consulta de Funcionários
echo.
set /p busca= Digite um parametro de busca: 
echo.
echo ----------------------- Relação Geral de Funcionários -----------------------
echo REG      NOME DO CLIENTE      DATA    CARGO    QTDE   BRUTO   INSS    LÍQUIDO
echo -----------------------------------------------------------------------------
findstr /i "%busca%" lista_fun.txt
echo -----------------------------------------------------------------------------
echo.
set /p resp= Deseja Cadastrar Nova Consulta? [s/n]: 
if /i %resp% equ s (goto:consulta) else (goto:menu)
pause > nul
goto:menu

:excluir
cls
title Exclusão de Funcionários
echo.
set /p busca= Digite o REGISTRO ou NOME do Cliente: 
findstr /i "%busca%" lista_fun.txt
::errorlevel 1 (existe o dado)
::errorlevel 0 (nao existe o dado)
if %errorlevel% equ 0 (
	findstr /i /v "%busca%" lista_fun.txt > lista_lixo.txt
	del lista_fun.txt
	rename lista_lixo.txt lista_fun.txt
	echo.
	echo ----- Registro Excluído com Sucesso! -----
	echo.
	pause > nul
	goto:menu) else (
	echo.
	echo ----- Dado não Encontrado! -----
	echo.
	pause > nul
	goto:menu)


pause > nul
goto:menu