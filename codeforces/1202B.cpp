#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu unsigned long long int
#define fr(va,beg,end) for(lli va=beg;va<end;va++)
#define pb push_back
#define rt return 0

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	vector<lli> v;
	string st;
	cin>>st;
	lli x,y;
	lli arr[10][10];
	lli dp[11][11][11][11];
	fr(i,0,10){
		fr(j,0,10){
			arr[i][j] = -2;
		}
	}

	for(int x=0;x<=9;x++){
		for(int y=0;y<=9;y++){
			for(int i=0;i<=9;i++){
				for(int j=0;j<=9;j++){
					lli countx,county;
                    int flag = 0,minn=1000;
					for(countx=0;countx<=10;countx++){
						for(county=0;county<=10;county++){
							if(countx != 0 || county != 0){
								lli p = i + (x*countx)%10 + (y*county)%10;
								if(p % 10 == j){
                                    flag = 1;
									if(countx + county - 1 < minn){
										minn = county + countx - 1;
									}
								}
							}
						}
					}
                    if(flag == 1){
                        dp[x][y][i][j] = minn;
                    }
                    else{
                        dp[x][y][i][j] = -1;
                    }
				}
			}
		}
	}

	for(lli x = 0;x <10;x++){
		for(lli y = x;y<10;y++){
			lli ans = 0;
			for(lli i=1;i<st.length();i++){
				char r = st[i-1];
				int q = r - '0';
				char l = st[i];
				int flag = 0;
				lli minn = 1000;
				int t = l - '0';
                lli p = dp[x][y][q][t];
                if(p == -1){
                    ans = -1;
                    break;
                }
                else{
                    ans += dp[x][y][q][t];
                }
				// lli countx = 0,county = 0;
				// for(lli countx = 0;countx <= 10;countx++){
				// 	for(lli county=0;county<=10;county++){
				// 		lli p = q + (x*countx)%10 + (y*county)%10;
				// 		if(p % 10 == t){
				// 			flag = 1;
				// 			if(countx + county -1 < minn){
				// 				minn = countx + county -1 ;
				// 			}
				// 		}
		 	// 		}
				// }
				// if(flag == 0){
				// 	ans = -1;
				// 	break;
				// }
				// else{
				// 	ans += minn;
				// }
			}
			arr[x][y] = ans;
		}
	}

	for(lli i=0;i<10;i++){
		for(lli j=0;j<10;j++){
			if(arr[i][j] == -2){
				cout<<arr[j][i]<<" ";
			}
			else{
				cout<<arr[i][j]<<" ";
			}
		}
		cout<<endl;
	}

rt;
}
		
