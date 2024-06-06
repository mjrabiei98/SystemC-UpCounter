#include "upCounter_TB.h"

int sc_main(int argc, char **argv)
{
	sc_signal<bool>	rst, clk;
	sc_signal<sc_uint<8> > cnt;

	upCounter_TB CTB1 ("CTB1_Instance");
		CTB1.rst(rst);
		CTB1.clk(clk);
		CTB1.cnt(cnt);

	sc_trace_file* VCDFile;
	VCDFile = sc_create_vcd_trace_file("upCounter");
			sc_trace(VCDFile, rst, "rst");
			sc_trace(VCDFile, clk, "clk");
			sc_trace(VCDFile, cnt, "cnt");		

	int i;
	rst = 1;
    sc_start (15,SC_NS);
	cout << "Reset released at: " << sc_time_stamp << '\n';
	rst = 0;
	for(i=0;i<40;i++){
		clk = 0;
        sc_start (50,SC_NS);
		cout <<"Rising clock edge at: "<< sc_time_stamp()<<". ";
		clk = 1;
		cout <<"Before falling at: "<<sc_time_stamp()<<" Count is: "<<cnt<<'\n';
        sc_start(50,SC_NS);
    }
	sc_start(100,SC_NS);
	return 0;
}
