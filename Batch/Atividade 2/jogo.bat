chcp 65001
@echo off
color 0a

:sorteio
cls
set /a cont=5
set /a numero=(%random% %%50) + 1
goto inicio

:inicio

cls

echo.
echo =======================================
echo ADVINHE O NUMERO SORTEADO ENTRE 01 E 50
echo ---------------------------------------
echo   QUANTIDADE DE TENTATIVAS = %cont%
echo ---------------------------------------
echo =======================================
echo.
set /p op= DIGITE O SEU PALPITE: 
set /a op=%op% 
echo.
echo ---------------------------------------
echo.

if %numero% equ %op% (
	echo            PARABENS! VOCE VENCEU!
	echo            Numero Sorteado : %numero%
	echo ---------------------------------
	goto novo_jogo
)

if %cont% equ 1 (
	echo            QUE PENA! VOCE PERDEU!
	echo            Numero Sorteado : %numero%
	echo ---------------------------------
	goto novo_jogo
)

if %numero% gtr %op% (
	set /a cont=%cont% - 1
	echo            TENTE UM NUMERO MAIOR
	echo ---------------------------------------
	pause > nul
	goto inicio
)

if %numero% lss %op% (
	set /a cont=%cont% - 1
	echo            TENTE UM NUMERO MENOR
	echo ---------------------------------------
	pause > nul
	goto inicio
)

:novo_jogo
set /p resp= Deseja Sortear Novo Numero? [s/n]: 
if /i %resp% equ s (goto:sorteio) else (exit)