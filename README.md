# Temperature Data Management Program

## Overview
This C program allows users to manage and analyze temperature data stored in a text file. It provides functionality to add new temperature readings, calculate the highest, lowest, and average temperatures, and display temperature trends (increasing, decreasing, or fluctuating). The program is menu-driven and provides a simple way to interact with the temperature data stored in a file.

## Features

- **Add Temperature:** Allows users to add new temperature readings to the file.
- **Get Highest Temperature:** Retrieves the highest recorded temperature from the file.
- **Get Lowest Temperature:** Retrieves the lowest recorded temperature from the file.
- **Get Average Temperature:** Calculates and displays the average temperature from all recorded values.
- **Show Temperature Values:** Displays all the temperature values stored in the file.
- **Show Temperature Trends:** Analyzes the trend of temperature data (increasing, decreasing, or fluctuating).

## Requirements

- A C compiler (e.g., GCC)
- Standard C libraries (stdio.h, string.h)

## Compilation and Usage

### 1. Compile the Program

To compile the program, use the following command (assuming you are using GCC):

```bash
gcc -o temp_data temp_data.c
```

### 2. Run the Program

Execute the compiled program:

```bash
./temp_data
```

The program will prompt you to enter a filename to store and access temperature data.

### 3. Choose from the Menu

Once the file is chosen, a menu will be displayed with the following options:

```
Menu:
1. Add temperature
2. Get highest temperature
3. Get lowest temperature
4. Get average temperature
5. Show temperature values
6. Show temperature trends
0. Exit
```

Enter the number corresponding to the action you wish to take.

## Example Usage

1. **Adding Temperature:** 
   After selecting option `1`, you can input a temperature. The program validates the input to ensure it is within the range of -100°C to 100°C.
   
2. **Displaying Statistics:**
   Options `2`, `3`, and `4` allow you to view the highest, lowest, and average temperatures respectively.

3. **Analyzing Trends:**
   Option `6` will analyze the temperature data and display whether the trend is increasing, decreasing, or fluctuating.

## Example Output:

```bash
Enter the filename to access data: temperatures.txt
Temperature data:
25 28 30 15 18 

Menu:
1. Add temperature
2. Get highest temperature
3. Get lowest temperature
4. Get average temperature
5. Show temperature values
6. Show temperature trends
0. Exit
Enter your choice: 2
Highest temperature is: 30 °C 
```

## Functions

### `addTemperature(FILE *file)`
Allows the user to add a temperature reading to the file.

### `getHighestTemperature(FILE *file)`
Returns the highest temperature recorded in the file.

### `getLowestTemperature(FILE *file)`
Returns the lowest temperature recorded in the file.

### `getAverageTemperature(FILE *file)`
Returns the average of all temperature readings in the file.

### `showvalues(FILE *file)`
Displays all recorded temperature values.

### `trends(FILE *file)`
Analyzes the temperature data and displays the trend (increasing, decreasing, or fluctuating).

## License

This project is open-source and licensed under the MIT License. Feel free to fork, modify, and distribute it as per your needs.

---

Feel free to contribute by submitting pull requests, reporting issues, or making suggestions for improvements.

## Acknowledgments

- Standard C libraries were used for file operations and user interaction.
