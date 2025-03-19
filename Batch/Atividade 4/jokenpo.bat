chcp 65001
@echo off
color 0a

title JO-KEN-PO

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
echo [R]EGRAS
echo [S]AIR
set /p op= SELECIONE UMA OPÇÃO: 
if /i %op% equ j (goto inicio)
if /i %op% equ p (goto placar)
if /i %op% equ r (goto regras)
if /i %op% equ s (exit) else (
	echo OPÇÃO INVÁLIDA!
	pause > nul
	goto:menu
)

:inicio
set /a vitorias= 0
set /a empates= 0
set /a derrotas= 0
goto jogar

:jogar
cls
title JO-KEN-PO
echo OLÁ, %nome%! BOA SORTE!
set /a cp= (%random% %%5) + 1
echo ----------------------------
echo Qtde de Vitórias: %vitorias%
echo Qtde de Empates: %empates%
echo Qtde de Derrotas: %derrotas%
echo ----------------------------
echo [1] Pedra
echo [2] Papel
echo [3] Tesoura
echo [4] Lagarto
echo [5] Spock
echo ----------------------------
set /p op= FAÇA A SUA ESCOLHA: 
set /a op=%op%
if %op% lss 1 (
	echo.
	echo ESCOLHA INVÁLIDA!
	pause > nul
	goto jogar)
if %op% gtr 5 (
	echo.
	echo ESCOLHA INVÁLIDA!
	pause > nul
	goto jogar)
	
if %op% equ 1 (
	set esc= Pedra
	if %cp% equ 3 (
		set cesc= Tesoura
		set res= VITÓRIA
		set /a vitorias=%vitorias%+1)
	if %cp% equ 4 (
		set cesc= Lagarto
		set res= VITÓRIA
		set /a vitorias=%vitorias%+1)
	if %cp% equ 2 (
		set cesc= Papel
		set res= DERROTA
		set /a derrotas=%derrotas%+1)
	if %cp% equ 5 (
		set cesc= Spock
		set res= DERROTA
		set /a derrotas=%derrotas%+1)
)
	
if %op% equ 2 (
	set esc= Papel
	if %cp% equ 1 (
		set cesc= Pedra
		set res= VITÓRIA
		set /a vitorias=%vitorias%+1)
	if %cp% equ 5 (
		set cesc= Spock
		set res= VITÓRIA
		set /a vitorias=%vitorias%+1)
	if %cp% equ 3 (
		set cesc= Tesoura
		set res= DERROTA
		set /a derrotas=%derrotas%+1)
	if %cp% equ 4 (
		set cesc= Lagarto
		set res= DERROTA
		set /a derrotas=%derrotas%+1)
)
	
if %op% equ 3 (
	set esc= Tesoura
	if %cp% equ 2 (
		set cesc= Papel
		set res= VITÓRIA
		set /a vitorias=%vitorias%+1)
	if %cp% equ 4 (
		set cesc= Lagarto
		set res= VITÓRIA
		set /a vitorias=%vitorias%+1)
	if %cp% equ 1 (
		set cesc= Pedra
		set res= DERROTA
		set /a derrotas=%derrotas%+1)
	if %cp% equ 5 (
		set cesc= Spock
		set res= DERROTA
		set /a derrotas=%derrotas%+1)
)
	
if %op% equ 4 (
	set esc= Lagarto
	if %cp% equ 2 (
		set cesc= Papel
		set res= VITÓRIA
		set /a vitorias=%vitorias%+1)
	if %cp% equ 5 (
		set cesc= Spock
		set res= VITÓRIA
		set /a vitorias=%vitorias%+1)
	if %cp% equ 1 (
		set cesc= Pedra
		set res= DERROTA
		set /a derrotas=%derrotas%+1)
	if %cp% equ 3 (
		set cesc= Tesoura
		set res= DERROTA
		set /a derrotas=%derrotas%+1)
)
	
if %op% equ 5 (
	set esc= Spock
	if %cp% equ 1 (
		set cesc= Pedra
		set res= VITÓRIA
		set /a vitorias=%vitorias%+1)
	if %cp% equ 3 (
		set cesc= Tesoura
		set res= VITÓRIA
		set /a vitorias=%vitorias%+1)
	if %cp% equ 2 (
		set cesc= Papel
		set res= DERROTA
		set /a derrotas=%derrotas%+1)
	if %cp% equ 4 (
		set cesc= Lagarto
		set res= DERROTA
		set /a derrotas=%derrotas%+1)
)
	
if %cp% equ %op% (
	set res= EMPATE
	set /a empates=%empates% + 1
	set cesc=%esc%)

echo.
echo --------------------------------
echo             %res%
echo --------------------------------
echo Sua Escolha: %esc%
echo Escolha da CPU: %cesc%
echo --------------------------------
echo.
set /p dnv= Deseja Jogar Novamente? [s/n]: 
if /i %dnv% equ s (goto jogar) else (goto registrar)

:registrar
echo %nome%      %vitorias%           %empates%           %derrotas% >> placar.txt
goto menu


:placar
cls
title PLACAR
echo ----------------- PLACAR -----------------
echo NOME     VITÓRIAS     EMPATES     DERROTAS 
echo ------------------------------------------
type placar.txt
echo ------------------------------------------
echo.
pause > nul
goto menu

:regras
cls
title REGRAS
echo ==============================================================================
echo Pedra:
echo 	Empata com Pedra; Ganha de Tesoura e Lagarto; Perde de Papel e Spock;
echo Papel:
echo 	Empata com Papel; Ganha de Pedra e Spock; Perde de Tesoura e Lagarto;
echo Tesoura:
echo 	Empata com Tesoura; Ganha de Lagarto e Papel; Perde de Pedra e Spock;
echo Lagarto:
echo 	Empata com Lagarto; Ganha de Papel e Spock; Perde de Pedra e Tesoura;
echo Spock:
echo 	Empata com Spock; Ganha de Pedra e Tesoura; Perde de Lagarto e Papel;
echo ==============================================================================
echo.
pause > nul
goto menu