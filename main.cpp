#include <iostream>
#include<fstream>
#include <iomanip>
#include<vector>
#include <sstream>
using namespace std;

    int main(){
    ifstream inFile;
    vector<string> line;
    string displayLine, word;
    int quantity = 0;
    float cost = 0.0, totalCost = 0.0;
    
    inFile.open("./order.dat");
  
    if(!inFile.is_open())
    {
    cerr << "File is not open" << endl;
    return -1;
    }
 
    while(inFile.good()){
    line.clear();
    cost = 0.0; 
    quantity = 0; 
  
    getline(inFile,displayLine);
    stringstream words(displayLine); 
    
    while(getline(words,word,',')){
    line.push_back(word); 
    }
    quantity = stoi(line[1]); 
    cost = stof(line[2]); 
    totalCost = totalCost + (quantity * cost);
    cout << displayLine << endl;
    }
    inFile.close();
    
    ofstream outFile;
    outFile.open("./order.dat", ios::app);
    outFile << "\n";
    outFile << fixed <<setprecision(2) << totalCost << endl;
    outFile.close();
    
    return 0;
    }