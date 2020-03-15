#include<bits/stdc++.h>
#include "testlib.h"
using namespace std;


int main() {
	rnd.setSeed(10);

    int number_of_candies=15,number_of_kids=1000,t=1,i,j,k,tmp;

    cout << t << "\n";

    while(t--){
        cout << number_of_candies << " " << number_of_kids << " " << 1 << "\n";

        for(i=0;i< number_of_kids;i++){
            bool candies[ number_of_candies+1 ]={0};
            k=rnd.next(1, number_of_candies);
            cout << k << " ";
            for(j=0;j<k;j++){
                do{
                    tmp=rnd.next(1, number_of_candies);
                }while(candies[tmp]);
                candies[tmp]=true;
                cout << tmp << " ";
            }
            cout << "\n";
        }
    }





	return 0;
}
