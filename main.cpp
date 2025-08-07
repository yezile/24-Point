#include<bits/stdc++.h>
using namespace std;
bool er; 
struct fr{
	int d,n;//分母 分子
	fr(int n = 0, int d = 0) : n(n), d(d) {}
	void Yue(){  //约分
		if(n==0){
			er=1;
		} 
		int g=__gcd(d,n);
		d=d/g;
		n=n/g;
	}
	void Fu(int a,int b){
		n=a,d=b;
	}
	void Tong(fr &b){ 
		//通分

		this->Yue();
		if(er==1){
			return ;
		}
		b.Yue();
		if(er==1){
			return ;
		}
		int l=this->d*b.d/__gcd(this->d,b.d);
		this->n=this->n*(l/this->d);
		this->d=this->d*(l/this->d);
		
		b.n=b.n*(l/b.d);
		b.d=b.d*(l/b.d);
	}
	fr operator+(const fr& other) const {
		fr now;
		now.d=d,now.n=n;
		fr next;
		next.d=other.d,next.n=other.n;
		now.Tong(next);
		fr Ans;
		Ans.d=now.d;
		Ans.n=now.n+next.n;
		Ans.Yue();
		return Ans;
    }
	fr operator-(const fr& other) const {
 		fr now;
 		now.d=d,now.n=n;
 		fr next;
 		next.d=other.d,next.n=other.n;
 		now.Tong(next);
 		fr Ans;
 		Ans.d=now.d;
 		Ans.n=now.n-next.n;
 		if(Ans.n<=0) {
 			er=1;
 			return Ans;
		 } 
 		Ans.Yue();
 		return Ans;
     }
     fr operator*(const fr& other) const {
  		fr now;
  		now.d=d,now.n=n;
  		fr next;
  		next.d=other.d,next.n=other.n;
  		now.Yue();
  		next.Yue();
  		fr Ans;
  		Ans.d=now.d*next.d;
  		Ans.n=now.n*next.n;
  		Ans.Yue();
  		return Ans;
      }
	fr operator/(const fr& other) const {
  		fr now;
  		now.d=d,now.n=n;
  		fr next;
  		next.d=other.n,next.n=other.d;
  		now.Yue();
  		next.Yue();
  		fr Ans;
  		Ans.d=now.d*next.d;
  		Ans.n=now.n*next.n;
  		Ans.Yue();
  		return Ans;
      }

};

int a[10];
char op[10]={' ','+','-','*','/'};
int vis[100][100][100][100];
/*
1    2   3    4     5
(( A    B  ) C )  D
(  A  ( B    C )) D
(  A    B )( C    D  )
   A (( B    C )  D  )
   A  ( B (  C    D  ))
*/
string kuoL[10][10]={{},{"((","","","",""},{"(","(","","",""},{"(","","(","",""},{"","((","","",""},{"","(","(","",""}};
string kuoR[10][10]={{},{"","",")",")",""},{"","","","))",""},{"","",")","",")"},{"","","",")",")"},{"","","","","))"}};

int pl[1005]={0,1234,1243,1324,1342,1423,1432,2134,2143,2314,2341,2413,2431,3124,3142,3214,3241,3412,3421,4123,4132,4213,4231,4312,4321};

fr ji(fr a,fr b,int fuhao){
	if(fuhao==1) return a+b;
	if(fuhao==2) return a-b;
	if(fuhao==3) return a*b;
	if(fuhao==4){
		if(b.n==0){
			er=1;
			return -1;
		}
		return a/b;
	}
}
void mei24(){
	fr num[5],ans1;
	int i=1,i1,i2,i3,i4;
	for(int i5=1;i5<=15;i5++){
	for(int i6=1;i6<=15;i6++){
	for(int i7=1;i7<=15;i7++){
	for(int i8=1;i8<=15;i8++){
		vis[i5][i6][i7][i8]=0;}}}}
	long long cnt=0;
	while(i<=24){

	i1=pl[i]%10,i2=pl[i]/10%10,i3=pl[i]/100%10,i4=pl[i]/1000;
	if(vis[a[i1]][a[i2]][a[i3]][a[i4]]==1){
		i++;	
		continue;
		
	}
	vis[a[i1]][a[i2]][a[i3]][a[i4]]=1;

	for(int i5=1;i5<=4;i5++){
	for(int i6=1;i6<=4;i6++){
	for(int i7=1;i7<=4;i7++){
	for(int i8=1;i8<=5;i8++){
		num[1].Fu(a[i1],1);num[2].Fu(a[i2],1);num[3].Fu(a[i3],1);num[4].Fu(a[i4],1);
//		cout<<i1<<i2<<i3<<i4<<endl; 

		if(i8==1) ans1=ji(ji(ji(num[1],num[2],i5),num[3],i6),num[4],i7);
		if(i8==2) ans1=ji(ji(num[1],ji(num[2],num[3],i6),i5),num[4],i7);
		if(i8==3) ans1=ji(ji(num[1],num[2],i5),ji(num[3],num[4],i7),i6);
		if(i8==4) ans1=ji(num[1],ji(ji(num[2],num[3],i6),num[4],i7),i5);
		if(i8==5) ans1=ji(num[1],ji(num[2],ji(num[3],num[4],i7),i6),i5);
		if(er==1) {
			er=0;
			continue;
		}
		ans1.Yue();
//		if(i8==2){
//			cout<<kuoL[i8][0]<<num[1].n<<op[i5];
//						cout<<kuoL[i8][1]<<num[2].n<<kuoR[i8][2]<<op[i6]<<kuoL[i8][2];
//						cout<<num[3].n<<kuoR[i8][3]<<op[i7];
//						cout<<num[4].n<<kuoR[i8][4];
//						cout<<'='<<ans1.n<<'/'<<ans1.d
//;						cout<<endl;
//		}
//		cout<<ji(ji(num[1],num[2],i5),num[3],i6).n<<' '<<ji(ji(num[1],num[2],i5),num[3],i6).d<<endl;
		cout<<kuoL[i8][0]<<num[1].n<<op[i5];
			cout<<kuoL[i8][1]<<num[2].n<<kuoR[i8][2]<<op[i6]<<kuoL[i8][2];
			cout<<num[3].n<<kuoR[i8][3]<<op[i7];
			cout<<num[4].n<<kuoR[i8][4];
			
			
		if(ans1.d==1&&ans1.n==24){
			cout<<endl;

		}
		else{
			cout<<"\r";
		}
	}}}}
	i++;	
	}

}
char numberL[30]={' ','1','2','3','4','5','6','7','8','9','X','J','Q','K'};
map<char,int >numberL1;
int main(){
	while(1){

	cout<<"请输入 4 个数字 范围(1~64) ：";
	
	for(int i=1;i<=4;i++){
		char inC;
		cin>>a[i];
		 
//		a[i]=numberL1[inC];
	}
	for(int i=1;i<=4;i++){
	
		 while(a[i]<1||a[i]>64){
			printf("第%d个数字输入错误，请再次输入：",i);
			cin>>a[i];
		}
//		a[i]=numberL1[inC];
	}
	
	mei24();
			
	}
	return 0;
}
