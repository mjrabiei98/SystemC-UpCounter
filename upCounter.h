// #include <systemc.h>

// SC_MODULE(upCounter)
// {
// 	sc_in<bool>	rst;
// 	sc_in<bool>	clk;
// 	sc_out<sc_uint<8> > cnt;

// 	sc_uint<8> cnt_val;

// 	SC_CTOR(upCounter)
// 	{
// 		SC_METHOD(counting);
// 		sensitive << rst << clk;
// 	}
// 	void counting();
// };
