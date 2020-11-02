/*1. Construa um programa em linguagem C que imprima na tela o caractere ‘A’ . Em seguida
imprima o número da tabela ASCII que corresponde ao ‘A’ e depois o valor hexadecimal
que que equivale ao ‘A’ . Faz a mesma coisa para o caractere ‘a’ .
*/


2. Construa um programa em linguagem C que imprima na tela a quantidade de bytes
ocupados na memória por cada uma das variáveis a seguir:
char a ;
int b ;
float c ;
double d ;
3. Execute o programa a seguir e proponha uma breve explicação do porquê a comparação
( x==y ) retorna verdadeiro, se os valores de x e y são diferentes.
#include <stdio.h>
main()
{
float x = 10.1234567;
float y = 10.1234568;
printf("\nx = %f\ty = %f", x, y);
printf("\nsao %s", x==y ? "IGUAIS" : "dIfErEnTeS");
}
4. A equação ax 2 + bx + c = 0 é resolvida pelo método de Báskara que calcula x’ e x’’ a partir
dos valores de a , b e c . Construa um programa em linguagem C que leia do teclado os
valores para a , b , e c , depois calcule e imprima na tela os valores de x’ e x’’ .
5. Um algoritmo bastante comum é o que troca os valores entre duas variáveis como, por
exemplo, o que está apresentado a seguir:
#include <stdio.h>
main()
{
int umValor = 10, outroValor = 20;
int auxiliar;
auxiliar = umValor;
umValor = outroValor;
outroValor = auxiliar;
}
No entanto, existe um método que possibilita a troca sem a utilização de uma variável auxiliar
(apenas as variáveis umValor e outroValor são necessárias). Pesquise, descubra qual é este
método e construa um programa em linguagem C para demonstrar o seu funcionamento.
6. Um operador aritmético unário é aquele que precisa de apenas um operando para funcionar.
Exemplos comuns são os operadores de incremento ( ++ ) e decremento ( -- ). Execute o
programa a seguir e observe a diferença quando eles são posicionados antes ou depois do
operando.
#include <stdio.h>
main()
{
1int umValor, outroValor;
printf("\nO operador vai DEPOIS da variavel (umValor++):");
umValor = 10;
outroValor = umValor ++ ;
printf(" Um valor: %i\tOutro valor: %i", umValor, outroValor);
printf("\nO operador vai ANTES da variavel (++umValor):");
umValor = 10;
outroValor = ++ umValor;
printf(" Um valor: %i\tOutro valor: %i\n\n", umValor, outroValor);
}
EXERCÍCIOS PARA REVISAR COMANDOS DE SELEÇÃO
7. O restaurante LeChiqué contratou um barista para avaliar o café que é servido aos
clientes. A tarefa do barista é aprovar (ou não) o café com base em 2 critérios:
 Amargor: reprovado se for intenso (código ‘I’), aprovado em caso contrário.
 Aroma: aprovado se assemelhar-se a amêndoas (código ‘A’), nozes (código
‘N’) ou castanhas (código ‘C’), reprovado em caso contrário.
Construa um programa em linguagem C que auxilie a tarefa do barista. Deverão ser
lidos do teclado o Amargor e o Aroma de uma amostra de café e impresso na tela se
ela foi aprovada ou não.
8. Construa um programa em linguagem C que informe se um dado ano é ou não bissexto.
Obs: um ano é bissexto se ele for divisível por 400 ou se ele for divisível por 4 e não por 100.
9. Uma empresa quer verificar se um empregado está qualificado para a aposentadoria ou não.



