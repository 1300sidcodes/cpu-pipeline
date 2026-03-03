#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    const int Instructions = 3;
    const int Stages = 5;

    string instructions[Instructions] = {"ADD", "SUB", "LW"};
    string stages[Stages] = {"IF", "ID", "EX", "MEM", "WB"};

    int totalCycles = Instructions + Stages - 1;

    cout << "\nOVERLAPPED 5-STAGE PIPELINE SIMULATION\n";
    cout << "Total Cycles = " << totalCycles << "\n\n";

    cout << setw(8) << "Cycle";
    for (int i = 0; i < Stages; i++)
        cout << setw(10) << stages[i];
    cout << "\n";

    cout << "------------------------------------------------------\n";

    for (int cycle = 0; cycle < totalCycles; cycle++) {
        cout << setw(8) << cycle + 1;

        for (int s = 0; s < Stages; s++) {
            int instrIndex = cycle - s;

            if (instrIndex >= 0 && instrIndex < Instructions)
                cout << setw(10) << instructions[instrIndex]+ "-" + stages[s];
            else
                cout << setw(10) << "-";
        }
        cout << "\n";
    }
    double cpi = (double) totalCycles / Instructions;
    double tput =(double) 1/cpi;

    int npcycles = Instructions * Stages;
    double npcpi = (double) npcycles / Instructions;
    double npt = 1 / npcpi;
    double SUR = tput/npt;


    cout <<"\nPerformance Metrics\n";
    cout <<"Instructions                                  = " << Instructions << "\n";
    cout <<"Stages                                        = "<<Stages<<"\n";
    cout <<"Cycles                                        = " << totalCycles << "\n";
    cout <<"CPI                                           = " <<fixed<<setprecision(2)<< cpi << "\n";
    cout <<"Throughput per unit time                      = "<<tput<< "\n";
    cout <<"Nonpipelined CPI                              = "<<npcpi<<"\n";
    cout <<"Nonpipelined throughput                       = "<<npt<<"\n";
    cout <<"The SpeedUp due to piepelining is             = "<<SUR<<"\n";

    return 0;
}
