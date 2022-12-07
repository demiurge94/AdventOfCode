#include <iostream>
#include <fstream> 
#include <string> 
#include <vector> 
#include <algorithm>
#include <unordered_map>

using namespace std; 


int main(){
  

    unordered_map<char, char> strategyGuide; 
    ifstream input; 
    input.open("input.txt"); 
    int allTotal = 0; 
    int rock =1, paper = 2, scissors = 3;
    int loss = 0, draw = 3, win = 6; 
    int partTwo = 0; 
    while(!input.eof()){
        string line; 
        getline(input, line);
        int total = 0; 
        if(line[0] == 'A'){
            /**
            * 
            */
           
           if(line[2] == 'X'){
            //tie
                total += draw + rock; 
                partTwo+= loss + scissors; 
           }
            else if(line[2] == 'Y'){
                // win
                cout<<"win"<<endl;
                total += win + paper; 
                partTwo += draw + rock; 

            }
            else {
                //loss z
                cout<<"here"<<endl;
                total += loss + scissors; 
                partTwo += win + paper; 
            }
        }
        if(line[0] == 'B'){
            if(line[2] == 'Y'){
                //tie
                total+=draw + paper; 
                partTwo += draw + paper; 
            }  
            else if(line[2] == 'Z'){
                // win
                total+= win + scissors; 
                partTwo += win + scissors; 
            }
            else {
                //loss rock
                cout<<"loss"<<endl;
                total+= 0 + rock; 
                partTwo += loss + rock; 
            }
        }
        if(line[0] == 'C'){
            if(line[2] == 'Z'){
                //tie
                cout<<"tie"<<total<< "+ " <<draw<<"+ " <<scissors<<endl;
                total+= draw + scissors; 
                partTwo+= win + rock; 
            }
            else if(line[2] == 'X'){
                // win
                total+= win + rock; 
                partTwo += loss + paper; 
            }
            else {
                //loss paper
                total+= loss + paper; 
                partTwo += draw + scissors; 
            }
        }
        cout<<total<<endl;
        allTotal += total;
        //getline(input, line);
    }
    cout<<partTwo<<endl; 
    input.close(); 
}
