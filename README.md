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

* Deciding architecture and refactor network stack (Socket & WiFi)

- To decide :

    1. To isolate WiFi , IP, and Socket codes 
        - wifi takes care only wifi
        - IP handles to set dhcp or static
        - Socket handles TCP connections

- Decisions based on review by Manoj :
    
    1.

- Flow of network routine since boot up :
    
    1.Get credential

    2.Connect with the credential

    3.Once connected inform IP stack wifi is ready

    4.IP layer wakes up and decide static or dhcp
        
         IF (DHCP) wait for lease and inform TCP stack ready

         ELSE(STATIC) set ip addr and inform TCP stack ready  

    5. TCP stack get ready signal from #4 and will try to bind to a socket with server **IP addr** and **server port** 

    6. TCP stack inform application that it's ready to TX and RX 

* In the event of wifi related failure will inform TCP stack to stop TX and RX

* In the event of socket failure but wifi connection is alive the socket will try to bind again and again until a sucess binding acheieved 
- Must handle what ever connection related matters
- Required API

    1. wifi_init()
    2. wifi_deinit()
    3. wifi_connect(ssid,password)
    4. wifi_disconnect()

- Required Task
    1.
*/

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

## 3. Connection connected/disconnected detection




MANOJKUMAR SUBRAMANIAM