/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 */

package br.com.fatec;


/**
 *
 * @author Vitor Aurélio Saccone Mimaki
 */
public class Principal {

	public static void exibeVeiculosFor(Proprietario p) {
            System.out.println("Proprietário: " + p.getNome());
            for(Veiculo v : p.getVeiculos()){
                System.out.println("Placa: " + v.getPlaca());
                System.out.println("Valor: " + v.getValor());
                System.out.println("============================================");
            }
	}
	
	public static void exibeVeiculosLambda(Proprietario p) {
            System.out.println("Proprietário: " + p.getNome());
            p.getVeiculos().forEach(veiculo -> {
		System.out.println("Placa: " + veiculo.getPlaca());
	        System.out.println("Valor: " + veiculo.getValor());
	        System.out.println("============================================");
		}
            );
	}
	
    public static void main(String[] args) {
        Proprietario p = new Proprietario();
        
        p.addVeiculo(new Veiculo("ABC", 10000));
        p.addVeiculo(new Veiculo("ABC", 90000));
        p.addVeiculo(new Veiculo("DEF", 20000));
        p.addVeiculo(new Veiculo("GHI", 30000));
        p.addVeiculo(new Veiculo("JKL", 40000));
        p.addVeiculo(new Veiculo("MNO", 50000));
        p.addVeiculo(new Veiculo("PQR", 60000));
        
        p.setNome("Vitor Mimaki");
        
        System.out.println("\t\tEnhanced For:");
        exibeVeiculosFor(p);
        
        System.out.println("\t\tExpressão Lambda:");
        exibeVeiculosLambda(p);
        
        System.out.println("O total dos bens é R$ " + p.valorBens());
    }
}
