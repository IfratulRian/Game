#include<bits/stdc++.h>
using namespace std;
#define fast() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'

char b[10];

void show(){
    cout<<endl;
    cout<<" "<<b[1]<<" | "<<b[2]<<" | "<<b[3]<<endl;
    cout<<"---|---|---"<<endl;
    cout<<" "<<b[4]<<" | "<<b[5]<<" | "<<b[6]<<endl;
    cout<<"---|---|---"<<endl;
    cout<<" "<<b[7]<<" | "<<b[8]<<" | "<<b[9]<<endl;
    cout<<endl;
}

bool win(char c){
    if(b[1]==c&&b[2]==c&&b[3]==c)return true;
    if(b[4]==c&&b[5]==c&&b[6]==c)return true;
    if(b[7]==c&&b[8]==c&&b[9]==c)return true;

    if(b[1]==c&&b[4]==c&&b[7]==c)return true;
    if(b[2]==c&&b[5]==c&&b[8]==c)return true;
    if(b[3]==c&&b[6]==c&&b[9]==c)return true;

    if(b[1]==c&&b[5]==c&&b[9]==c)return true;
    if(b[3]==c&&b[5]==c&&b[7]==c)return true;

    return false;
}

bool draw(){
    for(int i=1;i<=9;i++){
        if(b[i]!='X'&&b[i]!='O')return false;
    }
    return true;
}

void solve(){

    for(int i=1;i<=9;i++){
        b[i]='0'+i;
    }

    cout<<"TIC TAC TOE"<<endl;
    cout<<"Choose positions from 1 to 9"<<endl;

    show();

    int pos;
    char cur='X';

    while(true){

        cout<<"Player "<<cur<<", enter position (1-9): ";
        cin>>pos;

        if(pos<1||pos>9){
            cout<<"Invalid position!"<<endl;
            continue;
        }

        if(b[pos]=='X'||b[pos]=='O'){
            cout<<"Position already occupied!"<<endl;
            continue;
        }

        b[pos]=cur;

        show();

        if(win(cur)){
            cout<<"Player "<<cur<<" wins!"<<endl;
            return;
        }

        if(draw()){
            cout<<"Match Draw!"<<endl;
            return;
        }

        if(cur=='X')cur='O';
        else cur='X';
    }
}

int main(){
    fast();
    solve();
}