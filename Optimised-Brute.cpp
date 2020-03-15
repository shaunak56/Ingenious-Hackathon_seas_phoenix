#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define mod 1000000007

int solve(){
    int t, number_of_candies, number_of_kids, k, i, j, candy, truck1, truck2,  both;
    int minumum_time;
    
    
    cin >> number_of_candies >> number_of_kids >> t;
    
    minumum_time=INT_MAX;
    
    int pow2[number_of_candies+1];
    
    int candies_wanted[number_of_kids];
    
    pow2[0]=1;
    for(i=1;i<=number_of_candies;i++)
        pow2[i]=pow2[i-1]+pow2[i-1];
    
    for(i=0;i<number_of_kids;i++){
        cin >> k; // j = number of candies ith kid wants
        candies_wanted[i]=0;
        for(j=0;j<k;j++){
            cin >> candy;
            candies_wanted[i]|=pow2[candy-1];
        }
    }

    for(int combination=0;combination<pow2[number_of_candies];combination++){
        truck1=0;
        
        for(i=0;i<number_of_kids;i++)
            if((combination&candies_wanted[i])==candies_wanted[i])
                truck1++;
            
        truck2=0;
        combination=pow2[number_of_candies]- combination-1; 
        
        for(i=0;i<number_of_kids;i++){
            if((combination&candies_wanted[i])==candies_wanted[i])
                truck2++;
        }
        
        both=number_of_kids-truck1-truck2;
        
        if(truck2==0)
            minumum_time=min(minumum_time,number_of_kids*t);
        else    
            minumum_time=min(minumum_time, both+max(truck1,truck2) );
        
        combination=pow2[number_of_candies]- combination; 
    }
    
    return minumum_time;
}

int main(){
    FIO;
    // O( (2^number_of_candies)*(number_of_candies+number_of_kids) for each test case 
    int number_of_test_cases;

    cin >> number_of_test_cases;
    while(number_of_test_cases--)
        cout << solve() << "\n";
	return 0;
}
