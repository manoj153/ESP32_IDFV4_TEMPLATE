# WIFI ON ESP32 



### Run following command to get access to IDF toolchain to your enviroment
```
cd esp-idf/
./install.sh
. ./export.sh
```

### Then you may want to build and flash by :

```
idf.py flash
```
## Agenda

*   have ability to detect WiFi lost and reconnect
*   benchmark speed of reconnecions 
*   based on above point tweak wifi beacon frames to achieve optimum reconnection speed 