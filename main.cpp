#include <iostream>
#include <fstream>
#include <vector>

// ������� ��� ������ ����� � �������
void DFS(int vertex, const std::vector<std::vector<int>>& adjacencyMatrix, std::vector<bool>& visited)
{
    // �������� ������� ������� ��� ����������
    visited[vertex] = true;
    // ������� ����� ������� �������
    std::cout << vertex + 1 << " ";

    // ���������� ������� ��� ������� �������
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
        std::cerr << "������ �������� �����!" << std::endl;
        return 1; // ���������� 1 � ������ ������
    }

    // ������ ���������� ������ �����
    int N;
    inputFile >> N;

    // ������ ������� ���������
    std::vector<std::vector<int>> adjacencyMatrix(N, std::vector<int>(N));

    // ��������� ������� ��������� �� �����
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            inputFile >> adjacencyMatrix[i][j];
        }
    }

    inputFile.close();

    // ������ ������ ��� �������� ���������� � ���������� ��������
    std::vector<bool> visited(N, false);

    std::cout << "������� ������ ������: ";

    // ��������� ����� ����� � ������� � ������ ������� (������ 0)
    DFS(0, adjacencyMatrix, visited);

    // ������� �� ����� ������
    std::cout << std::endl;

    
    return EXIT_SUCCESS; 
}