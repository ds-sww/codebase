#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>  
#include<iostream>
using namespace std;
int main()
{
    printf("I am not accustomed to github. Hello world!\n");
    return 0;
}
/*#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
#define pi 3.1415926535897932384626433832795
int n,lgn;
double tmp;
struct complex
{
	double real,virt;
	complex(){ real=virt=0; }
	complex(double s,double t):real(s),virt(t){}
	friend complex operator +(const complex A,const complex &B)
	{
		complex C;
		C.real=A.real+B.real;
		C.virt=A.virt+B.virt;
		return C;
	}
	friend complex operator -(const complex A,const complex &B)
	{
		complex C;
		C.real=A.real-B.real;
		C.virt=A.virt-B.virt;
		return C;
	}
	friend complex operator *(const complex A,const complex &B)
	{
		complex C;
		C.real=A.real*B.real-A.virt*B.virt;
		C.virt=A.real*B.virt+A.virt*B.real;
		return C;
	}
}*a,*b,*c,*U,*V,*C,*D;
void print(complex A) { printf("%lf + %lfi\n",A.real,A.virt); }
int reverse(int k)
{
    int ret=0,now=lgn-1;
    while (k>0)
    {
       ret+=(1<<now)*(k % 2);
       k/=2;
       now--;
    }
    return ret;
}
complex *DFT(complex *a,int n,int opt)
{
	complex *spe=(complex *)malloc(n*sizeof(complex)),wm;
	for (int i=0;i<n;i++) spe[reverse(i)]=a[i];
	int m;
	for (int s=1;s<=lgn;s++)
	{
		m=1<<s;
		wm=complex(cos(2*pi*opt/m),sin(2*pi*opt/m));
		for (int k=0;k<n;k+=m)
		{
			complex w=complex(1,0);
			for (int j=0;j<m/2;j++)
			{
				complex t=w*spe[k+j+m/2];
				complex u=spe[k+j];
				spe[k+j]=u+t;
				spe[k+j+m/2]=u-t;
				w=w*wm;
			}
		}
	}
	return spe;
}
complex *FFT(int n)
{
	U=(complex *)malloc(n*sizeof(complex));
	V=(complex *)malloc(n*sizeof(complex));
	C=(complex *)malloc(n*sizeof(complex));
	D=(complex *)malloc(n*sizeof(complex));
	U=DFT(a,n,1);
	V=DFT(b,n,1);
	for (int i=0;i<n;i++) C[i]=U[i]*V[i];
	D=DFT(C,n,-1);
	for (int i=0;i<n;i++) D[i]=D[i]*complex(1/(double)n,0);
	return D;
	//coefficient : C[k]  -j,n
}
int main()
{
	freopen("FFT.in","r",stdin);
	freopen("FFT.out","w",stdout);
	//printf("Please enter the degree of Polynomial|n % 2 must be 0:\n");
	scanf("%d",&n);
	int t=1;
	lgn=1; //important for n'=8 lgn=3;
	while (t<n) { t*=2; lgn++; }
	//printf("Please enter Polynomial A | n coefficient numbers, starting from 0;\n");
	a=(complex *)malloc(2*t*sizeof(complex));
	b=(complex *)malloc(2*t*sizeof(complex));
	c=(complex *)malloc(2*t*sizeof(complex));
	for (int i=0;i<n;i++) { scanf("%lf",&tmp); a[i]=complex(tmp,0); }
	//printf("Please enter Polynomial B | n coefficient numbers, starting from 0;\n");
	for (int i=0;i<n;i++) { scanf("%lf",&tmp); b[i]=complex(tmp,0); }
	for (int i=n;i<2*t;i++) a[i]=b[i]=complex(0,0);
	n=t;
	c=FFT(2*n);
	for (int i=0;i<2*n;i++) print(c[i]);
	//system("pause");
	return 0;
}
*/
