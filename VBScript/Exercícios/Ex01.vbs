'Entrar com um n�mero inteiro e exibir n�meros antecesspr e sucessor
dim num

call exibir

sub exibir()
	num = cint(InputBox("Informe um N�mero inteiro: ", "ANTECESSOR E SUCESSOR"))
	msgbox("N�mero Antecessor: " & num - 1 & "" + vbNewLine & _
		   "N�mero Sucessor:  " & num + 1 & ""), vbInformation + vbOKOnly, "AVISO"
end sub