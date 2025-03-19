'Calcule a ¡rea do quadrado e PerÌmetro
dim lado

call area_per
sub area_per()
	lado = cint(InputBox("Informe o Lado do Quadrado", "¡ÅREA E PERÕçMETRO"))
	MsgBox("¡Årea: " & lado * lado & "" + vbNewLine & _
		   "PerÌmetro: " & lado * 4 & ""), vbInformation + vbOKOnly, "AVISO"
end sub