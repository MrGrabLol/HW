#include <iostream>
#include <math.h>


using namespace std;

 int fact(int n) {
	long double f = 1;
	for(int i = 1; i <= n; i++) {
		f *= i;
	}
	return f;
}

int main() {
	
	double x, eps, sum, kf;
	int n;
	cin>>x>>eps;
	n = 1;
	kf = 1 + (x/2*sin(x/2)) + ((pow(x, 2)/2) - 1) * cos(x);
	sum = ((2 * pow(n, 2) + 1)/fact(2 * n)) * pow(x, 2 * n);
	cout<<"SUM1 = "<<sum<<endl;
	while (abs(kf - sum) > eps) {
		n++;
		if (n % 2 == 0) {
			sum = sum - ((2 * pow(n, 2) + 1)/fact(2 * n)) * pow(x, 2 * n);
		} else if (n % 2 == 1) {
			sum = sum + ((2 * pow(n, 2) + 1)/fact(2 * n)) * pow(x, 2 * n);
		}
	}
	
	cout<<"--------------"<<endl;
	cout<<"SUM = "<<sum<<endl;
	cout<<"STEPS = "<<n<<endl;
	
	return 0;
}
