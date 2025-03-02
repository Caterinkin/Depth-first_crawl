#include <iostream>
#include <fstream>
#include <vector>

// Функция для обхода графа в глубину
void DFS(int vertex, const std::vector<std::vector<int>>& adjacencyMatrix, std::vector<bool>& visited)
{
    // Помечаем текущую вершину как посещённую
    visited[vertex] = true;
    // Выводим номер текущей вершины
    std::cout << vertex + 1 << " ";

    // Рекурсивно обходим все смежные вершины
    for (int i = 0; i < adjacencyMatrix.size(); ++i)
    {
        if (adjacencyMatrix[vertex][i] == 1 && !visited[i])
        {
            DFS(i, adjacencyMatrix, visited);
        }
    }
}

int main()
{
    
    setlocale(LC_ALL, "rus");

    std::ifstream inputFile("input.txt");
    if (!inputFile.is_open())
    {
        std::cerr << "Ошибка открытия файла!" << std::endl;
        return 1; // Возвращаем 1 в случае ошибки
    }

    // Читаем количество вершин графа
    int N;
    inputFile >> N;

    // Создаём матрицу смежности
    std::vector<std::vector<int>> adjacencyMatrix(N, std::vector<int>(N));

    // Заполняем матрицу смежности из файла
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            inputFile >> adjacencyMatrix[i][j];
        }
    }

    inputFile.close();

    // Создаём массив для хранения информации о посещённых вершинах
    std::vector<bool> visited(N, false);

    std::cout << "Порядок обхода вершин: ";

    // Запускаем обход графа в глубину с первой вершины (индекс 0)
    DFS(0, adjacencyMatrix, visited);

    // Переход на новую строку
    std::cout << std::endl;

    
    return EXIT_SUCCESS; 
}