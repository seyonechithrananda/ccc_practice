  
#include <iostream>
#include <string>

using namespace std;

int** rot90(int** table, int width, int height)
{

    int** rotatedTable = new int* [width];
    for(int i = 0; i < width; i++)
    {
        rotatedTable[i] = new int[height];
    }

    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            rotatedTable[j][height - i - 1] = table[i][j];
        }
    }
    return rotatedTable;
}

void printTable(int ** table, int width, int height)
{
    cout << "\n";
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            cout << table[i][j] << " ";
        }
        cout << "\n";
    }
}

int** getCorrectTable(int** table, int numFlowers)
{
    bool isCorrect = true;

    for(int i = 0; i < numFlowers - 1; i++)
    {
        if(table[i][0] > table[i+1][0] || table[0][i] > table[0][i+1])
        {
            isCorrect = false;
        }
    }

    if(isCorrect)
    {
        return table;
    }

    return getCorrectTable(rot90(table, numFlowers, numFlowers), numFlowers);

}

int main() 
{
    int numFlowers;
    string tableRow = "";
    string currentNum = "";
    int currentNumIndex = 0;

    cin >> numFlowers;

    int ** table = new int*[numFlowers];

    for(int i = 0; i < numFlowers; i++)
    {
        table[i] = new int[numFlowers];
    }

    for(int i = 0; i < numFlowers; i++)
    {
        cin >> ws;
        getline(cin, tableRow);

        for(int j = 0; j < tableRow.size(); j++)
        {
            if(tableRow[j] == ' ')
            {
                table[i][currentNumIndex] = stoi(currentNum);
                currentNum = "";
                currentNumIndex++;
            }
            else 
            {
                currentNum += tableRow[j];
            }
        }
        
        table[i][currentNumIndex] = stoi(currentNum);
        currentNum = "";
        currentNumIndex = 0;
    }
   
    table = getCorrectTable(table, numFlowers);

   printTable(table, numFlowers, numFlowers); 
    return 0;
}


