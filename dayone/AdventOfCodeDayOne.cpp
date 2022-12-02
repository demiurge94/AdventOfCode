#include <iostream>
#include <fstream> 
#include <string> 
#include <vector> 
#include <algorithm>
using namespace std; 


int main(){

    ifstream input; 
    input.open("input.txt"); 
    string line; 
    vector<int> elfCalories; 
    int i = 0; 
    int max = 0; 
    int mid = 0; 
    int last = 0;
    vector<int> elfs; 
    if(input.is_open() ){
        
        int temp = 0; 
        vector<int>  heavyElfs; 
        while(input.good() && getline(input, line) ){
            if(!line.empty()){
                temp+= stoi(line); 
                cout<<"adding: "<<stoi(line)<<endl;
            }
            else{
                //line is empty
                    
                if( i < 3 ) {
                    elfs.push_back(temp); 
                }
                if( i == 3 ){
                    sort(elfs.begin(), elfs.end(), greater<int>());
                }
                else{
                    // we are no longer in the first three!
                    if( temp > elfs[0] ){
                        // if bigger than the MAX 
                        elfs[2] = elfs[1]; 
                        elfs[1] = elfs[0]; 
                        elfs[0] = temp; 
                    }
                    else if( temp > elfs[1] ){
                        elfs[2] = elfs[1]; 
                        elfs[1] = temp; 
                    }
                    else if ( temp > elfs[2] ){
                        elfs[2] = temp; 
                    }
                }
                i++;
                temp=0; 
            }
            
        }
        input.close(); 
        cout<<elfs[0]<<" " <<elfs[1]<<" " <<elfs[2]<<endl;
        cout<<elfs[0]+elfs[1]+elfs[2]<<endl;
        cout<<" number of elfs to be sure "<<elfs.size()<<endl;
    }
  
    return 0; 
}