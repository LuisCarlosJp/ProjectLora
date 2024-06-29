
# Smart Home com RaspberryPI e ESP32

<img src="https://github.com/LuisCarlosJp/Smart_Home_com_RaspberryPI_e_ESP32/assets/95140960/e6ece513-bd09-40e7-8583-841476966509" width="50%" height="50%"/>

Este projeto visa criar um sistema de monitoramento inteligente utilizando tecnologias IoT para capturar e visualizar dados meteorológicos em tempo real.

<img src="https://github.com/LuisCarlosJp/Smart_Home_com_RaspberryPI_e_ESP32/assets/95140960/d0fe2f30-0ac8-4323-bad4-acbc4ffbf8f8" width="50%" height="50%"/>


## Funcionalidades Principais

- **Captura de Dados Meteorológicos**: Utiliza o sensor BMP280 para medir temperatura e pressão atmosférica, fornecendo informações precisas sobre as condições ambientais.
  
- **Transmissão Sem Fio**: Os dados são enviados sem fio para um gateway baseado em ESP32, que os encaminha para um servidor central hospedado em um Raspberry Pi.

- **Armazenamento e Visualização**: Os dados são armazenados em um banco de dados InfluxDB. A visualização em tempo real é realizada através do Grafana, proporcionando gráficos e dashboards interativos.

- **Automação e Integração**: Node-RED é utilizado para a integração dos dispositivos IoT e automação de processos, como por exemplo enviar alertas para whatsapp e telegram quando determinando evento ocorre.

- **Aplicativo**: Controle e monitorimentos dos sensores via MQTT.

Para configurar e executar este projeto, consulte nossa [Wiki](https://github.com/LuisCarlosJp/Smart_Home_com_RaspberryPI_e_ESP32/wiki) para obter instruções detalhadas sobre.



