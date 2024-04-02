#include <stdio.h>
#include <string.h>
#include <microhttpd.h>
#include <wiringPi.h>


#define PORT 8888
#define IP_ADDRESS "192.168.50.226"
#define PIN1 0   // Pin GPIO para la luz 1 (17)
#define PIN2 1   // Pin GPIO para la luz 2 (18)
#define PIN3 2   // Pin GPIO para la luz 3 (27)
#define PIN4 3   // Pin GPIO para la luz 4 (22)
#define PIN5 4   // Pin GPIO para la luz 5 (
#define PIN21  21   // Pin GPIO para la puerta 1 (24)
#define PIN22  22  // Pin GPIO para la puerta 2 (25)
#define PIN23  23  // Pin GPIO para la puerta 3 (4)
#define PIN24  24  // Pin GPIO para la puerta 4 (2)

// Estado de las luces (0 = apagada, 1 = encendida)
static int light_state1 = 0;
static int light_state2 = 0;
static int light_state3 = 0;
static int light_state4 = 0;
static int light_state5 = 0;
// Estado de las puertas (0 = cerrada, 1 = abierta)
static int door_state1 = 0;
static int door_state2 = 0;
static int door_state3 = 0;
static int door_state4 = 0;

static char imgur_link[256] = ""; // Variable para almacenar el enlace de la imagen

void read_led_states() {
    FILE *file = fopen("led_states.txt", "r");
    if (file != NULL) {
        int result = fscanf(file, "%d %d %d %d %d", &light_state1, &light_state2, &light_state3, &light_state4, &light_state5);
        if (result == 5) {
            digitalWrite(PIN1, light_state1);
            digitalWrite(PIN2, light_state2);
            digitalWrite(PIN3, light_state3);
            digitalWrite(PIN4, light_state4);
            digitalWrite(PIN5, light_state5);
        } else {
            printf("Error: No se pudo leer el estado de las luces correctamente.\n");
        }
        fclose(file);
    } else {
        printf("Error: No se pudo abrir el archivo de estados de las luces.\n");
    }
}

void read_door_states() {
    FILE *file = fopen("doors_states.txt", "r");
    if (file != NULL) {
        int result = fscanf(file, "%d %d %d %d", &door_state1, &door_state2, &door_state3, &door_state4);
        if (result == 4) {
            digitalWrite(PIN21, door_state1);
            digitalWrite(PIN22, door_state2);
            digitalWrite(PIN23, door_state3);
            digitalWrite(PIN24, door_state4);
        } else {
            printf("Error: No se pudo leer el estado de las puertas correctamente.\n");
        }
        fclose(file);
    } else {
        printf("Error: No se pudo abrir el archivo de estados de las puertas.\n");
    }
}


void save_led_states() {
    FILE *file = fopen("led_states.txt", "w");
    if (file != NULL) {
        fprintf(file, "%d %d %d %d %d\n", light_state1, light_state2, light_state3, light_state4, light_state5);
        fclose(file);
    }
}

