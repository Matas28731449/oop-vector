#include "headers/references.h"

void student::setGrade(int a) {
    grade.reserve(grade.size() + 1);
    grade.push_back(a);
}
void input(vector<student> &arr, string &opt) {
    student tmp;
    string  req = " ";
    cout << "'in' to input the data manually ;\n'gf' to generate random data file ;\n'rf' to read the data from file .\n";
    cout << "Enter your choice: "; cin >> opt;
    while(cin.fail() or (opt != "in" && opt != "gf" && opt != "rf")) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Incorrect form. Try again: "; cin >> opt;
    }
    if(opt == "in") {
        do {
            userInput(tmp);
            arr.push_back(tmp);
            tmp.clearGrade();
            cout << "Enter 'end' if all students are entered or any key to continue: "; cin >> req;
        } while(req != "end");
    }
    else if(opt == "gf") {
        do {
            fileGenerator();
            cout << "Enter 'end' to stop generating random data files or press any key to continue: "; cin >> req;
        } while(req != "end");
        exit(0);
    }
    else if(opt == "rf") fileInput(arr);
}
void output(vector<student> &arr, string tmp) {
    string opt = " ";
    //----------END OF THE PROGRAM----------
    while(opt != "vid" && opt != "med") {
        cout << "How would you like to calculate the final mark? Type 'vid' or 'med': "; cin >> opt;
    }
    //----------OUTPUT IN CONSOLE----------
    if(tmp == "in") {
        // cout << "-----------------------------------------------------------\n";
        // cout << left << setw(10) << "Vardas" << left << setw(14) << "Pavarde" << left << setw(12) << "Galutinis (Vid.) / Galutinis (Med.)\n";
        // cout << "-----------------------------------------------------------\n";
        // for(auto &i : arr) {
        //     opt == "vid" ? printf("%-9s %-13s %-19.2f \n", i.getName().c_str(), i.getSurname().c_str(), medium(i)) : printf("%-9s %-13s %23.2f \n", i.getName().c_str(), i.getSurname().c_str(), median(i));
        // }
    }
    //----------OUTPUT IN FILE----------
    else if(tmp == "rf") {
        // SORTING
        cout << "Sorting data...\n";
        auto start = std::chrono::high_resolution_clock::now();
        if(opt == "vid") {
            sort(arr.begin(), arr.end(),
            [] (student a, student b) {
                return a.getMedium() == b.getMedium() ? a.getSurname() > b.getSurname() : a.getMedium() > b.getMedium();
            });
        }
        else if(opt == "med") {
            sort(arr.begin(), arr.end(),
            [] (student a, student b) {
                return a.getMedian() == b.getMedian() ? a.getSurname() > b.getSurname() : a.getMedian() > b.getMedian();
            });
        }
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> difference = end - start;
        cout << "finished in: " << difference.count() << " s\n";
        // SPLITTING, strategy 3
        cout << "Splitting into two vectors (3nd strategy)...\n";
        start = std::chrono::high_resolution_clock::now();
        vector<student> fail;
        if(opt == "vid") {
            auto frac = find_if(arr.begin(), arr.end(), [] (student a) { return a.getMedium() < 5; }); // fracture
            fail.insert(fail.begin(), frac, arr.end());
            arr.erase(frac, arr.end());
        }
        else if(opt == "med") {
            auto frac = find_if(arr.begin(), arr.end(), [] (student a) { return a.getMedian() < 5; });
            fail.insert(fail.begin(), frac, arr.end());
            arr.erase(frac, arr.end());
        }
        fail.shrink_to_fit();
        arr.shrink_to_fit();
        end = std::chrono::high_resolution_clock::now();
        difference = end - start;
        cout << "finished in: " << difference.count() << " s\n";
        // TEMPLATE
        ofstream out[2];
        string   failRow = "",
                 passRow = "";
        char     entry[100];
        out[0].open("write/fail.txt");
        out[1].open("write/pass.txt");
        for(int i = 0; i < 2; i ++) {
            out[i] << "-------------------------------------------------------------------\n";
            out[i] << left << setw(14) << "Vardas" << left << setw(18) << "Pavarde" << left << setw(16) << "Galutinis (Vid.) / Galutinis (Med.)\n";
            out[i] << "-------------------------------------------------------------------\n";
        }
        // WRITING
        cout << "Writing into fail.txt...\n";
        start = std::chrono::high_resolution_clock::now();
        for(auto &i : fail) {
            opt == "vid" ? sprintf(entry, "%-13s %-17s %-18.2f \n", i.getName().c_str(), i.getSurname().c_str(), i.getMedium()) : sprintf(entry, "%-13s %-17s %23.2f \n", i.getName().c_str(), i.getSurname().c_str(), i.getMedian());
            failRow += entry;
        }
        fail.clear();
        out[0] << failRow;
        out[0].close();
        end = std::chrono::high_resolution_clock::now();
        difference = end - start;
        cout << "finished in: " << difference.count() << " s\n";
        cout << "Writing into pass.txt...\n";
        start = std::chrono::high_resolution_clock::now();
        for(auto &i : arr) {
            opt == "vid" ? sprintf(entry, "%-13s %-17s %-18.2f \n", i.getName().c_str(), i.getSurname().c_str(), i.getMedium()) : sprintf(entry, "%-13s %-17s %23.2f \n", i.getName().c_str(), i.getSurname().c_str(), i.getMedian());
            passRow += entry;
        }
        arr.clear();
        out[1] << passRow;
        out[1].close();
        end = std::chrono::high_resolution_clock::now();
        difference = end - start;
        cout << "finished in: " << difference.count() << " s\n";
    }
}
void fileInput(vector<student> &arr) {
    stringstream buf;   // buffer
    ifstream     in;    // input
    student      tmp;   // temporary
    string       row,
                 file;
    int          grade;

    system("ls read");
    cout << "Enter the name of the file to read from: "; cin >> file;
    try {
        cout << "Reading data...\n";
        auto start = std::chrono::high_resolution_clock::now();
        in.open("read/" + file);
        if(in.fail()) throw 6;
        buf << in.rdbuf();
        in.close();
        getline(buf, row); // reading just the first line of the data file
        int cnt = count(row.begin(), row.end(), 'N'); // searching for the amount of homework
        while(buf) {
            if(!buf.eof()) {
                buf >> row; tmp.setName(row);
                buf >> row; tmp.setSurname(row);
                for(int i = 0; i < cnt; i ++) {
                    buf >> grade;
                    tmp.setGrade(grade);
                }
                buf >> grade;
                tmp.setExam(grade);
                tmp.setMedium(medium(tmp));
                tmp.setMedian(median(tmp));
                tmp.clearGrade();
                arr.push_back(tmp);
            }
            else break;
        }
        buf.clear();
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> difference = end - start;
        cout << "finished in: " << difference.count() << " s\n";
    } catch(int e) {
        cout << "Error " << e << ": file not found\n"; exit(0);
    }
}
void userInput(student &tmp) {
    string opt = " ";   // option
    int    sum = 0,     // entered grade
           grd;         // sum of entered grades
    cout << "Enter the student's name and surname: "; cin >> opt; tmp.setName(opt); cin >> opt; tmp.setSurname(opt);
    cout << "Would you like to randomize the grades (type 'ran') or enter yourself? (any key to continue): "; cin >> opt;
    if(opt != "ran") {
        cout << "Enter the exam grade: "; cin >> grd; tmp.setExam(grd);
        while(cin.fail() || tmp.getExam() < 0 || tmp.getExam() > 10) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Incorrect form. Try again: "; cin >> grd; tmp.setExam(grd);
        }
        cout << "Enter the grades (any other symbol to stop): ";
        while(cin >> grd && grd >= 0 && grd <= 10) {
            if(tmp.getGrade().size() >= max) {
                cout << "You can enter a maximum of " << max << " grades per student.\n";
                break;
            }
            tmp.setGrade(grd);
            sum += grd;
        }
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if(sum == 0) {
            cout << "At least one grade that is not a symbol and higher than 0 must be entered! Try from the beginning.\n";
            tmp.clearGrade();
            userInput(tmp); // recursion
        }
        else cout << "In total " << tmp.getGrade().size() << " grades entered.\n";
    }
    else randInput(tmp);
}
void randInput(student &tmp) {
    int cnt = 0, // counter
        grd = 0; // generated grade
    tmp.setExam(randomize(1, 10)); // generated grade in a ten point system without 0 (student must participate in an exam)
    cout << "The exam grade: " << tmp.getExam() << "\n";
    cnt = randomize(1, max);
    cout << "The grades: ";
    for(int i = 0; i < cnt; i ++) {
        grd = randomize(0, 10); // generated grade in a ten point system with 0 (student may not submit his homework)
        tmp.setGrade(grd);
        i != cnt - 1 ? cout << grd << " " : cout << grd << "\n";
    }
}
double medium(student &tmp) {
    vector<int> grd = tmp.getGrade(); // temporary copy of grades
    int         sum = accumulate(grd.begin(), grd.end(), sum); // computing the sum of the given initial value and the elements in the given range
    return 0.4 * ((double)sum / grd.size()) + 0.6 * tmp.getExam();
}
double median(student &tmp) {
    vector<int> grd = tmp.getGrade(); // temporary copy of grades
    sort(grd.begin(), grd.end());
    return grd.size() % 2 == 0 ? 0.4 * ((grd[grd.size() / 2 - 1] + grd[grd.size() / 2]) / 2.0) + 0.6 * tmp.getExam() : 0.4 * grd[grd.size() / 2] + 0.6 * tmp.getExam();
}
int randomize(int beg, int end) { // beginning, ending
    mt19937 mt(static_cast<long unsigned int>(std::chrono::high_resolution_clock::now().time_since_epoch().count()));
    uniform_int_distribution<int> dis(beg, end);
    return dis(mt);
}
void fileGenerator() {
    stringstream buf;
    string       filename;
    int          homework,
                 students;
    // INPUTS
    cout << "Enter the name of the file (be sure to add *.txt file extension): "; cin >> filename;
    cout << "Enter the number of homework assignments per student: "; cin >> homework;
    while(cin.fail() || homework < 1) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "At least one homework assignment must be entered. Try again: "; cin >> homework;
        }
    cout << "Enter the number of students: "; cin >> students;
    while(cin.fail() || students < 1) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "At least one student must be entered. Try again: "; cin >> students;
        }
    // RANDOMIZER
    mt19937 mt(static_cast<long unsigned int>(std::chrono::high_resolution_clock::now().time_since_epoch().count()));
    uniform_int_distribution<int> dis(0, 10);
    // START
    cout << "Generating data...\n";
    auto start = std::chrono::high_resolution_clock::now();
    // TEMPLATE
    buf << left << setw(14) << "Vardas" << left << setw(18) << "Pavarde";
    for(int i = 0; i < homework; i ++) {
        buf << left << setw(10) << "ND" + to_string(i + 1);
    }
    buf << left << setw(10) << "Egz." << "\n";
    // GENERATOR
    for(int i = 0; i < students; i ++) {
        buf << left << setw(14) << "Vardas" + to_string(i + 1) << left << setw(18) << "Pavarde" + to_string(i + 1);
        for(int j = 0; j < homework; j ++) {
            buf << left << setw(10) << dis(mt);
        }
        buf << dis(mt) << "\n";
        if(i % (students / 100) == 0) {
            cout << 100 * i / students << "%\n";
        }
    }
    ofstream out("read/" + filename);
    out << buf.rdbuf();
    buf.clear();
    out.close();
    // END
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> difference = end - start;
    cout << "finished in: " << difference.count() << " s\n";
    cout << "File " << filename << " was generated.\n";
}
