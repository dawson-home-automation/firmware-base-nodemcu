#include "mqtt/mqtt_client.h"
#include "logger/smart_logger.h"

String getMacAddress();
String getIPAddress();
String macToStr(const uint8_t*);

void registerDevice(char* target){
    char body_c[200];
    String target_str(target);

    String body = "{\"ipAddress\":\"" + WiFi.localIP().toString() + "\",";
    body += "\"name\":\"" + getMacAddress() + "\",";
    body += "\"target\":\"" + target_str + "\"}";
    body.toCharArray(body_c, 200);

    publish_message("devices/registry", 1, body_c, false);
    Serial.printf("action=device_registry status=success body=%s\n", body_c);
    info("arduino_registry", "status=success");
}
