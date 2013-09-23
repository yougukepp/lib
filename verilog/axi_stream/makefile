all:clean
	iverilog -o test my_stream_ip.v tb.v
	vvp -n test -lxt2
	cp tb.vcd test.lxt
	gtkwave test.lxt

clean: 
	rm -rvf test.lxt tb.vcd test

