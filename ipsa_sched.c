#include <stdio.h>
#include <time.h>

#include "FreeRTOS.h"
#include "task.h"
#include "ipsa_sched.h"

// Déclaration de la fonction de la tâche
static void vTask1(void *pvParameters);
static void vTask2(void *pvParameters);
static void vTask3(void *pvParameters);
static void vTask4(void *pvParameters);
/*-----------------------------------------------------------*/
void ipsa_sched() {
    xTaskCreate(
        vTask1,               // Pointeur sur la fonction de la tâche
        "Tache 1",              // Nom de la tâche 
        configMINIMAL_STACK_SIZE,    // Taille de la pile
        NULL,                        // Paramètre de la tâche
        tskIDLE_PRIORITY + 3,        // Priorité de la tâche
        NULL                         // Handle de la tâche
    );
    
    xTaskCreate(
        vTask2,                // Pointeur sur la fonction de la tâche
        "Tache 2",               // Nom de la tâche pour le débogage
        configMINIMAL_STACK_SIZE,     // Taille de la pile
        NULL,                         // Paramètre de la tâche
        tskIDLE_PRIORITY + 2,         // Priorité de la tâche
        NULL                          // Handle de la tâche
    );

    xTaskCreate(
        vTask3,                // Pointeur sur la fonction de la tâche
        "Tache 3",               // Nom de la tâche pour le débogage
        configMINIMAL_STACK_SIZE,     // Taille de la pile
        NULL,                         // Paramètre de la tâche
        tskIDLE_PRIORITY + 1,         // Priorité de la tâche
        NULL                          // Handle de la tâche
    );

    xTaskCreate(
        vTask4,                // Pointeur sur la fonction de la tâche
        "Tache 4",               // Nom de la tâche pour le débogage
        configMINIMAL_STACK_SIZE,     // Taille de la pile
        NULL,                         // Paramètre de la tâche
        tskIDLE_PRIORITY,         // Priorité de la tâche
        NULL                          // Handle de la tâche
    );
    
    vTaskStartScheduler();
}


static void vTask1(void *pvParameters) {
    const TickType_t xDelay = pdMS_TO_TICKS(900); // Période de 560ms
    for( ; ; ) {
        printf("Working\n");
        vTaskDelay(xDelay); // Attendre pour la prochaine exécution
    }
}


static void vTask2(void *pvParameters) {
    const TickType_t xDelay = pdMS_TO_TICKS(710); // Période de 710ms
    const float temp_f = 90.2;
    float temp_c;
    temp_c = (temp_f - 32)/1.8;
    for( ; ; ) {
        temp_c = (temp_f - 32)/1.8;
        printf("%f Fahrenheit = %f Celsius\n",temp_f, temp_c);
        vTaskDelay(xDelay); // Attendre pour la prochaine exécution
    }
}

static void vTask3(void *pvParameters) {
    const TickType_t xDelay = pdMS_TO_TICKS(820); // Période de 820ms
    unsigned long x1 = 4234476;
    unsigned long x2 = 8849989;
    unsigned long y;
    for( ; ; ) {
        y = x1*x2;
        printf("%ld x %ld = %ld\n", x1, x2, y);
        vTaskDelay(xDelay); // Attendre pour la prochaine exécution
    }
}

static void vTask4(void *pvParameters) {
    const TickType_t xDelay = pdMS_TO_TICKS(1170); // Période de 1170ms
    int L[50] = {4, 26, 57, 76, 81, 93, 96, 107, 118, 148, 151, 161, 178, 180, 200, 218, 252, 263, 273, 298, 322, 327, 363, 375, 412, 440, 451, 471, 489, 500, 503, 526, 557, 574, 592, 611, 621, 633, 651, 675, 696, 698, 701, 719, 742, 766, 778, 786, 817};
    int valeur_cherche = 701;
    int a = 0;
    int b = 49;
    int milieu = 0;
    int trouve = 0;
    for( ; ; ) 
    {

        while(trouve == 0 && a <= b)
        {
            milieu = (a + b)/2;
            if(L[milieu] == valeur_cherche)
            {
                trouve = 1;
            }
            else
            {
                if(valeur_cherche > L[milieu])
                {
                    a = milieu + 1;
                }
                else
                {
                    b = milieu - 1;
                }
            }
        }

        if(trouve == 1)
        {
            printf("La valeur cherche est a la position %d\n", milieu);
        }
        else
        {
            printf("La valeur cherche n'est pas dans le tableau\n");
        }
    
    vTaskDelay(xDelay); // Attendre pour la prochaine exécution
    }
}