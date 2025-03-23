//
//  main.cpp
//  39Game
//
//  Created by ハイラル・ゼルダ on 2025.03.30.
//

//Provided by Roger

#include <random>
#include <iostream>
using namespace std;
mt19937 gen(time(0));
int Base[10];
int dp[400000][40],dep[400000][40];
int get_val(int S,int dig){return (S%Base[dig+1])/Base[dig];}
int get_dep(int S,int sum){if(sum>=39||S==0)return 0;return dep[S][sum];}
int dfs(int S,int sum){
    if(sum==39)    return 0;
    if(sum>39)    return 1;
    if(S==0)    return 0;
    if(dp[S][sum]!=-1)    return dp[S][sum];
    for(int i=1;i<=8;i++){
        if(get_val(S,i-1)==0)    continue;
        if(dfs(S-Base[i-1],sum+i)==0){dep[S][sum]=get_dep(S-Base[i-1],sum+i)+1;return dp[S][sum]=1;}
        dep[S][sum]=max(dep[S][sum],get_dep(S-Base[i-1],sum+i)+1);
    }
    return dp[S][sum]=0;
}
void pre_work(){
    memset(dp,-1,sizeof(dp));Base[0]=1;
    for(int i=1;i<=8;i++)    Base[i]=Base[i-1]*5;
    for(int i=0;i<Base[8];i++)    for(int j=0;j<=39;j++)    if(dp[i][j]==-1)    dfs(i,j);
}
void Game_Test(int on){
    pre_work();
    cout<<"Input your identity. Use 0 for first player and 1 for second player."<<endl;
    int now=Base[8]-1,sum=0,id;cin>>id;
    if(id!=0&&id!=1){cout<<"Invalid input."<<endl;return;}
    while(1){
        cout<<"Current state:";for(int i=0;i<8;i++)cout<<get_val(now,i)<<" ";cout<<endl;
        cout<<"Current sum:"<<sum<<endl;
        if(id==0){
            cout<<"This is your turn. ";
            if(dfs(now,sum)){
                cout<<"You can win."<<endl;
                for(int i=1;i<=8;i++)
                    if(get_val(now,i-1)>0&&dfs(now-Base[i-1],sum+i)==0)
                        {cout<<"Next move is "<<i<<"."<<endl;break;}
            }
            else{
                cout<<"You will lose."<<endl;
                int nowd=0;
                for(int i=1;i<=8;i++){
                    if(get_val(now,i-1)==0)    continue;
                    if(nowd==0){nowd=i;continue;}
                    if(get_dep(now-Base[nowd-1],sum+nowd)<get_dep(now-Base[i-1],sum+i))    nowd=i;
                }
                cout<<"Yet the move of "<<nowd<<" is recommended."<<endl;
            }
            cout<<"That is all the analysis. Input your decision."<<endl;
        }
        else{
            cout<<"This isn't your turn. ";
            if(dfs(now,sum))    cout<<"The other player can win."<<endl;
            else    cout<<"The other player will lose."<<endl;
            cout<<"Input the other player's decision."<<endl;
            if(on){
                bool flag=0;
                for(int i=1;i<=8;i++)
                    if(get_val(now,i-1)>0&&dfs(now-Base[i-1],sum+i)==0)
                        {cout<<"AI chooses the move "<<i<<". Input it."<<endl;flag=1;break;}
                if(flag==0){
                    int ch=gen()%8;while(get_val(now,ch)==0)    ch=gen()%8;
                    cout<<"AI chooses the move "<<ch+1<<". Input it."<<endl;
                }
            }
        }
        cout<<"If you want to test options, input -1, otherwise input the chosen number."<<endl;
        int x;cin>>x;
        if((x<1||x>8)&&x!=-1){cout<<"Invalid input."<<endl;return;}
        if(x==-1){
            cout<<"Tests start. Stop by inputing -1 again."<<endl;
            while(1){
                cin>>x;
                if((x<1||x>8)&&x!=-1){cout<<"Invalid input."<<endl;return;}
                if(x==-1){cout<<"Tests end."<<endl;cin>>x;break;}
                cout<<"Test case is "<<x<<". ";
                if(get_val(now,x-1)==0)    cout<<"Invalid option."<<endl;
                else    if(dfs(now-Base[x-1],sum+x)==0)    cout<<"Winning option."<<endl;
                else    cout<<"Loseing option."<<endl;
            }
        }
        if(x<1||x>8||get_val(now,x-1)==0){cout<<"Invalid input."<<endl;return;}
        now-=Base[x-1];sum+=x;id^=1;
        if(now==0){cout<<"Unable to move now."<<endl;break;}
        if(sum>=39){cout<<"The game ends with a final sum of "<<sum<<"."<<endl;break;}
    }
}
int main(){
    cout<<"Choose the game type. Use 0 for human-human game and 1 for AI-human game."<<endl;
    int opt;cin>>opt;
    if(opt!=0&&opt!=1){cout<<"Invalid input."<<endl;system("pause");return 0;}
    Game_Test(opt);system("pause");
    return 0;
}
