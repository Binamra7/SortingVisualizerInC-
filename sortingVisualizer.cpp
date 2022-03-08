#include<algorithm>
#include<vector>
#include<iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>
#include<windows.h>

using namespace std;

HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

void sortArray(int n);
void printArray(int n);
void printSortedArray(int n);
void generateArray(int n);

vector<int> a;
int n, m;

//generated a new array at first 
//also regenerated the array 
void generateArray(int n)
{
    system("CLS");
    for (int i = 0; i < n;i++)
    {    
            int randomNumber=0;
            randomNumber = (rand() % 100)+1;
            a.push_back(randomNumber) ;
    }
    printArray(n);
}

//prints the generated array
void printArray(int n)
{
    for (int i =0;i<n; i++)
    {
        int count = 0;
        for (int j = 0; j < a[i];j++)
        {
                printf("%c",219);
                if(j==a[i]-1)
                    cout << j+1;
        }
        cout << endl;
        cout << endl;
    }
    int cInt;
    printf("1.Generate New array:\n2.Start sorting\n3.Exit\n");
    scanf("%d", &cInt);
    if(cInt==1){
        a.clear();
        generateArray(n);
    }
    else if(cInt==2){
        
        sortArray(n);
    }
    else
        exit(0);
}

//sorting the array
//printing the intermediate array
void sortArray(int n)
{    
    int delay = 500;    
    int delay;
    if(n<7)
        delay = 100;
    else if(n>=7 && n<14)
        delay = 80;
    else if(n>=14)
        delay = 0;
    system("CLS");
    for (int i = 0; i < n;i++){
        for (int j = i + 1; j < n;j++)
        {
            system("CLS");
            
            {                  
            
                for (int k = 0; k < n; k++)
                {
                    for (int l = 0; l < a[k]; l++)
                    {
                        // SetConsoleTextAttribute(h, 15);
                         if(k<i)
                        {
                            SetConsoleTextAttribute(h, 10);                         
                            printf("%c", 219);
                            if (l == a[k] - 1)
                                cout << l+1;
                        }
                        if(k==i)
                        {
                            // printf("%c", 178);
                            SetConsoleTextAttribute(h, 9);                            
                            printf("%c", 219);
                            if (l == a[k] - 1)
                                cout << l+1;
                        }
                        else if(k==j)
                        {
                            SetConsoleTextAttribute(h, 12);
                            printf("%c", 219);
                            // printf("%c", 176);
                            if (l == a[k] - 1)
                                cout << l+1;
                        }
                        else if(k!=i && k!=j && k>i)
                        {
                            SetConsoleTextAttribute(h, 7);
                            printf("%c", 219);
                            if (l == a[k] - 1)
                                cout << l+1;
                        }
                    }
                    cout << endl;
                    cout << endl;
                    
                }
                //makes the execution slow
                std::this_thread::sleep_for(std::chrono::milliseconds {delay});
                
            }

            if(a[i]>=a[j])
            {
                system("CLS");
                swap(a[i], a[j]);}
                for (int k = 0; k < n; k++)
                {
                    for (int l = 0; l < a[k]; l++)
                    {
                        if(k<i)
                        {
                            SetConsoleTextAttribute(h, 10);                         
                            printf("%c", 219);
                            if (l == a[k] - 1)
                                cout << l+1;
                        }
                        if(k==i)
                        {
                            SetConsoleTextAttribute(h, 9);                         
                            printf("%c", 219);
                            if (l == a[k] - 1)
                                cout << l+1;
                        }
                        else if(k==j)
                        {
                            SetConsoleTextAttribute(h, 12);
                            printf("%c", 219);
                            if (l == a[k] - 1)
                                cout << l+1;
                        }
                        else if(k!=i && k!=j && k>i)
                        {
                            SetConsoleTextAttribute(h, 7);
                            printf("%c", 219);
                            if (l == a[k] - 1)
                                cout << l+1;
                        }
                    }
                    cout << endl;
                    cout << endl;
                    
                }
            //     //makes the execution slow
                std::this_thread::sleep_for(std::chrono::milliseconds {delay});
                
            // }
        }
    }            
}

//prints the final array;
void printSortedArray(int n)
{
    system("CLS");
    SetConsoleTextAttribute(h, 10);
    for (int i =0;i<n; i++)
    {
        for (int j = 0; j < a[i];j++)
        {
            printf("%c", 219);
            if (j == a[i] - 1)
             cout << j+1;
        }
        cout << endl;
        cout << endl;
        std::this_thread::sleep_for(std::chrono::milliseconds {25});
    }
}

int main()
{
    first:
    int n,m;
    SetConsoleTextAttribute(h, 7);
    printf("Enter the size of array:(2<=size<=20)");
    top:
    scanf("%d", &n);
    if(n<2 || n>20){
        cout << "Please Enter a valid number:\n";
        goto top;
    }
    generateArray(n);
    printSortedArray(n);
    fflush(stdin);
    cout << "DO YOU WANT TO RUN AGAIN(Y/N)\n";
    char choice;
    scanf("%c", &choice);
    if(choice=='n' || choice =='N')
        exit(0);
    else if(choice =='Y'|| 'y')
        goto first;
    return 0;
}
