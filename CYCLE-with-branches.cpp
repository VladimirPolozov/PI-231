/****************************************
* Author: Владимир Полозов              *
* Name: Циклы с ветвлением              *
* URL: https://onlinegdb.com/-vMvyVbpvK *
*****************************************/
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    double p, h, p1, F, l[4], R, K, phi;
    cout << "плотность жидкости p (в г на см3) = ";
    cin >> p; // 1,03
    cout << "на глубине h (в см) = ";
    cin >> h; // 85
    cout << "шарнирно закреплен брус плотностью p1 (в г на см3) = ";
    cin >> p1; // 0,68
    cout << "и его поперечное сечение F (в см2) = ";
    cin >> F; // 16
    cout << "Введите 4 значения (каждое на отдельной строке) длины бруса l (в см)\n";
    for (int index_of_length_value = 0; index_of_length_value < 4; ++index_of_length_value) {
        cin >> l[index_of_length_value]; // 90; 100; 150; 200;
    }
    
    cout << fixed;
    cout << setprecision(3);
    for (int index_of_length_value = 0; index_of_length_value < 4; ++index_of_length_value) {
        K = l[index_of_length_value] / h - sqrt(p / p1);
        
        if (K > 0) {
            R = l[index_of_length_value] * F * p1 * ( sqrt(p / p1) - 1 );
            phi = acos( h / l[index_of_length_value] * sqrt(p / p1) );
        } else if (K < 0) {
            R = l[index_of_length_value] * F * p1 * ( (h * p) / (l[index_of_length_value] * p1) - 1 );
            phi = 0;
        } else {
            continue;
        }
        
        cout << "R = " << R << "\tK = " << K << "\tphi = " << phi << endl;
    }
    
    return 0;
}
