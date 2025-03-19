dim nome(6), n, i
call sorteio
sub sorteio()
	'i = i
	'do while i <= 10
	for i = 1 to 10 step 1 'De um em Um, regressivo coloca - na frente
		nome(1) = "Arthur"
		nome(2) = "Álvaro"
		nome(3) = "Eduardo"
		nome(4) = "Giancarlo"
		nome(5) = "Jeferson"
		nome(6) = "Vitor"
		Randomize(Second(Time)) 'Torna o Sorteio Dinamico Baseado no SO segundos da hora
		n = int(rnd * 6) + 1 'Sorteia de 1 a 6 excluindo 0
		msgbox(nome(n)), vbInformation + vbOKOnly, "Qtde Sorteio: " & i & ""
	next
		'i=i+1
	'loop
	msgbox("Fim do Sorteio!"), vbInformation + vbOKOnly, "AVISO"
end sub