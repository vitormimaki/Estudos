chcp 65001
@echo off
color 0a
set /a cont=0
rem /a atributo numerico variavel
:sorteio
cls
set /a numero=(%random% %%100) + 1
set /a cont=%cont% + 1
echo.
echo ------Resultdo do Sorteio--------
echo Numero Sorteado : %numero%
echo Qtde de Sorteio : %cont%
echo ---------------------------------
echo.
set /p resp= Deseja Sortear Novo Numero? [s/n] :
if /i %resp% equ s (goto:sorteio) else (exit)