chcp 65001
@echo off
color 0a

title MENU DE FUNÇÕES

:menu
cls
echo.
echo ---------------------
echo    MENU DE FUNÇÕES
echo ---------------------
echo.
echo [P]ACOTE OFFICE
echo [S]ERVIÇOS DE REDE
echo [A]PLICATIVOS WINDOWS
echo [G]ERENCIAMENTO DA MAQUINA
echo [E]NCERRAR SESSAO
echo [F]FINALIZAR PROGRAMA
echo.
echo ---------------------

set /p op= Digite a opçao desejada: 

if /i %op% equ p (goto office)
if /i %op% equ s (goto rede)
if /i %op% equ a (goto app)
if /i %op% equ g (goto gerenciar)
if /i %op% equ e (goto LogIn)
if /i %op% equ f (exit) else (
	echo.
	echo ---------------------
	echo   Opcao Invalida !
	echo ---------------------
	echo.
	pause > nul
	goto menu)

:office
cls
echo.
echo ---------------------
echo    PACOTE OFFICE
echo ---------------------
echo.
echo [W]ORD
echo [E]XCEL
echo [A]CCES
echo [P]OWER POINT
echo [R]ETORNAR AO MENU
echo.
echo ---------------------

set /p op= Digite a opçao desejada: 


if /i %op% equ w (goto:word)
if /i %op% equ e (goto:excel)
if /i %op% equ a (goto:access)
if /i %op% equ p (goto:ppt)
if /i %op% equ r (goto:menu) else (
	echo.
	echo ---------------------
	echo   Opcao Invalida !
	echo ---------------------
	echo.
	pause > nul
	goto office)
	
:word
start winword.exe
goto office

:excel
start excel.exe
goto office

:access
start msaccess.exe
goto office

:ppt
start powerpnt.exe
goto office

:rede
cls
echo.
echo ---------------------
echo   SERVIÇOS DE REDE
echo ---------------------
echo.
echo [N]AVEGAR INTERNET
echo [T]ESTAR CONEXAO DE REDE
echo [O]BTER IP DA MAQUINA
echo [E]STATISTICAS DE REDE
echo [R]ETORNAR AO MENU
echo.
echo ---------------------

set /p op= Digite a opçao desejada: 

if /i %op% equ n (goto:navegar)
if /i %op% equ t (goto:teste)
if /i %op% equ o (goto:ip)
if /i %op% equ e (goto:est)
if /i %op% equ r (goto:menu) else (
	echo.
	echo ---------------------
	echo   Opcao Invalida !
	echo ---------------------
	echo.
	pause > nul
	goto rede)
	
:navegar
echo.
set /p site= Digite o endereco da pagina web: 
start chrome.exe %site%
goto rede

:teste
echo.
set /p teste= Digite o IP da maquina ou endereco web: 
ping %teste% -t
goto rede

:ip
ipconfig /all
pause > nul
goto rede

:est
netstat
pause > nul
goto rede

:app
cls
echo.
echo ---------------------
echo APLICATIVOS DO WINDOWS
echo ---------------------
echo.
echo [C]ALCULADORA
echo [T]ECLADO VIRTUAL
echo [W]INDOWS EXPLORER
echo [G]OOGLE CHROME
echo [P]AINT
echo [B]LOCO DE NOTAS
echo [R]ETORNAR AO MENU
echo.
echo ---------------------

set /p op= Digite a opçao desejada: 

if /i %op% equ c (goto:math)
if /i %op% equ t (goto:teclado)
if /i %op% equ w (goto:explorer)
if /i %op% equ g (goto:chrome)
if /i %op% equ p (goto:paint)
if /i %op% equ b (goto:notepad)
if /i %op% equ r (goto:menu) else (
	echo.
	echo ---------------------
	echo   Opcao Invalida !
	echo ---------------------
	echo.
	pause > nul
	goto app)
	
:math
start calc.exe
goto app

:teclado
start osk.exe
goto app

:explorer
start explorer.exe
goto app

:chrome
start chrome.exe
goto app

:paint
start mspaint.exe
goto app

:notepad
start notepad.exe
goto app

:gerenciar
cls
echo.
echo ------------------------
echo GERENCIAMENTO DA MAQUINA
echo ------------------------
echo.
echo [I]NFORMAÇÃO DO SISTEMA
echo [DM]DESLIGAR A MAQUINA
echo [RM]REINICIAR A MAQUINA
echo [HM]HIBERNAR A MAQUINA
echo [R]ETORNAR AO MENU
echo.
echo ---------------------

set /p op= Digite a opçao desejada: 

if /i %op% equ i (goto:info)
if /i %op% equ dm (goto:desligar)
if /i %op% equ rm (goto:reiniciar)
if /i %op% equ hm (goto:hibernar)
if /i %op% equ r (goto:menu) else (
	echo.
	echo ---------------------
	echo   Opcao Invalida !
	echo ---------------------
	echo.
	pause > nul
	goto gerenciar)

:info
systeminfo
pause > nul
goto gerenciar

:desligar
shutdown /s /t
goto gerenciar

:reiniciar
shutdown /r /t
goto gerenciar

:hibernar
shutdown /h /t
goto gerenciar