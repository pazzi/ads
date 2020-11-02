/*14. Construa um programa em linguagem C que simule o funcionamento de um cronômetro
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
*/

