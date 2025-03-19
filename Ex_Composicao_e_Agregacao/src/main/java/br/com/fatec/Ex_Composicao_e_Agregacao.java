/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 */

package br.com.fatec;

/**
 *
 * @author Vitor Aurélio Saccone Mimaki
 */
public class Ex_Composicao_e_Agregacao {
    public static String info(Universidade universidade){
        String info;
        info = "\nUniversidade: " + universidade.getNome() + "(" + universidade.getSigla() + ")\n";
        info += "Instituto: " + universidade.getInstituto().getNomeInstituto() + "(" + universidade.getInstituto().getSiglaInstituto() + ")\n";
        if(universidade.getInstituto().getCurso().getCodCurso() != -1) {
            info += "Curso: " + universidade.getInstituto().getCurso().getNomeCurso();
            info += "\nCOD: " + universidade.getInstituto().getCurso().getCodCurso();
        } else {
            info += "Este Instituto Nao Oferece Cursos";
        }
        return info;
    }
    public static void main(String[] args) {
        Curso cu1 = new Curso("Analise e Desenvolvimento de Sistemas");
        Curso cu2 = new Curso();
        
        cu1.setCodCurso(0);
        cu2.setNomeCurso("Jogos");
        cu2.setCodCurso(1);
        
        Instituto in1 = new Instituto("Desenvolvimento", "IDD");
        Instituto in2 = new Instituto("Jogos", "IDJ");
        Instituto in3 = new Instituto("Seguranca", "IDS");
        
        in1.setCurso(cu1);
        in2.setCurso(cu2);
        
        Universidade un1 = new Universidade(in1, "FACULDADE DE TECNOLOGIA", "FATEC");
        Universidade un2 = new Universidade(in2, "UNIVERSIDADE FEDERAL DO ABC", "UFABC");
        Universidade un3 = new Universidade(in3, "INSTITUTO DE TECNOLOGIA E AERONAUTICA", "ITA");
        Universidade un4 = new Universidade(new Instituto("JOGOS", "JG"), "INSTITUTOS DE JOGOS", "JOG");
        
        System.out.println(info(un1));
        System.out.println(info(un2));
        System.out.println(info(un3));
        System.out.println(info(un4));
    }
}