void save_door_states() {
    FILE *file = fopen("doors_states.txt", "w");
    if (file != NULL) {
        fprintf(file, "%d %d %d %d %d\n", door_state1, door_state2, door_state3, door_state4);
        fclose(file);
    }
}


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
        if (strcmp(url, "/luz1") == 0) {
           if(light_state1 == 0){
                light_state1 = 1;
                printf("Luz 1 encendida\n");
                digitalWrite(PIN1, HIGH);
                }
           else{
                printf("Luz 1 apagada");
                light_state1 = 0;
                digitalWrite(PIN1, LOW);
                }
        } else if(strcmp(url, "/luz2") == 0) {
            if(light_state2 == 0){
                light_state2 = 1;
                printf("Luz 2 encendida\n");
                digitalWrite(PIN2, HIGH);
                }
            else{
                printf("Luz 2 apagada");
                light_state2 = 0;
                digitalWrite(PIN2, LOW);
            }
        } else if (strcmp(url, "/luz3") == 0) {
            if(light_state3 == 0){
                light_state3 = 1;
                printf("Luz 3 encendida\n");
                digitalWrite(PIN3, HIGH);
                }
            else{
                printf("Luz 3 apagada");
                light_state3 = 0;
                digitalWrite(PIN3, LOW);            
            }
        } else if(strcmp(url, "/luz4") == 0) {
            if(light_state4 == 0){
                light_state4 = 1;
                printf("Luz 4 encendida\n");
                digitalWrite(PIN4, HIGH);
                }
            else{
                printf("Luz 4 apagada");
                light_state4 = 0;
                digitalWrite(PIN4, LOW);
            }
        } else if(strcmp(url, "/luz5") == 0) {
           if(light_state5 == 0){
                light_state5 = 1;
                printf("Luz 5 encendida\n");
                digitalWrite(PIN5, HIGH);
                }
           else{
                printf("Luz 5 apagada");
                light_state5 = 0;
                digitalWrite(PIN5, LOW);            
           }
        } else if(strcmp(url, "/abrirpuerta1") == 0){
		int door1 = digitalRead(PIN21);
		printf("Estado del pin: %d\n", door1);
		if(door1 == 0){
		door_state1 = 0;
		}else{
		door_state1 = 1;
		}
	  }else if(strcmp(url, "/abrirpuerta2") == 0){
                int door2 = digitalRead(PIN22);
                printf("Estado del pin: %d\n", door2);
                if(door2 == 0){
                door_state2 = 0;
                }else{
                door_state2 = 1;
                }

	} else if(strcmp(url, "/abrirpuerta3") == 0){
                int door3 = digitalRead(PIN23);
                printf("Estado del pin: %d\n", door3);
                if(door3 == 0){
                door_state3 = 0;
                }else{
                door_state3 = 1;
                }
	} else if(strcmp(url, "/abrirpuerta14") == 0){
                int door4 = digitalRead(PIN24);
                printf("Estado del pin: %d\n", door4);
                if(door4 == 0){
                door_state4 = 0;
                }else{
                door_state4 = 1;
                }
	} else if (strcmp(url, "/picture") == 0) {
                printf("Capturando imagen\n");
                system("fswebcam -r 640x480 --jpeg 85 -D 1 capture.jpg"); // Captura la imagen con fswebcam
                printf("Imagen capturada\n"); 

		 //Subir la imagen a Imgur utilizando curl
        	system("curl -H 'Authorization: Client-ID b50f7ce78eda865' -F 'image=@capture.jpg' https://api.imgur.com/3/image"); 
        	printf("Imagen subida a Imgur\n");
           	//Verificar el método HTTP y realizar la acción correspondiente
	}
  }
        save_led_states();
        save_door_states();


    // Generar la página HTML con el estado actual de las luces y las puertas
    char buffer[4096];
    sprintf(buffer, "<html><body><h1>Luz 1</h1><p>Estado: %s</p><form method=\"post\" action=\"/luz1\"><input type=\"submit\" value=\"Encender Luz 1\"></form><form method=\"post\" action=\"/luz1\"><input type=\"submit\" value=\"Apagar Luz 1\"></form><h1>Luz 2</h1><p>Estado: %s</p><form method=\"post\" action=\"/luz2\"><input type=\"submit\" value=\"Encender Luz 2\"></form><form method=\"post\" action=\"/luz2\"><input type=\"submit\" value=\"Apagar Luz 2\"></form><h1>Luz 3</h1><p>Estado: %s</p><form method=\"post\" action=\"/luz3\"><input type=\"submit\" value=\"Encender Luz 3\"></form><form method=\"post\" action=\"/luz3\"><input type=\"submit\" value=\"Apagar Luz 3\"></form><h1>Luz 4</h1><p>Estado: %s</p><form method=\"post\" action=\"/luz4\"><input type=\"submit\" value=\"Encender Luz 4\"></form><form method=\"post\" action=\"/luz4\"><input type=\"submit\" value=\"Apagar Luz 4\"></form><h1>Luz 5</h1><p>Estado: %s</p><form method=\"post\" action=\"/luz5\"><input type=\"submit\" value=\"Encender Luz 5\"></form><form method=\"post\" action=\"/luz5\"><input type=\"submit\" value=\"Apagar Luz 5\"></form><h1>Puerta 1</h1><p>Estado: %s</p><form method=\"post\" action=\"/abrirpuerta1\"><input type=\"submit\" value=\"Abrir Puerta 1\"></form><form method=\"post\" action=\"/cerrarpuerta1\"><input type=\"submit\" value=\"Cerrar Puerta 1\"></form><h1>Puerta 2</h1><p>Estado: %s</p><form method=\"post\" action=\"/abrirpuerta2\"><input type=\"submit\" value=\"Abrir Puerta 2\"></form><form method=\"post\" action=\"/cerrarpuerta2\"><input type=\"submit\" value=\"Cerrar Puerta 2\"></form><h1>Puerta 3</h1><p>Estado: %s</p><form method=\"post\" action=\"/abrirpuerta3\"><input type=\"submit\" value=\"Abrir Puerta 3\"></form><form method=\"post\" action=\"/cerrarpuerta3\"><input type=\"submit\" value=\"Cerrar Puerta 3\"></form><h1>Puerta 4</h1><p>Estado: %s</p><form method=\"post\" action=\"/abrirpuerta4\"><input type=\"submit\" value=\"Abrir Puerta 4\"></form><form method=\"post\" action=\"/cerrarpuerta4\"><input type=\"submit\" value=\"Cerrar Puerta 4\"></form><h2>Imagen subida exitosamente a Imgur</h2>'%s'></body></html>",
            light_state1 ? "Encendida" : "Apagada", light_state2 ? "Encendida" : "Apagada", light_state3 ? "Encendida" : "Apagada", light_state4 ? "Encendida" : "Apagada", light_state5 ? "Encendida" : "Apagada", door_state1 ? "Abierta" : "Cerrada", door_state2 ? "Abierta" : "Cerrada", door_state3 ? "Abierta" : "Cerrada", door_state4 ? "Abierta" : "Cerrada");

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

    // Configurar los pines de las luces y las puertas como salida
    pinMode(PIN1, OUTPUT);
    pinMode(PIN2, OUTPUT);
    pinMode(PIN3, OUTPUT);
    pinMode(PIN4, OUTPUT);
    pinMode(PIN5, OUTPUT);
    pinMode(PIN21, INPUT);
    pinMode(PIN22, INPUT);
    pinMode(PIN23, INPUT);
    pinMode(PIN24, INPUT);

    read_led_states();
    read_door_states();

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
