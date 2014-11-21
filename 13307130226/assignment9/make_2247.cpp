//本来想打表玩的(虽然这个打表程序可以在0.5s内跑完),可惜poj有代码长度限制,这个程序仅供留恋


#include<iostream>
#include<fstream>
#define minnN 2000000001
using namespace std;
long long ans[10000];
int ansn;
int base[4]={2,3,5,7};
long long tmp,minn;
int main(){
	ofstream ofile;
	ofile.open("code.2247.cpp");
	ofile << "#include<iostream>" << endl;
	ofile << "using namespace std;" << endl;
	ofile << "int q[]={" << endl;
	
	
	
	//ofile << "0,1,2,3,4,5,6,7,8,9,10" << endl;
	ofile << "0,1,";
	ansn=1;
	ans[0]=1;
	while(ansn<=5842){
		minn=minnN;
		for(int i=0;i<ansn;i++)
			for(int j=0;j<4;j++)
				if((tmp=(ans[i]*base[j]))>ans[ansn-1]&&tmp<minn)
					minn=tmp;
		ans[ansn++]=minn;
		ofile << minn << ',';
		//cout << ansn <<' '<< minn << endl;
	}
	
		
	ofile << "};" << endl;
	ofile << "int i;char *f;" << endl;
	ofile << "int main(){" << endl;
	ofile << "  while(cin >> i){" << endl;
	ofile << "    if(i==0)return 0;" << endl;
	ofile << "    cout <<\"The \" << i;" << endl;
	ofile << "    switch(i%10){" << endl;
	ofile << "      case 1:f = \"st\";break;" << endl;
	ofile << "      case 2:f = \"nd\";break;" << endl;
	ofile << "      case 3:f = \"rd\";break;" << endl;
	ofile << "      default:f = \"th\";break;" << endl;
	ofile << "    }" << endl;
	ofile << "    if(i%100 < 20 && i%100 > 10)" << endl;
	ofile << "      f = \"th\";" << endl;
	ofile << "	  cout << f << \" humble number is \" << q[i] << '.'<< endl;"<<endl;
	ofile << "  }" << endl;
	ofile << "}"<< endl;
	ofile.close();
	return 0;
}