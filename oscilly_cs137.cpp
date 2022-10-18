#include <iostream> 
#include <string> 
#include <fstream> 
#include <vector> 
#include <numeric> 

using namespace std; 



int main() {
    string line; 
    vector<string> arr; 
    ifstream in("/Users/dk/Downloads/Cs137.SPE"); 
    if (in.is_open()) {
        while (getline(in, line)) {
            arr.push_back(line); 
        }
    }
    in.close();   

    //cout << arr.size() << endl; 

    vector<float> arr_fig; 
    
    for(int i = 0; i < arr.size(); i++) {
        if ((i > 8) and (i < arr.size()-8)) {
            arr_fig.push_back(stof(arr[i])); 
        }
    }

    //cout << arr_fig.size() << endl; //вывод количества чисел с учетом того, что мы выкинули ненужное 

    float avg = accumulate( arr_fig.begin(), arr_fig.end(), 0.0) / arr_fig.size(); 

    cout << avg << endl;

    avg *= 5.85;

    vector<float> arr_line[2];
    for(int i = 0; i < arr_fig.size(); i++){ 
        if (arr_fig[i] > avg) {
            arr_line[0].push_back(i);
            arr_line[1].push_back(arr_fig[i]);
        }
    }
        for(int i = 0; i < arr_line[1].size(); i++){ 
            //cout << arr_line[0][i] << " - " << arr_line[1][i] << "; "; 
    }

    vector<float> groups[3];

    int sz = -1, tz, sum = 0, k = 0; 
    bool fe_key = false; 
    for(int i = 0; i < arr_line[1].size(); i++){ 
        if (fe_key == false) { 
            tz = arr_line[0][i]; 
            sum += arr_line[1][i];
            groups[0].push_back(0);
            groups[1].push_back(0);
            groups[2].push_back(0);
            groups[1][k] = tz; 
            fe_key = true; 
        }
        else if (sz == -1) {
            sz = tz;
            tz = arr_line[0][i]; 
            sum += arr_line[1][i];
            if (tz - sz != 1) {
                groups[2][k] = sz;
                groups[0][k] = sum;
                sum = 0;
                k++;
            }
        }
        else {
            sz = tz; 
            tz = arr_line[0][i]; 
            sum += arr_line[1][i];
            if (tz - sz != 1) {
                groups[0].push_back(0);
                groups[1].push_back(0);
                groups[2].push_back(0);
                groups[2][k] = sz;
                groups[0][k] = sum;
                sum = 0;
                k++;
                groups[1][k] = tz; 
            }
        }
    }
    groups[2][k] = tz;
    groups[0][k] = sum;
    sum = 0;

    /*
    for(int i = 0; i < groups[0].size(); i++) { 
        cout << "[" << groups[0][i] << " | " << groups[1][i] << " | " << groups[2][i] << "] " << endl;
    }
    */

    k = 0; // номер группы с максимальной суммой 
    int buf = -1;
    for(int i = 0; i < groups[0].size(); i++) {
        if (groups[0][i] > buf) { 
            k = i;
            buf = groups[0][i];
        }
    }

    //cout << k;

    //cout << "[" << groups[0][k] << " | " << groups[1][k] << " | " << groups[2][k] << "]" << endl;

    vector<float> gppp[3]; //группа пика полного поглащения
    float p = 100.0 / groups[0][k];
    float ngm, i_ngm; 
    buf = -1;

    for(int i = groups[1][k]; i <= groups[2][k]; i++) { 
        if(p * arr_fig[i] > 5){
            gppp[0].push_back(i);
            gppp[1].push_back(arr_fig[i]);
            gppp[2].push_back(p * arr_fig[i]);
        }

        if (arr_fig[i] > buf) { 
            ngm = i;
            buf = arr_fig[i];
        }
    }

    float shift = 0;

    for(int i = 0; i < gppp[0].size(); i++) { 
        if (gppp[0][i] < ngm) { 
            shift -= gppp[2][i];
        }
        else if (gppp[0][i] > ngm) {
            shift += gppp[2][i];
        }
        else { 
            i_ngm = i;
        }
    }


    string huinya = arr[arr.size() - 4];
    int probel; 
    probel = huinya.find(" ");
    float b, a; 
    b = stof(huinya.substr(0, probel));
    //cout << b <<endl;
    a = stof(huinya.substr(probel+1, huinya.size()));
    //cout << a << endl;

    float answer; 
    answer = (gppp[1][i_ngm] - gppp[1][i_ngm + 1])*(1 - (shift/100.0)) + gppp[1][i_ngm + 1];

    float enrg, razresheniye, s;
    enrg = answer * a + b; 
    razresheniye = gppp[0].size() / gppp[0][i_ngm];
    for(int i = 0; i < gppp[0].size(); i++) { 
       s += gppp[1][i];
    }

    /*
    for(int i = 0; i < gppp[0].size(); i++) { 
        cout << "[" << gppp[0][i] << " | " << gppp[1][i] << " | " << gppp[2][i] << "] " << endl;
    }
    */

    
    ofstream out; // вывод из программы в файл 
    out.open("/Users/dk/Downloads/out1.txt"); 

    out << "Смещенный пик: " << answer  << endl << endl; 
    out << "Левая граница: " << gppp[0][0]  << endl; 
    out << "Правая граница: " << gppp[0][gppp[0].size()-1]  << endl << endl;
    out << "Канал пика: " << gppp[0][i_ngm]  << endl; 
    out << "Значение в пике: " << gppp[1][i_ngm]  << endl <<endl;
    out << "Энергия: " << enrg  << endl; 
    out << "Разрешение: " << razresheniye  << endl;  
    out << "Площадь: " << s  << endl; 


    out.close();
    
    return 0;
}