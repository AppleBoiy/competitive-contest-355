//
// Created by Chaipat Jainan on 28/2/2024 AD.
//

#include "generator.h"

using namespace std;

void gen_input(int &cases, ll max_n = 1e14, ll max_m = 1e3) {
    // Set random number generator seed for reproducibility
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<ll> n_dist(1, max_n);
    uniform_int_distribution<ll> m_dist(2, max_m);

    // Generate 10 test cases
    for (int i = 1; i <= 10; ++i) {
        ll n = n_dist(gen);
        ll m = m_dist(gen);

        // Create and write to the output file
        string filename = "../in/" + to_string(cases) + ".in";
        ofstream outfile(filename);
        if (!outfile.is_open()) {
            cerr << "Error: Could not open file " << filename << endl;
            exit(1);
        }
        outfile << n << " " << m << endl;
        outfile.close();

        cases++;
    }
}

void gen_input_all() {
    int cases = 0;
    gen_input(cases, 1e3, 1e1);
    gen_input(cases, 1e6, 1e2);
    gen_input(cases, 1e9, 1e2);
    gen_input(cases, 1e12, 1e3);
    gen_input(cases, 1e14, 1e3);

    cout << "Total " << cases << " test cases generated!" << endl;
}

void gen_output() {

    // create output folder
    system("mkdir -p ../out");

    for (int i = 0; i < 50; ++i) {
        string in = "../in/" + to_string(i) + ".in";

        ll n = 0, m = 0;
        ifstream infile(in);

        if (!infile.is_open()) {
            cerr << "Error: Could not open file " << in << endl;
            exit(1);
        } else {
            infile >> n >> m;
        }

        string out = "../out/" + to_string(i) + ".out";

        ofstream outfile(out);
        if (!outfile.is_open()) {
            cerr << "Error: Could not open file " << out << endl;
            exit(1);
        }

        string output = to_string(fib_fast(n, m));
        outfile << output << endl;

        outfile.close();
    }
}

int main() {

    gen_input_all();
    gen_output();

    return 0;
}
