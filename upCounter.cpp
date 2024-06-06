#include <systemc.h>

SC_MODULE(upCounter)
{
	sc_in<bool>	rst;
	sc_in<bool>	clk;
	sc_out<sc_uint<8> > cnt;

	sc_uint<8> cnt_val;

	SC_CTOR(upCounter)
	{
		SC_METHOD(counting);
		sensitive << rst << clk;
	}
	void counting();
};


void upCounter::counting()
	{
//		if (rst->read())
		if (rst)
		{
			cnt_val = 0;
		}
//		else if (clk->event() && clk->read())
		else if (clk->event() && clk)
		{
			cnt_val = cnt_val + 1;
		}
//		cnt->write(cnt_val);
		cnt=cnt_val;
	}