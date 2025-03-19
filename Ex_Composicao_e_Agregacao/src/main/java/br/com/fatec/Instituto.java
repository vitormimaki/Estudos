/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package br.com.fatec;

/**
 *
 * @author Vitor Aurélio Saccone Mimaki
 */
public class Instituto {
    private String siglaInstituto;
    private String nomeInstituto;
    private Curso curso;
    
    public Instituto() {}
    
    public Instituto(String nome, String sigla) {
        this.curso = new Curso();
        this.curso.setCodCurso(-1);
        this.nomeInstituto = nome;
        this.siglaInstituto = sigla;
    }

    public String getSiglaInstituto() {
        return siglaInstituto;
    }

    public void setSiglaInstituto(String siglaInstituto) {
        this.siglaInstituto = siglaInstituto;
    }

    public String getNomeInstituto() {
        return nomeInstituto;
    }

    public void setNomeInstituto(String nomeInstituto) {
        this.nomeInstituto = nomeInstituto;
    }

    public Curso getCurso() {
        return curso;
    }

    public void setCurso(Curso curso) {
        this.curso = curso;
    } 
}
