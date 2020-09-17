//Assignment 3: gcd (worst case)
//Author: Aashima Mehta
// The code below shows two ways of doing the time elapsed code. 1) using chrono 2) sys/time.h
// if running the code on Visual Studio do it by uncommenting chrono statements 
//      and commenting sys/time.h statements

#include<iostream>
//#include<time.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>
//#include<chrono>
//#include<vector>
using namespace std;
//using namespace std::chrono;

int COUNT = 0; //Global Variable
//auto start = high_resolution_clock::now();
//int gettimeofday(struct timeval* tv, struct timezone* tz);

int gcd(int a, int b) {
	COUNT++;
	if (a % b == 0)
		return b;
	return gcd(b, a % b);
}

//operation that takes in the n to calculate max gcd
void print(int n) {
    struct timeval end, start;
    gettimeofday(&start, NULL);
    
    for (int i = 8; i <= n; i++) {
        int max = 0;
        int ra = 0;
        int rb = 0;
        for (int b = 8; b <= i; b++) {
            for (int a = 1; a <= b; a++) {
                gcd(b, a); //int c = gcd(b, a);
                if (max < COUNT) {
                    max = COUNT;
                    ra = a;
                    rb = b;
                }
                COUNT = 0; //reset
            }
        }
		////print the line
        //auto end = high_resolution_clock::now();
        //end = time(NULL);
        gettimeofday(&end, NULL);
        long seconds = (end.tv_sec - start.tv_sec);
        long millis = ((end.tv_sec * 1e3) + (end.tv_usec * 1e-3)) - (
                        (start.tv_sec * 1e3) + (start.tv_usec * 1e-3) );
        cout << "At i = " << i << "; gcd (" <<
            ra << ", " << rb << ") = 1 took " <<
            max << " modulus operations. Time = " << seconds;  //<<
        cout << "s or " << millis << "ms" << endl;

        /*cout << millis << endl;*/

        //std::chrono::duration<double> duration = (end - start);  
         //   cout << duration.count() << "s or "<< duration.count() * 1000 << "ms "<<endl;   
	}
}


int main() {
	cout << "=====================" << endl;
    print(30);
	cout << "=====================" << endl;
}