# Linear Regression Visualizer

Linear Regression Visualizer is a C++ program designed to help users **easily analyze and visualize the relationship between two numerical variables**. By reading data from a CSV file, the program plots a **scatter plot** and overlays a **linear regression line** to help identify trends in the data. This tool is ideal for **students, data enthusiasts, or developers** who want a lightweight visualization tool without relying on heavy data science frameworks.

The program leverages **ImGui** and **ImPlot**, which are powerful libraries for creating interactive graphical interfaces in C++ applications. This allows you to interact with the plot window in real-time, giving a smooth and responsive experience.

---

## Features

- **CSV File Input**: Read data directly from any CSV file containing numerical values.
- **Dynamic Column Selection**: Specify which columns in your CSV file represent the x and y axes through command-line arguments.
- **Linear Regression Calculation**: Automatically calculates the slope and intercept using the least squares method, giving a mathematical representation of the trend.
- **Interactive Visualization**: Use ImGui and ImPlot to display scatter points and regression lines in a responsive graphical window.
- **Lightweight and Extensible**: Easily extendable to add more features like multiple regression lines, dynamic updates, or additional visualization options.
- **Cross-platform Compatibility**: Designed to work on Linux (e.g., Manjaro) and can be adapted for Windows or macOS with minimal changes.

---

## File Structure

The repository is organized in a clear and intuitive structure to make it easy for developers to navigate:
	
This structure ensures that **all required files are easily accessible**, and new developers can quickly locate and modify components.

---

## Requirements

Before compiling and running the program, you need to ensure that your system has the following tools and libraries installed:

- **C++17 compatible compiler** (such as g++ or clang++)
- **GLFW** for creating windows and handling input
- **GLAD** for OpenGL function loading
- **ImGui** for graphical user interfaces
- **ImPlot** for plotting data

On **Manjaro Linux**, you can install GLFW and GLAD using `pacman`:

```bash
sudo pacman -S glfw glad
```



### bash
```
./linear_regression <file.csv> <x_column_index> <y_column_index>
```

### Result
```
![https://github.com/erfiuss/linear-regression-using-imgui-and-implot-and-reading-from-file-using-c-/blob/main/Screenshot_20250906_074423.png?raw=true
]
```
