/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package br.com.fatec;

import java.util.HashSet;
import javax.swing.JOptionPane;
/**
 *
 * @author Vitor Aurélio Saccone Mimaki
 */
public class Proprietario {
    private String nome, cpf;
    private HashSet<Veiculo> veiculos = new HashSet<>();

    public void addVeiculo(Veiculo v) {
        boolean existe = false;
        for(Veiculo veiculo : veiculos) {
            if(veiculo.getPlaca().equals(v.getPlaca())) {
                existe = true;
                break;
            }
        }
    	if(!existe) {
    		if(veiculos.size() < 5) {
                veiculos.add(v);
            } else {
                int resp;
                resp = JOptionPane.showConfirmDialog(null, 
                        "Você já possui " + veiculos.size() +
                        " veículos, deseja incluir mais este mesmo?", 
                        "Mensagem ao Usuário", JOptionPane.YES_NO_OPTION, JOptionPane.QUESTION_MESSAGE);
                if(resp == JOptionPane.YES_OPTION) {
                    veiculos.add(v);
                }
            }
    	}
    }
    
    public float valorBens() {
        
        float somatoria = 0;
     
        for (Veiculo veiculo : veiculos) {
            somatoria += veiculo.getValor();
        }
        
        return somatoria;
    }

    public boolean removeVeiculo(String placa) {
    	return this.getVeiculos().removeIf(veiculo -> veiculo.getPlaca() == placa);
    }
    
    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getCpf() {
        return cpf;
    }

    public void setCpf(String cpf) {
        this.cpf = cpf;
    }

    public HashSet<Veiculo> getVeiculos() {
        return veiculos;
    }

    public void setVeiculos(HashSet<Veiculo> veiculos) {
        this.veiculos = veiculos;
    }
}
