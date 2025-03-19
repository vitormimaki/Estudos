dim palavras(30), acertos, nome, sorteado, resp, pulo, repetir, extenso
dim audio

call carregar_voz

sub carregar_voz()
	set audio = CreateObject("SAPI.SPVOICE")
	audio.volume = 100
	audio.rate = 1
	call carregar_vetor
end sub

sub carregar_vetor()
	
	palavras(0) = "horizonte"
	palavras(1) = "receita"
	palavras(2) = "pressão"
	palavras(3) = "aquecimento"
	palavras(4) = "clara"
	palavras(5) = "rotate"
	palavras(6) = "alternado"
	palavras(7) = "licor"
	palavras(8) = "esquiar"
	palavras(9) = "laringite"
	palavras(10) = "companhia"
	palavras(11) = "sopa"
	palavras(12) = "ninho"
	palavras(13) = "aba"
	palavras(14) = "solta"
	palavras(15) = "monte"
	palavras(16) = "coruja"
	palavras(17) = "xilofone"
	palavras(18) = "picante"
	palavras(19) = "filhos"
	palavras(20) = "ditador"
	palavras(21) = "cacto"
	palavras(22) = "esportes"
	palavras(23) = "inesperado"
	palavras(24) = "eixo"
	palavras(25) = "estribos"
	palavras(26) = "enterrar"
	palavras(27) = "aro"
	palavras(28) = "corpo"
	palavras(29) = "fita"
	call inicio

end sub

sub inicio()

	nome = InputBox("Olá Jogador(a), digite seu nome: ", "Início do Jogo")
	acertos = 0
	pulo = 0
	call features

end sub

sub features()

	repetir = 0
	Randomize(Second(Time))
	sorteado = int(rnd * 30)
	extenso = palavras(sorteado)
	if (acertos = 12) then
		MsgBox("Você VENCEU!" + vbNewLine & _
			   "Qtde de Acertos: " & acertos & ""), vbExclamation + vbOKOnly, "" & nome & ""
		resp = MsgBox("Deseja Jogar Novamente?", vbQuestion + vbYesNo, "" & nome & "")
		if (resp = vbyes) then
			call inicio
		else
			exit sub
		end if
	end if
	call som

end sub

sub som()

	audio.speak("" & extenso & "")
	call jogo

end sub

sub jogo()
	
	resp = LCASE(InputBox("DIGITE A PALAVRA OUVIDA" + vbNewLine & _
						  + vbNewLine & _
						  "---------------------" + vbNewLine & _
						  "[R]epetir Áudio" + vbNewLine & _
						  "[P]ular Palavra" + vbNewLine & _
						  "---------------------","" & nome & ""))
	
	if ((pulo = 1 and resp = "p") or (repetir = 1 and resp = "r")) then
	
		msgbox("OPÇÃO ESGOTADA!"), vbExclamation + vbOKOnly, "ATENÇÃO"
		call jogo

	end if
	
	if (resp = "r" and repetir = 0) then
		repetir = repetir + 1
		call som
	end if
	
	if (resp = "p" and pulo = 0) then
		pulo = pulo + 1
		call features
	end if
	
	if (LCase(resp) = extenso) then
		acertos = acertos + 1
		call features
	else
		MsgBox("Você Errou!" + vbNewLine & _
					  "Qtde de Acertos: " & acertos & ""), vbExclamation + vbOKOnly, "" & nome & ""
		resp = MsgBox("Deseja Jogar Novamente?", vbQuestion + vbYesNo, "" & nome & "")
		if (resp = vbyes) then
			call inicio
		else
			exit sub
		end if
	end if
	
end sub