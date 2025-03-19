Dim n1, n2, media, situacao, resp 'Declaração de Variáveis Local
Dim audio

call carregar_voz

sub carregar_voz()
	set audio = CreateObject("SAPI.SPVOICE") 'Objeto para Criar Áudio
	audio.volume = 100 'Volume da Fala
	audio.rate = 1 'Velocidade da Fala
	call entrada_notas 'Chamando Método
end sub

sub entrada_notas() 'Criando Método
	'Entrada de Dados
	n1 = cdbl(inputbox("Digite a Nota 1", "Rendimento do Aluno")) 'cdbl - convert double
	n2 = cdbl(inputbox("Digite a Nota 2", "Rendimento do Aluno"))
	'Processamento
	media = round((n1+n2)/2,1) 'round(equaç, casasdec) - Arredonda
	if media < 4 then
		situacao = "Reprovado"
	elseif media >=4 and media < 6 then
		situacao = "Recuperação"
	else
		situacao = "Aprovado"
	end if
	
	audio.speak("Média do Aluno " & media & "" + vbNewLine & _
			    "Situação do Aluno " & situacao & "") 'Falar
	
	'Saídas de Dados
	resp = MsgBox("Media do Aluno: " & media & "" + vbNewLine & _
				  "Situação Aluno: " & situacao & "" + vbNewLine & _
				  "Deseja Realizar Novo Cálculo?", vbquestion + vbYesNo, "ATENÇÃO")
	if resp=vbYes then
		call entrada_notas 'Chamar Função
	else
		wscript.quit 'Finalizar Script
	end if
end sub