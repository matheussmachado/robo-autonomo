# SOBRE
Este diretório é destinado as funções/operações básicas para o robô, como funções para lidar com a locomoção de rodas através de motores dc, sensoriamento de obstáculos apartir de sensor ultrassônico e utilização de servo motor para girar o sensor durante as medições laterais.

## O arquivo operacoes.h:
Este arquivo de cabeçalho (header) define todas as portas de conexões com o hardware, bem como outras centraliza definições gerais utilizadas em todas as camadas desse projeto. Além disso, esse arquivo é utilizado para declarar todas as funções que serão utilizadas pelas camadas de funções intermediárias e função principal, no arquivo src/main.cpp. Desta forma, esse header serve como uma interface para as outras camadas. 