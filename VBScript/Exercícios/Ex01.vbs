'Entrar com um número inteiro e exibir números antecesspr e sucessor
dim num

call exibir

sub exibir()
	num = cint(InputBox("Informe um Número inteiro: ", "ANTECESSOR E SUCESSOR"))
	msgbox("Número Antecessor: " & num - 1 & "" + vbNewLine & _
		   "Número Sucessor:  " & num + 1 & ""), vbInformation + vbOKOnly, "AVISO"
end sub