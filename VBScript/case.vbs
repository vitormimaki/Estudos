dim frase, selecao, resp
call escolha
sub escolha()
	selecao= cint(InputBox("[1] Verde" + vbNewLine & _
						   "[2] Amarelo" + vbNewLine & _
						   "[3] Vermelho" + vbNewLine & _
						   "[0 ou 10] Encerrar", "Cores do Semáforo"))

	select case selecao
		   case 1:
				frase = "Verde - Siga em Frente"
		   case 2:
				frase = "Amarelo - Atenção"
		   case 3:
				frase = "Vermelho - Pare"
		   case 0,10:
				resp = MsgBox("Deseja encerrar?", vbQuestion + vbYesNo, "ATENÇÃO")
				if resp = vbYes then
					wscript.quit
				else
					call escolha
				end if
			case else
				frase = "Cor Inválida!"
	end select
	msgbox(""& frase &""), vbInformation + vbOKOnly, "CORES DO SEMÁFORO"
	call escolha
end sub