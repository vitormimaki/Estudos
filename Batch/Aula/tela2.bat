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
rem echo. -> pula linha no front
rem echo -> montar tela
echo ╔════════════════╗
echo      Tela 02
echo =================
echo [G] Gerar Arquivos Diversos
echo [O] Organizar Arquivos
echo [R] Retornar ao Menu
echo ===========================
rem set /p -> entrada de dados
set /p op= Digite a opcao desejada: 
rem if/i -> Ignora Caps
rem % -> Concatena; equ == -> igual
if /i %op% == g (goto:gerar)
if /i %op% == o (goto:organizar)
if /i %op% == r (call aula01.bat) else (
	echo.
	echo ---------------------
	echo   Opcao Invalida !
	echo ---------------------
	echo.
	pause 
	rem pause > nul -> tira a frase bonitinha (nao use esta porra)
	goto inicio)

:gerar
echo.
set /p nome= Digite o Nome do Arquivo a ser gerado: 
set /p qtde= Digite a Quantidade de Arquivos a serem gerados: 
set /p ext= Digite a Extensao do Tipo do Arquivo:
for /l %%n in (1, 1, %qtde%) do echo > %nome%%%n.%ext%
echo.
echo Arquivos Gerados com Sucesso!
echo.
pause
goto inicio

:organizar
echo.
c:
cd\Users\Aluno\Desktop
set /p pasta= Digite o nome da Pasta a ser Gerada: 
set /p ext= Digite a Extensao do Tipo do Arquivo: 
md %pasta%
move *.%ext% c:\Users\Aluno\Desktop\%pasta%
echo.
echo Arquivos organizados com Sucesso!
echo.
pause
goto inicio
