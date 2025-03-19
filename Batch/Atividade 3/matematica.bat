chcp 65001
@echo off
color 0a

title TESTE DE MATEMÁTICA

:nome
cls
set /p nome= DIGITE O SEU NOME: 
goto menu

:menu
cls
title MENU
echo BEM VINDO(A), %nome%!
echo MENU
echo [J]OGAR
echo [P]LACAR
echo [S]AIR
set /p op= SELECIONE UMA OPÇÃO: 
if /i %op% equ j (goto inicio)
if /i %op% equ p (goto placar)
if /i %op% equ s (exit) else (
	echo OPÇÃO INVÁLIDA!
	pause > nul
	goto:menu
)

:inicio
set /a acertos= 0
goto jogo

:jogo
cls
title TESTE DE MATEMÁTICA
echo OLÁ, %nome%! BOA SORTE!
set /a num1= (%random% %%10) + 1
set /a num2= (%random% %%10) + 1
set /a oper= (%random% %%3) + 1
echo ----------------------------
if %oper% equ 1 (
	echo %num1% + %num2% = ???
	set /a resp= %num1% + %num2%)
if %oper% equ 2 (
	echo %num1% - %num2% = ???
	set /a resp= %num1% - %num2%)
if %oper% equ 3 (
	echo %num1% * %num2% = ???
	set /a resp= %num1% * %num2%)
echo ----------------------------
echo Qtde de Acertos: %acertos%
echo ----------------------------
set /p op= DIGITE SUA RESPOSTA: 
set /a op=%op%
if %op% equ %resp% (
	set /a acertos= %acertos% + 1
	echo -----------------
	echo Resposta Correta!
	echo -----------------
	pause > nul
	goto jogo) else (
	echo -----------------
	echo Resposta Errada!
	echo -----------------
	goto registra)
	
:registra
echo %nome%     %acertos% >> placar.txt
echo ----------------------------------------
echo %acertos% Acertos! Parabéns, %nome%!
echo ----------------------------------------
echo.
set /p op= Deseja jogar novamente? [s/n]: 
if /i %op% equ s (goto inicio) else (goto menu)

:placar
cls
title PLACAR
echo ---- PLACAR ----
echo NOME     ACERTOS 
echo ----------------
type placar.txt
echo ----------------
echo.
pause > nul
goto menu