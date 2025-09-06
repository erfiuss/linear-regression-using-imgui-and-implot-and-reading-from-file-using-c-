#include <iostream>
#include <vector>
#include <numeric>
#include <fstream>
#include <sstream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "imgui.h"
#include "implot.h"
#include "backends/imgui_impl_glfw.h"
#include "backends/imgui_impl_opengl3.h"

using namespace std;

// ----------------- Linear regression -----------------
pair<double, double> linear_regression(const vector<double>& x, const vector<double>& y) {
int n = x.size();
double mean_x = accumulate(x.begin(), x.end(), 0.0) / n;
double mean_y = accumulate(y.begin(), y.end(), 0.0) / n;

double num = 0.0, den = 0.0;
for (int i = 0; i < n; i++) {
num += (x[i] - mean_x) * (y[i] - mean_y);
den += (x[i] - mean_x) * (x[i] - mean_x);
}

double m = num / den;
double b = mean_y - m * mean_x;
return {m, b};
}

// ----------------- Read data from CSV file using column indices -----------------
bool readDataFromFile(const string& filename, vector<double>& x, vector<double>& y, int col_x, int col_y) {
x.clear();
y.clear();

ifstream file(filename);
if (!file.is_open()) {
cerr << "Failed to open " << filename << endl;
return false;
}

string line;
while (getline(file, line)) {
stringstream ss(line);
string cell;
vector<string> cells;
while (getline(ss, cell, ',')) {
cells.push_back(cell);
}

if (col_x >= cells.size() || col_y >= cells.size()) continue;

try {
x.push_back(stod(cells[col_x]));
y.push_back(stod(cells[col_y]));
} catch (...) {
continue; // skip invalid lines
}
}

file.close();
return !x.empty() && !y.empty();
}

// ----------------- Plot function -----------------
void ShowLinearRegressionPlot(const vector<double>& x, const vector<double>& y) {
if (x.empty() || y.empty()) return;

auto [m, b] = linear_regression(x, y);

vector<double> line_x = {x.front(), x.back()};
vector<double> line_y = {m * line_x[0] + b, m * line_x[1] + b};

if (ImPlot::BeginPlot("Linear Regression")) {
ImPlot::PlotScatter("Data Points", x.data(), y.data(), x.size());
ImPlot::PlotLine("Regression Line", line_x.data(), line_y.data(), line_x.size());
ImPlot::EndPlot();
}
}

// ----------------- Main -----------------
int main(int argc, char* argv[]) {
if (argc < 4) {
cerr << "Usage: " << argv[0] << " <file.csv> <x_column_index> <y_column_index>" << endl;
return -1;
}

string filename = argv[1];
int col_x = stoi(argv[2]);
int col_y = stoi(argv[3]);

vector<double> x, y;
if (!readDataFromFile(filename, x, y, col_x, col_y)) {
cerr << "No valid data to plot!" << endl;
return -1;
}

// Init GLFW
if (!glfwInit()) return -1;

GLFWwindow* window = glfwCreateWindow(800, 600, "Linear Regression from File", NULL, NULL);
if (!window) { glfwTerminate(); return -1; }
glfwMakeContextCurrent(window);
glfwSwapInterval(1);

// Init GLAD
if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
cerr << "Failed to initialize GLAD!" << endl;
return -1;
}

// Init ImGui + ImPlot
IMGUI_CHECKVERSION();
ImGui::CreateContext();
ImPlot::CreateContext();
ImGuiIO& io = ImGui::GetIO(); (void)io;
ImGui::StyleColorsDark();

ImGui_ImplGlfw_InitForOpenGL(window, true);
ImGui_ImplOpenGL3_Init("#version 130");

// Main loop
while (!glfwWindowShouldClose(window)) {
glfwPollEvents();

ImGui_ImplOpenGL3_NewFrame();
ImGui_ImplGlfw_NewFrame();
ImGui::NewFrame();

ImGui::Begin("Regression Demo");
ShowLinearRegressionPlot(x, y);
ImGui::End();

// Render
ImGui::Render();
int display_w, display_h;
glfwGetFramebufferSize(window, &display_w, &display_h);
glViewport(0, 0, display_w, display_h);
glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
glClear(GL_COLOR_BUFFER_BIT);
ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

glfwSwapBuffers(window);
}

// Cleanup
ImGui_ImplOpenGL3_Shutdown();
ImGui_ImplGlfw_Shutdown();
ImPlot::DestroyContext();
ImGui::DestroyContext();
glfwDestroyWindow(window);
glfwTerminate();

return 0;
}