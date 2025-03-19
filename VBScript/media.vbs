Dim n1, n2, media, situacao, resp 'Declara��o de Vari�veis Local
Dim audio

call carregar_voz

sub carregar_voz()
	set audio = CreateObject("SAPI.SPVOICE") 'Objeto para Criar �udio
	audio.volume = 100 'Volume da Fala
	audio.rate = 1 'Velocidade da Fala
	call entrada_notas 'Chamando M�todo
end sub

sub entrada_notas() 'Criando M�todo
	'Entrada de Dados
	n1 = cdbl(inputbox("Digite a Nota 1", "Rendimento do Aluno")) 'cdbl - convert double
	n2 = cdbl(inputbox("Digite a Nota 2", "Rendimento do Aluno"))
	'Processamento
	media = round((n1+n2)/2,1) 'round(equa�, casasdec) - Arredonda
	if media < 4 then
		situacao = "Reprovado"
	elseif media >=4 and media < 6 then
		situacao = "Recupera��o"
	else
		situacao = "Aprovado"
	end if
	
	audio.speak("M�dia do Aluno " & media & "" + vbNewLine & _
			    "Situa��o do Aluno " & situacao & "") 'Falar
	
	'Sa�das de Dados
	resp = MsgBox("Media do Aluno: " & media & "" + vbNewLine & _
				  "Situa��o Aluno: " & situacao & "" + vbNewLine & _
				  "Deseja Realizar Novo C�lculo?", vbquestion + vbYesNo, "ATEN��O")
	if resp=vbYes then
		call entrada_notas 'Chamar Fun��o
	else
		wscript.quit 'Finalizar Script
	end if
end sub