#include <iostream>
#include <cstdio>
#include <ctime>
#include <fstream>
#include <cstddef>
#include <cstring>
using namespace std;

struct Social
{
    string SSN;
    string Name;
    string command;
};
void Insert(Social *&array, string SSN, string name, int place)
{
    array[place].Name = name;
    array[place].SSN = SSN;
}
void Delete(Social *&array, string SSN, string name, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (((SSN.compare(array[i].SSN)) == 0))
        {
            for (int x = i; x < size - 1; x++)
            {
                array[x] = array[x + 1];
            }
            break;
        }
    }
}
bool Retrieve(Social *&array, string SSN, string name, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (((SSN.compare(array[i].SSN)) == 0))
        {
            return true;
        }
    }
    return false;
}
void TooLarge(Social *&array, int size)
{
    Social *temp = new Social[size * 2];
    for (int i = 0; i < size; i++)
    {
        temp[i] = array[i];
    }
    delete[] array;
    array = temp;
}
void TooSmall(Social *&array, int size)
{
    Social *temp = new Social[size / 2];
    for (int i = 0; i < size / 2; i++)
    {
        temp[i] = array[i];
    }
    delete[] array;
    array = temp;
}
bool insertCheck(Social *&array, string SSN, string name, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (((SSN.compare(array[i].SSN)) == 0))
        {
            return false;
        }
    }
    return true;
}
bool deleteCheck(Social *&array, string SSN, string name, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (((SSN.compare(array[i].SSN)) == 0))
        {
            return true;
        }
    }
    return false;
}
int main(int argc, char *argv[])
{
    clock_t start, end;
    double duration;
    start = clock();
    string r = "r";
    string de = "d";
    string i = "i";
    int retrieveCount = 0;
    int insertCount = 0;
    int deleteCount = 0;
    int size = 1000;
    int itemNumber = 0;
    int place = 0;
    string file = argv[1];
    string command, b, c, d;
    Social *array = new Social[size];
    fstream input(argv[1]);
    int line = 0;
    //cout<<line;
    while (!input.eof())
    {
        input >> command >> b >> c >> d;
        //cout<< line++ <<endl;
        //if you find a==i call insert()
        // if a==r retrieve()
        string name = c + d;
        if ((i.compare(command) == 0))
        {
            if (insertCheck(array, b, name, size) == true)
            {
                if ((insertCount - deleteCount) == size)
                {
                    TooLarge(array, size);
                    size = size * 2;
                }
                Insert(array, b, name, place);
                place = place + 1;
                insertCount = insertCount + 1;
            }
        }
        if ((de.compare(command) == 0))
        {
            if (deleteCheck(array, b, name, size) == true)
            {
                Delete(array, b, name, size);
                place = place - 1;
                deleteCount = deleteCount + 1;

                if ((insertCount - deleteCount) < 0.25 * size)
                {
                    TooSmall(array, size);
                    size = size / 2;
                }
            }
        }
        if ((r.compare(command) == 0))
        {
            if (Retrieve(array, b, name, size) == true)
                retrieveCount = retrieveCount + 1;
        }
        itemNumber = insertCount - deleteCount;
    }
    input.close();

    cout << "The number of Valid Insertion: " << insertCount << endl;
    cout << "The number of Valid Deletion: " << deleteCount << endl;
    cout << "The number of Valid Retrieval: " << retrieveCount << endl;
    cout << "Item numbers in the array: " << itemNumber << endl;
    cout << "Array size is " << size << endl;

    end = clock();
    duration = (end - start) / (double)CLOCKS_PER_SEC;

    cout << "elapsed time: " << duration << '\n';
}
