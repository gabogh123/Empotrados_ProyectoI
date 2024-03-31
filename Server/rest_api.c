#include <stdio.h>
#include <string.h>
#include <microhttpd.h>

#define PORT 8888
#define IP_ADDRESS "192.168.50.180"

// Estado de las luces (0 = apagada, 1 = encendida)
static int light_states[5] = {0};

// Estado de las puertas (0 = cerrada, 1 = abierta)
static int door_states[4] = {0};

static int handler(void *cls, struct MHD_Connection *connection,
                   const char *url, const char *method, const char *version,
                   const char *upload_data, size_t *upload_data_size, void **con_cls) {
    const char *page;
    struct MHD_Response *response;
    int ret;

    // Imprimir la solicitud HTTP recibida
    printf("Received HTTP request:\n");
    printf("Method: %s\n", method);
    printf("URL: %s\n", url);
    printf("HTTP Version: %s\n", version);

    // Verificar la solicitud y ajustar el estado de las luces
    if (strcmp(method, "POST") == 0) {
        for (int i = 0; i < 5; ++i) {
            char toggle_light_url[20];
            char on_light_url[20];
            char off_light_url[20];
            sprintf(toggle_light_url, "/togglelight%d", i + 1);
            sprintf(on_light_url, "/turnonlight%d", i + 1);
            sprintf(off_light_url, "/turnofflight%d", i + 1);
            if (strcmp(url, toggle_light_url) == 0) {
                light_states[i] = !light_states[i]; // Toggle the light state
                printf("Luz %d %s\n", i + 1, light_states[i] ? "encendida" : "apagada");
            } else if (strcmp(url, on_light_url) == 0) {
                light_states[i] = 1; // Turn on the light
                printf("Luz %d encendida\n", i + 1);
            } else if (strcmp(url, off_light_url) == 0) {
                light_states[i] = 0; // Turn off the light
                printf("Luz %d apagada\n", i + 1);
            }
        }

        for (int i = 0; i < 4; ++i) {
            char toggle_door_url[20];
            char open_door_url[20];
            char close_door_url[20];
            sprintf(toggle_door_url, "/toggledoor%d", i + 1);
            sprintf(open_door_url, "/opendoor%d", i + 1);
            sprintf(close_door_url, "/closedoor%d", i + 1);
            if (strcmp(url, toggle_door_url) == 0) {
                door_states[i] = !door_states[i]; // Toggle the door state
                printf("Puerta %d %s\n", i + 1, door_states[i] ? "abierta" : "cerrada");
            } else if (strcmp(url, open_door_url) == 0) {
                door_states[i] = 1; // Open the door
                printf("Puerta %d abierta\n", i + 1);
            } else if (strcmp(url, close_door_url) == 0) {
                door_states[i] = 0; // Close the door
                printf("Puerta %d cerrada\n", i + 1);
            }
        }
    }

    // Generar la página HTML con el estado actual de las luces y puertas
    char buffer[4096];
    strcpy(buffer, "<html><body>");

    // Estado de las luces
    strcat(buffer, "<h2>Luces</h2>");
    for (int i = 0; i < 5; ++i) {
        char status[30];
        sprintf(status, "Luz %d: %s", i + 1, light_states[i] ? "Encendida" : "Apagada");
        char toggle_light_url[20];
        char button_label[20];
        if (light_states[i]) {
            sprintf(toggle_light_url, "/turnofflight%d", i + 1);
            strcpy(button_label, "Apagar Luz");
        } else {
            sprintf(toggle_light_url, "/turnonlight%d", i + 1);
            strcpy(button_label, "Encender Luz");
        }
        strcat(buffer, "<p>");
        strcat(buffer, status);
        strcat(buffer, "</p>");
        strcat(buffer, "<form method=\"post\" action=\"");
        strcat(buffer, toggle_light_url);
        strcat(buffer, "\">");
        strcat(buffer, "<input type=\"submit\" value=\"");
        strcat(buffer, button_label);
        strcat(buffer, "\">");
        strcat(buffer, "</form>");
    }

    // Estado de las puertas
    strcat(buffer, "<h2>Puertas</h2>");
    for (int i = 0; i < 4; ++i) {
        char status[30];
        sprintf(status, "Puerta %d: %s", i + 1, door_states[i] ? "Abierta" : "Cerrada");
        char toggle_door_url[20];
        char button_label[20];
        if (door_states[i]) {
            sprintf(toggle_door_url, "/closedoor%d", i + 1);
            strcpy(button_label, "Cerrar Puerta");
        } else {
            sprintf(toggle_door_url, "/opendoor%d", i + 1);
            strcpy(button_label, "Abrir Puerta");
        }
        strcat(buffer, "<p>");
        strcat(buffer, status);
        strcat(buffer, "</p>");
        strcat(buffer, "<form method=\"post\" action=\"");
        strcat(buffer, toggle_door_url);
        strcat(buffer, "\">");
        strcat(buffer, "<input type=\"submit\" value=\"");
        strcat(buffer, button_label);
        strcat(buffer, "\">");
        strcat(buffer, "</form>");
    }

    strcat(buffer, "</body></html>");

    page = strdup(buffer);

    // Enviar la respuesta HTTP con la página generada
    response = MHD_create_response_from_buffer(strlen(page), (void *)page, MHD_RESPMEM_MUST_FREE);
    ret = MHD_queue_response(connection, MHD_HTTP_OK, response);
    MHD_destroy_response(response);

    return ret;
}

int main() {
    struct MHD_Daemon *daemon;

    daemon = MHD_start_daemon(MHD_USE_SELECT_INTERNALLY, PORT, NULL, NULL,
                              &handler, NULL, MHD_OPTION_END);
    if (daemon == NULL) {
        printf("Failed to start server\n");
        return 1;
    }

    printf("Server running on %s:%d\n", IP_ADDRESS, PORT);
    getchar();

    MHD_stop_daemon(daemon);
    return 0;
}

