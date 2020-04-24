#include "network_global.h"

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/event_groups.h"


// EventGroupHandle_t gbl_socket_event_grp;

void network_global_init()
{
    gbl_socket_event_grp = xEventGroupCreate();

}