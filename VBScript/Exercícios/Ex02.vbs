'Calcule a �rea do quadrado e Per�metro
dim lado

call area_per
sub area_per()
	lado = cint(InputBox("Informe o Lado do Quadrado", "��REA E PER͍METRO"))
	MsgBox("��rea: " & lado * lado & "" + vbNewLine & _
		   "Per�metro: " & lado * 4 & ""), vbInformation + vbOKOnly, "AVISO"
end sub