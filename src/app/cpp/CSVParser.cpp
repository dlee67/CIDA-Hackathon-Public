#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <iostream>

using namespace std;

struct SleepData {
    string time_new;
    string minutes_mets;
    string minutes_steps;
    string ap_posture;
};

vector<SleepData> read_record() {

    cout << "Invoked read_record" << endl;

    fstream fin;
    fin.open("../../assets/data/master_minbymin.csv", ios::in);

    vector<SleepData> row;
    string line, word, temp;

    while (!fin.eof()) {

        struct SleepData data;
        getline(fin, line);
        stringstream s(line);
        getline(s, word, ',');
        data.time_new = word;
        getline(s, word, ',');
        data.minutes_mets = word;
        getline(s, word, ',');
        data.minutes_steps = word;
        getline(s, word, ',');
        data.ap_posture = word; 
        
        row.push_back(data);
    }

    return row;
} 
