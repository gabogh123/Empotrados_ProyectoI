#include <stdio.h>
#include <string.h>
#include <microhttpd.h>
#include <stdlib.h>
#include <unistd.h>

#define PORT 8888
#define IP_ADDRESS "192.168.50.266"
#define LIGHT_PIN_1 0  // Pin GPIO para la luz 1 (17)
#define LIGHT_PIN_2 1  // Pin GPIO para la luz 2 (18)
#define LIGHT_PIN_3 2  // Pin GPIO para la luz 3 (27)
#define LIGHT_PIN_4 3  // Pin GPIO para la luz 4 (22)
#define LIGHT_PIN_5 4  // Pin GPIO para la luz 5 (23)

// Estado de las luces (0 = apagada, 1 = encendida)
static int light_state1 = 0;
static int light_state2 = 0;
static int light_state3 = 0;
static int light_state4 = 0;
static int light_state5 = 0;

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
        if (strcmp(url, "/encenderluz1") == 0) {
            light_state1 = 1; // Encender la luz 1
            printf("Luz 1 encendida\n");
        } else if (strcmp(url, "/apagarluz1") == 0) {
            light_state1 = 0; // Apagar la luz 1
            printf("Luz 1 apagada\n");
        } else if (strcmp(url, "/encenderluz2") == 0) {
            light_state2 = 1; // Encender la luz 2
            printf("Luz 2 encendida\n");
        } else if (strcmp(url, "/apagarluz2") == 0) {
            light_state2 = 0; // Apagar la luz 2
            printf("Luz 2 apagada\n");
        } else if (strcmp(url, "/encenderluz3") == 0) {
            light_state3 = 1; // Encender la luz 3
            printf("Luz 3 encendida\n");
        } else if (strcmp(url, "/apagarluz3") == 0) {
            light_state3 = 0; // Apagar la luz 3
            printf("Luz 3 apagada\n");
        } else if (strcmp(url, "/encenderluz4") == 0) {
            light_state4 = 1; // Encender la luz 4
            printf("Luz 4 encendida\n");
        } else if (strcmp(url, "/apagarluz4") == 0) {
            light_state4 = 0; // Apagar la luz 4
            printf("Luz 4 apagada\n");
        } else if (strcmp(url, "/encenderluz5") == 0) {
            light_state5 = 1; // Encender la luz 5
            printf("Luz 5 encendida\n");
        } else if (strcmp(url, "/apagarluz5") == 0) {
            light_state5 = 0; // Apagar la luz 5
            printf("Luz 5 apagada\n");
        } else if (strcmp(url, "/capturarimagen") == 0) {
            printf("Capturando imagen\n");
            system("fswebcam -r 640x480 --jpeg 85 -D 1 capture.jpg"); // Captura la imagen con fswebcam
            printf("Imagen capturada\n");
        }
    }

    // Generar la página HTML con el estado actual de las luces y el botón de captura de imagen
    char buffer[4096];
    sprintf(buffer, "<html><body><h1>Luz 1</h1><p>Estado: %s</p><form method=\"post\" action=\"/encenderluz1\"><input type=\"submit\" value=\"Encender Luz 1\"></form><form method=\"post\" action=\"/apagarluz1\"><input type=\"submit\" value=\"Apagar Luz 1\"></form><h1>Luz 2</h1><p>Estado: %s</p><form method=\"post\" action=\"/encenderluz2\"><input type=\"submit\" value=\"Encender Luz 2\"></form><form method=\"post\" action=\"/apagarluz2\"><input type=\"submit\" value=\"Apagar Luz 2\"></form><h1>Luz 3</h1><p>Estado: %s</p><form method=\"post\" action=\"/encenderluz3\"><input type=\"submit\" value=\"Encender Luz 3\"></form><form method=\"post\" action=\"/apagarluz3\"><input type=\"submit\" value=\"Apagar Luz 3\"></form><h1>Luz 4</h1><p>Estado: %s</p><form method=\"post\" action=\"/encenderluz4\"><input type=\"submit\" value=\"Encender Luz 4\"></form><form method=\"post\" action=\"/apagarluz4\"><input type=\"submit\" value=\"Apagar Luz 4\"></form><h1>Luz 5</h1><p>Estado: %s</p><form method=\"post\" action=\"/encenderluz5\"><input type=\"submit\" value=\"Encender Luz 5\"></form><form method=\"post\" action=\"/apagarluz5\"><input type=\"submit\" value=\"Apagar Luz 5\"></form><h1>Capturar Imagen</h1><form method=\"post\" action=\"/capturarimagen\"><input type=\"submit\" value=\"Capturar\"></form></body></html>",
            light_state1 ? "Encendida" : "Apagada", light_state2 ? "Encendida" : "Apagada", light_state3 ? "Encendida" : "Apagada", light_state4 ? "Encendida" : "Apagada", light_state5 ? "Encendida" : "Apagada");

    page = strdup(buffer);

    // Enviar la respuesta HTTP con la página generada
    response = MHD_create_response_from_buffer(strlen(page), (void *)page, MHD_RESPMEM_MUST_FREE);
    ret = MHD_queue_response(connection, MHD_HTTP_OK, response);
    MHD_destroy_response(response);

    return ret;
}

int main() {
    if (wiringPiSetup() == -1) {
        printf("Failed to initialize WiringPi\n");
        return 1;
    }

    // Configurar los pines de las luces como salida
    pinMode(LIGHT_PIN_1, OUTPUT);
    pinMode(LIGHT_PIN_2, OUTPUT);
    pinMode(LIGHT_PIN_3, OUTPUT);
    pinMode(LIGHT_PIN_4, OUTPUT);
    pinMode(LIGHT_PIN_5, OUTPUT);

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

