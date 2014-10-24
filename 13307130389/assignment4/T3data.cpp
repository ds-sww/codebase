#include<cstdio>
#include<cstring>
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<fstream>

using namespace std ;

int main()
{
    
    int n = 0 , k = 0 ;
    int data = 0 ;
    srand( time(NULL)) ;
    do
    {
    std::ofstream fout; 
    fout.open("in.txt");
    while( n <= 0 || n < 70000 ) n = rand()*rand() % 100001 ; 
    while( k < 1 ) k = rand() % n ;
    fout << n  <<" " << k << endl ;
    for( int i = 1 ; i <= n ; i ++ )
       fout << rand()*rand() % 100000 - 50000 << " " ;
    fout.close();
    double time1 , time2 , time3 ;
    time1 = clock() ;
    system("T3.exe");
    time2 = clock() ;
    system("p3_qini7.exe");
    time3 = clock() ;
    

    cout << "Data : " << ++data  << endl ;
    cout << "Time1 : " << (time2 - time1)/CLOCKS_PER_SEC << " Time2 : "  << (time3-time2)/CLOCKS_PER_SEC << endl ;
    }
    //while(1);
    while( system("fc out.txt out1.txt") == 0 );
    
    return 0;
}
