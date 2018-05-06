#include <iostream>
#include <fstream>
#include <string.h>
#include <iomanip>

using namespace std;

const int SIZE=50;

int total_toys(int toys[SIZE], int size)
{
    int result=0;
    for (int i=0; i<size-1; i++)
    {
        result+=toys[i];
    }
    
    return result;
}

int over_500(int toys[SIZE], int size)
{
    int result=0;
    for (int i=0; i<size-1; i++)
    {
        if(toys[i]>=500)
        {
            result++;
        }
    }
    return result;
}

int most_toys(int toys[SIZE], int size)
{
    int result=0;
    int maxim=0;
    for (int i=0; i<size-1; i++)
    {
        if(toys[i]>=maxim)
        {
            maxim = toys[i];
            result = i;
        }
    }
    
    return result;
}

int least_toys(int toys[SIZE], int size)
{
    int result=0;
    
    int minimum=10000;
    for (int i=0; i<size-1; i++)
    {
        if(toys[i]<=minimum)
        {
            minimum = toys[i];
            result = i;
        }
    }
    
    return result;
}

void printResults(string name[SIZE],int toys[SIZE], int size)
{   
    string rating;
    
    cout << string(62, '-') << endl;
    cout << "Name \t\t\tNumber of toys \t\t\tRating\n";
    cout << string(62, '-') << endl;
    for (int i=0; i<size-1; i++)
    {
        cout << name[i] << "\t" ;
        if(name[i].length()<=7)
            cout<<"\t";
        if(name[i].length()<12)
            cout<<"\t";
        cout<< toys[i] << "\t\t\t";
        if(toys[i]<1000)
            cout<<"\t";
        if (toys[i]>=500)
        {
          cout << "\t";  
          rating = "*****"; 
            
        }
        else if ((toys[i]>=300) && (toys[i]<=499))
        {
            rating = "***";
        }
        else if ((toys[i]>=200) && (toys[i]<=299))
        {
            rating = "*";
        }
        else if (toys[i]<200)
        {
            rating = "-";
        }
        cout << rating << "\n";
        
    }
    
    cout << endl;
    cout << string(62, '-') << endl;
    cout << "Total number of toys is :"<< setw(35) << total_toys(toys, size)<<"\n";
    cout << "The number of elves who made more than 500 toys is : "<< setw(4) << over_500(toys, size)<<"\n";
    cout << "The elf who made the most toys is  : "<< setw(22) << name[most_toys(toys, size)] << "\n";
    cout << "The elf who made the least toys is : "<< setw(24) << name[least_toys(toys, size)] << "\n";
    cout << string(62, '-') << endl;
}



int main()
{
    int toys[SIZE];
    string name[SIZE];
    string elf, bestElf, worstElf;
    
    ifstream ins("elves.dat");
    
    //doing a loop of 50 iterations
    //assigning 50 0s to toys
    //assigning 50 blank spaces to elf
    //initializing the arrays
    for (int i=0; i<SIZE; i++)
    {
        toys[i]=0;
        name[i]=" ";
    }
    
    int toysB=0, size=0;
    
    //read from the file until the end of file
    while (!ins.eof())
    {
        //read first element of file, assign to 
        ins >> elf;
        name[size]=elf;
        ins >> toysB;
        toys[size]=toysB;
        size++;
        
    }
    
    //close the file when finished reading
    ins.close();
    
    //call the function printResults and pass the arrays
    printResults(name, toys, size);
    
    return 0;
}
