#include "ip_main.h"

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/event_groups.h"

#include "esp_system.h"
#include "esp_event.h"
#include "esp_log.h"
#include "network_global.h"


static void ip_event_handler(void* arg, esp_event_base_t event_base,
                                int32_t event_id, void* event_data)
                            
{
    if (event_base == IP_EVENT && event_id == IP_EVENT_STA_GOT_IP) 
    
    {
        ip_event_got_ip_t* event = (ip_event_got_ip_t*) event_data;
        ESP_LOGI(TAG, "got ip:%s",
                 ip4addr_ntoa(&event->ip_info.ip));
        // s_retry_num = 0;
        xEventGroupSetBits(gbl_socket_event_grp, GOT_IP_BIT); // Probably changing to STA_GOT_IP
        //Unlocks TCP_Socket layer
        //TCP Socket need to receive both AP_Connected and IP sucess to work 
    }

}

void ip_main_init()
{
    ESP_ERROR_CHECK(esp_event_handler_register(IP_EVENT, IP_EVENT_STA_GOT_IP, &ip_event_handler, NULL)); // it handles the internal loop to run handler call backs
}

void ip_main_task()
{
     


     while(1)
     {
         //for now can't think of to do in loop for ip task
         vTaskDelay(1000/portTICK_PERIOD_MS);
     }
}