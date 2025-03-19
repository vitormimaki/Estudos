'Entrar com 03 números inteiros quaisquer e exibir menor e maior números
dim n1,n2,n3, maior, menor, iguais

call maior_e_menor
sub maior_e_menor()

	n1 = cint(InputBox("Informe o 1° Número", "MAIOR E MENOR"))
	n2 = cint(InputBox("Informe o 2° Número", "MAIOR E MENOR"))
	n3 = cint(InputBox("Informe o 3° Número", "MAIOR E MENOR"))
	
	if n1 = n2 and n2 = n3 then
		iguais = 1
	else
		iguais = 0
		if n1 >= n2 and n1 >= n3 then
			maior = n1
			if n2 > n3 then
				menor = n3
			else
				menor = n2
			end if
		elseif n2 >= n1 and n2 >= n3 then
			maior = n2 
			if n1 > n3 then
				menor = n3
			else
				menor = n1
			end if
		elseif n3 >= n1 and n3 >= n2 then
			maior = n3
			if n2 > n1 then
				menor = n1
			else
				menor = n2
			end if
		end if
	end if
	
	if iguais = 0 then
		msgbox("O Número " & menor & " é menor!" + vbNewLine & _
			   "O Número " & maior & " é maior!"), vbInformation + vbOKOnly, "AVISO"
	else
		msgbox("SÃO IGUAIS"), vbInformation + vbOKOnly, "AVISO"
	end if
	
end sub