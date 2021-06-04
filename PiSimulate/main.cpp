#include <time.h>
#include <iostream>
#include <iomanip> 
#include <cstdlib> 

   // Defines precision for x and y values. More the
   // interval, more the number of significant digits
#define INTERVAL 10000
using namespace std;

void simulatePi();
void lottery();

void simulatePi() {
    int interval, i;
    double rand_x, rand_y, origin_dist, pi;
    int circle_points = 0, square_points = 0;

    // Initializing rand()
    srand(time(NULL));

    // Total Random numbers generated = possible x
    // values * possible y values
    for (i = 0; i < (INTERVAL * INTERVAL); i++) {

        // Randomly generated x and y values
        rand_x = double(rand() % (INTERVAL + 1)) / INTERVAL;
        rand_y = double(rand() % (INTERVAL + 1)) / INTERVAL;

        // Distance between (x, y) from the origin
        origin_dist = rand_x * rand_x + rand_y * rand_y;

        // Checking if (x, y) lies inside the define
        // circle with R=1
        if (origin_dist <= 1)
            circle_points++;

        // Total number of points generated
        square_points++;

        // estimated pi after this iteration
        pi = double(4 * circle_points) / square_points;

        // For visual understanding (Optional)
        cout << rand_x << " " << rand_y << " " << circle_points
            << " " << square_points << " - " << pi << endl << endl;

        // Pausing estimation for first 10 values (Optional)
        //if (i < 20)
          //  getchar();
    }

    // Final Estimated Value
    cout << "\nFinal Estimation of Pi = " << pi;
    return;
}

void lottery() {
    int anzahl, i;
    int x, j; // 1...49 
    int k; // 1...6 
    bool schon_gezogen[50];
    srand(time(NULL));
    cout << "Anzahl der Ziehungen > ";
    cin >> anzahl;
    for (i = 1; i <= anzahl; i++)
    {
        for (j = 1; j <= 49; j++)
            schon_gezogen[j] = false;
        for (k = 1; k <= 6; k++)
        {
            do
                x = rand() % 49 + 1;
            while (schon_gezogen[x]);
            schon_gezogen[x] = true;
        }
        for (j = 1; j <= 49; j++)
            if (schon_gezogen[j])
                cout << setw(3) << j;
        cout << endl;
    }
    return ;


}

int main()
{
    //simulatePi();
    //lottery();

    return 0;
}