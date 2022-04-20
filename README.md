# Mecanismos de controle da seção crítica
### Professores: Álvaro e Denise

<br>

Três atividades foram desenvolvidas:

## 1. Seção Crítica por espera ocupada
A presente atividade tem como objetivo implementar o algoritmo de *Manna-Pnueli* que implementa entrada em SC por algoritmo Cliente-Servidor. 

* A linguagem escolhida para realizar o trabalho foi **C**.

* A biblioteca escolhida foi *OpenMP*

### Testes
Nos testes a seção crítica foi executada inúmeras vezes pelos processos clientes. 
Considerou-se a variável **SOMA** como global/compartilhada e utilizou-se o seguinte trecho de
código:
```
{
    int local = SOMA;
    sleep(rand()%2);
    SOMA = local + 1;
}
```

### Resultados 
Para provar que a seção crítica no código implementado de fato funciona, realizou-se um teste em dois códigos, onde o primeiro não implementa controle de seção crítica nos processos clientes e o segundo faz a correta implementação da seção crítica nos processos clientes.

<br>

## 2. Somatórias, seção crítica e reduções em OpenMP
Utilizado o código referente ao *"Jogo da Vida"* já desenvolvido anteriormente, modificou-se o trecho de código que realiza a somatória de todas as posições da
última geração do tabuleiro (soma a quantidade total de células vivas no tabuleiro),
desenvolvendo três versões:
* Utilizando a diretiva *__#pragma omp critical__* realizou-se a operação entre as
threads, totalizando os resultados em uma variável global ao final;
* Utilizando uma operação de redução através da diretiva *__#pragma omp for reduction(???)__* realizou-se a mesma operação.
* Criou-se uma versão desse trecho do código onde não foi utilizado nenhuma das soluções acima ou outro recurso do OpenMP baseado em diretivas e
cláusulas para realizar a somatória, somente recursos usuais de programação da linguagem C.
### Resultados
Verificou-se o desempenho apenas desse trecho do código para as três
versões, avaliando tempo de processamento do trecho e speedup ao se variar a quantidade
de threads em 1, 2, 4 e 8 threads.

<br>

## 3. Seção crítica em Java
Foi considerado o programa disponibilizado pelos professores em Java que implementa uma simulação de uma via de mão
dupla, onde carros vêm em ambos os sentidos (direita e esquerda). 

### Problema
Os carros vindos das duas direções têm que passar por uma ponte, onde somente entra um carro por vez (tanto vindo da direita ou esquerda). É necessário um controle, senão haverá colisões.
![](/Media/problema.gif)


### Solução
Implementação de um mecanismo de seção crítica que permita evitar colisões dos carros sobre a ponte de via única. 

Há várias possibilidades para realizar essa implementação, entretanto escolhemos implementar um **semáforo** para controlar o tráfego.
![](/Media/solucao.gif)
