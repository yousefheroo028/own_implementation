#ifndef TESTS_STATISTICS_H
#define TESTS_STATISTICS_H

#include <bits/stdc++.h>

using namespace std;

template<class T>
class ungrouped_data {
protected:
    vector<T> data;
    vector<T> sorted_data;
    static int number_of_data;
    double mean;
    T median;
    unsigned int size;
    long double variance;
    string mode;
    long double standard_deviation;
public:
    ungrouped_data() {
        data = 0;
        sorted_data = 0;
        mean = 0;
        median = 0;
        variance = 0;
        standard_deviation = 0;
        number_of_data++;
        variance = 0;
        size = 0;
    }

    ungrouped_data(vector<T> d) {
        data = d;
        sort(d.begin(), d.end());
        sorted_data = d;
        number_of_data++;
        size = d.size();
        mean = 0;
        for (T i: data) mean += ((double) i / size);
        variance = 0;
        for (long double i: data) {
            variance += ((long double) ((i - mean) * (i - mean)) / (long double) size);
        }
        median = 0;
        if (size % 2) {
            median = sorted_data.at((size - 1) / 2);
        } else {
            median = (sorted_data.at((size / 2) - 1) + sorted_data.at(size / 2)) / 2;
        }
        standard_deviation = sqrtl(variance);
    }

    ungrouped_data(T n, vector<T> d) {
        data = d;
        sort(d.begin(), d.end());
        sorted_data = d;
        number_of_data++;
        mean = 0;
        for (T i: data) mean += ((double) i / size);
        variance = 0;
        for (T i: data) {
            variance += (((i - mean) * (i - mean)) / size);
        }
        median = 0;
        if (size % 2) {
            median = data.at((size - 1) / 2);
        } else {
            median = (data.at((size / 2) - 1) + data.at(size / 2)) / 2;
        }
        standard_deviation = sqrtl(variance);
        size = n;
    }

    friend ostream &operator<<(ostream &printData, ungrouped_data<T> &d) {
        printData << "Data = [";
        for (auto i = d.data.begin(); i != d.data.end() - 1; ++i) {
            printData << *i << ", ";
        }
        printData << d.data.back() << ']' << endl;
        return printData;
    }

    double get_mean() {
        return mean;
    }

    static void get_number_of_data() {
        cout << "Number of data sets = " << number_of_data;
    }

    T get_median() {
        return median;
    }

    vector<T> get_mode() {
        unsigned int max = 0;
        vector<T> modes;
        map<T, unsigned int> freq;
        for (T i: data) {
            freq[i]++;
            if (freq[i] > max) {
                max = freq[i];
            }
        }
        if (max > 1) {
            for (auto i = freq.begin(); i != freq.end(); ++i) {
                if (i->second == max) modes.push_back(i->first);
            }
        }
        return modes;
    }

    T get_range() {
        return (sorted_data.back() - sorted_data.front());
    }

    long double get_variance() {
        cout << "Variance = ";
        return variance;
    }

    unsigned int get_size() {
        cout << "Size = ";
        return size;
    }

    void show_sorted_data() {
        cout << "Sorted data = [";
        cout << sorted_data.front();
        sorted_data.erase(sorted_data.begin());
        for (auto i: sorted_data) cout << ", " << i;
        cout << ']';
    }

    float get_coefficient_of_variation() {
        cout << "Coefficient of variation = ";
        return (standard_deviation / mean) * 100;
    }

    long double get_standard_deviation() {
        cout << "Standard Deviation = ";
        return standard_deviation;
    }

    vector<vector<T>> get_possible_samples(const int &sample_size) {
        vector<vector<T>> temp(1 << size, vector<T>(0));
        vector<vector<T>> samples;
        if (sample_size > (signed int) size) {
            cout << "The sample size should be less than or equal to the population size.";
        } else if (sample_size < 1) {
            cout << "The sample size should be from 1 to " << size;
        } else {
            for (int i = 0; i < 1 << size; ++i) {
                for (int j = 0; j < size; ++j) {
                    if (__builtin_popcount(i) == sample_size) {
                        if ((i & (1 << j)) != 0) {
                            temp.at(i).push_back(data.at(j));
                        }
                    }
                }
            }
            sort(temp.begin(), temp.end());
            for (int i = 0; i < temp.size(); ++i) {
                if (temp.at(i).size()) samples.push_back(temp.at(i));
            }
            temp.clear();
        }
        return samples;
    }
};

template<class T>
int ungrouped_data<T>::number_of_data = 0;
#endif
