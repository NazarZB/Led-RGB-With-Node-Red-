# **Led RGB (with Node-red)**

  Ce projet permet de réaliser une LED RGB pilotée à distance via une interface web.  
  
## Vidéo 

[![video](https://img.youtube.com/vi/pIA5Q94g/0.jpg)](https://www.youtube.com/watch?v=pIA5Q94g)

## Matériels utilisés  

* [Arduino ESP32](https://www.amazon.fr/SeeKool-ESP-32S-d%C3%A9veloppement-Bluetooth-Ultra-Low/dp/B07DPP3BGZ/ref=sr_1_2_sspa?ie=UTF8&qid=1550052255&sr=8-2-spons&keywords=arduino+esp32&psc=1)

![ESP32](https://images-na.ssl-images-amazon.com/images/I/61H9-mWSrAL._SL1001_.jpg)


* [Del multicolores](https://www.amazon.fr/SODIAL-diode-electroluminescente-tete-ronde/dp/B00F4MGA0I/ref=sr_1_1?ie=UTF8&qid=1550052436&sr=8-1&keywords=led+rgb+arduino)

![Led](https://images-na.ssl-images-amazon.com/images/I/61U853WOASL._SL1000_.jpg)

## Bibliothèques utilisées  


* WiFi
* adafruit-MQTT


## Code

``` c++
#include <Adafruit_MQTT_Client.h>

WiFiClient wiFiClient;
Adafruit_MQTT_Client mqttClient(&wiFiClient, "192.168.1.106", 1883);
Adafruit_MQTT_Subscribe magentaSubscriber(&mqttClient, "/magenta");
Adafruit_MQTT_Subscribe blueSubscriber(&mqttClient, "/blue");
Adafruit_MQTT_Subscribe greenSubscriber(&mqttClient, "/green");


void magentaCallback(double x) {
  Serial.println(x);
 
    analogWrite(12, x);
;
  }

  
void blueCallback(double x) {
  Serial.println(x);

    analogWrite(27, x);

   
    
  }

  void greenCallback(double x) {
  Serial.println(x);
 
   analogWrite(14,x);
   
  
}

void setup() {
  // put your setup code here, to run once:
  
analogWrite(27, 255);
analogWrite(14,0);
analogWrite(12, 255);
Serial.begin(115200);


WiFi.begin("createch", "createch");
delay(5000);

Serial.print("IP address: ");
Serial.println(WiFi.localIP());

 magentaSubscriber.setCallback(magentaCallback);
 mqttClient.subscribe(&magentaSubscriber);

 blueSubscriber.setCallback(blueCallback);
 mqttClient.subscribe(&blueSubscriber);

 greenSubscriber.setCallback(greenCallback);
 mqttClient.subscribe(&greenSubscriber);


}

void loop() {
  

  // put your main code here, to run repeatedly:



if (mqttClient.connected()) {
    mqttClient.processPackets(10000);
    mqttClient.ping();
  } else {
    mqttClient.disconnect();
    mqttClient.connect();
  }

}

```

## Node-red 

On utilise node-red pour pouvor piloter notre Led RGB à distance 

![Nodered](https://image.noelshack.com/fichiers/2019/07/3/1550057156-screenshot-2019-02-13-node-red.png)



