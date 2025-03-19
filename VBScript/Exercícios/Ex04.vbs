Dim numeros(3), temp

call ordena()

sub ordena()
	For i = 0 To 3 step 1
		numeros(i) = cint(InputBox("Digite o número " & (i + 1) & ":", "ORDENA"))
	Next

	' Ordena os números em ordem crescente
	For i = 0 To 2 step 1
		For j = i + 1 To 3 step 1
			If numeros(i) > numeros(j) Then
				' Troca os números de posição
				temp = numeros(i)
				numeros(i) = numeros(j)
				numeros(j) = temp
			End If
		Next
	Next

	MsgBox("Números ordenados em ordem crescente: " & numeros(0) & ", " & numeros(1) & ", " & numeros(2) & ", " & numeros(3) & ""), vbInformation + vbOKOnly, "ORDENADOS"
end sub