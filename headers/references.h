#ifndef REFERENCES_H
#define REFERENCES_H

#include "library.h"

const int max = 100;

class person {
    protected:
        string name,
               surname;
    public:
        person() : name(""), surname("") { }

        inline string getName() const { return name; }
        inline string getSurname() const { return surname; }

        virtual void setName(string a) = 0;
        virtual void setSurname(string a) = 0;

        ~person() { }
};

class student : public person {
    private:
        vector<int> grade;
        int         exam;
        float       medium,
                    median;
    public:
        student() : exam(0), medium(0), median(0) { }

        inline string getName() const { return name; }
        inline string getSurname() const { return surname; }
        inline vector<int> getGrade() const { return grade; }
        inline int getExam() const { return exam; }
        inline double getMedium() const { return medium; }
        inline double getMedian() const { return median; }

        void setName(string a) { name = a; }
        void setSurname(string a) { surname = a; }
        void setGrade(int a);
        void clearGrade() { grade.clear(); }
        void setExam(int a) { exam = a; }
        void setMedium(double a) { medium = a; }
        void setMedian(double a) { median = a; }

        student(const student &other) {
            this->name = other.name;
            this->surname = other.surname;
            this->grade = std::move(other.grade);
            this->exam = other.exam;
            this->medium = other.medium;
            this->median = other.median;
        }
        student(student &&other) {
            this->name = other.name;
            this->surname = other.surname;
            this->grade = std::move(other.grade);
            this->exam = other.exam;
            this->medium = other.medium;
            this->median = other.median;
        }
        student &operator=(const student &other) {
            if(this != &other) {
                this->name = other.name;
                this->surname = other.surname;
                this->grade = std::move(other.grade);
                this->exam = other.exam;
                this->medium = other.medium;
                this->median = other.median;
            }
            return *this;
        }
        student &operator=(student &&other) {
            if(this != &other) {
                this->name = other.name;
                this->surname = other.surname;
                this->grade = std::move(other.grade);
                this->exam = other.exam;
                this->medium = other.medium;
                this->median = other.median;
                other.~student();
            }
            return *this;
        }
        ~student() { clearGrade(); }
};

void input(vector<student> &arr, string &opt);
void output(vector<student> &arr, string tmp);
void fileInput(vector<student> &arr);
void userInput(student &tmp);
void randInput(student &tmp);
double medium(student &tmp);
double median(student &tmp);
bool comparison(student &a, student &b);
int randomize(int beg, int end);
void fileGenerator();

#endif