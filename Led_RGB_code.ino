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

