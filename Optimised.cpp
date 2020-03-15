/* 
    c types of candies 1...c
    n number of students 1...n
    t time taken by a student 
    child[N] - list of candies a child need to have
*/

#include<bits/stdc++.h>

using namespace std;

int truck2=0,truck1=0,both=0;
int n;

int calculate(unordered_set<int> q1, unordered_set<int> child[], unordered_set<int> used){

    truck2=0,truck1=0,both=0;
    bool flagt1,flagB;
    for(auto i = q1.begin(); i!=q1.end(); i++){
        //cout<<*i<<" ";
        flagt1=1;
        flagB=0;
        for(auto j = child[*i].begin(); j!= child[*i].end(); j++){
            if(used.find(*j)==used.end()){
                flagt1=0;
            }
            else{
                flagB=1;
            }
        }
        if(flagt1==0 && flagB)
            both++;
        else if(flagt1)
            truck1++;
        else
            truck2++;
    }
    if(truck2==0){
        return n;
    }
    return both + max(truck1,truck2);
}

int main(){
    
    int testcase;
    cin>>testcase;

    while(testcase--){

        int c;

        cin>>c>>n;

        int t;

        cin>>t;

        int can,num;

        unordered_set<int> canFreq[c+1],child[n+1];
        int ma = 0,ind;

        for(int i=1;i<=n;i++){
            cin>>num;
            for(int j=1;j<=num;j++){
                cin>>can;
                child[i].insert(can);
                canFreq[can].insert(i);
                if(ma<canFreq[can].size())
                {
                    ind = can;
                    ma = canFreq[can].size();
                }
            }
        }
        can = ind;
        unordered_set<int> q1;

        // initially add the kids who needs the candy which is most popular in first queue
        for(int i=1; i<=n; i++){
            if(child[i].find(ind) != child[i].end())
            {
                q1.insert(i);
            }    
        }

        unordered_set<int> used;


        int ans = INT_MAX;
        int a,b,r;

        for(int x=2; x<=c; x++){
           // cout<<endl<<endl;
            used.insert(can);

            int temp = calculate(q1,child,used);
           // cout<<" "<<temp<<endl;
            if(ans > temp){
                ans = temp;
                a = truck2;
                b = both;
                r = truck1;
            }

            int ma=0;
            int next_can;
            int freq[c+1]={0};

            for(auto it = q1.begin(); it!=q1.end(); it++){
                for(auto it2 = child[*it].begin(); it2 != child[*it].end(); it2++){
                    if(used.find(*it2)==used.end()){
                        freq[*it2]++;
                        if(ma<freq[*it2]){
                            ma = freq[*it2];
                            next_can = *it2;
                        }
                    }
                }
            }

            can = next_can;

            for(auto it=canFreq[can].begin(); it!=canFreq[can].end();it++){
                q1.insert(*it);
            }
        }
        cout<<"ans "<<ans<<" seconds"<<endl;
    }
    return 0;
}
