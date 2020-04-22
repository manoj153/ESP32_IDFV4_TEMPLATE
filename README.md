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

*   understand CMAKE build system 

*   have ability to detect WiFi lost and reconnect
*   benchmark speed of reconnecions 
*   based on above point tweak wifi beacon frames to achieve optimum reconnection speed


# Achieved Objectives :
## 1. Project structure

```
Components
    Network
        -WiFi
            WiFi_main.c
            WiFi_main.h
    UART
        UART_main.c
        UART_main.h
```
## 2. Basic setup of CMAKE with WiFi component

## 3. Connection connected/disconnected 


MANOJKUMAR SUBRAMANIAM