#include <iostream>
using namespace std;
void recursive(int currentindex,string &n, int &totalnumber);
bool canbreak(int currentindex,string &n);

int main() {
	string n; //input is n
    int totalnumber; // number of hyperbinary representations
    cin >> n;
    recursive(0,n,totalnumber);
    return totalnumber;
}

void recursive(int currentindex,string &n, int &totalnumber){
    //終止條件 : 到底
    if(currentindex == n.size()-1){
        if(n[currentindex] == '0' || n[currentindex] == '1' || n[currentindex] == '2')
            totalnumber++;
        return;
    }

    //各細項操做
    if(n[currentindex] == '0'){
        recursive(++currentindex,n,totalnumber);
    }
    else if(n[currentindex] == '1'){
        recursive(++currentindex,n,totalnumber);
        if(canbreak(currentindex+1,n)){
            n[currentindex] = '0';
            n[currentindex+1] = n[currentindex+1]+2;
            recursive(++currentindex,n,totalnumber);
            n[currentindex] = '1';
            n[currentindex+1] = n[currentindex+1]-2;
        }
    }
    // every digit can't break twice
    else if(n[currentindex] == '2'){
        recursive(++currentindex,n,totalnumber);
        if(canbreak(currentindex+1,n)){
            n[currentindex] = '1';
            n[currentindex+1] = n[currentindex+1]+2;
            recursive(++currentindex,n,totalnumber);
            n[currentindex] = '2';
            n[currentindex+1] = n[currentindex+1]-2;
        }
    }
}

bool canbreak(int currentindex,string &n){   
    while(currentindex < n.size()){
        if(n[currentindex] == '2')
            return false;
        if(n[currentindex] == '0')
            return true;  
        currentindex++;
    }
    return n[n.size()-1] == '1';
}