Para estar em condições, um dos seguintes requisitos deve ser satisfeito:
Ter no mínimo 65 anos de idade.
Ter trabalhado no mínimo 30 anos.
Ter no mínimo 60 anos e ter trabalhado no mínimo 25 anos.
Com base nessas informações, construa um programa em linguagem C que leia do teclado o
ano do nascimento do empregado e também o ano que ele ingressou na empresa. Assumindo
que estamos no ano 2020
, o programa deverá imprimir na tela a idade e o tempo de
trabalho do empregado, assim como uma das duas mensagens: “Requerer Aposentadoria”
ou “NÃO Requerer Aposentadoria”.
maldito 2020!
EXERCÍCIOS PARA REVISAR COMANDOS DE REPETIÇÃO
10. Execute o programa a seguir e ache a carinha diferente. Sabendo que o problema consiste
em resolver uma equação de 1o grau, (3 x – x = 8), você acha que esta solução implementada
no programa ajuda ou atrapalha na resolução do problema? Diga o porquê?
#include <stdio.h>
main()
{
int x = -100;
while ( x ++ < 100)
printf("\nx = %i\t3x - x = %i\t%s",
x ,
3* x - x ,
((3* x - x ) == 8)?"8^)":"8^(");
}
11. Construa um programa em linguagem C que imprima na tela o valor de Y na seguinte
função: Y = 10X 2 – X/2, para X variando de -10 até +20.
212. Suponha alguém que resolveu fazer dieta para emagrecer e para isso estabeleceu uma
meta: a cada mês pretende perder 1% de seu peso inicial, ou seja, se ela inicialmente pesa
100 quilos, pretende perder 1 quilo a cada mês. Construa um programa em linguagem C
que auxilie esta pessoa a prever quanto estará pesando depois de um certo tempo. Deverá
ser lido do teclado o peso inicial da pessoa e a quantidade de meses que ela pretende
seguir a dieta. Em seguida o programa deverá imprimir seu peso final.
13. Suponha um elevador que suporta no máximo 400 quilos de carga para que funcione com
segurança. Construa um programa em linguagem C que simule o funcionamento da
entrada das pessoas neste elevador. O programa deverá ler do teclado o peso das
sucessivas pessoas que entram e avisar imediatamente quando o limite máximo de carga
for atingido ou superado. Ao final deverá ser impresso na tela a quantidade de pessoas e
o peso total de todas elas.
14. Construa um programa em linguagem C que simule o funcionamento de um cronômetro
digital que exibe em seu visor as horas (h), minutos (m) e segundos (s) no formato
hh:mm:ss. A contagem deve se iniciar em 00:00:00 e cada 60 segundos um novo
minuto deverá ser acrescido, assim como a cada 60 minutos uma nova hora deverá ser
acrescida. O programa deverá ser encerrado quando o contador de horas atingir 24. Para
uma simulação mais real a função _sleep(1000) pode ser utilizada, pois ela permite
que o tempo de um segundo (mil milissegundos) seja aguardado antes de uma nova
instrução ser executada pelo programa. Algo assim:
#include <stdlib.h>
int segundos = 0;
for(;;)
{
_sleep(1000);
printf(“%i\n”, segundos++);
}
15. A empresa Rodovias do Tietê, que administra o trecho da rodovia que liga Capivari a
Timbuktu, ganhou uma concorrência pública para a instalação de praças de pedágio e
telefones de emergência ao longo da rodovia. Os telefones de emergência serão instalados
a cada 2 quilômetros e as praças de pedágio a cada 40 quilômetros. Os telefones de
emergência somente serão instalados nos locais onde não houver praças de pedágio.
Construa um programa em linguagem C que leia do teclado a distância (em quilômetros)
entre Capivari e Timbuktu e imprima na tela todos os locais (expressos em quilômetros
de pista) onde deverão ser instalados os telefones de emergência e as praças de pedágio.
Assumir que a rodovia se inicia em Capivari no quilômetro 0 (zero).
16. Uma pessoa decidiu fazer viagens turísticas regularmente e para isso está depositando
mensalmente em uma poupança a quantia de R$ 800,00. Quando completa R$ 12.000,00
ela faz a viagem e recomeça a guardar dinheiro para a próxima viagem. Sabendo que
existem 12 meses no ano (1 a 12), construa um programa em linguagem C que informe a
pessoa em quais meses de quais anos ela poderá fazer a viagem turística no valor de R$
12.000,00. Assumir que ela começou a guardar dinheiro no mês 1 do ano de 2020 e que
ela pretende viajar pelos próximos 50 anos.

