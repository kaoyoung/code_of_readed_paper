#include <iostream>
#include <string>

using namespace std;

void recursive(int currentindex,string &n, int &totalnumber);
bool canbreak(int currentindex,string &n);
void init_string(string &n);

int main() {
	string n; //input is n
    int totalnumber = 0; // number of hyperbinary representations
    cin >> n;
    init_string(n);    
    recursive(0,n,totalnumber);
    cout << totalnumber << endl;
    return 0;
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
        recursive(currentindex+1,n,totalnumber);
    }
    else if(n[currentindex] == '1'){
        recursive(currentindex+1,n,totalnumber);
        if(canbreak(currentindex+1,n)){
            n[currentindex] = '0';
            n[currentindex+1] += 2;
            recursive(currentindex+1,n,totalnumber);
            n[currentindex] = '1';
            n[currentindex+1] -= 2;
        }
    }
    // every digit can't break twice
    else if(n[currentindex] == '2'){
        recursive(currentindex+1,n,totalnumber);
        if(canbreak(currentindex+1,n)){
            n[currentindex] = '1';
            n[currentindex+1] += 2;
            recursive(currentindex+1,n,totalnumber);
            n[currentindex] = '2';
            n[currentindex+1] -= 2;
        }
    }
    // deal with the case that n[currentindex] == '3'
    else{
        n[currentindex] = '2';
        n[currentindex+1] += 2;
        recursive(currentindex+1,n,totalnumber);
        n[currentindex] = '3';
        n[currentindex+1] -= 2;
    }
    return;
}

bool canbreak(int currentindex,string &n){   
    while(currentindex < n.size()){
        if(n[currentindex] == '2')
            return false;
        if(n[currentindex] == '0')
            return true;  
        currentindex++;
    }
    return !(n[n.size()-1] == '1');
}
void init_string(string &n){
    for(int i=n.size()-1; i>0; i--){
        if(n[i] >= '2'){            
                n[i] -= 2;
                n[i-1] += 1;       
        }
    }
    for(int i=0; i<n.size()-1; i++){
        if(n[i] >= '3'){            
                n[i] -= 1;
                n[i+1] += 2;       
        }
    }
}