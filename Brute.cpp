#include<bits/stdc++.h>
using namespace std;

#define fp(i,x,n) for(int i=x;i<n;i++)

int globalans = INT_MAX;

int n, tme;

vector<int> v[100001];

void findabc(vector<int> el){

    int truck1 = 0, truck2 = 0, both = 0;

    fp(i,0,n){

        int flag1 = 0, flag2 = 0;

        fp(j,0,v[i].size()){

            if(el[v[i][j]]==1)
                flag1 = 1;
            if(el[v[i][j]]==0)
                flag2 = 1;
        }

        if(flag1 && flag2)
            both ++;
        else if(flag1 && !flag2)
            truck1 ++;
        else if(!flag1 && flag2)
            truck2 ++;
    }

    globalans = min(globalans,(both+max(truck1,truck2))*tme);
}

void PowerSet(vector<int>set, int set_size, int c)
{
    unsigned int pow_set_size = pow(2, set_size);
    int counter, j;

    for(counter = 0; counter < pow_set_size; counter++) {

        vector<int> el(c+1,0);

        for(j = 0; j < set_size; j++)
            if(counter & (1 << j))
                el[set[j]] ++;

        findabc(el);
    }
}

int main(){

    int t,c,x,y;
    cin >> t;
    while(t--){
        cin >> c >> n >> tme;
        vector<int> set;

        fp(i,0,n){
            cin >> x;
            fp(j,0,x){
                cin >> y;
                v[i].push_back(y);
            }
        }

        fp(i,0,c)
            set.push_back(i+1);

        PowerSet(set, set.size(), c);

        cout << globalans << endl;

        globalans = INT_MAX;

        fp(i,0,n)
            v[i].clear();
    }
}
