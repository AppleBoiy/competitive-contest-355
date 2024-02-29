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

void gen_input_all(int &cases) {

    if (stat("../in", &info) != 0) {
        // create input folder
        system("mkdir -p ../in");
    } else if (info.st_mode & S_IFDIR) {
        // clear input folder
        system("rm -rf ../in/*");
        cout << "Input folder cleared!" << endl;
    }

    gen_input(cases, 1e3, 1e1);
    gen_input(cases, 1e6, 1e2);
    gen_input(cases, 1e9, 1e2);
    gen_input(cases, 1e12, 1e3);
    //    gen_input(cases, 1e14, 1e3);

    cout << "Total " << cases << " test cases generated!" << endl;
}

void gen_output(int cases) {

    // check output folder exists
    if (stat("../out", &info) != 0) {
        // create output folder
        system("mkdir -p ../out");
    } else if (info.st_mode & S_IFDIR) {
        // clear output folder
        system("rm -rf ../out/*");
        cout << "Output folder cleared!" << endl;
    }

    for (int i = 0; i < cases; ++i) {
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

    cout << "Total " << cases << " results generated!" << endl;
}

int main() {

    int cases = 0;
    gen_input_all(cases);
    gen_output(cases);

    return 0;
}
