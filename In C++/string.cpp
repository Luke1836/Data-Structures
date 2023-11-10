#include <iostream>
using namespace std;


int main(void)
{
    string name;
    int len;
    int no_rows;

    cout << "Enter a string" << endl;
    getline(cin, name);
    len = name.length();

    cout << "Enter the number of rows" << endl;
    cin >> no_rows;

    //Initialises every value to whitespace.
    char mat[no_rows][len];
    for (int i = 0; i < no_rows; i++) {
        for (int j = 0; j < len; j++) {
            mat[i][j] = ' ';
        }
    }

    /* c - keeps track of the index of the string we inputted. 
       j - keeps track of the columns
    */
    int c = 0; int j= 0;
    while(c < len)
    {   
        //prints the characters in the entire column.
        if(j%(no_rows - 1) == 0)
        {
            for(int i=0;i<no_rows;i++)
                {mat[i][j] = name[c];
                c++;}
        }
        //Prints it in the order given in the question for all other columns
        else{
            for(int i=0;i<no_rows;i++)
                if((j)%(no_rows-1) == i)
                    {mat[i][j] = name[c];
                    c++;}
                else
                    mat[i][j] = ' ';
        }
        j++;
        
    } 

    for(int i = 0 ; i < no_rows ; i++)
    {for(int j=0; j<len;j++)
        if(mat[i][j] != ' ')
            cout<< mat[i][j];
    }  
    cout << endl;
    for(int i = 0 ; i < no_rows ; i++)
    {for(int j=0; j<len;j++)
            cout<< mat[i][j] << "  ";
    cout << endl;
    }  

}