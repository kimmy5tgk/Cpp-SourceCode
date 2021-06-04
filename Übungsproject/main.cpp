#include<iostream>
#include<iomanip>
#include <map>
#include <algorithm>
#include<cmath>
#define MAXGRAD (10+1)


using namespace std;

int isPalindrome(int);
void countPal(int, int);
void caculatePolynom();
void intervalbisection();


int isPalindrome(int n) {
    int revers = 0;
    for (int i = n; i > 0; i /= 10) {
        revers = revers * 10 + i % 10;
        
    }

    // if n and rev are same, then n is palindrome
    return revers;
}
void countPal(int minNum, int maxNum) {
    int i = minNum;
    int k = maxNum;
    
    for (i; i <= k; i++) {
        for (int j = i; j <= k; j++) {
            int mul = i * j;
            if (isPalindrome(mul) == mul) {
                cout << i << " * " << j << " = " << mul << "\n";
            }
        }
    }

}

unsigned int rand_int() {
	unsigned int result = 0;
	for (unsigned int i = 0; i < sizeof(int); ++i) {
		result = (result << 8) + rand() % 256;
	}
	return result;
}

int rand_range(int lower, int upper) {
	if (lower > upper) { // Swap if lower>upper  
		swap(lower, upper);
	}
	return rand_int() % (upper - lower + 1) + lower;
}

int GenerateRandomNumbers(int* result, int lower, int upper, int count) {

	if (lower > upper) { // Swap if lower>upper
		swap(lower, upper);
	}

	if (count > upper - lower + 1) { // It is impossible to generate the array
		return 0;
	}

	int diff = upper - lower;

	for (int i = 0; i <= count; ++i) { // Initialize the array with the first numbers
		result[i] = i + lower;
	}

	map<int, int> number_map;

	for (int i = 0; i <= count; ++i) {
		int index = rand_range(i, diff);
		if (index <= count) { // The index is in the array, so swap the items
			swap(result[i], result[index]);
		}
		else {
			map<int, int>::iterator it = number_map.find(index + lower);
			if (it != number_map.end()) { // Lookup the number_map
				swap(it->second, result[i]);
			}
			else {
				number_map.insert(make_pair(index + lower, result[i])); // Add the item into the number_map
				result[i] = index + lower;
			}
		}
	}

	return count;
}

// y= a[0]x0 + a[1]x1 +a[2]x2+...+ a[n]xn
void caculatePolynom() {

	int i, n;
	float x, y;
	float a[MAXGRAD];
	cout << "Eingabe Grad des Polynoms >";
	cin >> n;
	cout << "Eingabe der Koeffizienten >";
	for (i = 0; i <= n; i++) {
		cout << "a[" << i << "]: "; cin >> a[i];
	}
	cout << "Eingabe x-Wert: "; cin >> x;
	y = 0;
	cout << setiosflags(ios::fixed)
		 << setprecision(3);
	for (i = n; i >= 0; i--)
		y = y * x + a[i];
	cout << endl << "y " << y;
	return;
}

void intervalbisection() {
	float zahl, minlimit, maxlimit, epsilon, fMin, fMax, average, fAverage;

	int iter = 0;
	do {
		cout << "Eingabe: zahl minlimit maxlimit epsilon";
		cin >> zahl >> minlimit >> maxlimit >> epsilon;
		fMin = minlimit * minlimit - zahl;
		fMax = maxlimit * maxlimit - zahl;
	} while (fMin * fMax >= 0);
	do {
		iter++;
		average = (minlimit + maxlimit) / 2;
		fAverage = average * average - zahl;
		if (fMin * fAverage > 0) {
			minlimit = average;
		}
		else {
			maxlimit = average;
		}
	} while (fabs(minlimit - maxlimit) > epsilon);
	cout << "Die Wurzel ist " << (minlimit + maxlimit) / 2 << endl;
	cout << "Standardfunktion: " << sqrt(zahl) << endl;
	cout << "Iterationen: " << iter << endl;
	cout << endl << "Programmende";
	return ;
}

int main() {
	 /*
	 srand(time(0));
	int result[10];
	 Generate 10 random numbers within the range 1 to 100
	GenerateRandomNumbers(result, 1, 49, 10);

	for (int i = 0; i < 10; ++i)
		cout << result[i] << endl;
	 
	 */
	//caculatePolynom();
	intervalbisection();
	return 0;
}

