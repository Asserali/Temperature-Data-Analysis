#include <stdio.h>
#include <string.h>

void addTemperature(FILE *file); //prototypes for functions
int getHighestTemperature(FILE *file);
int getLowestTemperature(FILE *file);
float getAverageTemperature(FILE *file);
void showvalues(FILE *file);
void trends(FILE *file);

int main() {
    FILE *file;
    char filename[100];
    char choice;
    int highestTemp, lowestTemp;
    float averageTemp;

    printf("Enter the filename to access data: ");
    scanf("%s", filename);

    file = fopen(filename, "a+");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    fseek(file, 0, 2);
    if (ftell(file) == 0){ //Ftell checks the size of file
        printf("No temperature data found. Creating new file.\n");
        fclose(file);
        printf("Your file's name is %s", filename);
        file = fopen(filename, "w+"); // w+ create file with reading and writing
        if (file == NULL) {
            printf("Error creating file.\n");
            return 1;
        }
    } else {
        showvalues(file);
    }
    printf("\n");

    do {
        printf("\nMenu:\n");
        printf("1. Add temperature\n");
        printf("2. Get highest temperature\n");
        printf("3. Get lowest temperature\n");
        printf("4. Get average temperature\n");
        printf("5. RE Show temperature Values\n");
        printf("6. Show temperature trends\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");

        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                addTemperature(file);
                break;
            case '2':
                highestTemp = getHighestTemperature(file);
                printf("Highest temperature is: %d °C \n", highestTemp);
                break;
            case '3':
                lowestTemp = getLowestTemperature(file);
                printf("Lowest temperature is: %d °C \n", lowestTemp);
                break;
            case '4':
                averageTemp = getAverageTemperature(file);
                if(averageTemp==0){printf("No Temperature Data found...");
                break;}else{
                printf("Average temperature is: %.2f °C \n", averageTemp);}
                break;
            case '5':
                printf("\n");
                showvalues(file);
                break;
            case '6':
                trends(file);
                break;
            case '0':
                printf("Exiting.\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (choice != '0');

    fclose(file);

    return 0;
}
void trends(FILE *file) {
    rewind(file);
    int temp, prevTemp;
    int increasing = 1, decreasing = 1, first = 1;

    while (fscanf(file, "%d", &temp) == 1) {
        if (first) {
            first = 0;
        } else {

            if (temp > prevTemp) {
                decreasing = 0;
            } else if (temp < prevTemp) {
                increasing = 0;
            }
        }
        prevTemp = temp;
    }


    if (increasing) {
        printf("Temperature trend: Increasing\n");
    } else if (decreasing) {
        printf("Temperature trend: Decreasing\n");
    } else {
        printf("Temperature trend: Fluctuating\n");
    }
}
void showvalues(FILE *file) {
    rewind(file);
    printf("Temperature data:\n");
    int temp;
    while (fscanf(file, "%d", &temp) == 1) {
        printf("%d ", temp);
    }
    printf("\n");
}

void addTemperature(FILE *file) {
    int temp;
    int slctn;

    while (1) {  // Infinite loop
        printf("Enter temperature: ");
        scanf("%d", &temp);

        if (temp >= -100 && temp <= 100) { // Check temp
            fprintf(file, "%d ", temp);

            printf("Temperature added successfully.\n");
            printf("Add another value?\nPress 1 to continue\nPress 0 to stop\n");
            scanf("%d", &slctn);
            if (slctn == 1) {
                continue;
            } else if (slctn == 0) {
                break;
            }
        } else {
            printf("Invalid temperature. Please enter a value between -100 and 100.\n");
        }
    }
}

int getHighestTemperature(FILE *file) {
    rewind(file);
    int highest = -101; // Set initial value lower than possible temperature
    int temp;
    while (fscanf(file, "%d", &temp) == 1) {
        if (temp > highest) {
            highest = temp;
        }
    }
    return highest;
}

int getLowestTemperature(FILE *file) {
    rewind(file);
    int lowest = 101; // Set initial value higher than possible temperature
    int temp;
    while (fscanf(file, "%d", &temp) == 1) {
        if (temp < lowest) {
            lowest = temp;
        }
    }
    return lowest;
}

float getAverageTemperature(FILE *file) {
    rewind(file);
    int sum = 0;
    int count = 0;
    int temp;
    while (fscanf(file, "%d", &temp) == 1) {
        sum += temp;
        count++;
    }
    if (count == 0) {
        return 0;
    } else {
        return (float)sum / count;
    }
}
